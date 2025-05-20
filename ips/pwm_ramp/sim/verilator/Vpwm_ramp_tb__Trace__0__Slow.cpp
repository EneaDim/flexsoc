// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vpwm_ramp_tb__Syms.h"


VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("prim_mubi_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->pushPrefix("prim_secded_pkg", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->declBit(c+1405,0,"prim_cdc_rand_delay.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1406,0,"prim_cdc_rand_delay.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1407,0,"prev_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1408,0,"src_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1409,0,"dst_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"prim_fifo_async_simple.clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"prim_fifo_async_simple.rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1412,0,"prim_fifo_async_simple.wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1413,0,"prim_fifo_async_simple.wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1414,0,"prim_fifo_async_simple.wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1415,0,"prim_fifo_async_simple.clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"prim_fifo_async_simple.rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1417,0,"prim_fifo_async_simple.rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1418,0,"prim_fifo_async_simple.rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1419,0,"prim_fifo_async_simple.rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1420,0,"prim_fifo_async_sram_adapter.clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1421,0,"prim_fifo_async_sram_adapter.rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1422,0,"prim_fifo_async_sram_adapter.wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1423,0,"prim_fifo_async_sram_adapter.wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1424,0,"prim_fifo_async_sram_adapter.wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1425,0,"wdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1426,0,"prim_fifo_async_sram_adapter.clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1427,0,"prim_fifo_async_sram_adapter.rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1428,0,"prim_fifo_async_sram_adapter.rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1429,0,"prim_fifo_async_sram_adapter.rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1430,0,"prim_fifo_async_sram_adapter.rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1431,0,"rdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1432,0,"r_full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1433,0,"r_notempty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1434,0,"w_full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1435,0,"w_sram_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1436,0,"w_sram_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1437,0,"w_sram_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1438,0,"w_sram_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1439,0,"w_sram_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1440,0,"w_sram_wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1441,0,"w_sram_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1442,0,"w_sram_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1443,0,"w_sram_rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1444,0,"r_sram_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1445,0,"r_sram_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1446,0,"r_sram_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1447,0,"r_sram_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1448,0,"r_sram_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1449,0,"r_sram_wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1450,0,"r_sram_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1451,0,"r_sram_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1452,0,"r_sram_rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1453,0,"prim_filter.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1454,0,"prim_filter.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1455,0,"prim_filter.enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1456,0,"prim_filter.filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1457,0,"prim_filter.filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1458,0,"prim_filter_ctr.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1459,0,"prim_filter_ctr.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1460,0,"prim_filter_ctr.enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1461,0,"prim_filter_ctr.filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1462,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1463,0,"prim_filter_ctr.filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1464,0,"prim_subreg.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1465,0,"prim_subreg.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1466,0,"prim_subreg.we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1467,0,"prim_subreg.wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1468,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1469,0,"prim_subreg.d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1470,0,"prim_subreg.qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1471,0,"prim_subreg.q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1472,0,"prim_subreg.ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1473,0,"prim_subreg.qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1474,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1475,0,"prim_subreg_ext.we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1476,0,"prim_subreg_ext.wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1477,0,"prim_subreg_ext.d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1478,0,"prim_subreg_ext.qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1479,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1480,0,"prim_subreg_ext.q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1481,0,"prim_subreg_ext.ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1482,0,"prim_subreg_ext.qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1483,0,"sram2tlul.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1484,0,"sram2tlul.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1485,0,"sram2tlul.tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1489,0,"sram2tlul.tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1492,0,"mem_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1493,0,"mem_write_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1494,0,"mem_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1495,0,"mem_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1496,0,"mem_rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1497,0,"mem_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1498,0,"mem_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1499,0,"tlul_adapter_host.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1500,0,"tlul_adapter_host.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1501,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1502,0,"gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1503,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1504,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1505,0,"tlul_adapter_host.wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1506,0,"wdata_intg_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1507,0,"be_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1508,0,"instr_type_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1509,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1510,0,"tlul_adapter_host.rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1511,0,"rdata_intg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1512,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1513,0,"intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1514,0,"tlul_adapter_host.tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1518,0,"tlul_adapter_host.tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1521,0,"tlul_adapter_reg.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1522,0,"tlul_adapter_reg.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1523,0,"tlul_adapter_reg.tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1527,0,"tlul_adapter_reg.tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1530,0,"tlul_adapter_reg.en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1531,0,"tlul_adapter_reg.intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1532,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1533,0,"tlul_adapter_reg.we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1534,0,"tlul_adapter_reg.addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1535,0,"tlul_adapter_reg.wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1536,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1537,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1538,0,"tlul_adapter_reg.rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1539,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1540,0,"tlul_adapter_sram.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"tlul_adapter_sram.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1542,0,"tlul_adapter_sram.tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1546,0,"tlul_adapter_sram.tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1549,0,"tlul_adapter_sram.en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1550,0,"req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1551,0,"req_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1552,0,"gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1553,0,"tlul_adapter_sram.we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1554,0,"tlul_adapter_sram.addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1555,0,"tlul_adapter_sram.wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1556,0,"wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1557,0,"tlul_adapter_sram.intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1558,0,"tlul_adapter_sram.rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1559,0,"rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1560,0,"rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1561,0,"compound_txn_in_progress_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1562,0,"readback_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1563,0,"readback_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1564,0,"wr_collision_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1565,0,"write_pending_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1566,0,"tlul_assert_multiple.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1567,0,"tlul_assert_multiple.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1568,0,"h2d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 217,0);
    tracep->declArray(c+1575,0,"d2h",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 131,0);
    tracep->declBit(c+1580,0,"clk_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_h_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1582,0,"clk_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_d_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1584,0,"tlul_fifo_async.tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1588,0,"tlul_fifo_async.tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1591,0,"tlul_fifo_async.tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1595,0,"tlul_fifo_async.tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1598,0,"tlul_socket_1n.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"tlul_socket_1n.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1600,0,"tlul_socket_1n.tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1604,0,"tlul_socket_1n.tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1607,0,"tlul_socket_1n.tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->declArray(c+1621,0,"tlul_socket_1n.tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 263,0);
    tracep->declBus(c+1630,0,"dev_select_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1631,0,"tlul_socket_m1.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"tlul_socket_m1.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1633,0,"tlul_socket_m1.tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->declArray(c+1647,0,"tlul_socket_m1.tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 263,0);
    tracep->declArray(c+1656,0,"tlul_socket_m1.tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1660,0,"tlul_socket_m1.tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1663,0,"multiple_pwm_ramp.clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"multiple_pwm_ramp.rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"multiple_pwm_ramp.enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1666,0,"step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1667,0,"lvds_0_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1668,0,"lvds_1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1669,0,"pwm_0_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1670,0,"pwm_1_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1671,0,"adc_value_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1672,0,"adc_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("multiple_pwm_ramp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1843,0,"NBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1666,0,"step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1667,0,"lvds_0_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1668,0,"lvds_1_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1669,0,"pwm_0_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1670,0,"pwm_1_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1671,0,"adc_value_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1672,0,"adc_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1844,0,"MAX_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"HNBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+657,0,"adc_value_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+658,0,"adc_value_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+659,0,"adc_valid_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+660,0,"adc_valid_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1846,0,"lvds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1847,0,"lvds_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_pwm_ramp_0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1843,0,"NBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1848,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"reverse_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1850,0,"step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1667,0,"lvds_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1669,0,"pwm_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+657,0,"adc_value_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+659,0,"adc_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1844,0,"MAX_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+661,0,"duty_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+662,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+663,0,"clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1669,0,"pwm_drive_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"lvds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"lvds_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+666,0,"f_edge_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_prim_deglitch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1851,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1667,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"COUNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+667,0,"count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+668,0,"d_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_async", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1667,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+668,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1856,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+669,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1667,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+669,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+669,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+668,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_prim_edge_detect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+664,0,"serial_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+665,0,"r_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+666,0,"f_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+670,0,"serial_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+664,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+670,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_pwm_ramp_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1843,0,"NBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1857,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"reverse_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1850,0,"step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+1668,0,"lvds_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1670,0,"pwm_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+658,0,"adc_value_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+660,0,"adc_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1844,0,"MAX_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+671,0,"duty_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+672,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+673,0,"clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1670,0,"pwm_drive_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+674,0,"lvds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+675,0,"lvds_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+676,0,"f_edge_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_prim_deglitch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1851,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1668,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+674,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"COUNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+677,0,"count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+678,0,"d_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_async", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1668,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+678,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1858,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+679,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1668,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+679,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+679,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+678,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_prim_edge_detect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1665,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+674,0,"serial_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+675,0,"r_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+676,0,"f_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+680,0,"serial_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1663,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1664,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+674,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+680,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("prim_cdc_rand_delay", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1405,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1406,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1407,0,"prev_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1408,0,"src_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1409,0,"dst_data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("prim_fifo_async_simple", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1859,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"EnRstChks",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnRzHs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1412,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1413,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1414,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+1415,0,"clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1417,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1418,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1419,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+345,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"src_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1078,0,"src_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+347,0,"pending_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1079,0,"pending_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1080,0,"not_in_reset_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1279,0,"dst_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1673,0,"dst_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1674,0,"data_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("u_prim_sync_reqack", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnRstChks",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnRzHs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"clk_src_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"rst_src_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1415,0,"clk_dst_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"rst_dst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"req_chk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+346,0,"src_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1078,0,"src_ack_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1279,0,"dst_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1673,0,"dst_ack_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"unused_req_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"effective_rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1675,0,"chk_flag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_nrz_hs_protocol", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+348,0,"src_fsm_ns",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1081,0,"src_fsm_cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1676,0,"dst_fsm_ns",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1280,0,"dst_fsm_cs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1677,0,"src_req_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1678,0,"src_req_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1082,0,"src_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1679,0,"dst_ack_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1281,0,"dst_ack_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1282,0,"dst_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+349,0,"src_handshake",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1680,0,"dst_handshake",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("ack_sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1281,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1082,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1281,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1083,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1281,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1083,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1410,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1411,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1083,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1082,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("req_sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1415,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1678,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1282,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1678,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1283,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1415,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1678,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1283,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1415,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1416,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1283,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1282,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("prim_fifo_async_sram_adapter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1860,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1859,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1859,0,"SramAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1860,0,"SramDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1861,0,"SramBaseAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1862,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1420,0,"clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1421,0,"rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1422,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1423,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1424,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1425,0,"wdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1426,0,"clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1427,0,"rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1428,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1429,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1430,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1431,0,"rdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1432,0,"r_full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1433,0,"r_notempty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1434,0,"w_full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1435,0,"w_sram_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1436,0,"w_sram_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1437,0,"w_sram_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1438,0,"w_sram_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1439,0,"w_sram_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1440,0,"w_sram_wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1441,0,"w_sram_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1442,0,"w_sram_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1443,0,"w_sram_rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1444,0,"r_sram_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1445,0,"r_sram_gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1446,0,"r_sram_write_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1447,0,"r_sram_addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1448,0,"r_sram_wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1449,0,"r_sram_wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1450,0,"r_sram_rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1451,0,"r_sram_rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1452,0,"r_sram_rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1863,0,"PtrVW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1862,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1319,0,"w_wptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1320,0,"w_wptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1321,0,"w_wptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1322,0,"w_wptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+681,0,"r_wptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+682,0,"r_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1323,0,"w_wptr_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+683,0,"r_wptr_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1324,0,"w_wptr_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+684,0,"r_wptr_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+685,0,"r_rptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+686,0,"r_rptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1681,0,"r_rptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1682,0,"r_rptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1325,0,"w_rptr_gray",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1326,0,"w_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+687,0,"r_rptr_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1327,0,"w_rptr_v",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+688,0,"r_rptr_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1328,0,"w_rptr_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1683,0,"w_wptr_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1684,0,"r_rptr_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1434,0,"w_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1432,0,"r_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+689,0,"r_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+690,0,"stored",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+691,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,0,"rdata_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1685,0,"r_sram_rptr_inc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+692,0,"r_sram_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+693,0,"r_sramrptr_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1684,0,"rfifo_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1685,0,"rsram_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1864,0,"XorMask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+689,0,"unused_r_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1686,0,"unused_w_sram",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1687,0,"unused_rsram",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1688,0,"store_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_rptr_gray", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1420,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1421,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1682,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1325,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1682,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1329,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1420,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1421,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1682,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1329,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1420,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1421,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1329,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1325,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_wptr_gray", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1426,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1427,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1322,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+681,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1322,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+694,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1426,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1427,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1322,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+694,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1865,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1866,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1426,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1427,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+694,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+681,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("prim_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1863,0,"Cycles",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1453,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1454,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1455,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1456,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1457,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1069,0,"stored_vector_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1689,0,"stored_vector_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1070,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1690,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1071,0,"unused_stored_vector_q_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1456,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("prim_filter_ctr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1853,0,"CntWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1458,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1459,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1460,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1461,0,"filter_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1462,0,"thresh_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1463,0,"filter_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1072,0,"diff_ctr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1691,0,"diff_ctr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1073,0,"filter_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1074,0,"stored_value_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1692,0,"update_stored_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1461,0,"filter_synced",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("prim_subreg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1867,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1869,0,"RESVAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1464,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1465,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1466,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1467,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1468,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1469,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1470,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1471,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1472,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1473,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1470,0,"wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"wr_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("wr_en_data_arb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1867,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"SwAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1855,0,"Mubi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1466,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1467,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1468,0,"de",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1469,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1471,0,"q",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1470,0,"wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"wr_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1870,0,"prim_mubi_pkg_MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1871,0,"prim_mubi_pkg_MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"prim_mubi_pkg_MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("gen_w", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1471,0,"unused_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("prim_subreg_ext", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1860,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1474,0,"re",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1475,0,"we",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1476,0,"wd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1477,0,"d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1478,0,"qe",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1479,0,"qre",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1480,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1481,0,"ds",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1482,0,"qs",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("pwm_ramp_tb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1873,0,"CLK_PERIOD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1874,0,"NBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"SAR_SEARCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"enable_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"reverse_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"step_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1694,0,"pwm_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+639,0,"adc_value_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+640,0,"adc_valid_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1875,0,"error_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declDouble(c+1876,0,"LSB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+13,0,"analog_input",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+641,0,"adc_value_ana",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+1695,0,"lvds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declDouble(c+643,0,"filtered_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->pushPrefix("lvds_inst", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+643,0,"lp",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+13,0,"ln",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+1695,0,"lvds_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_pwm_ramp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1874,0,"NBITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1878,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"enable_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"reverse_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"step_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+1695,0,"lvds_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1694,0,"pwm_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+639,0,"adc_value_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+640,0,"adc_valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1879,0,"MAX_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+645,0,"duty_cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+646,0,"counter",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+647,0,"clear",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1694,0,"pwm_drive_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+648,0,"lvds",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+649,0,"lvds_rise",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+650,0,"f_edge_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_prim_deglitch", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1851,0,"AsyncOn",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"SIZE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1695,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+648,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"COUNT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+651,0,"count_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+652,0,"d_s",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_async", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("prim_flop_2sync", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1695,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+652,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1880,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+653,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1695,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+653,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+653,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+652,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_prim_edge_detect", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+648,0,"serial_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+649,0,"r_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+650,0,"f_edge_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+654,0,"serial_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+648,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+654,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rc_filter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+1881,0,"ALPHA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+1883,0,"VDD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBit(c+1693,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+9,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1694,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declDouble(c+643,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+655,0,"y_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sram2tlul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1870,0,"SramAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"SramDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1869,0,"TlBaseAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1483,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1484,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1485,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1489,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1492,0,"mem_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1493,0,"mem_write_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1494,0,"mem_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1495,0,"mem_wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1496,0,"mem_rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1497,0,"mem_rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1498,0,"mem_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1853,0,"SRAM_DWB",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("tlul_adapter_host", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1853,0,"MAX_REQS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"EnableCmdIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableRspIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableRspDataIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1499,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1500,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1501,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1502,0,"gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1503,0,"addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1504,0,"we_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1505,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1506,0,"wdata_intg_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1507,0,"be_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1508,0,"instr_type_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1509,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1510,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1511,0,"rdata_intg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1512,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1513,0,"intg_err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1514,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1518,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1885,0,"WordSize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1075,0,"tl_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1696,0,"tl_be",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+335,0,"tl_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+1849,0,"intg_err_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"intg_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1697,0,"unused_addr_bottom_bits",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1698,0,"unused_tl_i_fields",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1885,0,"OutstandingReqCntW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1886,0,"OutstandingReqCntOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1076,0,"outstanding_reqs_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+339,0,"outstanding_reqs_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("g_multiple_reqs", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"ReqNumW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"MaxSource",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"ReqNumOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+340,0,"source_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1077,0,"source_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_rsp_intg_check", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1849,0,"sv2v_tmp_E222D",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,1);
    tracep->popPrefix();
    tracep->pushPrefix("u_cmd_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnableCmdIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+335,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1514,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+341,0,"cmd_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1888,0,"tlul_pkg_H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"data_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+344,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_adapter_reg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1843,0,"RegAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"RegDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1875,0,"AccessLatency",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"RegBw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1521,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1522,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1523,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1527,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1530,0,"en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1531,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1532,0,"re_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1533,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1534,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1535,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1536,0,"be_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1537,0,"busy_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1538,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1539,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1843,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1386,0,"outstanding_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+350,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1699,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1387,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1387,0,"rdata_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1388,0,"error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1388,0,"error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"err_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+351,0,"addr_align_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"malformed_meta_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1700,0,"tl_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1389,0,"reqid_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1390,0,"reqsz_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1391,0,"rspop_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+352,0,"rd_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+353,0,"wr_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+354,0,"tl_o_pre",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->pushPrefix("u_err", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1521,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1522,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1523,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+1700,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1843,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1701,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1702,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1703,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1704,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1705,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+24,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1889,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1706,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+354,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1527,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1888,0,"tlul_pkg_D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+357,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_passthrough_rsp_intg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+354,0,"sv2v_tmp_48555",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 66,1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_adapter_sram", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1870,0,"SramAw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"SramDw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"Outstanding",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1870,0,"SramBusBankAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"ByteAccess",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"ErrOnWrite",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"ErrOnRead",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"CmdIntgCheck",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgPt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"SecFifoPtr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableReadback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"DataXorAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"WidthMult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"IntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"DataOutW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1542,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1546,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1549,0,"en_ifetch_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1550,0,"req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1551,0,"req_type_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1552,0,"gnt_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1553,0,"we_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1554,0,"addr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1555,0,"wdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1556,0,"wmask_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1557,0,"intg_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1558,0,"rdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1559,0,"rvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1560,0,"rerror_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1561,0,"compound_txn_in_progress_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1562,0,"readback_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1563,0,"readback_error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1564,0,"wr_collision_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1565,0,"write_pending_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"SramByte",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"DataBitWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"WoffsetWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+25,0,"error_det",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"error_internal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"wr_attr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"instr_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"wr_vld_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"rd_vld_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"rsp_fifo_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"sramreqfifo_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"reqfifo_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"intg_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1707,0,"tlul_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"readback_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"sram_byte_readback_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1890,0,"readback_error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+727,0,"intg_error_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1542,0,"tl_i_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+619,0,"tl_o_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+619,0,"tl_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+1708,0,"unused_tl_i_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1865,0,"SramReqFifoWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1891,0,"ReqFifoWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1892,0,"RspFifoWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1709,0,"reqfifo_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+728,0,"reqfifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+729,0,"reqfifo_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+622,0,"reqfifo_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"reqfifo_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+1400,0,"reqfifo_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBit(c+1710,0,"sramreqfifo_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+730,0,"sramreqfifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"sramreqfifo_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"sramreqfifo_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1401,0,"sramreqfifo_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+1893,0,"sramreqaddrfifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1711,0,"sramreqaddrfifo_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBus(c+1894,0,"sramreqaddrfifo_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->declBit(c+109,0,"rspfifo_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+731,0,"rspfifo_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"rspfifo_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+623,0,"rspfifo_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+624,0,"rspfifo_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+626,0,"rspfifo_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+1709,0,"a_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+622,0,"d_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1712,0,"sram_ack",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+628,0,"d_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+629,0,"d_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+630,0,"vld_rd_rsp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1402,0,"error_blanking_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1895,0,"tlul_pkg_DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1869,0,"tlul_pkg_DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"unused_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"unused_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"error_instr_integ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+4,0,"error_data_integ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1403,0,"error_blanking_integ",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+631,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+632,0,"data_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1896,0,"prim_secded_pkg_SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBit(c+1713,0,"missed_err_gnt_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+732,0,"missed_err_gnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1890,0,"woffset",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1867,0,"DataWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"wmask_combined",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"wdata_combined",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"wmask_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"wdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"wmask_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+32,0,"wdata_intg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+1558,0,"rdata_reshaped",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1714,0,"rdata_tlword",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+1897,0,"prim_secded_pkg_SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBit(c+1715,0,"unused_rerror",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_no_data_xor_addr_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1716,0,"unused_sramreqaddrfifo",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_no_readback_check", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1849,0,"unused_sram_byte_readback_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1890,0,"sv2v_tmp_EC2B7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_rmask", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1404,0,"rmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1714,0,"sv2v_tmp_44C61",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 32,1);
    tracep->pushPrefix("sv2v_autoblock_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1872,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_write_output[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("gen_ft_output", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+33,0,"unused_w",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sv2v_autoblock_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+34,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_err", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1542,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+1707,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1843,0,"IW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"MW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"SubAW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1717,0,"opcode_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1718,0,"a_config_allowed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1719,0,"op_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1720,0,"op_partial",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1721,0,"op_get",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"instr_wr_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+36,0,"instr_type_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"addr_sz_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+38,0,"mask_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+39,0,"fulldata_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1889,0,"MaskOne",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1722,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1899,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1709,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+728,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBit(c+729,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+622,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1400,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBit(c+733,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+734,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+735,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+736,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+633,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+634,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+738,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1392,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+1392,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+1392,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+739,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+633,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+634,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+735,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+736,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+733,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+737,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+734,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+740,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+741,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+742,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+743,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+744,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+745,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1723,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1724,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rsp_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+619,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1546,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1888,0,"tlul_pkg_D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+635,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_passthrough_rsp_intg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+619,0,"sv2v_tmp_48555",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 66,1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1900,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+731,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+624,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+110,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+623,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+626,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+746,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+747,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+748,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+749,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+636,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+637,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+750,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+751,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+111,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1393,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+1393,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+1725,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+752,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+636,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+637,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+748,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+749,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+746,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+750,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+747,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+753,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+754,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+755,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+756,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+757,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+758,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1727,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1728,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sram_byte", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnableIntg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"Outstanding",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"EnableReadback",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1542,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+619,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1542,0,"tl_sram_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+619,0,"tl_sram_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+25,0,"error_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"error_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"alert_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1561,0,"compound_txn_in_progress_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1562,0,"readback_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1564,0,"wr_collision_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1565,0,"write_pending_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1843,0,"StateWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1565,0,"unused_write_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1564,0,"unused_wr_collision",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_no_integ_handling", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+1542,0,"sv2v_tmp_3714C",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 109,1);
    tracep->declArray(c+619,0,"sv2v_tmp_EF4AC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 66,1);
    tracep->declBus(c+1849,0,"sv2v_tmp_C54BC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,1);
    tracep->declBus(c+1562,0,"unused_readback_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_sramreqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1862,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1710,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+730,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+759,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1401,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+760,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+761,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+762,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+763,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+638,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+765,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1395,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1395,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+1395,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+766,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1540,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1541,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+638,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+112,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+762,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+763,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+760,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+764,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+761,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+767,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+768,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+769,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+770,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+771,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+772,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1729,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+113,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_tlul_data_integ_enc_data", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1895,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+5,0,"data_intg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->pushPrefix("u_data_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1895,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+5,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_tlul_data_integ_enc_instr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1869,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+7,0,"data_intg_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->pushPrefix("u_data_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1869,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+7,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_assert_multiple", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1853,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+1901,0,"EndpointType",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+1566,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1567,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1568,0,"h2d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 217,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1575,0,"d2h",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 131,0);
    tracep->pushPrefix("gen_assert[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tlul_assert", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declQuad(c+1901,0,"EndpointType",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+1566,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1567,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1730,0,"h2d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1734,0,"d2h",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1119,0,"pend_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2559,0);
    tracep->declBit(c+1065,0,"disable_sva",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1066,0,"disable_d_error_sva",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1737,0,"d_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+41,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+43,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_assert[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("tlul_assert", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declQuad(c+1901,0,"EndpointType",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+1566,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1567,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1738,0,"h2d",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1742,0,"d2h",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1199,0,"pend_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2559,0);
    tracep->declBit(c+1067,0,"disable_sva",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1068,0,"disable_d_error_sva",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"a_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1745,0,"d_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declQuad(c+46,0,"a_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+48,0,"d_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_fifo_async", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1863,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1863,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1580,0,"clk_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_h_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1582,0,"clk_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_d_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1584,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1588,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1591,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1595,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1903,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1904,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1903,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1863,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"OutputZeroIfInvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1580,0,"clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1746,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1330,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1747,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 106,0);
    tracep->declBus(c+1331,0,"wdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1582,0,"clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1356,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1751,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+711,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 106,0);
    tracep->declBus(c+1357,0,"rdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1853,0,"PTRV_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1852,0,"PTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1332,0,"fifo_wptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1333,0,"fifo_wptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1358,0,"fifo_rptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1359,0,"fifo_rptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1360,0,"fifo_wptr_sync_combi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1334,0,"fifo_rptr_sync_combi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1361,0,"fifo_wptr_gray_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1335,0,"fifo_rptr_gray_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1336,0,"fifo_rptr_sync_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1396,0,"fifo_wptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1397,0,"fifo_wptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1362,0,"fifo_rptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1363,0,"fifo_rptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1752,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1753,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1337,0,"full_wclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1364,0,"full_rclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1365,0,"empty_rclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("storage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+695+i*4,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 106,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1905,0,"xor_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+715,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 106,0);
    tracep->pushPrefix("g_depth_calc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1338,0,"wptr_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1339,0,"rptr_sync_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1340,0,"wptr_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1341,0,"rptr_sync_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1366,0,"rptr_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1367,0,"wptr_sync_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1368,0,"rptr_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1369,0,"wptr_sync_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("sync_rptr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1362,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1335,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1362,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1342,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1362,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1342,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1342,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1335,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sync_wptr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1396,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1361,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1396,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1370,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1396,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1370,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1370,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1361,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1904,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1863,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"OutputZeroIfInvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1582,0,"clk_wr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_wr_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1754,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1371,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1755,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1372,0,"wdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1580,0,"clk_rd_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_rd_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1343,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1757,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+1758,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1344,0,"rdepth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1853,0,"PTRV_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1852,0,"PTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1373,0,"fifo_wptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1374,0,"fifo_wptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1345,0,"fifo_rptr_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1346,0,"fifo_rptr_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1347,0,"fifo_wptr_sync_combi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1375,0,"fifo_rptr_sync_combi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1348,0,"fifo_wptr_gray_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1376,0,"fifo_rptr_gray_sync",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1377,0,"fifo_rptr_sync_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1378,0,"fifo_wptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1379,0,"fifo_wptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1398,0,"fifo_rptr_gray_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1399,0,"fifo_rptr_gray_d",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1760,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1761,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1380,0,"full_wclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1349,0,"full_rclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1350,0,"empty_rclk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("storage", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declQuad(c+719+i*2,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 63,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+1905,0,"xor_mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declQuad(c+1762,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->pushPrefix("g_depth_calc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1381,0,"wptr_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1382,0,"rptr_sync_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1383,0,"wptr_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1384,0,"rptr_sync_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1351,0,"rptr_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1352,0,"wptr_sync_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1353,0,"rptr_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1354,0,"wptr_sync_value",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("sync_rptr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1398,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1376,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1398,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1385,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1398,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1385,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1582,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1583,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1385,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1376,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sync_wptr", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1851,0,"EnablePrimCdcRand",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1378,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1348,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1378,0,"d_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1355,0,"intq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1851,0,"unused_sig",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_sync_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1378,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1355,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_sync_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1868,0,"ResetValue",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+1580,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1581,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1355,0,"d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1348,0,"q_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_socket_1n", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1863,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"HReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"HRspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1907,0,"DReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1907,0,"DRspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1889,0,"HReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1889,0,"HRspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1908,0,"DReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1908,0,"DRspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1851,0,"ExplicitErrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1852,0,"NWD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1600,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1604,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1607,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->declArray(c+1621,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 263,0);
    tracep->declBus(c+1630,0,"dev_select_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+358,0,"dev_select_t",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declArray(c+359,0,"tl_t_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+363,0,"tl_t_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1909,0,"MaxOutstanding",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1910,0,"OutstandingW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+773,0,"num_req_outstanding",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+774,0,"dev_select_outstanding",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+366,0,"hold_all_requests",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+367,0,"accept_t_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+368,0,"accept_t_rsp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("tl_u_o", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declArray(c+369+i*4,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 108,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("tl_u_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 5; ++i) {
        tracep->declArray(c+183+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 65,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+389,0,"blanked_auser",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+1895,0,"tlul_pkg_BlankedAData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1888,0,"tlul_pkg_H2DCmdMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+390,0,"tl_t_p",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+393,0,"hfifo_reqready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("fifo_h", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1852,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1600,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1604,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+359,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+363,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1630,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+358,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+124,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1911,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1911,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1764,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+775,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+50,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 109,0);
    tracep->declBit(c+114,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+394,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+395,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 109,0);
    tracep->declBit(c+776,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+777,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+778,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+779,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+399,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+781,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+115,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1084,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 109,0);
    tracep->declArray(c+1084,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 109,0);
    tracep->declArray(c+1765,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 109,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+782,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+399,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+400,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+778,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+779,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+776,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+780,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+777,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+783,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+784,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+785,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+786,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+787,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+788,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+198,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+199,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+789,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+402,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+405,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1769,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+125,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+790,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+792,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+793,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+406,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+794,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+795,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+408,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1088,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1088,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+128,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+796,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+406,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+407,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+792,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+793,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+790,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+794,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+791,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+797,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+798,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+799,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+800,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+801,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+802,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+200,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+201,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_dfifo[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fifo_d", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_dfifo[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fifo_d", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_dfifo[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1885,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fifo_d", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_dfifo[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("fifo_d", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_err_resp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("err_resp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+409,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+803,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+806,0,"err_opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+807,0,"err_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+808,0,"err_size",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+809,0,"err_rsp_pending",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+810,0,"err_instr_type",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+803,0,"tl_h_o_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1895,0,"tlul_pkg_DataWhenError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1869,0,"tlul_pkg_DataWhenInstrError",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+413,0,"unused_tl_h",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_intg_gen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1855,0,"EnableRspIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"EnableDataIntgGen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+803,0,"tl_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+803,0,"tl_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1888,0,"tlul_pkg_D2HRspMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"tlul_pkg_DataMaxWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+811,0,"unused_tl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_passthrough_rsp_intg", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declArray(c+803,0,"sv2v_tmp_48555",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 66,1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_u_o[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+414,0,"dev_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_u_o[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+415,0,"dev_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_u_o[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1885,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"dev_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("gen_u_o[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+417,0,"dev_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("sv2v_autoblock_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1872,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("sv2v_autoblock_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1872,0,"idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("tlul_socket_m1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1863,0,"M",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1907,0,"HReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1907,0,"HRspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1908,0,"HReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1908,0,"HRspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1851,0,"DReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"DRspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1889,0,"DReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+1889,0,"DRspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1633,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1647,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 263,0);
    tracep->declArray(c+1656,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1660,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1913,0,"IDW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1853,0,"STIDW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+482,0,"hreq_fifo_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->pushPrefix("hrsp_fifo_i", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 4; ++i) {
        tracep->declArray(c+496+i*3,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 65,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+508,0,"hrequest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+509,0,"hgrant",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+510,0,"dreq_fifo_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+514,0,"drsp_fifo_o",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBit(c+517,0,"arb_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+924,0,"arb_ready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+518,0,"arb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1914,0,"tlul_pkg_ArbiterImpl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+522,0,"hfifo_rspvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+313,0,"dfifo_rspready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+523,0,"hfifo_rspid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+314,0,"dfifo_rspready_merged",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_arb_ppc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("u_reqarb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1863,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1915,0,"DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"EnDataPort",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1885,0,"IdxW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"req_chk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+508,0,"req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declArray(c+482,0,"data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 435,0);
    tracep->declBus(c+509,0,"gnt_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+524,0,"idx_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+517,0,"valid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+518,0,"data_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBit(c+924,0,"ready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"unused_req_chk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_case", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+525,0,"masked_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+526,0,"ppc_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+527,0,"arb_req",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+925,0,"mask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+528,0,"mask_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+529,0,"winner",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->pushPrefix("gen_datapath", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("sv2v_autoblock_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1872,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("sv2v_autoblock_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1872,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("sv2v_autoblock_3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+530,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_arbreqgnt[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_arbreqgnt[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_arbreqgnt[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1885,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_arbreqgnt[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_host_fifo[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+54,0,"hreq_fifo_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1916,0,"reqid_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1770,0,"shifted_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1771,0,"unused_tl_h_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,6);
    tracep->pushPrefix("u_hostfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_host_fifo[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+58,0,"hreq_fifo_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1886,0,"reqid_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1772,0,"shifted_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1773,0,"unused_tl_h_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,6);
    tracep->pushPrefix("u_hostfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_host_fifo[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1885,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+62,0,"hreq_fifo_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1917,0,"reqid_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1774,0,"shifted_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1775,0,"unused_tl_h_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,6);
    tracep->pushPrefix("u_hostfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_host_fifo[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+66,0,"hreq_fifo_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1918,0,"reqid_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1776,0,"shifted_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+1777,0,"unused_tl_h_source",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,6);
    tracep->pushPrefix("u_hostfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(vlSelf, tracep);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("gen_idrouting[0]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1875,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_idrouting[1]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1854,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_idrouting[2]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1885,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("gen_idrouting[3]", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1906,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_devicefifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+510,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+514,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+1656,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1660,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+264,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+531,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+532,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+924,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+533,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+537,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1778,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+265,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+926,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+927,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+928,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+929,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+538,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+539,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+930,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+931,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+540,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1284,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1284,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+269,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+932,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+538,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+539,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+928,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+929,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+926,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+930,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+927,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+933,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+934,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+935,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+936,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+937,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+938,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1779,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+939,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+70,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+218,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+541,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+542,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+940,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+941,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+942,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+943,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+545,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+546,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+944,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+945,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+219,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1288,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1288,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1780,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+946,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+545,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+546,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+942,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+943,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+940,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+944,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+941,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+947,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+948,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+949,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+950,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+951,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+952,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+318,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_mubi_pkg__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1920,0,"MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1921,0,"MuBi8Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1922,0,"MuBi12Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1923,0,"MuBi16Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1924,0,"MuBi20Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1925,0,"MuBi24Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1926,0,"MuBi28Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+1927,0,"MuBi32Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INT, false,-1, 31,0);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__prim_secded_pkg__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1878,0,"Secded2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1928,0,"Secded2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1878,0,"Secded2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1929,0,"Secded2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+1930,0,"Secded3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1931,0,"Secded3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1930,0,"Secded6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1933,0,"Secded6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1848,0,"Secded7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1935,0,"Secded7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1878,0,"SecdedHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1928,0,"SecdedHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1930,0,"SecdedHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1931,0,"SecdedHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1848,0,"SecdedHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1935,0,"SecdedHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1848,0,"SecdedHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1938,0,"SecdedHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
    tracep->declBus(c+1941,0,"SecdedInv2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1942,0,"SecdedInv2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1941,0,"SecdedInv2822ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1943,0,"SecdedInv2822ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 27,0);
    tracep->declBus(c+1896,0,"SecdedInv3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1897,0,"SecdedInv3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1896,0,"SecdedInv6457ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1944,0,"SecdedInv6457ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declBus(c+1946,0,"SecdedInv7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1947,0,"SecdedInv7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1941,0,"SecdedInvHamming2216ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+1942,0,"SecdedInvHamming2216ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 21,0);
    tracep->declBus(c+1896,0,"SecdedInvHamming3932ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declQuad(c+1897,0,"SecdedInvHamming3932ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 38,0);
    tracep->declBus(c+1946,0,"SecdedInvHamming7264ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1947,0,"SecdedInvHamming7264ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 71,0);
    tracep->declBus(c+1946,0,"SecdedInvHamming7668ZeroEcc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declArray(c+1950,0,"SecdedInvHamming7668ZeroWord",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 75,0);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+418,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1783,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+131,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1786,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+135,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1789,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+422,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+812,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+423,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+427,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1790,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+136,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+813,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+814,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+815,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+816,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+428,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+429,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+817,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+818,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+430,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1091,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1091,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+140,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+819,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+428,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+429,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+815,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+816,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+813,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+817,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+814,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+820,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+821,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+822,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+823,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+824,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+825,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+202,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+203,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1791,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+826,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+73,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+116,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+431,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1792,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+827,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+828,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+829,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+830,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+432,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+433,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+832,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+117,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1095,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1095,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1795,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+833,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+432,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+433,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+829,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+830,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+827,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+831,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+828,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+834,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+835,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+836,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+837,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+838,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+839,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+204,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+205,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+434,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1798,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+144,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1801,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+148,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1804,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+438,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+840,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+439,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+443,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1805,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+149,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+841,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+842,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+843,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+844,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+444,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+445,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+845,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+846,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+446,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1098,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1098,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+153,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+847,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+444,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+445,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+843,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+844,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+841,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+845,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+842,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+848,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+849,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+850,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+851,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+852,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+853,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+206,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+207,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1806,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+854,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+76,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+118,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+447,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1807,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+855,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+856,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+857,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+858,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+448,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+449,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+859,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+860,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+119,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1102,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1102,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1810,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+861,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+448,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+449,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+857,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+858,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+855,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+859,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+856,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+862,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+863,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+864,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+865,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+866,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+867,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+208,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+209,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+450,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1813,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+157,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1816,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+161,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1819,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+454,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+868,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+455,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+459,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1820,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+162,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+869,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+870,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+871,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+872,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+460,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+461,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+873,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+874,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+462,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1105,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1105,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+166,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+875,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+460,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+461,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+871,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+872,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+869,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+873,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+870,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+876,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+877,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+878,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+879,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+880,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+881,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+210,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+211,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1821,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+882,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+79,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+120,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+463,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1822,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+883,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+884,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+885,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+886,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+464,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+887,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+888,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+121,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1109,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1109,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1825,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+889,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+464,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+465,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+885,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+886,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+883,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+887,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+884,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+890,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+891,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+892,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+893,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+894,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+895,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+212,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+213,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+466,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+1828,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+170,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+1831,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+174,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1834,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+470,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+896,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+471,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+475,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1835,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+175,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+897,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+898,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+899,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+900,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+476,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+477,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+901,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+902,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+478,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1112,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1112,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+179,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+903,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+476,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+477,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+899,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+900,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+897,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+901,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+898,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+904,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+905,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+906,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+907,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+908,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+909,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+214,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+215,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1836,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+910,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+82,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+122,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+479,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1837,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+911,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+912,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+913,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+914,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+480,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+481,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+915,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+916,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+123,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1116,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1116,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1840,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+917,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1598,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1599,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+480,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+481,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+913,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+914,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+911,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+915,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+912,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+918,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+919,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+920,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+921,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+922,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+923,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+216,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+217,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+54,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+273,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+547,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+551,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+228,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+276,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+85,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+953,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+86,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+220,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+554,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+229,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+954,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+955,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+956,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+957,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+555,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+556,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+958,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+959,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+221,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1291,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1291,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+233,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+960,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+555,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+556,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+956,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+957,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+954,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+958,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+955,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+961,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+962,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+963,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+964,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+965,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+966,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+320,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+557,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+967,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+558,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+561,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+277,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+968,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+969,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+970,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+971,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+562,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+563,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+972,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+973,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+564,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1295,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1295,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+280,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+974,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+562,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+563,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+970,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+971,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+968,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+972,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+969,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+975,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+976,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+977,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+978,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+979,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+980,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+321,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+58,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+283,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+565,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+569,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+237,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+286,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+981,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+92,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+222,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+572,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+238,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+982,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+983,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+984,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+985,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+573,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+574,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+986,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+987,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+223,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1298,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1298,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+242,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+988,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+573,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+574,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+984,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+985,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+982,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+986,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+983,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+989,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+990,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+991,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+992,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+993,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+994,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+575,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+995,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+576,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+579,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+96,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+287,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+996,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+997,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+998,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+999,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+580,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+581,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1000,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1001,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+582,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1302,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1302,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+290,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1002,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+580,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+581,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+998,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+999,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+996,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1000,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+997,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1003,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1004,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1005,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1006,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1007,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1008,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+325,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+326,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+62,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+293,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+583,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+587,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+246,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+296,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+97,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1009,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+98,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+224,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+590,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+247,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+1010,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1011,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1012,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1013,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+591,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1014,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1015,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+225,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1305,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1305,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+251,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1016,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+591,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+592,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1012,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1013,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1010,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1014,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1011,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1017,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1018,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1019,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1020,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1021,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1022,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+327,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+328,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+593,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1023,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+594,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+597,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+102,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+297,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+1024,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1025,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1026,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1027,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+598,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+599,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1028,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1029,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+600,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1309,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1309,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+300,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1030,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+598,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+599,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1026,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1027,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1024,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1028,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1025,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1031,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1032,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1033,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1034,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1035,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1036,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+329,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+330,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_sub__TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo__0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBus(c+1851,0,"ReqPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1851,0,"RspPass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"ReqDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"RspDepth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareReqW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"SpareRspW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1872,0,"prim_mubi_pkg_MuBi4Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_DataIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1845,0,"tlul_pkg_H2DCmdIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1843,0,"top_pkg_TL_AIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_AW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1867,0,"top_pkg_TL_DW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1872,0,"top_pkg_TL_DBW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1885,0,"top_pkg_TL_SZW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+66,0,"tl_h_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declBus(c+1845,0,"tlul_pkg_D2HRspIntgWidth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1854,0,"top_pkg_TL_DIW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+303,0,"tl_h_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declArray(c+601,0,"tl_d_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 108,0);
    tracep->declArray(c+605,0,"tl_d_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 65,0);
    tracep->declBus(c+1849,0,"spare_req_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+255,0,"spare_req_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1849,0,"spare_rsp_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+306,0,"spare_rsp_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1919,0,"REQFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1912,0,"RSPFIFO_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("reqfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1919,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1037,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+104,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+226,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+608,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+256,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declBit(c+1038,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1039,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1040,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1041,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+609,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+610,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1042,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1043,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+227,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1312,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+1312,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->declArray(c+260,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 107,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1044,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+609,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+610,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1040,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1041,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1038,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1042,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1039,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1045,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1046,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1047,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1048,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1049,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1050,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+331,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+332,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("rspfifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1912,0,"Width",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"Pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1851,0,"OutputZeroIfEmpty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1854,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+611,0,"wvalid_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1051,0,"wready_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+612,0,"wdata_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+615,0,"rvalid_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"rready_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+307,0,"rdata_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declBit(c+1052,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1053,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("gen_normal_fifo", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1054,0,"fifo_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1055,0,"fifo_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+616,0,"fifo_incr_wptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+617,0,"fifo_incr_rptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1056,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1057,0,"under_rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+618,0,"empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+1316,0,"storage",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+1316,0,"storage_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->declArray(c+310,0,"rdata_int",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 64,0);
    tracep->pushPrefix("gen_depth_eq1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+1058,0,"unused_ptrs",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fifo_cnt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1887,0,"Depth",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1855,0,"Secure",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1887,0,"PtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1887,0,"DepthW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+1631,0,"clk_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1632,0,"rst_ni",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1849,0,"clr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+616,0,"incr_wptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+617,0,"incr_rptr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1054,0,"wptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBus(c+1055,0,"rptr_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1052,0,"full_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1056,0,"empty_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1053,0,"depth_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 0,0);
    tracep->declBit(c+1890,0,"err_o",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1853,0,"WrapPtrW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1059,0,"wptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1060,0,"wptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1061,0,"rptr_wrap_cnt_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+1062,0,"rptr_wrap_set_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+1063,0,"wptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1064,0,"rptr_wrap_msb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+333,0,"wptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"rptr_wrap_set",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_init_top(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_init_top\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vpwm_ramp_tb___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpwm_ramp_tb___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vpwm_ramp_tb___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_register(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_register\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vpwm_ramp_tb___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vpwm_ramp_tb___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vpwm_ramp_tb___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vpwm_ramp_tb___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_const_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_const_0\n"); );
    // Init
    Vpwm_ramp_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_ramp_tb___024root*>(voidSelf);
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpwm_ramp_tb___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_const_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_const_0_sub_0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    // Body
    bufp->fullIData(oldp+1843,(8U),32);
    bufp->fullIData(oldp+1844,(0xffU),32);
    bufp->fullIData(oldp+1845,(7U),32);
    bufp->fullBit(oldp+1846,(vlSelfRef.multiple_pwm_ramp__DOT__lvds));
    bufp->fullBit(oldp+1847,(vlSelfRef.multiple_pwm_ramp__DOT__lvds_rise));
    bufp->fullCData(oldp+1848,(0U),8);
    bufp->fullBit(oldp+1849,(0U));
    bufp->fullCData(oldp+1850,(1U),8);
    bufp->fullBit(oldp+1851,(1U));
    bufp->fullIData(oldp+1852,(3U),32);
    bufp->fullIData(oldp+1853,(2U),32);
    bufp->fullIData(oldp+1854,(1U),32);
    bufp->fullBit(oldp+1855,(0U));
    bufp->fullBit(oldp+1856,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullCData(oldp+1857,(0x7fU),8);
    bufp->fullBit(oldp+1858,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullIData(oldp+1859,(0x10U),32);
    bufp->fullIData(oldp+1860,(0x20U),32);
    bufp->fullSData(oldp+1861,(0U),16);
    bufp->fullIData(oldp+1862,(5U),32);
    bufp->fullIData(oldp+1863,(4U),32);
    bufp->fullCData(oldp+1864,(0x10U),5);
    bufp->fullIData(oldp+1865,(5U),32);
    bufp->fullCData(oldp+1866,(0U),5);
    bufp->fullIData(oldp+1867,(0x20U),32);
    bufp->fullCData(oldp+1868,(0U),3);
    bufp->fullIData(oldp+1869,(0U),32);
    bufp->fullIData(oldp+1870,(0xcU),32);
    bufp->fullIData(oldp+1871,(0x10U),32);
    bufp->fullIData(oldp+1872,(4U),32);
    bufp->fullIData(oldp+1873,(0xaU),32);
    bufp->fullIData(oldp+1874,(6U),32);
    bufp->fullIData(oldp+1875,(0U),32);
    bufp->fullDouble(oldp+1876,(1.58730158730158721e-02));
    bufp->fullCData(oldp+1878,(0U),6);
    bufp->fullIData(oldp+1879,(0x3fU),32);
    bufp->fullBit(oldp+1880,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__d_o));
    bufp->fullDouble(oldp+1881,(7.00000000000000015e-03));
    bufp->fullDouble(oldp+1883,(1.0));
    bufp->fullIData(oldp+1885,(2U),32);
    bufp->fullCData(oldp+1886,(1U),2);
    bufp->fullIData(oldp+1887,(1U),32);
    bufp->fullIData(oldp+1888,(0x39U),32);
    bufp->fullCData(oldp+1889,(1U),4);
    bufp->fullBit(oldp+1890,(0U));
    bufp->fullIData(oldp+1891,(0x11U),32);
    bufp->fullIData(oldp+1892,(0x28U),32);
    bufp->fullBit(oldp+1893,(1U));
    bufp->fullSData(oldp+1894,(0U),12);
    bufp->fullIData(oldp+1895,(0xffffffffU),32);
    bufp->fullCData(oldp+1896,(0x2aU),7);
    bufp->fullQData(oldp+1897,(0x2a00000000ULL),39);
    bufp->fullIData(oldp+1899,(0x11U),32);
    bufp->fullIData(oldp+1900,(0x28U),32);
    bufp->fullQData(oldp+1901,(0x446576696365ULL),48);
    bufp->fullIData(oldp+1903,(0x6bU),32);
    bufp->fullIData(oldp+1904,(0x40U),32);
    bufp->fullCData(oldp+1905,(4U),3);
    bufp->fullIData(oldp+1906,(3U),32);
    bufp->fullCData(oldp+1907,(0xfU),4);
    bufp->fullSData(oldp+1908,(0x1111U),16);
    bufp->fullIData(oldp+1909,(0x100U),32);
    bufp->fullIData(oldp+1910,(9U),32);
    bufp->fullIData(oldp+1911,(0x6eU),32);
    bufp->fullIData(oldp+1912,(0x41U),32);
    bufp->fullIData(oldp+1913,(8U),32);
    bufp->fullIData(oldp+1914,(0x505043U),24);
    bufp->fullIData(oldp+1915,(0x6dU),32);
    bufp->fullCData(oldp+1916,(0U),2);
    bufp->fullCData(oldp+1917,(2U),2);
    bufp->fullCData(oldp+1918,(3U),2);
    bufp->fullIData(oldp+1919,(0x6cU),32);
    bufp->fullIData(oldp+1920,(4U),32);
    bufp->fullIData(oldp+1921,(8U),32);
    bufp->fullIData(oldp+1922,(0xcU),32);
    bufp->fullIData(oldp+1923,(0x10U),32);
    bufp->fullIData(oldp+1924,(0x14U),32);
    bufp->fullIData(oldp+1925,(0x18U),32);
    bufp->fullIData(oldp+1926,(0x1cU),32);
    bufp->fullIData(oldp+1927,(0x20U),32);
    bufp->fullIData(oldp+1928,(0U),22);
    bufp->fullIData(oldp+1929,(0U),28);
    bufp->fullCData(oldp+1930,(0U),7);
    bufp->fullQData(oldp+1931,(0ULL),39);
    bufp->fullQData(oldp+1933,(0ULL),64);
    __Vtemp_1[0U] = 0U;
    __Vtemp_1[1U] = 0U;
    __Vtemp_1[2U] = 0U;
    bufp->fullWData(oldp+1935,(__Vtemp_1),72);
    __Vtemp_2[0U] = 0U;
    __Vtemp_2[1U] = 0U;
    __Vtemp_2[2U] = 0U;
    bufp->fullWData(oldp+1938,(__Vtemp_2),76);
    bufp->fullCData(oldp+1941,(0x2aU),6);
    bufp->fullIData(oldp+1942,(0x2a0000U),22);
    bufp->fullIData(oldp+1943,(0xa800000U),28);
    bufp->fullQData(oldp+1944,(0x5400000000000000ULL),64);
    bufp->fullCData(oldp+1946,(0xaaU),8);
    __Vtemp_3[0U] = 0U;
    __Vtemp_3[1U] = 0U;
    __Vtemp_3[2U] = 0xaaU;
    bufp->fullWData(oldp+1947,(__Vtemp_3),72);
    __Vtemp_4[0U] = 0U;
    __Vtemp_4[1U] = 0U;
    __Vtemp_4[2U] = 0xaa0U;
    bufp->fullWData(oldp+1950,(__Vtemp_4),76);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_full_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_full_0\n"); );
    // Init
    Vpwm_ramp_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_ramp_tb___024root*>(voidSelf);
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vpwm_ramp_tb___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vpwm_ramp_tb___024root__trace_full_0_sub_0(Vpwm_ramp_tb___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_ramp_tb___024root__trace_full_0_sub_0\n"); );
    Vpwm_ramp_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<4>/*127:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<3>/*95:0*/ __Vtemp_24;
    VlWide<3>/*95:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_36;
    VlWide<4>/*127:0*/ __Vtemp_39;
    VlWide<4>/*127:0*/ __Vtemp_55;
    VlWide<4>/*127:0*/ __Vtemp_61;
    VlWide<4>/*127:0*/ __Vtemp_71;
    VlWide<4>/*127:0*/ __Vtemp_74;
    VlWide<4>/*127:0*/ __Vtemp_90;
    VlWide<4>/*127:0*/ __Vtemp_96;
    VlWide<4>/*127:0*/ __Vtemp_106;
    VlWide<4>/*127:0*/ __Vtemp_109;
    VlWide<4>/*127:0*/ __Vtemp_125;
    VlWide<4>/*127:0*/ __Vtemp_131;
    VlWide<4>/*127:0*/ __Vtemp_141;
    VlWide<4>/*127:0*/ __Vtemp_144;
    VlWide<4>/*127:0*/ __Vtemp_160;
    VlWide<4>/*127:0*/ __Vtemp_166;
    VlWide<4>/*127:0*/ __Vtemp_182;
    VlWide<4>/*127:0*/ __Vtemp_188;
    VlWide<4>/*127:0*/ __Vtemp_204;
    VlWide<4>/*127:0*/ __Vtemp_210;
    VlWide<4>/*127:0*/ __Vtemp_226;
    VlWide<4>/*127:0*/ __Vtemp_232;
    VlWide<4>/*127:0*/ __Vtemp_248;
    VlWide<4>/*127:0*/ __Vtemp_254;
    VlWide<4>/*127:0*/ __Vtemp_270;
    VlWide<4>/*127:0*/ __Vtemp_276;
    VlWide<3>/*95:0*/ __Vtemp_281;
    VlWide<3>/*95:0*/ __Vtemp_282;
    VlWide<3>/*95:0*/ __Vtemp_290;
    VlWide<3>/*95:0*/ __Vtemp_292;
    VlWide<3>/*95:0*/ __Vtemp_297;
    VlWide<3>/*95:0*/ __Vtemp_298;
    VlWide<3>/*95:0*/ __Vtemp_306;
    VlWide<3>/*95:0*/ __Vtemp_308;
    VlWide<3>/*95:0*/ __Vtemp_313;
    VlWide<3>/*95:0*/ __Vtemp_314;
    VlWide<3>/*95:0*/ __Vtemp_322;
    VlWide<3>/*95:0*/ __Vtemp_324;
    VlWide<3>/*95:0*/ __Vtemp_329;
    VlWide<3>/*95:0*/ __Vtemp_330;
    VlWide<3>/*95:0*/ __Vtemp_338;
    VlWide<3>/*95:0*/ __Vtemp_340;
    VlWide<3>/*95:0*/ __Vtemp_344;
    VlWide<4>/*127:0*/ __Vtemp_348;
    VlWide<4>/*127:0*/ __Vtemp_352;
    VlWide<4>/*127:0*/ __Vtemp_356;
    VlWide<4>/*127:0*/ __Vtemp_360;
    VlWide<4>/*127:0*/ __Vtemp_364;
    VlWide<4>/*127:0*/ __Vtemp_366;
    VlWide<4>/*127:0*/ __Vtemp_369;
    VlWide<3>/*95:0*/ __Vtemp_372;
    VlWide<4>/*127:0*/ __Vtemp_375;
    VlWide<3>/*95:0*/ __Vtemp_378;
    VlWide<4>/*127:0*/ __Vtemp_381;
    VlWide<4>/*127:0*/ __Vtemp_383;
    VlWide<3>/*95:0*/ __Vtemp_385;
    VlWide<3>/*95:0*/ __Vtemp_390;
    VlWide<3>/*95:0*/ __Vtemp_391;
    VlWide<3>/*95:0*/ __Vtemp_394;
    VlWide<3>/*95:0*/ __Vtemp_402;
    VlWide<3>/*95:0*/ __Vtemp_404;
    VlWide<3>/*95:0*/ __Vtemp_409;
    VlWide<3>/*95:0*/ __Vtemp_410;
    VlWide<3>/*95:0*/ __Vtemp_413;
    VlWide<3>/*95:0*/ __Vtemp_421;
    VlWide<3>/*95:0*/ __Vtemp_423;
    VlWide<3>/*95:0*/ __Vtemp_428;
    VlWide<3>/*95:0*/ __Vtemp_429;
    VlWide<3>/*95:0*/ __Vtemp_432;
    VlWide<3>/*95:0*/ __Vtemp_440;
    VlWide<3>/*95:0*/ __Vtemp_442;
    VlWide<3>/*95:0*/ __Vtemp_447;
    VlWide<3>/*95:0*/ __Vtemp_448;
    VlWide<3>/*95:0*/ __Vtemp_451;
    VlWide<3>/*95:0*/ __Vtemp_459;
    VlWide<3>/*95:0*/ __Vtemp_461;
    // Body
    bufp->fullIData(oldp+1,((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o)),32);
    bufp->fullIData(oldp+2,((IData)(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o)),32);
    bufp->fullCData(oldp+3,((0x7fU & (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
                                              >> 0x20U)))),7);
    bufp->fullCData(oldp+4,((0x7fU & (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
                                              >> 0x20U)))),7);
    bufp->fullQData(oldp+5,(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o),39);
    bufp->fullQData(oldp+7,(vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o),39);
    bufp->fullBit(oldp+9,(vlSelfRef.pwm_ramp_tb__DOT__rst_ni));
    bufp->fullBit(oldp+10,(vlSelfRef.pwm_ramp_tb__DOT__enable_i));
    bufp->fullBit(oldp+11,(vlSelfRef.pwm_ramp_tb__DOT__reverse_i));
    bufp->fullCData(oldp+12,(vlSelfRef.pwm_ramp_tb__DOT__step_i),6);
    bufp->fullDouble(oldp+13,(vlSelfRef.pwm_ramp_tb__DOT__analog_input));
    bufp->fullBit(oldp+15,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__effective_rst_n));
    bufp->fullIData(oldp+16,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d),32);
    bufp->fullIData(oldp+17,(vlSelfRef.prim_subreg__DOT__wr_data),32);
    bufp->fullBit(oldp+18,(vlSelfRef.tlul_adapter_reg__DOT__instr_error));
    bufp->fullBit(oldp+19,(vlSelfRef.tlul_adapter_reg__DOT__malformed_meta_err));
    bufp->fullBit(oldp+20,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+21,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+22,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+23,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+24,(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk));
    bufp->fullBit(oldp+25,(vlSelfRef.tlul_adapter_sram__DOT__error_det));
    bufp->fullBit(oldp+26,(vlSelfRef.tlul_adapter_sram__DOT__instr_error));
    bufp->fullIData(oldp+27,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata),17);
    bufp->fullCData(oldp+28,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata),5);
    bufp->fullIData(oldp+29,(vlSelfRef.tlul_adapter_sram__DOT__wmask_int),32);
    bufp->fullIData(oldp+30,(vlSelfRef.tlul_adapter_sram__DOT__wdata_int),32);
    bufp->fullCData(oldp+31,(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg),7);
    bufp->fullCData(oldp+32,(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg),7);
    bufp->fullBit(oldp+33,(((0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wmask_intg)) 
                            & (0U != (IData)(vlSelfRef.tlul_adapter_sram__DOT__wdata_intg)))));
    bufp->fullIData(oldp+34,(vlSelfRef.tlul_adapter_sram__DOT__sv2v_autoblock_1__DOT__i),32);
    bufp->fullBit(oldp+35,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err));
    bufp->fullBit(oldp+36,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err));
    bufp->fullBit(oldp+37,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk));
    bufp->fullBit(oldp+38,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk));
    bufp->fullBit(oldp+39,(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk));
    bufp->fullCData(oldp+40,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_mask),8);
    bufp->fullQData(oldp+41,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__a_data),64);
    bufp->fullQData(oldp+43,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_data),64);
    bufp->fullCData(oldp+45,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_mask),8);
    bufp->fullQData(oldp+46,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__a_data),64);
    bufp->fullQData(oldp+48,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_data),64);
    bufp->fullWData(oldp+50,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i),110);
    bufp->fullWData(oldp+54,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i),109);
    bufp->fullWData(oldp+58,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i),109);
    bufp->fullWData(oldp+62,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i),109);
    bufp->fullWData(oldp+66,(vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i),109);
    bufp->fullWData(oldp+70,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i),65);
    bufp->fullWData(oldp+73,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullWData(oldp+76,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullWData(oldp+79,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullWData(oldp+82,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+85,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                  >> 0xcU))));
    __Vtemp_4[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
    __Vtemp_4[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                     | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
    __Vtemp_4[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                     | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
    __Vtemp_4[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                     | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
    bufp->fullWData(oldp+86,(__Vtemp_4),108);
    bufp->fullBit(oldp+90,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])));
    bufp->fullBit(oldp+91,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                  >> 0xcU))));
    __Vtemp_8[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
    __Vtemp_8[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                     | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
    __Vtemp_8[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                     | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
    __Vtemp_8[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                     | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
    bufp->fullWData(oldp+92,(__Vtemp_8),108);
    bufp->fullBit(oldp+96,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])));
    bufp->fullBit(oldp+97,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                  >> 0xcU))));
    __Vtemp_12[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
    __Vtemp_12[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                      | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
    __Vtemp_12[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                      | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
    __Vtemp_12[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                      | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
    bufp->fullWData(oldp+98,(__Vtemp_12),108);
    bufp->fullBit(oldp+102,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])));
    bufp->fullBit(oldp+103,((1U & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                   >> 0xcU))));
    __Vtemp_16[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
    __Vtemp_16[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                      | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
    __Vtemp_16[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                      | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
    __Vtemp_16[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                      | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
    bufp->fullWData(oldp+104,(__Vtemp_16),108);
    bufp->fullBit(oldp+108,((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])));
    bufp->fullBit(oldp+109,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
    bufp->fullBit(oldp+110,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid));
    bufp->fullBit(oldp+111,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+112,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+113,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+114,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+115,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+116,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+117,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+118,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+119,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+120,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+121,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+122,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+123,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+124,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                                >> 1U))
                                             ? vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_24[0U] = 0U;
        __Vtemp_24[1U] = 0U;
        __Vtemp_24[2U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                   >> 1U))) {
        __Vtemp_24[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_24[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_24[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_24[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_24[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_24[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+125,(__Vtemp_24),65);
    if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
            >> 1U))) {
        __Vtemp_26[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_26[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_26[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_26[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_26[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_26[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+128,(__Vtemp_26),65);
    __Vtemp_36[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_36[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [0U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_36[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [0U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [0U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [0U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [0U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    __Vtemp_39[0U] = ((__Vtemp_36[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_39[1U] = ((__Vtemp_36[0U] >> 0x1fU) | (
                                                   __Vtemp_36[1U] 
                                                   << 1U));
    __Vtemp_39[2U] = ((__Vtemp_36[1U] >> 0x1fU) | (
                                                   __Vtemp_36[2U] 
                                                   << 1U));
    __Vtemp_39[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                       << 0xcU) | ((__Vtemp_36[2U] 
                                    >> 0x1fU) | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                  ? 0U
                                                  : 
                                                 (0xffeU 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                         [0U][3U] 
                                                         >> 0xcU))
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [0U][3U]) 
                                                      | (0xffeU 
                                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                         [0U][3U]))
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
    bufp->fullWData(oldp+131,(__Vtemp_39),109);
    bufp->fullBit(oldp+135,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [0U][3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [0U][0U])
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_55[0U] = 0U;
        __Vtemp_55[1U] = 0U;
        __Vtemp_55[2U] = 0U;
        __Vtemp_55[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                   [0U][3U] >> 0xcU))) {
        __Vtemp_55[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                          [0U][0U]);
        __Vtemp_55[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][1U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][1U]));
        __Vtemp_55[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][2U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][2U]));
        __Vtemp_55[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][3U]));
    } else {
        __Vtemp_55[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_55[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_55[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_55[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+136,(__Vtemp_55),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] 
            >> 0xcU))) {
        __Vtemp_61[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                          [0U][0U]);
        __Vtemp_61[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][1U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][1U]));
        __Vtemp_61[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][2U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][2U]));
        __Vtemp_61[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [0U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [0U][3U]));
    } else {
        __Vtemp_61[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_61[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_61[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_61[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+140,(__Vtemp_61),108);
    __Vtemp_71[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][1U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][1U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? (0xfffffffeU 
                                                  & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][0U])
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                    >> 1U));
    __Vtemp_71[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][2U]) | (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][2U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][1U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [1U][1U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                    >> 1U));
    __Vtemp_71[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                         ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                  & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U] >> 0xcU))
                                  ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [1U][3U]) | (0xffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][3U]))
                                  : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                       << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                      ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                               & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [1U][3U] 
                                                  >> 0xcU))
                                               ? ((1U 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [1U][2U]) 
                                                  | (0xfffffffeU 
                                                     & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                     [1U][2U]))
                                               : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                    >> 1U));
    __Vtemp_74[0U] = ((__Vtemp_71[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_74[1U] = ((__Vtemp_71[0U] >> 0x1fU) | (
                                                   __Vtemp_71[1U] 
                                                   << 1U));
    __Vtemp_74[2U] = ((__Vtemp_71[1U] >> 0x1fU) | (
                                                   __Vtemp_71[2U] 
                                                   << 1U));
    __Vtemp_74[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                       << 0xcU) | ((__Vtemp_71[2U] 
                                    >> 0x1fU) | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                  ? 0U
                                                  : 
                                                 (0xffeU 
                                                  & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                      & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                         [1U][3U] 
                                                         >> 0xcU))
                                                      ? 
                                                     ((1U 
                                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                       [1U][3U]) 
                                                      | (0xffeU 
                                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                         [1U][3U]))
                                                      : 
                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
    bufp->fullWData(oldp+144,(__Vtemp_74),109);
    bufp->fullBit(oldp+148,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [1U][3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [1U][0U])
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_90[0U] = 0U;
        __Vtemp_90[1U] = 0U;
        __Vtemp_90[2U] = 0U;
        __Vtemp_90[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                   [1U][3U] >> 0xcU))) {
        __Vtemp_90[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                          [1U][0U]);
        __Vtemp_90[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][1U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][1U]));
        __Vtemp_90[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][2U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][2U]));
        __Vtemp_90[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][3U]));
    } else {
        __Vtemp_90[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_90[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_90[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_90[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+149,(__Vtemp_90),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] 
            >> 0xcU))) {
        __Vtemp_96[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                          [1U][0U]);
        __Vtemp_96[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][1U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][1U]));
        __Vtemp_96[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][2U]) | (0xfffffffeU 
                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][2U]));
        __Vtemp_96[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [1U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                        [1U][3U]));
    } else {
        __Vtemp_96[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_96[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_96[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_96[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+153,(__Vtemp_96),108);
    __Vtemp_106[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][1U]) | 
                                      (0xfffffffeU 
                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][1U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                     >> 1U));
    __Vtemp_106[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][2U]) | 
                                      (0xfffffffeU 
                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][2U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [2U][1U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [2U][1U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                     >> 1U));
    __Vtemp_106[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [2U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][3U]) | 
                                      (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [2U][3U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [2U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [2U][2U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [2U][2U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                     >> 1U));
    __Vtemp_109[0U] = ((__Vtemp_106[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_109[1U] = ((__Vtemp_106[0U] >> 0x1fU) | 
                       (__Vtemp_106[1U] << 1U));
    __Vtemp_109[2U] = ((__Vtemp_106[1U] >> 0x1fU) | 
                       (__Vtemp_106[2U] << 1U));
    __Vtemp_109[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                        << 0xcU) | ((__Vtemp_106[2U] 
                                     >> 0x1fU) | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xffeU 
                                                   & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                          [2U][3U] 
                                                          >> 0xcU))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [2U][3U]) 
                                                       | (0xffeU 
                                                          & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                          [2U][3U]))
                                                       : 
                                                      vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
    bufp->fullWData(oldp+157,(__Vtemp_109),109);
    bufp->fullBit(oldp+161,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [2U][3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [2U][0U])
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_125[0U] = 0U;
        __Vtemp_125[1U] = 0U;
        __Vtemp_125[2U] = 0U;
        __Vtemp_125[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                   [2U][3U] >> 0xcU))) {
        __Vtemp_125[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [2U][0U]);
        __Vtemp_125[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][1U]));
        __Vtemp_125[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][2U]));
        __Vtemp_125[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][3U]));
    } else {
        __Vtemp_125[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_125[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_125[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_125[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+162,(__Vtemp_125),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] 
            >> 0xcU))) {
        __Vtemp_131[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [2U][0U]);
        __Vtemp_131[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][1U]));
        __Vtemp_131[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][2U]));
        __Vtemp_131[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [2U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [2U][3U]));
    } else {
        __Vtemp_131[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_131[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_131[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_131[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+166,(__Vtemp_131),108);
    __Vtemp_141[0U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][1U]) | 
                                      (0xfffffffeU 
                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][1U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U] 
                                                   >> 0xcU))
                                                ? (0xfffffffeU 
                                                   & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][0U])
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])) 
                                     >> 1U));
    __Vtemp_141[1U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][2U]) | 
                                      (0xfffffffeU 
                                       & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][2U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [3U][1U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [3U][1U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U])) 
                                     >> 1U));
    __Vtemp_141[2U] = ((((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                          ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                   & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                      [3U][3U] >> 0xcU))
                                   ? ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][3U]) | 
                                      (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                       [3U][3U])) : 
                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])) 
                        << 0x1fU) | (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                       ? 0U : (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                   [3U][3U] 
                                                   >> 0xcU))
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                    [3U][2U]) 
                                                   | (0xfffffffeU 
                                                      & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                      [3U][2U]))
                                                : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U])) 
                                     >> 1U));
    __Vtemp_144[0U] = ((__Vtemp_141[0U] << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    __Vtemp_144[1U] = ((__Vtemp_141[0U] >> 0x1fU) | 
                       (__Vtemp_141[1U] << 1U));
    __Vtemp_144[2U] = ((__Vtemp_141[1U] >> 0x1fU) | 
                       (__Vtemp_141[2U] << 1U));
    __Vtemp_144[3U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o) 
                        << 0xcU) | ((__Vtemp_141[2U] 
                                     >> 0x1fU) | ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                                                   ? 0U
                                                   : 
                                                  (0xffeU 
                                                   & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                       & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                          [3U][3U] 
                                                          >> 0xcU))
                                                       ? 
                                                      ((1U 
                                                        & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                        [3U][3U]) 
                                                       | (0xffeU 
                                                          & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                          [3U][3U]))
                                                       : 
                                                      vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U])))));
    bufp->fullWData(oldp+170,(__Vtemp_144),109);
    bufp->fullBit(oldp+174,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [3U][3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [3U][0U])
                                             : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_160[0U] = 0U;
        __Vtemp_160[1U] = 0U;
        __Vtemp_160[2U] = 0U;
        __Vtemp_160[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                   [3U][3U] >> 0xcU))) {
        __Vtemp_160[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [3U][0U]);
        __Vtemp_160[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][1U]));
        __Vtemp_160[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][2U]));
        __Vtemp_160[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][3U]));
    } else {
        __Vtemp_160[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_160[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_160[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_160[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+175,(__Vtemp_160),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] 
            >> 0xcU))) {
        __Vtemp_166[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [3U][0U]);
        __Vtemp_166[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][1U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][1U]));
        __Vtemp_166[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][2U]) | (0xfffffffeU 
                                         & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][2U]));
        __Vtemp_166[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                            [3U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                         [3U][3U]));
    } else {
        __Vtemp_166[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_166[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_166[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_166[3U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+179,(__Vtemp_166),108);
    bufp->fullWData(oldp+183,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[0]),66);
    bufp->fullWData(oldp+186,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[1]),66);
    bufp->fullWData(oldp+189,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[2]),66);
    bufp->fullWData(oldp+192,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[3]),66);
    bufp->fullWData(oldp+195,(vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4]),66);
    bufp->fullBit(oldp+198,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+199,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+200,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+201,(((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+202,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+203,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+204,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+205,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+206,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+207,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+208,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+209,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+210,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+211,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+212,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+213,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+214,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+215,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+216,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+217,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+218,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+219,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+220,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+221,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+222,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+223,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+224,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+225,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+226,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+227,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+228,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U])
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_182[0U] = 0U;
        __Vtemp_182[1U] = 0U;
        __Vtemp_182[2U] = 0U;
        __Vtemp_182[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
                   >> 0xcU))) {
        __Vtemp_182[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_182[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_182[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_182[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_182[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_182[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_182[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_182[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+229,(__Vtemp_182),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU))) {
        __Vtemp_188[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_188[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_188[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_188[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_188[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_188[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_188[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_188[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+233,(__Vtemp_188),108);
    bufp->fullBit(oldp+237,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U])
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_204[0U] = 0U;
        __Vtemp_204[1U] = 0U;
        __Vtemp_204[2U] = 0U;
        __Vtemp_204[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
                   >> 0xcU))) {
        __Vtemp_204[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_204[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_204[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_204[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_204[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_204[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_204[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_204[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+238,(__Vtemp_204),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU))) {
        __Vtemp_210[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_210[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_210[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_210[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_210[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_210[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_210[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_210[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+242,(__Vtemp_210),108);
    bufp->fullBit(oldp+246,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U])
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_226[0U] = 0U;
        __Vtemp_226[1U] = 0U;
        __Vtemp_226[2U] = 0U;
        __Vtemp_226[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
                   >> 0xcU))) {
        __Vtemp_226[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_226[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_226[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_226[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_226[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_226[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_226[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_226[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+247,(__Vtemp_226),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU))) {
        __Vtemp_232[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_232[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_232[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_232[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_232[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_232[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_232[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_232[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+251,(__Vtemp_232),108);
    bufp->fullBit(oldp+255,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U])
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_248[0U] = 0U;
        __Vtemp_248[1U] = 0U;
        __Vtemp_248[2U] = 0U;
        __Vtemp_248[3U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
                   >> 0xcU))) {
        __Vtemp_248[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_248[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_248[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_248[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_248[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_248[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_248[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_248[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+256,(__Vtemp_248),108);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
            >> 0xcU))) {
        __Vtemp_254[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U]);
        __Vtemp_254[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U]));
        __Vtemp_254[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U]));
        __Vtemp_254[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U]));
    } else {
        __Vtemp_254[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_254[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_254[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_254[3U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+260,(__Vtemp_254),108);
    bufp->fullBit(oldp+264,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                                >> 0xcU))
                                             ? (0xfffffffeU 
                                                & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])
                                             : vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_270[0U] = 0U;
        __Vtemp_270[1U] = 0U;
        __Vtemp_270[2U] = 0U;
        __Vtemp_270[3U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                   >> 0xcU))) {
        __Vtemp_270[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        __Vtemp_270[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        __Vtemp_270[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        __Vtemp_270[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
    } else {
        __Vtemp_270[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_270[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_270[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_270[3U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+265,(__Vtemp_270),108);
    if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
            >> 0xcU))) {
        __Vtemp_276[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        __Vtemp_276[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        __Vtemp_276[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                           | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        __Vtemp_276[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                           | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
    } else {
        __Vtemp_276[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_276[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_276[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_276[3U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+269,(__Vtemp_276),108);
    __Vtemp_281[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [0U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [0U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [0U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                         [0U][2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                           [0U][2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_282[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [0U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [0U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [0U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    __Vtemp_282[1U] = __Vtemp_281[1U];
    __Vtemp_282[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                   [0U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [0U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [0U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+273,(__Vtemp_282),66);
    bufp->fullBit(oldp+276,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                [0U][2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_290[0U] = 0U;
        __Vtemp_290[1U] = 0U;
        __Vtemp_290[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                   [0U][2U] >> 1U))) {
        __Vtemp_290[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_290[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_290[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_290[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_290[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_290[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+277,(__Vtemp_290),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
            [0U][2U] >> 1U))) {
        __Vtemp_292[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_292[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_292[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_292[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_292[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_292[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+280,(__Vtemp_292),65);
    __Vtemp_297[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [1U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [1U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [1U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                         [1U][2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                           [1U][2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_298[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [1U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [1U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [1U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    __Vtemp_298[1U] = __Vtemp_297[1U];
    __Vtemp_298[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                   [1U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [1U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [1U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+283,(__Vtemp_298),66);
    bufp->fullBit(oldp+286,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                [1U][2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_306[0U] = 0U;
        __Vtemp_306[1U] = 0U;
        __Vtemp_306[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                   [1U][2U] >> 1U))) {
        __Vtemp_306[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_306[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_306[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_306[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_306[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_306[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+287,(__Vtemp_306),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
            [1U][2U] >> 1U))) {
        __Vtemp_308[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_308[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_308[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_308[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_308[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_308[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+290,(__Vtemp_308),65);
    __Vtemp_313[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [2U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [2U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [2U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                         [2U][2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                           [2U][2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_314[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [2U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [2U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [2U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    __Vtemp_314[1U] = __Vtemp_313[1U];
    __Vtemp_314[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                   [2U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [2U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [2U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+293,(__Vtemp_314),66);
    bufp->fullBit(oldp+296,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                [2U][2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_322[0U] = 0U;
        __Vtemp_322[1U] = 0U;
        __Vtemp_322[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                   [2U][2U] >> 1U))) {
        __Vtemp_322[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_322[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_322[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_322[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_322[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_322[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+297,(__Vtemp_322),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
            [2U][2U] >> 1U))) {
        __Vtemp_324[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_324[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_324[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_324[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_324[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_324[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+300,(__Vtemp_324),65);
    __Vtemp_329[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [3U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [3U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [3U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                         [3U][2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                           [3U][2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_330[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                        [3U][2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [3U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [3U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    __Vtemp_330[1U] = __Vtemp_329[1U];
    __Vtemp_330[2U] = (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                   [3U][2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                      [3U][2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                                        [3U][2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+303,(__Vtemp_330),66);
    bufp->fullBit(oldp+306,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                              ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                             & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                                [3U][2U] 
                                                >> 1U))
                                             ? vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U]
                                             : vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    if (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_338[0U] = 0U;
        __Vtemp_338[1U] = 0U;
        __Vtemp_338[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                   [3U][2U] >> 1U))) {
        __Vtemp_338[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_338[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_338[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_338[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_338[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_338[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+307,(__Vtemp_338),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
            [3U][2U] >> 1U))) {
        __Vtemp_340[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_340[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_340[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_340[0U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_340[1U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_340[2U] = vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+310,(__Vtemp_340),65);
    bufp->fullCData(oldp+313,(((((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                  & (IData)(((0x60000U 
                                              == (0x60000U 
                                                  & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                             & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                 << 3U) | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                            & (IData)(
                                                      ((0x40000U 
                                                        == 
                                                        (0x60000U 
                                                         & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                       & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                           << 2U)) 
                               | (((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                    & (IData)(((0x20000U 
                                                == 
                                                (0x60000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                               & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                   << 1U) | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                             & (IData)(
                                                       ((0U 
                                                         == 
                                                         (0x60000U 
                                                          & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                        & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o))))))),4);
    bufp->fullBit(oldp+314,(((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o[0U] 
                              & (IData)(((0x60000U 
                                          == (0x60000U 
                                              & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                         & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                             | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                 & (IData)(((0x40000U 
                                             == (0x60000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                            & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                | ((vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                    & (IData)(((0x20000U 
                                                == 
                                                (0x60000U 
                                                 & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                               & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))) 
                                   | (vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o[0U] 
                                      & (IData)(((0U 
                                                  == 
                                                  (0x60000U 
                                                   & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                 & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o)))))))));
    bufp->fullBit(oldp+315,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+316,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+317,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+318,(((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+319,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+320,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+321,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+322,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+323,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+324,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+325,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+326,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+327,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+328,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+329,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+330,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+331,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+332,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+333,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+334,(((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                             & (~ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullWData(oldp+335,(vlSelfRef.tlul_adapter_host__DOT__tl_out),109);
    bufp->fullCData(oldp+339,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_d),2);
    bufp->fullBit(oldp+340,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d));
    bufp->fullCData(oldp+341,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                        >> 8U))),7);
    bufp->fullIData(oldp+342,(((vlSelfRef.tlul_adapter_host__DOT__tl_out[1U] 
                                << 8U) | (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                          >> 0x18U))),32);
    bufp->fullCData(oldp+343,((0x7fU & (vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                        >> 1U))),7);
    bufp->fullBit(oldp+344,((1U & VL_REDXOR_32((((vlSelfRef.tlul_adapter_host__DOT__tl_out[0U] 
                                                  ^ 
                                                  vlSelfRef.tlul_adapter_host__DOT__tl_out[1U]) 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_host__DOT__tl_out[2U]) 
                                                ^ vlSelfRef.tlul_adapter_host__DOT__tl_out[3U])))));
    bufp->fullBit(oldp+345,(vlSelfRef.prim_fifo_async_simple__DOT__wr_en));
    bufp->fullBit(oldp+346,(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    bufp->fullBit(oldp+347,(((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
                             & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
                                | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)))));
    bufp->fullBit(oldp+348,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
    bufp->fullBit(oldp+349,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake));
    bufp->fullBit(oldp+350,(vlSelfRef.tlul_adapter_reg__DOT__a_ack));
    bufp->fullBit(oldp+351,(vlSelfRef.tlul_adapter_reg__DOT__err_internal));
    bufp->fullBit(oldp+352,(vlSelfRef.tlul_adapter_reg__DOT__rd_req));
    bufp->fullBit(oldp+353,(vlSelfRef.tlul_adapter_reg__DOT__wr_req));
    bufp->fullWData(oldp+354,(vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre),66);
    bufp->fullBit(oldp+357,((1U & VL_REDXOR_32(((vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[0U] 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[1U]) 
                                                ^ vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U])))));
    bufp->fullCData(oldp+358,((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])),3);
    bufp->fullWData(oldp+359,(vlSelfRef.tlul_socket_1n__DOT__tl_t_o),109);
    __Vtemp_344[0U] = ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[0U]) 
                       | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    __Vtemp_344[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]) 
                       | (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[1U]));
    __Vtemp_344[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]) 
                       | (2U & vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U]));
    bufp->fullWData(oldp+363,(__Vtemp_344),66);
    bufp->fullBit(oldp+366,(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests));
    bufp->fullBit(oldp+367,(vlSelfRef.tlul_socket_1n__DOT__accept_t_req));
    bufp->fullBit(oldp+368,(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp));
    bufp->fullWData(oldp+369,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0]),109);
    bufp->fullWData(oldp+373,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1]),109);
    bufp->fullWData(oldp+377,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2]),109);
    bufp->fullWData(oldp+381,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3]),109);
    bufp->fullWData(oldp+385,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4]),109);
    bufp->fullIData(oldp+389,(vlSelfRef.tlul_socket_1n__DOT__blanked_auser),23);
    bufp->fullWData(oldp+390,(vlSelfRef.tlul_socket_1n__DOT__tl_t_p),66);
    bufp->fullBit(oldp+393,(vlSelfRef.tlul_socket_1n__DOT__hfifo_reqready));
    bufp->fullBit(oldp+394,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__rready_i));
    bufp->fullWData(oldp+395,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o),110);
    bufp->fullBit(oldp+399,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+400,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+401,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_t_p[2U] 
                                   >> 1U))));
    bufp->fullWData(oldp+402,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+405,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+406,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+407,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+408,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullWData(oldp+409,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [4U]),109);
    bufp->fullBit(oldp+413,((1U & VL_REDXOR_32((((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [4U][0U] 
                                                  ^ 
                                                  vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                  [4U][1U]) 
                                                 ^ 
                                                 vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                 [4U][2U]) 
                                                ^ vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [4U][3U])))));
    bufp->fullBit(oldp+414,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select));
    bufp->fullBit(oldp+415,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select));
    bufp->fullBit(oldp+416,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select));
    bufp->fullBit(oldp+417,(vlSelfRef.tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select));
    bufp->fullWData(oldp+418,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [0U]),109);
    bufp->fullBit(oldp+422,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                   [0U][3U] >> 0xcU))));
    __Vtemp_348[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [0U][0U]);
    __Vtemp_348[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [0U][1U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][1U]));
    __Vtemp_348[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [0U][2U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][2U]));
    __Vtemp_348[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [0U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [0U][3U]));
    bufp->fullWData(oldp+423,(__Vtemp_348),108);
    bufp->fullBit(oldp+427,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+428,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+429,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+430,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+431,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [0U][0U])));
    bufp->fullBit(oldp+432,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+433,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullWData(oldp+434,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [1U]),109);
    bufp->fullBit(oldp+438,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                   [1U][3U] >> 0xcU))));
    __Vtemp_352[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [1U][0U]);
    __Vtemp_352[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [1U][1U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][1U]));
    __Vtemp_352[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [1U][2U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][2U]));
    __Vtemp_352[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [1U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [1U][3U]));
    bufp->fullWData(oldp+439,(__Vtemp_352),108);
    bufp->fullBit(oldp+443,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+444,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+445,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+446,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+447,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [1U][0U])));
    bufp->fullBit(oldp+448,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+449,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullWData(oldp+450,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [2U]),109);
    bufp->fullBit(oldp+454,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                   [2U][3U] >> 0xcU))));
    __Vtemp_356[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [2U][0U]);
    __Vtemp_356[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [2U][1U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][1U]));
    __Vtemp_356[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [2U][2U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][2U]));
    __Vtemp_356[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [2U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [2U][3U]));
    bufp->fullWData(oldp+455,(__Vtemp_356),108);
    bufp->fullBit(oldp+459,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+460,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+461,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+462,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+463,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [2U][0U])));
    bufp->fullBit(oldp+464,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+465,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullWData(oldp+466,(vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                              [3U]),109);
    bufp->fullBit(oldp+470,((1U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                   [3U][3U] >> 0xcU))));
    __Vtemp_360[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                       [3U][0U]);
    __Vtemp_360[1U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [3U][1U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][1U]));
    __Vtemp_360[2U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [3U][2U]) | (0xfffffffeU & 
                                     vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][2U]));
    __Vtemp_360[3U] = ((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                        [3U][3U]) | (0xffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                     [3U][3U]));
    bufp->fullWData(oldp+471,(__Vtemp_360),108);
    bufp->fullBit(oldp+475,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+476,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+477,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+478,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+479,((1U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [3U][0U])));
    bufp->fullBit(oldp+480,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+481,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullWData(oldp+482,(vlSelfRef.tlul_socket_m1__DOT__hreq_fifo_o),436);
    bufp->fullWData(oldp+496,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[0]),66);
    bufp->fullWData(oldp+499,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[1]),66);
    bufp->fullWData(oldp+502,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[2]),66);
    bufp->fullWData(oldp+505,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i[3]),66);
    bufp->fullCData(oldp+508,(vlSelfRef.tlul_socket_m1__DOT__hrequest),4);
    bufp->fullCData(oldp+509,(vlSelfRef.tlul_socket_m1__DOT__hgrant),4);
    bufp->fullWData(oldp+510,(vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i),109);
    bufp->fullWData(oldp+514,(vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o),66);
    bufp->fullBit(oldp+517,((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest))));
    bufp->fullWData(oldp+518,(vlSelfRef.tlul_socket_m1__DOT__arb_data),109);
    bufp->fullCData(oldp+522,(((((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__3__KET__) 
                                 << 3U) | ((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__2__KET__) 
                                           << 2U)) 
                               | (((IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__1__KET__) 
                                   << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__hfifo_rspvalid__BRA__0__KET__)))),4);
    bufp->fullCData(oldp+523,((0x3fU & (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
                                        >> 0x13U))),8);
    bufp->fullCData(oldp+524,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__idx_o),2);
    bufp->fullCData(oldp+525,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__masked_req),4);
    bufp->fullCData(oldp+526,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out),4);
    bufp->fullCData(oldp+527,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__arb_req),4);
    bufp->fullCData(oldp+528,((0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U))),4);
    bufp->fullCData(oldp+529,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__winner),4);
    bufp->fullIData(oldp+530,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__sv2v_autoblock_3__DOT__i),32);
    bufp->fullBit(oldp+531,((1U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])));
    bufp->fullBit(oldp+532,((1U & (vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U] 
                                   >> 0xcU))));
    __Vtemp_364[0U] = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
    __Vtemp_364[1U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
                       | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
    __Vtemp_364[2U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
                       | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
    __Vtemp_364[3U] = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
                       | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
    bufp->fullWData(oldp+533,(__Vtemp_364),108);
    bufp->fullBit(oldp+537,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__rvalid_o));
    bufp->fullBit(oldp+538,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+539,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+540,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullBit(oldp+541,((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U])));
    bufp->fullWData(oldp+542,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o),65);
    bufp->fullBit(oldp+545,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+546,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullWData(oldp+547,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.tl_d_o),109);
    bufp->fullWData(oldp+551,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                              [0U]),66);
    bufp->fullBit(oldp+554,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                             [0U][0U])));
    bufp->fullBit(oldp+555,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+556,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+557,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                   [0U][2U] >> 1U))));
    bufp->fullWData(oldp+558,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+561,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+562,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+563,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+564,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullWData(oldp+565,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.tl_d_o),109);
    bufp->fullWData(oldp+569,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                              [1U]),66);
    bufp->fullBit(oldp+572,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                             [1U][0U])));
    bufp->fullBit(oldp+573,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+574,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+575,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                   [1U][2U] >> 1U))));
    bufp->fullWData(oldp+576,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+579,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+580,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+581,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+582,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullWData(oldp+583,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.tl_d_o),109);
    bufp->fullWData(oldp+587,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                              [2U]),66);
    bufp->fullBit(oldp+590,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                             [2U][0U])));
    bufp->fullBit(oldp+591,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+592,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+593,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                   [2U][2U] >> 1U))));
    bufp->fullWData(oldp+594,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+597,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+598,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+599,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+600,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullWData(oldp+601,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.tl_d_o),109);
    bufp->fullWData(oldp+605,(vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                              [3U]),66);
    bufp->fullBit(oldp+608,((1U & vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                             [3U][0U])));
    bufp->fullBit(oldp+609,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+610,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+611,((1U & (vlSelfRef.tlul_socket_m1__DOT__hrsp_fifo_i
                                   [3U][2U] >> 1U))));
    bufp->fullWData(oldp+612,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellinp__rspfifo__wdata_i),65);
    bufp->fullBit(oldp+615,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__rvalid_o));
    bufp->fullBit(oldp+616,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+617,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+618,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty));
    bufp->fullWData(oldp+619,(vlSelfRef.tlul_adapter_sram__DOT__tl_o_int),66);
    bufp->fullBit(oldp+622,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready));
    bufp->fullBit(oldp+623,((IData)(((0x8000U == (0x1c000U 
                                                  & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                     & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rready)))));
    bufp->fullQData(oldp+624,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata),40);
    bufp->fullQData(oldp+626,(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata),40);
    bufp->fullBit(oldp+628,(vlSelfRef.tlul_adapter_sram__DOT__d_valid));
    bufp->fullBit(oldp+629,(vlSelfRef.tlul_adapter_sram__DOT__d_error));
    bufp->fullBit(oldp+630,(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp));
    bufp->fullIData(oldp+631,((((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__d_error)) 
                                & (IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp))
                                ? (IData)((vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                           >> 8U)) : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data)),32);
    bufp->fullCData(oldp+632,((0x7fU & (((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp) 
                                         & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                            >> 0xeU))
                                         ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                         : ((IData)(vlSelfRef.tlul_adapter_sram__DOT__vld_rd_rsp)
                                             ? (IData)(
                                                       (vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rdata 
                                                        >> 1U))
                                             : 0x2aU)))),7);
    bufp->fullBit(oldp+633,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+634,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+635,((1U & VL_REDXOR_32(((vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U] 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U]) 
                                                ^ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U])))));
    bufp->fullBit(oldp+636,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+637,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+638,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr));
    bufp->fullCData(oldp+639,(vlSelfRef.pwm_ramp_tb__DOT__adc_value_o),6);
    bufp->fullBit(oldp+640,(vlSelfRef.pwm_ramp_tb__DOT__adc_valid_o));
    bufp->fullDouble(oldp+641,((1.58730158730158721e-02 
                                * VL_ITOR_D_I(6, (IData)(vlSelfRef.pwm_ramp_tb__DOT__adc_value_o)))));
    bufp->fullDouble(oldp+643,((1.0 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev)));
    bufp->fullCData(oldp+645,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle),6);
    bufp->fullCData(oldp+646,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter),6);
    bufp->fullBit(oldp+647,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__clear));
    bufp->fullBit(oldp+648,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds));
    bufp->fullBit(oldp+649,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds_rise));
    bufp->fullBit(oldp+650,(((~ (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__lvds)) 
                             & (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q))));
    bufp->fullCData(oldp+651,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__count_q),2);
    bufp->fullBit(oldp+652,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__d_s));
    bufp->fullBit(oldp+653,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+654,(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__u_prim_edge_detect__DOT__serial_q));
    bufp->fullDouble(oldp+655,(vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev));
    bufp->fullCData(oldp+657,(vlSelfRef.multiple_pwm_ramp__DOT__adc_value_0),8);
    bufp->fullCData(oldp+658,(vlSelfRef.multiple_pwm_ramp__DOT__adc_value_1),8);
    bufp->fullBit(oldp+659,(vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_0));
    bufp->fullBit(oldp+660,(vlSelfRef.multiple_pwm_ramp__DOT__adc_valid_1));
    bufp->fullCData(oldp+661,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__duty_cycle),8);
    bufp->fullCData(oldp+662,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__counter),8);
    bufp->fullBit(oldp+663,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__clear));
    bufp->fullBit(oldp+664,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds));
    bufp->fullBit(oldp+665,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds_rise));
    bufp->fullBit(oldp+666,(((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__lvds)) 
                             & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q))));
    bufp->fullCData(oldp+667,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__count_q),2);
    bufp->fullBit(oldp+668,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__d_s));
    bufp->fullBit(oldp+669,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+670,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_0__DOT__u_prim_edge_detect__DOT__serial_q));
    bufp->fullCData(oldp+671,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__duty_cycle),8);
    bufp->fullCData(oldp+672,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__counter),8);
    bufp->fullBit(oldp+673,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__clear));
    bufp->fullBit(oldp+674,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds));
    bufp->fullBit(oldp+675,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds_rise));
    bufp->fullBit(oldp+676,(((~ (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__lvds)) 
                             & (IData)(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q))));
    bufp->fullCData(oldp+677,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__count_q),2);
    bufp->fullBit(oldp+678,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__d_s));
    bufp->fullBit(oldp+679,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_deglitch__DOT__gen_async__DOT__prim_flop_2sync__DOT__intq));
    bufp->fullBit(oldp+680,(vlSelfRef.multiple_pwm_ramp__DOT__u_pwm_ramp_1__DOT__u_prim_edge_detect__DOT__serial_q));
    bufp->fullCData(oldp+681,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray),5);
    bufp->fullCData(oldp+682,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr),5);
    bufp->fullCData(oldp+683,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))),4);
    bufp->fullBit(oldp+684,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                   >> 4U))));
    bufp->fullCData(oldp+685,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q),5);
    bufp->fullCData(oldp+686,((0x1fU & ((IData)(1U) 
                                        + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)))),5);
    bufp->fullCData(oldp+687,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))),4);
    bufp->fullBit(oldp+688,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                   >> 4U))));
    bufp->fullBit(oldp+689,(((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                             == (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr))));
    bufp->fullBit(oldp+690,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored));
    bufp->fullIData(oldp+691,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q),32);
    bufp->fullCData(oldp+692,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr),5);
    bufp->fullBit(oldp+693,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty));
    bufp->fullCData(oldp+694,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq),5);
    bufp->fullWData(oldp+695,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[0]),107);
    bufp->fullWData(oldp+699,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[1]),107);
    bufp->fullWData(oldp+703,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[2]),107);
    bufp->fullWData(oldp+707,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[3]),107);
    if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk) {
        __Vtemp_366[0U] = 0U;
        __Vtemp_366[1U] = 0U;
        __Vtemp_366[2U] = 0U;
        __Vtemp_366[3U] = 0U;
    } else {
        __Vtemp_366[0U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
            [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U];
        __Vtemp_366[1U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
            [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U];
        __Vtemp_366[2U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
            [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U];
        __Vtemp_366[3U] = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
            [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U];
    }
    bufp->fullWData(oldp+711,(__Vtemp_366),107);
    bufp->fullWData(oldp+715,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                              [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))]),107);
    bufp->fullQData(oldp+719,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[0]),64);
    bufp->fullQData(oldp+721,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[1]),64);
    bufp->fullQData(oldp+723,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[2]),64);
    bufp->fullQData(oldp+725,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[3]),64);
    bufp->fullBit(oldp+727,(vlSelfRef.tlul_adapter_sram__DOT__intg_error_q));
    bufp->fullBit(oldp+728,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready));
    bufp->fullBit(oldp+729,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid));
    bufp->fullBit(oldp+730,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
    bufp->fullBit(oldp+731,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)) 
                                   & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
    bufp->fullBit(oldp+732,(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q));
    bufp->fullBit(oldp+733,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o));
    bufp->fullBit(oldp+734,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+735,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+736,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+737,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+738,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+739,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+740,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+741,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+742,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+743,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+744,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+745,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+746,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o));
    bufp->fullBit(oldp+747,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+748,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+749,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+750,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+751,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+752,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+753,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+754,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+755,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+756,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+757,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+758,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+759,((1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                                   & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))))));
    bufp->fullBit(oldp+760,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o));
    bufp->fullBit(oldp+761,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__depth_o));
    bufp->fullBit(oldp+762,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+763,((1U & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+764,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+765,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+766,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+767,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+768,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+769,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+770,((2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+771,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+772,((1U & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullSData(oldp+773,(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding),9);
    bufp->fullCData(oldp+774,(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding),3);
    bufp->fullBit(oldp+775,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+776,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+777,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+778,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+779,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+780,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+781,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+782,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+783,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+784,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+785,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+786,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+787,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+788,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+789,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+790,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+791,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+792,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+793,((1U & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+794,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+795,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+796,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+797,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+798,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+799,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+800,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+801,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+802,((1U & ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullWData(oldp+803,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int),66);
    bufp->fullCData(oldp+806,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode),3);
    bufp->fullCData(oldp+807,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source),8);
    bufp->fullCData(oldp+808,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size),2);
    bufp->fullBit(oldp+809,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending));
    bufp->fullCData(oldp+810,(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type),4);
    bufp->fullBit(oldp+811,((1U & VL_REDXOR_32(((vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
                                                 ^ 
                                                 vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
                                                ^ vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U])))));
    bufp->fullBit(oldp+812,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+813,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+814,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+815,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+816,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+817,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+818,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+819,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+820,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+821,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+822,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+823,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+824,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+825,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+826,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+827,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+828,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+829,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+830,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+831,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+832,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+833,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+834,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+835,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+836,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+837,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+838,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+839,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+840,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+841,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+842,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+843,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+844,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+845,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+846,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+847,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+848,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+849,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+850,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+851,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+852,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+853,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+854,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+855,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+856,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+857,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+858,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+859,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+860,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+861,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+862,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+863,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+864,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+865,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+866,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+867,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+868,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+869,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+870,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+871,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+872,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+873,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+874,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+875,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+876,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+877,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+878,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+879,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+880,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+881,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+882,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+883,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+884,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+885,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+886,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+887,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+888,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+889,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+890,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+891,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+892,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+893,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+894,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+895,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+896,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+897,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+898,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+899,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+900,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+901,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+902,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+903,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+904,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+905,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+906,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+907,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+908,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+909,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+910,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+911,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+912,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+913,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+914,((1U & (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+915,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+916,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+917,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+918,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+919,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+920,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+921,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+922,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+923,((1U & ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+924,(vlSelfRef.tlul_socket_m1__DOT__arb_ready));
    bufp->fullCData(oldp+925,(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask),4);
    bufp->fullBit(oldp+926,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+927,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+928,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+929,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+930,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+931,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+932,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+933,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+934,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+935,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+936,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+937,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+938,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+939,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+940,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+941,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+942,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+943,((1U & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+944,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+945,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+946,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+947,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+948,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+949,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+950,((2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+951,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+952,((1U & ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+953,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+954,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+955,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+956,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+957,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+958,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+959,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+960,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+961,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+962,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+963,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+964,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+965,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+966,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+967,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+968,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+969,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+970,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+971,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+972,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+973,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+974,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+975,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+976,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+977,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+978,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+979,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+980,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+981,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+982,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+983,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+984,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+985,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+986,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+987,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+988,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+989,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+990,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+991,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+992,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                         >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+993,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+994,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                   >> 1U))));
    bufp->fullBit(oldp+995,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+996,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+997,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+998,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+999,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1000,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+1001,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+1002,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+1003,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1004,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+1005,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1006,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+1007,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1008,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1009,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+1010,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+1011,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+1012,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1013,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1014,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+1015,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+1016,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+1017,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1018,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+1019,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1020,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+1021,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1022,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1023,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+1024,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+1025,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+1026,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1027,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1028,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+1029,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+1030,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+1031,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1032,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+1033,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1034,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+1035,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1036,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1037,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__reqfifo__wready_o));
    bufp->fullBit(oldp+1038,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__full_o));
    bufp->fullBit(oldp+1039,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__depth_o));
    bufp->fullBit(oldp+1040,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1041,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1042,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+1043,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+1044,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+1045,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1046,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+1047,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1048,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+1049,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1050,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1051,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__Vcellout__rspfifo__wready_o));
    bufp->fullBit(oldp+1052,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__full_o));
    bufp->fullBit(oldp+1053,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__depth_o));
    bufp->fullBit(oldp+1054,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1055,((1U & (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    bufp->fullBit(oldp+1056,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    bufp->fullBit(oldp+1057,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst));
    bufp->fullBit(oldp+1058,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    ^ (IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullCData(oldp+1059,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1060,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullCData(oldp+1061,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q),2);
    bufp->fullCData(oldp+1062,((2U & ((~ ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                          >> 1U)) << 1U))),2);
    bufp->fullBit(oldp+1063,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1064,((1U & ((IData)(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                                    >> 1U))));
    bufp->fullBit(oldp+1065,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_sva));
    bufp->fullBit(oldp+1066,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
    bufp->fullBit(oldp+1067,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_sva));
    bufp->fullBit(oldp+1068,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__disable_d_error_sva));
    bufp->fullCData(oldp+1069,(vlSelfRef.prim_filter__DOT__stored_vector_q),4);
    bufp->fullBit(oldp+1070,(vlSelfRef.prim_filter__DOT__stored_value_q));
    bufp->fullBit(oldp+1071,((1U & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                    >> 3U))));
    bufp->fullCData(oldp+1072,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q),2);
    bufp->fullBit(oldp+1073,(vlSelfRef.prim_filter_ctr__DOT__filter_q));
    bufp->fullBit(oldp+1074,(vlSelfRef.prim_filter_ctr__DOT__stored_value_q));
    bufp->fullCData(oldp+1075,(vlSelfRef.tlul_adapter_host__DOT__tl_source),8);
    bufp->fullCData(oldp+1076,(vlSelfRef.tlul_adapter_host__DOT__outstanding_reqs_q),2);
    bufp->fullBit(oldp+1077,(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q));
    bufp->fullBit(oldp+1078,(vlSelfRef.prim_fifo_async_simple__DOT__src_ack));
    bufp->fullBit(oldp+1079,(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    bufp->fullBit(oldp+1080,(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    bufp->fullBit(oldp+1081,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs));
    bufp->fullBit(oldp+1082,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack));
    bufp->fullBit(oldp+1083,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    bufp->fullWData(oldp+1084,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),110);
    bufp->fullWData(oldp+1088,(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1091,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1095,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1098,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1102,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1105,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1109,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1112,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1116,(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1119,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__pend_req),2560);
    bufp->fullWData(oldp+1199,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__pend_req),2560);
    bufp->fullBit(oldp+1279,(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    bufp->fullBit(oldp+1280,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs));
    bufp->fullBit(oldp+1281,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
    bufp->fullBit(oldp+1282,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req));
    bufp->fullBit(oldp+1283,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    bufp->fullWData(oldp+1284,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1288,(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1291,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1295,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1298,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1302,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1305,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1309,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullWData(oldp+1312,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__reqfifo__DOT__gen_normal_fifo__DOT__storage),108);
    bufp->fullWData(oldp+1316,(vlSymsp->TOP__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage),65);
    bufp->fullCData(oldp+1319,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q),5);
    bufp->fullCData(oldp+1320,((0x1fU & ((IData)(1U) 
                                         + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)))),5);
    bufp->fullCData(oldp+1321,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d),5);
    bufp->fullCData(oldp+1322,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q),5);
    bufp->fullCData(oldp+1323,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))),4);
    bufp->fullBit(oldp+1324,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                    >> 4U))));
    bufp->fullCData(oldp+1325,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray),5);
    bufp->fullCData(oldp+1326,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr),5);
    bufp->fullCData(oldp+1327,((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr))),4);
    bufp->fullBit(oldp+1328,((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                    >> 4U))));
    bufp->fullCData(oldp+1329,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq),5);
    bufp->fullBit(oldp+1330,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)))));
    bufp->fullCData(oldp+1331,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__wdepth_o),3);
    bufp->fullCData(oldp+1332,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q),3);
    bufp->fullCData(oldp+1333,((7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)))),3);
    bufp->fullCData(oldp+1334,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi),3);
    bufp->fullCData(oldp+1335,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync),3);
    bufp->fullCData(oldp+1336,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q),3);
    bufp->fullBit(oldp+1337,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk));
    bufp->fullBit(oldp+1338,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
                                    >> 2U))));
    bufp->fullBit(oldp+1339,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q) 
                                    >> 2U))));
    bufp->fullCData(oldp+1340,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q))),2);
    bufp->fullCData(oldp+1341,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q))),2);
    bufp->fullCData(oldp+1342,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq),3);
    bufp->fullBit(oldp+1343,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)))));
    bufp->fullCData(oldp+1344,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__rdepth_o),3);
    bufp->fullCData(oldp+1345,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q),3);
    bufp->fullCData(oldp+1346,((7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))),3);
    bufp->fullCData(oldp+1347,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi),3);
    bufp->fullCData(oldp+1348,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync),3);
    bufp->fullBit(oldp+1349,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                              == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)))));
    bufp->fullBit(oldp+1350,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk));
    bufp->fullBit(oldp+1351,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
                                    >> 2U))));
    bufp->fullBit(oldp+1352,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi) 
                                    >> 2U))));
    bufp->fullCData(oldp+1353,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))),2);
    bufp->fullCData(oldp+1354,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi))),2);
    bufp->fullCData(oldp+1355,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq),3);
    bufp->fullBit(oldp+1356,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)))));
    bufp->fullCData(oldp+1357,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__rdepth_o),3);
    bufp->fullCData(oldp+1358,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q),3);
    bufp->fullCData(oldp+1359,((7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))),3);
    bufp->fullCData(oldp+1360,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi),3);
    bufp->fullCData(oldp+1361,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync),3);
    bufp->fullCData(oldp+1362,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q),3);
    bufp->fullCData(oldp+1363,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d),3);
    bufp->fullBit(oldp+1364,(((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                              == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)))));
    bufp->fullBit(oldp+1365,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk));
    bufp->fullBit(oldp+1366,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
                                    >> 2U))));
    bufp->fullBit(oldp+1367,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi) 
                                    >> 2U))));
    bufp->fullCData(oldp+1368,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))),2);
    bufp->fullCData(oldp+1369,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi))),2);
    bufp->fullCData(oldp+1370,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq),3);
    bufp->fullBit(oldp+1371,((1U & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)))));
    bufp->fullCData(oldp+1372,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__wdepth_o),3);
    bufp->fullCData(oldp+1373,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q),3);
    bufp->fullCData(oldp+1374,((7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)))),3);
    bufp->fullCData(oldp+1375,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi),3);
    bufp->fullCData(oldp+1376,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync),3);
    bufp->fullCData(oldp+1377,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q),3);
    bufp->fullCData(oldp+1378,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q),3);
    bufp->fullCData(oldp+1379,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d),3);
    bufp->fullBit(oldp+1380,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk));
    bufp->fullBit(oldp+1381,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
                                    >> 2U))));
    bufp->fullBit(oldp+1382,((1U & ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q) 
                                    >> 2U))));
    bufp->fullCData(oldp+1383,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q))),2);
    bufp->fullCData(oldp+1384,((3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q))),2);
    bufp->fullCData(oldp+1385,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq),3);
    bufp->fullBit(oldp+1386,(vlSelfRef.tlul_adapter_reg__DOT__outstanding_q));
    bufp->fullIData(oldp+1387,(vlSelfRef.tlul_adapter_reg__DOT__rdata_q),32);
    bufp->fullBit(oldp+1388,(vlSelfRef.tlul_adapter_reg__DOT__error_q));
    bufp->fullCData(oldp+1389,(vlSelfRef.tlul_adapter_reg__DOT__reqid_q),8);
    bufp->fullCData(oldp+1390,(vlSelfRef.tlul_adapter_reg__DOT__reqsz_q),2);
    bufp->fullCData(oldp+1391,(vlSelfRef.tlul_adapter_reg__DOT__rspop_q),3);
    bufp->fullIData(oldp+1392,(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage),17);
    bufp->fullQData(oldp+1393,(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage),40);
    bufp->fullCData(oldp+1395,(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage),5);
    bufp->fullCData(oldp+1396,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q),3);
    bufp->fullCData(oldp+1397,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d),3);
    bufp->fullCData(oldp+1398,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q),3);
    bufp->fullCData(oldp+1399,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d),3);
    bufp->fullIData(oldp+1400,(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata),17);
    bufp->fullCData(oldp+1401,(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rdata),5);
    bufp->fullIData(oldp+1402,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data),32);
    bufp->fullCData(oldp+1403,(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ),7);
    bufp->fullIData(oldp+1404,(vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask),32);
    bufp->fullBit(oldp+1405,(vlSelfRef.prim_cdc_rand_delay__02Eclk_i));
    bufp->fullBit(oldp+1406,(vlSelfRef.prim_cdc_rand_delay__02Erst_ni));
    bufp->fullBit(oldp+1407,(vlSelfRef.prev_data_i));
    bufp->fullBit(oldp+1408,(vlSelfRef.src_data_i));
    bufp->fullBit(oldp+1409,(vlSelfRef.dst_data_o));
    bufp->fullBit(oldp+1410,(vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i));
    bufp->fullBit(oldp+1411,(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni));
    bufp->fullBit(oldp+1412,(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i));
    bufp->fullBit(oldp+1413,(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    bufp->fullSData(oldp+1414,(vlSelfRef.prim_fifo_async_simple__02Ewdata_i),16);
    bufp->fullBit(oldp+1415,(vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i));
    bufp->fullBit(oldp+1416,(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni));
    bufp->fullBit(oldp+1417,(vlSelfRef.prim_fifo_async_simple__02Ervalid_o));
    bufp->fullBit(oldp+1418,(vlSelfRef.prim_fifo_async_simple__02Erready_i));
    bufp->fullSData(oldp+1419,(vlSelfRef.prim_fifo_async_simple__02Erdata_o),16);
    bufp->fullBit(oldp+1420,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i));
    bufp->fullBit(oldp+1421,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni));
    bufp->fullBit(oldp+1422,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    bufp->fullBit(oldp+1423,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    bufp->fullIData(oldp+1424,(vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i),32);
    bufp->fullCData(oldp+1425,(vlSelfRef.wdepth_o),5);
    bufp->fullBit(oldp+1426,(vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i));
    bufp->fullBit(oldp+1427,(vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni));
    bufp->fullBit(oldp+1428,(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o));
    bufp->fullBit(oldp+1429,(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    bufp->fullIData(oldp+1430,(vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o),32);
    bufp->fullCData(oldp+1431,(vlSelfRef.rdepth_o),5);
    bufp->fullBit(oldp+1432,(vlSelfRef.r_full_o));
    bufp->fullBit(oldp+1433,(vlSelfRef.r_notempty_o));
    bufp->fullBit(oldp+1434,(vlSelfRef.w_full_o));
    bufp->fullBit(oldp+1435,(vlSelfRef.w_sram_req_o));
    bufp->fullBit(oldp+1436,(vlSelfRef.w_sram_gnt_i));
    bufp->fullBit(oldp+1437,(vlSelfRef.w_sram_write_o));
    bufp->fullSData(oldp+1438,(vlSelfRef.w_sram_addr_o),16);
    bufp->fullIData(oldp+1439,(vlSelfRef.w_sram_wdata_o),32);
    bufp->fullIData(oldp+1440,(vlSelfRef.w_sram_wmask_o),32);
    bufp->fullBit(oldp+1441,(vlSelfRef.w_sram_rvalid_i));
    bufp->fullIData(oldp+1442,(vlSelfRef.w_sram_rdata_i),32);
    bufp->fullCData(oldp+1443,(vlSelfRef.w_sram_rerror_i),2);
    bufp->fullBit(oldp+1444,(vlSelfRef.r_sram_req_o));
    bufp->fullBit(oldp+1445,(vlSelfRef.r_sram_gnt_i));
    bufp->fullBit(oldp+1446,(vlSelfRef.r_sram_write_o));
    bufp->fullSData(oldp+1447,(vlSelfRef.r_sram_addr_o),16);
    bufp->fullIData(oldp+1448,(vlSelfRef.r_sram_wdata_o),32);
    bufp->fullIData(oldp+1449,(vlSelfRef.r_sram_wmask_o),32);
    bufp->fullBit(oldp+1450,(vlSelfRef.r_sram_rvalid_i));
    bufp->fullIData(oldp+1451,(vlSelfRef.r_sram_rdata_i),32);
    bufp->fullCData(oldp+1452,(vlSelfRef.r_sram_rerror_i),2);
    bufp->fullBit(oldp+1453,(vlSelfRef.prim_filter__02Eclk_i));
    bufp->fullBit(oldp+1454,(vlSelfRef.prim_filter__02Erst_ni));
    bufp->fullBit(oldp+1455,(vlSelfRef.prim_filter__02Eenable_i));
    bufp->fullBit(oldp+1456,(vlSelfRef.prim_filter__02Efilter_i));
    bufp->fullBit(oldp+1457,(vlSelfRef.prim_filter__02Efilter_o));
    bufp->fullBit(oldp+1458,(vlSelfRef.prim_filter_ctr__02Eclk_i));
    bufp->fullBit(oldp+1459,(vlSelfRef.prim_filter_ctr__02Erst_ni));
    bufp->fullBit(oldp+1460,(vlSelfRef.prim_filter_ctr__02Eenable_i));
    bufp->fullBit(oldp+1461,(vlSelfRef.prim_filter_ctr__02Efilter_i));
    bufp->fullCData(oldp+1462,(vlSelfRef.thresh_i),2);
    bufp->fullBit(oldp+1463,(vlSelfRef.prim_filter_ctr__02Efilter_o));
    bufp->fullBit(oldp+1464,(vlSelfRef.prim_subreg__02Eclk_i));
    bufp->fullBit(oldp+1465,(vlSelfRef.prim_subreg__02Erst_ni));
    bufp->fullBit(oldp+1466,(vlSelfRef.prim_subreg__02Ewe));
    bufp->fullIData(oldp+1467,(vlSelfRef.prim_subreg__02Ewd),32);
    bufp->fullBit(oldp+1468,(vlSelfRef.de));
    bufp->fullIData(oldp+1469,(vlSelfRef.prim_subreg__02Ed),32);
    bufp->fullBit(oldp+1470,(vlSelfRef.prim_subreg__02Eqe));
    bufp->fullIData(oldp+1471,(vlSelfRef.prim_subreg__02Eq),32);
    bufp->fullIData(oldp+1472,(vlSelfRef.prim_subreg__02Eds),32);
    bufp->fullIData(oldp+1473,(vlSelfRef.prim_subreg__02Eqs),32);
    bufp->fullBit(oldp+1474,(vlSelfRef.re));
    bufp->fullBit(oldp+1475,(vlSelfRef.prim_subreg_ext__02Ewe));
    bufp->fullIData(oldp+1476,(vlSelfRef.prim_subreg_ext__02Ewd),32);
    bufp->fullIData(oldp+1477,(vlSelfRef.prim_subreg_ext__02Ed),32);
    bufp->fullBit(oldp+1478,(vlSelfRef.prim_subreg_ext__02Eqe));
    bufp->fullBit(oldp+1479,(vlSelfRef.qre));
    bufp->fullIData(oldp+1480,(vlSelfRef.prim_subreg_ext__02Eq),32);
    bufp->fullIData(oldp+1481,(vlSelfRef.prim_subreg_ext__02Eds),32);
    bufp->fullIData(oldp+1482,(vlSelfRef.prim_subreg_ext__02Eqs),32);
    bufp->fullBit(oldp+1483,(vlSelfRef.sram2tlul__02Eclk_i));
    bufp->fullBit(oldp+1484,(vlSelfRef.sram2tlul__02Erst_ni));
    bufp->fullWData(oldp+1485,(vlSelfRef.sram2tlul__02Etl_o),109);
    bufp->fullWData(oldp+1489,(vlSelfRef.sram2tlul__02Etl_i),66);
    bufp->fullBit(oldp+1492,(vlSelfRef.mem_req_i));
    bufp->fullBit(oldp+1493,(vlSelfRef.mem_write_i));
    bufp->fullSData(oldp+1494,(vlSelfRef.mem_addr_i),12);
    bufp->fullIData(oldp+1495,(vlSelfRef.mem_wdata_i),32);
    bufp->fullBit(oldp+1496,(vlSelfRef.mem_rvalid_o));
    bufp->fullIData(oldp+1497,(vlSelfRef.mem_rdata_o),32);
    bufp->fullCData(oldp+1498,(vlSelfRef.mem_error_o),2);
    bufp->fullBit(oldp+1499,(vlSelfRef.tlul_adapter_host__02Eclk_i));
    bufp->fullBit(oldp+1500,(vlSelfRef.tlul_adapter_host__02Erst_ni));
    bufp->fullBit(oldp+1501,(vlSelfRef.req_i));
    bufp->fullBit(oldp+1502,(vlSelfRef.gnt_o));
    bufp->fullIData(oldp+1503,(vlSelfRef.addr_i),32);
    bufp->fullBit(oldp+1504,(vlSelfRef.we_i));
    bufp->fullIData(oldp+1505,(vlSelfRef.tlul_adapter_host__02Ewdata_i),32);
    bufp->fullCData(oldp+1506,(vlSelfRef.wdata_intg_i),7);
    bufp->fullCData(oldp+1507,(vlSelfRef.be_i),4);
    bufp->fullCData(oldp+1508,(vlSelfRef.instr_type_i),4);
    bufp->fullBit(oldp+1509,(vlSelfRef.valid_o));
    bufp->fullIData(oldp+1510,(vlSelfRef.tlul_adapter_host__02Erdata_o),32);
    bufp->fullCData(oldp+1511,(vlSelfRef.rdata_intg_o),7);
    bufp->fullBit(oldp+1512,(vlSelfRef.err_o));
    bufp->fullBit(oldp+1513,(vlSelfRef.intg_err_o));
    bufp->fullWData(oldp+1514,(vlSelfRef.tlul_adapter_host__02Etl_o),109);
    bufp->fullWData(oldp+1518,(vlSelfRef.tlul_adapter_host__02Etl_i),66);
    bufp->fullBit(oldp+1521,(vlSelfRef.tlul_adapter_reg__02Eclk_i));
    bufp->fullBit(oldp+1522,(vlSelfRef.tlul_adapter_reg__02Erst_ni));
    bufp->fullWData(oldp+1523,(vlSelfRef.tlul_adapter_reg__02Etl_i),109);
    bufp->fullWData(oldp+1527,(vlSelfRef.tlul_adapter_reg__02Etl_o),66);
    bufp->fullCData(oldp+1530,(vlSelfRef.tlul_adapter_reg__02Een_ifetch_i),4);
    bufp->fullBit(oldp+1531,(vlSelfRef.tlul_adapter_reg__02Eintg_error_o));
    bufp->fullBit(oldp+1532,(vlSelfRef.re_o));
    bufp->fullBit(oldp+1533,(vlSelfRef.tlul_adapter_reg__02Ewe_o));
    bufp->fullCData(oldp+1534,(vlSelfRef.tlul_adapter_reg__02Eaddr_o),8);
    bufp->fullIData(oldp+1535,(vlSelfRef.tlul_adapter_reg__02Ewdata_o),32);
    bufp->fullCData(oldp+1536,(vlSelfRef.be_o),4);
    bufp->fullBit(oldp+1537,(vlSelfRef.busy_i));
    bufp->fullIData(oldp+1538,(vlSelfRef.tlul_adapter_reg__02Erdata_i),32);
    bufp->fullBit(oldp+1539,(vlSelfRef.error_i));
    bufp->fullBit(oldp+1540,(vlSelfRef.tlul_adapter_sram__02Eclk_i));
    bufp->fullBit(oldp+1541,(vlSelfRef.tlul_adapter_sram__02Erst_ni));
    bufp->fullWData(oldp+1542,(vlSelfRef.tlul_adapter_sram__02Etl_i),109);
    bufp->fullWData(oldp+1546,(vlSelfRef.tlul_adapter_sram__02Etl_o),66);
    bufp->fullCData(oldp+1549,(vlSelfRef.tlul_adapter_sram__02Een_ifetch_i),4);
    bufp->fullBit(oldp+1550,(vlSelfRef.req_o));
    bufp->fullCData(oldp+1551,(vlSelfRef.req_type_o),4);
    bufp->fullBit(oldp+1552,(vlSelfRef.gnt_i));
    bufp->fullBit(oldp+1553,(vlSelfRef.tlul_adapter_sram__02Ewe_o));
    bufp->fullSData(oldp+1554,(vlSelfRef.tlul_adapter_sram__02Eaddr_o),12);
    bufp->fullIData(oldp+1555,(vlSelfRef.tlul_adapter_sram__02Ewdata_o),32);
    bufp->fullIData(oldp+1556,(vlSelfRef.wmask_o),32);
    bufp->fullBit(oldp+1557,(vlSelfRef.tlul_adapter_sram__02Eintg_error_o));
    bufp->fullIData(oldp+1558,(vlSelfRef.tlul_adapter_sram__02Erdata_i),32);
    bufp->fullBit(oldp+1559,(vlSelfRef.rvalid_i));
    bufp->fullCData(oldp+1560,(vlSelfRef.rerror_i),2);
    bufp->fullBit(oldp+1561,(vlSelfRef.compound_txn_in_progress_o));
    bufp->fullCData(oldp+1562,(vlSelfRef.readback_en_i),4);
    bufp->fullBit(oldp+1563,(vlSelfRef.readback_error_o));
    bufp->fullBit(oldp+1564,(vlSelfRef.wr_collision_i));
    bufp->fullBit(oldp+1565,(vlSelfRef.write_pending_i));
    bufp->fullBit(oldp+1566,(vlSelfRef.tlul_assert_multiple__02Eclk_i));
    bufp->fullBit(oldp+1567,(vlSelfRef.tlul_assert_multiple__02Erst_ni));
    bufp->fullWData(oldp+1568,(vlSelfRef.h2d),218);
    bufp->fullWData(oldp+1575,(vlSelfRef.d2h),132);
    bufp->fullBit(oldp+1580,(vlSelfRef.clk_h_i));
    bufp->fullBit(oldp+1581,(vlSelfRef.rst_h_ni));
    bufp->fullBit(oldp+1582,(vlSelfRef.clk_d_i));
    bufp->fullBit(oldp+1583,(vlSelfRef.rst_d_ni));
    bufp->fullWData(oldp+1584,(vlSelfRef.tlul_fifo_async__02Etl_h_i),109);
    bufp->fullWData(oldp+1588,(vlSelfRef.tlul_fifo_async__02Etl_h_o),66);
    bufp->fullWData(oldp+1591,(vlSelfRef.tlul_fifo_async__02Etl_d_o),109);
    bufp->fullWData(oldp+1595,(vlSelfRef.tlul_fifo_async__02Etl_d_i),66);
    bufp->fullBit(oldp+1598,(vlSelfRef.tlul_socket_1n__02Eclk_i));
    bufp->fullBit(oldp+1599,(vlSelfRef.tlul_socket_1n__02Erst_ni));
    bufp->fullWData(oldp+1600,(vlSelfRef.tlul_socket_1n__02Etl_h_i),109);
    bufp->fullWData(oldp+1604,(vlSelfRef.tlul_socket_1n__02Etl_h_o),66);
    bufp->fullWData(oldp+1607,(vlSelfRef.tlul_socket_1n__02Etl_d_o),436);
    bufp->fullWData(oldp+1621,(vlSelfRef.tlul_socket_1n__02Etl_d_i),264);
    bufp->fullCData(oldp+1630,(vlSelfRef.dev_select_i),3);
    bufp->fullBit(oldp+1631,(vlSelfRef.tlul_socket_m1__02Eclk_i));
    bufp->fullBit(oldp+1632,(vlSelfRef.tlul_socket_m1__02Erst_ni));
    bufp->fullWData(oldp+1633,(vlSelfRef.tlul_socket_m1__02Etl_h_i),436);
    bufp->fullWData(oldp+1647,(vlSelfRef.tlul_socket_m1__02Etl_h_o),264);
    bufp->fullWData(oldp+1656,(vlSelfRef.tlul_socket_m1__02Etl_d_o),109);
    bufp->fullWData(oldp+1660,(vlSelfRef.tlul_socket_m1__02Etl_d_i),66);
    bufp->fullBit(oldp+1663,(vlSelfRef.multiple_pwm_ramp__02Eclk_i));
    bufp->fullBit(oldp+1664,(vlSelfRef.multiple_pwm_ramp__02Erst_ni));
    bufp->fullBit(oldp+1665,(vlSelfRef.multiple_pwm_ramp__02Eenable_i));
    bufp->fullCData(oldp+1666,(vlSelfRef.step_i),8);
    bufp->fullBit(oldp+1667,(vlSelfRef.lvds_0_i));
    bufp->fullBit(oldp+1668,(vlSelfRef.lvds_1_i));
    bufp->fullBit(oldp+1669,(vlSelfRef.pwm_0_o));
    bufp->fullBit(oldp+1670,(vlSelfRef.pwm_1_o));
    bufp->fullCData(oldp+1671,(vlSelfRef.adc_value_o),8);
    bufp->fullBit(oldp+1672,(vlSelfRef.adc_valid_o));
    bufp->fullBit(oldp+1673,(vlSelfRef.prim_fifo_async_simple__DOT__dst_ack));
    bufp->fullSData(oldp+1674,(vlSelfRef.prim_fifo_async_simple__DOT__data_q),16);
    bufp->fullBit(oldp+1675,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__chk_flag));
    bufp->fullBit(oldp+1676,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    bufp->fullBit(oldp+1677,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d));
    bufp->fullBit(oldp+1678,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    bufp->fullBit(oldp+1679,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d));
    bufp->fullBit(oldp+1680,(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake));
    bufp->fullCData(oldp+1681,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d),5);
    bufp->fullCData(oldp+1682,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q),5);
    bufp->fullBit(oldp+1683,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc));
    bufp->fullBit(oldp+1684,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc));
    bufp->fullBit(oldp+1685,(((IData)(vlSelfRef.r_sram_gnt_i) 
                              & (IData)(vlSelfRef.r_sram_req_o))));
    bufp->fullBit(oldp+1686,((1U & ((IData)(vlSelfRef.w_sram_rvalid_i) 
                                    ^ (VL_REDXOR_32(vlSelfRef.w_sram_rdata_i) 
                                       ^ VL_REDXOR_2(vlSelfRef.w_sram_rerror_i))))));
    bufp->fullBit(oldp+1687,((1U & VL_REDXOR_2(vlSelfRef.r_sram_rerror_i))));
    bufp->fullBit(oldp+1688,(vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en));
    bufp->fullCData(oldp+1689,(vlSelfRef.prim_filter__DOT__stored_vector_d),4);
    bufp->fullBit(oldp+1690,(((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
                              | (0xfU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))));
    bufp->fullCData(oldp+1691,(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d),2);
    bufp->fullBit(oldp+1692,(((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
                              == (IData)(vlSelfRef.thresh_i))));
    bufp->fullBit(oldp+1693,(vlSelfRef.pwm_ramp_tb__DOT__clk_i));
    bufp->fullBit(oldp+1694,(((IData)(vlSelfRef.pwm_ramp_tb__DOT__reverse_i)
                               ? ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                  > (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle))
                               : ((IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__counter) 
                                  < (IData)(vlSelfRef.pwm_ramp_tb__DOT__u_pwm_ramp__DOT__duty_cycle)))));
    bufp->fullBit(oldp+1695,(((1.0 * vlSelfRef.pwm_ramp_tb__DOT__u_rc_filter__DOT__y_prev) 
                              > vlSelfRef.pwm_ramp_tb__DOT__analog_input)));
    bufp->fullCData(oldp+1696,(((IData)(vlSelfRef.we_i)
                                 ? (IData)(vlSelfRef.be_i)
                                 : 0xfU)),4);
    bufp->fullBit(oldp+1697,((1U & VL_REDXOR_32((3U 
                                                 & vlSelfRef.addr_i)))));
    bufp->fullBit(oldp+1698,((1U & (VL_REDXOR_16((0xfffcU 
                                                  & vlSelfRef.tlul_adapter_host__02Etl_i[0U])) 
                                    ^ VL_REDXOR_32(
                                                   (0x1ffffU 
                                                    & ((vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                                                        << 0x10U) 
                                                       | (vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                          >> 0x10U))))))));
    bufp->fullBit(oldp+1699,((IData)(((vlSelfRef.tlul_adapter_reg__DOT__tl_o_pre[2U] 
                                       >> 1U) & vlSelfRef.tlul_adapter_reg__02Etl_i[0U]))));
    bufp->fullBit(oldp+1700,((1U & ((~ (((0U == (7U 
                                                 & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                    >> 9U))) 
                                         | ((1U == 
                                             (7U & 
                                              (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                               >> 9U))) 
                                            | (4U == 
                                               (7U 
                                                & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                   >> 9U))))) 
                                        & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk) 
                                           & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk) 
                                              & ((4U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                      >> 9U))) 
                                                 | ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                         >> 9U))) 
                                                    | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk))))))) 
                                    | ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_type_err) 
                                       | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__instr_wr_err))))));
    bufp->fullBit(oldp+1701,(((0U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                            >> 9U))) 
                              | ((1U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                               >> 9U))) 
                                 | (4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                 >> 9U)))))));
    bufp->fullBit(oldp+1702,(((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__addr_sz_chk) 
                              & ((IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__mask_chk) 
                                 & ((4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                  >> 9U))) 
                                    | ((1U == (7U & 
                                               (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                                >> 9U))) 
                                       | (IData)(vlSelfRef.tlul_adapter_reg__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->fullBit(oldp+1703,((0U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullBit(oldp+1704,((1U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullBit(oldp+1705,((4U == (7U & (vlSelfRef.tlul_adapter_reg__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullCData(oldp+1706,((0xfU & ((IData)(1U) 
                                        << (3U & (vlSelfRef.tlul_adapter_reg__02Etl_i[1U] 
                                                  >> 0x1cU))))),4);
    bufp->fullBit(oldp+1707,((1U & ((~ (((0U == (7U 
                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                    >> 9U))) 
                                         | ((1U == 
                                             (7U & 
                                              (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 9U))) 
                                            | (4U == 
                                               (7U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 9U))))) 
                                        & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                                           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
                                              & ((4U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                      >> 9U))) 
                                                 | ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                         >> 9U))) 
                                                    | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk))))))) 
                                    | ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_type_err) 
                                       | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err))))));
    bufp->fullBit(oldp+1708,((1U & VL_REDXOR_32((((
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                                   ^ 
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[1U]) 
                                                  ^ 
                                                  vlSelfRef.tlul_adapter_sram__02Etl_i[2U]) 
                                                 ^ 
                                                 vlSelfRef.tlul_adapter_sram__02Etl_i[3U])))));
    bufp->fullBit(oldp+1709,((IData)(((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                       >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]))));
    bufp->fullBit(oldp+1710,(((~ (IData)(vlSelfRef.tlul_adapter_sram__02Ewe_o)) 
                              & ((IData)(vlSelfRef.req_o) 
                                 & (IData)(vlSelfRef.gnt_i)))));
    bufp->fullSData(oldp+1711,((0xfffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                           << 2U) | 
                                          (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                           >> 0x1eU)))),12);
    bufp->fullBit(oldp+1712,(((IData)(vlSelfRef.req_o) 
                              & (IData)(vlSelfRef.gnt_i))));
    bufp->fullBit(oldp+1713,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
                              & ((~ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                    >> 0xcU)))));
    bufp->fullIData(oldp+1714,((vlSelfRef.tlul_adapter_sram__02Erdata_i 
                                & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask)),32);
    bufp->fullBit(oldp+1715,((1U & (IData)(vlSelfRef.rerror_i))));
    bufp->fullBit(oldp+1716,((1U & VL_REDXOR_32((0xfffU 
                                                 & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                                     << 2U) 
                                                    | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                       >> 0x1eU)))))));
    bufp->fullBit(oldp+1717,(((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                            >> 9U))) 
                              | ((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                               >> 9U))) 
                                 | (4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 9U)))))));
    bufp->fullBit(oldp+1718,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                              & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
                                 & ((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                  >> 9U))) 
                                    | ((1U == (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U))) 
                                       | (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk)))))));
    bufp->fullBit(oldp+1719,((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullBit(oldp+1720,((1U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullBit(oldp+1721,((4U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                           >> 9U)))));
    bufp->fullCData(oldp+1722,((0xfU & ((IData)(1U) 
                                        << (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                  >> 0x1cU))))),4);
    bufp->fullBit(oldp+1723,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                              & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+1724,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                              & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullQData(oldp+1725,((((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                 & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                                 ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                                 : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage)),40);
    bufp->fullBit(oldp+1727,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                              & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+1728,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
                              & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)))));
    bufp->fullBit(oldp+1729,(((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
                              & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)))));
    __Vtemp_369[0U] = ((vlSelfRef.h2d[4U] << 0x13U) 
                       | (vlSelfRef.h2d[3U] >> 0xdU));
    __Vtemp_369[1U] = ((vlSelfRef.h2d[5U] << 0x13U) 
                       | (vlSelfRef.h2d[4U] >> 0xdU));
    __Vtemp_369[2U] = ((vlSelfRef.h2d[6U] << 0x13U) 
                       | (vlSelfRef.h2d[5U] >> 0xdU));
    __Vtemp_369[3U] = (0x1fffU & (vlSelfRef.h2d[6U] 
                                  >> 0xdU));
    bufp->fullWData(oldp+1730,(__Vtemp_369),109);
    __Vtemp_372[0U] = ((vlSelfRef.d2h[3U] << 0x1eU) 
                       | (vlSelfRef.d2h[2U] >> 2U));
    __Vtemp_372[1U] = ((vlSelfRef.d2h[4U] << 0x1eU) 
                       | (vlSelfRef.d2h[3U] >> 2U));
    __Vtemp_372[2U] = (3U & (vlSelfRef.d2h[4U] >> 2U));
    bufp->fullWData(oldp+1734,(__Vtemp_372),66);
    bufp->fullCData(oldp+1737,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__0__KET____DOT__tlul_assert__DOT__d_mask),8);
    __Vtemp_375[0U] = vlSelfRef.h2d[0U];
    __Vtemp_375[1U] = vlSelfRef.h2d[1U];
    __Vtemp_375[2U] = vlSelfRef.h2d[2U];
    __Vtemp_375[3U] = (0x1fffU & vlSelfRef.h2d[3U]);
    bufp->fullWData(oldp+1738,(__Vtemp_375),109);
    __Vtemp_378[0U] = vlSelfRef.d2h[0U];
    __Vtemp_378[1U] = vlSelfRef.d2h[1U];
    __Vtemp_378[2U] = (3U & vlSelfRef.d2h[2U]);
    bufp->fullWData(oldp+1742,(__Vtemp_378),66);
    bufp->fullCData(oldp+1745,(vlSelfRef.tlul_assert_multiple__DOT__gen_assert__BRA__1__KET____DOT__tlul_assert__DOT__d_mask),8);
    bufp->fullBit(oldp+1746,((1U & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                                    >> 0xcU))));
    __Vtemp_381[0U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[0U] 
                                     >> 1U));
    __Vtemp_381[1U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                                     >> 1U));
    __Vtemp_381[2U] = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                        << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                                     >> 1U));
    __Vtemp_381[3U] = (0x7ffU & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                                 >> 1U));
    bufp->fullWData(oldp+1747,(__Vtemp_381),107);
    bufp->fullBit(oldp+1751,((1U & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])));
    bufp->fullBit(oldp+1752,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+1753,(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr));
    bufp->fullBit(oldp+1754,((1U & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
                                    >> 1U))));
    bufp->fullQData(oldp+1755,((((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                                 << 0x3fU) | (((QData)((IData)(
                                                               vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                                               << 0x1fU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                                 >> 1U)))),64);
    bufp->fullBit(oldp+1757,((1U & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U])));
    bufp->fullQData(oldp+1758,(((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                 ? 0ULL : vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])),64);
    bufp->fullBit(oldp+1760,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr));
    bufp->fullBit(oldp+1761,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr));
    bufp->fullQData(oldp+1762,(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                               [(3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]),64);
    bufp->fullBit(oldp+1764,((1U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                                    >> 0xcU))));
    if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU))) {
        __Vtemp_383[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        __Vtemp_383[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        __Vtemp_383[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        __Vtemp_383[3U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    } else {
        __Vtemp_383[0U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_383[1U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_383[2U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        __Vtemp_383[3U] = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    bufp->fullWData(oldp+1765,(__Vtemp_383),110);
    bufp->fullBit(oldp+1769,((1U & vlSelfRef.tlul_socket_1n__02Etl_h_i[0U])));
    bufp->fullCData(oldp+1770,((0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                         >> 1U))),8);
    bufp->fullCData(oldp+1771,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                      >> 9U))),2);
    bufp->fullCData(oldp+1772,((1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                               >> 0x14U)))),8);
    bufp->fullCData(oldp+1773,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                      >> 0x1cU))),2);
    bufp->fullCData(oldp+1774,((2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                               >> 7U)))),8);
    bufp->fullCData(oldp+1775,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                      >> 0xfU))),2);
    bufp->fullCData(oldp+1776,((3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                << 6U) 
                                               | (0x3cU 
                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                     >> 0x1aU)))))),8);
    bufp->fullCData(oldp+1777,((3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                      >> 2U))),2);
    bufp->fullBit(oldp+1778,((1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U])));
    bufp->fullBit(oldp+1779,((1U & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                                    >> 1U))));
    if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U))) {
        __Vtemp_385[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_385[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_385[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_385[0U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_385[1U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_385[2U] = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1780,(__Vtemp_385),65);
    __Vtemp_390[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                        >> 7U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                         >> 7U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                           >> 7U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_391[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                        >> 7U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_391[1U] = __Vtemp_390[1U];
    __Vtemp_391[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                   >> 7U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                      >> 7U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                                        >> 7U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+1783,(__Vtemp_391),66);
    __Vtemp_394[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                     >> 6U));
    __Vtemp_394[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                        << 0x1aU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[7U] 
                                     >> 6U));
    __Vtemp_394[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                             >> 6U));
    bufp->fullWData(oldp+1786,(__Vtemp_394),66);
    bufp->fullBit(oldp+1789,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                               ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                                 >> 7U))
                                              ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                              : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->fullBit(oldp+1790,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                    >> 6U))));
    bufp->fullBit(oldp+1791,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                                    >> 7U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_402[0U] = 0U;
        __Vtemp_402[1U] = 0U;
        __Vtemp_402[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                   >> 7U))) {
        __Vtemp_402[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_402[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_402[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_402[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_402[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_402[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1792,(__Vtemp_402),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
            >> 7U))) {
        __Vtemp_404[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_404[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_404[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_404[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_404[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_404[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1795,(__Vtemp_404),65);
    __Vtemp_409[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 5U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                         >> 5U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                           >> 5U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_410[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                        >> 5U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_410[1U] = __Vtemp_409[1U];
    __Vtemp_410[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                   >> 5U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                      >> 5U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                                        >> 5U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+1798,(__Vtemp_410),66);
    __Vtemp_413[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                     >> 4U));
    __Vtemp_413[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                        << 0x1cU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[5U] 
                                     >> 4U));
    __Vtemp_413[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                             >> 4U));
    bufp->fullWData(oldp+1801,(__Vtemp_413),66);
    bufp->fullBit(oldp+1804,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                               ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                                 >> 5U))
                                              ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                              : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->fullBit(oldp+1805,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                    >> 4U))));
    bufp->fullBit(oldp+1806,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                                    >> 5U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_421[0U] = 0U;
        __Vtemp_421[1U] = 0U;
        __Vtemp_421[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
                   >> 5U))) {
        __Vtemp_421[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_421[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_421[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_421[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_421[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_421[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1807,(__Vtemp_421),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[6U] 
            >> 5U))) {
        __Vtemp_423[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_423[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_423[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_423[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_423[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_423[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1810,(__Vtemp_423),65);
    __Vtemp_428[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 3U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                         >> 3U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                           >> 3U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_429[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                        >> 3U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_429[1U] = __Vtemp_428[1U];
    __Vtemp_429[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                   >> 3U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                      >> 3U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                                        >> 3U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+1813,(__Vtemp_429),66);
    __Vtemp_432[0U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                     >> 2U));
    __Vtemp_432[1U] = ((vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                        << 0x1eU) | (vlSelfRef.tlul_socket_1n__02Etl_d_i[3U] 
                                     >> 2U));
    __Vtemp_432[2U] = (3U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                             >> 2U));
    bufp->fullWData(oldp+1816,(__Vtemp_432),66);
    bufp->fullBit(oldp+1819,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                               ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                                 >> 3U))
                                              ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                              : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->fullBit(oldp+1820,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                    >> 2U))));
    bufp->fullBit(oldp+1821,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                                    >> 3U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_440[0U] = 0U;
        __Vtemp_440[1U] = 0U;
        __Vtemp_440[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
                   >> 3U))) {
        __Vtemp_440[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_440[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_440[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_440[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_440[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_440[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1822,(__Vtemp_440),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[4U] 
            >> 3U))) {
        __Vtemp_442[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_442[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_442[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_442[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_442[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_442[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1825,(__Vtemp_442),65);
    __Vtemp_447[1U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                     ? 0U
                                                                     : 
                                                                    (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                      & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                         >> 1U))
                                                                      ? 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                      : 
                                                                     vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                       ? 0U
                                                                       : 
                                                                      (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                        & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                           >> 1U))
                                                                        ? 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                        : 
                                                                       vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                     >> 1U))) 
                                              >> 0x20U)) 
                                     << 1U));
    __Vtemp_448[0U] = (((IData)((((QData)((IData)(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                        >> 1U))
                                                     ? 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                     : 
                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                  << 0x3fU) | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U)))) 
                        << 1U) | (IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__reqfifo__wready_o));
    __Vtemp_448[1U] = __Vtemp_447[1U];
    __Vtemp_448[2U] = (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellout__rspfifo__rvalid_o) 
                        << 1U) | ((IData)(((((QData)((IData)(
                                                             ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                               ? 0U
                                                               : 
                                                              (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                   >> 1U))
                                                                ? 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U]
                                                                : 
                                                               vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U])))) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                  ? 0U
                                                                  : 
                                                                 (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                   & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                      >> 1U))
                                                                   ? 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U]
                                                                   : 
                                                                  vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U])))) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                                                    ? 0U
                                                                    : 
                                                                   (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                                     & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                                        >> 1U))
                                                                     ? 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                                                     : 
                                                                    vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))) 
                                                  >> 1U))) 
                                           >> 0x20U)) 
                                  >> 0x1fU));
    bufp->fullWData(oldp+1828,(__Vtemp_448),66);
    __Vtemp_451[0U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[0U];
    __Vtemp_451[1U] = vlSelfRef.tlul_socket_1n__02Etl_d_i[1U];
    __Vtemp_451[2U] = (3U & vlSelfRef.tlul_socket_1n__02Etl_d_i[2U]);
    bufp->fullWData(oldp+1831,(__Vtemp_451),66);
    bufp->fullBit(oldp+1834,(((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty)
                               ? 0U : (1U & (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                              & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                                 >> 1U))
                                              ? vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U]
                                              : vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U])))));
    bufp->fullBit(oldp+1835,((1U & vlSelfRef.tlul_socket_1n__02Etl_d_i[0U])));
    bufp->fullBit(oldp+1836,((1U & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                                    >> 1U))));
    if (vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        __Vtemp_459[0U] = 0U;
        __Vtemp_459[1U] = 0U;
        __Vtemp_459[2U] = 0U;
    } else if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
                   >> 1U))) {
        __Vtemp_459[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_459[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_459[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_459[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_459[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_459[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1837,(__Vtemp_459),65);
    if (((IData)(vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
         & (vlSelfRef.tlul_socket_1n__02Etl_d_i[2U] 
            >> 1U))) {
        __Vtemp_461[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[0U];
        __Vtemp_461[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[1U];
        __Vtemp_461[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__Vcellinp__rspfifo__wdata_i[2U];
    } else {
        __Vtemp_461[0U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        __Vtemp_461[1U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        __Vtemp_461[2U] = vlSymsp->TOP__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d.__PVT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    bufp->fullWData(oldp+1840,(__Vtemp_461),65);
}
