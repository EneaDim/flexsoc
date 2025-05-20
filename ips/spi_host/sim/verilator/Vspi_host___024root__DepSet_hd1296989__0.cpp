// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vspi_host.h for the primary calling header

#include "Vspi_host__pch.h"
#include "Vspi_host___024root.h"

VL_INLINE_OPT void Vspi_host___024root___ico_sequent__TOP__0(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___ico_sequent__TOP__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_simple__DOT__dst_ack;
    prim_fifo_async_simple__DOT__dst_ack = 0;
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake = 0;
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake = 0;
    VlWide<4>/*108:0*/ tlul_adapter_host__DOT__tl_out;
    VL_ZERO_W(109, tlul_adapter_host__DOT__tl_out);
    CData/*0:0*/ tlul_adapter_sram__DOT__instr_error;
    tlul_adapter_sram__DOT__instr_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__reqfifo_rready;
    tlul_adapter_sram__DOT__reqfifo_rready = 0;
    QData/*39:0*/ tlul_adapter_sram__DOT__rspfifo_rdata;
    tlul_adapter_sram__DOT__rspfifo_rdata = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_valid;
    tlul_adapter_sram__DOT__d_valid = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_error;
    tlul_adapter_sram__DOT__d_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__vld_rd_rsp;
    tlul_adapter_sram__DOT__vld_rd_rsp = 0;
    IData/*31:0*/ tlul_adapter_sram__DOT__wmask_int;
    tlul_adapter_sram__DOT__wmask_int = 0;
    IData/*31:0*/ tlul_adapter_sram__DOT__wdata_int;
    tlul_adapter_sram__DOT__wdata_int = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err;
    tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__instr_type_err;
    tlul_adapter_sram__DOT__u_err__DOT__instr_type_err = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk;
    tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__mask_chk;
    tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk;
    tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk = 0;
    VlWide<4>/*108:0*/ tlul_socket_1n__DOT__tl_t_o;
    VL_ZERO_W(109, tlul_socket_1n__DOT__tl_t_o);
    IData/*22:0*/ tlul_socket_1n__DOT__blanked_auser;
    tlul_socket_1n__DOT__blanked_auser = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select;
    tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select = 0;
    CData/*0:0*/ spi_host__DOT__u_spi_host_reg__DOT__reg_we;
    spi_host__DOT__u_spi_host_reg__DOT__reg_we = 0;
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp = 0;
    CData/*0:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout = 0;
    CData/*3:0*/ __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val;
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val = 0;
    QData/*56:0*/ __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload;
    __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload = 0;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<4>/*127:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<4>/*127:0*/ __Vtemp_9;
    VlWide<4>/*127:0*/ __Vtemp_10;
    VlWide<4>/*127:0*/ __Vtemp_11;
    VlWide<4>/*127:0*/ __Vtemp_12;
    VlWide<3>/*95:0*/ __Vtemp_13;
    VlWide<4>/*127:0*/ __Vtemp_14;
    VlWide<4>/*127:0*/ __Vtemp_15;
    VlWide<4>/*127:0*/ __Vtemp_16;
    VlWide<4>/*127:0*/ __Vtemp_17;
    VlWide<3>/*95:0*/ __Vtemp_18;
    VlWide<4>/*127:0*/ __Vtemp_19;
    VlWide<4>/*127:0*/ __Vtemp_20;
    VlWide<4>/*127:0*/ __Vtemp_21;
    VlWide<4>/*127:0*/ __Vtemp_22;
    VlWide<3>/*95:0*/ __Vtemp_23;
    VlWide<4>/*127:0*/ __Vtemp_24;
    VlWide<4>/*127:0*/ __Vtemp_25;
    VlWide<4>/*127:0*/ __Vtemp_26;
    VlWide<4>/*127:0*/ __Vtemp_27;
    // Body
    vlSelfRef.dst_data_o = vlSelfRef.src_data_i;
    vlSelfRef.mem_rvalid_o = ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                               >> 1U) & (1U == (7U 
                                                & ((vlSelfRef.sram2tlul__02Etl_i[2U] 
                                                    << 2U) 
                                                   | (vlSelfRef.sram2tlul__02Etl_i[1U] 
                                                      >> 0x1eU)))));
    vlSelfRef.mem_rdata_o = ((vlSelfRef.sram2tlul__02Etl_i[1U] 
                              << 0x10U) | (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                           >> 0x10U));
    vlSelfRef.mem_error_o = (3U & (- (IData)((1U & 
                                              (vlSelfRef.sram2tlul__02Etl_i[0U] 
                                               >> 1U)))));
    vlSelfRef.valid_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                               >> 1U));
    vlSelfRef.tlul_adapter_host__02Erdata_o = ((vlSelfRef.tlul_adapter_host__02Etl_i[1U] 
                                                << 0x10U) 
                                               | (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                                  >> 0x10U));
    vlSelfRef.rdata_intg_o = (0x7fU & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                                       >> 2U));
    vlSelfRef.err_o = (1U & (vlSelfRef.tlul_adapter_host__02Etl_i[0U] 
                             >> 1U));
    vlSelfRef.req_type_o = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                    >> 0xfU));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0xeU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0xcU));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    vlSelfRef.sram2tlul__02Etl_o[0U] = (IData)((1ULL 
                                                | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                   << 0x18U)));
    vlSelfRef.sram2tlul__02Etl_o[1U] = ((0xff000000U 
                                         & (0xf000000U 
                                            | ((IData)(vlSelfRef.mem_addr_i) 
                                               << 0x1eU))) 
                                        | (IData)((
                                                   (1ULL 
                                                    | ((QData)((IData)(vlSelfRef.mem_wdata_i)) 
                                                       << 0x18U)) 
                                                   >> 0x20U)));
    vlSelfRef.sram2tlul__02Etl_o[2U] = ((0xf0000000U 
                                         & vlSelfRef.sram2tlul__02Etl_o[2U]) 
                                        | (0xffffffU 
                                           & ((IData)(vlSelfRef.mem_addr_i) 
                                              >> 2U)));
    vlSelfRef.sram2tlul__02Etl_o[3U] = ((0x3fU & vlSelfRef.sram2tlul__02Etl_o[3U]) 
                                        | (0x1fc0U 
                                           & (((IData)(vlSelfRef.mem_req_i) 
                                               << 0xcU) 
                                              | (((IData)(vlSelfRef.mem_write_i)
                                                   ? 0U
                                                   : 4U) 
                                                 << 9U))));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
    tlul_adapter_sram__DOT__wmask_int = 0U;
    vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d = (((IData)(vlSelfRef.prim_filter_ctr__02Efilter_i) 
                                                   == (IData)(vlSelfRef.prim_filter_ctr__DOT__filter_q))
                                                   ? 
                                                  (3U 
                                                   & (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q) 
                                                       >= (IData)(vlSelfRef.thresh_i))
                                                       ? (IData)(vlSelfRef.thresh_i)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q))))
                                                   : 0U);
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp 
        = vlSelfRef.prim_fifo_async_sram_adapter__02Ewdata_i;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__inp;
    vlSelfRef.w_sram_wdata_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_A12ED__22__Vfuncout;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        vlSelfRef.addr_o = (0xfffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                       << 2U) | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1eU)));
        tlul_adapter_sram__DOT__wmask_int = ((0xffff0000U 
                                              & tlul_adapter_sram__DOT__wmask_int) 
                                             | ((0xff00U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                   >> 0x19U)))) 
                                                    << 8U)) 
                                                | (0xffU 
                                                   & (- (IData)(
                                                                (1U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                    >> 0x18U)))))));
        tlul_adapter_sram__DOT__wmask_int = ((0xffffU 
                                              & tlul_adapter_sram__DOT__wmask_int) 
                                             | (((- (IData)(
                                                            (1U 
                                                             & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                >> 0x1bU)))) 
                                                 << 0x18U) 
                                                | (0xff0000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                     >> 0x1aU)))) 
                                                      << 0x10U))));
    } else {
        vlSelfRef.addr_o = 0U;
    }
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__inp 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                               >> 0x18U));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_B0D6A__75__Vfuncout)) 
           << 1U);
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.gnt_o = (1U & vlSelfRef.tlul_adapter_host__02Etl_i[0U]);
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d 
        = ((IData)(vlSelfRef.r_sram_rvalid_i) ? vlSelfRef.r_sram_rdata_i
            : 0U);
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
    if ((0U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        }
    } else if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U < (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = (0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                    << 1U));
                }
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
            if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = ((0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                     << 1U)) | (IData)(vlSelfRef.spi_sdio_i));
                }
            } else {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = ((0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                 << 1U)) | (IData)(vlSelfRef.spi_sdio_i));
            }
        } else if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
            if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = (0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                << 1U));
            }
        } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
        }
    }
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    prim_fifo_async_simple__DOT__dst_ack = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
                                            & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.we_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                       >> 0xcU) & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                 >> 9U))) 
                                   | (1U == (7U & (
                                                   vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 9U)))));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    VL_CONCAT_WIQ(92,32,60, __Vtemp_3, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp 
                    = (0xfffffffcU & vlSelfRef.addr_i);
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp;
            }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp 
                                    = ((IData)(vlSelfRef.we_i)
                                        ? (IData)(vlSelfRef.be_i)
                                        : 0xfU);
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp 
                                        = vlSelfRef.tlul_adapter_host__02Ewdata_i;
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp;
                                }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              (1U 
                                                               | (([&]() {
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp 
                                            = ((VL_EXTEND_II(9,4, 
                                                             ([&]() {
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp 
                                                                = vlSelfRef.instr_type_i;
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout 
                                                                = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp;
                                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout))) 
                                                << 0xeU) 
                                               | VL_EXTEND_II(14,7, 
                                                              ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp 
                                                            = vlSelfRef.wdata_intg_i;
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp;
                                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout))));
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout) 
                                                                  << 1U)))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_4, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp 
                    = vlSelfRef.tlul_adapter_host__DOT__tl_source;
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout)), __Vtemp_3);
    tlul_adapter_host__DOT__tl_out[0U] = __Vtemp_4[0U];
    tlul_adapter_host__DOT__tl_out[1U] = __Vtemp_4[1U];
    tlul_adapter_host__DOT__tl_out[2U] = __Vtemp_4[2U];
    tlul_adapter_host__DOT__tl_out[3U] = (0x20U | (
                                                   ((IData)(vlSelfRef.req_i) 
                                                    << 0xcU) 
                                                   | ((((IData)(vlSelfRef.we_i)
                                                         ? 
                                                        ((0xfU 
                                                          == (IData)(vlSelfRef.be_i))
                                                          ? 0U
                                                          : 1U)
                                                         : 4U) 
                                                       << 9U) 
                                                      | __Vtemp_4[3U])));
    tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk 
        = ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 4U))) 
                                || (1U & ((1U == (3U 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                     >> 4U)))
                                           ? (~ (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                 >> 0x1cU))
                                           : ((2U == 
                                               (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))) 
                                              && (1U 
                                                  & (~ (IData)(
                                                               (0U 
                                                                != 
                                                                (3U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                                    >> 0x1cU)))))))))));
    tlul_adapter_sram__DOT__u_err__DOT__mask_chk = 
        ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                >> 0xcU)) && (1U & ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                  >> 4U)))
                                     ? (~ (IData)((0U 
                                                   != 
                                                   (0xfU 
                                                    & (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                         << 8U) 
                                                        | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                           >> 0x18U)) 
                                                       & (~ 
                                                          ((IData)(1U) 
                                                           << 
                                                           (3U 
                                                            & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                               >> 0x1cU)))))))))
                                     : ((1U == (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U)))
                                         ? ((0x20000000U 
                                             & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                             ? (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (3U 
                                                            & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                               >> 0x18U)))))
                                             : (~ (IData)(
                                                          (0U 
                                                           != 
                                                           (0xcU 
                                                            & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                               >> 0x18U))))))
                                         : (2U == (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                      >> 4U)))))));
    tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk 
        = ((1U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                  >> 0xcU)) && ((0U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                              >> 4U)))
                                 ? (0U != (0xfU & (
                                                   ((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                     << 8U) 
                                                    | (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                       >> 0x18U)) 
                                                   & ((IData)(1U) 
                                                      << 
                                                      (3U 
                                                       & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                          >> 0x1cU))))))
                                 : ((1U == (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                  >> 4U)))
                                     ? ((0x20000000U 
                                         & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                         ? (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x1aU)))
                                         : (3U == (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                      >> 0x18U))))
                                     : ((2U == (3U 
                                                & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                   >> 4U))) 
                                        && (0xfU == 
                                            (0xfU & 
                                             (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                              >> 0x18U)))))));
    tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_true_strict__78__Vfuncout)) 
           & ((0U == (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                >> 9U)))));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val 
        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                   >> 0xfU));
    __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout 
        = (1U & (~ ((6U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val)) 
                    | (9U == (IData)(__Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__val)))));
    tlul_adapter_sram__DOT__u_err__DOT__instr_type_err 
        = __Vfunc_tlul_adapter_sram__DOT__u_err__DOT__prim_mubi_pkg_mubi4_test_invalid__80__Vfuncout;
    tlul_adapter_sram__DOT__instr_error = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                               >> 0xfU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__Vfuncout 
                    = (1U & (~ ((6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val)) 
                                | (9U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__val)))));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_invalid__39__Vfuncout)) 
                                           | (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                   >> 0xfU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__54__Vfuncout)) 
                                              & ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__val 
                        = vlSelfRef.en_ifetch_i;
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__Vfuncout 
                        = (6U != (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_false_loose__56__Vfuncout))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit = 0U;
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((8U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | (((8U == (0xcU & (vlSelfRef.spi_host__02Etl_i[1U] 
                               >> 0x1cU))) << 2U) | 
              (((4U == (0xcU & (vlSelfRef.spi_host__02Etl_i[1U] 
                                >> 0x1cU))) << 1U) 
               | (0U == (0xcU & (vlSelfRef.spi_host__02Etl_i[1U] 
                                 >> 0x1cU))))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit 
        = ((7U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit)) 
           | ((0xcU == (0xcU & (vlSelfRef.spi_host__02Etl_i[1U] 
                                >> 0x1cU))) << 3U));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata 
        = (((QData)((IData)((vlSelfRef.rdata_i & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSelfRef.spi_host__02Etl_i[3U] 
                    >> 0xcU) & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (0xfffeU & vlSelfRef.tlul_socket_m1__02Etl_d_i[0U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U] 
        = ((0xffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                 >> 0x10U)) : 0U) << 0x10U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffff0000U & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (((1U == (7U & ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                              << 2U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                                        >> 0x1eU))))
                ? ((vlSelfRef.tlul_socket_m1__02Etl_d_i[1U] 
                    << 0x10U) | (vlSelfRef.tlul_socket_m1__02Etl_d_i[0U] 
                                 >> 0x10U)) : 0U) >> 0x10U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U] 
        = ((0xffffU & vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U]) 
           | (0xffff0000U & vlSelfRef.tlul_socket_m1__02Etl_d_i[1U]));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U] 
        = (1U & vlSelfRef.tlul_socket_m1__02Etl_d_i[2U]);
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    VL_CONCAT_WIQ(92,32,60, __Vtemp_8, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                        << 0x1dU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                     >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__227__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__inp 
                                    = (0xfU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xcU] 
                                                << 1U) 
                                               | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                                  >> 0x1fU)));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__228__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xbU] 
                                            << 1U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                              >> 0x1fU));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__229__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                  >> 8U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__230__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                                                                     >> 7U))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_9, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__inp 
                    = (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                                >> 1U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__226__Vfuncout)), __Vtemp_8);
    VL_CONCAT_WIW(102,2,100, __Vtemp_10, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xbU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__225__Vfuncout)), __Vtemp_9);
    VL_CONCAT_WIW(105,3,102, __Vtemp_11, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0xdU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__224__Vfuncout)), __Vtemp_10);
    VL_CONCAT_WIW(108,3,105, __Vtemp_12, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                             >> 0x10U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__223__Vfuncout)), __Vtemp_11);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_12[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_12[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_12[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                       >> 7U)) | __Vtemp_12[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_13, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                        << 0xaU) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                    >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__235__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                               >> 0x12U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__236__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[8U] 
                                            << 0xeU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                              >> 0x12U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__237__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[7U] 
                                                   << 5U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                     >> 0x1bU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__238__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                                                     >> 0x1aU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_14, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__inp 
                    = (1U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                                      >> 0x14U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__234__Vfuncout)), __Vtemp_13);
    VL_CONCAT_WIW(102,2,100, __Vtemp_15, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__inp 
                    = (vlSelfRef.tlul_socket_m1__02Etl_h_i[9U] 
                       >> 0x1eU);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__233__Vfuncout)), __Vtemp_14);
    VL_CONCAT_WIW(105,3,102, __Vtemp_16, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__inp 
                    = (7U & vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU]);
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__232__Vfuncout)), __Vtemp_15);
    VL_CONCAT_WIW(108,3,105, __Vtemp_17, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                             >> 3U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__231__Vfuncout)), __Vtemp_16);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_17[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_17[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_17[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0xaU] 
                       << 6U)) | __Vtemp_17[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_18, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                        << 0x17U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                     >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__243__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                               >> 5U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__244__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[5U] 
                                            << 0x1bU) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                              >> 5U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__245__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__inp 
                                            = (0x7fffffU 
                                               & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[4U] 
                                                   << 0x12U) 
                                                  | (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                     >> 0xeU)));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__246__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                                                     >> 0xdU))))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_19, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__inp 
                    = (2U | (0xfcU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                                      >> 7U)));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__242__Vfuncout)), __Vtemp_18);
    VL_CONCAT_WIW(102,2,100, __Vtemp_20, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x11U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__241__Vfuncout)), __Vtemp_19);
    VL_CONCAT_WIW(105,3,102, __Vtemp_21, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x13U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__240__Vfuncout)), __Vtemp_20);
    VL_CONCAT_WIW(108,3,105, __Vtemp_22, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                             >> 0x16U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__239__Vfuncout)), __Vtemp_21);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_22[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_22[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_22[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[6U] 
                       >> 0xdU)) | __Vtemp_22[3U]);
    VL_CONCAT_WIQ(92,32,60, __Vtemp_23, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__inp 
                    = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                        << 4U) | (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                  >> 0x1cU));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__inp;
            }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_D591E__251__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__inp 
                                    = (0xfU & (vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                               >> 0x18U));
                                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_B0D6A__252__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__inp 
                                        = ((vlSelfRef.tlul_socket_m1__02Etl_h_i[1U] 
                                            << 8U) 
                                           | (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                              >> 0x18U));
                                    vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__inp;
                                }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_9783B__253__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              ((([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__inp 
                                            = (0x7fffffU 
                                               & (vlSelfRef.tlul_socket_m1__02Etl_h_i[0U] 
                                                  >> 1U));
                                        vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_EDEFC__254__Vfuncout) 
                                                                << 1U) 
                                                               | (1U 
                                                                  & vlSelfRef.tlul_socket_m1__02Etl_h_i[0U])))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_24, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__inp 
                    = (3U | (0xfcU & ((vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                                       << 6U) | (0x3cU 
                                                 & (vlSelfRef.tlul_socket_m1__02Etl_h_i[2U] 
                                                    >> 0x1aU)))));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_15E34__250__Vfuncout)), __Vtemp_23);
    VL_CONCAT_WIW(102,2,100, __Vtemp_25, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__inp 
                    = (3U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 4U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_FDEB5__249__Vfuncout)), __Vtemp_24);
    VL_CONCAT_WIW(105,3,102, __Vtemp_26, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 6U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__248__Vfuncout)), __Vtemp_25);
    VL_CONCAT_WIW(108,3,105, __Vtemp_27, ([&]() {
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__inp 
                    = (7U & (vlSelfRef.tlul_socket_m1__02Etl_h_i[3U] 
                             >> 9U));
                vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_m1__DOT__sv2v_cast_3__247__Vfuncout)), __Vtemp_26);
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[0U] 
        = __Vtemp_27[0U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[1U] 
        = __Vtemp_27[1U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[2U] 
        = __Vtemp_27[2U];
    vlSelfRef.tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__hreq_fifo_i[3U] 
        = ((0x1000U & vlSelfRef.tlul_socket_m1__02Etl_h_i[3U]) 
           | __Vtemp_27[3U]);
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U] 
        = ((0xfffffff8U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                           << 2U)) | (IData)(vlSelfRef.dev_select_i));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[0U] 
                              >> 0x1eU)) | (0xfffffff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[1U] 
                              >> 0x1eU)) | (0xfffffff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U] 
        = (((4U & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   << 2U)) | (vlSelfRef.tlul_socket_1n__02Etl_h_i[2U] 
                              >> 0x1eU)) | (0x3ff8U 
                                            & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                                               << 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.wmask_o = tlul_adapter_sram__DOT__wmask_int;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    if (((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o))) {
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
            = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q))));
    }
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    tlul_adapter_sram__DOT__wdata_int = 0U;
    if ((0x1000U & vlSelfRef.tlul_adapter_sram__02Etl_i[3U])) {
        tlul_adapter_sram__DOT__wdata_int = ((0xffffff00U 
                                              & tlul_adapter_sram__DOT__wdata_int) 
                                             | (((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                  >> 0x18U) 
                                                 & (IData)(vlSelfRef.we_o))
                                                 ? 
                                                (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                                 >> 0x18U)
                                                 : 0U));
        tlul_adapter_sram__DOT__wdata_int = ((0xffff00ffU 
                                              & tlul_adapter_sram__DOT__wdata_int) 
                                             | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x19U) 
                                                  & (IData)(vlSelfRef.we_o))
                                                  ? 
                                                 (0xffU 
                                                  & vlSelfRef.tlul_adapter_sram__02Etl_i[1U])
                                                  : 0U) 
                                                << 8U));
        tlul_adapter_sram__DOT__wdata_int = ((0xff00ffffU 
                                              & tlul_adapter_sram__DOT__wdata_int) 
                                             | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x1aU) 
                                                  & (IData)(vlSelfRef.we_o))
                                                  ? 
                                                 (0xffU 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                     >> 8U))
                                                  : 0U) 
                                                << 0x10U));
        tlul_adapter_sram__DOT__wdata_int = ((0xffffffU 
                                              & tlul_adapter_sram__DOT__wdata_int) 
                                             | ((((vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                   >> 0x1bU) 
                                                  & (IData)(vlSelfRef.we_o))
                                                  ? 
                                                 (0xffU 
                                                  & (vlSelfRef.tlul_adapter_sram__02Etl_i[1U] 
                                                     >> 0x10U))
                                                  : 0U) 
                                                << 0x18U));
    }
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = tlul_adapter_host__DOT__tl_out[0U];
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = tlul_adapter_host__DOT__tl_out[1U];
    vlSelfRef.tlul_adapter_host__02Etl_o[2U] = tlul_adapter_host__DOT__tl_out[2U];
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = tlul_adapter_host__DOT__tl_out[3U];
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffffffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0xff000000U 
                                                   & tlul_adapter_host__DOT__tl_out[0U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0xff000000U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | (0xffffffU 
                                                   & tlul_adapter_host__DOT__tl_out[1U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffff8001U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0x7ffeU 
                                                   & tlul_adapter_host__DOT__tl_out[0U]));
    vlSelfRef.tlul_adapter_sram__DOT__error_det = (1U 
                                                   & ((IData)(tlul_adapter_sram__DOT__instr_error) 
                                                      | ((~ 
                                                          (((0U 
                                                             == 
                                                             (7U 
                                                              & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                 >> 9U))) 
                                                            | ((1U 
                                                                == 
                                                                (7U 
                                                                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                    >> 9U))) 
                                                               | (4U 
                                                                  == 
                                                                  (7U 
                                                                   & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                                                      >> 9U))))) 
                                                           & ((IData)(tlul_adapter_sram__DOT__u_err__DOT__addr_sz_chk) 
                                                              & ((IData)(tlul_adapter_sram__DOT__u_err__DOT__mask_chk) 
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
                                                                       | (IData)(tlul_adapter_sram__DOT__u_err__DOT__fulldata_chk))))))) 
                                                         | ((IData)(tlul_adapter_sram__DOT__u_err__DOT__instr_type_err) 
                                                            | (IData)(tlul_adapter_sram__DOT__u_err__DOT__instr_wr_err)))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next = 0U;
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next 
        = ((1U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
            ? ((0xfffffff8U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) 
                   << 2U) | (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) 
                              << 1U) | (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q))))
            : ((2U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                ? ((0xfffffff0U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                   | (((8U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid)) 
                              << 3U)) | (4U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)) 
                                               << 2U))) 
                      | ((2U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)) 
                                << 1U)) | (1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))))))
                : ((4U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                       | ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                           ? 0U : ((0x17U >= (0x1fU 
                                              & VL_SHIFTL_III(5,5,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                    ? (0xffU & (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                                >> 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                    : 0U))) : ((8U 
                                                & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                                                ? (0xffffff00U 
                                                   & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next)
                                                : 0xffffffffU))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x800U == (0xe00U & vlSelfRef.spi_host__02Etl_i[3U])));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.spi_host__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.spi_host__02Etl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                   >> 1U))) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U];
    }
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] = 0U;
    } else if (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                & (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                   >> 0xcU))) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    } else {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U];
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req)));
            if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__src_req;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
                = (1U & (~ (IData)(prim_fifo_async_simple__DOT__dst_ack)));
            if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
            = prim_fifo_async_simple__DOT__dst_ack;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
    vlSelfRef.wdata_o = tlul_adapter_sram__DOT__wdata_int;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.r_sram_req_o = 0U;
    if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) {
        vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q;
        vlSelfRef.r_sram_req_o = (1U & ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc)));
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d;
        vlSelfRef.r_sram_req_o = (1U & ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                              ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc)))));
    }
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata 
        = ((((4U != (7U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                           >> 9U))) ? 0U : 1U) << 0xfU) 
           | (((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
               << 0xeU) | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__inp 
                                = (0xfU & (vlSelfRef.tlul_adapter_sram__02Etl_i[0U] 
                                           >> 0xfU));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_EECFA__72__Vfuncout)) 
                            << 0xaU) | ((([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__inp 
                                    = (3U & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             >> 4U));
                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__73__Vfuncout)) 
                                         << 8U) | ([&]() {
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__inp 
                                = (0xffU & ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                                             << 4U) 
                                            | (vlSelfRef.tlul_adapter_sram__02Etl_i[2U] 
                                               >> 0x1cU)));
                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__74__Vfuncout))))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                    & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.spi_host__02Etl_i[1U] 
                           >> 0x1cU))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    tlul_adapter_sram__DOT__rspfifo_rdata = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0ULL
                                              : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                                                  ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                                                  : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[0U] 
        = (((IData)((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U)))) 
            << 1U) | (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[1U] 
        = (((IData)((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                      << 0x3fU) | (((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                    << 0x1fU) | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U)))) 
            >> 0x1fU) | ((IData)(((((QData)((IData)(
                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                    >> 1U))) 
                                  >> 0x20U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__drsp_fifo_o[2U] 
        = (((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o) 
            << 1U) | ((IData)(((((QData)((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[2U])) 
                                 << 0x3fU) | (((QData)((IData)(
                                                               vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[1U])) 
                                               << 0x1fU) 
                                              | ((QData)((IData)(
                                                                 vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rdata_o[0U])) 
                                                 >> 1U))) 
                               >> 0x20U)) >> 0x1fU));
    vlSelfRef.tlul_socket_1n__DOT__hold_all_requests 
        = ((0U != (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)) 
           & ((7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]) 
              != (IData)(vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding)));
    tlul_socket_1n__DOT__tl_t_o[0U] = (((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                         << 0x1eU) 
                                        | (0x3ffffffeU 
                                           & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U] 
                                              >> 2U))) 
                                       | (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o));
    tlul_socket_1n__DOT__tl_t_o[1U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                              >> 2U)) 
                                       | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                           << 0x1eU) 
                                          | (0x3ffffffeU 
                                             & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[1U] 
                                                >> 2U))));
    tlul_socket_1n__DOT__tl_t_o[2U] = ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                              >> 2U)) 
                                       | ((vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                           << 0x1eU) 
                                          | (0x3ffffffeU 
                                             & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[2U] 
                                                >> 2U))));
    tlul_socket_1n__DOT__tl_t_o[3U] = (((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o) 
                                        << 0xcU) | 
                                       ((1U & (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                               >> 2U)) 
                                        | (0xffeU & 
                                           (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[3U] 
                                            >> 2U))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.req_o) 
                                           & (IData)(vlSelfRef.gnt_i))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready)));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re 
        = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req));
    spi_host__DOT__u_spi_host_reg__DOT__reg_we = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
                                                  & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req));
    tlul_adapter_sram__DOT__d_error = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                       && (1U & ((1U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                      >> 0xfU)))
                                                  ? 
                                                 ((IData)(tlul_adapter_sram__DOT__rspfifo_rdata) 
                                                  | (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                     >> 0xeU))
                                                  : 
                                                 (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                  >> 0xeU))));
    tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                       && (1U & (IData)(
                                                        ((0x8000U 
                                                          != 
                                                          (0x1c000U 
                                                           & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                                         | (IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid)))));
    tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select 
        = ((0U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select 
        = ((1U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select 
        = ((2U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select 
        = ((3U == (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xfffffffeU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (1U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x11ffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xe00U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1e3fU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1c0U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1fcfU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x30U & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0x1ff0U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0xfU & tlul_socket_1n__DOT__tl_t_o[3U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xfffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf0000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][2U] = 
        ((0xf0000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][2U]) | (0xfffffffU & tlul_socket_1n__DOT__tl_t_o[2U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xf0ffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xf000000U & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xff000000U & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][1U]) | (0xffffffU & tlul_socket_1n__DOT__tl_t_o[1U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][0U]) | (0xfffffeU & tlul_socket_1n__DOT__tl_t_o[0U]));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[4U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [4U][3U]) | (0x1000U & ((tlul_socket_1n__DOT__tl_t_o[3U] 
                                   & ((4U <= (7U & 
                                              vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U])) 
                                      << 0xcU)) & (
                                                   (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__hold_all_requests)) 
                                                   << 0xcU))));
    tlul_socket_1n__DOT__blanked_auser = ((([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp 
                        = (0x1fU & (tlul_socket_1n__DOT__tl_t_o[0U] 
                                    >> 0x13U));
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_5__178__Vfuncout)) 
                                           << 0x12U) 
                                          | ((([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp 
                            = (0xfU & (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0xfU));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_EECFA__179__Vfuncout)) 
                                              << 0xeU) 
                                             | ((([&]() {
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[0U] 
                                = tlul_socket_1n__DOT__tl_t_o[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[1U] 
                                = tlul_socket_1n__DOT__tl_t_o[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[2U] 
                                = tlul_socket_1n__DOT__tl_t_o[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[3U] 
                                = tlul_socket_1n__DOT__tl_t_o[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__tl[3U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[0U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[0U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[1U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[2U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[2U];
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[3U] 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__tl[3U];
                            vlSelf->__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload = VL_RAND_RESET_Q(43);
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload 
                                = ((0x78000000000ULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload) 
                                   | (((QData)((IData)(
                                                       ((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[2U] 
                                                         << 4U) 
                                                        | (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                                           >> 0x1cU)))) 
                                       << 7U) | (QData)((IData)(
                                                                ((0x70U 
                                                                  & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[3U] 
                                                                     >> 5U)) 
                                                                 | (0xfU 
                                                                    & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[1U] 
                                                                       >> 0x18U)))))));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload 
                                = ((0x7fffffffffULL 
                                    & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload) 
                                   | ((QData)((IData)(
                                                      (0xfU 
                                                       & (vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__tl[0U] 
                                                          >> 0xfU)))) 
                                      << 0x27U));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__payload;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_extract_h2d_cmd_intg__183__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd_intg 
                                = (0x7fU & (IData)(
                                                   (([&]() {
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_i 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__185__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__inp 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_i;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__inp;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__186__Vfuncout;
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xfdffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x39U));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xfbffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3aU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xf7ffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3bU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xefffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3cU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xdfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3dU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0xbfffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3eU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    ((0x7fffffffffffffffULL 
                                                      & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o) 
                                                     | ((QData)((IData)(
                                                                        (1U 
                                                                         & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o))))) 
                                                        << 0x3fU));
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o 
                                                    = 
                                                    (0x5400000000000000ULL 
                                                     ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o);
                                                vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__data_o;
                                            }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__184__Vfuncout) 
                                                    >> 0x39U)));
                            __Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__unused_cmd_payload 
                                = (0x1ffffffffffffffULL 
                                   & ([&]() {
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_i 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_57__188__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__inp 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_i;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__inp;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_64__189__Vfuncout;
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xfdffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x103fff800007fffULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x39U));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xfbffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x17c1ff801ff801fULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3aU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xf7ffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1bde1f87e0781e1ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3bU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xefffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1deee3b8e388e22ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3cU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xdfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1ef76cdb2c93244ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3dU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0xbfffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1f7bb56d5525488ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3eU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = ((0x7fffffffffffffffULL 
                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o) 
                                               | ((QData)((IData)(
                                                                  (1U 
                                                                   & VL_REDXOR_64(
                                                                                (0x1fbdda769a46910ULL 
                                                                                & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o))))) 
                                                  << 0x3fU));
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o 
                                            = (0x5400000000000000ULL 
                                               ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o);
                                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__data_o;
                                    }(), vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_64_57_enc__187__Vfuncout));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__cmd_intg;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__cmd_intg 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_cmd_intg__182__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__Vfuncout 
                                = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__cmd_intg)));
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__inp 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_cmd_intg__181__Vfuncout;
                            vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__Vfuncout 
                                = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__inp;
                        }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_FE1F6__180__Vfuncout)) 
                                                 << 7U) 
                                                | ([&]() {
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o = 0xffffffffULL;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = (0x7effffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x7dffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xdeba8050ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x21U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x7bffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x413d89aaULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x22U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x77ffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x31234ed1ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x23U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x6fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0xc2c1323bULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x24U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x5fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x2dcc624cULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x25U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = ((0x3fffffffffULL & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o) 
                               | ((QData)((IData)((1U 
                                                   & VL_REDXOR_64(
                                                                  (0x98505586ULL 
                                                                   & vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o))))) 
                                  << 0x26U));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o 
                            = (0x2a00000000ULL ^ vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o);
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__data_o;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__enc_data 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__prim_secded_pkg_prim_secded_inv_39_32_enc__193__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__data_intg 
                            = (0x7fU & (IData)((vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__enc_data 
                                                >> 0x20U)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__data_intg;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__data_intg 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_data_intg__192__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__Vfuncout 
                            = (0x7fU & (~ (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__data_intg)));
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__inp 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__tlul_pkg_get_bad_data_intg__191__Vfuncout;
                        vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__Vfuncout 
                            = vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__inp;
                    }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__sv2v_cast_83AAC__190__Vfuncout)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error 
        = (((~ (IData)((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit)))) 
            & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re) 
               | (IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we))) 
           | ((IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we) 
              & ((IData)((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))) 
                 & (0U != (1U & (~ ((vlSelfRef.spi_host__02Etl_i[1U] 
                                     << 8U) | (vlSelfRef.spi_host__02Etl_i[1U] 
                                               >> 0x18U))))))));
    tlul_adapter_sram__DOT__vld_rd_rsp = ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                          & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
                                                & (0x8000U 
                                                   == 
                                                   (0x18000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][3U] = 
        ((0xfffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][3U]) | (0x1000U & (tlul_socket_1n__DOT__tl_t_o[3U] 
                                  & ((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select) 
                                     << 0xcU))));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xffffffU & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       << 0x18U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][1U] = 
        ((0xff000000U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][1U]) | (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                         ? ((tlul_socket_1n__DOT__tl_t_o[1U] 
                             << 8U) | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                       >> 0x18U)) : 0xffffffffU) 
                       >> 8U));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[0U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [0U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__0__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[1U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [1U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__1__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[2U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [2U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__2__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_o[3U][0U] = 
        ((0xff000001U & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
          [3U][0U]) | (0xfffffeU & (((IData)(tlul_socket_1n__DOT__gen_u_o__BRA__3__KET____DOT__dev_select)
                                      ? ((tlul_socket_1n__DOT__tl_t_o[0U] 
                                          << 0x1fU) 
                                         | (tlul_socket_1n__DOT__tl_t_o[0U] 
                                            >> 1U))
                                      : tlul_socket_1n__DOT__blanked_auser) 
                                    << 1U)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                  >> 2U) & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                            & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6 
        = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
           & (IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.tlul_adapter_sram__DOT__tl_o_int, 
                  (((QData)((IData)(tlul_adapter_sram__DOT__d_valid)) 
                    << 0x3fU) | (((QData)((IData)((
                                                   ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                    & (1U 
                                                       != 
                                                       (3U 
                                                        & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                           >> 0xfU))))
                                                    ? 0U
                                                    : 1U))) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp 
                                                = ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                    ? 
                                                   (3U 
                                                    & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                       >> 8U))
                                                    : 0U);
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp 
                                                    = 
                                                    ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)
                                                      : 0U);
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              (((QData)((IData)(
                                                                                ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp 
                                                            = 
                                                            (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                              & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                              ? (IData)(
                                                                        (tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                         >> 8U))
                                                              : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data);
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout))) 
                                                                                << 0xeU) 
                                                                               | (QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp 
                                                        = 
                                                        VL_EXTEND_II(14,7, 
                                                                     ([&]() {
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp 
                                                                    = 
                                                                    (0x7fU 
                                                                     & (((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                         & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                                            >> 0xeU))
                                                                         ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                                                         : 
                                                                        ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                          ? (IData)(
                                                                                (tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                                >> 1U))
                                                                          : 0x2aU)));
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout 
                                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp;
                                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout)));
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout))))))))))), 
                  ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                     & (IData)(tlul_adapter_sram__DOT__d_error)) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp 
                        = ((((IData)(vlSelfRef.gnt_i) 
                             | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
                            & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)) 
                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
           & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en 
        = (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
            >> 3U) & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
    vlSelfRef.tlul_adapter_sram__02Etl_o[0U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U];
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    tlul_adapter_sram__DOT__reqfifo_rready = (IData)(
                                                     ((vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U] 
                                                       >> 1U) 
                                                      & vlSelfRef.tlul_adapter_sram__02Etl_i[0U]));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_adapter_sram__DOT__reqfifo_rready)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(((0x8000U == (0x1c000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                         & (IData)(tlul_adapter_sram__DOT__reqfifo_rready)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

void Vspi_host___024root___eval_triggers__ico(Vspi_host___024root* vlSelf);
void Vspi_host___024root___eval_ico(Vspi_host___024root* vlSelf);

bool Vspi_host___024root___eval_phase__ico(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_phase__ico\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vspi_host___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vspi_host___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vspi_host___024root___eval_act(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_act\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__0(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__0\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__r_wptr;
    prim_fifo_async_sram_adapter__DOT__r_wptr = 0;
    CData/*0:0*/ prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (((IData)(vlSelfRef.r_sram_gnt_i) & (IData)(vlSelfRef.r_sram_req_o))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr)));
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 1U;
        } else if (((~ (IData)(vlSelfRef.r_sram_rvalid_i)) 
                    & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        }
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_wptr_gray__DOT__intq = 0U;
    }
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__inp;
    vlSelfRef.r_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__24__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__02Erdata_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
            ? vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_q
            : vlSelfRef.prim_fifo_async_sram_adapter__DOT__rdata_d);
    vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
           | (IData)(vlSelfRef.r_sram_rvalid_i));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_wptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp = 0U;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 3U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 2U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 1U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
           | (IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub 
        = (0x1fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp)) 
                    - (IData)(1U)));
    if ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = (0x10U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__dec_tmp;
    }
    prim_fifo_async_sram_adapter__DOT__r_wptr = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__6__Vfuncout;
    vlSelfRef.r_notempty_o = vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o;
    vlSelfRef.r_full_o = ((IData)(prim_fifo_async_sram_adapter__DOT__r_wptr) 
                          == (0x10U ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sram_rptr) 
           == (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr));
    vlSelfRef.rdepth_o = (((1U & ((IData)(prim_fifo_async_sram_adapter__DOT__r_wptr) 
                                  >> 4U)) == (1U & 
                                              ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q) 
                                               >> 4U)))
                           ? ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__inp 
                    = (0x1fU & ((0xfU & (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr)) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__17__Vfuncout))
                           : ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__inp 
                    = (0x1fU & ((0x10U | (0xfU & (IData)(prim_fifo_async_sram_adapter__DOT__r_wptr))) 
                                - (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__18__Vfuncout)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__1(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__1\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*106:0*/ __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    VL_ZERO_W(107, __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0);
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[0U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[1U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U] 
            = ((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                << 0x1fU) | (vlSelfRef.tlul_fifo_async__02Etl_h_i[2U] 
                             >> 1U));
        __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U] 
            = (0x7ffU & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                         >> 1U));
        __VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][0U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[0U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][1U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[1U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][2U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[2U];
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0][3U] 
            = __VdlyVal__tlul_fifo_async__DOT__reqfifo__DOT__storage__v0[3U];
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__2(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__2\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    QData/*63:0*/ __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*1:0*/ __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    CData/*0:0*/ __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0;
    // Body
    __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 0U;
    if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
        __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[2U])) 
                << 0x3fU) | (((QData)((IData)(vlSelfRef.tlul_fifo_async__02Etl_d_i[1U])) 
                              << 0x1fU) | ((QData)((IData)(
                                                           vlSelfRef.tlul_fifo_async__02Etl_d_i[0U])) 
                                           >> 1U)));
        __VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 
            = (3U & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q));
        __VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0 = 1U;
    }
    if (__VdlySet__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0) {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage[__VdlyDim0__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0] 
            = __VdlyVal__tlul_fifo_async__DOT__rspfifo__DOT__storage__v0;
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__3(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__3\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ spi_host__DOT__u_spi_host_reg__DOT__reg_we;
    spi_host__DOT__u_spi_host_reg__DOT__reg_we = 0;
    CData/*2:0*/ __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*2:0*/ __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    if (vlSelfRef.spi_host__02Erst_ni) {
        if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) {
            vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
            __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else {
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
                vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
                vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            }
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
                __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
                __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            }
        }
        if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) {
            vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
            __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        } else {
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
                vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
                vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
            }
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
                __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
                __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                    = (7U & ((IData)(1U) + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
            }
        }
        if (vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) {
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSelfRef.spi_host__02Etl_i[0U] 
                      >> 0x18U));
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSelfRef.spi_host__02Etl_i[0U] 
                      >> 0x1aU));
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en) 
                   & (vlSelfRef.spi_host__02Etl_i[0U] 
                      >> 0x19U));
        }
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q 
            = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q 
            = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state 
            = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state;
        if (vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) {
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q 
                = (0xffU & ((vlSelfRef.spi_host__02Etl_i[3U] 
                             << 4U) | (vlSelfRef.spi_host__02Etl_i[2U] 
                                       >> 0x1cU)));
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q 
                = (3U & (vlSelfRef.spi_host__02Etl_i[3U] 
                         >> 4U));
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req)
                    ? 1U : 0U);
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error) 
                   | (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal));
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 1U;
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q 
                = ((((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error) 
                     | (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
                    | (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req))
                    ? 0xffffffffU : vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next);
        } else if ((IData)(((vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U] 
                             >> 1U) & vlSelfRef.spi_host__02Etl_i[0U]))) {
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        }
    } else {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q = 0U;
    }
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_q 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) && (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_d));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) && (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) && (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_q 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) && (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_d));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__wdata_qe 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) && (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_d));
    vlSelfRef.spi_sclk_o = ((IData)(vlSelfRef.spi_host__02Erst_ni) 
                            & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_q)) 
                               & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (4U & ((~ ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 2U)) << 2U));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (4U & ((~ ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 2U)) << 2U));
    vlSelfRef.spi_sdioz_o = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_q;
    vlSelfRef.spi_sdio_o = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 0U;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d = 0U;
    if ((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            if ((1U >= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 1U;
                    if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_d = 1U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdioz_d = 0U;
        }
    }
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_q 
        = ((1U & (~ (IData)(vlSelfRef.spi_host__02Erst_ni))) 
           || (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_d));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk 
        = ((IData)(vlSelfRef.spi_host__02Erst_ni) & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT____Vcellinp__u_clk_div2__d_i));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre, 
                  (((QData)((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q)) 
                    << 0x3fU) | (((QData)((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rspop_q)) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__310__inp 
                                                = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqsz_q;
                                            vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__310__Vfuncout 
                                                = vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__310__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_FDEB5__310__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__311__inp 
                                                    = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__reqid_q;
                                                vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__311__Vfuncout 
                                                    = vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__311__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_15E34__311__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              ((QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__313__inp 
                                                        = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rdata_q;
                                                    vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__313__Vfuncout 
                                                        = vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__313__inp;
                                                }(), vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_9783B__313__Vfuncout))) 
                                                                               << 0xeU))))))), 
                  (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__error_q) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__315__inp 
                        = (1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__outstanding_q)));
                    vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__315__Vfuncout 
                        = vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__315__inp;
                }(), (IData)(vlSelfRef.__Vfunc_spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__sv2v_cast_1__315__Vfuncout))));
    vlSelfRef.spi_host__02Etl_o[0U] = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U];
    vlSelfRef.spi_host__02Etl_o[1U] = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[1U];
    vlSelfRef.spi_host__02Etl_o[2U] = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[2U];
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack 
        = (IData)(((vlSelfRef.spi_host__02Etl_i[3U] 
                    >> 0xcU) & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__tl_o_pre[0U]));
    vlSelfRef.spi_cs_o = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_q;
    if ((0U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_d = 1U;
    } else if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_d = 0U;
    } else if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__cs_d = 1U;
    }
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & (0x800U == (0xe00U & vlSelfRef.spi_host__02Etl_i[3U])));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__a_ack) 
           & ((0U == (7U & (vlSelfRef.spi_host__02Etl_i[3U] 
                            >> 9U))) | (1U == (7U & 
                                               (vlSelfRef.spi_host__02Etl_i[3U] 
                                                >> 9U)))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req) 
           & (0U != (3U & (vlSelfRef.spi_host__02Etl_i[1U] 
                           >> 0x1cU))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re 
        = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
           & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__rd_req));
    spi_host__DOT__u_spi_host_reg__DOT__reg_we = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__err_internal)) 
                                                  & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_reg_if__DOT__wr_req));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error 
        = (((~ (IData)((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit)))) 
            & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re) 
               | (IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we))) 
           | ((IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we) 
              & ((IData)((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))) 
                 & (0U != (1U & (~ ((vlSelfRef.spi_host__02Etl_i[1U] 
                                     << 8U) | (vlSelfRef.spi_host__02Etl_i[1U] 
                                               >> 0x18U))))))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6 
        = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
           & (IData)(spi_host__DOT__u_spi_host_reg__DOT__reg_we));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_ctrl_en__DOT__wr_en 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
           & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__4(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__4\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o;
    tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o;
    tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_adapter_sram__02Erst_ni) {
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
    } else {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
    }
    if ((1U & (~ (IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni)))) {
        vlSelfRef.tlul_adapter_sram__DOT__intg_error_q = 0U;
    }
    vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q 
        = ((IData)(vlSelfRef.tlul_adapter_sram__02Erst_ni) 
           & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det) 
              & ((~ vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
                 & (vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                    >> 0xcU))));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.intg_error_o = vlSelfRef.tlul_adapter_sram__DOT__intg_error_q;
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready 
        = (1U & ((~ (IData)(tlul_adapter_sram__DOT__u_sramreqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready 
        = (1U & ((~ (IData)(tlul_adapter_sram__DOT__u_reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.req_o = ((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                        >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_det)) 
                                    & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & (IData)(vlSelfRef.rvalid_i));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = (((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready)) 
           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__5(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__5\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o;
    tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o;
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o = 0;
    SData/*8:0*/ __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
        = vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_1n__02Erst_ni) {
        if (vlSelfRef.tlul_socket_1n__DOT__accept_t_req) {
            if ((1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp)))) {
                __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding)));
            }
            vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding 
                = (7U & vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rdata_o[0U]);
        } else if (vlSelfRef.tlul_socket_1n__DOT__accept_t_rsp) {
            __Vdly__tlul_socket_1n__DOT__num_req_outstanding 
                = (0x1ffU & ((IData)(vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding) 
                             - (IData)(1U)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
             & vlSelfRef.tlul_socket_1n__DOT__tl_u_o
             [4U][0U])) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        } else if ((1U & ((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [4U][3U] >> 0xcU) & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]))) {
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 1U;
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source 
                = (0xffU & ((vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                             [4U][3U] << 4U) | (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                                                [4U][2U] 
                                                >> 0x1cU)));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode 
                = (7U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                         [4U][3U] >> 9U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size 
                = (3U & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                         [4U][3U] >> 4U));
            vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type 
                = (0xfU & (vlSelfRef.tlul_socket_1n__DOT__tl_u_o
                           [4U][0U] >> 0xfU));
        }
    } else {
        __Vdly__tlul_socket_1n__DOT__num_req_outstanding = 0U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode = 4U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size = 0U;
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type = 9U;
        vlSelfRef.tlul_socket_1n__DOT__dev_select_outstanding = 0U;
    }
    vlSelfRef.tlul_socket_1n__DOT__num_req_outstanding 
        = __Vdly__tlul_socket_1n__DOT__num_req_outstanding;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    VL_ASSIGNSEL_WI(66,32,0x10U, vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int, 
                    (([&]() {
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__val 
                        = vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_instr_type;
                    vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__prim_mubi_pkg_mubi4_test_true_strict__221__Vfuncout))
                      ? 0U : 0xffffffffU));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U] 
        = (2U | ((0xffff0000U & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U]) 
                 | (1U & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending)))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0xc000ffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (0xffff0000U & (((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_size) 
                              << 0x19U) | ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_source) 
                                           << 0x11U))));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U] 
        = ((0x3fffffffU & vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U]) 
           | (((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                ? 1U : 0U) << 0x1eU));
    vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U] 
        = (3U & ((0x3ffffffeU & ((IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_rsp_pending) 
                                 << 1U)) | (((4U == (IData)(vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__err_opcode))
                                              ? 1U : 0U) 
                                            >> 2U)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o 
        = (1U & ((~ (IData)(tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
               >> 0xcU)) & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][0U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[0U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][1U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[1U];
    vlSelfRef.tlul_socket_1n__DOT__tl_u_i[4U][2U] = 
        vlSelfRef.tlul_socket_1n__DOT__gen_err_resp__DOT__err_resp__DOT__tl_h_o_int[2U];
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__6(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__6\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o;
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o = 0;
    CData/*0:0*/ tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o;
    tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0;
    CData/*1:0*/ __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0;
    // Body
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    if (vlSelfRef.tlul_socket_m1__02Erst_ni) {
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst) {
            vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst 
                = (1U & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
        }
        if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt;
        } else if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
            __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
                = (3U & ((IData)(1U) + (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
        }
        if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest)) 
             & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = (0xfU & VL_SHIFTL_III(4,4,32, (IData)(vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out), 1U));
        } else if (((0U != (IData)(vlSelfRef.tlul_socket_m1__DOT__hrequest)) 
                    & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o)))) {
            vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask 
                = vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__ppc_out;
        }
    } else {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst = 1U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q = 0U;
        __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q = 0U;
        vlSelfRef.tlul_socket_m1__DOT__gen_arb_ppc__DOT__u_reqarb__DOT__gen_normal_case__DOT__mask = 0U;
    }
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = __Vdly__tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (2U & ((~ ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 1U)) << 1U));
    tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (2U ^ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__reqfifo__wready_o 
        = (1U & ((~ (IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o 
        = (1U & ((~ (IData)(tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty 
        = ((~ (vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
               >> 1U)) & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__rvalid_o 
        = (1U & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__empty)) 
                 & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst))));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__7(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__7\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_fifo_async_simple__DOT__wr_en) {
        vlSelfRef.prim_fifo_async_simple__DOT__data_q 
            = vlSelfRef.prim_fifo_async_simple__02Ewdata_i;
    }
    vlSelfRef.prim_fifo_async_simple__02Erdata_o = vlSelfRef.prim_fifo_async_simple__DOT__data_q;
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__8(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__8\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_filter__02Erst_ni) {
        vlSelfRef.prim_filter__DOT__stored_vector_q 
            = vlSelfRef.prim_filter__DOT__stored_vector_d;
        if (((0U == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)) 
             | (0xfU == (IData)(vlSelfRef.prim_filter__DOT__stored_vector_d)))) {
            vlSelfRef.prim_filter__DOT__stored_value_q 
                = vlSelfRef.prim_filter__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter__DOT__stored_vector_q = 0U;
        vlSelfRef.prim_filter__DOT__stored_value_q = 0U;
    }
    vlSelfRef.prim_filter__DOT__stored_vector_d = (
                                                   (0xeU 
                                                    & ((IData)(vlSelfRef.prim_filter__DOT__stored_vector_q) 
                                                       << 1U)) 
                                                   | (IData)(vlSelfRef.prim_filter__02Efilter_i));
    vlSelfRef.prim_filter__02Efilter_o = ((IData)(vlSelfRef.prim_filter__02Eenable_i)
                                           ? (IData)(vlSelfRef.prim_filter__DOT__stored_value_q)
                                           : (IData)(vlSelfRef.prim_filter__02Efilter_i));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__9(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__9\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.prim_filter_ctr__02Erst_ni) {
        vlSelfRef.prim_filter_ctr__DOT__filter_q = vlSelfRef.prim_filter_ctr__02Efilter_i;
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q 
            = vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d;
        if (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d) 
             == (IData)(vlSelfRef.thresh_i))) {
            vlSelfRef.prim_filter_ctr__DOT__stored_value_q 
                = vlSelfRef.prim_filter_ctr__02Efilter_i;
        }
    } else {
        vlSelfRef.prim_filter_ctr__DOT__filter_q = 0U;
        vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q = 0U;
        vlSelfRef.prim_filter_ctr__DOT__stored_value_q = 0U;
    }
    vlSelfRef.prim_filter_ctr__DOT__diff_ctr_d = (((IData)(vlSelfRef.prim_filter_ctr__02Efilter_i) 
                                                   == (IData)(vlSelfRef.prim_filter_ctr__DOT__filter_q))
                                                   ? 
                                                  (3U 
                                                   & (((IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q) 
                                                       >= (IData)(vlSelfRef.thresh_i))
                                                       ? (IData)(vlSelfRef.thresh_i)
                                                       : 
                                                      ((IData)(1U) 
                                                       + (IData)(vlSelfRef.prim_filter_ctr__DOT__diff_ctr_q))))
                                                   : 0U);
    vlSelfRef.prim_filter_ctr__02Efilter_o = ((IData)(vlSelfRef.prim_filter_ctr__02Eenable_i)
                                               ? (IData)(vlSelfRef.prim_filter_ctr__DOT__stored_value_q)
                                               : (IData)(vlSelfRef.prim_filter_ctr__02Efilter_i));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__10(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__10\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake = 0;
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q 
        = vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_d));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__02Ewready_o = 
        ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__not_in_reset_q));
    vlSelfRef.prim_fifo_async_simple__DOT__src_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
           | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q));
    vlSelfRef.prim_fifo_async_simple__DOT__src_ack = 0U;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__ack_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q));
    vlSelfRef.prim_fifo_async_simple__DOT__wr_en = 
        ((IData)(vlSelfRef.prim_fifo_async_simple__02Ewvalid_i) 
         & (IData)(vlSelfRef.prim_fifo_async_simple__02Ewready_o));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__src_ack 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_ack;
    }
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req));
    vlSelfRef.prim_fifo_async_simple__DOT__pending_d 
        = ((~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_ack)) 
           & ((IData)(vlSelfRef.prim_fifo_async_simple__DOT__wr_en) 
              | (IData)(vlSelfRef.prim_fifo_async_simple__DOT__pending_q)));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 0U;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_ns = 1U;
        }
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__11(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__11\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
    if (vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[2U];
        vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellinp__reqfifo__wdata_i[3U];
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__12(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__12\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*2:0*/ tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi;
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__147__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__dec_tmp;
    }
    tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__172__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_sync_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_sync_combi));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__13(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__13\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi;
    tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*0:0*/ tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in = 0;
    // Body
    if (vlSelfRef.rst_d_ni) {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi;
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d;
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq;
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d;
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d;
        }
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq 
            = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q;
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__sync_rptr__DOT__intq = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__sync_wptr__DOT__intq = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__151__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp = 0U;
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__rspfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__dec_tmp;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__gray2dec__170__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval 
        = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_sync;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb = 0;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp = 0U;
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval) 
                 >> 1U));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp 
        = ((5U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
           | ((IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0) 
              << 1U));
    tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0 
        = (1U & (((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp 
        = ((6U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
           | (IData)(tlul_fifo_async__DOT__reqfifo__DOT____Vlvbound_he9bf8c26__0));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub 
        = (7U & (((IData)(4U) - (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp)) 
                 - (IData)(1U)));
    if ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__grayval))) {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub;
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = (4U | (IData)(vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout));
        __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp_sub) 
                     >> 2U));
    } else {
        vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout 
            = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__dec_tmp;
    }
    tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi 
        = vlSelfRef.__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__gray2dec__149__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_d 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q) 
           == (4U ^ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_sync_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__176__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk 
        = ((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q) 
           == (IData)(tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_sync_combi));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
              >> 1U));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_d_i[0U]));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__14(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__14\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ prim_fifo_async_simple__DOT__dst_ack;
    prim_fifo_async_simple__DOT__dst_ack = 0;
    CData/*0:0*/ prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake;
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake = 0;
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d));
    vlSelfRef.prim_fifo_async_simple__DOT__dst_req = 0U;
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__req_sync__DOT__intq 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q));
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__dst_req 
            = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_req;
    }
    vlSelfRef.prim_fifo_async_simple__02Ervalid_o = vlSelfRef.prim_fifo_async_simple__DOT__dst_req;
    prim_fifo_async_simple__DOT__dst_ack = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erready_i) 
                                            & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake 
        = ((IData)(prim_fifo_async_simple__DOT__dst_ack) 
           & (IData)(vlSelfRef.prim_fifo_async_simple__DOT__dst_req));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_q;
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
                = (1U & (~ (IData)(prim_fifo_async_simple__DOT__dst_ack)));
            if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
                vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
            }
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 0U;
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_ack_d 
            = prim_fifo_async_simple__DOT__dst_ack;
        if (prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_handshake) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__dst_fsm_ns = 1U;
        }
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__15(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__15\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[0U]);
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[1U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]) 
               | (0xfffffffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[2U]));
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__reqfifo__DOT__gen_normal_fifo__DOT__storage[3U] 
            = ((1U & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]) 
               | (0xffeU & vlSelfRef.tlul_socket_m1__DOT__dreq_fifo_i[3U]));
    }
    if (vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[0U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[0U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[1U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[1U];
        vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__storage[2U] 
            = vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellinp__rspfifo__wdata_i[2U];
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__16(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__16\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*108:0*/ tlul_adapter_host__DOT__tl_out;
    VL_ZERO_W(109, tlul_adapter_host__DOT__tl_out);
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp = 0;
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<4>/*127:0*/ __Vtemp_2;
    // Body
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q 
        = ((IData)(vlSelfRef.tlul_adapter_host__02Erst_ni) 
           & (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d));
    vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    if (((IData)(vlSelfRef.req_i) & (IData)(vlSelfRef.gnt_o))) {
        vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_d 
            = (1U & ((~ (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q)) 
                     & ((IData)(1U) + (IData)(vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q))));
    }
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp 
        = vlSelfRef.tlul_adapter_host__DOT__g_multiple_reqs__DOT__source_q;
    __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout 
        = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__inp;
    vlSelfRef.tlul_adapter_host__DOT__tl_source = __Vfunc_tlul_adapter_host__DOT__sv2v_cast_8__28__Vfuncout;
    VL_CONCAT_WIQ(92,32,60, __Vtemp_1, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp 
                    = (0xfffffffcU & vlSelfRef.addr_i);
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__inp;
            }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_D591E__32__Vfuncout), 
                  (((QData)((IData)(([&]() {
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp 
                                    = ((IData)(vlSelfRef.we_i)
                                        ? (IData)(vlSelfRef.be_i)
                                        : 0xfU);
                                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout 
                                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__inp;
                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_B0D6A__33__Vfuncout)))) 
                    << 0x38U) | (((QData)((IData)(([&]() {
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp 
                                        = vlSelfRef.tlul_adapter_host__02Ewdata_i;
                                    vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout 
                                        = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__inp;
                                }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_9783B__34__Vfuncout))) 
                                  << 0x18U) | (QData)((IData)(
                                                              (1U 
                                                               | (([&]() {
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp 
                                            = ((VL_EXTEND_II(9,4, 
                                                             ([&]() {
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp 
                                                                = vlSelfRef.instr_type_i;
                                                            vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout 
                                                                = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__inp;
                                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EECFA__36__Vfuncout))) 
                                                << 0xeU) 
                                               | VL_EXTEND_II(14,7, 
                                                              ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp 
                                                            = vlSelfRef.wdata_intg_i;
                                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__inp;
                                                    }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_83AAC__38__Vfuncout))));
                                        vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout 
                                            = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__inp;
                                    }(), vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_EDEFC__35__Vfuncout) 
                                                                  << 1U)))))));
    VL_CONCAT_WIW(100,8,92, __Vtemp_2, ([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp 
                    = vlSelfRef.tlul_adapter_host__DOT__tl_source;
                vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout 
                    = vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__inp;
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_host__DOT__sv2v_cast_15E34__31__Vfuncout)), __Vtemp_1);
    tlul_adapter_host__DOT__tl_out[0U] = __Vtemp_2[0U];
    tlul_adapter_host__DOT__tl_out[1U] = __Vtemp_2[1U];
    tlul_adapter_host__DOT__tl_out[2U] = __Vtemp_2[2U];
    tlul_adapter_host__DOT__tl_out[3U] = (0x20U | (
                                                   ((IData)(vlSelfRef.req_i) 
                                                    << 0xcU) 
                                                   | ((((IData)(vlSelfRef.we_i)
                                                         ? 
                                                        ((0xfU 
                                                          == (IData)(vlSelfRef.be_i))
                                                          ? 0U
                                                          : 1U)
                                                         : 4U) 
                                                       << 9U) 
                                                      | __Vtemp_2[3U])));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = tlul_adapter_host__DOT__tl_out[0U];
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = tlul_adapter_host__DOT__tl_out[1U];
    vlSelfRef.tlul_adapter_host__02Etl_o[2U] = tlul_adapter_host__DOT__tl_out[2U];
    vlSelfRef.tlul_adapter_host__02Etl_o[3U] = tlul_adapter_host__DOT__tl_out[3U];
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffffffU 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0xff000000U 
                                                   & tlul_adapter_host__DOT__tl_out[0U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[1U] = ((0xff000000U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[1U]) 
                                                | (0xffffffU 
                                                   & tlul_adapter_host__DOT__tl_out[1U]));
    vlSelfRef.tlul_adapter_host__02Etl_o[0U] = ((0xffff8001U 
                                                 & vlSelfRef.tlul_adapter_host__02Etl_o[0U]) 
                                                | (0x7ffeU 
                                                   & tlul_adapter_host__DOT__tl_out[0U]));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__17(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__17\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ prim_fifo_async_sram_adapter__DOT__w_rptr;
    prim_fifo_async_sram_adapter__DOT__w_rptr = 0;
    CData/*0:0*/ prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub = 0;
    CData/*0:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout = 0;
    SData/*15:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d;
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d;
        }
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq 
            = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q;
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_q = 0U;
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__u_sync_rptr_gray__DOT__intq = 0U;
    }
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_d 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp 
        = (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__inp;
    vlSelfRef.w_sram_addr_o = __Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_55648__21__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub 
        = (0x1fU & (((IData)(0x10U) - (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval))) 
                    - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in 
        = ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in 
        = (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = (0x1fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout) 
                    ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout 
        = ((0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout)) 
           | (0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__4__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval 
        = vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_rptr_gray;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb = 0;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp = 0U;
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                 >> 3U));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x17U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 3U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 3U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                            >> 2U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1bU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 2U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 2U) ^ ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval) 
                            >> 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1dU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | ((IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0) 
              << 1U));
    prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0 
        = (1U & (((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp) 
                  >> 1U) ^ (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp 
        = ((0x1eU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
           | (IData)(prim_fifo_async_sram_adapter__DOT____Vlvbound_h2ff0bc74__0));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub 
        = (0x1fU & (((IData)(0x10U) - (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp)) 
                    - (IData)(1U)));
    if ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__grayval))) {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub;
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = (0x10U | (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout));
        __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__unused_decsub_msb 
            = (1U & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp_sub) 
                     >> 4U));
    } else {
        vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout 
            = __Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__dec_tmp;
    }
    prim_fifo_async_sram_adapter__DOT__w_rptr = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__gray2dec__15__Vfuncout;
    vlSelfRef.wdepth_o = (((1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                                  >> 4U)) == (1U & 
                                              ((IData)(prim_fifo_async_sram_adapter__DOT__w_rptr) 
                                               >> 4U)))
                           ? ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__inp 
                    = (0x1fU & ((0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q)) 
                                - (0xfU & (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__8__Vfuncout))
                           : ([&]() {
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__inp 
                    = (0x1fU & ((0x10U | (0xfU & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q))) 
                                - (0xfU & (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr))));
                vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__Vfuncout 
                    = vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__inp;
            }(), (IData)(vlSelfRef.__Vfunc_prim_fifo_async_sram_adapter__DOT__sv2v_cast_2DA09__9__Vfuncout)));
    vlSelfRef.w_full_o = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_q) 
                          == (0x10U ^ (IData)(prim_fifo_async_sram_adapter__DOT__w_rptr)));
    vlSelfRef.w_sram_req_o = ((~ (IData)(vlSelfRef.w_full_o)) 
                              & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i));
    vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o 
        = ((~ (IData)(vlSelfRef.w_full_o)) & (IData)(vlSelfRef.w_sram_gnt_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__w_wptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ewready_o));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__18(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__18\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT____Vlvbound_hda94dff7__0 
            = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
        if ((0x17U >= (0x1fU & VL_SHIFTL_III(5,32,32, 
                                             (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                = (((~ ((IData)(0xffU) << (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) 
                    & vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage) 
                   | (0xffffffU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT____Vlvbound_hda94dff7__0) 
                                   << (0x1fU & VL_SHIFTL_III(5,32,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))));
        }
    }
    if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT____Vlvbound_hda94dff7__0 
            = vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q;
        if ((0x17U >= (0x1fU & VL_SHIFTL_III(5,32,32, 
                                             (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage 
                = (((~ ((IData)(0xffU) << (0x1fU & 
                                           VL_SHIFTL_III(5,32,32, 
                                                         (3U 
                                                          & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))) 
                    & vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage) 
                   | (0xffffffU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT____Vlvbound_hda94dff7__0) 
                                   << (0x1fU & VL_SHIFTL_III(5,32,32, 
                                                             (3U 
                                                              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)), 3U)))));
        }
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__19(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__19\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wdata;
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata;
    }
    if (vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) {
        vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage 
            = vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wdata;
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__20(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__20\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
            >> 0xcU) & ((~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                        & (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT____Vcellout__reqfifo__wready_o)));
    vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_1n__DOT__fifo_h__DOT__reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__2(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__2\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | (1U 
                                                   & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk))));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[0U]) 
                                                | ((IData)(
                                                           ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                             ? 0ULL
                                                             : 
                                                            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                            [
                                                            (3U 
                                                             & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[1U] = (((IData)(
                                                         ((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                           ? 0ULL
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))])) 
                                                 >> 0x1fU) 
                                                | ((IData)(
                                                           (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                              ? 0ULL
                                                              : 
                                                             vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                             [
                                                             (3U 
                                                              & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                            >> 0x20U)) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((2U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (3U 
                                                   & ((IData)(
                                                              (((IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)
                                                                 ? 0ULL
                                                                 : 
                                                                vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__storage
                                                                [
                                                                (3U 
                                                                 & (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q))]) 
                                                               >> 0x20U)) 
                                                      >> 0x1fU)));
    vlSelfRef.tlul_fifo_async__02Etl_h_o[2U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_h_o[2U]) 
                                                | (2U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                                                      << 1U)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__21(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__21\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub = 0;
    CData/*2:0*/ __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in = 0;
    // Body
    if (vlSelfRef.rst_h_ni) {
        if (vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr) {
            vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d;
        }
        if (vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr) {
            vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q 
                = vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d;
        }
    } else {
        vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_q = 0U;
        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_q = 0U;
    }
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_incr_rptr 
        = (1U & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__empty_rclk)) 
                 & vlSelfRef.tlul_fifo_async__02Etl_h_i[0U]));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_q)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in;
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__decval)));
    vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__fifo_rptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__rspfifo__DOT__g_full_gray_conversion__DOT__dec2gray__174__Vfuncout;
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_incr_wptr 
        = ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__full_wclk)) 
           & (vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
              >> 0xcU));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_q)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub 
        = (7U & (((IData)(4U) - (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval))) 
                 - (IData)(1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in 
        = ((4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval))
            ? (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_sub)
            : (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in 
        = (3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in;
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = (7U & ((IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout) 
                 ^ VL_SHIFTR_III(3,3,32, (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval_in), 1U)));
    __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout 
        = ((3U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout)) 
           | (4U & (IData)(__Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__decval)));
    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_wptr_gray_d 
        = __Vfunc_tlul_fifo_async__DOT__reqfifo__DOT__g_full_gray_conversion__DOT__dec2gray__153__Vfuncout;
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__3(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__3\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((0xfffffffeU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (1U 
                                                   & (~ (IData)(vlSelfRef.tlul_fifo_async__DOT__rspfifo__DOT__full_wclk))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[0U] = ((1U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[0U]) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[1U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][0U]) 
                                                 >> 0x1fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[2U] = ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                   ? 0U
                                                   : 
                                                  vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                  [
                                                  (3U 
                                                   & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][1U]) 
                                                 >> 0x1fU) 
                                                | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                     ? 0U
                                                     : 
                                                    vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                    [
                                                    (3U 
                                                     & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                   << 1U));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0x1000U 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x1fffU 
                                                   & ((((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                         ? 0U
                                                         : 
                                                        vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                        [
                                                        (3U 
                                                         & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][2U]) 
                                                       >> 0x1fU) 
                                                      | (((IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)
                                                           ? 0U
                                                           : 
                                                          vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__storage
                                                          [
                                                          (3U 
                                                           & (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__fifo_rptr_q))][3U]) 
                                                         << 1U))));
    vlSelfRef.tlul_fifo_async__02Etl_d_o[3U] = ((0xfffU 
                                                 & vlSelfRef.tlul_fifo_async__02Etl_d_o[3U]) 
                                                | (0x1000U 
                                                   & ((~ (IData)(vlSelfRef.tlul_fifo_async__DOT__reqfifo__DOT__empty_rclk)) 
                                                      << 0xcU)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__22(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__22\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q 
        = ((IData)(vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni) 
           && (IData)(vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d));
    vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
        = vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_q;
    if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
        if (vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_fsm_cs) {
            vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
                = (1U & (~ (IData)(vlSelfRef.prim_fifo_async_simple__DOT__src_req)));
        }
    } else {
        vlSelfRef.prim_fifo_async_simple__DOT__u_prim_sync_reqack__DOT__gen_nrz_hs_protocol__DOT__src_req_d 
            = vlSelfRef.prim_fifo_async_simple__DOT__src_req;
    }
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__23(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__23\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
            >> 1U) & ((~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
                      & (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT____Vcellout__rspfifo__wready_o)));
    vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_socket_m1__DOT__u_devicefifo__DOT__rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__24(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__24\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub = 0;
    CData/*4:0*/ __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in = 0;
    // Body
    if (vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni) {
        if (vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc) {
            vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q 
                = vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d;
        }
    } else {
        vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_q = 0U;
    }
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval 
        = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_q)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub 
        = (0x1fU & (((IData)(0x10U) - (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval))) 
                    - (IData)(1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in 
        = ((0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval))
            ? (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_sub)
            : (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in 
        = (0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in;
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = (0x1fU & ((IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout) 
                    ^ VL_SHIFTR_III(5,5,32, (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval_in), 1U)));
    __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout 
        = ((0xfU & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout)) 
           | (0x10U & (IData)(__Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__decval)));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_gray_d 
        = __Vfunc_prim_fifo_async_sram_adapter__DOT__dec2gray__13__Vfuncout;
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc 
        = ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Ervalid_o) 
           & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i));
    vlSelfRef.prim_fifo_async_sram_adapter__DOT__store_en 
        = ((~ ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored) 
               ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))) 
           & (IData)(vlSelfRef.r_sram_rvalid_i));
    vlSelfRef.r_sram_req_o = 0U;
    vlSelfRef.r_sram_req_o = (1U & ((IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__stored)
                                     ? ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))
                                     : ((~ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_sramrptr_empty)) 
                                        & (~ ((IData)(vlSelfRef.r_sram_rvalid_i) 
                                              ^ (IData)(vlSelfRef.prim_fifo_async_sram_adapter__DOT__r_rptr_inc))))));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__25(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__25\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ spi_host__DOT__u_spi_host_core__DOT__sclk_en;
    spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0;
    CData/*0:0*/ spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o;
    spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o = 0;
    CData/*0:0*/ spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o;
    spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o = 0;
    // Body
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q 
        = vlSelfRef.__Vdly__spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (4U & ((~ ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 2U)) << 2U));
    spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (4U ^ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    if (vlSelfRef.spi_host__02Erst_ni) {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q 
            = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d;
        if (vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en) {
            vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q 
                = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en)
                    ? (vlSelfRef.spi_host__02Etl_i[0U] 
                       >> 0x18U) : 0U);
        }
    } else {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q = 0U;
        vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_wdata__q = 0U;
    }
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set_cnt 
        = (4U & ((~ ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
                     >> 2U)) << 2U));
    spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q) 
           == (4U ^ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q) 
           == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready 
        = (1U & ((~ (IData)(spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__u_wdata__DOT__wr_en 
        = (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
            >> 3U) & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____VdfgRegularize_h533b1fce_2_6));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready 
        = (1U & ((~ (IData)(spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__full_o)) 
                 & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid 
        = (1U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty)) 
                 & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wvalid_q) 
           & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit) 
                  >> 2U) & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_error)) 
                            & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_re)))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__wdata_qe) 
           & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) 
           & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_q)));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 0U;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q;
    if ((0U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state = 1U;
            }
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                = (7U & ((IData)(1U) + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q)));
        }
    } else if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U < (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                        = (7U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                                 - (IData)(1U)));
                }
            }
        } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
            if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                        = (7U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                                 - (IData)(1U)));
                }
            }
        } else if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rready_d = 1U;
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d 
                    = (7U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q) 
                             - (IData)(1U)));
            }
        }
        if ((1U >= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state = 2U;
                    }
                }
            } else if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state = 2U;
                }
            }
        }
    } else {
        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__next_state = 0U;
        if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_d = 0U;
        }
    }
    spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
    if ((0U != (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            if ((1U < (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_d 
                            = (1U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                     >> 7U));
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                    }
                } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                }
            } else {
                if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q)))) {
                    if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_d 
                                = (1U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                         >> 7U));
                        }
                    }
                }
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                                = (0xfU & ((IData)(1U) 
                                           + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                        }
                    } else {
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                    }
                } else if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                        vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d 
                            = (0xfU & ((IData)(1U) 
                                       + (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q)));
                    }
                } else {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
                }
            }
            spi_host__DOT__u_spi_host_core__DOT__sclk_en = 1U;
            if ((1U >= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
                    if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                        if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                            spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
                        }
                    }
                } else if ((8U <= (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                    if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)))) {
                        spi_host__DOT__u_spi_host_core__DOT__sclk_en = 0U;
                    }
                }
            }
        } else if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sdio_d = 0U;
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_d = 0U;
        }
    }
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (2U == (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (2U == (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (2U == (3U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT____Vcellinp__u_clk_div2__d_i 
        = ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)) 
           & (IData)(spi_host__DOT__u_spi_host_core__DOT__sclk_en));
}

VL_INLINE_OPT void Vspi_host___024root___nba_sequent__TOP__26(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_sequent__TOP__26\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((~ (IData)(vlSelfRef.we_o)) & ((IData)(vlSelfRef.req_o) 
                                           & (IData)(vlSelfRef.gnt_i))) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready) 
            & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst))) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__full_o)));
    vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__6(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__6\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tlul_adapter_sram__DOT__reqfifo_rready;
    tlul_adapter_sram__DOT__reqfifo_rready = 0;
    CData/*4:0*/ tlul_adapter_sram__DOT__sramreqfifo_rdata;
    tlul_adapter_sram__DOT__sramreqfifo_rdata = 0;
    QData/*39:0*/ tlul_adapter_sram__DOT__rspfifo_rdata;
    tlul_adapter_sram__DOT__rspfifo_rdata = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_valid;
    tlul_adapter_sram__DOT__d_valid = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__d_error;
    tlul_adapter_sram__DOT__d_error = 0;
    CData/*0:0*/ tlul_adapter_sram__DOT__vld_rd_rsp;
    tlul_adapter_sram__DOT__vld_rd_rsp = 0;
    // Body
    tlul_adapter_sram__DOT__sramreqfifo_rdata = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                                                  ? 0U
                                                  : (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_sramreqfifo__DOT__gen_normal_fifo__DOT__storage));
    vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__storage);
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask = 0U;
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask 
        = ((0xffff0000U & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask) 
           | ((0xff00U & ((- (IData)((1U & ((IData)(tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                            >> 2U)))) 
                          << 8U)) | (0xffU & (- (IData)(
                                                        (1U 
                                                         & ((IData)(tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                                            >> 1U)))))));
    vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask 
        = ((0xffffU & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask) 
           | (((- (IData)((1U & ((IData)(tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                 >> 4U)))) << 0x18U) 
              | (0xff0000U & ((- (IData)((1U & ((IData)(tlul_adapter_sram__DOT__sramreqfifo_rdata) 
                                                >> 3U)))) 
                              << 0x10U))));
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data 
        = (([&]() {
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__val 
                    = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                               >> 0xaU));
                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__Vfuncout 
                    = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__val));
            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__58__Vfuncout))
            ? 0U : 0xffffffffU);
    vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ 
        = (0x7fU & (([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__val 
                        = (0xfU & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                   >> 0xaU));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__Vfuncout 
                        = (6U == (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__val));
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__prim_mubi_pkg_mubi4_test_true_strict__62__Vfuncout))
                     ? (IData)((vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_instr__data_intg_o 
                                >> 0x20U)) : (IData)(
                                                     (vlSelfRef.tlul_adapter_sram__DOT____Vcellout__u_tlul_data_integ_enc_data__data_intg_o 
                                                      >> 0x20U))));
    tlul_adapter_sram__DOT__d_valid = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                       && (1U & (IData)(
                                                        ((0x8000U 
                                                          != 
                                                          (0x1c000U 
                                                           & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                                                         | (IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid)))));
    vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata 
        = (((QData)((IData)((vlSelfRef.rdata_i & vlSelfRef.tlul_adapter_sram__DOT__gen_rmask__DOT__rmask))) 
            << 8U) | (QData)((IData)((1U & ((IData)(vlSelfRef.rerror_i) 
                                            >> 1U)))));
    tlul_adapter_sram__DOT__vld_rd_rsp = ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                          & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                             & ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
                                                & (0x8000U 
                                                   == 
                                                   (0x18000U 
                                                    & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)))));
    tlul_adapter_sram__DOT__rspfifo_rdata = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__empty)
                                              ? 0ULL
                                              : (((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_empty) 
                                                  & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_rready))
                                                  ? vlSelfRef.tlul_adapter_sram__DOT__rspfifo_wdata
                                                  : vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__storage));
    tlul_adapter_sram__DOT__d_error = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
                                       && (1U & ((1U 
                                                  == 
                                                  (3U 
                                                   & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                      >> 0xfU)))
                                                  ? 
                                                 ((IData)(tlul_adapter_sram__DOT__rspfifo_rdata) 
                                                  | (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                     >> 0xeU))
                                                  : 
                                                 (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                  >> 0xeU))));
    VL_CONCAT_WQI(66,64,2, vlSelfRef.tlul_adapter_sram__DOT__tl_o_int, 
                  (((QData)((IData)(tlul_adapter_sram__DOT__d_valid)) 
                    << 0x3fU) | (((QData)((IData)((
                                                   ((IData)(tlul_adapter_sram__DOT__d_valid) 
                                                    & (1U 
                                                       != 
                                                       (3U 
                                                        & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                           >> 0xfU))))
                                                    ? 0U
                                                    : 1U))) 
                                  << 0x3cU) | VL_EXTEND_QQ(60,57, 
                                                           (((QData)((IData)(
                                                                             ([&]() {
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp 
                                                = ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                    ? 
                                                   (3U 
                                                    & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                       >> 8U))
                                                    : 0U);
                                            vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout 
                                                = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__inp;
                                        }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_FDEB5__64__Vfuncout)))) 
                                                             << 0x37U) 
                                                            | (((QData)((IData)(
                                                                                ([&]() {
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp 
                                                    = 
                                                    ((IData)(tlul_adapter_sram__DOT__d_valid)
                                                      ? 
                                                     (0xffU 
                                                      & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)
                                                      : 0U);
                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout 
                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__inp;
                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_15E34__65__Vfuncout)))) 
                                                                << 0x2fU) 
                                                               | VL_EXTEND_QQ(47,46, 
                                                                              (((QData)((IData)(
                                                                                ([&]() {
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp 
                                                            = 
                                                            (((~ (IData)(tlul_adapter_sram__DOT__d_error)) 
                                                              & (IData)(tlul_adapter_sram__DOT__vld_rd_rsp))
                                                              ? (IData)(
                                                                        (tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                         >> 8U))
                                                              : vlSelfRef.tlul_adapter_sram__DOT__error_blanking_data);
                                                        vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout 
                                                            = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__inp;
                                                    }(), vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_9783B__67__Vfuncout))) 
                                                                                << 0xeU) 
                                                                               | (QData)((IData)(
                                                                                ([&]() {
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp 
                                                        = 
                                                        VL_EXTEND_II(14,7, 
                                                                     ([&]() {
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp 
                                                                    = 
                                                                    (0x7fU 
                                                                     & (((IData)(tlul_adapter_sram__DOT__vld_rd_rsp) 
                                                                         & (vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata 
                                                                            >> 0xeU))
                                                                         ? (IData)(vlSelfRef.tlul_adapter_sram__DOT__error_blanking_integ)
                                                                         : 
                                                                        ((IData)(tlul_adapter_sram__DOT__vld_rd_rsp)
                                                                          ? (IData)(
                                                                                (tlul_adapter_sram__DOT__rspfifo_rdata 
                                                                                >> 1U))
                                                                          : 0x2aU)));
                                                                vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout 
                                                                    = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__inp;
                                                            }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_83AAC__70__Vfuncout)));
                                                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout 
                                                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__inp;
                                                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_11E70__68__Vfuncout))))))))))), 
                  ((((IData)(tlul_adapter_sram__DOT__d_valid) 
                     & (IData)(tlul_adapter_sram__DOT__d_error)) 
                    << 1U) | ([&]() {
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp 
                        = ((((IData)(vlSelfRef.gnt_i) 
                             | (IData)(vlSelfRef.tlul_adapter_sram__DOT__missed_err_gnt_q)) 
                            & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)) 
                           & (IData)(vlSelfRef.tlul_adapter_sram__DOT__sramreqfifo_wready));
                    vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout 
                        = vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__inp;
                }(), (IData)(vlSelfRef.__Vfunc_tlul_adapter_sram__DOT__sv2v_cast_1__71__Vfuncout))));
    vlSelfRef.tlul_adapter_sram__02Etl_o[0U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[1U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[1U];
    vlSelfRef.tlul_adapter_sram__02Etl_o[2U] = vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U];
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr 
        = (((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
             >> 0xcU) & vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[0U]) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_wready)));
    tlul_adapter_sram__DOT__reqfifo_rready = (IData)(
                                                     ((vlSelfRef.tlul_adapter_sram__DOT__tl_o_int[2U] 
                                                       >> 1U) 
                                                      & vlSelfRef.tlul_adapter_sram__02Etl_i[0U]));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_wptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__wptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(tlul_adapter_sram__DOT__reqfifo_rready)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__rspfifo_rvalid) 
           & ((~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__under_rst)) 
              & (IData)(((0x8000U == (0x1c000U & vlSelfRef.tlul_adapter_sram__DOT__reqfifo_rdata)) 
                         & (IData)(tlul_adapter_sram__DOT__reqfifo_rready)))));
    vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_reqfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
    vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_set 
        = ((IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__fifo_incr_rptr) 
           & (~ (IData)(vlSelfRef.tlul_adapter_sram__DOT__u_rspfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)));
}

