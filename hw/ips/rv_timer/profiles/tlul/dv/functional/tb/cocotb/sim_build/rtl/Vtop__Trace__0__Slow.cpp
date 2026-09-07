// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__rv_timer_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____11(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rv_timer_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__rv_timer_reg_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rv_timer_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"gpio_intr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"intr_timer_expired_hart0_timer0_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"tl_i_a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"tl_i_a_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"tl_i_a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"tl_i_a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"tl_i_a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"tl_i_a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"tl_i_a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"tl_i_a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"tl_i_d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"tl_o_d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"tl_o_d_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"tl_o_d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+16,0,"tl_o_d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+17,0,"tl_o_a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+18,0,"tl_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 108,0);
    VL_TRACE_DECL_WIDE(tracep,c+22,0,"tl_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 65,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"FLEXSOC_TL_PUT_FULL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+533,0,"FLEXSOC_TL_PUT_PARTIAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+534,0,"FLEXSOC_TL_GET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rv_timer", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"gpio_intr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+32,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+33,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+34,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+41,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+43,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+44,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+45,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+50,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+51,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"intr_timer_expired_hart0_timer0_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_intr_1", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+53,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_intr_0", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "active", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_enable0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_state0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_test0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "cfg0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "step", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+60,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prescale", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "timer_v0", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "compare_v0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_state0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+65,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "timer_v0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+67,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+68,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+69,0,"active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "prescaler", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+70+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i), 11,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "step", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+71+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+72,0,"tick",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mtime_d", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+73+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "mtime", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+74+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "mtimecmp", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "mtimecmp_update", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"intr_timer_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"intr_timer_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+79,0,"intr_timer_test_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"intr_timer_test_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"intr_timer_state_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+82,0,"intr_timer_state_de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+83,0,"intr_timer_state_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+84,0,"intr_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "input_capture_active_d", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BIT_ARRAY(tracep,c+85+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i));
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____11(vlSelf, tracep, "input_capture_active_q", 0, c+86, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BIT(tracep,c+87,0,"sel_gpio_intr_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"sel_gpio_intr_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_harts[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"active",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+92,0,"prescaler",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"step",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"tick",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"mtime_d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"mtime",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mtimecmp", VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+97+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (0 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"intr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"tick_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_hw", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+537,0,"FlopOutput",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_QUAD(tracep,c+538,0,"IntrT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 39,0);
    VL_TRACE_DECL_BIT(tracep,c+100,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+101,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"event_intr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"reg2hw_intr_enable_q_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"reg2hw_intr_test_q_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+105,0,"reg2hw_intr_test_qe_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"reg2hw_intr_state_q_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"hw2reg_intr_state_de_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"hw2reg_intr_state_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"intr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"status",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "g_intr_event", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+111,0,"new_event",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+117,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+120,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+121,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+122,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+125,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+126,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+127,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+128,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+131,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+132,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+133,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+134,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+135,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+136,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+137,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_intr_1", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+138,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_intr_0", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+139,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "active", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_enable0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_state0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_test0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+143,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+144,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "cfg0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "step", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+145,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prescale", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+146,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "timer_v0", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+147,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "compare_v0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+148,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+149,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_state0", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+150,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+151,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "timer_v0", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+153,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+154,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+155,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+157,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+158,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+159,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+160,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+161,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_reg_h2d", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+164,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+167,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+168,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+171,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+172,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+173,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+175,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+176,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_reg_d2h", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+177,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+178,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+179,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+180,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+181,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+182,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+183,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+184,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+185,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+186,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+187,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+188,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+189,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+190,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+191,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+192,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+193,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+194,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+195,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+196,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+198,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+199,0,"ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+200,0,"ctrl_active_0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+201,0,"ctrl_active_0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+202,0,"ctrl_gpio_intr_0_0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+203,0,"ctrl_gpio_intr_0_0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+204,0,"ctrl_gpio_intr_1_0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+205,0,"ctrl_gpio_intr_1_0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+206,0,"intr_enable0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+207,0,"intr_enable0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+208,0,"intr_enable0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+209,0,"intr_state0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+210,0,"intr_state0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+211,0,"intr_state0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+212,0,"intr_test0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+213,0,"intr_test0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+214,0,"cfg0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+215,0,"cfg0_prescale_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+216,0,"cfg0_prescale_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+217,0,"cfg0_step_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+218,0,"cfg0_step_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+219,0,"timer_v0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+220,0,"timer_v0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+221,0,"timer_v0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+222,0,"compare_v0_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+223,0,"compare_v0_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+224,0,"compare_v0_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+225,0,"intr_test0_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+226,0,"intr_test0_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+227,0,"compare_v0_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+228,0,"compare_v0_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+229,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+230,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+231,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_cfg0_prescale", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+545,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+547,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+232,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+233,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+234,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+235,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+547,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+236,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+237,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+238,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+239,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+240,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+241,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+545,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+242,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+243,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+547,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+244,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BIT(tracep,c+245,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+246,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+247,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_cfg0_step", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+550,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+249,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+250,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+251,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+252,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+253,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+254,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+255,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+256,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+257,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+258,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+259,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+260,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+261,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_compare_v0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+264,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+265,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+266,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+267,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+268,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+269,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+270,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+271,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+272,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+273,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+274,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+275,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+276,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+277,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+278,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+279,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_compare_v00_qe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+280,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+281,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+282,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+283,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_active_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+284,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+285,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+286,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+287,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+288,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+289,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+290,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+291,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+292,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+293,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+294,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+295,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+296,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+297,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_gpio_intr_0_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+303,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+305,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+306,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+307,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+308,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+310,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+311,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+312,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+314,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+315,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_gpio_intr_1_0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+316,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+317,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+318,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+319,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+320,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+321,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+322,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+323,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+324,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+325,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+326,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+327,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+328,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+330,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_enable0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+332,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+333,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+334,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+335,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+336,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+337,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+338,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+339,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+340,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+341,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+342,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+343,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+344,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+345,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+346,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+347,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_state0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+555,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+348,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+349,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+350,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+351,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+352,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+353,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+354,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+355,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+356,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+357,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+358,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+359,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+555,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+360,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+361,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+362,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+363,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+364,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+365,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_test0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+536,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+367,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+368,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+369,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+370,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_if", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+556,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+371,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+372,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+373,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+374,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+375,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+376,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+377,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+378,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+379,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+380,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+381,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+382,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+383,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+384,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+385,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+386,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+387,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+388,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+390,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+391,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+392,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+393,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+394,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+395,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+557,0,"en_ifetch_i",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+397,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+398,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+400,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+401,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+402,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+558,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+404,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+405,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+406,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+408,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+409,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+410,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+411,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+412,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+413,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+416,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+417,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+418,0,"rspop_q",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+419,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+420,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o_pre", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+422,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+423,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+424,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+425,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+426,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+427,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+428,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+429,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+430,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+431,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_err", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+432,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+433,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+434,0,"a_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"a_opcode",1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"a_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"a_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+438,0,"a_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+439,0,"a_address",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+440,0,"a_mask",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+441,0,"a_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+442,0,"rsvd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+443,0,"instr_type",2, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+444,0,"cmd_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+445,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+446,0,"d_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+447,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+558,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+558,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+448,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+449,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+450,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+451,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+452,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+453,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+454,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+455,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+456,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+457,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+559,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+458,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+459,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+460,0,"d_opcode",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+462,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+465,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+467,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+468,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+469,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+471,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+472,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+473,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+475,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+476,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+477,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+478,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+479,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+480,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+481,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_i", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+482,0,"d_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+483,0,"d_opcode",3, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+484,0,"d_param",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+485,0,"d_size",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+486,0,"d_source",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+487,0,"d_sink",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+488,0,"d_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+489,0,"rsp_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+490,0,"data_intg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+491,0,"d_error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+492,0,"a_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tl_o", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+493,0,"d_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+494,0,"d_opcode",3, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+495,0,"d_param",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+496,0,"d_size",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+497,0,"d_source",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+498,0,"d_sink",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+499,0,"d_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+500,0,"rsp_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+501,0,"data_intg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+502,0,"d_error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+503,0,"a_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+504,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_timer_v0", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+505,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+506,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+507,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+508,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+509,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+511,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+512,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+513,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+514,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+515,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+516,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+546,0,"SwAccess",4, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+517,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+518,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+519,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+520,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+523,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+524,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tlul_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "top_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__top_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
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
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 0);
    for (int i = 0; i < 1; ++i) {
        VL_TRACE_DECL_BIT_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (0 - i));
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__top_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__top_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+542,0,"TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+560,0,"TL_AUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+561,0,"TL_DUW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+558,0,"TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+556,0,"SecVolatileRawUnlockEn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+562,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+563,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+562,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+564,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+566,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+568,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+570,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+562,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+563,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+566,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+570,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+573,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 75,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+578,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 27,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+580,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+582,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+585,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+576,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 21,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_QUAD(tracep,c+580,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 38,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+585,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 71,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_WIDE(tracep,c+588,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 75,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____17(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__rv_timer_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__rv_timer_reg_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+535,0,"N_HARTS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+535,0,"N_TIMERS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"RV_TIMER_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"RV_TIMER_INTR_ENABLE0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"RV_TIMER_INTR_STATE0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"RV_TIMER_INTR_TEST0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+595,0,"RV_TIMER_CFG0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"RV_TIMER_TIMER_V0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"RV_TIMER_COMPARE_V0_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"RV_TIMER_INTR_TEST0_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);

    Vtop___024root__trace_init_dtype____17(vlSelf, tracep, "RV_TIMER_PERMIT", 0, c+525, VerilatedTraceSigDirection::NONE);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____17(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____17(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____17(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____17(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____17\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 6);
    for (int i = 0; i < 7; ++i) {
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
    VL_TRACE_DECL_BUS(tracep,c+543,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+545,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+598,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+599,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+601,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__tlul_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__tlul_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+602,0,"ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+604,0,"H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"H2DCmdFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+604,0,"D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"D2HRspFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+604,0,"DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+606,0,"DataFullWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_A_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+607,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_H2D_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"a_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"a_opcode",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"a_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"a_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"a_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"a_address",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "a_user", VerilatedTracePrefixType::STRUCT_PACKED, 4, 0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"rsvd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+607,0,"instr_type",2, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"d_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_D_USER_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "TL_D2H_DEFAULT", VerilatedTracePrefixType::STRUCT_PACKED, 10, 0);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"d_opcode",3, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"d_param",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+610,0,"d_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"d_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"d_sink",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "d_user", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"rsp_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+608,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+540,0,"a_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC);
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
    bufp->fullCData(oldp+532,(0U),3);
    bufp->fullCData(oldp+533,(1U),3);
    bufp->fullCData(oldp+534,(4U),3);
    bufp->fullIData(oldp+535,(1U),32);
    bufp->fullIData(oldp+536,(1U),32);
    bufp->fullBit(oldp+537,(1U));
    bufp->fullQData(oldp+538,(0x0000004576656e74ULL),40);
    bufp->fullBit(oldp+540,(1U));
    bufp->fullIData(oldp+541,(5U),32);
    bufp->fullIData(oldp+542,(0x00000020U),32);
    bufp->fullIData(oldp+543,(4U),32);
    bufp->fullBit(oldp+544,(0U));
    bufp->fullIData(oldp+545,(0x0000000cU),32);
    bufp->fullCData(oldp+546,(0U),3);
    bufp->fullSData(oldp+547,(0U),12);
    bufp->fullBit(oldp+548,(0U));
    bufp->fullIData(oldp+549,(8U),32);
    bufp->fullCData(oldp+550,(1U),8);
    bufp->fullCData(oldp+551,(0U),8);
    bufp->fullIData(oldp+552,(0xffffffffU),32);
    bufp->fullIData(oldp+553,(0U),32);
    bufp->fullBit(oldp+554,(0U));
    bufp->fullCData(oldp+555,(3U),3);
    bufp->fullIData(oldp+556,(0U),32);
    bufp->fullCData(oldp+557,(9U),4);
    bufp->fullIData(oldp+558,(2U),32);
    bufp->fullCData(oldp+559,(1U),4);
    bufp->fullIData(oldp+560,(0x00000015U),32);
    bufp->fullIData(oldp+561,(0x0000000eU),32);
    bufp->fullCData(oldp+562,(0U),6);
    bufp->fullIData(oldp+563,(0U),22);
    bufp->fullIData(oldp+564,(0U),28);
    bufp->fullCData(oldp+565,(0U),7);
    bufp->fullQData(oldp+566,(0ULL),39);
    bufp->fullQData(oldp+568,(0ULL),64);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+570,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+573,(__Vtemp_2),76);
    bufp->fullCData(oldp+576,(0x2aU),6);
    bufp->fullIData(oldp+577,(0x002a0000U),22);
    bufp->fullIData(oldp+578,(0x0a800000U),28);
    bufp->fullCData(oldp+579,(0x2aU),7);
    bufp->fullQData(oldp+580,(0x0000002a00000000ULL),39);
    bufp->fullQData(oldp+582,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+584,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0x000000aaU;
    bufp->fullWData(oldp+585,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0x00000aa0U;
    bufp->fullWData(oldp+588,(__Vtemp_4),76);
    bufp->fullCData(oldp+591,(0U),5);
    bufp->fullCData(oldp+592,(4U),5);
    bufp->fullCData(oldp+593,(8U),5);
    bufp->fullCData(oldp+594,(0x0cU),5);
    bufp->fullCData(oldp+595,(0x10U),5);
    bufp->fullCData(oldp+596,(0x14U),5);
    bufp->fullCData(oldp+597,(0x18U),5);
    bufp->fullIData(oldp+598,(0x00000010U),32);
    bufp->fullIData(oldp+599,(0x00000014U),32);
    bufp->fullIData(oldp+600,(0x00000018U),32);
    bufp->fullIData(oldp+601,(0x0000001cU),32);
    bufp->fullIData(oldp+602,(0x00505043U),24);
    bufp->fullIData(oldp+603,(0x00000039U),32);
    bufp->fullIData(oldp+604,(7U),32);
    bufp->fullIData(oldp+605,(0x00000040U),32);
    bufp->fullIData(oldp+606,(0x00000027U),32);
    bufp->fullCData(oldp+607,(9U),4);
    bufp->fullCData(oldp+608,(0x7fU),7);
    bufp->fullCData(oldp+609,(0U),3);
    bufp->fullCData(oldp+610,(0U),2);
    bufp->fullCData(oldp+611,(0U),4);
    bufp->fullCData(oldp+612,(0U),3);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 1>& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 7>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.rv_timer_tb__DOT__clk_i));
    bufp->fullBit(oldp+1,(vlSelfRef.rv_timer_tb__DOT__rst_ni));
    bufp->fullCData(oldp+2,(vlSelfRef.rv_timer_tb__DOT__gpio_intr_i),2);
    bufp->fullBit(oldp+3,(vlSelfRef.rv_timer_tb__DOT__intr_timer_expired_hart0_timer0_o));
    bufp->fullBit(oldp+4,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_valid));
    bufp->fullCData(oldp+5,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_opcode),3);
    bufp->fullCData(oldp+6,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_param),3);
    bufp->fullCData(oldp+7,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_size),2);
    bufp->fullCData(oldp+8,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_source),8);
    bufp->fullIData(oldp+9,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_address),32);
    bufp->fullCData(oldp+10,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_mask),4);
    bufp->fullIData(oldp+11,(vlSelfRef.rv_timer_tb__DOT__tl_i_a_data),32);
    bufp->fullBit(oldp+12,(vlSelfRef.rv_timer_tb__DOT__tl_i_d_ready));
    bufp->fullBit(oldp+13,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_valid));
    bufp->fullCData(oldp+14,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_opcode),3);
    bufp->fullIData(oldp+15,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_data),32);
    bufp->fullBit(oldp+16,(vlSelfRef.rv_timer_tb__DOT__tl_o_d_error));
    bufp->fullBit(oldp+17,(vlSelfRef.rv_timer_tb__DOT__tl_o_a_ready));
    bufp->fullWData(oldp+18,(vlSelfRef.rv_timer_tb__DOT__tl_i),109);
    bufp->fullWData(oldp+22,(vlSelfRef.rv_timer_tb__DOT__tl_o),66);
    bufp->fullBit(oldp+25,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__clk_i));
    bufp->fullBit(oldp+26,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__rst_ni));
    bufp->fullCData(oldp+27,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gpio_intr_i),2);
    bufp->fullBit(oldp+28,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                  >> 0x0000000cU))));
    bufp->fullCData(oldp+29,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                    >> 9U))),3);
    bufp->fullCData(oldp+30,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                    >> 6U))),3);
    bufp->fullCData(oldp+31,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                    >> 4U))),2);
    bufp->fullCData(oldp+32,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[3U] 
                                              << 4U) 
                                             | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[2U] 
                                                >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+33,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[2U] 
                               << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                                         >> 0x0000001cU))),32);
    bufp->fullCData(oldp+34,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                                             >> 0x00000018U))),4);
    bufp->fullIData(oldp+35,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[1U] 
                               << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                         >> 0x00000018U))),32);
    bufp->fullCData(oldp+36,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                             >> 0x00000013U))),5);
    bufp->fullCData(oldp+37,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+38,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                             >> 8U))),7);
    bufp->fullCData(oldp+39,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U] 
                                             >> 1U))),7);
    bufp->fullBit(oldp+40,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_i[0U])));
    bufp->fullBit(oldp+41,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                  >> 1U))));
    bufp->fullCData(oldp+42,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[2U] 
                                     << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                               >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+43,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                    >> 0x0000001bU))),3);
    bufp->fullCData(oldp+44,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                    >> 0x00000019U))),2);
    bufp->fullCData(oldp+45,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                             >> 0x00000011U))),8);
    bufp->fullBit(oldp+46,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                                  >> 0x00000010U))));
    bufp->fullIData(oldp+47,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[1U] 
                               << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                                  >> 0x00000010U))),32);
    bufp->fullCData(oldp+48,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                             >> 9U))),7);
    bufp->fullCData(oldp+49,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                             >> 2U))),7);
    bufp->fullBit(oldp+50,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U] 
                                  >> 1U))));
    bufp->fullBit(oldp+51,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tl_o[0U])));
    bufp->fullBit(oldp+52,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_expired_hart0_timer0_o));
    bufp->fullBit(oldp+53,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x0000001bU))));
    bufp->fullBit(oldp+54,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x0000001aU))));
    bufp->fullBit(oldp+55,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x00000019U))));
    bufp->fullBit(oldp+56,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x00000018U))));
    bufp->fullBit(oldp+57,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x00000017U))));
    bufp->fullBit(oldp+58,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x00000016U))));
    bufp->fullBit(oldp+59,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                  >> 0x00000015U))));
    bufp->fullCData(oldp+60,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                             >> 0x0000000dU))),8);
    bufp->fullSData(oldp+61,((0x00000fffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                                             >> 1U))),12);
    bufp->fullIData(oldp+62,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[2U] 
                               << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                                                  >> 1U))),32);
    bufp->fullIData(oldp+63,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[1U] 
                               << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U] 
                                                  >> 1U))),32);
    bufp->fullBit(oldp+64,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__reg2hw[0U])));
    bufp->fullBit(oldp+65,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                          >> 0x00000022U)))));
    bufp->fullBit(oldp+66,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                          >> 0x00000021U)))));
    bufp->fullIData(oldp+67,((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg 
                                      >> 1U))),32);
    bufp->fullBit(oldp+68,((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__hw2reg))));
    bufp->fullBit(oldp+69,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__active));
    bufp->fullSData(oldp+70,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__prescaler[0]),12);
    bufp->fullCData(oldp+71,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__step[0]),8);
    bufp->fullBit(oldp+72,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__tick));
    bufp->fullIData(oldp+73,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime_d[0]),32);
    bufp->fullIData(oldp+74,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtime[0]),32);
    bufp->fullIData(oldp+75,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp[0U][0U]),32);
    bufp->fullBit(oldp+76,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__mtimecmp_update[0U][0U]));
    bufp->fullBit(oldp+77,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_set));
    bufp->fullBit(oldp+78,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_en));
    bufp->fullBit(oldp+79,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_q));
    bufp->fullBit(oldp+80,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_test_qe));
    bufp->fullBit(oldp+81,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_q));
    bufp->fullBit(oldp+82,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_de));
    bufp->fullBit(oldp+83,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_timer_state_d));
    bufp->fullBit(oldp+84,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__intr_out));
    bufp->fullBit(oldp+85,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_d[0]));
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 86, vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__input_capture_active_q);
    bufp->fullBit(oldp+87,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_0));
    bufp->fullBit(oldp+88,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__sel_gpio_intr_1));
    bufp->fullBit(oldp+89,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__clk_i));
    bufp->fullBit(oldp+90,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__rst_ni));
    bufp->fullBit(oldp+91,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__active));
    bufp->fullSData(oldp+92,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__prescaler),12);
    bufp->fullCData(oldp+93,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__step),8);
    bufp->fullBit(oldp+94,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick));
    bufp->fullIData(oldp+95,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime_d),32);
    bufp->fullIData(oldp+96,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtime),32);
    bufp->fullIData(oldp+97,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__mtimecmp[0]),32);
    bufp->fullBit(oldp+98,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__intr));
    bufp->fullSData(oldp+99,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_core__DOT__tick_count),12);
    bufp->fullBit(oldp+100,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__clk_i));
    bufp->fullBit(oldp+101,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__rst_ni));
    bufp->fullBit(oldp+102,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__event_intr_i));
    bufp->fullBit(oldp+103,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_enable_q_i));
    bufp->fullBit(oldp+104,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_q_i));
    bufp->fullBit(oldp+105,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_test_qe_i));
    bufp->fullBit(oldp+106,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__reg2hw_intr_state_q_i));
    bufp->fullBit(oldp+107,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_de_o));
    bufp->fullBit(oldp+108,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__hw2reg_intr_state_d_o));
    bufp->fullBit(oldp+109,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__intr_o));
    bufp->fullBit(oldp+110,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__status));
    bufp->fullBit(oldp+111,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__gen_harts__BRA__0__KET____DOT__u_intr_hw__DOT__g_intr_event__DOT__new_event));
    bufp->fullBit(oldp+112,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__clk_i));
    bufp->fullBit(oldp+113,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__rst_ni));
    bufp->fullBit(oldp+114,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+115,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+116,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+117,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+118,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+119,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+120,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+121,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+122,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+123,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+124,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+125,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+126,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_i[0U])));
    bufp->fullBit(oldp+127,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+128,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+129,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+130,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+131,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+132,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+133,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+134,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+135,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+136,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+137,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o[0U])));
    bufp->fullBit(oldp+138,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x0000001bU))));
    bufp->fullBit(oldp+139,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x0000001aU))));
    bufp->fullBit(oldp+140,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x00000019U))));
    bufp->fullBit(oldp+141,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x00000018U))));
    bufp->fullBit(oldp+142,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x00000017U))));
    bufp->fullBit(oldp+143,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x00000016U))));
    bufp->fullBit(oldp+144,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                   >> 0x00000015U))));
    bufp->fullCData(oldp+145,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                              >> 0x0000000dU))),8);
    bufp->fullSData(oldp+146,((0x00000fffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                              >> 1U))),12);
    bufp->fullIData(oldp+147,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[2U] 
                                << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                                   >> 1U))),32);
    bufp->fullIData(oldp+148,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[1U] 
                                << 0x0000001fU) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U] 
                                                   >> 1U))),32);
    bufp->fullBit(oldp+149,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg2hw[0U])));
    bufp->fullBit(oldp+150,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                           >> 0x00000022U)))));
    bufp->fullBit(oldp+151,((1U & (IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                           >> 0x00000021U)))));
    bufp->fullIData(oldp+152,((IData)((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg 
                                       >> 1U))),32);
    bufp->fullBit(oldp+153,((1U & (IData)(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__hw2reg))));
    bufp->fullBit(oldp+154,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_we));
    bufp->fullBit(oldp+155,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_re));
    bufp->fullCData(oldp+156,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_addr),5);
    bufp->fullIData(oldp+157,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_wdata),32);
    bufp->fullCData(oldp+158,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_be),4);
    bufp->fullIData(oldp+159,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata),32);
    bufp->fullBit(oldp+160,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_error));
    bufp->fullBit(oldp+161,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addrmiss));
    bufp->fullBit(oldp+162,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__wr_err));
    bufp->fullIData(oldp+163,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+164,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+165,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+166,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+167,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+168,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[3U] 
                                               << 4U) 
                                              | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+169,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[2U] 
                                << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+170,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+171,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[1U] 
                                << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+172,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+173,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+174,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+175,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+176,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_h2d[0U])));
    bufp->fullBit(oldp+177,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+178,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+179,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+180,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+181,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+182,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+183,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+184,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+185,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+186,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+187,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_reg_d2h[0U])));
    bufp->fullBit(oldp+188,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+189,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+190,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+191,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+192,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+193,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+194,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+195,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+196,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+197,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+198,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__tl_o_pre[0U])));
    bufp->fullBit(oldp+199,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_we));
    bufp->fullBit(oldp+200,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_qs));
    bufp->fullBit(oldp+201,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_active_0_wd));
    bufp->fullBit(oldp+202,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_qs));
    bufp->fullBit(oldp+203,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_0_0_wd));
    bufp->fullBit(oldp+204,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_qs));
    bufp->fullBit(oldp+205,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__ctrl_gpio_intr_1_0_wd));
    bufp->fullBit(oldp+206,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_we));
    bufp->fullBit(oldp+207,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_qs));
    bufp->fullBit(oldp+208,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_enable0_wd));
    bufp->fullBit(oldp+209,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_we));
    bufp->fullBit(oldp+210,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_qs));
    bufp->fullBit(oldp+211,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_state0_wd));
    bufp->fullBit(oldp+212,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_we));
    bufp->fullBit(oldp+213,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_wd));
    bufp->fullBit(oldp+214,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_we));
    bufp->fullSData(oldp+215,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_qs),12);
    bufp->fullSData(oldp+216,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_prescale_wd),12);
    bufp->fullCData(oldp+217,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_qs),8);
    bufp->fullCData(oldp+218,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__cfg0_step_wd),8);
    bufp->fullBit(oldp+219,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_we));
    bufp->fullIData(oldp+220,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_qs),32);
    bufp->fullIData(oldp+221,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__timer_v0_wd),32);
    bufp->fullBit(oldp+222,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_we));
    bufp->fullIData(oldp+223,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qs),32);
    bufp->fullIData(oldp+224,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_wd),32);
    bufp->fullBit(oldp+225,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_qe));
    bufp->fullBit(oldp+226,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__intr_test0_flds_we));
    bufp->fullBit(oldp+227,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_qe));
    bufp->fullBit(oldp+228,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__compare_v0_flds_we));
    bufp->fullCData(oldp+229,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__addr_hit),7);
    bufp->fullBit(oldp+230,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__unused_wdata));
    bufp->fullBit(oldp+231,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__unused_be));
    bufp->fullBit(oldp+232,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__clk_i));
    bufp->fullBit(oldp+233,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__rst_ni));
    bufp->fullBit(oldp+234,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__we));
    bufp->fullSData(oldp+235,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wd),12);
    bufp->fullBit(oldp+236,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qe));
    bufp->fullSData(oldp+237,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__q),12);
    bufp->fullSData(oldp+238,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__ds),12);
    bufp->fullSData(oldp+239,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__qs),12);
    bufp->fullBit(oldp+240,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en));
    bufp->fullSData(oldp+241,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_data),12);
    bufp->fullBit(oldp+242,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__we));
    bufp->fullSData(oldp+243,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wd),12);
    bufp->fullSData(oldp+244,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__q),12);
    bufp->fullBit(oldp+245,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullSData(oldp+246,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__wr_data),12);
    bufp->fullSData(oldp+247,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_prescale__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),12);
    bufp->fullBit(oldp+248,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__clk_i));
    bufp->fullBit(oldp+249,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__rst_ni));
    bufp->fullBit(oldp+250,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__we));
    bufp->fullCData(oldp+251,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wd),8);
    bufp->fullBit(oldp+252,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qe));
    bufp->fullCData(oldp+253,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__q),8);
    bufp->fullCData(oldp+254,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__ds),8);
    bufp->fullCData(oldp+255,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__qs),8);
    bufp->fullBit(oldp+256,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en));
    bufp->fullCData(oldp+257,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_data),8);
    bufp->fullBit(oldp+258,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+259,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->fullCData(oldp+260,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__q),8);
    bufp->fullBit(oldp+261,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+262,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->fullCData(oldp+263,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_cfg0_step__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->fullBit(oldp+264,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__clk_i));
    bufp->fullBit(oldp+265,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__rst_ni));
    bufp->fullBit(oldp+266,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__we));
    bufp->fullIData(oldp+267,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wd),32);
    bufp->fullBit(oldp+268,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qe));
    bufp->fullIData(oldp+269,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__q),32);
    bufp->fullIData(oldp+270,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__ds),32);
    bufp->fullIData(oldp+271,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__qs),32);
    bufp->fullBit(oldp+272,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en));
    bufp->fullIData(oldp+273,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_data),32);
    bufp->fullBit(oldp+274,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullIData(oldp+275,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->fullIData(oldp+276,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__q),32);
    bufp->fullBit(oldp+277,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullIData(oldp+278,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->fullIData(oldp+279,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    bufp->fullBit(oldp+280,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__clk_i));
    bufp->fullBit(oldp+281,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__rst_ni));
    bufp->fullBit(oldp+282,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__d_i));
    bufp->fullBit(oldp+283,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_compare_v00_qe__DOT__q_o));
    bufp->fullBit(oldp+284,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__clk_i));
    bufp->fullBit(oldp+285,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__rst_ni));
    bufp->fullBit(oldp+286,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__we));
    bufp->fullBit(oldp+287,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wd));
    bufp->fullBit(oldp+288,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qe));
    bufp->fullBit(oldp+289,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__q));
    bufp->fullBit(oldp+290,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__ds));
    bufp->fullBit(oldp+291,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__qs));
    bufp->fullBit(oldp+292,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en));
    bufp->fullBit(oldp+293,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_data));
    bufp->fullBit(oldp+294,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+295,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+296,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+297,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+298,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+299,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_active_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+300,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__clk_i));
    bufp->fullBit(oldp+301,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__rst_ni));
    bufp->fullBit(oldp+302,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__we));
    bufp->fullBit(oldp+303,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wd));
    bufp->fullBit(oldp+304,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qe));
    bufp->fullBit(oldp+305,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__q));
    bufp->fullBit(oldp+306,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__ds));
    bufp->fullBit(oldp+307,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__qs));
    bufp->fullBit(oldp+308,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en));
    bufp->fullBit(oldp+309,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_data));
    bufp->fullBit(oldp+310,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+311,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+312,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+313,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+314,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+315,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_0_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+316,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__clk_i));
    bufp->fullBit(oldp+317,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__rst_ni));
    bufp->fullBit(oldp+318,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__we));
    bufp->fullBit(oldp+319,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wd));
    bufp->fullBit(oldp+320,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qe));
    bufp->fullBit(oldp+321,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__q));
    bufp->fullBit(oldp+322,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__ds));
    bufp->fullBit(oldp+323,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__qs));
    bufp->fullBit(oldp+324,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en));
    bufp->fullBit(oldp+325,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_data));
    bufp->fullBit(oldp+326,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+327,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+328,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+329,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+330,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+331,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_ctrl_gpio_intr_1_0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+332,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__clk_i));
    bufp->fullBit(oldp+333,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__rst_ni));
    bufp->fullBit(oldp+334,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__we));
    bufp->fullBit(oldp+335,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wd));
    bufp->fullBit(oldp+336,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qe));
    bufp->fullBit(oldp+337,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__q));
    bufp->fullBit(oldp+338,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__ds));
    bufp->fullBit(oldp+339,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__qs));
    bufp->fullBit(oldp+340,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en));
    bufp->fullBit(oldp+341,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_data));
    bufp->fullBit(oldp+342,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+343,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+344,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+345,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+346,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+347,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_enable0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+348,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__clk_i));
    bufp->fullBit(oldp+349,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__rst_ni));
    bufp->fullBit(oldp+350,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__we));
    bufp->fullBit(oldp+351,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wd));
    bufp->fullBit(oldp+352,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__de));
    bufp->fullBit(oldp+353,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__d));
    bufp->fullBit(oldp+354,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qe));
    bufp->fullBit(oldp+355,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__q));
    bufp->fullBit(oldp+356,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__ds));
    bufp->fullBit(oldp+357,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__qs));
    bufp->fullBit(oldp+358,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en));
    bufp->fullBit(oldp+359,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_data));
    bufp->fullBit(oldp+360,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+361,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+362,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__de));
    bufp->fullBit(oldp+363,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__d));
    bufp->fullBit(oldp+364,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+365,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+366,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_state0__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+367,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__we));
    bufp->fullBit(oldp+368,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__wd));
    bufp->fullBit(oldp+369,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__qe));
    bufp->fullBit(oldp+370,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_intr_test0__DOT__q));
    bufp->fullBit(oldp+371,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__clk_i));
    bufp->fullBit(oldp+372,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rst_ni));
    bufp->fullBit(oldp+373,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+374,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+375,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+376,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+377,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+378,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+379,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+380,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+381,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+382,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+383,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+384,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+385,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_i[0U])));
    bufp->fullBit(oldp+386,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+387,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+388,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+389,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+390,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+391,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+392,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+393,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+394,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+395,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+396,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o[0U])));
    bufp->fullBit(oldp+397,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__re_o));
    bufp->fullBit(oldp+398,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__we_o));
    bufp->fullCData(oldp+399,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_o),5);
    bufp->fullIData(oldp+400,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wdata_o),32);
    bufp->fullCData(oldp+401,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__be_o),4);
    bufp->fullIData(oldp+402,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_i),32);
    bufp->fullBit(oldp+403,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_i));
    bufp->fullBit(oldp+404,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__outstanding_q));
    bufp->fullBit(oldp+405,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__a_ack));
    bufp->fullBit(oldp+406,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__d_ack));
    bufp->fullIData(oldp+407,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata),32);
    bufp->fullIData(oldp+408,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rdata_q),32);
    bufp->fullBit(oldp+409,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error_q));
    bufp->fullBit(oldp+410,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__error));
    bufp->fullBit(oldp+411,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__err_internal));
    bufp->fullBit(oldp+412,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__instr_error));
    bufp->fullBit(oldp+413,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__addr_align_err));
    bufp->fullBit(oldp+414,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__malformed_meta_err));
    bufp->fullBit(oldp+415,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_err));
    bufp->fullCData(oldp+416,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqid_q),8);
    bufp->fullCData(oldp+417,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__reqsz_q),2);
    bufp->fullCData(oldp+418,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rspop_q),3);
    bufp->fullBit(oldp+419,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__rd_req));
    bufp->fullBit(oldp+420,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__wr_req));
    bufp->fullBit(oldp+421,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+422,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+423,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+424,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+425,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+426,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+427,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+428,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+429,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+430,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+431,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__tl_o_pre[0U])));
    bufp->fullBit(oldp+432,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__clk_i));
    bufp->fullBit(oldp+433,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__rst_ni));
    bufp->fullBit(oldp+434,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                   >> 0x0000000cU))));
    bufp->fullCData(oldp+435,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 9U))),3);
    bufp->fullCData(oldp+436,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 6U))),3);
    bufp->fullCData(oldp+437,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                     >> 4U))),2);
    bufp->fullCData(oldp+438,((0x000000ffU & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[3U] 
                                               << 4U) 
                                              | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                                 >> 0x0000001cU)))),8);
    bufp->fullIData(oldp+439,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[2U] 
                                << 4U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                          >> 0x0000001cU))),32);
    bufp->fullCData(oldp+440,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                              >> 0x00000018U))),4);
    bufp->fullIData(oldp+441,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[1U] 
                                << 8U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                          >> 0x00000018U))),32);
    bufp->fullCData(oldp+442,((0x0000001fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x00000013U))),5);
    bufp->fullCData(oldp+443,((0x0000000fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 0x0000000fU))),4);
    bufp->fullCData(oldp+444,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 8U))),7);
    bufp->fullCData(oldp+445,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U] 
                                              >> 1U))),7);
    bufp->fullBit(oldp+446,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__tl_i[0U])));
    bufp->fullBit(oldp+447,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__err_o));
    bufp->fullBit(oldp+448,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__opcode_allowed));
    bufp->fullBit(oldp+449,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__a_config_allowed));
    bufp->fullBit(oldp+450,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_full));
    bufp->fullBit(oldp+451,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_partial));
    bufp->fullBit(oldp+452,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__op_get));
    bufp->fullBit(oldp+453,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+454,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+455,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+456,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+457,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk));
    bufp->fullCData(oldp+458,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_err__DOT__mask),4);
    bufp->fullBit(oldp+459,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+460,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+461,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+462,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+463,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+464,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+465,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+466,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+467,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+468,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+469,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->fullBit(oldp+470,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+471,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+472,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+473,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+474,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+475,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+476,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+477,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+478,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+479,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+480,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->fullBit(oldp+481,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_reg_if__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->fullBit(oldp+482,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+483,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+484,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+485,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+486,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+487,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+488,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+489,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+490,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+491,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+492,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_i[0U])));
    bufp->fullBit(oldp+493,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                   >> 1U))));
    bufp->fullCData(oldp+494,((7U & ((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[2U] 
                                      << 2U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                                >> 0x0000001eU)))),3);
    bufp->fullCData(oldp+495,((7U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x0000001bU))),3);
    bufp->fullCData(oldp+496,((3U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                     >> 0x00000019U))),2);
    bufp->fullCData(oldp+497,((0x000000ffU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                              >> 0x00000011U))),8);
    bufp->fullBit(oldp+498,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                   >> 0x00000010U))));
    bufp->fullIData(oldp+499,(((vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[1U] 
                                << 0x00000010U) | (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                                   >> 0x00000010U))),32);
    bufp->fullCData(oldp+500,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 9U))),7);
    bufp->fullCData(oldp+501,((0x0000007fU & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                              >> 2U))),7);
    bufp->fullBit(oldp+502,((1U & (vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U] 
                                   >> 1U))));
    bufp->fullBit(oldp+503,((1U & vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__tl_o[0U])));
    bufp->fullBit(oldp+504,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_rsp_intg_gen__DOT__unused_tl));
    bufp->fullBit(oldp+505,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__clk_i));
    bufp->fullBit(oldp+506,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__rst_ni));
    bufp->fullBit(oldp+507,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__we));
    bufp->fullIData(oldp+508,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wd),32);
    bufp->fullBit(oldp+509,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__de));
    bufp->fullIData(oldp+510,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__d),32);
    bufp->fullBit(oldp+511,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qe));
    bufp->fullIData(oldp+512,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__q),32);
    bufp->fullIData(oldp+513,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__ds),32);
    bufp->fullIData(oldp+514,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__qs),32);
    bufp->fullBit(oldp+515,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en));
    bufp->fullIData(oldp+516,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_data),32);
    bufp->fullBit(oldp+517,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__we));
    bufp->fullIData(oldp+518,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wd),32);
    bufp->fullBit(oldp+519,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__de));
    bufp->fullIData(oldp+520,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__d),32);
    bufp->fullIData(oldp+521,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__q),32);
    bufp->fullBit(oldp+522,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullIData(oldp+523,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__wr_data),32);
    bufp->fullIData(oldp+524,(vlSelfRef.rv_timer_tb__DOT__u_rv_timer__DOT__u_reg__DOT__u_timer_v0__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),32);
    Vtop___024root__trace_full_dtype____1(vlSelf, bufp, 525, vlSymsp->TOP__rv_timer_reg_pkg.RV_TIMER_PERMIT);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*0:0*/, 1>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullBit(oldp+0,(__VdtypeVar[0]));
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 7>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[0]),4);
    bufp->fullCData(oldp+1,(__VdtypeVar[1]),4);
    bufp->fullCData(oldp+2,(__VdtypeVar[2]),4);
    bufp->fullCData(oldp+3,(__VdtypeVar[3]),4);
    bufp->fullCData(oldp+4,(__VdtypeVar[4]),4);
    bufp->fullCData(oldp+5,(__VdtypeVar[5]),4);
    bufp->fullCData(oldp+6,(__VdtypeVar[6]),4);
}
