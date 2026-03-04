// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmy_ip_tb.h for the primary calling header

#include "Vmy_ip_tb__pch.h"

std::string VL_TO_STRING(const Vmy_ip_tb_tlul_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vmy_ip_tb_tlul_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->vlNamep : "null");
}
