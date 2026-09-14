// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_prim_util_pkg___configure_coverage(Vtop_prim_util_pkg* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_prim_util_pkg___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 4, first, true, "/home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv", 34, 5, "", "v_line/prim_util_pkg", "block", "34-35", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 8261, first, false, "/home/eneadim/github/flexsoc/hw/ips/pkgs/prim_util_pkg.sv", 34, 5, "", "v_line/prim_util_pkg", "block", "34-35", "", "", "", "");
}
