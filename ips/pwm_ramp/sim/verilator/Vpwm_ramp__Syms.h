// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPWM_RAMP__SYMS_H_
#define VERILATED_VPWM_RAMP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpwm_ramp.h"

// INCLUDE MODULE CLASSES
#include "Vpwm_ramp___024root.h"
#include "Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vpwm_ramp__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpwm_ramp* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpwm_ramp___024root            TOP;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    Vpwm_ramp_tlul_fifo_sync__RCz6_RDz6 TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;

    // CONSTRUCTORS
    Vpwm_ramp__Syms(VerilatedContext* contextp, const char* namep, Vpwm_ramp* modelp);
    ~Vpwm_ramp__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
