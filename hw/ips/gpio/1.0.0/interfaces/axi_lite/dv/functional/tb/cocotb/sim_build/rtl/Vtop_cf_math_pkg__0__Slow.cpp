// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_cf_math_pkg___configure_coverage(Vtop_cf_math_pkg* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vtop_cf_math_pkg___configure_coverage\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverInsert(vlSelf->__Vcoverage + 4, first, true, "/home/eneadim/github/flexsoc/vendor/pulp/common_cells/src/cf_math_pkg.sv", 43, 9, "", "v_line/cf_math_pkg", "block", "43-44", "", "", "", "");
    vlSelf->__vlCoverInsert(vlSymsp->__Vcoverage + 5862, first, false, "/home/eneadim/github/flexsoc/vendor/pulp/common_cells/src/cf_math_pkg.sv", 43, 9, "", "v_line/cf_math_pkg", "block", "43-44", "", "", "", "");
}