VL_INLINE_OPT void Vspi_host___024root___nba_comb__TOP__7(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___nba_comb__TOP__7\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata 
        = ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
            ? 0U : ((0x17U >= (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                     (3U 
                                                      & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                     ? (0xffU & (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__storage 
                                 >> (0x1fU & VL_SHIFTL_III(5,5,32, 
                                                           (3U 
                                                            & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_txfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                     : 0U));
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next = 0U;
    vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next 
        = ((1U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
            ? ((0xfffffff8U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
               | (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_rxrst__q) 
                   << 2U) | (((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_txrst__q) 
                              << 1U) | (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q))))
            : ((2U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                ? ((0xfffffff0U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                   | (((8U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_rvalid)) 
                              << 3U)) | (4U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__rx_fifo_wready)) 
                                               << 2U))) 
                      | ((2U & ((~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid)) 
                                << 1U)) | (1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))))))
                : ((4U & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                    ? ((0xffffff00U & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next) 
                       | ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__fifo_empty)
                           ? 0U : ((0x17U >= (0x1fU 
                                              & VL_SHIFTL_III(5,5,32, 
                                                              (3U 
                                                               & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U)))
                                    ? (0xffU & (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__storage 
                                                >> 
                                                (0x1fU 
                                                 & VL_SHIFTL_III(5,5,32, 
                                                                 (3U 
                                                                  & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__u_spi_rxfifo__DOT__gen_normal_fifo__DOT__u_fifo_cnt__DOT__rptr_wrap_cnt_q)), 3U))))
                                    : 0U))) : ((8U 
                                                & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__addr_hit))
                                                ? (0xffffff00U 
                                                   & vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__reg_rdata_next)
                                                : 0xffffffffU))));
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q;
    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
        = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q;
    if ((0U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((((IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT____Vcellout__u_ctrl_en__q) 
              & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_reg__DOT__wdata_qe)) 
             & (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_wready))) {
            if ((2U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_d 
                    = (1U & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata) 
                             >> 7U));
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        }
    } else if ((1U == (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_state))) {
        if ((1U < (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__byte_cnt_q))) {
            if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = (0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                    << 1U));
                }
            } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
            }
        } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__r_wn_q) {
            if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
                if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk) {
                    vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                        = ((0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                     << 1U)) | (IData)(vlSelfRef.spi_sdio_i));
                }
            } else {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = ((0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                 << 1U)) | (IData)(vlSelfRef.spi_sdio_i));
            }
        } else if ((8U > (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__bit_cnt_q))) {
            if ((1U & (~ (IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__sclk)))) {
                vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                    = (0xfeU & ((IData)(vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_q) 
                                << 1U));
            }
        } else if (vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rvalid) {
            vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__current_byte_d 
                = vlSelfRef.spi_host__DOT__u_spi_host_core__DOT__tx_fifo_rdata;
        }
    }
}

