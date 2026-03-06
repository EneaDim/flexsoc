// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip0_tb.h for the primary calling header

#include "Vip0_tb__pch.h"

VL_ATTR_COLD void Vip0_tb_tlul_if___ctor_var_reset(Vip0_tb_tlul_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vip0_tb_tlul_if___ctor_var_reset\n"); );
    Vip0_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__clk_i = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11908517815223722933ull);
    vlSelf->__PVT__rst_ni = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3161515032326629241ull);
    VL_SCOPED_RAND_RESET_W(109, vlSelf->h2d, __VscopeHash, 11460876968636362437ull);
    VL_SCOPED_RAND_RESET_W(66, vlSelf->d2h, __VscopeHash, 18089683219658873148ull);
}
