// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPI_HOST__SYMS_H_
#define VERILATED_VSPI_HOST__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vspi_host.h"

// INCLUDE MODULE CLASSES
#include "Vspi_host___024root.h"
#include "Vspi_host_tlul_fifo_sync__RCz6_RDz6.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vspi_host__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vspi_host* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vspi_host___024root            TOP;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vspi_host_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // CONSTRUCTORS
    Vspi_host__Syms(VerilatedContext* contextp, const char* namep, Vspi_host* modelp);
    ~Vspi_host__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
