// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb_tlul_if.h"

std::string VL_TO_STRING(const Vpwm_ramp_tb_tlul_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vpwm_ramp_tb_tlul_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
