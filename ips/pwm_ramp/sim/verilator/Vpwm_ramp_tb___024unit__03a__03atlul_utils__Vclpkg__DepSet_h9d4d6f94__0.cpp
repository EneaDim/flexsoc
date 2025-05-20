// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_ramp_tb.h for the primary calling header

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb___024unit__03a__03atlul_utils__Vclpkg.h"

std::string VL_TO_STRING(const VlClassRef<Vpwm_ramp_tb___024unit__03a__03atlul_utils>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vpwm_ramp_tb___024unit__03a__03atlul_utils::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vpwm_ramp_tb___024unit__03a__03atlul_utils::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vpwm_ramp_tb___024unit__03a__03atlul_utils::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vpwm_ramp_tb___024unit__03a__03atlul_utils::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vpwm_ramp_tb___024unit__03a__03atlul_utils::to_string_middle\n"); );
    // Body
    std::string out;
    out += "drv_if:" + VL_TO_STRING(__PVT__drv_if);
    return out;
}
