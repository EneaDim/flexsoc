// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPI_HOST_TB__SYMS_H_
#define VERILATED_VSPI_HOST_TB__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "Vspi_host_tb.h"

// INCLUDE MODULE CLASSES
#include "Vspi_host_tb___024root.h"
#include "Vspi_host_tb_spi_host_tb.h"
#include "Vspi_host_tb___024unit.h"
#include "Vspi_host_tb_spi_host_reg_pkg.h"
#include "Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6.h"
#include "Vspi_host_tb_tlul_if.h"
#include "Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vspi_host_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vspi_host_tb* const __Vm_modelp;
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vspi_host_tb___024root         TOP;
    Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg TOP____024unit__03a__03atlul_utils__Vclpkg;
    Vspi_host_tb___024unit         TOP____024unit;
    Vspi_host_tb_spi_host_reg_pkg  TOP__spi_host_reg_pkg;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;
    Vspi_host_tb_spi_host_tb       TOP__spi_host_tb;
    Vspi_host_tb_tlul_if           TOP__spi_host_tb__tl_if;

    // SCOPE NAMES
    VerilatedScope __Vscope_spi_host_tb__tl_if;

    // CONSTRUCTORS
    Vspi_host_tb__Syms(VerilatedContext* contextp, const char* namep, Vspi_host_tb* modelp);
    ~Vspi_host_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
