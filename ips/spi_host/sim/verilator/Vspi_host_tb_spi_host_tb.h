// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vspi_host_tb.h for the primary calling header

#ifndef VERILATED_VSPI_HOST_TB_SPI_HOST_TB_H_
#define VERILATED_VSPI_HOST_TB_SPI_HOST_TB_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vspi_host_tb___024unit__03a__03atlul_utils;
class Vspi_host_tb_tlul_if;


class Vspi_host_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vspi_host_tb_spi_host_tb final : public VerilatedModule {
  public:
    // CELLS
    Vspi_host_tb_tlul_if* tl_if;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __PVT__clk_i;
        CData/*0:0*/ __PVT__rst_ni;
        CData/*0:0*/ __PVT__spi_sdio_i;
        CData/*0:0*/ __PVT__spi_sclk_o;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_we;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_re;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_error;
        CData/*0:0*/ u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q;
        CData/*0:0*/ u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q;
        CData/*0:0*/ u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__wdata_qe;
        CData/*7:0*/ u_spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q;
        CData/*3:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__addr_hit;
        CData/*0:0*/ u_spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__instr_error;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__malformed_meta_err;
        CData/*7:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q;
        CData/*1:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_wr_err;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__instr_type_err;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__addr_sz_chk;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__mask_chk;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__fulldata_chk;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en;
        CData/*1:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_state;
        CData/*1:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__next_state;
        CData/*7:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
        CData/*7:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__current_byte_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__cs_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdio_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sdioz_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk_en;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d;
        CData/*3:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q;
        CData/*3:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_d;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__r_wn_q;
        CData/*1:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_depth;
        CData/*1:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_depth;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__sclk;
        CData/*7:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready;
        CData/*0:0*/ u_spi_host__DOT__u_spi_host_core__DOT____Vcellinp__u_clk_div2__d_i;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
    };
    struct {
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst;
        CData/*7:0*/ u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT____Vlvbound_hda94dff7__0;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst;
        CData/*7:0*/ u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT____Vlvbound_hda94dff7__0;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        CData/*2:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_msb;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_msb;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set;
        CData/*0:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__5__inp;
        CData/*7:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__Vfuncout;
        CData/*7:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__6__inp;
        CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__Vfuncout;
        CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__10__inp;
        CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__Vfuncout;
        CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_invalid__11__val;
        CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__Vfuncout;
        CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__prim_mubi_pkg_mubi4_test_true_strict__26__val;
        CData/*0:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__Vfuncout;
        CData/*3:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__46__val;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__67__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__68__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__70__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__71__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__76__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__77__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__79__inp;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__Vfuncout;
        CData/*1:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__sv2v_cast_2DA09__80__inp;
        CData/*2:0*/ __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        CData/*2:0*/ __Vdly__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
        IData/*31:0*/ __PVT__read_data;
        IData/*31:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next;
        IData/*31:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q;
        VlWide<3>/*65:0*/ __PVT__u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre;
        IData/*23:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage;
        IData/*23:0*/ __PVT__u_spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage;
        IData/*31:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__Vfuncout;
        IData/*31:0*/ __Vfunc_u_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__8__inp;
        VlWide<4>/*108:0*/ __PVT__tl_i;
        VlWide<3>/*65:0*/ __PVT__tl_o;
    };

    // INTERNAL VARIABLES
    Vspi_host_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vspi_host_tb_spi_host_tb(Vspi_host_tb__Syms* symsp, const char* v__name);
    ~Vspi_host_tb_spi_host_tb();
    VL_UNCOPYABLE(Vspi_host_tb_spi_host_tb);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
