// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vspi_host_tb__pch.h"
#include "Vspi_host_tb.h"
#include "Vspi_host_tb___024root.h"
#include "Vspi_host_tb_spi_host_tb.h"
#include "Vspi_host_tb___024unit.h"
#include "Vspi_host_tb_spi_host_reg_pkg.h"
#include "Vspi_host_tb_tlul_fifo_sync__RCz6_RDz6.h"
#include "Vspi_host_tb_tlul_if.h"
#include "Vspi_host_tb___024unit__03a__03atlul_utils__Vclpkg.h"

// FUNCTIONS
Vspi_host_tb__Syms::~Vspi_host_tb__Syms()
{
#ifdef VM_TRACE
    if (__Vm_dumping) _traceDumpClose();
#endif  // VM_TRACE
}

void Vspi_host_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vspi_host_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vspi_host_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock(__Vm_dumperMutex);
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}

Vspi_host_tb__Syms::Vspi_host_tb__Syms(VerilatedContext* contextp, const char* namep, Vspi_host_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit__03a__03atlul_utils__Vclpkg{this, Verilated::catName(namep, "$unit::tlul_utils__Vclpkg")}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
    , TOP__spi_host_reg_pkg{this, Verilated::catName(namep, "spi_host_reg_pkg")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[0].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[1].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[2].fifo_d")}
    , TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d{this, Verilated::catName(namep, "tlul_socket_1n.gen_dfifo[3].fifo_d")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[0].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[1].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[2].u_hostfifo")}
    , TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo{this, Verilated::catName(namep, "tlul_socket_m1.gen_host_fifo[3].u_hostfifo")}
    , TOP__spi_host_tb{this, Verilated::catName(namep, "spi_host_tb")}
    , TOP__spi_host_tb__tl_if{this, Verilated::catName(namep, "spi_host_tb.tl_if")}
{
        // Check resources
        Verilated::stackCheck(3941);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__024unit__03a__03atlul_utils__Vclpkg = &TOP____024unit__03a__03atlul_utils__Vclpkg;
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.__PVT__spi_host_reg_pkg = &TOP__spi_host_reg_pkg;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d = &TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo;
    TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo = &TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo;
    TOP.spi_host_tb = &TOP__spi_host_tb;
    TOP__spi_host_tb.tl_if = &TOP__spi_host_tb__tl_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit__03a__03atlul_utils__Vclpkg.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__spi_host_reg_pkg.__Vconfigure(true);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vconfigure(true);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vconfigure(false);
    TOP__spi_host_tb.__Vconfigure(true);
    TOP__spi_host_tb__tl_if.__Vconfigure(true);
    // Setup scopes
    __Vscope_spi_host_tb__tl_if.configure(this, name(), "spi_host_tb.tl_if", "tl_if", "<null>", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_spi_host_tb__tl_if.varInsert(__Vfinal,"d2h", &(TOP__spi_host_tb__tl_if.d2h), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,65,0);
        __Vscope_spi_host_tb__tl_if.varInsert(__Vfinal,"h2d", &(TOP__spi_host_tb__tl_if.h2d), false, VLVT_WDATA,VLVD_NODIR|VLVF_PUB_RW,0,1 ,108,0);
    }
}
