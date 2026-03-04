// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vmy_ip_tb__pch.h"

Vmy_ip_tb__Syms::Vmy_ip_tb__Syms(VerilatedContext* contextp, const char* namep, Vmy_ip_tb* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(464);
    // Setup sub module instances
    TOP____024unit__03a__03atlul_utils__Vclpkg.ctor(this, "$unit::tlul_utils__Vclpkg");
    TOP____024unit.ctor(this, "$unit");
    TOP__my_ip_reg_pkg.ctor(this, "my_ip_reg_pkg");
    TOP__my_ip_tb.ctor(this, "my_ip_tb");
    TOP__my_ip_tb__tl_if.ctor(this, "my_ip_tb.tl_if");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__024unit__03a__03atlul_utils__Vclpkg = &TOP____024unit__03a__03atlul_utils__Vclpkg;
    TOP.__PVT____024unit = &TOP____024unit;
    TOP.__PVT__my_ip_reg_pkg = &TOP__my_ip_reg_pkg;
    TOP.my_ip_tb = &TOP__my_ip_tb;
    TOP__my_ip_tb.tl_if = &TOP__my_ip_tb__tl_if;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit__03a__03atlul_utils__Vclpkg.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    TOP__my_ip_reg_pkg.__Vconfigure(true);
    TOP__my_ip_tb.__Vconfigure(true);
    TOP__my_ip_tb__tl_if.__Vconfigure(true);
    // Setup scopes
    __Vscopep_my_ip_tb__tl_if = new VerilatedScope{this, "my_ip_tb.tl_if", "tl_if", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg = new VerilatedScope{this, "my_ip_tb.u_my_ip.u_my_ip_reg", "u_my_ip_reg", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg__u_reg_if__u_err = new VerilatedScope{this, "my_ip_tb.u_my_ip.u_my_ip_reg.u_reg_if.u_err", "u_err", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_my_ip_tb__tl_if->varInsert("d2h", &(TOP__my_ip_tb__tl_if.d2h), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,65,0);
    __Vscopep_my_ip_tb__tl_if->varInsert("h2d", &(TOP__my_ip_tb__tl_if.h2d), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,108,0);
}

Vmy_ip_tb__Syms::~Vmy_ip_tb__Syms() {
    if (__Vm_dumping) _traceDumpClose();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_my_ip_tb__tl_if, __Vscopep_my_ip_tb__tl_if = nullptr);
    VL_DO_CLEAR(delete __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg, __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg = nullptr);
    VL_DO_CLEAR(delete __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg__u_reg_if__u_err, __Vscopep_my_ip_tb__u_my_ip__u_my_ip_reg__u_reg_if__u_err = nullptr);
    // Tear down sub module instances
    TOP__my_ip_tb__tl_if.dtor();
    TOP__my_ip_tb.dtor();
    TOP__my_ip_reg_pkg.dtor();
    TOP____024unit.dtor();
    TOP____024unit__03a__03atlul_utils__Vclpkg.dtor();
}

void Vmy_ip_tb__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void Vmy_ip_tb__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void Vmy_ip_tb__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
