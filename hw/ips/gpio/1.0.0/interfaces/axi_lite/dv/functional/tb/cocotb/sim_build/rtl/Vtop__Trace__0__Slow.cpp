// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__axi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____16(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____19(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____22(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____29(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "axi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__axi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
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
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+8,0,"aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"w_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+16,0,"r_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+17,0,"aw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+19,0,"resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+21,0,"ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+22,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+24,0,"r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+25,0,"axi_aw_addr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"axi_aw_prot_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"axi_aw_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"axi_aw_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"axi_w_data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+30,0,"axi_w_strb_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+31,0,"axi_w_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"axi_w_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+33,0,"axi_b_resp_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"axi_b_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"axi_b_ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"axi_ar_addr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+37,0,"axi_ar_prot_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+38,0,"axi_ar_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"axi_ar_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"axi_r_data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"axi_r_resp_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+42,0,"axi_r_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+43,0,"axi_r_ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"cio_gpio_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"cio_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"cio_gpio_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"intr_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+59,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+62,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+65,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+66,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+67,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+68,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+69,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+70,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+73,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+74,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+75,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+78,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+79,0,"de",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+80,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+81,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+82,0,"reg_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"core_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_core_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+85,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+86,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+87,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+88,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+91,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+93,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+94,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+96,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+97,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+98,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+99,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+100,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+101,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+102,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+103,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+107,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+108,0,"de",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+109,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+110,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+111,0,"cio_gpio_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+112,0,"cio_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"cio_gpio_en_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+114,0,"intr_gpio_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"GpioAsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"FilterCntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"data_in_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+116,0,"data_in_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+117,0,"gpio_o_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"gpio_oe_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"event_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+120,0,"event_fall",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+121,0,"event_high",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+122,0,"event_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+123,0,"filter_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+124,0,"state_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+125,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+126,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+127,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+128,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+129,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+131,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+132,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+133,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+134,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+135,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+136,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+137,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+138,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+140,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+141,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+143,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+145,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+146,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+147,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+148,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+149,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+150,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+151,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+152,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+153,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+154,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+155,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+156,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+157,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+158,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+159,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+160,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+161,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+163,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+167,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+168,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+171,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+172,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+173,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+175,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+176,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+177,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+178,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+180,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+181,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+182,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+183,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+184,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+185,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+186,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+187,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+188,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+189,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+190,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+191,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+192,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+193,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+194,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+195,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+198,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+199,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_input_filter[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+200,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+201,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+202,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+203,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+723,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+204,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+205,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+206,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+207,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+208,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+209,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+210,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_async", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+211,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+212,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+213,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+214,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+215,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+216,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+217,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+218,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+219,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+220,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+221,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+222,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+223,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+224,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_filter_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+225,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+226,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+227,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_state_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+228,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+229,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+230,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_gpio_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+231,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+232,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+233,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+234,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+235,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+236,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+237,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+238,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+239,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+240,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+241,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+242,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+243,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+244,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+245,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+246,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+247,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+249,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+250,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+251,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+252,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+253,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+254,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+255,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+256,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+257,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+258,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+259,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+260,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+262,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+264,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_axi_reg_req", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+265,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+266,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+267,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+268,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+269,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_axi_reg_rsp", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+270,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+271,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+272,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_flexsoc_axi_to_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+726,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+727,0,"BUFFER_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"DECOUPLE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+273,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+274,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_req_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+275,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+276,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+277,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+278,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+279,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+280,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+281,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+282,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+283,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+284,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+285,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+286,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+287,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+288,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+289,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+290,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+291,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+292,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+293,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_req_o", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+294,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+295,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+296,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+297,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_rsp_i", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+300,0,"error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"write_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+303,0,"write_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "write_fifo_in", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+304,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+305,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+306,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "write_fifo_out", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+307,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+308,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+309,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+310,0,"write_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+311,0,"write_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"write_resp_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+313,0,"write_resp_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"write_resp_fifo_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+315,0,"write_resp_fifo_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+316,0,"write_resp_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+317,0,"write_resp_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+318,0,"read_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+319,0,"read_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+320,0,"read_fifo_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+321,0,"read_fifo_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+322,0,"read_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+323,0,"read_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+324,0,"read_resp_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+325,0,"read_resp_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "read_resp_fifo_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+326,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+327,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "read_resp_fifo_out", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+328,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+329,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+330,0,"read_resp_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+331,0,"read_resp_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "read_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+332,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+333,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "write_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+334,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "arb_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+336,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+337,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+338,0,"read_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+339,0,"write_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+340,0,"read_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+341,0,"write_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_read", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+342,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+343,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+344,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+345,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+346,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+347,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+348,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+349,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+350,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+351,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+352,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+353,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+354,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+355,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+356,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+357,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+358,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+359,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____16(vlSelf, tracep, "mem_q", 0, c+360, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_read_resp", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+732,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+362,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+363,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+364,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+365,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+367,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+368,0,"error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+369,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+370,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+371,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+372,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+373,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+374,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+375,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+376,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+377,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+378,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+379,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+380,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+381,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+382,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+383,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____19(vlSelf, tracep, "mem_q", 0, c+384, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_write_req", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+732,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+388,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+389,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+390,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+391,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+392,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+393,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+394,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+397,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+399,0,"strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+401,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+402,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+403,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+404,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+405,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+406,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+408,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+409,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+412,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+413,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____22(vlSelf, tracep, "mem_q", 0, c+414, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_write_resp", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+732,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+420,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+422,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+423,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+424,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+425,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+426,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+427,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+428,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+429,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+430,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+431,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+432,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+433,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+434,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+436,0,"mem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+437,0,"mem_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_stream_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+733,0,"N_INP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+734,0,"ARBITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "inp_data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+440,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+442,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+444,0,"inp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+445,0,"inp_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "oup_data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+446,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+447,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+448,0,"oup_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+449,0,"oup_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+733,0,"N_INP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+734,0,"ARBITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+450,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+451,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "inp_data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+452,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+453,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+454,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+455,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+456,0,"inp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+457,0,"inp_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "oup_data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+458,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+459,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+460,0,"oup_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+461,0,"oup_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_rr_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "i_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"NumIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+732,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"ExtPrio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"AxiVldRdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"LockIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"FairArb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"IdxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+462,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+463,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+735,0,"rr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+465,0,"gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+466,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+467,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+468,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+469,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+471,0,"gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+472,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+473,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+474,0,"idx_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+475,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "data_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+476,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+477,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+478,0,"gnt_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+479,0,"req_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+480,0,"rr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+481,0,"req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_int_rr", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+482,0,"rr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_fair_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+483,0,"upper_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+484,0,"lower_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+485,0,"upper_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+486,0,"lower_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+487,0,"next_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+488,0,"upper_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+489,0,"lower_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_lzc_lower", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"CNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+490,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+491,0,"cnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+492,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lzc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vtop___024root__trace_init_dtype____29(vlSelf, tracep, "index_lut", 0, c+493, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+495,0,"sel_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+496,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+497,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+498,0,"in_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_lzc_upper", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"CNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+499,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+500,0,"cnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+501,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lzc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vtop___024root__trace_init_dtype____29(vlSelf, tracep, "index_lut", 0, c+502, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+504,0,"sel_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+505,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+507,0,"in_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lock", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+508,0,"lock_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+509,0,"lock_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+510,0,"req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_levels[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+511,0,"sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+736,0,"Idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"Idx1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+512,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+513,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_req_i", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+514,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+515,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+516,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+517,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+518,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+520,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+521,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+522,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+523,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+524,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+525,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "intr_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "en_input_filter", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+526,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvllow", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+527,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_lvlhigh", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+528,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_falling", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+529,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "en_rising", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+530,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+532,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "direct", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_oe", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+533,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gpio_o", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+534,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+535,0,"intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+726,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+536,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+537,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+539,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+540,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+542,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+543,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+544,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+545,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+546,0,"reg_we_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+547,0,"reg_we_check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+549,0,"data_in_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+550,0,"direct_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+551,0,"direct_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"direct_gpio_o_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+553,0,"direct_gpio_o_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+554,0,"direct_gpio_oe_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+555,0,"direct_gpio_oe_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+556,0,"intr_ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+557,0,"intr_ctrl_en_rising_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+558,0,"intr_ctrl_en_rising_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+559,0,"intr_ctrl_en_falling_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+560,0,"intr_ctrl_en_falling_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+561,0,"intr_ctrl_en_lvlhigh_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+562,0,"intr_ctrl_en_lvlhigh_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+563,0,"intr_ctrl_en_lvllow_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+564,0,"intr_ctrl_en_lvllow_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"intr_ctrl_en_input_filter_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+566,0,"intr_ctrl_en_input_filter_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+567,0,"direct_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+568,0,"direct_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+569,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+570,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+571,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_data_in", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+737,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+572,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+573,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+574,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+575,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+576,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+578,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+580,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+581,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+737,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+582,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+583,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+585,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+586,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_ro", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"unused_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"unused_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+587,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_direct_gpio_o", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+588,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+589,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+590,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+592,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+593,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+595,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_direct_gpio_oe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+597,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+598,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+599,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+600,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+601,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+602,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+603,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+604,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+605,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_falling", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+606,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+607,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+608,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+610,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+611,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+612,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+613,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+614,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+616,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+618,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+619,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+620,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+621,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_input_filter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+622,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+623,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+624,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+626,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+628,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+629,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+630,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+631,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+632,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+633,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+634,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+635,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+636,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_lvlhigh", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+638,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+639,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+640,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+642,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+644,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+645,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+646,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+647,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+648,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+649,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+651,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+652,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+653,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_lvllow", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+654,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+655,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+656,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+657,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+658,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+659,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+660,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+661,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+662,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+664,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+667,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_intr_ctrl_en_rising", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+670,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+671,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+672,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+673,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+674,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+677,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+678,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+679,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+739,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+680,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+682,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+683,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+684,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+685,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_reg_we_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+740,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+686,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+687,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+688,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+689,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+690,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+691,0,"oh_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_buf", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+692,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+693,0,"out_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+694,0,"inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_onehot_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+740,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"AddrCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnableCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"StrictCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"EnableAlertTriggerSVA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+695,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+696,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+697,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+698,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+699,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+727,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+700,0,"or_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+701,0,"and_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+702,0,"err_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+727,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+727,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+744,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+745,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+746,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+747,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+748,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+749,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+744,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+750,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+751,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+745,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+752,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+753,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+703,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+704,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+705,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+706,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+707,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+708,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+709,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+710,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+718,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+711,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+712,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+713,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+714,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____16(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____16(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____16(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____16(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____16\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____19(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____19(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____19(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____19(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____19\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1,fidx,"error",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+3,fidx,"error",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____22(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____22(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____22(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____22(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____22\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"addr",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"strb",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"addr",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"strb",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____29(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____29(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____29\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____29(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____29(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____29\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__axi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__axi_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+729,0,"BurstWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"RespWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"CacheWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+740,0,"ProtWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"QosWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"RegionWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+754,0,"LenWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+740,0,"SizeWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+730,0,"LockWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+755,0,"AtopWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+722,0,"NsaidWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"BURST_FIXED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"BURST_INCR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+757,0,"BURST_WRAP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"RESP_OKAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"RESP_EXOKAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+757,0,"RESP_SLVERR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+758,0,"RESP_DECERR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+759,0,"CACHE_BUFFERABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+760,0,"CACHE_MODIFIABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+761,0,"CACHE_RD_ALLOC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+762,0,"CACHE_WR_ALLOC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+763,0,"ATOP_ATOMICSWAP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+764,0,"ATOP_ATOMICCMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"ATOP_NONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"ATOP_ATOMICSTORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+757,0,"ATOP_ATOMICLOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+719,0,"ATOP_LITTLE_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+720,0,"ATOP_BIG_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+765,0,"ATOP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+766,0,"ATOP_CLR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+767,0,"ATOP_EOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+768,0,"ATOP_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+769,0,"ATOP_SMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+770,0,"ATOP_SMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+771,0,"ATOP_UMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+772,0,"ATOP_UMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+773,0,"ATOP_R_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+774,0,"DemuxAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+775,0,"DemuxW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+776,0,"DemuxB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+777,0,"DemuxAr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+778,0,"DemuxR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+779,0,"MuxAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+780,0,"MuxW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+781,0,"MuxB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+782,0,"MuxAr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+783,0,"MuxR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____31(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__gpio_reg_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+725,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"NumRegs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+738,0,"GPIO_DATA_IN_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+761,0,"GPIO_DIRECT_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+762,0,"GPIO_INTR_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+784,0,"GPIO_DIRECT_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);

    Vtop___024root__trace_init_dtype____31(vlSelf, tracep, "GPIO_PERMIT", 0, c+715, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+726,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+725,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____31(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____31(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____31\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____31(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____31(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____31\n"); );
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
    VL_TRACE_DECL_BUS(tracep,c+725,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+747,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+751,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+785,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+786,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+787,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+788,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+726,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
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
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+718,(1U),32);
    bufp->fullBit(oldp+719,(0U));
    bufp->fullBit(oldp+720,(1U));
    bufp->fullBit(oldp+721,(1U));
    bufp->fullIData(oldp+722,(4U),32);
    bufp->fullCData(oldp+723,(0x0fU),4);
    bufp->fullBit(oldp+724,(1U));
    bufp->fullIData(oldp+725,(4U),32);
    bufp->fullIData(oldp+726,(0x00000020U),32);
    bufp->fullIData(oldp+727,(2U),32);
    bufp->fullBit(oldp+728,(0U));
    bufp->fullIData(oldp+729,(2U),32);
    bufp->fullIData(oldp+730,(1U),32);
    bufp->fullBit(oldp+731,(0U));
    bufp->fullIData(oldp+732,(0x00000020U),32);
    bufp->fullIData(oldp+733,(2U),32);
    bufp->fullSData(oldp+734,(0x7272U),16);
    bufp->fullBit(oldp+735,(0U));
    bufp->fullIData(oldp+736,(0U),32);
    bufp->fullCData(oldp+737,(1U),3);
    bufp->fullCData(oldp+738,(0U),4);
    bufp->fullCData(oldp+739,(0U),3);
    bufp->fullIData(oldp+740,(3U),32);
    bufp->fullIData(oldp+741,(3U),32);
    bufp->fullCData(oldp+742,(0U),2);
    bufp->fullIData(oldp+743,(0U),32);
    bufp->fullIData(oldp+744,(5U),32);
    bufp->fullIData(oldp+745,(6U),32);
    bufp->fullIData(oldp+746,(7U),32);
    bufp->fullIData(oldp+747,(8U),32);
    bufp->fullIData(oldp+748,(9U),32);
    bufp->fullIData(oldp+749,(0x0000000aU),32);
    bufp->fullIData(oldp+750,(0x0000000bU),32);
    bufp->fullIData(oldp+751,(0x0000000cU),32);
    bufp->fullIData(oldp+752,(0x0000000dU),32);
    bufp->fullIData(oldp+753,(0x0000000eU),32);
    bufp->fullIData(oldp+754,(8U),32);
    bufp->fullIData(oldp+755,(6U),32);
    bufp->fullCData(oldp+756,(1U),2);
    bufp->fullCData(oldp+757,(2U),2);
    bufp->fullCData(oldp+758,(3U),2);
    bufp->fullCData(oldp+759,(1U),4);
    bufp->fullCData(oldp+760,(2U),4);
    bufp->fullCData(oldp+761,(4U),4);
    bufp->fullCData(oldp+762,(8U),4);
    bufp->fullCData(oldp+763,(0x30U),6);
    bufp->fullCData(oldp+764,(0x31U),6);
    bufp->fullCData(oldp+765,(0U),3);
    bufp->fullCData(oldp+766,(1U),3);
    bufp->fullCData(oldp+767,(2U),3);
    bufp->fullCData(oldp+768,(3U),3);
    bufp->fullCData(oldp+769,(4U),3);
    bufp->fullCData(oldp+770,(5U),3);
    bufp->fullCData(oldp+771,(6U),3);
    bufp->fullCData(oldp+772,(7U),3);
    bufp->fullIData(oldp+773,(5U),32);
    bufp->fullSData(oldp+774,(0x0200U),10);
    bufp->fullSData(oldp+775,(0x0100U),10);
    bufp->fullSData(oldp+776,(0x0080U),10);
    bufp->fullSData(oldp+777,(0x0040U),10);
    bufp->fullSData(oldp+778,(0x0020U),10);
    bufp->fullSData(oldp+779,(0x0010U),10);
    bufp->fullSData(oldp+780,(8U),10);
    bufp->fullSData(oldp+781,(4U),10);
    bufp->fullSData(oldp+782,(2U),10);
    bufp->fullSData(oldp+783,(1U),10);
    bufp->fullCData(oldp+784,(0U),8);
    bufp->fullIData(oldp+785,(0x00000010U),32);
    bufp->fullIData(oldp+786,(0x00000014U),32);
    bufp->fullIData(oldp+787,(0x00000018U),32);
    bufp->fullIData(oldp+788,(0x0000001cU),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*7:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*79:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar);

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
    bufp->fullCData(oldp+6,((0x0000000fU & (IData)(
                                                   (vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                    >> 0x00000033U)))),4);
    bufp->fullCData(oldp+7,((7U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                           >> 0x00000030U)))),3);
    bufp->fullBit(oldp+8,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                         >> 0x0000002fU)))));
    bufp->fullIData(oldp+9,((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                     >> 0x0000000fU))),32);
    bufp->fullCData(oldp+10,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                     >> 0x0000000bU)))),4);
    bufp->fullBit(oldp+11,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->fullBit(oldp+12,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                          >> 9U)))));
    bufp->fullCData(oldp+13,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                                     >> 5U)))),4);
    bufp->fullCData(oldp+14,((7U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->fullBit(oldp+15,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->fullBit(oldp+16,((1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_i))));
    bufp->fullBit(oldp+17,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->fullBit(oldp+18,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->fullCData(oldp+19,((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->fullBit(oldp+20,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->fullBit(oldp+21,((1U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->fullIData(oldp+22,((IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->fullCData(oldp+23,((3U & (IData)((vlSelfRef.gpio_tb__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->fullBit(oldp+24,((1U & (IData)(vlSelfRef.gpio_tb__DOT__axi_lite_o))));
    bufp->fullCData(oldp+25,(vlSelfRef.gpio_tb__DOT__axi_aw_addr_i),4);
    bufp->fullCData(oldp+26,(vlSelfRef.gpio_tb__DOT__axi_aw_prot_i),3);
    bufp->fullBit(oldp+27,(vlSelfRef.gpio_tb__DOT__axi_aw_valid_i));
    bufp->fullBit(oldp+28,(vlSelfRef.gpio_tb__DOT__axi_aw_ready_o));
    bufp->fullIData(oldp+29,(vlSelfRef.gpio_tb__DOT__axi_w_data_i),32);
    bufp->fullCData(oldp+30,(vlSelfRef.gpio_tb__DOT__axi_w_strb_i),4);
    bufp->fullBit(oldp+31,(vlSelfRef.gpio_tb__DOT__axi_w_valid_i));
    bufp->fullBit(oldp+32,(vlSelfRef.gpio_tb__DOT__axi_w_ready_o));
    bufp->fullCData(oldp+33,(vlSelfRef.gpio_tb__DOT__axi_b_resp_o),2);
    bufp->fullBit(oldp+34,(vlSelfRef.gpio_tb__DOT__axi_b_valid_o));
    bufp->fullBit(oldp+35,(vlSelfRef.gpio_tb__DOT__axi_b_ready_i));
    bufp->fullCData(oldp+36,(vlSelfRef.gpio_tb__DOT__axi_ar_addr_i),4);
    bufp->fullCData(oldp+37,(vlSelfRef.gpio_tb__DOT__axi_ar_prot_i),3);
    bufp->fullBit(oldp+38,(vlSelfRef.gpio_tb__DOT__axi_ar_valid_i));
    bufp->fullBit(oldp+39,(vlSelfRef.gpio_tb__DOT__axi_ar_ready_o));
    bufp->fullIData(oldp+40,(vlSelfRef.gpio_tb__DOT__axi_r_data_o),32);
    bufp->fullCData(oldp+41,(vlSelfRef.gpio_tb__DOT__axi_r_resp_o),2);
    bufp->fullBit(oldp+42,(vlSelfRef.gpio_tb__DOT__axi_r_valid_o));
    bufp->fullBit(oldp+43,(vlSelfRef.gpio_tb__DOT__axi_r_ready_i));
    bufp->fullBit(oldp+44,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__clk_i));
    bufp->fullBit(oldp+45,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__rst_ni));
    bufp->fullCData(oldp+46,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_i),4);
    bufp->fullCData(oldp+47,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_o),4);
    bufp->fullCData(oldp+48,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__cio_gpio_en_o),4);
    bufp->fullCData(oldp+49,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__intr_gpio_o),4);
    bufp->fullCData(oldp+50,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                     >> 0x00000033U)))),4);
    bufp->fullCData(oldp+51,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                            >> 0x00000030U)))),3);
    bufp->fullBit(oldp+52,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                          >> 0x0000002fU)))));
    bufp->fullIData(oldp+53,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                      >> 0x0000000fU))),32);
    bufp->fullCData(oldp+54,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                     >> 0x0000000bU)))),4);
    bufp->fullBit(oldp+55,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->fullBit(oldp+56,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                          >> 9U)))));
    bufp->fullCData(oldp+57,((0x0000000fU & (IData)(
                                                    (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                                     >> 5U)))),4);
    bufp->fullCData(oldp+58,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->fullBit(oldp+59,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->fullBit(oldp+60,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_i))));
    bufp->fullBit(oldp+61,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->fullBit(oldp+62,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->fullCData(oldp+63,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->fullBit(oldp+64,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->fullBit(oldp+65,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->fullIData(oldp+66,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->fullCData(oldp+67,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->fullBit(oldp+68,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__axi_lite_o))));
    bufp->fullCData(oldp+69,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->fullBit(oldp+70,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->fullCData(oldp+71,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x00000015U))),4);
    bufp->fullBit(oldp+72,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                  >> 0x00000014U))));
    bufp->fullCData(oldp+73,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x00000010U))),4);
    bufp->fullCData(oldp+74,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 0x0000000cU))),4);
    bufp->fullCData(oldp+75,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 8U))),4);
    bufp->fullCData(oldp+76,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw 
                                             >> 4U))),4);
    bufp->fullCData(oldp+77,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg2hw)),4);
    bufp->fullCData(oldp+78,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                             >> 9U))),4);
    bufp->fullBit(oldp+79,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                  >> 8U))));
    bufp->fullCData(oldp+80,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg) 
                                             >> 4U))),4);
    bufp->fullCData(oldp+81,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__hw2reg))),4);
    bufp->fullBit(oldp+82,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__reg_rst_ni));
    bufp->fullBit(oldp+83,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__core_rst_ni));
    bufp->fullBit(oldp+84,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+85,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+86,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+87,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+88,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__intq));
    bufp->fullBit(oldp+89,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+90,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+91,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+92,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+93,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+94,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+95,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+96,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__clk_i));
    bufp->fullBit(oldp+97,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__rst_ni));
    bufp->fullCData(oldp+98,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                             >> 0x0000001aU))),4);
    bufp->fullBit(oldp+99,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                  >> 0x00000019U))));
    bufp->fullCData(oldp+100,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                              >> 0x00000015U))),4);
    bufp->fullBit(oldp+101,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+102,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                              >> 0x00000010U))),4);
    bufp->fullCData(oldp+103,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                              >> 0x0000000cU))),4);
    bufp->fullCData(oldp+104,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                              >> 8U))),4);
    bufp->fullCData(oldp+105,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw 
                                              >> 4U))),4);
    bufp->fullCData(oldp+106,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__reg2hw)),4);
    bufp->fullCData(oldp+107,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                              >> 9U))),4);
    bufp->fullBit(oldp+108,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                   >> 8U))));
    bufp->fullCData(oldp+109,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+110,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__hw2reg))),4);
    bufp->fullCData(oldp+111,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_i),4);
    bufp->fullCData(oldp+112,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_o),4);
    bufp->fullCData(oldp+113,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__cio_gpio_en_o),4);
    bufp->fullCData(oldp+114,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__intr_gpio_o),4);
    bufp->fullCData(oldp+115,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_d),4);
    bufp->fullCData(oldp+116,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__data_in_q),4);
    bufp->fullCData(oldp+117,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_o_q),4);
    bufp->fullCData(oldp+118,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gpio_oe_q),4);
    bufp->fullCData(oldp+119,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_rise),4);
    bufp->fullCData(oldp+120,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_fall),4);
    bufp->fullCData(oldp+121,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_high),4);
    bufp->fullCData(oldp+122,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__event_low),4);
    bufp->fullBit(oldp+123,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__filter_rst_ni));
    bufp->fullBit(oldp+124,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__state_rst_ni));
    bufp->fullBit(oldp+125,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+126,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+127,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+128,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+129,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+130,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+131,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+132,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+133,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+134,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+135,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+136,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+137,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+138,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+139,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+140,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+141,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+142,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+143,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+144,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+145,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+146,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+147,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+148,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+149,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__0__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+150,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+151,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+152,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+153,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+154,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+155,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+156,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+157,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+158,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+159,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+160,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+161,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+162,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+163,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+164,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+165,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+166,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+167,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+168,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+169,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+170,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+171,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+172,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+173,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+174,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__1__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+175,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+176,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+177,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+178,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+179,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+180,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+181,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+182,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+183,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+184,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+185,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+186,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+187,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+188,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+189,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+190,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+191,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+192,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+193,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+194,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+195,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+196,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+197,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+198,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+199,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__2__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+200,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__clk_i));
    bufp->fullBit(oldp+201,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__rst_ni));
    bufp->fullBit(oldp+202,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__enable_i));
    bufp->fullBit(oldp+203,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_i));
    bufp->fullBit(oldp+204,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_o));
    bufp->fullCData(oldp+205,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_q),4);
    bufp->fullCData(oldp+206,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__diff_ctr_d),4);
    bufp->fullBit(oldp+207,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_q));
    bufp->fullBit(oldp+208,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+209,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__update_stored_value));
    bufp->fullBit(oldp+210,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__filter_synced));
    bufp->fullBit(oldp+211,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__clk_i));
    bufp->fullBit(oldp+212,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__rst_ni));
    bufp->fullBit(oldp+213,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_i));
    bufp->fullBit(oldp+214,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__q_o));
    bufp->fullBit(oldp+215,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullBit(oldp+216,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+217,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+218,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+219,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+220,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+221,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+222,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+223,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+224,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__gen_input_filter__BRA__3__KET____DOT__u_filter__DOT__gen_async__DOT__prim_flop_2sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+225,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+226,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+227,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_filter_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+228,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+229,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+230,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_core__DOT__u_state_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+231,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__clk_i));
    bufp->fullBit(oldp+232,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__rst_ni));
    bufp->fullCData(oldp+233,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                      >> 0x00000033U)))),4);
    bufp->fullCData(oldp+234,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                             >> 0x00000030U)))),3);
    bufp->fullBit(oldp+235,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                           >> 0x0000002fU)))));
    bufp->fullIData(oldp+236,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                       >> 0x0000000fU))),32);
    bufp->fullCData(oldp+237,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                      >> 0x0000000bU)))),4);
    bufp->fullBit(oldp+238,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                           >> 0x0000000aU)))));
    bufp->fullBit(oldp+239,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                           >> 9U)))));
    bufp->fullCData(oldp+240,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                                      >> 5U)))),4);
    bufp->fullCData(oldp+241,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                             >> 2U)))),3);
    bufp->fullBit(oldp+242,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+243,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_i))));
    bufp->fullBit(oldp+244,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+245,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                           >> 0x00000027U)))));
    bufp->fullCData(oldp+246,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                             >> 0x00000025U)))),2);
    bufp->fullBit(oldp+247,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+248,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                           >> 0x00000023U)))));
    bufp->fullIData(oldp+249,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                       >> 3U))),32);
    bufp->fullCData(oldp+250,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+251,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__axi_lite_o))));
    bufp->fullCData(oldp+252,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x0000001aU))),4);
    bufp->fullBit(oldp+253,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                   >> 0x00000019U))));
    bufp->fullCData(oldp+254,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x00000015U))),4);
    bufp->fullBit(oldp+255,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+256,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x00000010U))),4);
    bufp->fullCData(oldp+257,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 0x0000000cU))),4);
    bufp->fullCData(oldp+258,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 8U))),4);
    bufp->fullCData(oldp+259,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw 
                                              >> 4U))),4);
    bufp->fullCData(oldp+260,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__reg2hw)),4);
    bufp->fullCData(oldp+261,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                              >> 9U))),4);
    bufp->fullBit(oldp+262,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                   >> 8U))));
    bufp->fullCData(oldp+263,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+264,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__hw2reg))),4);
    bufp->fullBit(oldp+265,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                           >> 0x00000029U)))));
    bufp->fullBit(oldp+266,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                           >> 0x00000028U)))));
    bufp->fullCData(oldp+267,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+268,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req 
                                       >> 4U))),32);
    bufp->fullCData(oldp+269,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_req))),4);
    bufp->fullIData(oldp+270,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                       >> 2U))),32);
    bufp->fullBit(oldp+271,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp 
                                           >> 1U)))));
    bufp->fullBit(oldp+272,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__flexsoc_axi_reg_rsp))));
    bufp->fullBit(oldp+273,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__clk_i));
    bufp->fullBit(oldp+274,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni));
    bufp->fullCData(oldp+275,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 0x00000033U)))),4);
    bufp->fullCData(oldp+276,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                             >> 0x00000030U)))),3);
    bufp->fullBit(oldp+277,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 0x0000002fU)))));
    bufp->fullIData(oldp+278,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                       >> 0x0000000fU))),32);
    bufp->fullCData(oldp+279,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 0x0000000bU)))),4);
    bufp->fullBit(oldp+280,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 0x0000000aU)))));
    bufp->fullBit(oldp+281,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 9U)))));
    bufp->fullCData(oldp+282,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 5U)))),4);
    bufp->fullCData(oldp+283,((7U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                             >> 2U)))),3);
    bufp->fullBit(oldp+284,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+285,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i))));
    bufp->fullBit(oldp+286,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+287,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000027U)))));
    bufp->fullCData(oldp+288,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                             >> 0x00000025U)))),2);
    bufp->fullBit(oldp+289,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+290,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000023U)))));
    bufp->fullIData(oldp+291,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                       >> 3U))),32);
    bufp->fullCData(oldp+292,((3U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+293,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o))));
    bufp->fullBit(oldp+294,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                           >> 0x00000029U)))));
    bufp->fullBit(oldp+295,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                           >> 0x00000028U)))));
    bufp->fullCData(oldp+296,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+297,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                       >> 4U))),32);
    bufp->fullCData(oldp+298,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o))),4);
    bufp->fullIData(oldp+299,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                       >> 2U))),32);
    bufp->fullBit(oldp+300,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+301,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))));
    bufp->fullBit(oldp+302,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full));
    bufp->fullBit(oldp+303,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty));
    bufp->fullCData(oldp+304,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+305,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                       >> 4U))),32);
    bufp->fullCData(oldp+306,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in))),4);
    bufp->fullCData(oldp+307,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+308,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                       >> 4U))),32);
    bufp->fullCData(oldp+309,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out))),4);
    bufp->fullBit(oldp+310,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push));
    bufp->fullBit(oldp+311,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop));
    bufp->fullBit(oldp+312,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full));
    bufp->fullBit(oldp+313,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty));
    bufp->fullBit(oldp+314,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in));
    bufp->fullBit(oldp+315,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out));
    bufp->fullBit(oldp+316,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push));
    bufp->fullBit(oldp+317,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop));
    bufp->fullBit(oldp+318,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full));
    bufp->fullBit(oldp+319,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty));
    bufp->fullCData(oldp+320,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_in),4);
    bufp->fullCData(oldp+321,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out),4);
    bufp->fullBit(oldp+322,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push));
    bufp->fullBit(oldp+323,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop));
    bufp->fullBit(oldp+324,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full));
    bufp->fullBit(oldp+325,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty));
    bufp->fullIData(oldp+326,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                       >> 1U))),32);
    bufp->fullBit(oldp+327,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in))));
    bufp->fullIData(oldp+328,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                       >> 1U))),32);
    bufp->fullBit(oldp+329,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))));
    bufp->fullBit(oldp+330,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push));
    bufp->fullBit(oldp+331,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop));
    bufp->fullCData(oldp+332,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+333,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req))));
    bufp->fullCData(oldp+334,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+335,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req))));
    bufp->fullCData(oldp+336,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+337,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req))));
    bufp->fullBit(oldp+338,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid));
    bufp->fullBit(oldp+339,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    bufp->fullBit(oldp+340,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready));
    bufp->fullBit(oldp+341,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready));
    bufp->fullBit(oldp+342,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__clk_i));
    bufp->fullBit(oldp+343,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni));
    bufp->fullBit(oldp+344,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o));
    bufp->fullBit(oldp+345,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o));
    bufp->fullBit(oldp+346,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o));
    bufp->fullCData(oldp+347,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_i),4);
    bufp->fullBit(oldp+348,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i));
    bufp->fullCData(oldp+349,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o),4);
    bufp->fullBit(oldp+350,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i));
    bufp->fullBit(oldp+351,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock));
    bufp->fullBit(oldp+352,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n));
    bufp->fullBit(oldp+353,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q));
    bufp->fullBit(oldp+354,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n));
    bufp->fullBit(oldp+355,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q));
    bufp->fullCData(oldp+356,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+357,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+358,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+359,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n))),4);
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 360, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q);
    bufp->fullBit(oldp+362,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__clk_i));
    bufp->fullBit(oldp+363,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni));
    bufp->fullBit(oldp+364,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o));
    bufp->fullBit(oldp+365,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o));
    bufp->fullBit(oldp+366,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o));
    bufp->fullIData(oldp+367,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                       >> 1U))),32);
    bufp->fullBit(oldp+368,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i))));
    bufp->fullBit(oldp+369,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i));
    bufp->fullIData(oldp+370,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                       >> 1U))),32);
    bufp->fullBit(oldp+371,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o))));
    bufp->fullBit(oldp+372,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i));
    bufp->fullBit(oldp+373,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock));
    bufp->fullBit(oldp+374,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n));
    bufp->fullBit(oldp+375,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q));
    bufp->fullBit(oldp+376,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n));
    bufp->fullBit(oldp+377,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q));
    bufp->fullCData(oldp+378,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+379,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q),2);
    bufp->fullIData(oldp+380,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                                << 0x0000001eU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                                   >> 2U))),32);
    bufp->fullBit(oldp+381,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                   >> 1U))));
    bufp->fullIData(oldp+382,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                << 0x0000001fU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                                   >> 1U))),32);
    bufp->fullBit(oldp+383,((1U & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U])));
    Vtop___024root__trace_full_dtype____1(vlSelf, bufp, 384, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q);
    bufp->fullBit(oldp+388,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__clk_i));
    bufp->fullBit(oldp+389,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni));
    bufp->fullBit(oldp+390,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o));
    bufp->fullBit(oldp+391,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o));
    bufp->fullBit(oldp+392,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o));
    bufp->fullCData(oldp+393,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+394,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                       >> 4U))),32);
    bufp->fullCData(oldp+395,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i))),4);
    bufp->fullBit(oldp+396,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i));
    bufp->fullCData(oldp+397,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+398,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                       >> 4U))),32);
    bufp->fullCData(oldp+399,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o))),4);
    bufp->fullBit(oldp+400,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i));
    bufp->fullBit(oldp+401,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock));
    bufp->fullBit(oldp+402,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n));
    bufp->fullBit(oldp+403,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q));
    bufp->fullBit(oldp+404,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n));
    bufp->fullBit(oldp+405,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q));
    bufp->fullCData(oldp+406,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+407,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+408,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                              >> 0x0000000cU))),4);
    bufp->fullIData(oldp+409,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                << 0x00000014U) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                                   >> 0x0000000cU))),32);
    bufp->fullCData(oldp+410,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                              >> 8U))),4);
    bufp->fullCData(oldp+411,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                              >> 4U))),4);
    bufp->fullIData(oldp+412,(((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                << 0x0000001cU) | (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                                   >> 4U))),32);
    bufp->fullCData(oldp+413,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U])),4);
    Vtop___024root__trace_full_dtype____2(vlSelf, bufp, 414, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q);
    bufp->fullBit(oldp+420,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__clk_i));
    bufp->fullBit(oldp+421,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni));
    bufp->fullBit(oldp+422,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o));
    bufp->fullBit(oldp+423,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o));
    bufp->fullBit(oldp+424,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o));
    bufp->fullBit(oldp+425,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i));
    bufp->fullBit(oldp+426,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i));
    bufp->fullBit(oldp+427,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o));
    bufp->fullBit(oldp+428,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i));
    bufp->fullBit(oldp+429,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock));
    bufp->fullBit(oldp+430,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n));
    bufp->fullBit(oldp+431,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q));
    bufp->fullBit(oldp+432,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n));
    bufp->fullBit(oldp+433,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q));
    bufp->fullCData(oldp+434,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+435,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+436,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n),2);
    bufp->fullCData(oldp+437,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q),2);
    bufp->fullBit(oldp+438,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__clk_i));
    bufp->fullBit(oldp+439,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni));
    bufp->fullCData(oldp+440,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                              >> 6U))),4);
    bufp->fullBit(oldp+441,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                   >> 5U))));
    bufp->fullCData(oldp+442,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+443,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i))));
    bufp->fullCData(oldp+444,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i),2);
    bufp->fullCData(oldp+445,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o),2);
    bufp->fullCData(oldp+446,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+447,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o))));
    bufp->fullBit(oldp+448,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o));
    bufp->fullBit(oldp+449,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i));
    bufp->fullBit(oldp+450,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__clk_i));
    bufp->fullBit(oldp+451,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni));
    bufp->fullCData(oldp+452,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                              >> 6U))),4);
    bufp->fullBit(oldp+453,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                   >> 5U))));
    bufp->fullCData(oldp+454,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+455,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i))));
    bufp->fullCData(oldp+456,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i),2);
    bufp->fullCData(oldp+457,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o),2);
    bufp->fullCData(oldp+458,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+459,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o))));
    bufp->fullBit(oldp+460,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o));
    bufp->fullBit(oldp+461,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i));
    bufp->fullBit(oldp+462,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__clk_i));
    bufp->fullBit(oldp+463,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni));
    bufp->fullCData(oldp+464,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i),2);
    bufp->fullCData(oldp+465,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o),2);
    bufp->fullCData(oldp+466,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                              >> 6U))),4);
    bufp->fullBit(oldp+467,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                   >> 5U))));
    bufp->fullCData(oldp+468,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+469,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i))));
    bufp->fullBit(oldp+470,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o));
    bufp->fullBit(oldp+471,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i));
    bufp->fullCData(oldp+472,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+473,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o))));
    bufp->fullBit(oldp+474,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o));
    bufp->fullBit(oldp+475,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes));
    bufp->fullCData(oldp+476,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                              >> 1U))),4);
    bufp->fullBit(oldp+477,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes))));
    bufp->fullBit(oldp+478,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes));
    bufp->fullBit(oldp+479,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes));
    bufp->fullBit(oldp+480,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q));
    bufp->fullCData(oldp+481,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d),2);
    bufp->fullBit(oldp+482,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d));
    bufp->fullCData(oldp+483,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),2);
    bufp->fullCData(oldp+484,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),2);
    bufp->fullBit(oldp+485,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx));
    bufp->fullBit(oldp+486,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx));
    bufp->fullBit(oldp+487,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx));
    bufp->fullBit(oldp+488,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty));
    bufp->fullBit(oldp+489,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_empty));
    bufp->fullCData(oldp+490,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i),2);
    bufp->fullBit(oldp+491,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o));
    bufp->fullBit(oldp+492,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o));
    Vtop___024root__trace_full_dtype____3(vlSelf, bufp, 493, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut);
    bufp->fullCData(oldp+495,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->fullBit(oldp+496,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                   >> 1U))));
    bufp->fullBit(oldp+497,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
    bufp->fullCData(oldp+498,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->fullCData(oldp+499,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i),2);
    bufp->fullBit(oldp+500,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o));
    bufp->fullBit(oldp+501,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o));
    Vtop___024root__trace_full_dtype____3(vlSelf, bufp, 502, vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut);
    bufp->fullCData(oldp+504,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->fullBit(oldp+505,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                   >> 1U))));
    bufp->fullBit(oldp+506,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
    bufp->fullCData(oldp+507,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->fullBit(oldp+508,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d));
    bufp->fullBit(oldp+509,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
    bufp->fullCData(oldp+510,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),2);
    bufp->fullBit(oldp+511,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
    bufp->fullBit(oldp+512,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->fullBit(oldp+513,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->fullBit(oldp+514,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x00000029U)))));
    bufp->fullBit(oldp+515,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x00000028U)))));
    bufp->fullCData(oldp+516,((0x0000000fU & (IData)(
                                                     (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                      >> 0x00000024U)))),4);
    bufp->fullIData(oldp+517,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i 
                                       >> 4U))),32);
    bufp->fullCData(oldp+518,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->fullIData(oldp+519,((IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                       >> 2U))),32);
    bufp->fullBit(oldp+520,((1U & (IData)((vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 1U)))));
    bufp->fullBit(oldp+521,((1U & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->fullCData(oldp+522,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x0000001aU))),4);
    bufp->fullBit(oldp+523,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                   >> 0x00000019U))));
    bufp->fullCData(oldp+524,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x00000015U))),4);
    bufp->fullBit(oldp+525,((1U & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                   >> 0x00000014U))));
    bufp->fullCData(oldp+526,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x00000010U))),4);
    bufp->fullCData(oldp+527,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 0x0000000cU))),4);
    bufp->fullCData(oldp+528,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 8U))),4);
    bufp->fullCData(oldp+529,((0x0000000fU & (vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw 
                                              >> 4U))),4);
    bufp->fullCData(oldp+530,((0x0000000fU & vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg2hw)),4);
    bufp->fullCData(oldp+531,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                              >> 9U))),4);
    bufp->fullBit(oldp+532,((1U & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                   >> 8U))));
    bufp->fullCData(oldp+533,((0x0000000fU & ((IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg) 
                                              >> 4U))),4);
    bufp->fullCData(oldp+534,((0x0000000fU & (IData)(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__hw2reg))),4);
    bufp->fullBit(oldp+535,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->fullBit(oldp+536,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->fullBit(oldp+537,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->fullCData(oldp+538,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_addr),4);
    bufp->fullIData(oldp+539,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->fullCData(oldp+540,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->fullIData(oldp+541,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->fullBit(oldp+542,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->fullBit(oldp+543,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->fullBit(oldp+544,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->fullIData(oldp+545,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+546,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->fullCData(oldp+547,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__reg_we_check),3);
    bufp->fullBit(oldp+548,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__err_q));
    bufp->fullCData(oldp+549,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__data_in_qs),4);
    bufp->fullBit(oldp+550,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_re));
    bufp->fullBit(oldp+551,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_we));
    bufp->fullCData(oldp+552,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_qs),4);
    bufp->fullCData(oldp+553,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_o_wd),4);
    bufp->fullCData(oldp+554,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_qs),4);
    bufp->fullCData(oldp+555,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_gpio_oe_wd),4);
    bufp->fullBit(oldp+556,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_we));
    bufp->fullCData(oldp+557,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_qs),4);
    bufp->fullCData(oldp+558,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_rising_wd),4);
    bufp->fullCData(oldp+559,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_qs),4);
    bufp->fullCData(oldp+560,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_falling_wd),4);
    bufp->fullCData(oldp+561,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_qs),4);
    bufp->fullCData(oldp+562,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvlhigh_wd),4);
    bufp->fullCData(oldp+563,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_qs),4);
    bufp->fullCData(oldp+564,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_lvllow_wd),4);
    bufp->fullCData(oldp+565,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_qs),4);
    bufp->fullCData(oldp+566,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__intr_ctrl_en_input_filter_wd),4);
    bufp->fullBit(oldp+567,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_qe));
    bufp->fullCData(oldp+568,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__direct_flds_we),2);
    bufp->fullCData(oldp+569,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__addr_hit),3);
    bufp->fullBit(oldp+570,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->fullBit(oldp+571,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->fullBit(oldp+572,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__clk_i));
    bufp->fullBit(oldp+573,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__rst_ni));
    bufp->fullBit(oldp+574,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__de));
    bufp->fullCData(oldp+575,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__d),4);
    bufp->fullBit(oldp+576,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qe));
    bufp->fullCData(oldp+577,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__q),4);
    bufp->fullCData(oldp+578,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__ds),4);
    bufp->fullCData(oldp+579,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__qs),4);
    bufp->fullBit(oldp+580,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en));
    bufp->fullCData(oldp+581,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_data),4);
    bufp->fullBit(oldp+582,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__de));
    bufp->fullCData(oldp+583,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__d),4);
    bufp->fullCData(oldp+584,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+585,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+586,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+587,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_data_in__DOT__wr_en_data_arb__DOT__gen_ro__DOT__unused_q),4);
    bufp->fullBit(oldp+588,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__re));
    bufp->fullBit(oldp+589,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__we));
    bufp->fullCData(oldp+590,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__wd),4);
    bufp->fullCData(oldp+591,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__d),4);
    bufp->fullBit(oldp+592,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qe));
    bufp->fullBit(oldp+593,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qre));
    bufp->fullCData(oldp+594,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__q),4);
    bufp->fullCData(oldp+595,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__ds),4);
    bufp->fullCData(oldp+596,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_o__DOT__qs),4);
    bufp->fullBit(oldp+597,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__re));
    bufp->fullBit(oldp+598,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__we));
    bufp->fullCData(oldp+599,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__wd),4);
    bufp->fullCData(oldp+600,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__d),4);
    bufp->fullBit(oldp+601,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qe));
    bufp->fullBit(oldp+602,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qre));
    bufp->fullCData(oldp+603,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__q),4);
    bufp->fullCData(oldp+604,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__ds),4);
    bufp->fullCData(oldp+605,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_direct_gpio_oe__DOT__qs),4);
    bufp->fullBit(oldp+606,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__clk_i));
    bufp->fullBit(oldp+607,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__rst_ni));
    bufp->fullBit(oldp+608,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__we));
    bufp->fullCData(oldp+609,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wd),4);
    bufp->fullBit(oldp+610,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qe));
    bufp->fullCData(oldp+611,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__q),4);
    bufp->fullCData(oldp+612,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__ds),4);
    bufp->fullCData(oldp+613,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__qs),4);
    bufp->fullBit(oldp+614,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en));
    bufp->fullCData(oldp+615,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_data),4);
    bufp->fullBit(oldp+616,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+617,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+618,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+619,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+620,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+621,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_falling__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+622,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__clk_i));
    bufp->fullBit(oldp+623,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__rst_ni));
    bufp->fullBit(oldp+624,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__we));
    bufp->fullCData(oldp+625,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wd),4);
    bufp->fullBit(oldp+626,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qe));
    bufp->fullCData(oldp+627,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__q),4);
    bufp->fullCData(oldp+628,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__ds),4);
    bufp->fullCData(oldp+629,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__qs),4);
    bufp->fullBit(oldp+630,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en));
    bufp->fullCData(oldp+631,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_data),4);
    bufp->fullBit(oldp+632,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+633,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+634,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+635,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+636,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+637,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_input_filter__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+638,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__clk_i));
    bufp->fullBit(oldp+639,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__rst_ni));
    bufp->fullBit(oldp+640,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__we));
    bufp->fullCData(oldp+641,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wd),4);
    bufp->fullBit(oldp+642,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qe));
    bufp->fullCData(oldp+643,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__q),4);
    bufp->fullCData(oldp+644,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__ds),4);
    bufp->fullCData(oldp+645,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__qs),4);
    bufp->fullBit(oldp+646,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en));
    bufp->fullCData(oldp+647,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_data),4);
    bufp->fullBit(oldp+648,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+649,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+650,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+651,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+652,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+653,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvlhigh__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+654,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__clk_i));
    bufp->fullBit(oldp+655,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__rst_ni));
    bufp->fullBit(oldp+656,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__we));
    bufp->fullCData(oldp+657,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wd),4);
    bufp->fullBit(oldp+658,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qe));
    bufp->fullCData(oldp+659,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__q),4);
    bufp->fullCData(oldp+660,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__ds),4);
    bufp->fullCData(oldp+661,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__qs),4);
    bufp->fullBit(oldp+662,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en));
    bufp->fullCData(oldp+663,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_data),4);
    bufp->fullBit(oldp+664,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+665,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+666,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+667,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+668,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+669,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_lvllow__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+670,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__clk_i));
    bufp->fullBit(oldp+671,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__rst_ni));
    bufp->fullBit(oldp+672,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__we));
    bufp->fullCData(oldp+673,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wd),4);
    bufp->fullBit(oldp+674,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qe));
    bufp->fullCData(oldp+675,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__q),4);
    bufp->fullCData(oldp+676,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__ds),4);
    bufp->fullCData(oldp+677,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__qs),4);
    bufp->fullBit(oldp+678,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en));
    bufp->fullCData(oldp+679,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_data),4);
    bufp->fullBit(oldp+680,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+681,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wd),4);
    bufp->fullCData(oldp+682,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__q),4);
    bufp->fullBit(oldp+683,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+684,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__wr_data),4);
    bufp->fullCData(oldp+685,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_intr_ctrl_en_rising__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),4);
    bufp->fullBit(oldp+686,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->fullBit(oldp+687,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->fullCData(oldp+688,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),3);
    bufp->fullBit(oldp+689,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->fullBit(oldp+690,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->fullCData(oldp+691,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),3);
    bufp->fullCData(oldp+692,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),3);
    bufp->fullCData(oldp+693,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),3);
    bufp->fullCData(oldp+694,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),3);
    bufp->fullBit(oldp+695,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->fullBit(oldp+696,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->fullCData(oldp+697,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),3);
    bufp->fullBit(oldp+698,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->fullBit(oldp+699,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->fullCData(oldp+700,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),7);
    bufp->fullCData(oldp+701,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),7);
    bufp->fullCData(oldp+702,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_gpio_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),7);
    bufp->fullBit(oldp+703,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+704,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+705,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+706,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+707,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__intq));
    bufp->fullBit(oldp+708,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+709,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+710,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+711,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+712,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+713,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+714,(vlSelfRef.gpio_tb__DOT__u_gpio__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    Vtop___024root__trace_full_dtype____4(vlSelf, bufp, 715, vlSymsp->TOP__gpio_reg_pkg.GPIO_PERMIT);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*7:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x0000000fU & (__VdtypeVar 
                                            >> 4U))),4);
    bufp->fullCData(oldp+1,((0x0000000fU & __VdtypeVar)),4);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(VL_SEL_IWII(66, __VdtypeVar, 0x00000022U, 32)),32);
    bufp->fullBit(oldp+1,((1U & VL_BITSEL_IWII(66, 
                                               __VdtypeVar, 0x00000021U))));
    bufp->fullIData(oldp+2,(VL_SEL_IWII(66, __VdtypeVar, 1U, 32)),32);
    bufp->fullBit(oldp+3,((1U & VL_BITSEL_IWII(66, 
                                               __VdtypeVar, 0U))));
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*79:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x0000000fU & VL_SEL_IWII(80, 
                                                       __VdtypeVar, 0x0000004cU, 4))),4);
    bufp->fullIData(oldp+1,(VL_SEL_IWII(80, __VdtypeVar, 0x0000002cU, 32)),32);
    bufp->fullCData(oldp+2,((0x0000000fU & VL_SEL_IWII(80, 
                                                       __VdtypeVar, 0x00000028U, 4))),4);
    bufp->fullCData(oldp+3,((0x0000000fU & VL_SEL_IWII(80, 
                                                       __VdtypeVar, 0x00000024U, 4))),4);
    bufp->fullIData(oldp+4,(VL_SEL_IWII(80, __VdtypeVar, 4U, 32)),32);
    bufp->fullCData(oldp+5,((0x0000000fU & VL_SEL_IWII(80, 
                                                       __VdtypeVar, 0U, 4))),4);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullBit(oldp+0,((1U & (__VdtypeVar >> 1U))));
    bufp->fullBit(oldp+1,((1U & __VdtypeVar)));
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 3>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[0]),4);
    bufp->fullCData(oldp+1,(__VdtypeVar[1]),4);
    bufp->fullCData(oldp+2,(__VdtypeVar[2]),4);
}
