// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg.h"
#include "Vspi_host_tb_spi_host_tb.h"

VL_INLINE_OPT VlCoroutine Vspi_host_tb_spi_host_tb___eval_initial__TOP__spi_host_tb__Vtiming__1(Vspi_host_tb_spi_host_tb* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vspi_host_tb_spi_host_tb___eval_initial__TOP__spi_host_tb__Vtiming__1\n"); );
    Vspi_host_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlClassRef<Vspi_host_tb___024unit__03a__03atlul_utils> __PVT__tl_utils_inst;
    // Body
    vlSelfRef.__PVT__rst_ni = 0U;
    vlSelfRef.__PVT__tl_i[0U] = 0U;
    vlSelfRef.__PVT__tl_i[1U] = 0U;
    vlSelfRef.__PVT__tl_i[2U] = 0U;
    vlSelfRef.__PVT__tl_i[3U] = 0U;
    vlSelfRef.__PVT__spi_sdio_i = 0U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x2710ULL, 
                                            nullptr, 
                                            "tb/spi_host_tb.sv", 
                                            75);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    vlSelfRef.__PVT__rst_ni = 1U;
    co_await vlSymsp->TOP.__VdlySched.delay(0x2710ULL, 
                                            nullptr, 
                                            "tb/spi_host_tb.sv", 
                                            77);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    VL_WRITEF_NX("\nRunning...\n\n",0);
    __PVT__tl_utils_inst = VL_NEW(Vspi_host_tb___024unit__03a__03atlul_utils, vlSymsp, (&vlSymsp->TOP__spi_host_tb__tl_if));
    co_await vlSymsp->TOP.__VdlySched.delay(0xf4240ULL, 
                                            nullptr, 
                                            "tb/spi_host_tb.sv", 
                                            83);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    co_await VL_NULL_CHECK(__PVT__tl_utils_inst, "tb/spi_host_tb.sv", 85)->__VnoInFunc_tlul_write(vlSymsp, 0U, 1U, 0U);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    co_await VL_NULL_CHECK(__PVT__tl_utils_inst, "tb/spi_host_tb.sv", 86)->__VnoInFunc_tlul_write(vlSymsp, 4U, 0xfU, 1U);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    co_await vlSymsp->TOP.__VdlySched.delay(0xf4240ULL, 
                                            nullptr, 
                                            "tb/spi_host_tb.sv", 
                                            87);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    co_await VL_NULL_CHECK(__PVT__tl_utils_inst, "tb/spi_host_tb.sv", 89)->__VnoInFunc_tlul_read(vlSymsp, 8U, vlSelfRef.__PVT__read_data, 2U);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    VL_WRITEF_NX("Read data: %x\n",0,32,vlSelfRef.__PVT__read_data);
    co_await vlSymsp->TOP.__VdlySched.delay(0xf4240ULL, 
                                            nullptr, 
                                            "tb/spi_host_tb.sv", 
                                            91);
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
    VL_WRITEF_NX("Coverage: 100%%\n\nEnd.\n\n",0);
    VL_FINISH_MT("tb/spi_host_tb.sv", 100, "");
    vlSymsp->TOP.__Vm_traceActivity[0x1fU] = 1U;
}
