// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmy_ip_tb__Syms.h"


VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__top_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__tlul_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_reg_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("top_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__top_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("tlul_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__tlul_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_alert_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("my_ip_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_reg_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("my_ip_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__0(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__tl_if__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+123,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+2,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+3,0,"a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+4,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+6,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+7,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+9,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+10,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+11,0,"instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+12,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+13,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+14,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+15,0,"port_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+124,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+125,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+126,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+127,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+128,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+129,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+130,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+131,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+132,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+133,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+134,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+36,0,"port_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"error_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+17,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tl_if", VerilatedTracePrefixType::SCOPE_INTERFACE);
    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__tl_if__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("u_my_ip", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+15,0,"port_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"port_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("setting", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+48,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+49,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("en", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+50,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+76,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+78,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+80,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+81,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+82,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+83,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+135,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+136,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+137,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_my_ip_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("setting", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+48,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+49,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("en", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+50,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+76,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+78,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+80,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+81,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+82,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+83,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+135,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+136,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+137,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+15,0,"port_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"port_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"ctrl_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"ctrl_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"ctrl_setting",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+135,0,"status_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"status_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+84,0,"rdata_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+54,0,"wdata_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_name", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+139,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+36,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+140,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+55,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+139,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+55,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+139,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+55,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+36,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_my_ip_reg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("setting", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+48,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+49,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("en", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+50,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+76,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+78,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+80,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+81,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("wdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+82,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+83,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("full", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+135,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("empty", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+136,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rdata", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+137,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+141,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+142,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+26,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+28,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+144,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_reg_h2d", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_reg_d2h", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+30,0,"ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+51,0,"ctrl_en_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"ctrl_en_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+52,0,"ctrl_rst_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"ctrl_rst_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"ctrl_setting_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+90,0,"ctrl_setting_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+91,0,"status_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+135,0,"status_full_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+136,0,"status_empty_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"rdata_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+137,0,"rdata_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+31,0,"wdata_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"wdata_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+54,0,"wdata_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"wdata_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+18,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+144,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+93,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_ctrl_en", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+139,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+95,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+51,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+88,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+51,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_rst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+139,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+52,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+97,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+52,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+89,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+52,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+52,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_setting", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+147,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+148,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+148,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+30,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+48,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+99,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+48,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+147,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+145,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+30,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+90,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+148,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+48,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+30,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+100,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+48,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rdata", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+149,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+84,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+144,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+84,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+137,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_reg_if", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+146,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+146,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+146,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+142,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+151,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBus(c+152,0,"en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+144,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+27,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+85,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+144,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+29,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+37,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+57,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+57,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+58,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+59,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+60,0,"rspop_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+34,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_err", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+102,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+153,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+103,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+104,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+105,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+106,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+107,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+155,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+108,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+146,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+146,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+61,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+146,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+146,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+37,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"d_opcode",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+39,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+42,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+43,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+44,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+45,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+46,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+47,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+61,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_empty", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+156,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+91,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+136,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+136,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+136,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_full", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+156,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+91,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+144,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+144,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_wdata", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+153,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+157,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+150,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+31,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+53,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+109,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+53,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+31,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+153,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+157,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+146,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+31,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+144,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+150,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+53,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+31,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+110,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+53,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_wdata0_qe", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+138,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+139,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+62,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+54,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__top_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__top_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+143,0,"TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+153,0,"TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+138,0,"TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+158,0,"TL_AUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+159,0,"TL_DUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+154,0,"TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+151,0,"SecVolatileRawUnlockEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+160,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+161,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+160,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+162,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+163,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+164,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+163,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+166,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+150,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+168,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+160,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+161,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+163,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+164,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+150,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+168,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+150,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+171,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+174,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+175,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+174,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+176,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+177,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+178,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+177,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+180,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+182,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+183,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+174,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+175,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+177,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+178,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+182,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+183,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+182,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+186,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_alert_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("ALERT_TX_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+144,0,"alert_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"alert_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ALERT_RX_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+144,0,"ping_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"ping_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+144,0,"ack_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"ack_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__tl_if__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_tb__tl_if__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBit(c+111,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("h2d", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+63,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+65,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+66,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+67,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+68,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+69,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+70,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+72,0,"instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+73,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+74,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+75,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("d2h", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+112,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+113,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+114,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+115,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+116,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+117,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+118,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+119,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+120,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+121,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_reg_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__my_ip_reg_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+142,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+142,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+189,0,"MY_IP_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+190,0,"MY_IP_STATUS_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+191,0,"MY_IP_RDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+192,0,"MY_IP_WDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+193,0,"MY_IP_STATUS_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+150,0,"MY_IP_RDATA_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("MY_IP_PERMIT", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declBus(c+194+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+142,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+153,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+198,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+147,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+123,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+199,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+200,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_sub__TOP__tlul_pkg__0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_sub__TOP__tlul_pkg__0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+201,0,"ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+202,0,"H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+204,0,"H2DCmdFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+202,0,"D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+204,0,"D2HRspFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+143,0,"DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+203,0,"DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+205,0,"DataFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+206,0,"DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+207,0,"DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("TL_A_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+208,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+209,0,"instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+210,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+210,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBus(c+207,0,"BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("TL_H2D_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+144,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+211,0,"a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+193,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+150,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+206,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+189,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+207,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+208,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+209,0,"instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+210,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+210,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+141,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("TL_D_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+210,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+210,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("TL_D2H_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+144,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+213,0,"d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+212,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+193,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+150,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+139,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+206,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+210,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+210,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+144,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+141,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_init_top(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_init_top\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmy_ip_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vmy_ip_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmy_ip_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vmy_ip_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_register(Vmy_ip_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_register\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vmy_ip_tb___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vmy_ip_tb___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vmy_ip_tb___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vmy_ip_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_const_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_const_0\n"); );
    // Body
    Vmy_ip_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_ip_tb___024root*>(voidSelf);
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vmy_ip_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_const_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_const_0_sub_0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+123,(0x00000014U),32);
    bufp->fullBit(oldp+124,((1U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+125,((7U & ((vlSymsp->TOP__my_ip_tb.__PVT__tl_o[2U] 
                                      << 2U) | (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+126,((7U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+127,((3U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+128,((0x000000ffU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+129,((1U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+130,(((vlSymsp->TOP__my_ip_tb.__PVT__tl_o[1U] 
                                << 0x00000010U) | (
                                                   vlSymsp->TOP__my_ip_tb.__PVT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+131,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+132,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+133,((1U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+134,((1U & vlSymsp->TOP__my_ip_tb.__PVT__tl_o[0U])));
    bufp->fullBit(oldp+135,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_full));
    bufp->fullBit(oldp+136,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__status_empty));
    bufp->fullCData(oldp+137,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__rdata),8);
    bufp->fullIData(oldp+138,(1U),32);
    bufp->fullBit(oldp+139,(0U));
    bufp->fullBit(oldp+140,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__d_o));
    bufp->fullBit(oldp+141,(1U));
    bufp->fullIData(oldp+142,(4U),32);
    bufp->fullIData(oldp+143,(0x00000020U),32);
    bufp->fullBit(oldp+144,(0U));
    bufp->fullCData(oldp+145,(0U),3);
    bufp->fullBit(oldp+146,(0U));
    bufp->fullIData(oldp+147,(0x00000010U),32);
    bufp->fullSData(oldp+148,(0U),16);
    bufp->fullIData(oldp+149,(8U),32);
    bufp->fullCData(oldp+150,(0U),8);
    bufp->fullIData(oldp+151,(0U),32);
    bufp->fullCData(oldp+152,(9U),4);
    bufp->fullIData(oldp+153,(8U),32);
    bufp->fullIData(oldp+154,(2U),32);
    bufp->fullCData(oldp+155,(1U),4);
    bufp->fullIData(oldp+156,(1U),32);
    bufp->fullCData(oldp+157,(2U),3);
    bufp->fullIData(oldp+158,(0x00000015U),32);
    bufp->fullIData(oldp+159,(0x0000000eU),32);
    bufp->fullCData(oldp+160,(0U),6);
    bufp->fullIData(oldp+161,(0U),22);
    bufp->fullIData(oldp+162,(0U),28);
    bufp->fullCData(oldp+163,(0U),7);
    bufp->fullQData(oldp+164,(0ULL),39);
    bufp->fullQData(oldp+166,(0ULL),64);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+168,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+171,(__Vtemp_2),76);
    bufp->fullCData(oldp+174,(0x2aU),6);
    bufp->fullIData(oldp+175,(0x002a0000U),22);
    bufp->fullIData(oldp+176,(0x0a800000U),28);
    bufp->fullCData(oldp+177,(0x2aU),7);
    bufp->fullQData(oldp+178,(0x0000002a00000000ULL),39);
    bufp->fullQData(oldp+180,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+182,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0x000000aaU;
    bufp->fullWData(oldp+183,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0x00000aa0U;
    bufp->fullWData(oldp+186,(__Vtemp_4),76);
    bufp->fullCData(oldp+189,(0U),4);
    bufp->fullCData(oldp+190,(4U),4);
    bufp->fullCData(oldp+191,(8U),4);
    bufp->fullCData(oldp+192,(0x0cU),4);
    bufp->fullCData(oldp+193,(0U),2);
    bufp->fullCData(oldp+194,(vlSymsp->TOP__my_ip_reg_pkg.__PVT__MY_IP_PERMIT[0]),4);
    bufp->fullCData(oldp+195,(vlSymsp->TOP__my_ip_reg_pkg.__PVT__MY_IP_PERMIT[1]),4);
    bufp->fullCData(oldp+196,(vlSymsp->TOP__my_ip_reg_pkg.__PVT__MY_IP_PERMIT[2]),4);
    bufp->fullCData(oldp+197,(vlSymsp->TOP__my_ip_reg_pkg.__PVT__MY_IP_PERMIT[3]),4);
    bufp->fullIData(oldp+198,(0x0000000cU),32);
    bufp->fullIData(oldp+199,(0x00000018U),32);
    bufp->fullIData(oldp+200,(0x0000001cU),32);
    bufp->fullIData(oldp+201,(0x00505043U),24);
    bufp->fullIData(oldp+202,(0x00000039U),32);
    bufp->fullIData(oldp+203,(7U),32);
    bufp->fullIData(oldp+204,(0x00000040U),32);
    bufp->fullIData(oldp+205,(0x00000027U),32);
    bufp->fullIData(oldp+206,(0U),32);
    bufp->fullIData(oldp+207,(0xffffffffU),32);
    bufp->fullCData(oldp+208,(0U),5);
    bufp->fullCData(oldp+209,(9U),4);
    bufp->fullCData(oldp+210,(0x7fU),7);
    bufp->fullCData(oldp+211,(0U),3);
    bufp->fullCData(oldp+212,(0U),3);
    bufp->fullCData(oldp+213,(0U),3);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_full_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_full_0\n"); );
    // Body
    Vmy_ip_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmy_ip_tb___024root*>(voidSelf);
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vmy_ip_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vmy_ip_tb___024root__trace_full_0_sub_0(Vmy_ip_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmy_ip_tb___024root__trace_full_0_sub_0\n"); );
    Vmy_ip_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSymsp->TOP__my_ip_tb.__PVT__rst_ni));
    bufp->fullBit(oldp+2,((1U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                 >> 0x0000000cU))));
    bufp->fullCData(oldp+3,((7U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                   >> 9U))),3);
    bufp->fullCData(oldp+4,((7U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                   >> 6U))),3);
    bufp->fullCData(oldp+5,((3U & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                   >> 4U))),2);
    bufp->fullCData(oldp+6,((0x000000ffU & ((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[3U] 
                                             << 4U) 
                                            | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[2U] 
                                               >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+7,(((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[2U] 
                              << 4U) | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                                        >> 0x0000001cU))),32);
    bufp->fullCData(oldp+8,((0x0000000fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                                            >> 0x00000018U))),4);
    bufp->fullIData(oldp+9,(((vlSymsp->TOP__my_ip_tb.__PVT__tl_i[1U] 
                              << 8U) | (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                        >> 0x00000018U))),32);
    bufp->fullCData(oldp+10,((0x0000001fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+11,((0x0000000fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+12,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+13,((0x0000007fU & (vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+14,((1U & vlSymsp->TOP__my_ip_tb.__PVT__tl_i[0U])));
    bufp->fullBit(oldp+15,(vlSymsp->TOP__my_ip_tb.__PVT__port_i));
    bufp->fullIData(oldp+16,(vlSymsp->TOP__my_ip_tb.__PVT__error_count),32);
    bufp->fullIData(oldp+17,(vlSymsp->TOP__my_ip_tb.__PVT__rdata),32);
    bufp->fullCData(oldp+18,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit),4);
    bufp->fullBit(oldp+19,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->fullBit(oldp+20,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+22,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+23,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+24,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+25,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->fullBit(oldp+26,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o));
    bufp->fullBit(oldp+27,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o));
    bufp->fullIData(oldp+28,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+29,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i));
    bufp->fullBit(oldp+30,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we));
    bufp->fullBit(oldp+31,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i));
    bufp->fullBit(oldp+32,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->fullBit(oldp+33,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->fullBit(oldp+34,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->fullBit(oldp+35,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->fullBit(oldp+36,(vlSymsp->TOP__my_ip_tb.__PVT__port_o));
    bufp->fullBit(oldp+37,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->fullCData(oldp+38,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->fullCData(oldp+39,((7U & (IData)(((0x000000000000001fULL 
                                             & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                >> 2U)) 
                                            | ((0x000000000000001fULL 
                                                & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                   >> 0x0000000aU)) 
                                               | ((0x000000000000001fULL 
                                                   & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                      >> 0x0000002bU)) 
                                                  | ((QData)((IData)(
                                                                     (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                       << 1U) 
                                                                      | (1U 
                                                                         & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                     >> 0x0000003bU))))))),3);
    bufp->fullCData(oldp+40,((3U & (IData)(((0x000000000000007fULL 
                                             & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q))) 
                                            | ((0x000000000000007fULL 
                                                & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                   >> 8U)) 
                                               | ((0x000000000000007fULL 
                                                   & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                      >> 0x00000029U)) 
                                                  | ((QData)((IData)(
                                                                     (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                       << 1U) 
                                                                      | (1U 
                                                                         & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                     >> 0x00000039U))))))),2);
    bufp->fullCData(oldp+41,((0x000000ffU & (IData)(
                                                    ((0x0000000000007f00ULL 
                                                      & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                         << 8U)) 
                                                     | ((0x0000000000007fffULL 
                                                         & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q))) 
                                                        | ((0x0000000000007fffULL 
                                                            & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                               >> 0x00000021U)) 
                                                           | ((QData)((IData)(
                                                                              (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                               | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                              >> 0x00000031U))))))),8);
    bufp->fullBit(oldp+42,((1U & (IData)(((0x000000000000fe00ULL 
                                           & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                              << 9U)) 
                                          | ((0x000000000000fffeULL 
                                              & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                 << 1U)) 
                                             | ((0x000000000000ffffULL 
                                                 & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                    >> 0x00000020U)) 
                                                | ((QData)((IData)(
                                                                   (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                     << 1U) 
                                                                    | (1U 
                                                                       & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                   >> 0x00000030U))))))));
    bufp->fullIData(oldp+43,((IData)(((0x0000fe0000000000ULL 
                                       & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                          << 0x00000029U)) 
                                      | ((0x0000fffe00000000ULL 
                                          & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                             << 0x00000021U)) 
                                         | ((0x0000ffffffffffffULL 
                                             & (QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q))) 
                                            | ((QData)((IData)(
                                                               (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                 << 1U) 
                                                                | (1U 
                                                                   & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                               >> 0x00000010U)))))),32);
    bufp->fullCData(oldp+44,((0x0000007fU & (IData)(
                                                    ((0x007f000000000000ULL 
                                                      & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                         << 0x00000030U)) 
                                                     | ((0x007fff0000000000ULL 
                                                         & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                            << 0x00000028U)) 
                                                        | ((0x007fffffffffff80ULL 
                                                            & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                               << 7U)) 
                                                           | ((QData)((IData)(
                                                                              (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                               | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                              >> 9U))))))),7);
    bufp->fullCData(oldp+45,((0x0000007fU & (IData)(
                                                    ((0x3f80000000000000ULL 
                                                      & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                                         << 0x00000037U)) 
                                                     | ((0x3fff800000000000ULL 
                                                         & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                            << 0x0000002fU)) 
                                                        | ((0x3fffffffffffc000ULL 
                                                            & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                               << 0x0000000eU)) 
                                                           | ((QData)((IData)(
                                                                              (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                                << 1U) 
                                                                               | (1U 
                                                                                & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                              >> 2U))))))),7);
    bufp->fullBit(oldp+46,((1U & (IData)(((0x7f00000000000000ULL 
                                           & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                              << 0x00000038U)) 
                                          | ((0x7fff000000000000ULL 
                                              & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                                 << 0x00000030U)) 
                                             | ((0x7fffffffffff8000ULL 
                                                 & ((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                    << 0x0000000fU)) 
                                                | ((QData)((IData)(
                                                                   (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                     << 1U) 
                                                                    | (1U 
                                                                       & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))) 
                                                   >> 1U))))))));
    bufp->fullBit(oldp+47,((1U & (IData)((((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                           << 0x00000039U) 
                                          | (((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                              << 0x00000031U) 
                                             | (((QData)((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                                 << 0x00000010U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q) 
                                                                    << 1U) 
                                                                   | (1U 
                                                                      & (~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q)))))))))))));
    bufp->fullSData(oldp+48,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q),16);
    bufp->fullBit(oldp+49,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q));
    bufp->fullBit(oldp+50,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q));
    bufp->fullBit(oldp+51,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q));
    bufp->fullBit(oldp+52,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q));
    bufp->fullCData(oldp+53,(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q),8);
    bufp->fullBit(oldp+54,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe));
    bufp->fullBit(oldp+55,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_core__DOT__u_sync_name__DOT__intq));
    bufp->fullIData(oldp+56,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->fullBit(oldp+57,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q));
    bufp->fullCData(oldp+58,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->fullCData(oldp+59,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->fullCData(oldp+60,(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->fullBit(oldp+61,((1U & (~ ((((VL_REDXOR_4(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rspop_q) 
                                        ^ VL_REDXOR_2(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqsz_q)) 
                                       ^ VL_REDXOR_8(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__reqid_q)) 
                                      ^ VL_REDXOR_32(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__rdata_q)) 
                                     ^ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_q))))));
    bufp->fullBit(oldp+62,(vlSymsp->TOP__my_ip_tb.__PVT__clk_i));
    bufp->fullBit(oldp+63,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                  >> 0x0000000cU))));
    bufp->fullCData(oldp+64,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                    >> 9U))),3);
    bufp->fullCData(oldp+65,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                    >> 6U))),3);
    bufp->fullCData(oldp+66,((3U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                    >> 4U))),2);
    bufp->fullCData(oldp+67,((0x000000ffU & ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                              << 4U) 
                                             | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+68,(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[2U] 
                               << 4U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                         >> 0x0000001cU))),32);
    bufp->fullCData(oldp+69,((0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullIData(oldp+70,(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                               << 8U) | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+71,((0x0000001fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+72,((0x0000000fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+73,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+74,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+75,((1U & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U])));
    bufp->fullBit(oldp+76,((1U & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                  >> 0x00000015U))));
    bufp->fullBit(oldp+77,((1U & ((0x00000fffU & ((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                  | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                     >> 0x00000014U)))));
    bufp->fullBit(oldp+78,((1U & ((0x00001ffeU & ((
                                                   (1U 
                                                    == 
                                                    (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x0000001eU)) 
                                                   & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                      & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                  << 1U)) 
                                  | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                     >> 0x00000013U)))));
    bufp->fullBit(oldp+79,((1U & ((0x00003ffcU & ((
                                                   (1U 
                                                    == 
                                                    (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x0000001eU)) 
                                                   & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                      & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                  << 2U)) 
                                  | ((0x00003fffU & 
                                      ((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                               >> 0x0000001eU)) 
                                       & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                          & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                     | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                        >> 0x00000012U))))));
    bufp->fullCData(oldp+80,((0x000000ffU & ((0x003ffc00U 
                                              & (((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                 << 0x0000000aU)) 
                                             | ((0x003fff00U 
                                                 & (((1U 
                                                      == 
                                                      (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                       >> 0x0000001eU)) 
                                                     & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                        & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                    << 8U)) 
                                                | ((0x003fffffU 
                                                    & (((2U 
                                                         == 
                                                         (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                          >> 0x0000001eU)) 
                                                        & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                           & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                       >> 1U)) 
                                                   | ((0x003fffffU 
                                                       & ((IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q) 
                                                          >> 9U)) 
                                                      | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                         >> 0x0000000aU))))))),8);
    bufp->fullBit(oldp+81,((1U & ((0x007ff800U & ((
                                                   (1U 
                                                    == 
                                                    (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x0000001eU)) 
                                                   & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                      & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                  << 0x0000000bU)) 
                                  | ((0x007ffe00U & 
                                      (((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                >> 0x0000001eU)) 
                                        & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                           & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                       << 9U)) | ((0x007fffffU 
                                                   & ((2U 
                                                       == 
                                                       (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                        >> 0x0000001eU)) 
                                                      & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                         & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))) 
                                                  | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                     >> 9U)))))));
    bufp->fullCData(oldp+82,((0x000000ffU & ((0x7ff80000U 
                                              & (((1U 
                                                   == 
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 0x0000001eU)) 
                                                  & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                     & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                 << 0x00000013U)) 
                                             | ((0x7ffe0000U 
                                                 & (((1U 
                                                      == 
                                                      (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                       >> 0x0000001eU)) 
                                                     & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                        & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                    << 0x00000011U)) 
                                                | ((0x7fffff00U 
                                                    & (((2U 
                                                         == 
                                                         (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                          >> 0x0000001eU)) 
                                                        & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                                                           & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o))) 
                                                       << 8U)) 
                                                   | ((0x7fffffffU 
                                                       & (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q)) 
                                                      | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe) 
                                                         >> 1U))))))),8);
    bufp->fullBit(oldp+83,((1U & (((IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q) 
                                   << 1U) | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__wdata_qe)))));
    bufp->fullBit(oldp+84,(((2U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                    >> 0x0000001eU)) 
                            & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                               & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->fullCData(oldp+85,((0x0000000cU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                             >> 0x0000001cU))),4);
    bufp->fullBit(oldp+86,(((~ (0U != (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__addr_hit))) 
                            & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o) 
                               | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o)))));
    bufp->fullBit(oldp+87,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__we_o) 
                            & (((0U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                        >> 0x0000001eU)) 
                                & (0U != (0x0000000fU 
                                          & (~ ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                 << 8U) 
                                                | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                   >> 0x00000018U)))))) 
                               | ((0U != (1U & (~ (
                                                   (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    << 8U) 
                                                   | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                      >> 0x00000018U))))) 
                                  & ((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                             >> 0x0000001eU)) 
                                     | ((2U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                >> 0x0000001eU)) 
                                        | (3U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 0x0000001eU)))))))));
    bufp->fullBit(oldp+88,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                  >> 0x00000018U))));
    bufp->fullBit(oldp+89,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                  >> 0x00000019U))));
    bufp->fullSData(oldp+90,((0x0000ffffU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                             >> 8U))),16);
    bufp->fullBit(oldp+91,(((1U == (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                    >> 0x0000001eU)) 
                            & ((~ (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__error_i)) 
                               & (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__re_o)))));
    bufp->fullCData(oldp+92,((vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                              >> 0x00000018U)),8);
    bufp->fullBit(oldp+93,((1U & VL_REDXOR_32(((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                << 8U) 
                                               | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                  >> 0x00000018U))))));
    bufp->fullBit(oldp+94,((1U & VL_REDXOR_32((0x0000000fU 
                                               & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 0x00000018U))))));
    bufp->fullBit(oldp+95,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                             ? ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                                & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                   >> 0x00000018U))
                             : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_en__q))));
    bufp->fullBit(oldp+96,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                            & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                               >> 0x00000018U))));
    bufp->fullBit(oldp+97,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                             ? ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                                & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                   >> 0x00000019U))
                             : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_rst__q))));
    bufp->fullBit(oldp+98,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we) 
                            & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                               >> 0x00000019U))));
    bufp->fullSData(oldp+99,((0x0000ffffU & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                                              ? ((vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  << 0x00000018U) 
                                                 | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                    >> 8U))
                                              : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_ctrl_setting__q)))),16);
    bufp->fullSData(oldp+100,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_ctrl_en__DOT__we)
                                ? (0x0000ffffU & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                  >> 8U))
                                : 0U)),16);
    bufp->fullBit(oldp+101,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__outstanding_q) 
                             & vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U])));
    bufp->fullBit(oldp+102,((1U & ((~ (((0U == (7U 
                                                & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                   >> 9U))) 
                                        | ((1U == (7U 
                                                   & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                      >> 9U))) 
                                           | (4U == 
                                              (7U & 
                                               (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U))))) 
                                       & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                                          & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                             & ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                     >> 9U))) 
                                                | ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                        >> 9U))) 
                                                   | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk))))))) 
                                   | ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err) 
                                      | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err))))));
    bufp->fullBit(oldp+103,(((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                           >> 9U))) 
                             | ((1U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                              >> 9U))) 
                                | (4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                >> 9U)))))));
    bufp->fullBit(oldp+104,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk) 
                             & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk) 
                                & ((4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                                 >> 9U))) 
                                   | ((1U == (7U & 
                                              (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                               >> 9U))) 
                                      | (IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->fullBit(oldp+105,((0U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->fullBit(oldp+106,((1U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->fullBit(oldp+107,((4U == (7U & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[3U] 
                                          >> 9U)))));
    bufp->fullCData(oldp+108,((0x0000000fU & ((IData)(1U) 
                                              << (3U 
                                                  & (vlSymsp->TOP__my_ip_tb__tl_if.h2d[1U] 
                                                     >> 0x0000001cU))))),4);
    bufp->fullCData(oldp+109,((0x000000ffU & ((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i)
                                               ? ((
                                                   vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                   << 8U) 
                                                  | (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                                     >> 0x00000018U))
                                               : (IData)(vlSymsp->TOP__my_ip_tb.u_my_ip__DOT__u_my_ip_reg__DOT____Vcellout__u_wdata__q)))),8);
    bufp->fullCData(oldp+110,(((IData)(vlSymsp->TOP__my_ip_tb.__PVT__u_my_ip__DOT__u_my_ip_reg__DOT__u_wdata0_qe__DOT__d_i)
                                ? (vlSymsp->TOP__my_ip_tb__tl_if.h2d[0U] 
                                   >> 0x00000018U) : 0U)),8);
    bufp->fullBit(oldp+111,(vlSymsp->TOP__my_ip_tb__tl_if.__PVT__clk_i));
    bufp->fullBit(oldp+112,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+113,((7U & ((vlSymsp->TOP__my_ip_tb__tl_if.d2h[2U] 
                                      << 2U) | (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+114,((7U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+115,((3U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+116,((0x000000ffU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+117,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+118,(((vlSymsp->TOP__my_ip_tb__tl_if.d2h[1U] 
                                << 0x00000010U) | (
                                                   vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+119,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+120,((0x0000007fU & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+121,((1U & (vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+122,((1U & vlSymsp->TOP__my_ip_tb__tl_if.d2h[0U])));
}
