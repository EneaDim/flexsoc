// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip0_tb.h for the primary calling header

#include "Vip0_tb__pch.h"

std::string VL_TO_STRING(const Vip0_tb_tlul_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vip0_tb_tlul_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
