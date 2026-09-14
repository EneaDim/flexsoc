// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__axi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__uart_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____8(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____9(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____18(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____21(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____24(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____31(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "axi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__axi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "uart_reg_pkg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__uart_reg_pkg__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "uart_tb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"rx_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"tx_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"aw_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+9,0,"w_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+10,0,"b_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+11,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+12,0,"prot",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+13,0,"ar_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+14,0,"r_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+15,0,"aw_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+16,0,"w_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+18,0,"b_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+19,0,"ar_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+20,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"resp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+22,0,"r_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+23,0,"axi_aw_addr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"axi_aw_prot_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+25,0,"axi_aw_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+26,0,"axi_aw_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+27,0,"axi_w_data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+28,0,"axi_w_strb_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+29,0,"axi_w_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+30,0,"axi_w_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+31,0,"axi_b_resp_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+32,0,"axi_b_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+33,0,"axi_b_ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+34,0,"axi_ar_addr_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+35,0,"axi_ar_prot_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"axi_ar_valid_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"axi_ar_ready_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"axi_r_data_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"axi_r_resp_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+40,0,"axi_r_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+41,0,"axi_r_ready_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_uart", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+42,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+43,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"rx_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"tx_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+48,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+51,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+52,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+55,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+56,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+58,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+59,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+60,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+61,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "nco", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+65,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_odd", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+66,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_en", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+67,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "llpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+68,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "slpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+69,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "nf", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+70,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+77,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+78,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+79,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+80,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+81,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+82,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+83,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+84,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+85,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+86,0,"re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "wdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+87,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+88,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "txrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+89,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+90,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+91,0,"q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+92,0,"qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+93,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+95,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+96,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+97,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+98,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+99,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_status", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+100,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+102,0,"reg_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+103,0,"core_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_core_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+104,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+105,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+107,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+108,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+109,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+110,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+111,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+112,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+113,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+114,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+115,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_reset_sync", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+116,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+117,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+119,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+120,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+121,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+122,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+123,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+124,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+125,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+127,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_uart_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+128,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+129,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "nco", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+130,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_odd", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+131,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_en", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+132,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "llpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+133,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "slpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+134,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "nf", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+135,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+136,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+137,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+138,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+139,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+140,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+141,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+142,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+143,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+144,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+145,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+146,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+147,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+148,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+149,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+150,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+151,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "wdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+152,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+153,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "txrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+154,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+155,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+156,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+157,0,"qe",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+158,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+159,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+160,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+161,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+162,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+163,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+164,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_status", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+165,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+166,0,"d",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+167,0,"rx_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+168,0,"tx_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"NcoWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"TxFifoDepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"RxFifoDepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+169,0,"rx_val_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+170,0,"uart_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+171,0,"tick_baud_x16",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+172,0,"rx_tick_baud",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+173,0,"tx_fifo_depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+174,0,"rx_fifo_depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+175,0,"rx_fifo_depth_prev_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+176,0,"rx_timeout_count_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BUS(tracep,c+177,0,"rx_timeout_count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BUS(tracep,c+178,0,"uart_rxto_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 23,0);
    VL_TRACE_DECL_BIT(tracep,c+179,0,"rx_fifo_depth_changed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+180,0,"uart_rxto_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+181,0,"tx_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1057,0,"rx_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+182,0,"sys_loopback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+183,0,"line_loopback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+184,0,"rxnf_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+185,0,"uart_fifo_rxrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+186,0,"uart_fifo_txrst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+187,0,"tx_fifo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+188,0,"tx_fifo_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+189,0,"tx_fifo_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+190,0,"tx_fifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+191,0,"tx_uart_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+192,0,"tx_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+193,0,"tx_out_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+194,0,"rx_fifo_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+195,0,"rx_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+196,0,"rx_fifo_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+197,0,"rx_fifo_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+198,0,"rx_fifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+199,0,"rx_uart_idle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+200,0,"rx_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+201,0,"rx_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+202,0,"break_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+203,0,"allzero_cnt_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+204,0,"allzero_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+205,0,"allzero_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+206,0,"not_allzero_char",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+207,0,"event_tx_watermark",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+208,0,"event_tx_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+209,0,"event_rx_watermark",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+210,0,"event_tx_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+211,0,"event_rx_overflow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+212,0,"event_rx_frame_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+213,0,"event_rx_break_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+214,0,"event_rx_timeout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+215,0,"event_rx_parity_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+216,0,"tx_uart_idle_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+217,0,"timing_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+218,0,"tx_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+219,0,"rx_rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+220,0,"rx_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+221,0,"tx_fifo_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+222,0,"tx_fifo_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+223,0,"nco_sum_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 16,0);
    VL_TRACE_DECL_BIT(tracep,c+224,0,"rx_sync_q1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+225,0,"rx_sync_q2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+226,0,"rx_in_mx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+227,0,"rx_in_maj",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "sync_rx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+228,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+229,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+230,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+231,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+232,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+233,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1057,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+234,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+235,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+236,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+237,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+238,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+239,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+240,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+241,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rx_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+242,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+243,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+244,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_timing_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+245,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+246,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+247,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_tx_reset_branch", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+248,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+249,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+250,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_uart_rxfifo", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1061,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+251,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+252,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+253,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+254,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+255,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+256,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+257,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+258,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+259,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+260,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+261,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+262,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+263,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+264,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+265,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+266,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+267,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+268,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);

    Vtop___024root__trace_init_dtype____8(vlSelf, tracep, "storage", 0, c+269, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+285,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+286,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1061,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1064,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+287,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+288,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+289,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+290,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+291,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+292,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+293,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+294,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+295,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+296,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1064,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+297,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+298,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+299,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+300,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+301,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+302,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+303,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+304,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_uart_txfifo", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+305,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+306,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+307,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+308,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+309,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+310,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+311,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+312,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+313,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+314,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+315,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1065,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+316,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+317,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+318,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+319,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+320,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+321,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+322,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);

    Vtop___024root__trace_init_dtype____9(vlSelf, tracep, "storage", 0, c+323, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+331,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+332,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1065,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+333,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+334,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+335,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+336,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+337,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+338,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+339,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+340,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+341,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+342,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+343,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+344,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+345,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+346,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+347,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+348,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+349,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+350,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "uart_rx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+351,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+352,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1057,0,"rx_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+353,0,"tick_baud_x16",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+354,0,"parity_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+355,0,"parity_odd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+356,0,"tick_baud",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+357,0,"rx_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+358,0,"rx_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+359,0,"idle",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+360,0,"frame_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+361,0,"rx_parity_err",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+362,0,"rx",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+363,0,"rx_valid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+364,0,"sreg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 10,0);
    VL_TRACE_DECL_BUS(tracep,c+365,0,"sreg_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 10,0);
    VL_TRACE_DECL_BUS(tracep,c+366,0,"bit_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+367,0,"bit_cnt_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+368,0,"baud_div_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+369,0,"baud_div_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+370,0,"tick_baud_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+371,0,"tick_baud_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+372,0,"idle_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+373,0,"idle_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "uart_tx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+374,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+375,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+376,0,"tx_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+377,0,"tick_baud_x16",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+378,0,"parity_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+379,0,"wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+380,0,"wr_parity",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+381,0,"wr_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+382,0,"idle",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+383,0,"tx",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+384,0,"baud_div_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+385,0,"tick_baud_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+386,0,"bit_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+387,0,"bit_cnt_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+388,0,"sreg_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 10,0);
    VL_TRACE_DECL_BUS(tracep,c+389,0,"sreg_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 10,0);
    VL_TRACE_DECL_BIT(tracep,c+390,0,"tx_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+391,0,"tx_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_uart_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+392,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+393,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+394,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+395,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+396,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+397,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+398,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+399,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+400,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+401,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+402,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+403,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+404,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+405,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+406,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+407,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+408,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+409,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+410,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+411,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+412,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "nco", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+413,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_odd", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+414,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_en", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+415,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "llpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+416,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "slpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+417,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "nf", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+418,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+419,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+420,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+421,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+422,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+423,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+424,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+425,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+426,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+427,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+428,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+429,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+430,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+431,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+432,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+433,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+434,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "wdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+435,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+436,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "txrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+437,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+438,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+439,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+440,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+441,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+442,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+443,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+444,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+445,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+446,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+447,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_status", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+448,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+449,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+1057,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_axi_reg_req", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+450,0,"valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+451,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+452,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+453,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+454,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "flexsoc_axi_reg_rsp", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+455,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+456,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+457,0,"ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_flexsoc_axi_to_reg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1066,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1067,0,"BUFFER_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"DECOUPLE_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+458,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+459,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_req_i", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "aw", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+460,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+461,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+462,0,"aw_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "w", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+463,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+464,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+465,0,"w_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+466,0,"b_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "ar", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+467,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+468,0,"prot",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+469,0,"ar_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+470,0,"r_ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "axi_lite_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED, 7, 0);
    VL_TRACE_DECL_BIT(tracep,c+471,0,"aw_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+472,0,"w_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "b", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+473,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+474,0,"b_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+475,0,"ar_ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "r", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+476,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+477,0,"resp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+478,0,"r_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_req_o", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+479,0,"valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+480,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+481,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+482,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+483,0,"wstrb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_rsp_i", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+484,0,"rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+485,0,"error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+486,0,"ready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+487,0,"write_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+488,0,"write_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "write_fifo_in", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+489,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+490,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+491,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "write_fifo_out", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+492,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+493,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+494,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+495,0,"write_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+496,0,"write_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+497,0,"write_resp_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+498,0,"write_resp_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+499,0,"write_resp_fifo_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+500,0,"write_resp_fifo_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+501,0,"write_resp_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+502,0,"write_resp_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+503,0,"read_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+504,0,"read_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+505,0,"read_fifo_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+506,0,"read_fifo_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+507,0,"read_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+508,0,"read_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+509,0,"read_resp_fifo_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+510,0,"read_resp_fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "read_resp_fifo_in", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+511,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+512,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "read_resp_fifo_out", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+513,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+514,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+515,0,"read_resp_fifo_push",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+516,0,"read_resp_fifo_pop",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "read_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+517,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+518,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "write_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+519,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+520,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "arb_req", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+521,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+522,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+523,0,"read_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+524,0,"write_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+525,0,"read_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+526,0,"write_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_read", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1064,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+527,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+528,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+529,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+530,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+531,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+532,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+533,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+534,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+535,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+536,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+537,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+538,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+539,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+540,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+541,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+542,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+543,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+544,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____18(vlSelf, tracep, "mem_q", 0, c+545, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_read_resp", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1070,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+547,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+548,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+549,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+550,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+551,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+552,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+553,0,"error",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+554,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+555,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+556,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+557,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+558,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+559,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+560,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+561,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+562,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+563,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+564,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+565,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+566,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+567,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+568,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____21(vlSelf, tracep, "mem_q", 0, c+569, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_write_req", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1070,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+573,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+574,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+575,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+576,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+577,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+578,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+579,0,"data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+580,0,"strb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+581,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+582,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+583,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+584,0,"strb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+585,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+586,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+587,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+588,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+589,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+590,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+591,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+592,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "mem_n", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+593,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+594,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+595,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+596,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+597,0,"data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+598,0,"strb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____24(vlSelf, tracep, "mem_q", 0, c+599, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_fifo_write_resp", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"FALL_THROUGH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1070,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"ADDR_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+605,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+606,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"testmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+607,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+608,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+609,0,"usage_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+610,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+611,0,"push_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+612,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+613,0,"pop_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"FifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+614,0,"gate_clock",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+615,0,"read_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+616,0,"read_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+617,0,"write_pointer_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+618,0,"write_pointer_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+619,0,"status_cnt_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+620,0,"status_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+621,0,"mem_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+622,0,"mem_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_stream_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1071,0,"N_INP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1072,0,"ARBITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+623,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+624,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "inp_data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+625,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+626,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+627,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+628,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+629,0,"inp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+630,0,"inp_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "oup_data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+631,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+632,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+633,0,"oup_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+634,0,"oup_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1071,0,"N_INP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1072,0,"ARBITER",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+635,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+636,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "inp_data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+637,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+638,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+639,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+640,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+641,0,"inp_valid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+642,0,"inp_ready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "oup_data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+643,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+644,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+645,0,"oup_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+646,0,"oup_ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_rr_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "i_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"NumIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1070,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"ExtPrio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"AxiVldRdy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"LockIn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"FairArb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"IdxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+647,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+648,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"flush_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1073,0,"rr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+649,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+650,0,"gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "data_i", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+651,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+652,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+653,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+654,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+655,0,"req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+656,0,"gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "data_o", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+657,0,"addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+658,0,"write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+659,0,"idx_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_arbiter", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+660,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "data_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+661,0,"addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BIT(tracep,c+662,0,"write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+663,0,"gnt_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+664,0,"req_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+665,0,"rr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+666,0,"req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_int_rr", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+667,0,"rr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_fair_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+668,0,"upper_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+669,0,"lower_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+670,0,"upper_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+671,0,"lower_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+672,0,"next_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+673,0,"upper_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+674,0,"lower_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "i_lzc_lower", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"CNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+675,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+676,0,"cnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+677,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lzc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vtop___024root__trace_init_dtype____31(vlSelf, tracep, "index_lut", 0, c+678, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+680,0,"sel_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+681,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+682,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+683,0,"in_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "i_lzc_upper", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"MODE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"CNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+684,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+685,0,"cnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+686,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lzc", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);

    Vtop___024root__trace_init_dtype____31(vlSelf, tracep, "index_lut", 0, c+687, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+689,0,"sel_nodes",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_PUSH_PREFIX(tracep, "index_nodes", VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+690,0,"[1]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+691,0,"[0]",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+692,0,"in_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_lock", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+693,0,"lock_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+694,0,"lock_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+695,0,"req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_levels[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+696,0,"sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1074,0,"Idx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"Idx1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_reg_core", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+697,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+698,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_req_i", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_DECL_BIT(tracep,c+699,0,"valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+700,0,"write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+701,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+702,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+703,0,"wstrb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg_rsp_o", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+704,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+705,0,"error",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+706,0,"ready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "reg2hw", VerilatedTracePrefixType::STRUCT_PACKED, 5, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 8, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "nco", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+707,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_odd", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+708,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "parity_en", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+709,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "llpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+710,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "slpbk", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+711,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "nf", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+712,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+713,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "tx", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+714,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+715,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+716,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+717,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+718,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+719,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+720,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+721,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+722,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+723,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+724,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+725,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+726,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+727,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+728,0,"re",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "wdata", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BUS(tracep,c+729,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+730,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_ctrl", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "txrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+731,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+732,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxrst", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_DECL_BIT(tracep,c+733,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+734,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "hw2reg", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "status", VerilatedTracePrefixType::STRUCT_PACKED, 6, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+735,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+736,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txidle", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+737,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txempty", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+738,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rxfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+739,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txfull", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BIT(tracep,c+740,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "rdata", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+741,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "fifo_status", VerilatedTracePrefixType::STRUCT_PACKED, 2, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "rxlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+742,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "txlvl", VerilatedTracePrefixType::STRUCT_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+743,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+1057,0,"devmode_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+744,0,"intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1066,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+745,0,"reg_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+746,0,"reg_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+747,0,"reg_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+748,0,"reg_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+749,0,"reg_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+750,0,"reg_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+751,0,"reg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+752,0,"addrmiss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+753,0,"wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+754,0,"reg_rdata_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"reg_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+755,0,"reg_we_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+756,0,"reg_we_check",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+757,0,"err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+758,0,"ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+759,0,"ctrl_tx_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+760,0,"ctrl_tx_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+761,0,"ctrl_rx_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+762,0,"ctrl_rx_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+763,0,"ctrl_nf_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+764,0,"ctrl_nf_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+765,0,"ctrl_slpbk_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+766,0,"ctrl_slpbk_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+767,0,"ctrl_llpbk_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+768,0,"ctrl_llpbk_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+769,0,"ctrl_parity_en_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+770,0,"ctrl_parity_en_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+771,0,"ctrl_parity_odd_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+772,0,"ctrl_parity_odd_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+773,0,"ctrl_nco_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+774,0,"ctrl_nco_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+775,0,"status_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+776,0,"status_txfull_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+777,0,"status_rxfull_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+778,0,"status_txempty_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+779,0,"status_txidle_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+780,0,"status_rxidle_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+781,0,"status_rxempty_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+782,0,"rdata_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+783,0,"rdata_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+784,0,"wdata_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+785,0,"wdata_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+786,0,"fifo_ctrl_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+787,0,"fifo_ctrl_rxrst_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+788,0,"fifo_ctrl_txrst_wd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+789,0,"fifo_status_re",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+790,0,"fifo_status_txlvl_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+791,0,"fifo_status_rxlvl_qs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+792,0,"wdata_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+793,0,"wdata_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+794,0,"fifo_ctrl_qe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+795,0,"fifo_ctrl_flds_we",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+796,0,"addr_hit",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"shadow_busy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+797,0,"unused_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+798,0,"unused_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_llpbk", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+799,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+800,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+801,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+802,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+803,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+804,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+805,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+806,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+807,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+808,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+809,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+810,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+811,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+812,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+813,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+814,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_nco", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1076,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+815,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+816,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+817,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+818,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1077,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+819,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+820,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+821,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+822,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+823,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+824,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+825,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+826,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1077,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BUS(tracep,c+827,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+828,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+829,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+830,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_nf", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+831,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+832,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+833,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+834,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+835,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+836,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+837,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+838,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+839,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+840,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+841,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+842,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+843,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+844,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+845,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+846,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_parity_en", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+847,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+848,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+849,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+850,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+851,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+852,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+853,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+854,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+855,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+856,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+857,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+858,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+859,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+860,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+861,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+862,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_parity_odd", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+863,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+864,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+865,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+866,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+867,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+868,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+869,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+870,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+871,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+872,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+873,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+874,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+875,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+876,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+877,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+878,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_rx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+879,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+880,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+881,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+882,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+883,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+884,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+885,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+886,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+887,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+888,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+889,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+890,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+891,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+892,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+893,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+894,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_slpbk", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+895,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+896,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+897,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+898,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+899,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+900,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+901,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+902,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+903,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+904,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+905,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+906,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+907,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+908,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+909,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+910,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_ctrl_tx", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+911,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+912,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+913,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+914,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+915,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+916,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+917,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+918,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+919,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+920,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1075,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+921,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+922,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+923,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+924,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+925,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+926,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_ctrl0_qe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+927,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+928,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+929,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+930,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_ctrl_rxrst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+931,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+932,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+933,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+934,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+935,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+936,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+937,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+938,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+939,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+940,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+941,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+942,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+943,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+944,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+945,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+946,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_ctrl_txrst", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+947,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+948,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+949,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+950,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+951,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+952,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+953,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+954,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+955,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+956,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+957,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+958,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+959,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+960,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+961,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+962,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_status_rxlvl", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+963,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+964,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+965,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+966,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+967,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_fifo_status_txlvl", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+968,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+969,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+970,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+971,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+972,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_reg_we_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1080,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+973,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+974,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+975,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BIT(tracep,c+976,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+977,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+978,0,"oh_buf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_buf", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1081,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+979,0,"in_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+980,0,"out_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+981,0,"inv",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_prim_onehot_check", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1065,0,"AddrWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1080,0,"OneHotWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"AddrCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"EnableCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"StrictCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1058,0,"EnableAlertTriggerSVA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+982,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+983,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+984,0,"oh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1082,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+985,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+986,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1083,0,"NumLevels",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+987,0,"or_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BUS(tracep,c+988,0,"and_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_DECL_BUS(tracep,c+989,0,"err_tree",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 14,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1084,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1084,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1067,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1083,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1083,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1067,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1081,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1083,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1085,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1083,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1085,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1087,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1088,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1089,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1090,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1081,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1091,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1092,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_tree[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1085,0,"Base0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1093,0,"Base1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[0]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1085,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1093,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[1]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1094,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1095,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[2]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1087,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1096,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1097,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[3]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1088,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1098,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1099,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[4]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1089,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1100,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1101,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[5]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1090,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1102,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1103,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[6]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1091,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1104,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1105,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_level[7]", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1092,0,"Pa",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1106,0,"C0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1107,0,"C1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_rdata", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+990,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+991,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+992,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+993,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+994,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_rxempty", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+995,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+996,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+997,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+998,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+999,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_rxfull", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1000,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1001,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1002,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1003,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1004,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_rxidle", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1005,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1006,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1007,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1008,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1009,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_txempty", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1010,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1011,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1012,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1013,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1014,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_txfull", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1015,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1016,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1017,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1018,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1019,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_status_txidle", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+1020,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1021,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1022,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1023,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1024,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_wdata", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1025,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1026,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1027,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1028,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1029,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1030,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1031,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1032,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1033,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1034,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1078,0,"SwAccess",1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BIT(tracep,c+1060,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT);
    VL_TRACE_DECL_BIT(tracep,c+1035,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1036,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1062,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1037,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+1038,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1039,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "gen_w", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1040,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_wdata0_qe", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+1051,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BIT(tracep,c+1041,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1042,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1043,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1044,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____8(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____8(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____8(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____8(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____8\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 15, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[15]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[14]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"[13]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"[12]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"[11]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"[10]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+6,fidx,"[9]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+7,fidx,"[8]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+8,fidx,"[7]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+9,fidx,"[6]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+10,fidx,"[5]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+11,fidx,"[4]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+12,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+13,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+14,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+15,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____9(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____9(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____9(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____9(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____9\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 7, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[7]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[6]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"[5]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"[4]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"[3]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"[2]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+6,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+7,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____18(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____18(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____18(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____18(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____18\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"[1]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"[0]",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____21(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____21(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____21\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____21(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____21(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____21\n"); );
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

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____24(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____24(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____24(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____24(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____24\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_PACKED, 1, 0);
    VL_TRACE_PUSH_PREFIX(tracep, "[1]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,fidx,"addr",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+2,fidx,"strb",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "[0]", VerilatedTracePrefixType::STRUCT_PACKED, 3, 0);
    VL_TRACE_DECL_BUS(tracep,c+3,fidx,"addr",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+4,fidx,"data",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+5,fidx,"strb",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
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
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"BurstWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1068,0,"RespWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"CacheWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1065,0,"ProtWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"QosWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"RegionWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1059,0,"LenWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1065,0,"SizeWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1069,0,"LockWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1080,0,"AtopWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1063,0,"NsaidWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1108,0,"BURST_FIXED",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1109,0,"BURST_INCR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1110,0,"BURST_WRAP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1108,0,"RESP_OKAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1109,0,"RESP_EXOKAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1110,0,"RESP_SLVERR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1111,0,"RESP_DECERR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1112,0,"CACHE_BUFFERABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1113,0,"CACHE_MODIFIABLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1114,0,"CACHE_RD_ALLOC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1115,0,"CACHE_WR_ALLOC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1116,0,"ATOP_ATOMICSWAP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1117,0,"ATOP_ATOMICCMP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1108,0,"ATOP_NONE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1109,0,"ATOP_ATOMICSTORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1110,0,"ATOP_ATOMICLOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+1052,0,"ATOP_LITTLE_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"ATOP_BIG_END",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1082,0,"ATOP_ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1118,0,"ATOP_CLR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1119,0,"ATOP_EOR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1120,0,"ATOP_SET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1121,0,"ATOP_SMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1122,0,"ATOP_SMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1123,0,"ATOP_UMAX",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1124,0,"ATOP_UMIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+1125,0,"ATOP_R_RESP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1126,0,"DemuxAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1127,0,"DemuxW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1128,0,"DemuxB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1129,0,"DemuxAr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1130,0,"DemuxR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1131,0,"MuxAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1132,0,"MuxW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1133,0,"MuxB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1134,0,"MuxAr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
    VL_TRACE_DECL_BUS(tracep,c+1135,0,"MuxR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 9,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____33(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__uart_reg_pkg__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__uart_reg_pkg__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"RxFifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"TxFifoDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"BlockAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1081,0,"NumRegs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1136,0,"UART_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1137,0,"UART_STATUS_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1138,0,"UART_RDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1139,0,"UART_WDATA_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1140,0,"UART_FIFO_CTRL_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1141,0,"UART_FIFO_STATUS_OFFSET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_DECL_BUS(tracep,c+1142,0,"UART_STATUS_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"UART_STATUS_TXEMPTY_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"UART_STATUS_TXIDLE_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"UART_STATUS_RXIDLE_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1053,0,"UART_STATUS_RXEMPTY_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 0,0);
    VL_TRACE_DECL_BUS(tracep,c+1079,0,"UART_RDATA_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+1143,0,"UART_FIFO_STATUS_RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 23,0);

    Vtop___024root__trace_init_dtype____33(vlSelf, tracep, "UART_PERMIT", 0, c+1045, VerilatedTraceSigDirection::NONE);
    VL_TRACE_DECL_BUS(tracep,c+1056,0,"AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1066,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____33(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____33(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____33\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____33(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____33(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____33\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 0, 5);
    for (int i = 0; i < 6; ++i) {
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
    VL_TRACE_DECL_BUS(tracep,c+1055,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1086,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1090,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1054,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1097,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1101,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1105,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1066,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, 31,0);
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
    bufp->fullIData(oldp+1051,(1U),32);
    bufp->fullBit(oldp+1052,(0U));
    bufp->fullBit(oldp+1053,(1U));
    bufp->fullIData(oldp+1054,(0x00000010U),32);
    bufp->fullIData(oldp+1055,(4U),32);
    bufp->fullIData(oldp+1056,(5U),32);
    bufp->fullBit(oldp+1057,(1U));
    bufp->fullBit(oldp+1058,(1U));
    bufp->fullIData(oldp+1059,(8U),32);
    bufp->fullBit(oldp+1060,(0U));
    bufp->fullIData(oldp+1061,(0x00000010U),32);
    bufp->fullBit(oldp+1062,(0U));
    bufp->fullIData(oldp+1063,(4U),32);
    bufp->fullIData(oldp+1064,(5U),32);
    bufp->fullIData(oldp+1065,(3U),32);
    bufp->fullIData(oldp+1066,(0x00000020U),32);
    bufp->fullIData(oldp+1067,(2U),32);
    bufp->fullIData(oldp+1068,(2U),32);
    bufp->fullIData(oldp+1069,(1U),32);
    bufp->fullIData(oldp+1070,(0x00000020U),32);
    bufp->fullIData(oldp+1071,(2U),32);
    bufp->fullSData(oldp+1072,(0x7272U),16);
    bufp->fullBit(oldp+1073,(0U));
    bufp->fullIData(oldp+1074,(0U),32);
    bufp->fullCData(oldp+1075,(0U),3);
    bufp->fullSData(oldp+1076,(0x4b7fU),16);
    bufp->fullSData(oldp+1077,(0U),16);
    bufp->fullCData(oldp+1078,(2U),3);
    bufp->fullCData(oldp+1079,(0U),8);
    bufp->fullIData(oldp+1080,(6U),32);
    bufp->fullIData(oldp+1081,(6U),32);
    bufp->fullCData(oldp+1082,(0U),3);
    bufp->fullIData(oldp+1083,(3U),32);
    bufp->fullIData(oldp+1084,(0U),32);
    bufp->fullIData(oldp+1085,(7U),32);
    bufp->fullIData(oldp+1086,(8U),32);
    bufp->fullIData(oldp+1087,(9U),32);
    bufp->fullIData(oldp+1088,(0x0000000aU),32);
    bufp->fullIData(oldp+1089,(0x0000000bU),32);
    bufp->fullIData(oldp+1090,(0x0000000cU),32);
    bufp->fullIData(oldp+1091,(0x0000000dU),32);
    bufp->fullIData(oldp+1092,(0x0000000eU),32);
    bufp->fullIData(oldp+1093,(0x0000000fU),32);
    bufp->fullIData(oldp+1094,(0x00000011U),32);
    bufp->fullIData(oldp+1095,(0x00000012U),32);
    bufp->fullIData(oldp+1096,(0x00000013U),32);
    bufp->fullIData(oldp+1097,(0x00000014U),32);
    bufp->fullIData(oldp+1098,(0x00000015U),32);
    bufp->fullIData(oldp+1099,(0x00000016U),32);
    bufp->fullIData(oldp+1100,(0x00000017U),32);
    bufp->fullIData(oldp+1101,(0x00000018U),32);
    bufp->fullIData(oldp+1102,(0x00000019U),32);
    bufp->fullIData(oldp+1103,(0x0000001aU),32);
    bufp->fullIData(oldp+1104,(0x0000001bU),32);
    bufp->fullIData(oldp+1105,(0x0000001cU),32);
    bufp->fullIData(oldp+1106,(0x0000001dU),32);
    bufp->fullIData(oldp+1107,(0x0000001eU),32);
    bufp->fullCData(oldp+1108,(0U),2);
    bufp->fullCData(oldp+1109,(1U),2);
    bufp->fullCData(oldp+1110,(2U),2);
    bufp->fullCData(oldp+1111,(3U),2);
    bufp->fullCData(oldp+1112,(1U),4);
    bufp->fullCData(oldp+1113,(2U),4);
    bufp->fullCData(oldp+1114,(4U),4);
    bufp->fullCData(oldp+1115,(8U),4);
    bufp->fullCData(oldp+1116,(0x30U),6);
    bufp->fullCData(oldp+1117,(0x31U),6);
    bufp->fullCData(oldp+1118,(1U),3);
    bufp->fullCData(oldp+1119,(2U),3);
    bufp->fullCData(oldp+1120,(3U),3);
    bufp->fullCData(oldp+1121,(4U),3);
    bufp->fullCData(oldp+1122,(5U),3);
    bufp->fullCData(oldp+1123,(6U),3);
    bufp->fullCData(oldp+1124,(7U),3);
    bufp->fullIData(oldp+1125,(5U),32);
    bufp->fullSData(oldp+1126,(0x0200U),10);
    bufp->fullSData(oldp+1127,(0x0100U),10);
    bufp->fullSData(oldp+1128,(0x0080U),10);
    bufp->fullSData(oldp+1129,(0x0040U),10);
    bufp->fullSData(oldp+1130,(0x0020U),10);
    bufp->fullSData(oldp+1131,(0x0010U),10);
    bufp->fullSData(oldp+1132,(8U),10);
    bufp->fullSData(oldp+1133,(4U),10);
    bufp->fullSData(oldp+1134,(2U),10);
    bufp->fullSData(oldp+1135,(1U),10);
    bufp->fullCData(oldp+1136,(0U),5);
    bufp->fullCData(oldp+1137,(4U),5);
    bufp->fullCData(oldp+1138,(8U),5);
    bufp->fullCData(oldp+1139,(0x0cU),5);
    bufp->fullCData(oldp+1140,(0x10U),5);
    bufp->fullCData(oldp+1141,(0x14U),5);
    bufp->fullCData(oldp+1142,(0x3cU),6);
    bufp->fullIData(oldp+1143,(0U),24);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<4>/*127:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const QData/*63:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const SData/*9:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*81:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____5(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____6(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.uart_tb__DOT__clk_i));
    bufp->fullBit(oldp+1,(vlSelfRef.uart_tb__DOT__rst_ni));
    bufp->fullBit(oldp+2,(vlSelfRef.uart_tb__DOT__rx_i));
    bufp->fullBit(oldp+3,(vlSelfRef.uart_tb__DOT__tx_o));
    bufp->fullCData(oldp+4,((0x0000001fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                    >> 0x00000034U)))),5);
    bufp->fullCData(oldp+5,((7U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                           >> 0x00000031U)))),3);
    bufp->fullBit(oldp+6,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                         >> 0x00000030U)))));
    bufp->fullIData(oldp+7,((IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                     >> 0x00000010U))),32);
    bufp->fullCData(oldp+8,((0x0000000fU & (IData)(
                                                   (vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                    >> 0x0000000cU)))),4);
    bufp->fullBit(oldp+9,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                         >> 0x0000000bU)))));
    bufp->fullBit(oldp+10,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->fullCData(oldp+11,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__axi_lite_i 
                                                     >> 5U)))),5);
    bufp->fullCData(oldp+12,((7U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->fullBit(oldp+13,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->fullBit(oldp+14,((1U & (IData)(vlSelfRef.uart_tb__DOT__axi_lite_i))));
    bufp->fullBit(oldp+15,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->fullBit(oldp+16,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->fullCData(oldp+17,((3U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->fullBit(oldp+18,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->fullBit(oldp+19,((1U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->fullIData(oldp+20,((IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->fullCData(oldp+21,((3U & (IData)((vlSelfRef.uart_tb__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->fullBit(oldp+22,((1U & (IData)(vlSelfRef.uart_tb__DOT__axi_lite_o))));
    bufp->fullCData(oldp+23,(vlSelfRef.uart_tb__DOT__axi_aw_addr_i),5);
    bufp->fullCData(oldp+24,(vlSelfRef.uart_tb__DOT__axi_aw_prot_i),3);
    bufp->fullBit(oldp+25,(vlSelfRef.uart_tb__DOT__axi_aw_valid_i));
    bufp->fullBit(oldp+26,(vlSelfRef.uart_tb__DOT__axi_aw_ready_o));
    bufp->fullIData(oldp+27,(vlSelfRef.uart_tb__DOT__axi_w_data_i),32);
    bufp->fullCData(oldp+28,(vlSelfRef.uart_tb__DOT__axi_w_strb_i),4);
    bufp->fullBit(oldp+29,(vlSelfRef.uart_tb__DOT__axi_w_valid_i));
    bufp->fullBit(oldp+30,(vlSelfRef.uart_tb__DOT__axi_w_ready_o));
    bufp->fullCData(oldp+31,(vlSelfRef.uart_tb__DOT__axi_b_resp_o),2);
    bufp->fullBit(oldp+32,(vlSelfRef.uart_tb__DOT__axi_b_valid_o));
    bufp->fullBit(oldp+33,(vlSelfRef.uart_tb__DOT__axi_b_ready_i));
    bufp->fullCData(oldp+34,(vlSelfRef.uart_tb__DOT__axi_ar_addr_i),5);
    bufp->fullCData(oldp+35,(vlSelfRef.uart_tb__DOT__axi_ar_prot_i),3);
    bufp->fullBit(oldp+36,(vlSelfRef.uart_tb__DOT__axi_ar_valid_i));
    bufp->fullBit(oldp+37,(vlSelfRef.uart_tb__DOT__axi_ar_ready_o));
    bufp->fullIData(oldp+38,(vlSelfRef.uart_tb__DOT__axi_r_data_o),32);
    bufp->fullCData(oldp+39,(vlSelfRef.uart_tb__DOT__axi_r_resp_o),2);
    bufp->fullBit(oldp+40,(vlSelfRef.uart_tb__DOT__axi_r_valid_o));
    bufp->fullBit(oldp+41,(vlSelfRef.uart_tb__DOT__axi_r_ready_i));
    bufp->fullBit(oldp+42,(vlSelfRef.uart_tb__DOT__u_uart__DOT__clk_i));
    bufp->fullBit(oldp+43,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rst_ni));
    bufp->fullBit(oldp+44,(vlSelfRef.uart_tb__DOT__u_uart__DOT__rx_i));
    bufp->fullBit(oldp+45,(vlSelfRef.uart_tb__DOT__u_uart__DOT__tx_o));
    bufp->fullCData(oldp+46,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                     >> 0x00000034U)))),5);
    bufp->fullCData(oldp+47,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                            >> 0x00000031U)))),3);
    bufp->fullBit(oldp+48,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                          >> 0x00000030U)))));
    bufp->fullIData(oldp+49,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                      >> 0x00000010U))),32);
    bufp->fullCData(oldp+50,((0x0000000fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                     >> 0x0000000cU)))),4);
    bufp->fullBit(oldp+51,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                          >> 0x0000000bU)))));
    bufp->fullBit(oldp+52,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                          >> 0x0000000aU)))));
    bufp->fullCData(oldp+53,((0x0000001fU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                                     >> 5U)))),5);
    bufp->fullCData(oldp+54,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                            >> 2U)))),3);
    bufp->fullBit(oldp+55,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i 
                                          >> 1U)))));
    bufp->fullBit(oldp+56,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_i))));
    bufp->fullBit(oldp+57,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                          >> 0x00000028U)))));
    bufp->fullBit(oldp+58,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                          >> 0x00000027U)))));
    bufp->fullCData(oldp+59,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                            >> 0x00000025U)))),2);
    bufp->fullBit(oldp+60,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                          >> 0x00000024U)))));
    bufp->fullBit(oldp+61,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                          >> 0x00000023U)))));
    bufp->fullIData(oldp+62,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                      >> 3U))),32);
    bufp->fullCData(oldp+63,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o 
                                            >> 1U)))),2);
    bufp->fullBit(oldp+64,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__axi_lite_o))));
    bufp->fullSData(oldp+65,((0x0000ffffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                     >> 0x00000029U)))),16);
    bufp->fullBit(oldp+66,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000028U)))));
    bufp->fullBit(oldp+67,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000027U)))));
    bufp->fullBit(oldp+68,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000026U)))));
    bufp->fullBit(oldp+69,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000025U)))));
    bufp->fullBit(oldp+70,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000024U)))));
    bufp->fullBit(oldp+71,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000023U)))));
    bufp->fullBit(oldp+72,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000022U)))));
    bufp->fullBit(oldp+73,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000021U)))));
    bufp->fullBit(oldp+74,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000020U)))));
    bufp->fullBit(oldp+75,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001fU)))));
    bufp->fullBit(oldp+76,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001eU)))));
    bufp->fullBit(oldp+77,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001dU)))));
    bufp->fullBit(oldp+78,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001cU)))));
    bufp->fullBit(oldp+79,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001bU)))));
    bufp->fullBit(oldp+80,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000001aU)))));
    bufp->fullBit(oldp+81,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000019U)))));
    bufp->fullBit(oldp+82,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000018U)))));
    bufp->fullBit(oldp+83,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000017U)))));
    bufp->fullBit(oldp+84,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x00000016U)))));
    bufp->fullCData(oldp+85,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                     >> 0x0000000eU)))),8);
    bufp->fullBit(oldp+86,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 0x0000000dU)))));
    bufp->fullCData(oldp+87,((0x000000ffU & (IData)(
                                                    (vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                                     >> 5U)))),8);
    bufp->fullBit(oldp+88,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 4U)))));
    bufp->fullBit(oldp+89,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 3U)))));
    bufp->fullBit(oldp+90,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 2U)))));
    bufp->fullBit(oldp+91,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw 
                                          >> 1U)))));
    bufp->fullBit(oldp+92,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg2hw))));
    bufp->fullBit(oldp+93,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x0000001dU))));
    bufp->fullBit(oldp+94,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x0000001cU))));
    bufp->fullBit(oldp+95,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x0000001bU))));
    bufp->fullBit(oldp+96,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x0000001aU))));
    bufp->fullBit(oldp+97,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x00000019U))));
    bufp->fullBit(oldp+98,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                  >> 0x00000018U))));
    bufp->fullCData(oldp+99,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                             >> 0x00000010U))),8);
    bufp->fullCData(oldp+100,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg 
                                              >> 8U))),8);
    bufp->fullCData(oldp+101,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__hw2reg)),8);
    bufp->fullBit(oldp+102,(vlSelfRef.uart_tb__DOT__u_uart__DOT__reg_rst_ni));
    bufp->fullBit(oldp+103,(vlSelfRef.uart_tb__DOT__u_uart__DOT__core_rst_ni));
    bufp->fullBit(oldp+104,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+105,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+106,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+107,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+108,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__intq));
    bufp->fullBit(oldp+109,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+110,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+111,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+112,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+113,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+114,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+115,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_core_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+116,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__clk_i));
    bufp->fullBit(oldp+117,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__rst_ni));
    bufp->fullBit(oldp+118,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__q_o));
    bufp->fullBit(oldp+119,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__d_o));
    bufp->fullBit(oldp+120,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__intq));
    bufp->fullBit(oldp+121,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+122,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+123,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+124,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+125,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+126,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+127,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_reg_reset_sync__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+128,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__clk_i));
    bufp->fullBit(oldp+129,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rst_ni));
    bufp->fullSData(oldp+130,((0x0000ffffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                      >> 0x00000029U)))),16);
    bufp->fullBit(oldp+131,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+132,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000027U)))));
    bufp->fullBit(oldp+133,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000026U)))));
    bufp->fullBit(oldp+134,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000025U)))));
    bufp->fullBit(oldp+135,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+136,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000023U)))));
    bufp->fullBit(oldp+137,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000022U)))));
    bufp->fullBit(oldp+138,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000021U)))));
    bufp->fullBit(oldp+139,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000020U)))));
    bufp->fullBit(oldp+140,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001fU)))));
    bufp->fullBit(oldp+141,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001eU)))));
    bufp->fullBit(oldp+142,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001dU)))));
    bufp->fullBit(oldp+143,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001cU)))));
    bufp->fullBit(oldp+144,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001bU)))));
    bufp->fullBit(oldp+145,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000001aU)))));
    bufp->fullBit(oldp+146,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000019U)))));
    bufp->fullBit(oldp+147,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000018U)))));
    bufp->fullBit(oldp+148,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000017U)))));
    bufp->fullBit(oldp+149,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x00000016U)))));
    bufp->fullCData(oldp+150,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                      >> 0x0000000eU)))),8);
    bufp->fullBit(oldp+151,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 0x0000000dU)))));
    bufp->fullCData(oldp+152,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                                      >> 5U)))),8);
    bufp->fullBit(oldp+153,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 4U)))));
    bufp->fullBit(oldp+154,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 3U)))));
    bufp->fullBit(oldp+155,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 2U)))));
    bufp->fullBit(oldp+156,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw 
                                           >> 1U)))));
    bufp->fullBit(oldp+157,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__reg2hw))));
    bufp->fullBit(oldp+158,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x0000001dU))));
    bufp->fullBit(oldp+159,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x0000001cU))));
    bufp->fullBit(oldp+160,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x0000001bU))));
    bufp->fullBit(oldp+161,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x0000001aU))));
    bufp->fullBit(oldp+162,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x00000019U))));
    bufp->fullBit(oldp+163,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                   >> 0x00000018U))));
    bufp->fullCData(oldp+164,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+165,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg 
                                              >> 8U))),8);
    bufp->fullCData(oldp+166,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__hw2reg)),8);
    bufp->fullBit(oldp+167,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_i));
    bufp->fullBit(oldp+168,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_o));
    bufp->fullSData(oldp+169,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_val_q),16);
    bufp->fullCData(oldp+170,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rdata),8);
    bufp->fullBit(oldp+171,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tick_baud_x16));
    bufp->fullBit(oldp+172,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_tick_baud));
    bufp->fullCData(oldp+173,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_depth),4);
    bufp->fullCData(oldp+174,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth),5);
    bufp->fullCData(oldp+175,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_prev_q),5);
    bufp->fullIData(oldp+176,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_d),24);
    bufp->fullIData(oldp+177,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_timeout_count_q),24);
    bufp->fullIData(oldp+178,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_val),24);
    bufp->fullBit(oldp+179,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_depth_changed));
    bufp->fullBit(oldp+180,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rxto_en));
    bufp->fullBit(oldp+181,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_enable));
    bufp->fullBit(oldp+182,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sys_loopback));
    bufp->fullBit(oldp+183,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__line_loopback));
    bufp->fullBit(oldp+184,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rxnf_enable));
    bufp->fullBit(oldp+185,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_rxrst));
    bufp->fullBit(oldp+186,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_fifo_txrst));
    bufp->fullCData(oldp+187,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_data),8);
    bufp->fullBit(oldp+188,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rready));
    bufp->fullBit(oldp+189,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_rvalid));
    bufp->fullBit(oldp+190,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wready));
    bufp->fullBit(oldp+191,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle));
    bufp->fullBit(oldp+192,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out));
    bufp->fullBit(oldp+193,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_out_q));
    bufp->fullCData(oldp+194,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_data),8);
    bufp->fullBit(oldp+195,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_valid));
    bufp->fullBit(oldp+196,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wvalid));
    bufp->fullBit(oldp+197,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_rvalid));
    bufp->fullBit(oldp+198,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_wready));
    bufp->fullBit(oldp+199,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_uart_idle));
    bufp->fullBit(oldp+200,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync));
    bufp->fullBit(oldp+201,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in));
    bufp->fullBit(oldp+202,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__break_err));
    bufp->fullCData(oldp+203,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_d),5);
    bufp->fullCData(oldp+204,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_cnt_q),5);
    bufp->fullBit(oldp+205,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__allzero_err));
    bufp->fullBit(oldp+206,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__not_allzero_char));
    bufp->fullBit(oldp+207,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_watermark));
    bufp->fullBit(oldp+208,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_empty));
    bufp->fullBit(oldp+209,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_watermark));
    bufp->fullBit(oldp+210,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_tx_done));
    bufp->fullBit(oldp+211,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_overflow));
    bufp->fullBit(oldp+212,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_frame_err));
    bufp->fullBit(oldp+213,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_break_err));
    bufp->fullBit(oldp+214,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_timeout));
    bufp->fullBit(oldp+215,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__event_rx_parity_err));
    bufp->fullBit(oldp+216,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_uart_idle_q));
    bufp->fullBit(oldp+217,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__timing_rst_ni));
    bufp->fullBit(oldp+218,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_rst_ni));
    bufp->fullBit(oldp+219,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_rst_ni));
    bufp->fullBit(oldp+220,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_fifo_pop));
    bufp->fullCData(oldp+221,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wdata),8);
    bufp->fullBit(oldp+222,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__tx_fifo_wvalid));
    bufp->fullIData(oldp+223,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__nco_sum_q),17);
    bufp->fullBit(oldp+224,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q1));
    bufp->fullBit(oldp+225,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_sync_q2));
    bufp->fullBit(oldp+226,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_mx));
    bufp->fullBit(oldp+227,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__rx_in_maj));
    bufp->fullBit(oldp+228,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__clk_i));
    bufp->fullBit(oldp+229,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__rst_ni));
    bufp->fullBit(oldp+230,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_i));
    bufp->fullBit(oldp+231,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__q_o));
    bufp->fullBit(oldp+232,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__d_o));
    bufp->fullBit(oldp+233,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__intq));
    bufp->fullBit(oldp+234,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__clk_i));
    bufp->fullBit(oldp+235,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__rst_ni));
    bufp->fullBit(oldp+236,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__d_i));
    bufp->fullBit(oldp+237,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_1__DOT__q_o));
    bufp->fullBit(oldp+238,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__clk_i));
    bufp->fullBit(oldp+239,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__rst_ni));
    bufp->fullBit(oldp+240,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__d_i));
    bufp->fullBit(oldp+241,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__sync_rx__DOT__u_sync_2__DOT__q_o));
    bufp->fullBit(oldp+242,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+243,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+244,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_rx_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+245,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+246,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+247,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_timing_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+248,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__clk_i));
    bufp->fullBit(oldp+249,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__rst_ni));
    bufp->fullBit(oldp+250,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_tx_reset_branch__DOT__q_o));
    bufp->fullBit(oldp+251,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clk_i));
    bufp->fullBit(oldp+252,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rst_ni));
    bufp->fullBit(oldp+253,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__clr_i));
    bufp->fullBit(oldp+254,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wvalid_i));
    bufp->fullBit(oldp+255,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wready_o));
    bufp->fullCData(oldp+256,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__wdata_i),8);
    bufp->fullBit(oldp+257,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rvalid_o));
    bufp->fullBit(oldp+258,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rready_i));
    bufp->fullCData(oldp+259,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__rdata_o),8);
    bufp->fullBit(oldp+260,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__full_o));
    bufp->fullCData(oldp+261,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__depth_o),5);
    bufp->fullCData(oldp+262,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),4);
    bufp->fullCData(oldp+263,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),4);
    bufp->fullBit(oldp+264,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+265,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+266,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+267,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+268,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 269, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->fullCData(oldp+285,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->fullCData(oldp+286,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->fullBit(oldp+287,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->fullBit(oldp+288,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->fullBit(oldp+289,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->fullBit(oldp+290,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->fullBit(oldp+291,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->fullCData(oldp+292,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),4);
    bufp->fullCData(oldp+293,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),4);
    bufp->fullBit(oldp+294,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->fullBit(oldp+295,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->fullCData(oldp+296,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),5);
    bufp->fullCData(oldp+297,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),5);
    bufp->fullCData(oldp+298,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),5);
    bufp->fullCData(oldp+299,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),5);
    bufp->fullCData(oldp+300,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),5);
    bufp->fullBit(oldp+301,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->fullBit(oldp+302,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->fullBit(oldp+303,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->fullBit(oldp+304,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->fullBit(oldp+305,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clk_i));
    bufp->fullBit(oldp+306,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rst_ni));
    bufp->fullBit(oldp+307,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__clr_i));
    bufp->fullBit(oldp+308,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wvalid_i));
    bufp->fullBit(oldp+309,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wready_o));
    bufp->fullCData(oldp+310,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__wdata_i),8);
    bufp->fullBit(oldp+311,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rvalid_o));
    bufp->fullBit(oldp+312,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rready_i));
    bufp->fullCData(oldp+313,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__rdata_o),8);
    bufp->fullBit(oldp+314,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__full_o));
    bufp->fullCData(oldp+315,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__depth_o),4);
    bufp->fullCData(oldp+316,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_wptr),3);
    bufp->fullCData(oldp+317,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_rptr),3);
    bufp->fullBit(oldp+318,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+319,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+320,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+321,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+322,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__empty));
    Vtop___024root__trace_full_dtype____1(vlSelf, bufp, 323, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage);
    bufp->fullCData(oldp+331,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__storage_rdata),8);
    bufp->fullCData(oldp+332,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__rdata_int),8);
    bufp->fullBit(oldp+333,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clk_i));
    bufp->fullBit(oldp+334,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rst_ni));
    bufp->fullBit(oldp+335,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__clr_i));
    bufp->fullBit(oldp+336,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_wptr_i));
    bufp->fullBit(oldp+337,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__incr_rptr_i));
    bufp->fullCData(oldp+338,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_o),3);
    bufp->fullCData(oldp+339,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_o),3);
    bufp->fullBit(oldp+340,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__full_o));
    bufp->fullBit(oldp+341,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__empty_o));
    bufp->fullCData(oldp+342,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__depth_o),4);
    bufp->fullCData(oldp+343,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),4);
    bufp->fullCData(oldp+344,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt),4);
    bufp->fullCData(oldp+345,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),4);
    bufp->fullCData(oldp+346,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt),4);
    bufp->fullBit(oldp+347,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb));
    bufp->fullBit(oldp+348,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb));
    bufp->fullBit(oldp+349,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set));
    bufp->fullBit(oldp+350,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__u_uart_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set));
    bufp->fullBit(oldp+351,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__clk_i));
    bufp->fullBit(oldp+352,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rst_ni));
    bufp->fullBit(oldp+353,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_x16));
    bufp->fullBit(oldp+354,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_enable));
    bufp->fullBit(oldp+355,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__parity_odd));
    bufp->fullBit(oldp+356,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud));
    bufp->fullBit(oldp+357,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid));
    bufp->fullCData(oldp+358,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_data),8);
    bufp->fullBit(oldp+359,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle));
    bufp->fullBit(oldp+360,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__frame_err));
    bufp->fullBit(oldp+361,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_parity_err));
    bufp->fullBit(oldp+362,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx));
    bufp->fullBit(oldp+363,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__rx_valid_q));
    bufp->fullSData(oldp+364,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_q),11);
    bufp->fullSData(oldp+365,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__sreg_d),11);
    bufp->fullCData(oldp+366,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_q),4);
    bufp->fullCData(oldp+367,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__bit_cnt_d),4);
    bufp->fullCData(oldp+368,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_q),4);
    bufp->fullCData(oldp+369,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__baud_div_d),4);
    bufp->fullBit(oldp+370,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_d));
    bufp->fullBit(oldp+371,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__tick_baud_q));
    bufp->fullBit(oldp+372,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_d));
    bufp->fullBit(oldp+373,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_rx__DOT__idle_q));
    bufp->fullBit(oldp+374,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__clk_i));
    bufp->fullBit(oldp+375,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__rst_ni));
    bufp->fullBit(oldp+376,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_enable));
    bufp->fullBit(oldp+377,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_x16));
    bufp->fullBit(oldp+378,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__parity_enable));
    bufp->fullBit(oldp+379,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr));
    bufp->fullBit(oldp+380,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_parity));
    bufp->fullCData(oldp+381,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__wr_data),8);
    bufp->fullBit(oldp+382,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__idle));
    bufp->fullBit(oldp+383,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx));
    bufp->fullCData(oldp+384,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__baud_div_q),4);
    bufp->fullBit(oldp+385,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tick_baud_q));
    bufp->fullCData(oldp+386,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_q),4);
    bufp->fullCData(oldp+387,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__bit_cnt_d),4);
    bufp->fullSData(oldp+388,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_q),11);
    bufp->fullSData(oldp+389,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__sreg_d),11);
    bufp->fullBit(oldp+390,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_q));
    bufp->fullBit(oldp+391,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_core__DOT__uart_tx__DOT__tx_d));
    bufp->fullBit(oldp+392,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__clk_i));
    bufp->fullBit(oldp+393,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__rst_ni));
    bufp->fullCData(oldp+394,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                      >> 0x00000034U)))),5);
    bufp->fullCData(oldp+395,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                             >> 0x00000031U)))),3);
    bufp->fullBit(oldp+396,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                           >> 0x00000030U)))));
    bufp->fullIData(oldp+397,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                       >> 0x00000010U))),32);
    bufp->fullCData(oldp+398,((0x0000000fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                      >> 0x0000000cU)))),4);
    bufp->fullBit(oldp+399,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                           >> 0x0000000bU)))));
    bufp->fullBit(oldp+400,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                           >> 0x0000000aU)))));
    bufp->fullCData(oldp+401,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                                      >> 5U)))),5);
    bufp->fullCData(oldp+402,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                             >> 2U)))),3);
    bufp->fullBit(oldp+403,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+404,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_i))));
    bufp->fullBit(oldp+405,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+406,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                           >> 0x00000027U)))));
    bufp->fullCData(oldp+407,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                             >> 0x00000025U)))),2);
    bufp->fullBit(oldp+408,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+409,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                           >> 0x00000023U)))));
    bufp->fullIData(oldp+410,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                       >> 3U))),32);
    bufp->fullCData(oldp+411,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+412,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__axi_lite_o))));
    bufp->fullSData(oldp+413,((0x0000ffffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                      >> 0x00000029U)))),16);
    bufp->fullBit(oldp+414,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+415,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000027U)))));
    bufp->fullBit(oldp+416,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000026U)))));
    bufp->fullBit(oldp+417,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000025U)))));
    bufp->fullBit(oldp+418,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+419,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000023U)))));
    bufp->fullBit(oldp+420,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000022U)))));
    bufp->fullBit(oldp+421,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000021U)))));
    bufp->fullBit(oldp+422,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000020U)))));
    bufp->fullBit(oldp+423,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001fU)))));
    bufp->fullBit(oldp+424,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001eU)))));
    bufp->fullBit(oldp+425,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001dU)))));
    bufp->fullBit(oldp+426,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001cU)))));
    bufp->fullBit(oldp+427,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001bU)))));
    bufp->fullBit(oldp+428,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000001aU)))));
    bufp->fullBit(oldp+429,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000019U)))));
    bufp->fullBit(oldp+430,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000018U)))));
    bufp->fullBit(oldp+431,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000017U)))));
    bufp->fullBit(oldp+432,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x00000016U)))));
    bufp->fullCData(oldp+433,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                      >> 0x0000000eU)))),8);
    bufp->fullBit(oldp+434,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 0x0000000dU)))));
    bufp->fullCData(oldp+435,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                                      >> 5U)))),8);
    bufp->fullBit(oldp+436,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 4U)))));
    bufp->fullBit(oldp+437,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 3U)))));
    bufp->fullBit(oldp+438,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 2U)))));
    bufp->fullBit(oldp+439,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw 
                                           >> 1U)))));
    bufp->fullBit(oldp+440,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__reg2hw))));
    bufp->fullBit(oldp+441,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x0000001dU))));
    bufp->fullBit(oldp+442,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x0000001cU))));
    bufp->fullBit(oldp+443,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x0000001bU))));
    bufp->fullBit(oldp+444,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x0000001aU))));
    bufp->fullBit(oldp+445,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x00000019U))));
    bufp->fullBit(oldp+446,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                   >> 0x00000018U))));
    bufp->fullCData(oldp+447,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+448,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg 
                                              >> 8U))),8);
    bufp->fullCData(oldp+449,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__hw2reg)),8);
    bufp->fullBit(oldp+450,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                           >> 0x0000002aU)))));
    bufp->fullBit(oldp+451,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                           >> 0x00000029U)))));
    bufp->fullCData(oldp+452,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+453,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req 
                                       >> 4U))),32);
    bufp->fullCData(oldp+454,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_req))),4);
    bufp->fullIData(oldp+455,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp 
                                       >> 2U))),32);
    bufp->fullBit(oldp+456,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp 
                                           >> 1U)))));
    bufp->fullBit(oldp+457,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__flexsoc_axi_reg_rsp))));
    bufp->fullBit(oldp+458,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__clk_i));
    bufp->fullBit(oldp+459,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__rst_ni));
    bufp->fullCData(oldp+460,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 0x00000034U)))),5);
    bufp->fullCData(oldp+461,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                             >> 0x00000031U)))),3);
    bufp->fullBit(oldp+462,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 0x00000030U)))));
    bufp->fullIData(oldp+463,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                       >> 0x00000010U))),32);
    bufp->fullCData(oldp+464,((0x0000000fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 0x0000000cU)))),4);
    bufp->fullBit(oldp+465,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 0x0000000bU)))));
    bufp->fullBit(oldp+466,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 0x0000000aU)))));
    bufp->fullCData(oldp+467,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                                      >> 5U)))),5);
    bufp->fullCData(oldp+468,((7U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                             >> 2U)))),3);
    bufp->fullBit(oldp+469,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+470,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_req_i))));
    bufp->fullBit(oldp+471,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+472,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000027U)))));
    bufp->fullCData(oldp+473,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                             >> 0x00000025U)))),2);
    bufp->fullBit(oldp+474,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+475,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                           >> 0x00000023U)))));
    bufp->fullIData(oldp+476,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                       >> 3U))),32);
    bufp->fullCData(oldp+477,((3U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o 
                                             >> 1U)))),2);
    bufp->fullBit(oldp+478,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__axi_lite_rsp_o))));
    bufp->fullBit(oldp+479,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                           >> 0x0000002aU)))));
    bufp->fullBit(oldp+480,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                           >> 0x00000029U)))));
    bufp->fullCData(oldp+481,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+482,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o 
                                       >> 4U))),32);
    bufp->fullCData(oldp+483,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_req_o))),4);
    bufp->fullIData(oldp+484,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                       >> 2U))),32);
    bufp->fullBit(oldp+485,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i 
                                           >> 1U)))));
    bufp->fullBit(oldp+486,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__reg_rsp_i))));
    bufp->fullBit(oldp+487,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_full));
    bufp->fullBit(oldp+488,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_empty));
    bufp->fullCData(oldp+489,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+490,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in 
                                       >> 4U))),32);
    bufp->fullCData(oldp+491,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_in))),4);
    bufp->fullCData(oldp+492,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+493,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out 
                                       >> 4U))),32);
    bufp->fullCData(oldp+494,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_out))),4);
    bufp->fullBit(oldp+495,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_push));
    bufp->fullBit(oldp+496,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_fifo_pop));
    bufp->fullBit(oldp+497,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_full));
    bufp->fullBit(oldp+498,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_empty));
    bufp->fullBit(oldp+499,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_in));
    bufp->fullBit(oldp+500,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_out));
    bufp->fullBit(oldp+501,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_push));
    bufp->fullBit(oldp+502,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_resp_fifo_pop));
    bufp->fullBit(oldp+503,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_full));
    bufp->fullBit(oldp+504,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_empty));
    bufp->fullCData(oldp+505,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_in),5);
    bufp->fullCData(oldp+506,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_out),5);
    bufp->fullBit(oldp+507,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_push));
    bufp->fullBit(oldp+508,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_fifo_pop));
    bufp->fullBit(oldp+509,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_full));
    bufp->fullBit(oldp+510,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_empty));
    bufp->fullIData(oldp+511,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in 
                                       >> 1U))),32);
    bufp->fullBit(oldp+512,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_in))));
    bufp->fullIData(oldp+513,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out 
                                       >> 1U))),32);
    bufp->fullBit(oldp+514,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_out))));
    bufp->fullBit(oldp+515,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_push));
    bufp->fullBit(oldp+516,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_resp_fifo_pop));
    bufp->fullCData(oldp+517,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+518,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_req))));
    bufp->fullCData(oldp+519,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+520,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_req))));
    bufp->fullCData(oldp+521,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+522,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__arb_req))));
    bufp->fullBit(oldp+523,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_valid));
    bufp->fullBit(oldp+524,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_valid));
    bufp->fullBit(oldp+525,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__read_ready));
    bufp->fullBit(oldp+526,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__write_ready));
    bufp->fullBit(oldp+527,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__clk_i));
    bufp->fullBit(oldp+528,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__rst_ni));
    bufp->fullBit(oldp+529,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__full_o));
    bufp->fullBit(oldp+530,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__empty_o));
    bufp->fullBit(oldp+531,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__usage_o));
    bufp->fullCData(oldp+532,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_i),5);
    bufp->fullBit(oldp+533,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__push_i));
    bufp->fullCData(oldp+534,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__data_o),5);
    bufp->fullBit(oldp+535,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__pop_i));
    bufp->fullBit(oldp+536,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__gate_clock));
    bufp->fullBit(oldp+537,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_n));
    bufp->fullBit(oldp+538,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__read_pointer_q));
    bufp->fullBit(oldp+539,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_n));
    bufp->fullBit(oldp+540,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__write_pointer_q));
    bufp->fullCData(oldp+541,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+542,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+543,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n) 
                                              >> 5U))),5);
    bufp->fullCData(oldp+544,((0x0000001fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_n))),5);
    Vtop___024root__trace_full_dtype____2(vlSelf, bufp, 545, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read__DOT__mem_q);
    bufp->fullBit(oldp+547,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__clk_i));
    bufp->fullBit(oldp+548,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__rst_ni));
    bufp->fullBit(oldp+549,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__full_o));
    bufp->fullBit(oldp+550,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__empty_o));
    bufp->fullBit(oldp+551,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__usage_o));
    bufp->fullIData(oldp+552,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i 
                                       >> 1U))),32);
    bufp->fullBit(oldp+553,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_i))));
    bufp->fullBit(oldp+554,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__push_i));
    bufp->fullIData(oldp+555,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o 
                                       >> 1U))),32);
    bufp->fullBit(oldp+556,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__data_o))));
    bufp->fullBit(oldp+557,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__pop_i));
    bufp->fullBit(oldp+558,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__gate_clock));
    bufp->fullBit(oldp+559,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_n));
    bufp->fullBit(oldp+560,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__read_pointer_q));
    bufp->fullBit(oldp+561,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_n));
    bufp->fullBit(oldp+562,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__write_pointer_q));
    bufp->fullCData(oldp+563,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+564,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__status_cnt_q),2);
    bufp->fullIData(oldp+565,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[2U] 
                                << 0x0000001eU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                                   >> 2U))),32);
    bufp->fullBit(oldp+566,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                   >> 1U))));
    bufp->fullIData(oldp+567,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[1U] 
                                << 0x0000001fU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U] 
                                                   >> 1U))),32);
    bufp->fullBit(oldp+568,((1U & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_n[0U])));
    Vtop___024root__trace_full_dtype____3(vlSelf, bufp, 569, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_read_resp__DOT__mem_q);
    bufp->fullBit(oldp+573,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__clk_i));
    bufp->fullBit(oldp+574,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__rst_ni));
    bufp->fullBit(oldp+575,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__full_o));
    bufp->fullBit(oldp+576,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__empty_o));
    bufp->fullBit(oldp+577,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__usage_o));
    bufp->fullCData(oldp+578,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+579,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i 
                                       >> 4U))),32);
    bufp->fullCData(oldp+580,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_i))),4);
    bufp->fullBit(oldp+581,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__push_i));
    bufp->fullCData(oldp+582,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+583,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o 
                                       >> 4U))),32);
    bufp->fullCData(oldp+584,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__data_o))),4);
    bufp->fullBit(oldp+585,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__pop_i));
    bufp->fullBit(oldp+586,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__gate_clock));
    bufp->fullBit(oldp+587,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_n));
    bufp->fullBit(oldp+588,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__read_pointer_q));
    bufp->fullBit(oldp+589,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_n));
    bufp->fullBit(oldp+590,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__write_pointer_q));
    bufp->fullCData(oldp+591,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+592,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+593,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                              >> 0x0000000dU))),5);
    bufp->fullIData(oldp+594,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[2U] 
                                << 0x00000013U) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                                   >> 0x0000000dU))),32);
    bufp->fullCData(oldp+595,((0x0000000fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                              >> 9U))),4);
    bufp->fullCData(oldp+596,((0x0000001fU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                              >> 4U))),5);
    bufp->fullIData(oldp+597,(((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[1U] 
                                << 0x0000001cU) | (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U] 
                                                   >> 4U))),32);
    bufp->fullCData(oldp+598,((0x0000000fU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_n[0U])),4);
    Vtop___024root__trace_full_dtype____4(vlSelf, bufp, 599, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_req__DOT__mem_q);
    bufp->fullBit(oldp+605,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__clk_i));
    bufp->fullBit(oldp+606,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__rst_ni));
    bufp->fullBit(oldp+607,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__full_o));
    bufp->fullBit(oldp+608,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__empty_o));
    bufp->fullBit(oldp+609,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__usage_o));
    bufp->fullBit(oldp+610,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_i));
    bufp->fullBit(oldp+611,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__push_i));
    bufp->fullBit(oldp+612,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__data_o));
    bufp->fullBit(oldp+613,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__pop_i));
    bufp->fullBit(oldp+614,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__gate_clock));
    bufp->fullBit(oldp+615,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_n));
    bufp->fullBit(oldp+616,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__read_pointer_q));
    bufp->fullBit(oldp+617,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_n));
    bufp->fullBit(oldp+618,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__write_pointer_q));
    bufp->fullCData(oldp+619,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_n),2);
    bufp->fullCData(oldp+620,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__status_cnt_q),2);
    bufp->fullCData(oldp+621,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_n),2);
    bufp->fullCData(oldp+622,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_fifo_write_resp__DOT__mem_q),2);
    bufp->fullBit(oldp+623,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__clk_i));
    bufp->fullBit(oldp+624,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__rst_ni));
    bufp->fullCData(oldp+625,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                              >> 7U))),5);
    bufp->fullBit(oldp+626,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                   >> 6U))));
    bufp->fullCData(oldp+627,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+628,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_data_i))));
    bufp->fullCData(oldp+629,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_valid_i),2);
    bufp->fullCData(oldp+630,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__inp_ready_o),2);
    bufp->fullCData(oldp+631,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+632,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_data_o))));
    bufp->fullBit(oldp+633,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_valid_o));
    bufp->fullBit(oldp+634,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__oup_ready_i));
    bufp->fullBit(oldp+635,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__clk_i));
    bufp->fullBit(oldp+636,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__rst_ni));
    bufp->fullCData(oldp+637,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                              >> 7U))),5);
    bufp->fullBit(oldp+638,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                   >> 6U))));
    bufp->fullCData(oldp+639,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+640,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_data_i))));
    bufp->fullCData(oldp+641,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_valid_i),2);
    bufp->fullCData(oldp+642,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__inp_ready_o),2);
    bufp->fullCData(oldp+643,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+644,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_data_o))));
    bufp->fullBit(oldp+645,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_valid_o));
    bufp->fullBit(oldp+646,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__oup_ready_i));
    bufp->fullBit(oldp+647,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__clk_i));
    bufp->fullBit(oldp+648,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__rst_ni));
    bufp->fullCData(oldp+649,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_i),2);
    bufp->fullCData(oldp+650,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_o),2);
    bufp->fullCData(oldp+651,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                              >> 7U))),5);
    bufp->fullBit(oldp+652,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                   >> 6U))));
    bufp->fullCData(oldp+653,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+654,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_i))));
    bufp->fullBit(oldp+655,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__req_o));
    bufp->fullBit(oldp+656,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gnt_i));
    bufp->fullCData(oldp+657,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+658,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__data_o))));
    bufp->fullBit(oldp+659,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__idx_o));
    bufp->fullBit(oldp+660,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__index_nodes));
    bufp->fullCData(oldp+661,((0x0000001fU & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes) 
                                              >> 1U))),5);
    bufp->fullBit(oldp+662,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__data_nodes))));
    bufp->fullBit(oldp+663,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gnt_nodes));
    bufp->fullBit(oldp+664,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_nodes));
    bufp->fullBit(oldp+665,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__rr_q));
    bufp->fullCData(oldp+666,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__req_d),2);
    bufp->fullBit(oldp+667,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__rr_d));
    bufp->fullCData(oldp+668,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_mask),2);
    bufp->fullCData(oldp+669,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_mask),2);
    bufp->fullBit(oldp+670,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_idx));
    bufp->fullBit(oldp+671,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_idx));
    bufp->fullBit(oldp+672,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__next_idx));
    bufp->fullBit(oldp+673,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__upper_empty));
    bufp->fullBit(oldp+674,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__lower_empty));
    bufp->fullCData(oldp+675,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__in_i),2);
    bufp->fullBit(oldp+676,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__cnt_o));
    bufp->fullBit(oldp+677,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__empty_o));
    Vtop___024root__trace_full_dtype____5(vlSelf, bufp, 678, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_lut);
    bufp->fullCData(oldp+680,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->fullBit(oldp+681,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes) 
                                   >> 1U))));
    bufp->fullBit(oldp+682,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__index_nodes))));
    bufp->fullCData(oldp+683,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_lower__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->fullCData(oldp+684,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__in_i),2);
    bufp->fullBit(oldp+685,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__cnt_o));
    bufp->fullBit(oldp+686,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__empty_o));
    Vtop___024root__trace_full_dtype____5(vlSelf, bufp, 687, vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_lut);
    bufp->fullCData(oldp+689,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__sel_nodes),2);
    bufp->fullBit(oldp+690,((1U & ((IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes) 
                                   >> 1U))));
    bufp->fullBit(oldp+691,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__index_nodes))));
    bufp->fullCData(oldp+692,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_fair_arb__DOT__i_lzc_upper__DOT__gen_lzc__DOT__in_tmp),2);
    bufp->fullBit(oldp+693,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_d));
    bufp->fullBit(oldp+694,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__lock_q));
    bufp->fullCData(oldp+695,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_int_rr__DOT__gen_lock__DOT__req_q),2);
    bufp->fullBit(oldp+696,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_flexsoc_axi_to_reg__DOT__i_stream_arbiter__DOT__i_arb__DOT__gen_rr_arb__DOT__i_arbiter__DOT__gen_arbiter__DOT__gen_levels__BRA__0__KET____DOT__gen_level__BRA__0__KET____DOT__sel));
    bufp->fullBit(oldp+697,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__clk_i));
    bufp->fullBit(oldp+698,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rst_ni));
    bufp->fullBit(oldp+699,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x0000002aU)))));
    bufp->fullBit(oldp+700,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                           >> 0x00000029U)))));
    bufp->fullCData(oldp+701,((0x0000001fU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                                      >> 0x00000024U)))),5);
    bufp->fullIData(oldp+702,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i 
                                       >> 4U))),32);
    bufp->fullCData(oldp+703,((0x0000000fU & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_req_i))),4);
    bufp->fullIData(oldp+704,((IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                       >> 2U))),32);
    bufp->fullBit(oldp+705,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o 
                                           >> 1U)))));
    bufp->fullBit(oldp+706,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rsp_o))));
    bufp->fullSData(oldp+707,((0x0000ffffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                      >> 0x00000029U)))),16);
    bufp->fullBit(oldp+708,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000028U)))));
    bufp->fullBit(oldp+709,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000027U)))));
    bufp->fullBit(oldp+710,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000026U)))));
    bufp->fullBit(oldp+711,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000025U)))));
    bufp->fullBit(oldp+712,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000024U)))));
    bufp->fullBit(oldp+713,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000023U)))));
    bufp->fullBit(oldp+714,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000022U)))));
    bufp->fullBit(oldp+715,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000021U)))));
    bufp->fullBit(oldp+716,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000020U)))));
    bufp->fullBit(oldp+717,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001fU)))));
    bufp->fullBit(oldp+718,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001eU)))));
    bufp->fullBit(oldp+719,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001dU)))));
    bufp->fullBit(oldp+720,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001cU)))));
    bufp->fullBit(oldp+721,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001bU)))));
    bufp->fullBit(oldp+722,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000001aU)))));
    bufp->fullBit(oldp+723,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000019U)))));
    bufp->fullBit(oldp+724,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000018U)))));
    bufp->fullBit(oldp+725,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000017U)))));
    bufp->fullBit(oldp+726,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x00000016U)))));
    bufp->fullCData(oldp+727,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                      >> 0x0000000eU)))),8);
    bufp->fullBit(oldp+728,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 0x0000000dU)))));
    bufp->fullCData(oldp+729,((0x000000ffU & (IData)(
                                                     (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                                      >> 5U)))),8);
    bufp->fullBit(oldp+730,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 4U)))));
    bufp->fullBit(oldp+731,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 3U)))));
    bufp->fullBit(oldp+732,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 2U)))));
    bufp->fullBit(oldp+733,((1U & (IData)((vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw 
                                           >> 1U)))));
    bufp->fullBit(oldp+734,((1U & (IData)(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg2hw))));
    bufp->fullBit(oldp+735,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x0000001dU))));
    bufp->fullBit(oldp+736,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x0000001cU))));
    bufp->fullBit(oldp+737,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x0000001bU))));
    bufp->fullBit(oldp+738,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x0000001aU))));
    bufp->fullBit(oldp+739,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x00000019U))));
    bufp->fullBit(oldp+740,((1U & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                   >> 0x00000018U))));
    bufp->fullCData(oldp+741,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                              >> 0x00000010U))),8);
    bufp->fullCData(oldp+742,((0x000000ffU & (vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg 
                                              >> 8U))),8);
    bufp->fullCData(oldp+743,((0x000000ffU & vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__hw2reg)),8);
    bufp->fullBit(oldp+744,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__intg_err_o));
    bufp->fullBit(oldp+745,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we));
    bufp->fullBit(oldp+746,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_re));
    bufp->fullCData(oldp+747,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_addr),5);
    bufp->fullIData(oldp+748,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_wdata),32);
    bufp->fullCData(oldp+749,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_be),4);
    bufp->fullIData(oldp+750,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata),32);
    bufp->fullBit(oldp+751,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_error));
    bufp->fullBit(oldp+752,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addrmiss));
    bufp->fullBit(oldp+753,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wr_err));
    bufp->fullIData(oldp+754,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_rdata_next),32);
    bufp->fullBit(oldp+755,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_err));
    bufp->fullCData(oldp+756,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__reg_we_check),6);
    bufp->fullBit(oldp+757,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__err_q));
    bufp->fullBit(oldp+758,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_we));
    bufp->fullBit(oldp+759,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_qs));
    bufp->fullBit(oldp+760,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_tx_wd));
    bufp->fullBit(oldp+761,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_qs));
    bufp->fullBit(oldp+762,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_rx_wd));
    bufp->fullBit(oldp+763,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_qs));
    bufp->fullBit(oldp+764,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nf_wd));
    bufp->fullBit(oldp+765,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_qs));
    bufp->fullBit(oldp+766,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_slpbk_wd));
    bufp->fullBit(oldp+767,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_qs));
    bufp->fullBit(oldp+768,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_llpbk_wd));
    bufp->fullBit(oldp+769,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_qs));
    bufp->fullBit(oldp+770,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_en_wd));
    bufp->fullBit(oldp+771,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_qs));
    bufp->fullBit(oldp+772,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_parity_odd_wd));
    bufp->fullSData(oldp+773,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_qs),16);
    bufp->fullSData(oldp+774,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__ctrl_nco_wd),16);
    bufp->fullBit(oldp+775,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_re));
    bufp->fullBit(oldp+776,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txfull_qs));
    bufp->fullBit(oldp+777,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxfull_qs));
    bufp->fullBit(oldp+778,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txempty_qs));
    bufp->fullBit(oldp+779,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_txidle_qs));
    bufp->fullBit(oldp+780,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxidle_qs));
    bufp->fullBit(oldp+781,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__status_rxempty_qs));
    bufp->fullBit(oldp+782,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_re));
    bufp->fullCData(oldp+783,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__rdata_qs),8);
    bufp->fullBit(oldp+784,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_we));
    bufp->fullCData(oldp+785,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_wd),8);
    bufp->fullBit(oldp+786,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_we));
    bufp->fullBit(oldp+787,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_rxrst_wd));
    bufp->fullBit(oldp+788,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_txrst_wd));
    bufp->fullBit(oldp+789,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_re));
    bufp->fullCData(oldp+790,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_txlvl_qs),8);
    bufp->fullCData(oldp+791,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_status_rxlvl_qs),8);
    bufp->fullBit(oldp+792,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_qe));
    bufp->fullBit(oldp+793,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__wdata_flds_we));
    bufp->fullBit(oldp+794,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_qe));
    bufp->fullCData(oldp+795,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__fifo_ctrl_flds_we),2);
    bufp->fullCData(oldp+796,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__addr_hit),6);
    bufp->fullBit(oldp+797,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_wdata));
    bufp->fullBit(oldp+798,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__unused_be));
    bufp->fullBit(oldp+799,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__clk_i));
    bufp->fullBit(oldp+800,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__rst_ni));
    bufp->fullBit(oldp+801,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__we));
    bufp->fullBit(oldp+802,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wd));
    bufp->fullBit(oldp+803,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qe));
    bufp->fullBit(oldp+804,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__q));
    bufp->fullBit(oldp+805,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__ds));
    bufp->fullBit(oldp+806,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__qs));
    bufp->fullBit(oldp+807,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en));
    bufp->fullBit(oldp+808,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_data));
    bufp->fullBit(oldp+809,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+810,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+811,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+812,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+813,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+814,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_llpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+815,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__clk_i));
    bufp->fullBit(oldp+816,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__rst_ni));
    bufp->fullBit(oldp+817,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__we));
    bufp->fullSData(oldp+818,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wd),16);
    bufp->fullBit(oldp+819,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qe));
    bufp->fullSData(oldp+820,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__q),16);
    bufp->fullSData(oldp+821,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__ds),16);
    bufp->fullSData(oldp+822,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__qs),16);
    bufp->fullBit(oldp+823,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en));
    bufp->fullSData(oldp+824,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_data),16);
    bufp->fullBit(oldp+825,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__we));
    bufp->fullSData(oldp+826,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wd),16);
    bufp->fullSData(oldp+827,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__q),16);
    bufp->fullBit(oldp+828,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullSData(oldp+829,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__wr_data),16);
    bufp->fullSData(oldp+830,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nco__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),16);
    bufp->fullBit(oldp+831,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__clk_i));
    bufp->fullBit(oldp+832,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__rst_ni));
    bufp->fullBit(oldp+833,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__we));
    bufp->fullBit(oldp+834,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wd));
    bufp->fullBit(oldp+835,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qe));
    bufp->fullBit(oldp+836,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__q));
    bufp->fullBit(oldp+837,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__ds));
    bufp->fullBit(oldp+838,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__qs));
    bufp->fullBit(oldp+839,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en));
    bufp->fullBit(oldp+840,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_data));
    bufp->fullBit(oldp+841,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+842,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+843,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+844,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+845,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+846,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_nf__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+847,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__clk_i));
    bufp->fullBit(oldp+848,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__rst_ni));
    bufp->fullBit(oldp+849,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__we));
    bufp->fullBit(oldp+850,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wd));
    bufp->fullBit(oldp+851,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qe));
    bufp->fullBit(oldp+852,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__q));
    bufp->fullBit(oldp+853,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__ds));
    bufp->fullBit(oldp+854,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__qs));
    bufp->fullBit(oldp+855,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en));
    bufp->fullBit(oldp+856,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_data));
    bufp->fullBit(oldp+857,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+858,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+859,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+860,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+861,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+862,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_en__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+863,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__clk_i));
    bufp->fullBit(oldp+864,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__rst_ni));
    bufp->fullBit(oldp+865,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__we));
    bufp->fullBit(oldp+866,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wd));
    bufp->fullBit(oldp+867,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qe));
    bufp->fullBit(oldp+868,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__q));
    bufp->fullBit(oldp+869,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__ds));
    bufp->fullBit(oldp+870,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__qs));
    bufp->fullBit(oldp+871,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en));
    bufp->fullBit(oldp+872,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_data));
    bufp->fullBit(oldp+873,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+874,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+875,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+876,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+877,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+878,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_parity_odd__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+879,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__clk_i));
    bufp->fullBit(oldp+880,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__rst_ni));
    bufp->fullBit(oldp+881,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__we));
    bufp->fullBit(oldp+882,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wd));
    bufp->fullBit(oldp+883,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qe));
    bufp->fullBit(oldp+884,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__q));
    bufp->fullBit(oldp+885,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__ds));
    bufp->fullBit(oldp+886,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__qs));
    bufp->fullBit(oldp+887,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en));
    bufp->fullBit(oldp+888,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_data));
    bufp->fullBit(oldp+889,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+890,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+891,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+892,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+893,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+894,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_rx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+895,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__clk_i));
    bufp->fullBit(oldp+896,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__rst_ni));
    bufp->fullBit(oldp+897,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__we));
    bufp->fullBit(oldp+898,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wd));
    bufp->fullBit(oldp+899,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qe));
    bufp->fullBit(oldp+900,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__q));
    bufp->fullBit(oldp+901,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__ds));
    bufp->fullBit(oldp+902,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__qs));
    bufp->fullBit(oldp+903,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en));
    bufp->fullBit(oldp+904,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_data));
    bufp->fullBit(oldp+905,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+906,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+907,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+908,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+909,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+910,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_slpbk__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+911,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__clk_i));
    bufp->fullBit(oldp+912,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__rst_ni));
    bufp->fullBit(oldp+913,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__we));
    bufp->fullBit(oldp+914,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wd));
    bufp->fullBit(oldp+915,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qe));
    bufp->fullBit(oldp+916,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__q));
    bufp->fullBit(oldp+917,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__ds));
    bufp->fullBit(oldp+918,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__qs));
    bufp->fullBit(oldp+919,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en));
    bufp->fullBit(oldp+920,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_data));
    bufp->fullBit(oldp+921,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+922,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+923,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+924,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+925,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+926,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_ctrl_tx__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+927,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__clk_i));
    bufp->fullBit(oldp+928,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__rst_ni));
    bufp->fullBit(oldp+929,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__d_i));
    bufp->fullBit(oldp+930,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl0_qe__DOT__q_o));
    bufp->fullBit(oldp+931,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__clk_i));
    bufp->fullBit(oldp+932,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__rst_ni));
    bufp->fullBit(oldp+933,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__we));
    bufp->fullBit(oldp+934,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wd));
    bufp->fullBit(oldp+935,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qe));
    bufp->fullBit(oldp+936,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__q));
    bufp->fullBit(oldp+937,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__ds));
    bufp->fullBit(oldp+938,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__qs));
    bufp->fullBit(oldp+939,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en));
    bufp->fullBit(oldp+940,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_data));
    bufp->fullBit(oldp+941,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+942,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+943,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+944,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+945,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+946,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_rxrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+947,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__clk_i));
    bufp->fullBit(oldp+948,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__rst_ni));
    bufp->fullBit(oldp+949,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__we));
    bufp->fullBit(oldp+950,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wd));
    bufp->fullBit(oldp+951,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qe));
    bufp->fullBit(oldp+952,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__q));
    bufp->fullBit(oldp+953,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__ds));
    bufp->fullBit(oldp+954,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__qs));
    bufp->fullBit(oldp+955,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en));
    bufp->fullBit(oldp+956,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_data));
    bufp->fullBit(oldp+957,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__we));
    bufp->fullBit(oldp+958,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wd));
    bufp->fullBit(oldp+959,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__q));
    bufp->fullBit(oldp+960,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullBit(oldp+961,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__wr_data));
    bufp->fullBit(oldp+962,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_ctrl_txrst__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q));
    bufp->fullBit(oldp+963,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__re));
    bufp->fullCData(oldp+964,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__d),8);
    bufp->fullBit(oldp+965,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qre));
    bufp->fullCData(oldp+966,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__ds),8);
    bufp->fullCData(oldp+967,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_rxlvl__DOT__qs),8);
    bufp->fullBit(oldp+968,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__re));
    bufp->fullCData(oldp+969,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__d),8);
    bufp->fullBit(oldp+970,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qre));
    bufp->fullCData(oldp+971,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__ds),8);
    bufp->fullCData(oldp+972,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_fifo_status_txlvl__DOT__qs),8);
    bufp->fullBit(oldp+973,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__clk_i));
    bufp->fullBit(oldp+974,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__rst_ni));
    bufp->fullCData(oldp+975,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_i),6);
    bufp->fullBit(oldp+976,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__en_i));
    bufp->fullBit(oldp+977,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__err_o));
    bufp->fullCData(oldp+978,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__oh_buf),6);
    bufp->fullCData(oldp+979,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__in_i),6);
    bufp->fullCData(oldp+980,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__out_o),6);
    bufp->fullCData(oldp+981,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_buf__DOT__inv),6);
    bufp->fullBit(oldp+982,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__clk_i));
    bufp->fullBit(oldp+983,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__rst_ni));
    bufp->fullCData(oldp+984,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__oh_i),6);
    bufp->fullBit(oldp+985,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__en_i));
    bufp->fullBit(oldp+986,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_o));
    bufp->fullSData(oldp+987,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__or_tree),15);
    bufp->fullSData(oldp+988,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__and_tree),15);
    bufp->fullSData(oldp+989,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_prim_reg_we_check__DOT__u_prim_onehot_check__DOT__err_tree),15);
    bufp->fullBit(oldp+990,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__re));
    bufp->fullCData(oldp+991,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__d),8);
    bufp->fullBit(oldp+992,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qre));
    bufp->fullCData(oldp+993,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__ds),8);
    bufp->fullCData(oldp+994,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_rdata__DOT__qs),8);
    bufp->fullBit(oldp+995,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__re));
    bufp->fullBit(oldp+996,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__d));
    bufp->fullBit(oldp+997,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qre));
    bufp->fullBit(oldp+998,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__ds));
    bufp->fullBit(oldp+999,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxempty__DOT__qs));
    bufp->fullBit(oldp+1000,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__re));
    bufp->fullBit(oldp+1001,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__d));
    bufp->fullBit(oldp+1002,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qre));
    bufp->fullBit(oldp+1003,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__ds));
    bufp->fullBit(oldp+1004,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxfull__DOT__qs));
    bufp->fullBit(oldp+1005,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__re));
    bufp->fullBit(oldp+1006,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__d));
    bufp->fullBit(oldp+1007,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qre));
    bufp->fullBit(oldp+1008,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__ds));
    bufp->fullBit(oldp+1009,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_rxidle__DOT__qs));
    bufp->fullBit(oldp+1010,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__re));
    bufp->fullBit(oldp+1011,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__d));
    bufp->fullBit(oldp+1012,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qre));
    bufp->fullBit(oldp+1013,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__ds));
    bufp->fullBit(oldp+1014,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txempty__DOT__qs));
    bufp->fullBit(oldp+1015,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__re));
    bufp->fullBit(oldp+1016,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__d));
    bufp->fullBit(oldp+1017,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qre));
    bufp->fullBit(oldp+1018,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__ds));
    bufp->fullBit(oldp+1019,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txfull__DOT__qs));
    bufp->fullBit(oldp+1020,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__re));
    bufp->fullBit(oldp+1021,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__d));
    bufp->fullBit(oldp+1022,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qre));
    bufp->fullBit(oldp+1023,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__ds));
    bufp->fullBit(oldp+1024,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_status_txidle__DOT__qs));
    bufp->fullBit(oldp+1025,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__clk_i));
    bufp->fullBit(oldp+1026,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__rst_ni));
    bufp->fullBit(oldp+1027,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__we));
    bufp->fullCData(oldp+1028,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wd),8);
    bufp->fullBit(oldp+1029,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qe));
    bufp->fullCData(oldp+1030,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__q),8);
    bufp->fullCData(oldp+1031,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__ds),8);
    bufp->fullCData(oldp+1032,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__qs),8);
    bufp->fullBit(oldp+1033,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en));
    bufp->fullCData(oldp+1034,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_data),8);
    bufp->fullBit(oldp+1035,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__we));
    bufp->fullCData(oldp+1036,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wd),8);
    bufp->fullCData(oldp+1037,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__q),8);
    bufp->fullBit(oldp+1038,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_en));
    bufp->fullCData(oldp+1039,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__wr_data),8);
    bufp->fullCData(oldp+1040,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata__DOT__wr_en_data_arb__DOT__gen_w__DOT__unused_q),8);
    bufp->fullBit(oldp+1041,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__clk_i));
    bufp->fullBit(oldp+1042,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__rst_ni));
    bufp->fullBit(oldp+1043,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__d_i));
    bufp->fullBit(oldp+1044,(vlSelfRef.uart_tb__DOT__u_uart__DOT__u_uart_reg__DOT__u_reg_core__DOT__u_wdata0_qe__DOT__q_o));
    Vtop___024root__trace_full_dtype____6(vlSelf, bufp, 1045, vlSymsp->TOP__uart_reg_pkg.UART_PERMIT);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<4>/*127:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000078U, 8))),8);
    bufp->fullCData(oldp+1,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000070U, 8))),8);
    bufp->fullCData(oldp+2,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000068U, 8))),8);
    bufp->fullCData(oldp+3,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000060U, 8))),8);
    bufp->fullCData(oldp+4,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000058U, 8))),8);
    bufp->fullCData(oldp+5,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000050U, 8))),8);
    bufp->fullCData(oldp+6,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000048U, 8))),8);
    bufp->fullCData(oldp+7,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000040U, 8))),8);
    bufp->fullCData(oldp+8,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000038U, 8))),8);
    bufp->fullCData(oldp+9,((0x000000ffU & VL_SEL_IWII(128, 
                                                       __VdtypeVar, 0x00000030U, 8))),8);
    bufp->fullCData(oldp+10,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 0x00000028U, 8))),8);
    bufp->fullCData(oldp+11,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 0x00000020U, 8))),8);
    bufp->fullCData(oldp+12,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 0x00000018U, 8))),8);
    bufp->fullCData(oldp+13,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 0x00000010U, 8))),8);
    bufp->fullCData(oldp+14,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 8U, 8))),8);
    bufp->fullCData(oldp+15,((0x000000ffU & VL_SEL_IWII(128, 
                                                        __VdtypeVar, 0U, 8))),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const QData/*63:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000038U)))),8);
    bufp->fullCData(oldp+1,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000030U)))),8);
    bufp->fullCData(oldp+2,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000028U)))),8);
    bufp->fullCData(oldp+3,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000020U)))),8);
    bufp->fullCData(oldp+4,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000018U)))),8);
    bufp->fullCData(oldp+5,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 0x00000010U)))),8);
    bufp->fullCData(oldp+6,((0x000000ffU & (IData)(
                                                   (__VdtypeVar 
                                                    >> 8U)))),8);
    bufp->fullCData(oldp+7,((0x000000ffU & (IData)(
                                                   __VdtypeVar))),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const SData/*9:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x0000001fU & (__VdtypeVar 
                                            >> 5U))),5);
    bufp->fullCData(oldp+1,((0x0000001fU & __VdtypeVar)),5);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*65:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____3\n"); );
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

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____4(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlWide<3>/*81:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____4\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,((0x0000001fU & VL_SEL_IWII(82, 
                                                       __VdtypeVar, 0x0000004dU, 5))),5);
    bufp->fullIData(oldp+1,(VL_SEL_IWII(82, __VdtypeVar, 0x0000002dU, 32)),32);
    bufp->fullCData(oldp+2,((0x0000000fU & VL_SEL_IWII(82, 
                                                       __VdtypeVar, 0x00000029U, 4))),4);
    bufp->fullCData(oldp+3,((0x0000001fU & VL_SEL_IWII(82, 
                                                       __VdtypeVar, 0x00000024U, 5))),5);
    bufp->fullIData(oldp+4,(VL_SEL_IWII(82, __VdtypeVar, 4U, 32)),32);
    bufp->fullCData(oldp+5,((0x0000000fU & VL_SEL_IWII(82, 
                                                       __VdtypeVar, 0U, 4))),4);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____5(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const CData/*1:0*/& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____5\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullBit(oldp+0,((1U & (__VdtypeVar >> 1U))));
    bufp->fullBit(oldp+1,((1U & __VdtypeVar)));
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____6(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*3:0*/, 6>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____6\n"); );
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
}