void Vspi_host___024root___eval_triggers__act(Vspi_host___024root* vlSelf);

bool Vspi_host___024root___eval_phase__act(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_phase__act\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<26> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vspi_host___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vspi_host___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void Vspi_host___024root___eval_nba(Vspi_host___024root* vlSelf);

bool Vspi_host___024root___eval_phase__nba(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_phase__nba\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vspi_host___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host___024root___dump_triggers__ico(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host___024root___dump_triggers__nba(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vspi_host___024root___dump_triggers__act(Vspi_host___024root* vlSelf);
#endif  // VL_DEBUG

void Vspi_host___024root___eval(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vspi_host___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/spi_host.v", 311, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vspi_host___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vspi_host___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/spi_host.v", 311, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vspi_host___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/spi_host.v", 311, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vspi_host___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vspi_host___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vspi_host___024root___eval_debug_assertions(Vspi_host___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vspi_host___024root___eval_debug_assertions\n"); );
    Vspi_host__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_cdc_rand_delay__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_cdc_rand_delay.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prev_data_i & 0xfeU)))) {
        Verilated::overWidthError("prev_data_i");}
    if (VL_UNLIKELY(((vlSelfRef.src_data_i & 0xfeU)))) {
        Verilated::overWidthError("src_data_i");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("sram2tlul.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.sram2tlul__02Etl_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("sram2tlul.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_req_i & 0xfeU)))) {
        Verilated::overWidthError("mem_req_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_write_i & 0xfeU)))) {
        Verilated::overWidthError("mem_write_i");}
    if (VL_UNLIKELY(((vlSelfRef.mem_addr_i & 0xf000U)))) {
        Verilated::overWidthError("mem_addr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_wr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_wr_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.wvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.clk_rd_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rst_rd_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_simple__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_simple.rready_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_wr_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_wr_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_wr_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_wr_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Ewvalid_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.wvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Eclk_rd_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.clk_rd_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erst_rd_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rst_rd_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_fifo_async_sram_adapter__02Erready_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_fifo_async_sram_adapter.rready_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("w_sram_rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.w_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("w_sram_rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_gnt_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("r_sram_rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.r_sram_rerror_i & 0xfcU)))) {
        Verilated::overWidthError("r_sram_rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.enable_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter.filter_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Eenable_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.enable_i");}
    if (VL_UNLIKELY(((vlSelfRef.prim_filter_ctr__02Efilter_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("prim_filter_ctr.filter_i");}
    if (VL_UNLIKELY(((vlSelfRef.thresh_i & 0xfcU)))) {
        Verilated::overWidthError("thresh_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_host.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.req_i & 0xfeU)))) {
        Verilated::overWidthError("req_i");}
    if (VL_UNLIKELY(((vlSelfRef.we_i & 0xfeU)))) {
        Verilated::overWidthError("we_i");}
    if (VL_UNLIKELY(((vlSelfRef.wdata_intg_i & 0x80U)))) {
        Verilated::overWidthError("wdata_intg_i");}
    if (VL_UNLIKELY(((vlSelfRef.be_i & 0xf0U)))) {
        Verilated::overWidthError("be_i");}
    if (VL_UNLIKELY(((vlSelfRef.instr_type_i & 0xf0U)))) {
        Verilated::overWidthError("instr_type_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_host__02Etl_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_adapter_host.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_adapter_sram.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_adapter_sram__02Etl_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_adapter_sram.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.en_ifetch_i & 0xf0U)))) {
        Verilated::overWidthError("en_ifetch_i");}
    if (VL_UNLIKELY(((vlSelfRef.gnt_i & 0xfeU)))) {
        Verilated::overWidthError("gnt_i");}
    if (VL_UNLIKELY(((vlSelfRef.rvalid_i & 0xfeU)))) {
        Verilated::overWidthError("rvalid_i");}
    if (VL_UNLIKELY(((vlSelfRef.rerror_i & 0xfcU)))) {
        Verilated::overWidthError("rerror_i");}
    if (VL_UNLIKELY(((vlSelfRef.readback_en_i & 0xf0U)))) {
        Verilated::overWidthError("readback_en_i");}
    if (VL_UNLIKELY(((vlSelfRef.wr_collision_i & 0xfeU)))) {
        Verilated::overWidthError("wr_collision_i");}
    if (VL_UNLIKELY(((vlSelfRef.write_pending_i & 0xfeU)))) {
        Verilated::overWidthError("write_pending_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_assert_multiple__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_assert_multiple.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.h2d[6U] & 0xfc000000U)))) {
        Verilated::overWidthError("h2d");}
    if (VL_UNLIKELY(((vlSelfRef.d2h[4U] & 0xfffffff0U)))) {
        Verilated::overWidthError("d2h");}
    if (VL_UNLIKELY(((vlSelfRef.clk_h_i & 0xfeU)))) {
        Verilated::overWidthError("clk_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.rst_h_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_h_ni");}
    if (VL_UNLIKELY(((vlSelfRef.clk_d_i & 0xfeU)))) {
        Verilated::overWidthError("clk_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.rst_d_ni & 0xfeU)))) {
        Verilated::overWidthError("rst_d_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_fifo_async__02Etl_h_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_fifo_async.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_fifo_async__02Etl_d_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_fifo_async.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_1n.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Etl_h_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("tlul_socket_1n.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_1n__02Etl_d_i[8U] 
                      & 0xffffff00U)))) {
        Verilated::overWidthError("tlul_socket_1n.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.dev_select_i & 0xf8U)))) {
        Verilated::overWidthError("dev_select_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("tlul_socket_m1.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Etl_h_i[0xdU] 
                      & 0xfff00000U)))) {
        Verilated::overWidthError("tlul_socket_m1.tl_h_i");}
    if (VL_UNLIKELY(((vlSelfRef.tlul_socket_m1__02Etl_d_i[2U] 
                      & 0xfffffffcU)))) {
        Verilated::overWidthError("tlul_socket_m1.tl_d_i");}
    if (VL_UNLIKELY(((vlSelfRef.spi_host__02Eclk_i 
                      & 0xfeU)))) {
        Verilated::overWidthError("spi_host.clk_i");}
    if (VL_UNLIKELY(((vlSelfRef.spi_host__02Erst_ni 
                      & 0xfeU)))) {
        Verilated::overWidthError("spi_host.rst_ni");}
    if (VL_UNLIKELY(((vlSelfRef.spi_host__02Etl_i[3U] 
                      & 0xffffe000U)))) {
        Verilated::overWidthError("spi_host.tl_i");}
    if (VL_UNLIKELY(((vlSelfRef.spi_sdio_i & 0xfeU)))) {
        Verilated::overWidthError("spi_sdio_i");}
}
#endif  // VL_DEBUG
