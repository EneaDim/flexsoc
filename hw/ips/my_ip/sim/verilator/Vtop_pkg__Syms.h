// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_PKG__SYMS_H_
#define VERILATED_VTOP_PKG__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_pkg.h"

// INCLUDE MODULE CLASSES
#include "Vtop_pkg___024root.h"
#include "Vtop_pkg_tlul_fifo_sync__RCz9_RDz9.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop_pkg__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_pkg* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtop_pkg___024root             TOP;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vtop_pkg_tlul_fifo_sync__RCz9_RDz9 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // CONSTRUCTORS
    Vtop_pkg__Syms(VerilatedContext* contextp, const char* namep, Vtop_pkg* modelp);
    ~Vtop_pkg__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
