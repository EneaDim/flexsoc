// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vip1_tb.h for the primary calling header

#include "Vip1_tb__pch.h"

std::string VL_TO_STRING(const Vip1_tb_tlul_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vip1_tb_tlul_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
