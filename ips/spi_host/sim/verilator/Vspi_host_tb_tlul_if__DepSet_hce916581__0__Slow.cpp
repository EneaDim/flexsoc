// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb_tlul_if.h"

VL_ATTR_COLD void Vspi_host_tb_tlul_if___ctor_var_reset(Vspi_host_tb_tlul_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vspi_host_tb_tlul_if___ctor_var_reset\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__PVT__clk_i = VL_RAND_RESET_I(1);
    vlSelf->__PVT__rst_ni = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(109, vlSelf->h2d);
    VL_RAND_RESET_W(66, vlSelf->d2h);
}
