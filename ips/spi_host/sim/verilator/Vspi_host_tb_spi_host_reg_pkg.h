// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi_host_tb.h for the primary calling header

#ifndef VERILATED_VSPI_HOST_TB_SPI_HOST_REG_PKG_H_
#define VERILATED_VSPI_HOST_TB_SPI_HOST_REG_PKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vspi_host_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi_host_tb_spi_host_reg_pkg final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vspi_host_tb__Syms* const vlSymsp;

    // PARAMETERS
    static constexpr VlUnpacked<CData/*3:0*/, 4> __PVT__SPI_HOST_PERMIT = {{
        0x01U, 0x01U, 0x01U, 0x01U
    }};

    // CONSTRUCTORS
    Vspi_host_tb_spi_host_reg_pkg(Vspi_host_tb__Syms* symsp, const char* v__name);
    ~Vspi_host_tb_spi_host_reg_pkg();
    VL_UNCOPYABLE(Vspi_host_tb_spi_host_reg_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
