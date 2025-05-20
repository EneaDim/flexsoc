// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb_tlul_if.h"

std::string VL_TO_STRING(const Vspi_host_tb_tlul_if* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vspi_host_tb_tlul_if::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}
