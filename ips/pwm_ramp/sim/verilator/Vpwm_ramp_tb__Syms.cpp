// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vpwm_ramp_tb__pch.h"
#include "Vpwm_ramp_tb.h"
#include "Vpwm_ramp_tb___024root.h"
#include "Vpwm_ramp_tb_tlul_fifo_sync__RCz6_RDz6.h"

// FUNCTIONS
Vpwm_ramp_tb__Syms::~Vpwm_ramp_tb__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vpwm_ramp_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vpwm_ramp_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vpwm_ramp_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vpwm_ramp_tb__Syms::Vpwm_ramp_tb__Syms(VerilatedContext* contextp, const char* namep, Vpwm_ramp_tb* modelp)
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
        Verilated::stackCheck(4039);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
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
