// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vip0_tb__Syms.h"


VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__top_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__tlul_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_reg_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("top_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__top_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("tlul_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__tlul_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_alert_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ip0_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__ip0_reg_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("ip0_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__tl_if__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+84,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+2,0,"tl_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+6,0,"port_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+85,0,"tl_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+27,0,"port_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"error_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+8,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__tl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_ip0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+28,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+6,0,"port_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"port_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+49,0,"reg2hw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+88,0,"hw2reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->pushPrefix("u_ip0_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+49,0,"reg2hw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+88,0,"hw2reg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+6,0,"port_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"port_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ctrl_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"ctrl_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"ctrl_setting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+89,0,"status_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"status_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+51,0,"rdata_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+35,0,"wdata_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_name", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+93,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+27,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+94,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+36,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+93,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+36,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+93,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+27,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ip0_reg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+28,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declQuad(c+49,0,"reg2hw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+88,0,"hw2reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+95,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+17,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+53,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+19,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+98,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"tl_reg_h2d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+28,0,"tl_reg_d2h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+28,0,"tl_o_pre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+21,0,"ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"ctrl_en_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"ctrl_en_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"ctrl_rst_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+58,0,"ctrl_rst_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"ctrl_setting_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+59,0,"ctrl_setting_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+60,0,"status_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"status_full_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"status_empty_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"rdata_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"rdata_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"wdata_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"wdata_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+35,0,"wdata_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"wdata_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+9,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+98,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ctrl_en", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+93,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+64,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+31,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+31,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+31,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_rst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+93,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+32,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+66,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+32,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+32,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+32,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_setting", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+101,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+102,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+21,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+68,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+33,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+101,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+99,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+21,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+102,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+33,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+21,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+33,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rdata", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+103,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+51,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+98,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+91,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_reg_if", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+100,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+100,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+100,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+96,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+105,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+28,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+106,0,"en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+98,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+17,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+53,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+54,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+98,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+20,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+108,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+37,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+70,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+39,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+71,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+41,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+42,0,"rspop_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+25,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+28,0,"tl_o_pre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->pushPrefix("u_err", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+71,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+107,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+108,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+108,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+72,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+109,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+77,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+100,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+100,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declArray(c+28,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+28,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+43,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+100,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+100,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declArray(c+28,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+28,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+43,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_empty", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+60,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+90,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+90,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+90,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_full", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+110,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+60,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+98,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+89,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+98,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+89,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+89,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_wdata", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+107,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+111,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+104,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+34,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+78,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+34,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+107,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+111,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+100,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+22,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+61,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+98,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+34,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+22,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_wdata0_qe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+92,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+93,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+22,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+35,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__top_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__top_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+97,0,"TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+107,0,"TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+92,0,"TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+112,0,"TL_AUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+113,0,"TL_DUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+108,0,"TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+105,0,"SecVolatileRawUnlockEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+114,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+115,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+114,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+116,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+117,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+118,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+117,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+120,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+104,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+122,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+114,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+115,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+117,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+118,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+104,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+122,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+104,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+125,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+128,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+129,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+128,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+130,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+131,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+132,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+131,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+134,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+136,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+137,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+128,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+129,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+131,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+132,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+136,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+137,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+136,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+140,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+143,0,"ALERT_TX_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+144,0,"ALERT_RX_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__tl_if__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__ip0_tb__tl_if__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+80,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+45,0,"h2d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+81,0,"d2h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__ip0_reg_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__ip0_reg_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+96,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+96,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"IP0_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+146,0,"IP0_STATUS_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+147,0,"IP0_RDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+148,0,"IP0_WDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+149,0,"IP0_STATUS_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+104,0,"IP0_RDATA_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("IP0_PERMIT", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+150+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+96,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+107,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+101,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+84,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+155,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+156,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_sub__TOP__tlul_pkg__0(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_sub__TOP__tlul_pkg__0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+157,0,"ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+158,0,"H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+159,0,"H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+160,0,"H2DCmdFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+158,0,"D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+159,0,"D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+160,0,"D2HRspFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+97,0,"DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+159,0,"DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+161,0,"DataFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+162,0,"DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+164,0,"TL_A_USER_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+163,0,"BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+165,0,"TL_H2D_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+169,0,"TL_D_USER_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 13,0);
    tracep->declArray(c+170,0,"TL_D2H_DEFAULT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_init_top(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_init_top\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vip0_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vip0_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vip0_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vip0_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vip0_tb___024root__trace_register(Vip0_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_register\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vip0_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vip0_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vip0_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vip0_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_const_0_sub_0(Vip0_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vip0_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_const_0\n"); );
    // Body
    Vip0_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vip0_tb___024root*>(voidSelf);
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vip0_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_const_0_sub_0(Vip0_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_const_0_sub_0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_5;
    VlWide<3>/*95:0*/ __Vtemp_6;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+84,(0x00000014U),32);
    bufp->fullWData(oldp+85,(vlSymsp->TOP__ip0_tb.__PVT__tl_o),66);
    bufp->fullSData(oldp+88,((((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__status_full) 
                               << 9U) | (((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__status_empty) 
                                          << 8U) | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__rdata)))),10);
    bufp->fullBit(oldp+89,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__status_full));
    bufp->fullBit(oldp+90,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__status_empty));
    bufp->fullCData(oldp+91,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__rdata),8);
    bufp->fullIData(oldp+92,(1U),32);
    bufp->fullBit(oldp+93,(0U));
    bufp->fullBit(oldp+94,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__u_sync_name__DOT__d_o));
    bufp->fullBit(oldp+95,(1U));
    bufp->fullIData(oldp+96,(4U),32);
    bufp->fullIData(oldp+97,(0x00000020U),32);
    bufp->fullBit(oldp+98,(0U));
    bufp->fullCData(oldp+99,(0U),3);
    bufp->fullBit(oldp+100,(0U));
    bufp->fullIData(oldp+101,(0x00000010U),32);
    bufp->fullSData(oldp+102,(0U),16);
    bufp->fullIData(oldp+103,(8U),32);
    bufp->fullCData(oldp+104,(0U),8);
    bufp->fullIData(oldp+105,(0U),32);
    bufp->fullCData(oldp+106,(9U),4);
    bufp->fullIData(oldp+107,(8U),32);
    bufp->fullIData(oldp+108,(2U),32);
    bufp->fullCData(oldp+109,(1U),4);
    bufp->fullIData(oldp+110,(1U),32);
    bufp->fullCData(oldp+111,(2U),3);
    bufp->fullIData(oldp+112,(0x00000015U),32);
    bufp->fullIData(oldp+113,(0x0000000eU),32);
    bufp->fullCData(oldp+114,(0U),6);
    bufp->fullIData(oldp+115,(0U),22);
    bufp->fullIData(oldp+116,(0U),28);
    bufp->fullCData(oldp+117,(0U),7);
    bufp->fullQData(oldp+118,(0ULL),39);
    bufp->fullQData(oldp+120,(0ULL),64);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+122,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+125,(__Vtemp_2),76);
    bufp->fullCData(oldp+128,(0x2aU),6);
    bufp->fullIData(oldp+129,(0x002a0000U),22);
    bufp->fullIData(oldp+130,(0x0a800000U),28);
    bufp->fullCData(oldp+131,(0x2aU),7);
    bufp->fullQData(oldp+132,(0x0000002a00000000ULL),39);
    bufp->fullQData(oldp+134,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+136,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0x000000aaU;
    bufp->fullWData(oldp+137,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0x00000aa0U;
    bufp->fullWData(oldp+140,(__Vtemp_4),76);
    bufp->fullCData(oldp+143,(1U),2);
    bufp->fullCData(oldp+144,(5U),4);
    bufp->fullCData(oldp+145,(0U),4);
    bufp->fullCData(oldp+146,(4U),4);
    bufp->fullCData(oldp+147,(8U),4);
    bufp->fullCData(oldp+148,(0x0cU),4);
    bufp->fullCData(oldp+149,(0U),2);
    bufp->fullCData(oldp+150,(vlSymsp->TOP__ip0_reg_pkg.__PVT__IP0_PERMIT[0]),4);
    bufp->fullCData(oldp+151,(vlSymsp->TOP__ip0_reg_pkg.__PVT__IP0_PERMIT[1]),4);
    bufp->fullCData(oldp+152,(vlSymsp->TOP__ip0_reg_pkg.__PVT__IP0_PERMIT[2]),4);
    bufp->fullCData(oldp+153,(vlSymsp->TOP__ip0_reg_pkg.__PVT__IP0_PERMIT[3]),4);
    bufp->fullIData(oldp+154,(0x0000000cU),32);
    bufp->fullIData(oldp+155,(0x00000018U),32);
    bufp->fullIData(oldp+156,(0x0000001cU),32);
    bufp->fullIData(oldp+157,(0x00505043U),24);
    bufp->fullIData(oldp+158,(0x00000039U),32);
    bufp->fullIData(oldp+159,(7U),32);
    bufp->fullIData(oldp+160,(0x00000040U),32);
    bufp->fullIData(oldp+161,(0x00000027U),32);
    bufp->fullIData(oldp+162,(0U),32);
    bufp->fullIData(oldp+163,(0xffffffffU),32);
    bufp->fullIData(oldp+164,(0x00027fffU),23);
    __Vtemp_5[0U] = 0xff04ffffU;
    __Vtemp_5[1U] = 0x00ffffffU;
    __Vtemp_5[2U] = 0U;
    __Vtemp_5[3U] = 0U;
    bufp->fullWData(oldp+165,(__Vtemp_5),109);
    bufp->fullSData(oldp+169,(0x3fffU),14);
    __Vtemp_6[0U] = 0x0000fffdU;
    __Vtemp_6[1U] = 0U;
    __Vtemp_6[2U] = 0U;
    bufp->fullWData(oldp+170,(__Vtemp_6),66);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_full_0_sub_0(Vip0_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vip0_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_full_0\n"); );
    // Body
    Vip0_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vip0_tb___024root*>(voidSelf);
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vip0_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vip0_tb___024root__trace_full_0_sub_0(Vip0_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vip0_tb___024root__trace_full_0_sub_0\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSymsp->TOP__ip0_tb.__PVT__rst_ni));
    bufp->fullWData(oldp+2,(vlSymsp->TOP__ip0_tb.__PVT__tl_i),109);
    bufp->fullBit(oldp+6,(vlSymsp->TOP__ip0_tb.__PVT__port_i));
    bufp->fullIData(oldp+7,(vlSymsp->TOP__ip0_tb.__PVT__error_count),32);
    bufp->fullIData(oldp+8,(vlSymsp->TOP__ip0_tb.__PVT__rdata),32);
    bufp->fullCData(oldp+9,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__addr_hit),4);
    bufp->fullBit(oldp+10,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->fullBit(oldp+12,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+13,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+14,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+16,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->fullBit(oldp+17,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__we_o));
    bufp->fullBit(oldp+18,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o));
    bufp->fullIData(oldp+19,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+20,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we));
    bufp->fullBit(oldp+22,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_wdata0_qe__DOT__d_i));
    bufp->fullBit(oldp+23,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->fullBit(oldp+24,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->fullBit(oldp+27,(vlSymsp->TOP__ip0_tb.__PVT__port_o));
    __Vtemp_2[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                              << 0x00000039U) | (((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                  << 0x00000031U) 
                                                 | (((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                     << 0x00000010U) 
                                                    | (QData)((IData)(
                                                                      (((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_q) 
                                                                        << 1U) 
                                                                       | (1U 
                                                                          & (~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__outstanding_q))))))))));
    __Vtemp_2[1U] = (((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rspop_q) 
                      << 0x0000001eU) | (IData)(((((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                   << 0x00000039U) 
                                                  | (((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                      << 0x00000031U) 
                                                     | (((QData)((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                         << 0x00000010U) 
                                                        | (QData)((IData)(
                                                                          (((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_q) 
                                                                            << 1U) 
                                                                           | (1U 
                                                                              & (~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__outstanding_q))))))))) 
                                                 >> 0x00000020U)));
    __Vtemp_2[2U] = (((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__outstanding_q) 
                      << 1U) | ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rspop_q) 
                                >> 2U));
    bufp->fullWData(oldp+28,(__Vtemp_2),66);
    bufp->fullBit(oldp+31,(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_en__q));
    bufp->fullBit(oldp+32,(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_rst__q));
    bufp->fullSData(oldp+33,(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_setting__q),16);
    bufp->fullCData(oldp+34,(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_wdata__q),8);
    bufp->fullBit(oldp+35,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__wdata_qe));
    bufp->fullBit(oldp+36,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_core__DOT__u_sync_name__DOT__intq));
    bufp->fullBit(oldp+37,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->fullIData(oldp+38,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->fullBit(oldp+39,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_q));
    bufp->fullCData(oldp+40,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->fullCData(oldp+41,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->fullCData(oldp+42,(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->fullBit(oldp+43,((1U & (~ ((((VL_REDXOR_4(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rspop_q) 
                                        ^ VL_REDXOR_2(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                       ^ VL_REDXOR_8(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                      ^ VL_REDXOR_32(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                     ^ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_q))))));
    bufp->fullBit(oldp+44,(vlSymsp->TOP__ip0_tb.__PVT__clk_i));
    bufp->fullWData(oldp+45,(vlSymsp->TOP__ip0_tb__tl_if.h2d),109);
    bufp->fullQData(oldp+49,((((QData)((IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_setting__q)) 
                               << 0x00000018U) | (QData)((IData)(
                                                                 (((IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_rst__q) 
                                                                   << 0x00000017U) 
                                                                  | (((IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_en__q) 
                                                                      << 0x00000016U) 
                                                                     | ((((1U 
                                                                           == 
                                                                           (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                                            >> 0x0000001eU)) 
                                                                          & ((~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                             & (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                         << 0x00000014U) 
                                                                        | ((((1U 
                                                                              == 
                                                                              (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                                               >> 0x0000001eU)) 
                                                                             & ((~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                                & (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                            << 0x00000012U) 
                                                                           | ((((2U 
                                                                                == 
                                                                                (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                                                >> 0x0000001eU)) 
                                                                                & ((~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i)) 
                                                                                & (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o))) 
                                                                               << 9U) 
                                                                              | (((IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_wdata__q) 
                                                                                << 1U) 
                                                                                | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__wdata_qe))))))))))),40);
    bufp->fullBit(oldp+51,(((2U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                    >> 0x0000001eU)) 
                            & ((~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i)) 
                               & (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->fullCData(oldp+52,((0x0000000cU & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                             >> 0x0000001cU))),4);
    bufp->fullIData(oldp+53,(((vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                               << 8U) | (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+54,((0x0000000fU & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullBit(oldp+55,(((~ (0U != (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__addr_hit))) 
                            & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o) 
                               | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__we_o)))));
    bufp->fullBit(oldp+56,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__we_o) 
                            & (((0U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                        >> 0x0000001eU)) 
                                & (0U != (0x0000000fU 
                                          & (~ ((vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                 << 8U) 
                                                | (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                   >> 0x00000018U)))))) 
                               | ((0U != (1U & (~ (
                                                   (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                      >> 0x00000018U))))) 
                                  & ((1U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                             >> 0x0000001eU)) 
                                     | ((2U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                >> 0x0000001eU)) 
                                        | (3U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                  >> 0x0000001eU)))))))));
    bufp->fullBit(oldp+57,((1U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U))));
    bufp->fullBit(oldp+58,((1U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                  >> 0x00000019U))));
    bufp->fullSData(oldp+59,((0x0000ffffU & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                             >> 8U))),16);
    bufp->fullBit(oldp+60,(((1U == (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                    >> 0x0000001eU)) 
                            & ((~ (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__error_i)) 
                               & (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->fullCData(oldp+61,((vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                              >> 0x00000018U)),8);
    bufp->fullBit(oldp+62,((1U & VL_REDXOR_32(((vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                << 8U) 
                                               | (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                                  >> 0x00000018U))))));
    bufp->fullBit(oldp+63,((1U & VL_REDXOR_32((0x0000000fU 
                                               & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                  >> 0x00000018U))))));
    bufp->fullBit(oldp+64,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we)
                             ? ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we) 
                                & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                   >> 0x00000018U))
                             : (IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_en__q))));
    bufp->fullBit(oldp+65,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we) 
                            & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                               >> 0x00000018U))));
    bufp->fullBit(oldp+66,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we)
                             ? ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we) 
                                & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                   >> 0x00000019U))
                             : (IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_rst__q))));
    bufp->fullBit(oldp+67,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we) 
                            & (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                               >> 0x00000019U))));
    bufp->fullSData(oldp+68,((0x0000ffffU & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we)
                                              ? ((vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                  << 0x00000018U) 
                                                 | (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                    >> 8U))
                                              : (IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_ctrl_setting__q)))),16);
    bufp->fullSData(oldp+69,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_ctrl_en__DOT__we)
                               ? (0x0000ffffU & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                 >> 8U))
                               : 0U)),16);
    bufp->fullBit(oldp+70,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__outstanding_q) 
                            & vlSymsp->TOP__ip0_tb__tl_if.h2d[0U])));
    bufp->fullBit(oldp+71,((1U & ((~ (((0U == (7U & 
                                               (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                >> 9U))) 
                                       | ((1U == (7U 
                                                  & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                     >> 9U))) 
                                          | (4U == 
                                             (7U & 
                                              (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                               >> 9U))))) 
                                      & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                                         & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                            & ((4U 
                                                == 
                                                (7U 
                                                 & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                    >> 9U))) 
                                               | ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                       >> 9U))) 
                                                  | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk))))))) 
                                  | ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                                     | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))))));
    bufp->fullBit(oldp+72,(((0U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                          >> 9U))) 
                            | ((1U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                             >> 9U))) 
                               | (4U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                               >> 9U)))))));
    bufp->fullBit(oldp+73,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                            & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                               & ((4U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                >> 9U))) 
                                  | ((1U == (7U & (
                                                   vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                                   >> 9U))) 
                                     | (IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->fullBit(oldp+74,((0U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->fullBit(oldp+75,((1U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->fullBit(oldp+76,((4U == (7U & (vlSymsp->TOP__ip0_tb__tl_if.h2d[3U] 
                                         >> 9U)))));
    bufp->fullCData(oldp+77,((0x0000000fU & ((IData)(1U) 
                                             << (3U 
                                                 & (vlSymsp->TOP__ip0_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001cU))))),4);
    bufp->fullCData(oldp+78,((0x000000ffU & ((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_wdata0_qe__DOT__d_i)
                                              ? ((vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                                  << 8U) 
                                                 | (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                                    >> 0x00000018U))
                                              : (IData)(vlSymsp->TOP__ip0_tb.u_ip0__DOT__u_ip0_reg__DOT____Vcellout__u_wdata__q)))),8);
    bufp->fullCData(oldp+79,(((IData)(vlSymsp->TOP__ip0_tb.__PVT__u_ip0__DOT__u_ip0_reg__DOT__u_wdata0_qe__DOT__d_i)
                               ? (vlSymsp->TOP__ip0_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U) : 0U)),8);
    bufp->fullBit(oldp+80,(vlSymsp->TOP__ip0_tb__tl_if.__PVT__clk_i));
    bufp->fullWData(oldp+81,(vlSymsp->TOP__ip0_tb__tl_if.d2h),66);
}
