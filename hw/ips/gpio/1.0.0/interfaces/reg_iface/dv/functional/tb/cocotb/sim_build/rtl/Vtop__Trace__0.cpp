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
    bufp->chgBit(oldp+6,((1U & (IData)((vlSelfRef.gpio_tb__DOT__reg_req_i 
                                        >> 0x00000029U)))));
    bufp->chgBit(oldp+7,((1U & (IData)((vlSelfRef.gpio_tb__DOT__reg_req_i 
                                        >> 0x00000028U)))));
    bufp->chgCData(oldp+8,((0x0000000fU & (IData)((vlSelfRef.gpio_tb__DOT__reg_req_i 
                                                   >> 0x00000024U)))),4);
    bufp->chgIData(oldp+9,((IData)((vlSelfRef.gpio_tb__DOT__reg_req_i 
                                    >> 4U))),32);
    bufp->chgCData(oldp+10,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+11,((IData)((vlSelfRef.gpio_tb__DOT__reg_rsp_o 
                                     >> 2U))),32);
    bufp->chgBit(oldp+12,((1U & (IData)((vlSelfRef.gpio_tb__DOT__reg_rsp_o 
                                         >> 1U)))));
    bufp->chgBit(oldp+13,((1U & (IData)(vlSelfRef.gpio_tb__DOT__reg_rsp_o))));
    bufp->chgBit(oldp+14,(vlSelfRef.gpio_tb__DOT__reg_req_valid));
    bufp->chgBit(oldp+15,(vlSelfRef.gpio_tb__DOT__reg_req_write));
    bufp->chgCData(oldp+16,(vlSelfRef.gpio_tb__DOT__reg_req_addr),4);
    bufp->chgIData(oldp+17,(vlSelfRef.gpio_tb__DOT__reg_req_wdata),32);
    bufp->chgCData(oldp+18,(vlSelfRef.gpio_tb__DOT__reg_req_wstrb),4);
    bufp->chgBit(oldp+19,(vlSelfRef.gpio_tb__DOT__reg_rsp_ready));
    bufp->chgBit(oldp+20,(vlSelfRef.gpio_tb__DOT__reg_rsp_error));
    bufp->chgIData(oldp+21,(vlSelfRef.gpio_tb__DOT__reg_rsp_rdata),32);
    bufp->chgBit(oldp+22,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i));
    bufp->chgBit(oldp+23,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni));
    bufp->chgCData(oldp+24,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+25,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+26,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+27,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o),4);
    bufp->chgBit(oldp+28,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_req_i 
                                         >> 0x00000029U)))));
    bufp->chgBit(oldp+29,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_req_i 
                                         >> 0x00000028U)))));
    bufp->chgCData(oldp+30,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_req_i 
                                                    >> 0x00000024U)))),4);
    bufp->chgIData(oldp+31,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_req_i 
                                     >> 4U))),32);
    bufp->chgCData(oldp+32,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+33,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rsp_o 
                                     >> 2U))),32);
    bufp->chgBit(oldp+34,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rsp_o 
                                         >> 1U)))));
    bufp->chgBit(oldp+35,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rsp_o))));
    bufp->chgCData(oldp+36,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+37,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+38,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000015U))),4);
    bufp->chgBit(oldp+39,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                 >> 0x00000014U))));
    bufp->chgCData(oldp+40,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x00000010U))),4);
    bufp->chgCData(oldp+41,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 0x0000000cU))),4);
    bufp->chgCData(oldp+42,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 8U))),4);
    bufp->chgCData(oldp+43,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                            >> 4U))),4);
    bufp->chgCData(oldp+44,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw)),4);
    bufp->chgCData(oldp+45,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 9U))),4);
    bufp->chgBit(oldp+46,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                 >> 8U))));
    bufp->chgCData(oldp+47,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                            >> 4U))),4);
    bufp->chgCData(oldp+48,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg))),4);
    bufp->chgBit(oldp+49,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni));
    bufp->chgBit(oldp+50,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni));
    bufp->chgBit(oldp+51,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+52,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+53,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+54,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+55,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq));
    bufp->chgBit(oldp+56,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+57,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+58,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+59,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+60,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+61,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+62,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+63,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i));
    bufp->chgBit(oldp+64,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni));
    bufp->chgCData(oldp+65,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x0000001aU))),4);
    bufp->chgBit(oldp+66,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                 >> 0x00000019U))));
    bufp->chgCData(oldp+67,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x00000015U))),4);
    bufp->chgBit(oldp+68,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                 >> 0x00000014U))));
    bufp->chgCData(oldp+69,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x00000010U))),4);
    bufp->chgCData(oldp+70,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 0x0000000cU))),4);
    bufp->chgCData(oldp+71,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 8U))),4);
    bufp->chgCData(oldp+72,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                            >> 4U))),4);
    bufp->chgCData(oldp+73,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+74,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                            >> 9U))),4);
    bufp->chgBit(oldp+75,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                 >> 8U))));
    bufp->chgCData(oldp+76,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                            >> 4U))),4);
    bufp->chgCData(oldp+77,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg))),4);
    bufp->chgCData(oldp+78,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i),4);
    bufp->chgCData(oldp+79,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o),4);
    bufp->chgCData(oldp+80,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o),4);
    bufp->chgCData(oldp+81,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o),4);
    bufp->chgCData(oldp+82,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d),4);
    bufp->chgCData(oldp+83,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q),4);
    bufp->chgCData(oldp+84,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q),4);
    bufp->chgCData(oldp+85,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q),4);
    bufp->chgCData(oldp+86,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise),4);
    bufp->chgCData(oldp+87,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall),4);
    bufp->chgCData(oldp+88,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high),4);
    bufp->chgCData(oldp+89,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low),4);
    bufp->chgBit(oldp+90,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni));
    bufp->chgBit(oldp+91,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni));
    bufp->chgBit(oldp+92,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+93,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+94,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+95,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+96,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+97,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+98,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+99,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+100,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+101,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+102,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+103,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+104,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+105,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+106,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+107,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+108,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+109,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+110,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+111,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+112,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+113,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+114,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+115,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+116,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+117,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+118,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+119,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+120,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+121,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+122,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+123,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+124,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+125,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+126,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+127,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+128,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+129,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+130,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+131,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+132,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+133,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+134,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+135,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+136,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+137,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+138,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+139,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+140,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+141,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+142,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+143,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+144,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+145,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+146,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+147,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+148,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+149,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+150,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+151,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+152,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+153,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+154,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+155,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+156,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+157,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+158,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+159,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+160,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+161,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+162,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+163,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+164,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+165,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+166,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+167,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i));
    bufp->chgBit(oldp+168,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni));
    bufp->chgBit(oldp+169,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i));
    bufp->chgBit(oldp+170,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i));
    bufp->chgBit(oldp+171,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o));
    bufp->chgCData(oldp+172,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->chgCData(oldp+173,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->chgBit(oldp+174,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q));
    bufp->chgBit(oldp+175,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->chgBit(oldp+176,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->chgBit(oldp+177,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced));
    bufp->chgBit(oldp+178,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->chgBit(oldp+179,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->chgBit(oldp+180,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->chgBit(oldp+181,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->chgBit(oldp+182,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->chgBit(oldp+183,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->chgBit(oldp+184,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+185,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+186,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->chgBit(oldp+187,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+188,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+189,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+190,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+191,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->chgBit(oldp+192,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+193,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+194,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+195,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i));
    bufp->chgBit(oldp+196,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni));
    bufp->chgBit(oldp+197,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o));
    bufp->chgBit(oldp+198,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i));
    bufp->chgBit(oldp+199,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni));
    bufp->chgBit(oldp+200,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+201,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_req_i 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+202,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_req_i 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+203,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+204,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+205,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+206,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+207,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg_rsp_o))));
    bufp->chgCData(oldp+208,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+209,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+210,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+211,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+212,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+213,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+214,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+215,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+216,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw)),4);
    bufp->chgCData(oldp+217,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+218,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+219,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+220,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg))),4);
    bufp->chgBit(oldp+221,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->chgBit(oldp+222,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->chgBit(oldp+223,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000029U)))));
    bufp->chgBit(oldp+224,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                          >> 0x00000028U)))));
    bufp->chgCData(oldp+225,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                     >> 0x00000024U)))),4);
    bufp->chgIData(oldp+226,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                      >> 4U))),32);
    bufp->chgCData(oldp+227,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->chgIData(oldp+228,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                      >> 2U))),32);
    bufp->chgBit(oldp+229,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                          >> 1U)))));
    bufp->chgBit(oldp+230,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->chgCData(oldp+231,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->chgBit(oldp+232,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->chgCData(oldp+233,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->chgBit(oldp+234,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->chgCData(oldp+235,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->chgCData(oldp+236,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->chgCData(oldp+237,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->chgCData(oldp+238,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->chgCData(oldp+239,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw)),4);
    bufp->chgCData(oldp+240,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->chgBit(oldp+241,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                  >> 8U))));
    bufp->chgCData(oldp+242,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->chgCData(oldp+243,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg))),4);
    bufp->chgBit(oldp+244,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->chgBit(oldp+245,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->chgBit(oldp+246,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->chgCData(oldp+247,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr),4);
    bufp->chgIData(oldp+248,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->chgCData(oldp+249,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->chgIData(oldp+250,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->chgBit(oldp+251,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->chgBit(oldp+252,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->chgBit(oldp+253,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->chgIData(oldp+254,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->chgBit(oldp+255,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->chgCData(oldp+256,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check),3);
    bufp->chgBit(oldp+257,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q));
    bufp->chgCData(oldp+258,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs),4);
    bufp->chgBit(oldp+259,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re));
    bufp->chgBit(oldp+260,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we));
    bufp->chgCData(oldp+261,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs),4);
    bufp->chgCData(oldp+262,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd),4);
    bufp->chgCData(oldp+263,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs),4);
    bufp->chgCData(oldp+264,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd),4);
    bufp->chgBit(oldp+265,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we));
    bufp->chgCData(oldp+266,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs),4);
    bufp->chgCData(oldp+267,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd),4);
    bufp->chgCData(oldp+268,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs),4);
    bufp->chgCData(oldp+269,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd),4);
    bufp->chgCData(oldp+270,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs),4);
    bufp->chgCData(oldp+271,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd),4);
    bufp->chgCData(oldp+272,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs),4);
    bufp->chgCData(oldp+273,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd),4);
    bufp->chgCData(oldp+274,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs),4);
    bufp->chgCData(oldp+275,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd),4);
    bufp->chgBit(oldp+276,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe));
    bufp->chgCData(oldp+277,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we),2);
    bufp->chgCData(oldp+278,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit),3);
    bufp->chgBit(oldp+279,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->chgBit(oldp+280,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->chgBit(oldp+281,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i));
    bufp->chgBit(oldp+282,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni));
    bufp->chgBit(oldp+283,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de));
    bufp->chgCData(oldp+284,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d),4);
    bufp->chgBit(oldp+285,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe));
    bufp->chgCData(oldp+286,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q),4);
    bufp->chgCData(oldp+287,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds),4);
    bufp->chgCData(oldp+288,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs),4);
    bufp->chgBit(oldp+289,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en));
    bufp->chgCData(oldp+290,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data),4);
    bufp->chgBit(oldp+291,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de));
    bufp->chgCData(oldp+292,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d),4);
    bufp->chgCData(oldp+293,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+294,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+295,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+296,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q),4);
    bufp->chgBit(oldp+297,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re));
    bufp->chgBit(oldp+298,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we));
    bufp->chgCData(oldp+299,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd),4);
    bufp->chgCData(oldp+300,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d),4);
    bufp->chgBit(oldp+301,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    bufp->chgBit(oldp+302,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre));
    bufp->chgCData(oldp+303,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q),4);
    bufp->chgCData(oldp+304,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds),4);
    bufp->chgCData(oldp+305,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs),4);
    bufp->chgBit(oldp+306,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re));
    bufp->chgBit(oldp+307,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we));
    bufp->chgCData(oldp+308,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd),4);
    bufp->chgCData(oldp+309,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d),4);
    bufp->chgBit(oldp+310,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe));
    bufp->chgBit(oldp+311,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre));
    bufp->chgCData(oldp+312,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q),4);
    bufp->chgCData(oldp+313,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds),4);
    bufp->chgCData(oldp+314,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs),4);
    bufp->chgBit(oldp+315,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i));
    bufp->chgBit(oldp+316,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni));
    bufp->chgBit(oldp+317,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we));
    bufp->chgCData(oldp+318,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd),4);
    bufp->chgBit(oldp+319,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe));
    bufp->chgCData(oldp+320,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q),4);
    bufp->chgCData(oldp+321,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds),4);
    bufp->chgCData(oldp+322,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs),4);
    bufp->chgBit(oldp+323,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en));
    bufp->chgCData(oldp+324,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data),4);
    bufp->chgBit(oldp+325,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+326,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+327,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+328,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+329,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+330,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+331,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i));
    bufp->chgBit(oldp+332,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni));
    bufp->chgBit(oldp+333,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we));
    bufp->chgCData(oldp+334,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd),4);
    bufp->chgBit(oldp+335,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe));
    bufp->chgCData(oldp+336,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q),4);
    bufp->chgCData(oldp+337,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds),4);
    bufp->chgCData(oldp+338,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs),4);
    bufp->chgBit(oldp+339,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en));
    bufp->chgCData(oldp+340,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data),4);
    bufp->chgBit(oldp+341,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+342,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+343,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+344,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+345,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+346,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+347,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i));
    bufp->chgBit(oldp+348,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni));
    bufp->chgBit(oldp+349,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we));
    bufp->chgCData(oldp+350,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd),4);
    bufp->chgBit(oldp+351,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe));
    bufp->chgCData(oldp+352,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q),4);
    bufp->chgCData(oldp+353,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds),4);
    bufp->chgCData(oldp+354,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs),4);
    bufp->chgBit(oldp+355,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en));
    bufp->chgCData(oldp+356,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data),4);
    bufp->chgBit(oldp+357,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+358,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+359,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+360,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+361,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+362,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+363,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i));
    bufp->chgBit(oldp+364,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni));
    bufp->chgBit(oldp+365,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we));
    bufp->chgCData(oldp+366,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd),4);
    bufp->chgBit(oldp+367,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe));
    bufp->chgCData(oldp+368,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q),4);
    bufp->chgCData(oldp+369,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds),4);
    bufp->chgCData(oldp+370,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs),4);
    bufp->chgBit(oldp+371,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en));
    bufp->chgCData(oldp+372,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data),4);
    bufp->chgBit(oldp+373,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+374,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+375,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+376,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+377,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+378,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+379,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i));
    bufp->chgBit(oldp+380,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni));
    bufp->chgBit(oldp+381,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we));
    bufp->chgCData(oldp+382,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd),4);
    bufp->chgBit(oldp+383,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe));
    bufp->chgCData(oldp+384,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q),4);
    bufp->chgCData(oldp+385,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds),4);
    bufp->chgCData(oldp+386,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs),4);
    bufp->chgBit(oldp+387,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en));
    bufp->chgCData(oldp+388,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data),4);
    bufp->chgBit(oldp+389,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we));
    bufp->chgCData(oldp+390,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->chgCData(oldp+391,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q),4);
    bufp->chgBit(oldp+392,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->chgCData(oldp+393,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->chgCData(oldp+394,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->chgBit(oldp+395,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->chgBit(oldp+396,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->chgCData(oldp+397,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),3);
    bufp->chgBit(oldp+398,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->chgBit(oldp+399,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->chgCData(oldp+400,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),3);
    bufp->chgCData(oldp+401,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),3);
    bufp->chgCData(oldp+402,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),3);
    bufp->chgCData(oldp+403,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),3);
    bufp->chgBit(oldp+404,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->chgBit(oldp+405,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->chgCData(oldp+406,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),3);
    bufp->chgBit(oldp+407,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->chgBit(oldp+408,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->chgCData(oldp+409,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),7);
    bufp->chgCData(oldp+410,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),7);
    bufp->chgCData(oldp+411,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),7);
    bufp->chgBit(oldp+412,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->chgBit(oldp+413,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->chgBit(oldp+414,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->chgBit(oldp+415,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->chgBit(oldp+416,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq));
    bufp->chgBit(oldp+417,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->chgBit(oldp+418,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->chgBit(oldp+419,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->chgBit(oldp+420,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->chgBit(oldp+421,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->chgBit(oldp+422,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->chgBit(oldp+423,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 424, vlSymsp->TOP__gpio_reg_pkg.GPIO_PERMIT);
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
