// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host_tb.h for the primary calling header

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb__Syms.h"
#include "Vspi_host_tb_spi_host_reg_pkg.h"

// Parameter definitions for Vspi_host_tb_spi_host_reg_pkg
constexpr VlUnpacked<CData/*3:0*/, 4> Vspi_host_tb_spi_host_reg_pkg::__PVT__SPI_HOST_PERMIT;


void Vspi_host_tb_spi_host_reg_pkg___ctor_var_reset(Vspi_host_tb_spi_host_reg_pkg* vlSelf);

Vspi_host_tb_spi_host_reg_pkg::Vspi_host_tb_spi_host_reg_pkg(Vspi_host_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vspi_host_tb_spi_host_reg_pkg___ctor_var_reset(this);
}

void Vspi_host_tb_spi_host_reg_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vspi_host_tb_spi_host_reg_pkg::~Vspi_host_tb_spi_host_reg_pkg() {
}
