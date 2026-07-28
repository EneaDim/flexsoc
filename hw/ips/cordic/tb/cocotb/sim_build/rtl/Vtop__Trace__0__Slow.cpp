// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__cordic_lut_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__cordic_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("top_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__top_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("tlul_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_alert_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__prim_alert_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("cordic_lut_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__cordic_lut_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("cordic_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_init_sub__TOP__cordic_reg_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("cordic_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"tl_i_a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"tl_i_a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"tl_i_a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"tl_i_a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+7,0,"tl_i_a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+8,0,"tl_i_a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"tl_i_a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+10,0,"tl_i_a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+11,0,"tl_i_d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"tl_o_d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"tl_o_d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+14,0,"tl_o_d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+15,0,"tl_o_d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+16,0,"tl_o_a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+17,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+18,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+19,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+20,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+21,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+22,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+24,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+25,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+26,0,"instr_type",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+27,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+28,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+29,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+30,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+31,0,"d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+32,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+33,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+34,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+35,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+36,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+37,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+38,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+39,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBus(c+41,0,"cmd_intg_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+42,0,"data_intg_calc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->pushPrefix("u_cordic", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+43,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+45,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+46,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+47,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+48,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+49,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+50,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+51,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+52,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+53,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+54,0,"instr_type",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+55,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+56,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+57,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+58,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"d_opcode",2, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+60,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+61,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+62,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+63,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+64,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+65,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+66,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+67,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+69,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("n_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+70,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+71,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("soft_rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+72,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mode", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+73,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+74,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+75,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+76,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+77,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+78,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+79,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+81,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+82,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+83,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+84,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+85,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+86,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+87,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+88,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+89,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+90,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+91,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+92,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+93,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+94,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+95,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+96,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+97,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+98,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+99,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+100,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+101,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+102,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+103,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+104,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+105,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+106,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+107,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+108,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+109,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+110,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_cordic_core", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+111,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+113,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("n_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+114,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+115,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("soft_rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+116,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mode", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+117,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+118,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+119,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+120,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+121,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+122,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+123,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+124,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+125,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+127,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+128,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+129,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+130,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+131,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+132,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+133,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+134,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+135,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+136,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+137,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+138,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+139,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+140,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+141,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+142,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+143,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+144,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+145,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+146,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+147,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+148,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+149,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+150,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+151,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+152,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+153,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+154,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+155,0,"ctrl_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+156,0,"ctrl_mode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+157,0,"ctrl_soft_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+158,0,"ctrl_rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+159,0,"ctrl_n_iter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+160,0,"ctrl_rsvd2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+161,0,"status_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+162,0,"status_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+163,0,"status_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+164,0,"status_rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+165,0,"x_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"y_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"z_in_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+168,0,"x_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"y_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+170,0,"z_out_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+171,0,"cfg_data_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+172,0,"cfg_frac_width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+173,0,"cfg_max_iter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+174,0,"cfg_rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+834,0,"DATA_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+835,0,"DATA_FRAC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+834,0,"ANGLE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+836,0,"ANGLE_FRAC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+837,0,"GUARD_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+838,0,"INT_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+834,0,"MAX_ITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+839,0,"ITER_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+840,0,"DATA_W_U8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+841,0,"DATA_FRAC_W_U8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+840,0,"MAX_ITER_U8",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+175,0,"state_q",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+176,0,"state_d",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+177,0,"x_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+178,0,"x_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+179,0,"y_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+180,0,"y_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+181,0,"z_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+182,0,"z_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+183,0,"iter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+184,0,"iter_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+185,0,"n_iter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+186,0,"n_iter_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+187,0,"mode_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+188,0,"mode_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+189,0,"status_valid_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+190,0,"status_error_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+191,0,"start_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+192,0,"start_fall_unused",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+193,0,"n_iter_eff",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+194,0,"n_iter_invalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+195,0,"x_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+196,0,"y_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+197,0,"z_init",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+198,0,"x_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+199,0,"y_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+200,0,"x_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+201,0,"y_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+202,0,"z_step",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+203,0,"x_out_next_32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+204,0,"y_out_next_32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+205,0,"z_out_next_32",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_start_edge_detect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+206,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"serial_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"r_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"f_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"serial_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+843,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+213,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+215,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+216,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+217,0,"x_in_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+218,0,"y_in_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 18,0);
    tracep->declBus(c+219,0,"z_in_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+220,0,"x_final_visible",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+221,0,"y_final_visible",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_cordic_reg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+222,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+223,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+224,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+225,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+226,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+227,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+228,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+229,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+230,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+231,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+232,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+233,0,"instr_type",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+234,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+235,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+236,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+237,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+238,0,"d_opcode",2, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+239,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+240,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+241,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+242,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+243,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+244,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+245,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+246,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+247,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("reg2hw", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("ctrl", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd2", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+248,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("n_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+249,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+250,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("soft_rst", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+251,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("mode", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+252,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("start", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+253,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+254,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+255,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+256,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+257,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+258,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+259,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+260,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+261,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+262,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+263,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_in", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+264,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+265,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+266,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+267,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+268,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+269,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+270,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+271,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+272,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+273,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+274,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+275,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+276,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+277,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+278,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("hw2reg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("status", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("busy", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+279,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("valid", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+280,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("error", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+281,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+282,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("x_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+283,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("y_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+284,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("z_out", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+285,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("cfg", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->pushPrefix("data_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+286,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("frac_width", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+287,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("max_iter", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+288,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("rsvd", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+289,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->declBit(c+290,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+844,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+846,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+291,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+293,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+294,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+295,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+296,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+297,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+298,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+299,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+300,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+301,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_reg_h2d", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+302,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+303,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+304,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+305,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+306,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+307,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+308,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+309,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+310,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+311,0,"instr_type",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+312,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+313,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+314,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_reg_d2h", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+315,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+316,0,"d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+317,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+318,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+319,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+320,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+321,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+322,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+323,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+324,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+326,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+327,0,"d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+328,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+329,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+330,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+331,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+332,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+333,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+334,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+335,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+336,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+337,0,"ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+338,0,"ctrl_start_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+339,0,"ctrl_start_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+340,0,"ctrl_mode_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+341,0,"ctrl_mode_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+342,0,"ctrl_soft_rst_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+343,0,"ctrl_soft_rst_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+344,0,"ctrl_rsvd_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+345,0,"ctrl_rsvd_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+346,0,"ctrl_n_iter_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+347,0,"ctrl_n_iter_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+348,0,"ctrl_rsvd2_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+349,0,"ctrl_rsvd2_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+350,0,"status_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"status_busy_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+352,0,"status_valid_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"status_error_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+354,0,"status_rsvd_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+355,0,"x_in_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+356,0,"x_in_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+357,0,"x_in_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+358,0,"y_in_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+359,0,"y_in_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+360,0,"y_in_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+361,0,"z_in_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+362,0,"z_in_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+363,0,"z_in_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+364,0,"x_out_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+365,0,"x_out_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+366,0,"y_out_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+367,0,"y_out_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+368,0,"z_out_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+369,0,"z_out_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+370,0,"cfg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+371,0,"cfg_data_width_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+372,0,"cfg_frac_width_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+373,0,"cfg_max_iter_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+374,0,"cfg_rsvd_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+375,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBit(c+376,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+377,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+378,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_cfg_data_width", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+379,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+380,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+381,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+382,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+383,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+384,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+385,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+386,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+387,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_cfg_frac_width", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+388,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+390,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+391,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+392,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+393,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+394,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+395,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+396,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_cfg_max_iter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+397,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+398,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+399,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+400,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+401,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+403,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+404,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+405,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_cfg_rsvd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+847,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+406,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+408,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+409,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+410,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+411,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+412,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+413,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+414,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_mode", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+843,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+415,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+416,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+418,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+419,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+420,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+421,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+422,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+423,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+424,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+425,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+426,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+427,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+428,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+429,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+430,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+431,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+432,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+433,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+434,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_n_iter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+850,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+851,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+435,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+436,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+437,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+438,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+439,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+440,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+441,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+442,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+443,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+444,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+445,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+446,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+850,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+447,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+448,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+449,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+450,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+451,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+452,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+453,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+454,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_rsvd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+839,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+852,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+455,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+456,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+457,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+458,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+459,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+460,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+461,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+462,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+463,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+464,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+465,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+466,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+839,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+467,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+468,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+469,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+470,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+471,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+472,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+473,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+474,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_rsvd2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+834,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+853,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+475,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+477,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+478,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+479,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+480,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+481,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+482,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+483,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+484,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+485,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+486,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+834,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+487,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+488,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+489,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+490,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+491,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+492,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+493,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+494,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_soft_rst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+843,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+495,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+496,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+497,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+498,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+499,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+500,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+501,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+502,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+503,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+504,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+505,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+506,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+507,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+509,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+510,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+511,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+512,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+513,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+514,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl_start", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+843,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+515,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+516,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+517,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+518,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+519,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+520,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+521,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+522,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+523,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+524,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+525,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+526,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+842,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+527,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+529,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+530,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+531,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+532,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+533,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+534,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_reg_if", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+849,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+849,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+849,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBus(c+844,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+854,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+846,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+535,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+536,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+537,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+538,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+539,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+540,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+541,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+542,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+543,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+544,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+545,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+546,0,"instr_type",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+547,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+548,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+549,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+550,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+551,0,"d_opcode",2, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+552,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+553,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+554,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+555,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+556,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+557,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+558,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+559,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+560,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBus(c+561,0,"en_ifetch_i",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+562,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+563,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+564,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+565,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+566,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+567,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+568,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+569,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+570,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+850,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+855,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+571,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+572,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+573,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+574,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+575,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+576,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+577,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+578,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+579,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+580,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+581,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+582,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+583,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+584,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+585,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+586,0,"rspop_q",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+587,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+588,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+589,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+590,0,"d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+591,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+592,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+593,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+594,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+595,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+596,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+597,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+598,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+599,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_err", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+600,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+601,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+602,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+603,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+604,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+605,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+606,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+607,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+608,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+609,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+610,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+611,0,"instr_type",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+612,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+613,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+614,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+615,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+850,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+855,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+846,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+855,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+616,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+617,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+618,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+619,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+620,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+621,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+622,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+623,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+624,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+625,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+856,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1, 3,0);
    tracep->declBus(c+626,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+849,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+849,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+627,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+628,0,"d_opcode",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+629,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+630,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+631,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+632,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+633,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+634,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+635,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+636,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+637,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+638,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+639,0,"d_opcode",2, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+640,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+641,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+642,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+643,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+644,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+645,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+646,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+647,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+648,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+649,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+849,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+849,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->pushPrefix("tl_i", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+650,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+651,0,"d_opcode",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+652,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+653,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+654,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+655,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+656,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+657,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+658,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+659,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+660,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("tl_o", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+661,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+662,0,"d_opcode",2, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+663,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+664,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+665,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+666,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+667,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+668,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+669,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+670,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+671,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->declBit(c+672,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_busy", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+857,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+673,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+674,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+675,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+676,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+677,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+678,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+680,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+681,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_error", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+857,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+682,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+683,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+684,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+685,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+686,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+687,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+688,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+689,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+690,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_rsvd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+858,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+691,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+692,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+693,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+694,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBit(c+695,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+696,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+697,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+698,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->declBus(c+699,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 28,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_status_valid", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+857,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+700,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+701,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+702,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+703,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+704,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+705,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+706,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+707,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+708,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_x_in", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+859,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+709,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+710,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+711,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+712,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+713,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+714,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+715,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+716,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+717,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+718,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+719,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+720,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+721,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+722,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+723,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+724,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+725,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+726,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+727,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+728,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_x_out", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+729,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+730,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+731,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+732,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+733,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+734,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+735,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+736,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+737,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_y_in", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+859,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+738,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+739,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+740,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+741,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+742,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+743,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+744,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+745,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+746,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+747,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+748,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+749,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+750,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+751,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+752,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+753,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+754,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+755,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+756,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+757,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_y_out", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+758,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+759,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+760,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+761,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+762,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+763,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+764,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+765,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+766,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_z_in", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+859,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+767,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+768,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+769,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+770,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+771,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+772,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+773,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+774,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+775,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+776,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+777,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+778,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+848,0,"SwAccess",5, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+849,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, false,-1);
    tracep->declBit(c+779,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+780,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+781,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+782,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+783,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+784,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+785,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+786,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_z_out", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+860,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBit(c+787,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+788,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+789,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+790,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+791,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+792,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+793,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+794,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+795,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("t", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+796,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+797,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+798,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+799,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+800,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+801,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+802,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+803,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+804,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+805,0,"instr_type",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+806,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+807,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+808,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+845,0,"TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+850,0,"TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+842,0,"TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+861,0,"TL_AUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+835,0,"TL_DUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+846,0,"TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+855,0,"TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+854,0,"SecVolatileRawUnlockEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+862,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+863,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+862,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+864,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+865,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+866,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+865,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+868,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+851,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+870,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+862,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+863,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+865,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+866,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+851,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+870,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+851,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+873,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+876,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+877,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+876,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+878,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+879,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+880,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+879,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+882,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+884,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+885,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+876,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+877,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+879,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+880,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+884,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+885,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+884,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+888,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_alert_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_alert_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("ALERT_TX_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+891,0,"alert_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+892,0,"alert_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("ALERT_RX_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+891,0,"ping_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+892,0,"ping_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+891,0,"ack_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+892,0,"ack_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__cordic_lut_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__cordic_lut_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+893,0,"PI_Q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+894,0,"HALF_PI_Q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("AtanLut", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+809+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__cordic_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__cordic_reg_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+844,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+844,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+846,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+862,0,"CORDIC_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+895,0,"CORDIC_STATUS_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+896,0,"CORDIC_X_IN_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+897,0,"CORDIC_Y_IN_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+898,0,"CORDIC_Z_IN_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+899,0,"CORDIC_X_OUT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+900,0,"CORDIC_Y_OUT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+901,0,"CORDIC_Z_OUT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+902,0,"CORDIC_CFG_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+859,0,"CORDIC_STATUS_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"CORDIC_X_OUT_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"CORDIC_Y_OUT_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"CORDIC_Z_OUT_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+859,0,"CORDIC_CFG_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("CORDIC_PERMIT", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 9; ++i) {
        tracep->declBus(c+825+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, true,(i+0), 3,0);
    }
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+846,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+850,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+903,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+834,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+904,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+905,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+906,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->declBus(c+907,0,"ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+908,0,"H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+909,0,"H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+910,0,"H2DCmdFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+908,0,"D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+909,0,"D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+910,0,"D2HRspFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+845,0,"DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+909,0,"DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+911,0,"DataFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+859,0,"DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+912,0,"DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("TL_A_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+852,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+913,0,"instr_type",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+914,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+914,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBus(c+912,0,"BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("TL_H2D_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+891,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+915,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+916,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+917,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+851,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+859,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+918,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+912,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("a_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+852,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+913,0,"instr_type",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+914,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+914,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+892,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("TL_D_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+914,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+914,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("TL_D2H_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBit(c+891,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+919,0,"d_opcode",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+916,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+917,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+851,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+843,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+859,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("d_user", VerilatedTracePrefixType::STRUCT_PACKED);
    tracep->declBus(c+914,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+914,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->declBit(c+891,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+892,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+834,(0x00000010U),32);
    bufp->fullIData(oldp+835,(0x0000000eU),32);
    bufp->fullIData(oldp+836,(0x0000000dU),32);
    bufp->fullIData(oldp+837,(3U),32);
    bufp->fullIData(oldp+838,(0x00000013U),32);
    bufp->fullIData(oldp+839,(5U),32);
    bufp->fullCData(oldp+840,(0x10U),8);
    bufp->fullCData(oldp+841,(0x0eU),8);
    bufp->fullIData(oldp+842,(1U),32);
    bufp->fullBit(oldp+843,(0U));
    bufp->fullIData(oldp+844,(6U),32);
    bufp->fullIData(oldp+845,(0x00000020U),32);
    bufp->fullIData(oldp+846,(4U),32);
    bufp->fullIData(oldp+847,(8U),32);
    bufp->fullCData(oldp+848,(0U),3);
    bufp->fullBit(oldp+849,(0U));
    bufp->fullIData(oldp+850,(8U),32);
    bufp->fullCData(oldp+851,(0U),8);
    bufp->fullCData(oldp+852,(0U),5);
    bufp->fullSData(oldp+853,(0U),16);
    bufp->fullIData(oldp+854,(0U),32);
    bufp->fullIData(oldp+855,(2U),32);
    bufp->fullCData(oldp+856,(1U),4);
    bufp->fullIData(oldp+857,(1U),32);
    bufp->fullIData(oldp+858,(0x0000001dU),32);
    bufp->fullIData(oldp+859,(0U),32);
    bufp->fullIData(oldp+860,(0x00000020U),32);
    bufp->fullIData(oldp+861,(0x00000015U),32);
    bufp->fullCData(oldp+862,(0U),6);
    bufp->fullIData(oldp+863,(0U),22);
    bufp->fullIData(oldp+864,(0U),28);
    bufp->fullCData(oldp+865,(0U),7);
    bufp->fullQData(oldp+866,(0ULL),39);
    bufp->fullQData(oldp+868,(0ULL),64);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+870,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+873,(__Vtemp_2),76);
    bufp->fullCData(oldp+876,(0x2aU),6);
    bufp->fullIData(oldp+877,(0x002a0000U),22);
    bufp->fullIData(oldp+878,(0x0a800000U),28);
    bufp->fullCData(oldp+879,(0x2aU),7);
    bufp->fullQData(oldp+880,(0x0000002a00000000ULL),39);
    bufp->fullQData(oldp+882,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+884,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0x000000aaU;
    bufp->fullWData(oldp+885,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0x00000aa0U;
    bufp->fullWData(oldp+888,(__Vtemp_4),76);
    bufp->fullBit(oldp+891,(0U));
    bufp->fullBit(oldp+892,(1U));
    bufp->fullSData(oldp+893,(0x6488U),16);
    bufp->fullSData(oldp+894,(0x3244U),16);
    bufp->fullCData(oldp+895,(4U),6);
    bufp->fullCData(oldp+896,(8U),6);
    bufp->fullCData(oldp+897,(0x0cU),6);
    bufp->fullCData(oldp+898,(0x10U),6);
    bufp->fullCData(oldp+899,(0x14U),6);
    bufp->fullCData(oldp+900,(0x18U),6);
    bufp->fullCData(oldp+901,(0x1cU),6);
    bufp->fullCData(oldp+902,(0x20U),6);
    bufp->fullIData(oldp+903,(0x0000000cU),32);
    bufp->fullIData(oldp+904,(0x00000014U),32);
    bufp->fullIData(oldp+905,(0x00000018U),32);
    bufp->fullIData(oldp+906,(0x0000001cU),32);
    bufp->fullIData(oldp+907,(0x00505043U),24);
    bufp->fullIData(oldp+908,(0x00000039U),32);
    bufp->fullIData(oldp+909,(7U),32);
    bufp->fullIData(oldp+910,(0x00000040U),32);
    bufp->fullIData(oldp+911,(0x00000027U),32);
    bufp->fullIData(oldp+912,(0xffffffffU),32);
    bufp->fullCData(oldp+913,(9U),4);
    bufp->fullCData(oldp+914,(0x7fU),7);
    bufp->fullCData(oldp+915,(0U),3);
    bufp->fullCData(oldp+916,(0U),3);
    bufp->fullCData(oldp+917,(0U),2);
    bufp->fullCData(oldp+918,(0U),4);
    bufp->fullCData(oldp+919,(0U),3);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+1,(vlSelfRef.cordic_tb__DOT__clk_i));
    bufp->fullBit(oldp+2,(vlSelfRef.cordic_tb__DOT__rst_ni));
    bufp->fullBit(oldp+3,(vlSelfRef.cordic_tb__DOT__tl_i_a_valid));
    bufp->fullCData(oldp+4,(vlSelfRef.cordic_tb__DOT__tl_i_a_opcode),3);
    bufp->fullCData(oldp+5,(vlSelfRef.cordic_tb__DOT__tl_i_a_param),3);
    bufp->fullCData(oldp+6,(vlSelfRef.cordic_tb__DOT__tl_i_a_size),2);
    bufp->fullCData(oldp+7,(vlSelfRef.cordic_tb__DOT__tl_i_a_source),8);
    bufp->fullIData(oldp+8,(vlSelfRef.cordic_tb__DOT__tl_i_a_address),32);
    bufp->fullCData(oldp+9,(vlSelfRef.cordic_tb__DOT__tl_i_a_mask),4);
    bufp->fullIData(oldp+10,(vlSelfRef.cordic_tb__DOT__tl_i_a_data),32);
    bufp->fullBit(oldp+11,(vlSelfRef.cordic_tb__DOT__tl_i_d_ready));
    bufp->fullBit(oldp+12,(vlSelfRef.cordic_tb__DOT__tl_o_d_valid));
    bufp->fullCData(oldp+13,(vlSelfRef.cordic_tb__DOT__tl_o_d_opcode),3);
    bufp->fullIData(oldp+14,(vlSelfRef.cordic_tb__DOT__tl_o_d_data),32);
    bufp->fullBit(oldp+15,(vlSelfRef.cordic_tb__DOT__tl_o_d_error));
    bufp->fullBit(oldp+16,(vlSelfRef.cordic_tb__DOT__tl_o_a_ready));
    bufp->fullBit(oldp+17,((1U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->fullCData(oldp+18,((7U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->fullCData(oldp+19,((7U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->fullCData(oldp+20,((3U & (vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->fullCData(oldp+21,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+22,(((vlSelfRef.cordic_tb__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->fullCData(oldp+23,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullIData(oldp+24,(((vlSelfRef.cordic_tb__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+25,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+26,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+27,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+28,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+29,((1U & vlSelfRef.cordic_tb__DOT__tl_i[0U])));
    bufp->fullBit(oldp+30,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->fullCData(oldp+31,((7U & ((vlSelfRef.cordic_tb__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+32,((7U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->fullCData(oldp+33,((3U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->fullCData(oldp+34,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->fullBit(oldp+35,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->fullIData(oldp+36,(((vlSelfRef.cordic_tb__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->fullCData(oldp+37,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->fullCData(oldp+38,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->fullBit(oldp+39,((1U & (vlSelfRef.cordic_tb__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->fullBit(oldp+40,((1U & vlSelfRef.cordic_tb__DOT__tl_o[0U])));
    bufp->fullCData(oldp+41,(vlSelfRef.cordic_tb__DOT__cmd_intg_calc),7);
    bufp->fullCData(oldp+42,(vlSelfRef.cordic_tb__DOT__data_intg_calc),7);
    bufp->fullBit(oldp+43,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__clk_i));
    bufp->fullBit(oldp+44,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__rst_ni));
    bufp->fullBit(oldp+45,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->fullCData(oldp+46,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->fullCData(oldp+47,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->fullCData(oldp+48,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->fullCData(oldp+49,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+50,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->fullCData(oldp+51,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullIData(oldp+52,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+53,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+54,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+55,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+56,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+57,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_i[0U])));
    bufp->fullBit(oldp+58,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->fullCData(oldp+59,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+60,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->fullCData(oldp+61,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->fullCData(oldp+62,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->fullBit(oldp+63,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->fullIData(oldp+64,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->fullCData(oldp+65,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->fullCData(oldp+66,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->fullBit(oldp+67,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->fullBit(oldp+68,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__tl_o[0U])));
    bufp->fullSData(oldp+69,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[9U] 
                                              << 5U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                                >> 0x0000001bU)))),16);
    bufp->fullCData(oldp+70,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                             >> 0x00000013U))),8);
    bufp->fullCData(oldp+71,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                             >> 0x0000000eU))),5);
    bufp->fullBit(oldp+72,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                  >> 0x0000000dU))));
    bufp->fullBit(oldp+73,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                  >> 0x0000000cU))));
    bufp->fullBit(oldp+74,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                  >> 0x0000000bU))));
    bufp->fullIData(oldp+75,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[8U] 
                                              << 0x00000012U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                                >> 0x0000000eU)))),29);
    bufp->fullBit(oldp+76,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 0x0000000dU))));
    bufp->fullBit(oldp+77,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 0x0000000cU))));
    bufp->fullBit(oldp+78,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 0x0000000bU))));
    bufp->fullBit(oldp+79,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 0x0000000aU))));
    bufp->fullBit(oldp+80,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 9U))));
    bufp->fullBit(oldp+81,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 8U))));
    bufp->fullBit(oldp+82,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                                  >> 7U))));
    bufp->fullIData(oldp+83,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[7U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
                                                  >> 7U))),32);
    bufp->fullIData(oldp+84,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[6U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
                                                  >> 7U))),32);
    bufp->fullIData(oldp+85,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[5U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
                                                  >> 7U))),32);
    bufp->fullIData(oldp+86,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[4U] 
                               << 0x00000019U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                                                  >> 7U))),32);
    bufp->fullBit(oldp+87,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                                  >> 6U))));
    bufp->fullIData(oldp+88,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[3U] 
                               << 0x0000001aU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                                                  >> 6U))),32);
    bufp->fullBit(oldp+89,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                                  >> 5U))));
    bufp->fullIData(oldp+90,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[2U] 
                               << 0x0000001bU) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                                  >> 5U))),32);
    bufp->fullBit(oldp+91,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                  >> 4U))));
    bufp->fullCData(oldp+92,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[1U] 
                                              << 4U) 
                                             | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullBit(oldp+93,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                  >> 0x0000001bU))));
    bufp->fullCData(oldp+94,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                             >> 0x00000013U))),8);
    bufp->fullBit(oldp+95,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                  >> 0x00000012U))));
    bufp->fullCData(oldp+96,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                             >> 0x0000000aU))),8);
    bufp->fullBit(oldp+97,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                  >> 9U))));
    bufp->fullCData(oldp+98,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U] 
                                             >> 1U))),8);
    bufp->fullBit(oldp+99,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__reg2hw[0U])));
    bufp->fullBit(oldp+100,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                             >> 0x0000001fU)));
    bufp->fullBit(oldp+101,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                                   >> 0x0000001eU))));
    bufp->fullBit(oldp+102,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U] 
                                   >> 0x0000001dU))));
    bufp->fullIData(oldp+103,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[4U])),29);
    bufp->fullIData(oldp+104,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[3U]),32);
    bufp->fullIData(oldp+105,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[2U]),32);
    bufp->fullIData(oldp+106,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[1U]),32);
    bufp->fullCData(oldp+107,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                               >> 0x00000018U)),8);
    bufp->fullCData(oldp+108,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+109,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U] 
                                              >> 8U))),8);
    bufp->fullCData(oldp+110,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__hw2reg[0U])),8);
    bufp->fullBit(oldp+111,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__clk_i));
    bufp->fullBit(oldp+112,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__rst_ni));
    bufp->fullSData(oldp+113,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[9U] 
                                               << 5U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                                 >> 0x0000001bU)))),16);
    bufp->fullCData(oldp+114,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                              >> 0x00000013U))),8);
    bufp->fullCData(oldp+115,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                              >> 0x0000000eU))),5);
    bufp->fullBit(oldp+116,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                   >> 0x0000000dU))));
    bufp->fullBit(oldp+117,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                   >> 0x0000000cU))));
    bufp->fullBit(oldp+118,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                   >> 0x0000000bU))));
    bufp->fullIData(oldp+119,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[8U] 
                                               << 0x00000012U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                                 >> 0x0000000eU)))),29);
    bufp->fullBit(oldp+120,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 0x0000000dU))));
    bufp->fullBit(oldp+121,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 0x0000000cU))));
    bufp->fullBit(oldp+122,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 0x0000000bU))));
    bufp->fullBit(oldp+123,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 0x0000000aU))));
    bufp->fullBit(oldp+124,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 9U))));
    bufp->fullBit(oldp+125,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 8U))));
    bufp->fullBit(oldp+126,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                   >> 7U))));
    bufp->fullIData(oldp+127,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[7U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+128,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[6U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+129,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[5U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+130,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[4U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                                                   >> 7U))),32);
    bufp->fullBit(oldp+131,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                                   >> 6U))));
    bufp->fullIData(oldp+132,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[3U] 
                                << 0x0000001aU) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                                                   >> 6U))),32);
    bufp->fullBit(oldp+133,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                                   >> 5U))));
    bufp->fullIData(oldp+134,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[2U] 
                                << 0x0000001bU) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                                   >> 5U))),32);
    bufp->fullBit(oldp+135,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                   >> 4U))));
    bufp->fullCData(oldp+136,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[1U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullBit(oldp+137,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                   >> 0x0000001bU))));
    bufp->fullCData(oldp+138,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                              >> 0x00000013U))),8);
    bufp->fullBit(oldp+139,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                   >> 0x00000012U))));
    bufp->fullCData(oldp+140,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                              >> 0x0000000aU))),8);
    bufp->fullBit(oldp+141,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                   >> 9U))));
    bufp->fullCData(oldp+142,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U] 
                                              >> 1U))),8);
    bufp->fullBit(oldp+143,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__reg2hw[0U])));
    bufp->fullBit(oldp+144,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                             >> 0x0000001fU)));
    bufp->fullBit(oldp+145,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                                   >> 0x0000001eU))));
    bufp->fullBit(oldp+146,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U] 
                                   >> 0x0000001dU))));
    bufp->fullIData(oldp+147,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[4U])),29);
    bufp->fullIData(oldp+148,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[3U]),32);
    bufp->fullIData(oldp+149,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[2U]),32);
    bufp->fullIData(oldp+150,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[1U]),32);
    bufp->fullCData(oldp+151,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                               >> 0x00000018U)),8);
    bufp->fullCData(oldp+152,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+153,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U] 
                                              >> 8U))),8);
    bufp->fullCData(oldp+154,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__hw2reg[0U])),8);
    bufp->fullBit(oldp+155,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_start));
    bufp->fullBit(oldp+156,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_mode));
    bufp->fullBit(oldp+157,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_soft_rst));
    bufp->fullCData(oldp+158,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd),5);
    bufp->fullCData(oldp+159,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_n_iter),8);
    bufp->fullSData(oldp+160,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__ctrl_rsvd2),16);
    bufp->fullBit(oldp+161,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_busy));
    bufp->fullBit(oldp+162,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid));
    bufp->fullBit(oldp+163,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error));
    bufp->fullIData(oldp+164,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_rsvd),29);
    bufp->fullIData(oldp+165,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_in_value),32);
    bufp->fullIData(oldp+166,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_in_value),32);
    bufp->fullIData(oldp+167,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_in_value),32);
    bufp->fullIData(oldp+168,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_value),32);
    bufp->fullIData(oldp+169,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_value),32);
    bufp->fullIData(oldp+170,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_value),32);
    bufp->fullCData(oldp+171,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_data_width),8);
    bufp->fullCData(oldp+172,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_frac_width),8);
    bufp->fullCData(oldp+173,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_max_iter),8);
    bufp->fullCData(oldp+174,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__cfg_rsvd),8);
    bufp->fullBit(oldp+175,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_q));
    bufp->fullBit(oldp+176,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__state_d));
    bufp->fullIData(oldp+177,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_q),19);
    bufp->fullIData(oldp+178,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_d),19);
    bufp->fullIData(oldp+179,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_q),19);
    bufp->fullIData(oldp+180,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_d),19);
    bufp->fullSData(oldp+181,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_q),16);
    bufp->fullSData(oldp+182,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_d),16);
    bufp->fullCData(oldp+183,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_q),5);
    bufp->fullCData(oldp+184,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__iter_d),5);
    bufp->fullCData(oldp+185,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_q),8);
    bufp->fullCData(oldp+186,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_d),8);
    bufp->fullBit(oldp+187,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_q));
    bufp->fullBit(oldp+188,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__mode_d));
    bufp->fullBit(oldp+189,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_valid_d));
    bufp->fullBit(oldp+190,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__status_error_d));
    bufp->fullBit(oldp+191,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_rise));
    bufp->fullBit(oldp+192,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__start_fall_unused));
    bufp->fullCData(oldp+193,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_eff),8);
    bufp->fullBit(oldp+194,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__n_iter_invalid));
    bufp->fullIData(oldp+195,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_init),19);
    bufp->fullIData(oldp+196,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_init),19);
    bufp->fullSData(oldp+197,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_init),16);
    bufp->fullIData(oldp+198,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_shift),19);
    bufp->fullIData(oldp+199,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_shift),19);
    bufp->fullIData(oldp+200,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_step),19);
    bufp->fullIData(oldp+201,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_step),19);
    bufp->fullSData(oldp+202,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_step),16);
    bufp->fullIData(oldp+203,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__x_out_next_32),32);
    bufp->fullIData(oldp+204,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__y_out_next_32),32);
    bufp->fullIData(oldp+205,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__z_out_next_32),32);
    bufp->fullBit(oldp+206,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__clk_i));
    bufp->fullBit(oldp+207,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__rst_ni));
    bufp->fullBit(oldp+208,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__en_i));
    bufp->fullBit(oldp+209,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_i));
    bufp->fullBit(oldp+210,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__r_edge_o));
    bufp->fullBit(oldp+211,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__f_edge_o));
    bufp->fullBit(oldp+212,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__serial_q));
    bufp->fullBit(oldp+213,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+214,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+215,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+216,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__u_start_edge_detect__DOT__u_sync_1__DOT__q_o));
    bufp->fullIData(oldp+217,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__x_in_int),19);
    bufp->fullIData(oldp+218,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__y_in_int),19);
    bufp->fullSData(oldp+219,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk1__DOT__z_in_int),16);
    bufp->fullSData(oldp+220,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__x_final_visible),16);
    bufp->fullSData(oldp+221,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_core__DOT__unnamedblk2__DOT__y_final_visible),16);
    bufp->fullBit(oldp+222,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__clk_i));
    bufp->fullBit(oldp+223,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__rst_ni));
    bufp->fullBit(oldp+224,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+225,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+226,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+227,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+228,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+229,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+230,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+231,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+232,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+233,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+234,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+235,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+236,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_i[0U])));
    bufp->fullBit(oldp+237,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+238,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+239,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+240,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+241,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+242,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+243,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+244,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+245,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+246,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+247,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o[0U])));
    bufp->fullSData(oldp+248,((0x0000ffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[9U] 
                                               << 5U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                                 >> 0x0000001bU)))),16);
    bufp->fullCData(oldp+249,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                              >> 0x00000013U))),8);
    bufp->fullCData(oldp+250,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                              >> 0x0000000eU))),5);
    bufp->fullBit(oldp+251,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                   >> 0x0000000dU))));
    bufp->fullBit(oldp+252,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                   >> 0x0000000cU))));
    bufp->fullBit(oldp+253,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                   >> 0x0000000bU))));
    bufp->fullIData(oldp+254,((0x1fffffffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[8U] 
                                               << 0x00000012U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                                 >> 0x0000000eU)))),29);
    bufp->fullBit(oldp+255,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 0x0000000dU))));
    bufp->fullBit(oldp+256,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 0x0000000cU))));
    bufp->fullBit(oldp+257,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 0x0000000bU))));
    bufp->fullBit(oldp+258,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 0x0000000aU))));
    bufp->fullBit(oldp+259,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 9U))));
    bufp->fullBit(oldp+260,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 8U))));
    bufp->fullBit(oldp+261,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                   >> 7U))));
    bufp->fullIData(oldp+262,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[7U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+263,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[6U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+264,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[5U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
                                                   >> 7U))),32);
    bufp->fullIData(oldp+265,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[4U] 
                                << 0x00000019U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                                                   >> 7U))),32);
    bufp->fullBit(oldp+266,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                                   >> 6U))));
    bufp->fullIData(oldp+267,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[3U] 
                                << 0x0000001aU) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                                                   >> 6U))),32);
    bufp->fullBit(oldp+268,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                                   >> 5U))));
    bufp->fullIData(oldp+269,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[2U] 
                                << 0x0000001bU) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                                   >> 5U))),32);
    bufp->fullBit(oldp+270,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                   >> 4U))));
    bufp->fullCData(oldp+271,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[1U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullBit(oldp+272,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                   >> 0x0000001bU))));
    bufp->fullCData(oldp+273,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                              >> 0x00000013U))),8);
    bufp->fullBit(oldp+274,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                   >> 0x00000012U))));
    bufp->fullCData(oldp+275,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                              >> 0x0000000aU))),8);
    bufp->fullBit(oldp+276,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                   >> 9U))));
    bufp->fullCData(oldp+277,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U] 
                                              >> 1U))),8);
    bufp->fullBit(oldp+278,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg2hw[0U])));
    bufp->fullBit(oldp+279,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                             >> 0x0000001fU)));
    bufp->fullBit(oldp+280,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                                   >> 0x0000001eU))));
    bufp->fullBit(oldp+281,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U] 
                                   >> 0x0000001dU))));
    bufp->fullIData(oldp+282,((0x1fffffffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[4U])),29);
    bufp->fullIData(oldp+283,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[3U]),32);
    bufp->fullIData(oldp+284,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[2U]),32);
    bufp->fullIData(oldp+285,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[1U]),32);
    bufp->fullCData(oldp+286,((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                               >> 0x00000018U)),8);
    bufp->fullCData(oldp+287,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+288,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U] 
                                              >> 8U))),8);
    bufp->fullCData(oldp+289,((0x000000ffU & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__hw2reg[0U])),8);
    bufp->fullBit(oldp+290,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__devmode_i));
    bufp->fullBit(oldp+291,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_we));
    bufp->fullBit(oldp+292,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_re));
    bufp->fullCData(oldp+293,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_addr),6);
    bufp->fullIData(oldp+294,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_wdata),32);
    bufp->fullCData(oldp+295,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_be),4);
    bufp->fullIData(oldp+296,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata),32);
    bufp->fullBit(oldp+297,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_error));
    bufp->fullBit(oldp+298,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addrmiss));
    bufp->fullBit(oldp+299,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__wr_err));
    bufp->fullIData(oldp+300,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+301,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__reg_busy));
    bufp->fullBit(oldp+302,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+303,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+304,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+305,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+306,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[3U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+307,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[2U] 
                                << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+308,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+309,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[1U] 
                                << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+310,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+311,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+312,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+313,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+314,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_h2d[0U])));
    bufp->fullBit(oldp+315,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+316,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+317,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+318,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+319,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+320,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+321,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+322,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+323,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+324,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+325,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_reg_d2h[0U])));
    bufp->fullBit(oldp+326,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+327,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+328,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+329,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+330,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+331,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+332,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+333,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+334,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+335,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+336,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__tl_o_pre[0U])));
    bufp->fullBit(oldp+337,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_we));
    bufp->fullBit(oldp+338,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_qs));
    bufp->fullBit(oldp+339,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_start_wd));
    bufp->fullBit(oldp+340,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_qs));
    bufp->fullBit(oldp+341,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_mode_wd));
    bufp->fullBit(oldp+342,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_qs));
    bufp->fullBit(oldp+343,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_soft_rst_wd));
    bufp->fullCData(oldp+344,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_qs),5);
    bufp->fullCData(oldp+345,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd_wd),5);
    bufp->fullCData(oldp+346,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_qs),8);
    bufp->fullCData(oldp+347,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_n_iter_wd),8);
    bufp->fullSData(oldp+348,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_qs),16);
    bufp->fullSData(oldp+349,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__ctrl_rsvd2_wd),16);
    bufp->fullBit(oldp+350,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_re));
    bufp->fullBit(oldp+351,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_busy_qs));
    bufp->fullBit(oldp+352,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_valid_qs));
    bufp->fullBit(oldp+353,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_error_qs));
    bufp->fullIData(oldp+354,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__status_rsvd_qs),29);
    bufp->fullBit(oldp+355,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_we));
    bufp->fullIData(oldp+356,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_qs),32);
    bufp->fullIData(oldp+357,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_in_wd),32);
    bufp->fullBit(oldp+358,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_we));
    bufp->fullIData(oldp+359,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_qs),32);
    bufp->fullIData(oldp+360,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_in_wd),32);
    bufp->fullBit(oldp+361,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_we));
    bufp->fullIData(oldp+362,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_qs),32);
    bufp->fullIData(oldp+363,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_in_wd),32);
    bufp->fullBit(oldp+364,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_re));
    bufp->fullIData(oldp+365,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__x_out_qs),32);
    bufp->fullBit(oldp+366,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_re));
    bufp->fullIData(oldp+367,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__y_out_qs),32);
    bufp->fullBit(oldp+368,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_re));
    bufp->fullIData(oldp+369,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__z_out_qs),32);
    bufp->fullBit(oldp+370,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_re));
    bufp->fullCData(oldp+371,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_data_width_qs),8);
    bufp->fullCData(oldp+372,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_frac_width_qs),8);
    bufp->fullCData(oldp+373,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_max_iter_qs),8);
    bufp->fullCData(oldp+374,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__cfg_rsvd_qs),8);
    bufp->fullSData(oldp+375,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__addr_hit),9);
    bufp->fullBit(oldp+376,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__shadow_busy));
    bufp->fullBit(oldp+377,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_wdata));
    bufp->fullBit(oldp+378,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__unused_be));
    bufp->fullBit(oldp+379,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__re));
    bufp->fullBit(oldp+380,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__we));
    bufp->fullCData(oldp+381,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__wd),8);
    bufp->fullCData(oldp+382,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__d),8);
    bufp->fullBit(oldp+383,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qe));
    bufp->fullBit(oldp+384,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qre));
    bufp->fullCData(oldp+385,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__q),8);
    bufp->fullCData(oldp+386,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__ds),8);
    bufp->fullCData(oldp+387,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_data_width__DOT__qs),8);
    bufp->fullBit(oldp+388,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__re));
    bufp->fullBit(oldp+389,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__we));
    bufp->fullCData(oldp+390,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__wd),8);
    bufp->fullCData(oldp+391,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__d),8);
    bufp->fullBit(oldp+392,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qe));
    bufp->fullBit(oldp+393,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qre));
    bufp->fullCData(oldp+394,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__q),8);
    bufp->fullCData(oldp+395,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__ds),8);
    bufp->fullCData(oldp+396,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_frac_width__DOT__qs),8);
    bufp->fullBit(oldp+397,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__re));
    bufp->fullBit(oldp+398,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__we));
    bufp->fullCData(oldp+399,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__wd),8);
    bufp->fullCData(oldp+400,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__d),8);
    bufp->fullBit(oldp+401,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qe));
    bufp->fullBit(oldp+402,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qre));
    bufp->fullCData(oldp+403,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__q),8);
    bufp->fullCData(oldp+404,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__ds),8);
    bufp->fullCData(oldp+405,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_max_iter__DOT__qs),8);
    bufp->fullBit(oldp+406,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__re));
    bufp->fullBit(oldp+407,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__we));
    bufp->fullCData(oldp+408,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__wd),8);
    bufp->fullCData(oldp+409,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__d),8);
    bufp->fullBit(oldp+410,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qe));
    bufp->fullBit(oldp+411,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qre));
    bufp->fullCData(oldp+412,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__q),8);
    bufp->fullCData(oldp+413,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__ds),8);
    bufp->fullCData(oldp+414,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_cfg_rsvd__DOT__qs),8);
    bufp->fullBit(oldp+415,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__clk_i));
    bufp->fullBit(oldp+416,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__rst_ni));
    bufp->fullBit(oldp+417,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__we));
    bufp->fullBit(oldp+418,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wd));
    bufp->fullBit(oldp+419,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__de));
    bufp->fullBit(oldp+420,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__d));
    bufp->fullBit(oldp+421,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qe));
    bufp->fullBit(oldp+422,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__q));
    bufp->fullBit(oldp+423,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__ds));
    bufp->fullBit(oldp+424,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__qs));
    bufp->fullBit(oldp+425,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en));
    bufp->fullBit(oldp+426,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_data));
    bufp->fullBit(oldp+427,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+428,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+429,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__de));
    bufp->fullBit(oldp+430,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__d));
    bufp->fullBit(oldp+431,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+432,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+433,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+434,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_mode__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+435,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__clk_i));
    bufp->fullBit(oldp+436,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__rst_ni));
    bufp->fullBit(oldp+437,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__we));
    bufp->fullCData(oldp+438,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wd),8);
    bufp->fullBit(oldp+439,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__de));
    bufp->fullCData(oldp+440,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__d),8);
    bufp->fullBit(oldp+441,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qe));
    bufp->fullCData(oldp+442,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__q),8);
    bufp->fullCData(oldp+443,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__ds),8);
    bufp->fullCData(oldp+444,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__qs),8);
    bufp->fullBit(oldp+445,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en));
    bufp->fullCData(oldp+446,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_data),8);
    bufp->fullBit(oldp+447,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+448,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->fullBit(oldp+449,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__de));
    bufp->fullCData(oldp+450,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__d),8);
    bufp->fullCData(oldp+451,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__q),8);
    bufp->fullBit(oldp+452,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+453,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->fullCData(oldp+454,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_n_iter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->fullBit(oldp+455,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__clk_i));
    bufp->fullBit(oldp+456,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__rst_ni));
    bufp->fullBit(oldp+457,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__we));
    bufp->fullCData(oldp+458,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wd),5);
    bufp->fullBit(oldp+459,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__de));
    bufp->fullCData(oldp+460,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__d),5);
    bufp->fullBit(oldp+461,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qe));
    bufp->fullCData(oldp+462,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__q),5);
    bufp->fullCData(oldp+463,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__ds),5);
    bufp->fullCData(oldp+464,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__qs),5);
    bufp->fullBit(oldp+465,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en));
    bufp->fullCData(oldp+466,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_data),5);
    bufp->fullBit(oldp+467,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+468,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wd),5);
    bufp->fullBit(oldp+469,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__de));
    bufp->fullCData(oldp+470,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__d),5);
    bufp->fullCData(oldp+471,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__q),5);
    bufp->fullBit(oldp+472,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+473,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__wr_data),5);
    bufp->fullCData(oldp+474,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),5);
    bufp->fullBit(oldp+475,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__clk_i));
    bufp->fullBit(oldp+476,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__rst_ni));
    bufp->fullBit(oldp+477,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__we));
    bufp->fullSData(oldp+478,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wd),16);
    bufp->fullBit(oldp+479,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__de));
    bufp->fullSData(oldp+480,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__d),16);
    bufp->fullBit(oldp+481,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qe));
    bufp->fullSData(oldp+482,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__q),16);
    bufp->fullSData(oldp+483,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__ds),16);
    bufp->fullSData(oldp+484,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__qs),16);
    bufp->fullBit(oldp+485,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en));
    bufp->fullSData(oldp+486,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_data),16);
    bufp->fullBit(oldp+487,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__we));
    bufp->fullSData(oldp+488,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->fullBit(oldp+489,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__de));
    bufp->fullSData(oldp+490,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__d),16);
    bufp->fullSData(oldp+491,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__q),16);
    bufp->fullBit(oldp+492,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullSData(oldp+493,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->fullSData(oldp+494,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_rsvd2__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->fullBit(oldp+495,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__clk_i));
    bufp->fullBit(oldp+496,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__rst_ni));
    bufp->fullBit(oldp+497,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__we));
    bufp->fullBit(oldp+498,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wd));
    bufp->fullBit(oldp+499,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__de));
    bufp->fullBit(oldp+500,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__d));
    bufp->fullBit(oldp+501,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qe));
    bufp->fullBit(oldp+502,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__q));
    bufp->fullBit(oldp+503,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__ds));
    bufp->fullBit(oldp+504,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__qs));
    bufp->fullBit(oldp+505,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en));
    bufp->fullBit(oldp+506,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_data));
    bufp->fullBit(oldp+507,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+508,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+509,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__de));
    bufp->fullBit(oldp+510,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__d));
    bufp->fullBit(oldp+511,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+512,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+513,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+514,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_soft_rst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+515,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__clk_i));
    bufp->fullBit(oldp+516,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__rst_ni));
    bufp->fullBit(oldp+517,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__we));
    bufp->fullBit(oldp+518,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wd));
    bufp->fullBit(oldp+519,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__de));
    bufp->fullBit(oldp+520,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__d));
    bufp->fullBit(oldp+521,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qe));
    bufp->fullBit(oldp+522,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__q));
    bufp->fullBit(oldp+523,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__ds));
    bufp->fullBit(oldp+524,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__qs));
    bufp->fullBit(oldp+525,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en));
    bufp->fullBit(oldp+526,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_data));
    bufp->fullBit(oldp+527,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+528,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+529,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__de));
    bufp->fullBit(oldp+530,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__d));
    bufp->fullBit(oldp+531,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+532,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+533,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+534,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_ctrl_start__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+535,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__clk_i));
    bufp->fullBit(oldp+536,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rst_ni));
    bufp->fullBit(oldp+537,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+538,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+539,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+540,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+541,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+542,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+543,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+544,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+545,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+546,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+547,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+548,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+549,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_i[0U])));
    bufp->fullBit(oldp+550,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+551,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+552,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+553,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+554,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+555,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+556,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+557,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+558,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+559,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+560,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o[0U])));
    bufp->fullCData(oldp+561,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__en_ifetch_i),4);
    bufp->fullBit(oldp+562,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error_o));
    bufp->fullBit(oldp+563,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__re_o));
    bufp->fullBit(oldp+564,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__we_o));
    bufp->fullCData(oldp+565,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_o),6);
    bufp->fullIData(oldp+566,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wdata_o),32);
    bufp->fullCData(oldp+567,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__be_o),4);
    bufp->fullBit(oldp+568,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__busy_i));
    bufp->fullIData(oldp+569,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_i),32);
    bufp->fullBit(oldp+570,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_i));
    bufp->fullBit(oldp+571,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->fullBit(oldp+572,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->fullBit(oldp+573,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__d_ack));
    bufp->fullIData(oldp+574,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata),32);
    bufp->fullIData(oldp+575,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->fullBit(oldp+576,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error_q));
    bufp->fullBit(oldp+577,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__error));
    bufp->fullBit(oldp+578,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->fullBit(oldp+579,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->fullBit(oldp+580,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__intg_error));
    bufp->fullBit(oldp+581,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__addr_align_err));
    bufp->fullBit(oldp+582,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->fullBit(oldp+583,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_err));
    bufp->fullCData(oldp+584,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->fullCData(oldp+585,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->fullCData(oldp+586,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->fullBit(oldp+587,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->fullBit(oldp+588,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->fullBit(oldp+589,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+590,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+591,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+592,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+593,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+594,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+595,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+596,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+597,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+598,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+599,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__tl_o_pre[0U])));
    bufp->fullBit(oldp+600,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i));
    bufp->fullBit(oldp+601,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni));
    bufp->fullBit(oldp+602,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+603,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+604,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+605,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+606,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+607,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+608,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+609,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+610,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+611,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+612,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+613,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+614,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U])));
    bufp->fullBit(oldp+615,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o));
    bufp->fullBit(oldp+616,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed));
    bufp->fullBit(oldp+617,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed));
    bufp->fullBit(oldp+618,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full));
    bufp->fullBit(oldp+619,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial));
    bufp->fullBit(oldp+620,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get));
    bufp->fullBit(oldp+621,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+622,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+623,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+624,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+625,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->fullCData(oldp+626,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_err__DOT__mask),4);
    bufp->fullBit(oldp+627,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+628,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+629,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+630,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+631,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+632,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+633,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+634,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+635,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+636,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+637,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->fullBit(oldp+638,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+639,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+640,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+641,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+642,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+643,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+644,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+645,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+646,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+647,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+648,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->fullBit(oldp+649,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->fullBit(oldp+650,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+651,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+652,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+653,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+654,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+655,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+656,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+657,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+658,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+659,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+660,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->fullBit(oldp+661,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+662,((7U & ((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+663,((7U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+664,((3U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+665,((0x000000ffU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+666,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+667,(((vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                << 0x00000010U) | (
                                                   vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+668,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+669,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+670,((1U & (vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+671,((1U & vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->fullBit(oldp+672,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->fullBit(oldp+673,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__re));
    bufp->fullBit(oldp+674,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__we));
    bufp->fullBit(oldp+675,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__wd));
    bufp->fullBit(oldp+676,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__d));
    bufp->fullBit(oldp+677,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qe));
    bufp->fullBit(oldp+678,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qre));
    bufp->fullBit(oldp+679,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__q));
    bufp->fullBit(oldp+680,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__ds));
    bufp->fullBit(oldp+681,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_busy__DOT__qs));
    bufp->fullBit(oldp+682,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__re));
    bufp->fullBit(oldp+683,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__we));
    bufp->fullBit(oldp+684,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__wd));
    bufp->fullBit(oldp+685,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__d));
    bufp->fullBit(oldp+686,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qe));
    bufp->fullBit(oldp+687,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qre));
    bufp->fullBit(oldp+688,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__q));
    bufp->fullBit(oldp+689,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__ds));
    bufp->fullBit(oldp+690,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_error__DOT__qs));
    bufp->fullBit(oldp+691,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__re));
    bufp->fullBit(oldp+692,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__we));
    bufp->fullIData(oldp+693,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__wd),29);
    bufp->fullIData(oldp+694,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__d),29);
    bufp->fullBit(oldp+695,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qe));
    bufp->fullBit(oldp+696,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qre));
    bufp->fullIData(oldp+697,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__q),29);
    bufp->fullIData(oldp+698,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__ds),29);
    bufp->fullIData(oldp+699,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_rsvd__DOT__qs),29);
    bufp->fullBit(oldp+700,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__re));
    bufp->fullBit(oldp+701,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__we));
    bufp->fullBit(oldp+702,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__wd));
    bufp->fullBit(oldp+703,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__d));
    bufp->fullBit(oldp+704,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qe));
    bufp->fullBit(oldp+705,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qre));
    bufp->fullBit(oldp+706,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__q));
    bufp->fullBit(oldp+707,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__ds));
    bufp->fullBit(oldp+708,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_status_valid__DOT__qs));
    bufp->fullBit(oldp+709,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__clk_i));
    bufp->fullBit(oldp+710,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__rst_ni));
    bufp->fullBit(oldp+711,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__we));
    bufp->fullIData(oldp+712,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wd),32);
    bufp->fullBit(oldp+713,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__de));
    bufp->fullIData(oldp+714,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__d),32);
    bufp->fullBit(oldp+715,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qe));
    bufp->fullIData(oldp+716,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__q),32);
    bufp->fullIData(oldp+717,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__ds),32);
    bufp->fullIData(oldp+718,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__qs),32);
    bufp->fullBit(oldp+719,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en));
    bufp->fullIData(oldp+720,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_data),32);
    bufp->fullBit(oldp+721,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__we));
    bufp->fullIData(oldp+722,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->fullBit(oldp+723,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__de));
    bufp->fullIData(oldp+724,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->fullIData(oldp+725,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->fullBit(oldp+726,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullIData(oldp+727,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->fullIData(oldp+728,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->fullBit(oldp+729,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__re));
    bufp->fullBit(oldp+730,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__we));
    bufp->fullIData(oldp+731,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__wd),32);
    bufp->fullIData(oldp+732,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__d),32);
    bufp->fullBit(oldp+733,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qe));
    bufp->fullBit(oldp+734,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qre));
    bufp->fullIData(oldp+735,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__q),32);
    bufp->fullIData(oldp+736,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__ds),32);
    bufp->fullIData(oldp+737,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_x_out__DOT__qs),32);
    bufp->fullBit(oldp+738,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__clk_i));
    bufp->fullBit(oldp+739,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__rst_ni));
    bufp->fullBit(oldp+740,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__we));
    bufp->fullIData(oldp+741,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wd),32);
    bufp->fullBit(oldp+742,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__de));
    bufp->fullIData(oldp+743,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__d),32);
    bufp->fullBit(oldp+744,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qe));
    bufp->fullIData(oldp+745,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__q),32);
    bufp->fullIData(oldp+746,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__ds),32);
    bufp->fullIData(oldp+747,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__qs),32);
    bufp->fullBit(oldp+748,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en));
    bufp->fullIData(oldp+749,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_data),32);
    bufp->fullBit(oldp+750,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__we));
    bufp->fullIData(oldp+751,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->fullBit(oldp+752,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__de));
    bufp->fullIData(oldp+753,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->fullIData(oldp+754,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->fullBit(oldp+755,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullIData(oldp+756,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->fullIData(oldp+757,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->fullBit(oldp+758,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__re));
    bufp->fullBit(oldp+759,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__we));
    bufp->fullIData(oldp+760,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__wd),32);
    bufp->fullIData(oldp+761,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__d),32);
    bufp->fullBit(oldp+762,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qe));
    bufp->fullBit(oldp+763,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qre));
    bufp->fullIData(oldp+764,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__q),32);
    bufp->fullIData(oldp+765,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__ds),32);
    bufp->fullIData(oldp+766,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_y_out__DOT__qs),32);
    bufp->fullBit(oldp+767,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__clk_i));
    bufp->fullBit(oldp+768,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__rst_ni));
    bufp->fullBit(oldp+769,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__we));
    bufp->fullIData(oldp+770,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wd),32);
    bufp->fullBit(oldp+771,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__de));
    bufp->fullIData(oldp+772,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__d),32);
    bufp->fullBit(oldp+773,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qe));
    bufp->fullIData(oldp+774,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__q),32);
    bufp->fullIData(oldp+775,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__ds),32);
    bufp->fullIData(oldp+776,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__qs),32);
    bufp->fullBit(oldp+777,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en));
    bufp->fullIData(oldp+778,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_data),32);
    bufp->fullBit(oldp+779,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__we));
    bufp->fullIData(oldp+780,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->fullBit(oldp+781,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__de));
    bufp->fullIData(oldp+782,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__d),32);
    bufp->fullIData(oldp+783,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__q),32);
    bufp->fullBit(oldp+784,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullIData(oldp+785,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->fullIData(oldp+786,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_in__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->fullBit(oldp+787,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__re));
    bufp->fullBit(oldp+788,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__we));
    bufp->fullIData(oldp+789,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__wd),32);
    bufp->fullIData(oldp+790,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__d),32);
    bufp->fullBit(oldp+791,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qe));
    bufp->fullBit(oldp+792,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qre));
    bufp->fullIData(oldp+793,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__q),32);
    bufp->fullIData(oldp+794,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__ds),32);
    bufp->fullIData(oldp+795,(vlSelfRef.cordic_tb__DOT__u_cordic__DOT__u_cordic_reg__DOT__u_z_out__DOT__qs),32);
    bufp->fullBit(oldp+796,((1U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+797,((7U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+798,((7U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+799,((3U & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+800,((0x000000ffU & ((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[3U] 
                                               << 4U) 
                                              | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+801,(((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[2U] 
                                << 4U) | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+802,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+803,(((vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[1U] 
                                << 8U) | (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+804,((0x0000001fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+805,((0x0000000fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+806,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+807,((0x0000007fU & (vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+808,((1U & vlSelfRef.cordic_tb__DOT__unnamedblk1__DOT__t[0U])));
    bufp->fullSData(oldp+809,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[0]),16);
    bufp->fullSData(oldp+810,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[1]),16);
    bufp->fullSData(oldp+811,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[2]),16);
    bufp->fullSData(oldp+812,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[3]),16);
    bufp->fullSData(oldp+813,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[4]),16);
    bufp->fullSData(oldp+814,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[5]),16);
    bufp->fullSData(oldp+815,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[6]),16);
    bufp->fullSData(oldp+816,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[7]),16);
    bufp->fullSData(oldp+817,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[8]),16);
    bufp->fullSData(oldp+818,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[9]),16);
    bufp->fullSData(oldp+819,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[10]),16);
    bufp->fullSData(oldp+820,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[11]),16);
    bufp->fullSData(oldp+821,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[12]),16);
    bufp->fullSData(oldp+822,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[13]),16);
    bufp->fullSData(oldp+823,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[14]),16);
    bufp->fullSData(oldp+824,(vlSymsp->TOP__cordic_lut_pkg.AtanLut[15]),16);
    bufp->fullCData(oldp+825,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[0]),4);
    bufp->fullCData(oldp+826,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[1]),4);
    bufp->fullCData(oldp+827,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[2]),4);
    bufp->fullCData(oldp+828,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[3]),4);
    bufp->fullCData(oldp+829,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[4]),4);
    bufp->fullCData(oldp+830,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[5]),4);
    bufp->fullCData(oldp+831,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[6]),4);
    bufp->fullCData(oldp+832,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[7]),4);
    bufp->fullCData(oldp+833,(vlSymsp->TOP__cordic_reg_pkg.CORDIC_PERMIT[8]),4);
}
