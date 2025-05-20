// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vspi_host__pch.h"
#include "Vspi_host.h"
#include "Vspi_host___024root.h"
#include "Vspi_host_tlul_fifo_sync__RCz6_RDz6.h"

// FUNCTIONS
Vspi_host__Syms::~Vspi_host__Syms()
{
}

Vspi_host__Syms::Vspi_host__Syms(VerilatedContext* contextp, const char* namep, Vspi_host* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[0].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[1].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[2].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[3].fifo_d")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[0].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[1].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[2].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[3].u_hostfifo")}
{
        // Check resources
        Verilated::stackCheck(4593);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vconfigure(true);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vconfigure(false);
}
