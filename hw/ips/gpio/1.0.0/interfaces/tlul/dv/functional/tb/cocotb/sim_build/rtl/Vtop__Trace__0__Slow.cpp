// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"cio_gpio_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"cio_gpio_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"cio_gpio_en_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"intr_gpio_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"tl_i_a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"tl_i_a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"tl_i_a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"tl_i_a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"tl_i_a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"tl_i_a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"tl_i_a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"tl_i_a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"tl_i_d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"tl_o_d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"tl_o_d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"tl_o_d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"tl_o_d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+19,0,"tl_o_a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+20,0,"tl_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 108,0);
    VL_TRACE_DECL_WIDE(tracep,c+24,0,"tl_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 65,0);
    VL_TRACE_DECL_BUS(tracep,c+589,0,"FLEXSOC_TL_PUT_FULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+590,0,"FLEXSOC_TL_PUT_PARTIAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"FLEXSOC_TL_GET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"cio_gpio_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"cio_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"cio_gpio_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+32,0,"intr_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+34,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+46,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+59,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+64,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+66,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+67,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+68,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+69,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+70,0,"reg_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"core_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_core_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+77,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+78,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+80,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+85,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+88,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+90,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+91,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+92,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+96,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+97,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"cio_gpio_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+100,0,"cio_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"cio_gpio_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"intr_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"GpioAsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"FilterCntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"data_in_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"data_in_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"gpio_o_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"gpio_oe_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+107,0,"event_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"event_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"event_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"event_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+111,0,"filter_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"state_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+115,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+116,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+117,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+120,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+121,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+122,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+123,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+124,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+125,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+127,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+130,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+133,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+134,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+135,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+136,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+137,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+138,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+139,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+143,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+145,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+146,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+147,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+148,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+149,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+150,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+151,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+153,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+154,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+155,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+156,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+157,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+158,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+159,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+160,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+161,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+162,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+163,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+164,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+165,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+166,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+167,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+168,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+170,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+171,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+172,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+173,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+174,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+175,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+176,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+177,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+178,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+179,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+180,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+181,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+182,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+183,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+184,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+185,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+186,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+187,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+188,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+189,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+190,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+191,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+192,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+193,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+194,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+195,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+198,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+199,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+200,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+201,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+202,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+203,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+204,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+205,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+206,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+207,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+208,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+209,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+210,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+211,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+212,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+213,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+214,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+215,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_state_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+216,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+217,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+218,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+219,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+220,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+221,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+222,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+223,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+224,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+225,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+226,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+228,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+229,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+230,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+231,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+232,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+233,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+234,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+235,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+236,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+237,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+238,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+239,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+240,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+241,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+242,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+243,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+244,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+245,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+246,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+247,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+249,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+250,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+251,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+252,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+253,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+254,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+255,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+256,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+257,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+258,0,"flexsoc_tlul_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+259,0,"flexsoc_tlul_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+260,0,"flexsoc_tlul_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"flexsoc_tlul_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"flexsoc_tlul_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_tlul_reg_req", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+263,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+264,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+265,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+266,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+267,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_tlul_reg_rsp", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+268,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+269,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+270,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_flexsoc_tlul_to_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+602,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+271,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+272,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+273,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+274,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+275,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+276,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+277,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+278,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+279,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+280,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+281,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+282,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+283,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+284,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+285,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+286,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+287,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+288,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+289,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+290,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+291,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+292,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+293,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+294,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+295,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+296,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"en_ifetch_i",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+297,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+298,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+300,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+301,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+310,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+311,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+316,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+317,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+318,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+319,0,"rspop_q",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+320,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+321,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+322,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+323,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+324,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+325,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+326,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+327,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+328,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+329,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+330,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+331,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+332,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_err", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+333,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+334,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+336,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+337,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+338,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+339,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+340,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+341,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+342,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+343,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+344,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+345,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+346,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+347,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+348,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+349,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+350,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+351,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+352,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+353,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+354,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+355,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+356,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+357,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+358,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+607,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+359,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+360,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+361,0,"d_opcode",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+362,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+363,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+364,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+365,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+367,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+368,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+369,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+370,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+371,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+372,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+373,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+374,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+375,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+376,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+377,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+378,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+379,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+380,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+381,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+382,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+383,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+384,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_req_i", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+385,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+386,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+387,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+388,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+390,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+391,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+392,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+393,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+394,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+397,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+400,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+401,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+402,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+404,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+405,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+406,0,"intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+407,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+408,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+409,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+412,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+413,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+416,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+417,0,"reg_we_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+418,0,"reg_we_check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+419,0,"err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+420,0,"data_in_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"direct_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+422,0,"direct_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+423,0,"direct_gpio_o_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+424,0,"direct_gpio_o_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+425,0,"direct_gpio_oe_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+426,0,"direct_gpio_oe_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+427,0,"intr_ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+428,0,"intr_ctrl_en_rising_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+429,0,"intr_ctrl_en_rising_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+430,0,"intr_ctrl_en_falling_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+431,0,"intr_ctrl_en_falling_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+432,0,"intr_ctrl_en_lvlhigh_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+433,0,"intr_ctrl_en_lvlhigh_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"intr_ctrl_en_lvllow_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"intr_ctrl_en_lvllow_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"intr_ctrl_en_input_filter_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"intr_ctrl_en_input_filter_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"direct_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+439,0,"direct_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+440,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_data_in", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+444,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+445,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+446,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+447,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+448,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+449,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+450,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+451,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+452,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+453,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+454,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+455,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+456,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+457,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_ro", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"unused_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"unused_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+458,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_direct_gpio_o", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+459,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+460,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+462,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+463,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+464,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+465,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+467,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_direct_gpio_oe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+468,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+469,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+470,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+471,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+472,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+473,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+475,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+476,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_falling", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+477,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+478,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+479,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+480,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+481,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+482,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+483,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+484,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+485,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+486,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+487,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+488,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+489,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+490,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+491,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+492,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_input_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+493,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+494,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+495,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+496,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+497,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+498,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+499,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+500,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+501,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+502,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+503,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+504,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+505,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+506,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_lvlhigh", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+509,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+510,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+511,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+514,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+515,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+516,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+517,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+518,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+519,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+520,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+524,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_lvllow", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+525,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+526,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+527,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+529,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+533,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+534,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+535,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+538,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+539,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+540,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_rising", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+541,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+542,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+543,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+544,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+545,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+547,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+548,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+549,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+550,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+551,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+554,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+555,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+556,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_reg_we_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+557,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+558,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+559,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+560,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+561,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+562,0,"oh_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_buf", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+563,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+564,0,"out_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_onehot_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+613,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"AddrCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnableCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+599,0,"StrictCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+595,0,"EnableAlertTriggerSVA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+566,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+567,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+568,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+614,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+569,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+570,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+571,0,"or_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+572,0,"and_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+573,0,"err_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+602,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+602,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+618,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+619,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+620,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+621,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+622,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+623,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+574,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+575,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+578,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+579,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+580,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+581,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+585,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tlul_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "top_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__top_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+601,0,"TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+624,0,"TL_AUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+623,0,"TL_DUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+602,0,"SecVolatileRawUnlockEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+625,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+626,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+629,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+631,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+634,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+626,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+629,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+634,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+637,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+644,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+646,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+648,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+649,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+640,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+644,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+648,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+649,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+648,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+652,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 75,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____11(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+600,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"NumRegs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"GPIO_DATA_IN_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+655,0,"GPIO_DIRECT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+656,0,"GPIO_INTR_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"GPIO_DIRECT_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);

    Vtop___024root__trace_init_dtype____11(vlSelf, tracep, "GPIO_PERMIT", 0, c+586, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____11(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____11(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____11(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____11(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____11\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 2);
    for (int i = 0; i < 3; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, (i + 0), 3,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+600,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+621,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+657,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+658,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+659,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+660,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+661,0,"ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BUS(tracep,c+662,0,"H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"H2DCmdFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+662,0,"D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"D2HRspFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+664,0,"DataFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_A_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+667,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_H2D_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+670,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+589,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+614,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+667,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_D_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_D2H_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+589,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+614,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+604,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
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
    bufp->fullCData(oldp+589,(0U),3);
    bufp->fullCData(oldp+590,(1U),3);
    bufp->fullCData(oldp+591,(4U),3);
    bufp->fullIData(oldp+592,(1U),32);
    bufp->fullBit(oldp+593,(0U));
    bufp->fullBit(oldp+594,(1U));
    bufp->fullBit(oldp+595,(1U));
    bufp->fullIData(oldp+596,(4U),32);
    bufp->fullCData(oldp+597,(0x0fU),4);
    bufp->fullBit(oldp+598,(1U));
    bufp->fullBit(oldp+599,(0U));
    bufp->fullIData(oldp+600,(4U),32);
    bufp->fullIData(oldp+601,(0x00000020U),32);
    bufp->fullIData(oldp+602,(0U),32);
    bufp->fullCData(oldp+603,(9U),4);
    bufp->fullBit(oldp+604,(0U));
    bufp->fullIData(oldp+605,(8U),32);
    bufp->fullIData(oldp+606,(2U),32);
    bufp->fullCData(oldp+607,(1U),4);
    bufp->fullCData(oldp+608,(1U),3);
    bufp->fullCData(oldp+609,(0U),4);
    bufp->fullCData(oldp+610,(0U),3);
    bufp->fullIData(oldp+611,(3U),32);
    bufp->fullIData(oldp+612,(3U),32);
    bufp->fullIData(oldp+613,(2U),32);
    bufp->fullCData(oldp+614,(0U),2);
    bufp->fullIData(oldp+615,(5U),32);
    bufp->fullIData(oldp+616,(6U),32);
    bufp->fullIData(oldp+617,(7U),32);
    bufp->fullIData(oldp+618,(9U),32);
    bufp->fullIData(oldp+619,(0x0000000aU),32);
    bufp->fullIData(oldp+620,(0x0000000bU),32);
    bufp->fullIData(oldp+621,(0x0000000cU),32);
    bufp->fullIData(oldp+622,(0x0000000dU),32);
    bufp->fullIData(oldp+623,(0x0000000eU),32);
    bufp->fullIData(oldp+624,(0x00000015U),32);
    bufp->fullCData(oldp+625,(0U),6);
    bufp->fullIData(oldp+626,(0U),22);
    bufp->fullIData(oldp+627,(0U),28);
    bufp->fullCData(oldp+628,(0U),7);
    bufp->fullQData(oldp+629,(0ULL),39);
    bufp->fullQData(oldp+631,(0ULL),64);
    bufp->fullCData(oldp+633,(0U),8);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+634,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+637,(__Vtemp_2),76);
    bufp->fullCData(oldp+640,(0x2aU),6);
    bufp->fullIData(oldp+641,(0x002a0000U),22);
    bufp->fullIData(oldp+642,(0x0a800000U),28);
    bufp->fullCData(oldp+643,(0x2aU),7);
    bufp->fullQData(oldp+644,(0x0000002a00000000ULL),39);
    bufp->fullQData(oldp+646,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+648,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0x000000aaU;
    bufp->fullWData(oldp+649,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0x00000aa0U;
    bufp->fullWData(oldp+652,(__Vtemp_4),76);
    bufp->fullCData(oldp+655,(4U),4);
    bufp->fullCData(oldp+656,(8U),4);
    bufp->fullIData(oldp+657,(0x00000010U),32);
    bufp->fullIData(oldp+658,(0x00000014U),32);
    bufp->fullIData(oldp+659,(0x00000018U),32);
    bufp->fullIData(oldp+660,(0x0000001cU),32);
    bufp->fullIData(oldp+661,(0x00505043U),24);
    bufp->fullIData(oldp+662,(0x00000039U),32);
    bufp->fullIData(oldp+663,(0x00000040U),32);
    bufp->fullIData(oldp+664,(0x00000027U),32);
    bufp->fullIData(oldp+665,(0U),32);
    bufp->fullIData(oldp+666,(0xffffffffU),32);
    bufp->fullCData(oldp+667,(0U),5);
    bufp->fullCData(oldp+668,(9U),4);
    bufp->fullCData(oldp+669,(0x7fU),7);
    bufp->fullCData(oldp+670,(0U),3);
    bufp->fullCData(oldp+671,(0U),3);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.gpio_tb__DOT__clk_i));
    bufp->fullBit(oldp+1,(vlSelfRef.gpio_tb__DOT__rst_ni));
    bufp->fullCData(oldp+2,(vlSelfRef.gpio_tb__DOT__cio_gpio_i),4);
    bufp->fullCData(oldp+3,(vlSelfRef.gpio_tb__DOT__cio_gpio_o),4);
    bufp->fullCData(oldp+4,(vlSelfRef.gpio_tb__DOT__cio_gpio_en_o),4);
    bufp->fullCData(oldp+5,(vlSelfRef.gpio_tb__DOT__intr_gpio_o),4);
    bufp->fullBit(oldp+6,(vlSelfRef.gpio_tb__DOT__tl_i_a_valid));
    bufp->fullCData(oldp+7,(vlSelfRef.gpio_tb__DOT__tl_i_a_opcode),3);
    bufp->fullCData(oldp+8,(vlSelfRef.gpio_tb__DOT__tl_i_a_param),3);
    bufp->fullCData(oldp+9,(vlSelfRef.gpio_tb__DOT__tl_i_a_size),2);
    bufp->fullCData(oldp+10,(vlSelfRef.gpio_tb__DOT__tl_i_a_source),8);
    bufp->fullIData(oldp+11,(vlSelfRef.gpio_tb__DOT__tl_i_a_address),32);
    bufp->fullCData(oldp+12,(vlSelfRef.gpio_tb__DOT__tl_i_a_mask),4);
    bufp->fullIData(oldp+13,(vlSelfRef.gpio_tb__DOT__tl_i_a_data),32);
    bufp->fullBit(oldp+14,(vlSelfRef.gpio_tb__DOT__tl_i_d_ready));
    bufp->fullBit(oldp+15,(vlSelfRef.gpio_tb__DOT__tl_o_d_valid));
    bufp->fullCData(oldp+16,(vlSelfRef.gpio_tb__DOT__tl_o_d_opcode),3);
    bufp->fullIData(oldp+17,(vlSelfRef.gpio_tb__DOT__tl_o_d_data),32);
    bufp->fullBit(oldp+18,(vlSelfRef.gpio_tb__DOT__tl_o_d_error));
    bufp->fullBit(oldp+19,(vlSelfRef.gpio_tb__DOT__tl_o_a_ready));
    bufp->fullWData(oldp+20,(vlSelfRef.gpio_tb__DOT__tl_i),109);
    bufp->fullWData(oldp+24,(vlSelfRef.gpio_tb__DOT__tl_o),66);
    bufp->fullBit(oldp+27,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i));
    bufp->fullBit(oldp+28,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni));
    bufp->fullCData(oldp+29,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i),4);
    bufp->fullCData(oldp+30,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o),4);
    bufp->fullCData(oldp+31,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o),4);
    bufp->fullCData(oldp+32,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o),4);
    bufp->fullBit(oldp+33,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->fullCData(oldp+34,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->fullCData(oldp+35,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->fullCData(oldp+36,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->fullCData(oldp+37,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+38,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->fullCData(oldp+39,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullIData(oldp+40,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+41,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+42,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+43,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+44,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+45,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_i[0U])));
    bufp->fullBit(oldp+46,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->fullCData(oldp+47,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+48,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->fullCData(oldp+49,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->fullCData(oldp+50,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->fullBit(oldp+51,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->fullIData(oldp+52,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->fullCData(oldp+53,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->fullCData(oldp+54,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->fullBit(oldp+55,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->fullBit(oldp+56,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__tl_o[0U])));
    bufp->fullCData(oldp+57,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->fullBit(oldp+58,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->fullCData(oldp+59,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->fullBit(oldp+60,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->fullCData(oldp+61,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->fullCData(oldp+62,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->fullCData(oldp+63,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->fullCData(oldp+64,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->fullCData(oldp+65,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw)),4);
    bufp->fullCData(oldp+66,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->fullBit(oldp+67,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                  >> 8U))));
    bufp->fullCData(oldp+68,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->fullCData(oldp+69,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg))),4);
    bufp->fullBit(oldp+70,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni));
    bufp->fullBit(oldp+71,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni));
    bufp->fullBit(oldp+72,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+73,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+74,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+75,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+76,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq));
    bufp->fullBit(oldp+77,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+78,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+79,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+80,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+81,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+82,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+83,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+84,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i));
    bufp->fullBit(oldp+85,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni));
    bufp->fullCData(oldp+86,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->fullBit(oldp+87,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->fullCData(oldp+88,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->fullBit(oldp+89,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->fullCData(oldp+90,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->fullCData(oldp+91,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->fullCData(oldp+92,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->fullCData(oldp+93,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->fullCData(oldp+94,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)),4);
    bufp->fullCData(oldp+95,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->fullBit(oldp+96,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                  >> 8U))));
    bufp->fullCData(oldp+97,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->fullCData(oldp+98,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg))),4);
    bufp->fullCData(oldp+99,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i),4);
    bufp->fullCData(oldp+100,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o),4);
    bufp->fullCData(oldp+101,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o),4);
    bufp->fullCData(oldp+102,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o),4);
    bufp->fullCData(oldp+103,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d),4);
    bufp->fullCData(oldp+104,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q),4);
    bufp->fullCData(oldp+105,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q),4);
    bufp->fullCData(oldp+106,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q),4);
    bufp->fullCData(oldp+107,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise),4);
    bufp->fullCData(oldp+108,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall),4);
    bufp->fullCData(oldp+109,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high),4);
    bufp->fullCData(oldp+110,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low),4);
    bufp->fullBit(oldp+111,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni));
    bufp->fullBit(oldp+112,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni));
    bufp->fullBit(oldp+113,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+114,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+115,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+116,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+117,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+118,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+119,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+120,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+121,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+122,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+123,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+124,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+125,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+126,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+127,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+128,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+129,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+130,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+131,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+132,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+133,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+134,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+135,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+136,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+137,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+138,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+139,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+140,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+141,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+142,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+143,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+144,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+145,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+146,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+147,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+148,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+149,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+150,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+151,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+152,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+153,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+154,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+155,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+156,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+157,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+158,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+159,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+160,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+161,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+162,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+163,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+164,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+165,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+166,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+167,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+168,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+169,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+170,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+171,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+172,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+173,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+174,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+175,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+176,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+177,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+178,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+179,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+180,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+181,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+182,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+183,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+184,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+185,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+186,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+187,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+188,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+189,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+190,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+191,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+192,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+193,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+194,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+195,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+196,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+197,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+198,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+199,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+200,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+201,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+202,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+203,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+204,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+205,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+206,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+207,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+208,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+209,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+210,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+211,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+212,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+213,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+214,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+215,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+216,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+217,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+218,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+219,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i));
    bufp->fullBit(oldp+220,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni));
    bufp->fullBit(oldp+221,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+222,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+223,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+224,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+225,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+226,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+227,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+228,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+229,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+230,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+231,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+232,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+233,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_i[0U])));
    bufp->fullBit(oldp+234,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+235,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+236,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+237,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+238,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+239,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+240,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+241,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+242,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+243,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+244,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__tl_o[0U])));
    bufp->fullCData(oldp+245,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x0000001aU))),4);
    bufp->fullBit(oldp+246,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                   >> 0x00000019U))));
    bufp->fullCData(oldp+247,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x00000015U))),4);
    bufp->fullBit(oldp+248,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+249,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x00000010U))),4);
    bufp->fullCData(oldp+250,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x0000000cU))),4);
    bufp->fullCData(oldp+251,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 8U))),4);
    bufp->fullCData(oldp+252,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 4U))),4);
    bufp->fullCData(oldp+253,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw)),4);
    bufp->fullCData(oldp+254,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                              >> 9U))),4);
    bufp->fullBit(oldp+255,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                   >> 8U))));
    bufp->fullCData(oldp+256,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+257,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg))),4);
    bufp->fullBit(oldp+258,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_re));
    bufp->fullBit(oldp+259,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_we));
    bufp->fullCData(oldp+260,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_addr),4);
    bufp->fullIData(oldp+261,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_wdata),32);
    bufp->fullCData(oldp+262,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_be),4);
    bufp->fullBit(oldp+263,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                           >> 0x00000029U)))));
    bufp->fullBit(oldp+264,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                           >> 0x00000028U)))));
    bufp->fullCData(oldp+265,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+266,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req 
                                       >> 4U))),32);
    bufp->fullCData(oldp+267,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_req))),4);
    bufp->fullIData(oldp+268,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                       >> 2U))),32);
    bufp->fullBit(oldp+269,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp 
                                           >> 1U)))));
    bufp->fullBit(oldp+270,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_tlul_reg_rsp))));
    bufp->fullBit(oldp+271,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__clk_i));
    bufp->fullBit(oldp+272,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rst_ni));
    bufp->fullBit(oldp+273,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+274,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+275,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+276,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+277,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+278,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+279,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+280,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+281,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+282,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+283,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+284,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+285,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_i[0U])));
    bufp->fullBit(oldp+286,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+287,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+288,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+289,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+290,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+291,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+292,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+293,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+294,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+295,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+296,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o[0U])));
    bufp->fullBit(oldp+297,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__re_o));
    bufp->fullBit(oldp+298,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__we_o));
    bufp->fullCData(oldp+299,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_o),4);
    bufp->fullIData(oldp+300,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wdata_o),32);
    bufp->fullCData(oldp+301,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__be_o),4);
    bufp->fullBit(oldp+302,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__busy_i));
    bufp->fullIData(oldp+303,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_i),32);
    bufp->fullBit(oldp+304,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_i));
    bufp->fullBit(oldp+305,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__outstanding_q));
    bufp->fullBit(oldp+306,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__a_ack));
    bufp->fullBit(oldp+307,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__d_ack));
    bufp->fullIData(oldp+308,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata),32);
    bufp->fullIData(oldp+309,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rdata_q),32);
    bufp->fullBit(oldp+310,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error_q));
    bufp->fullBit(oldp+311,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__error));
    bufp->fullBit(oldp+312,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__err_internal));
    bufp->fullBit(oldp+313,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__instr_error));
    bufp->fullBit(oldp+314,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__addr_align_err));
    bufp->fullBit(oldp+315,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__malformed_meta_err));
    bufp->fullBit(oldp+316,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_err));
    bufp->fullCData(oldp+317,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqid_q),8);
    bufp->fullCData(oldp+318,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__reqsz_q),2);
    bufp->fullCData(oldp+319,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rspop_q),3);
    bufp->fullBit(oldp+320,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__rd_req));
    bufp->fullBit(oldp+321,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__wr_req));
    bufp->fullBit(oldp+322,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+323,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[2U] 
                                      << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+324,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+325,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+326,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+327,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+328,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[1U] 
                                << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+329,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+330,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+331,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+332,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__tl_o_pre[0U])));
    bufp->fullBit(oldp+333,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__clk_i));
    bufp->fullBit(oldp+334,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__rst_ni));
    bufp->fullBit(oldp+335,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+336,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+337,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+338,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+339,((0x000000ffU & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+340,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+341,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+342,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+343,((0x0000001fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+344,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+345,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+346,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+347,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__tl_i[0U])));
    bufp->fullBit(oldp+348,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__err_o));
    bufp->fullBit(oldp+349,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__opcode_allowed));
    bufp->fullBit(oldp+350,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__a_config_allowed));
    bufp->fullBit(oldp+351,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_full));
    bufp->fullBit(oldp+352,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_partial));
    bufp->fullBit(oldp+353,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__op_get));
    bufp->fullBit(oldp+354,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+355,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+356,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+357,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+358,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__fulldata_chk));
    bufp->fullCData(oldp+359,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_err__DOT__mask),4);
    bufp->fullBit(oldp+360,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+361,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                      << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+362,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+363,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+364,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+365,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+366,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+367,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+368,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+369,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+370,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->fullBit(oldp+371,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+372,((7U & ((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+373,((7U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+374,((3U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+375,((0x000000ffU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+376,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+377,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+378,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+379,((0x0000007fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+380,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+381,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->fullBit(oldp+382,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_tlul_to_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->fullBit(oldp+383,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->fullBit(oldp+384,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->fullBit(oldp+385,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x00000029U)))));
    bufp->fullBit(oldp+386,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x00000028U)))));
    bufp->fullCData(oldp+387,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+388,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                       >> 4U))),32);
    bufp->fullCData(oldp+389,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->fullIData(oldp+390,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                       >> 2U))),32);
    bufp->fullBit(oldp+391,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 1U)))));
    bufp->fullBit(oldp+392,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->fullCData(oldp+393,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x0000001aU))),4);
    bufp->fullBit(oldp+394,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                   >> 0x00000019U))));
    bufp->fullCData(oldp+395,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x00000015U))),4);
    bufp->fullBit(oldp+396,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+397,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x00000010U))),4);
    bufp->fullCData(oldp+398,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x0000000cU))),4);
    bufp->fullCData(oldp+399,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 8U))),4);
    bufp->fullCData(oldp+400,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 4U))),4);
    bufp->fullCData(oldp+401,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw)),4);
    bufp->fullCData(oldp+402,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                              >> 9U))),4);
    bufp->fullBit(oldp+403,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                   >> 8U))));
    bufp->fullCData(oldp+404,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+405,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg))),4);
    bufp->fullBit(oldp+406,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->fullBit(oldp+407,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->fullBit(oldp+408,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->fullCData(oldp+409,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr),4);
    bufp->fullIData(oldp+410,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->fullCData(oldp+411,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->fullIData(oldp+412,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->fullBit(oldp+413,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->fullBit(oldp+414,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->fullBit(oldp+415,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->fullIData(oldp+416,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+417,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->fullCData(oldp+418,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check),3);
    bufp->fullBit(oldp+419,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q));
    bufp->fullCData(oldp+420,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs),4);
    bufp->fullBit(oldp+421,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re));
    bufp->fullBit(oldp+422,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we));
    bufp->fullCData(oldp+423,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs),4);
    bufp->fullCData(oldp+424,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd),4);
    bufp->fullCData(oldp+425,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs),4);
    bufp->fullCData(oldp+426,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd),4);
    bufp->fullBit(oldp+427,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we));
    bufp->fullCData(oldp+428,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs),4);
    bufp->fullCData(oldp+429,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd),4);
    bufp->fullCData(oldp+430,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs),4);
    bufp->fullCData(oldp+431,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd),4);
    bufp->fullCData(oldp+432,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs),4);
    bufp->fullCData(oldp+433,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd),4);
    bufp->fullCData(oldp+434,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs),4);
    bufp->fullCData(oldp+435,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd),4);
    bufp->fullCData(oldp+436,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs),4);
    bufp->fullCData(oldp+437,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd),4);
    bufp->fullBit(oldp+438,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe));
    bufp->fullCData(oldp+439,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we),2);
    bufp->fullCData(oldp+440,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit),3);
    bufp->fullBit(oldp+441,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->fullBit(oldp+442,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->fullBit(oldp+443,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i));
    bufp->fullBit(oldp+444,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni));
    bufp->fullBit(oldp+445,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de));
    bufp->fullCData(oldp+446,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d),4);
    bufp->fullBit(oldp+447,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe));
    bufp->fullCData(oldp+448,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q),4);
    bufp->fullCData(oldp+449,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds),4);
    bufp->fullCData(oldp+450,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs),4);
    bufp->fullBit(oldp+451,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en));
    bufp->fullCData(oldp+452,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data),4);
    bufp->fullBit(oldp+453,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de));
    bufp->fullCData(oldp+454,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d),4);
    bufp->fullCData(oldp+455,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+456,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+457,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+458,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q),4);
    bufp->fullBit(oldp+459,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re));
    bufp->fullBit(oldp+460,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we));
    bufp->fullCData(oldp+461,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd),4);
    bufp->fullCData(oldp+462,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d),4);
    bufp->fullBit(oldp+463,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    bufp->fullBit(oldp+464,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre));
    bufp->fullCData(oldp+465,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q),4);
    bufp->fullCData(oldp+466,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds),4);
    bufp->fullCData(oldp+467,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs),4);
    bufp->fullBit(oldp+468,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re));
    bufp->fullBit(oldp+469,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we));
    bufp->fullCData(oldp+470,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd),4);
    bufp->fullCData(oldp+471,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d),4);
    bufp->fullBit(oldp+472,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe));
    bufp->fullBit(oldp+473,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre));
    bufp->fullCData(oldp+474,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q),4);
    bufp->fullCData(oldp+475,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds),4);
    bufp->fullCData(oldp+476,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs),4);
    bufp->fullBit(oldp+477,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i));
    bufp->fullBit(oldp+478,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni));
    bufp->fullBit(oldp+479,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we));
    bufp->fullCData(oldp+480,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd),4);
    bufp->fullBit(oldp+481,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe));
    bufp->fullCData(oldp+482,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q),4);
    bufp->fullCData(oldp+483,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds),4);
    bufp->fullCData(oldp+484,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs),4);
    bufp->fullBit(oldp+485,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en));
    bufp->fullCData(oldp+486,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data),4);
    bufp->fullBit(oldp+487,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+488,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+489,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+490,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+491,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+492,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+493,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i));
    bufp->fullBit(oldp+494,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni));
    bufp->fullBit(oldp+495,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we));
    bufp->fullCData(oldp+496,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd),4);
    bufp->fullBit(oldp+497,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe));
    bufp->fullCData(oldp+498,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q),4);
    bufp->fullCData(oldp+499,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds),4);
    bufp->fullCData(oldp+500,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs),4);
    bufp->fullBit(oldp+501,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en));
    bufp->fullCData(oldp+502,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data),4);
    bufp->fullBit(oldp+503,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+504,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+505,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+506,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+507,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+508,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+509,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i));
    bufp->fullBit(oldp+510,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni));
    bufp->fullBit(oldp+511,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we));
    bufp->fullCData(oldp+512,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd),4);
    bufp->fullBit(oldp+513,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe));
    bufp->fullCData(oldp+514,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q),4);
    bufp->fullCData(oldp+515,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds),4);
    bufp->fullCData(oldp+516,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs),4);
    bufp->fullBit(oldp+517,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en));
    bufp->fullCData(oldp+518,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data),4);
    bufp->fullBit(oldp+519,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+520,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+521,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+522,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+523,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+524,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+525,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i));
    bufp->fullBit(oldp+526,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni));
    bufp->fullBit(oldp+527,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we));
    bufp->fullCData(oldp+528,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd),4);
    bufp->fullBit(oldp+529,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe));
    bufp->fullCData(oldp+530,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q),4);
    bufp->fullCData(oldp+531,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds),4);
    bufp->fullCData(oldp+532,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs),4);
    bufp->fullBit(oldp+533,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en));
    bufp->fullCData(oldp+534,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data),4);
    bufp->fullBit(oldp+535,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+536,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+537,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+538,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+539,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+540,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+541,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i));
    bufp->fullBit(oldp+542,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni));
    bufp->fullBit(oldp+543,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we));
    bufp->fullCData(oldp+544,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd),4);
    bufp->fullBit(oldp+545,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe));
    bufp->fullCData(oldp+546,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q),4);
    bufp->fullCData(oldp+547,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds),4);
    bufp->fullCData(oldp+548,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs),4);
    bufp->fullBit(oldp+549,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en));
    bufp->fullCData(oldp+550,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data),4);
    bufp->fullBit(oldp+551,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+552,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+553,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+554,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+555,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+556,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+557,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->fullBit(oldp+558,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->fullCData(oldp+559,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),3);
    bufp->fullBit(oldp+560,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->fullBit(oldp+561,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->fullCData(oldp+562,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),3);
    bufp->fullCData(oldp+563,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),3);
    bufp->fullCData(oldp+564,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),3);
    bufp->fullCData(oldp+565,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),3);
    bufp->fullBit(oldp+566,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->fullBit(oldp+567,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->fullCData(oldp+568,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),3);
    bufp->fullBit(oldp+569,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->fullBit(oldp+570,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->fullCData(oldp+571,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),7);
    bufp->fullCData(oldp+572,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),7);
    bufp->fullCData(oldp+573,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),7);
    bufp->fullBit(oldp+574,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+575,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+576,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+577,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+578,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq));
    bufp->fullBit(oldp+579,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+580,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+581,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+582,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+583,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+584,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+585,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 586, vlSymsp->TOP__gpio_reg_pkg.GPIO_PERMIT);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[0]),4);
    bufp->fullCData(oldp+1,(__VdtypeVar[1]),4);
    bufp->fullCData(oldp+2,(__VdtypeVar[2]),4);
}
