// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_pkg__pch.h"

//============================================================
// Constructors

Vtop_pkg::Vtop_pkg(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_pkg__Syms(contextp(), _vcname__, this)}
    , prim_clk_div__02Eclk_i{vlSymsp->TOP.prim_clk_div__02Eclk_i}
    , prim_clk_div__02Erst_ni{vlSymsp->TOP.prim_clk_div__02Erst_ni}
    , prim_lifo__02Eclk_i{vlSymsp->TOP.prim_lifo__02Eclk_i}
    , prim_lifo__02Erst_ni{vlSymsp->TOP.prim_lifo__02Erst_ni}
    , prim_ram__02Eclk_i{vlSymsp->TOP.prim_ram__02Eclk_i}
    , prim_rom__02Eclk_i{vlSymsp->TOP.prim_rom__02Eclk_i}
    , prim_shreg__02Eclk_i{vlSymsp->TOP.prim_shreg__02Eclk_i}
    , prim_cdc_rand_delay__02Eclk_i{vlSymsp->TOP.prim_cdc_rand_delay__02Eclk_i}
    , prim_cdc_rand_delay__02Erst_ni{vlSymsp->TOP.prim_cdc_rand_delay__02Erst_ni}
    , prim_intr_hw__02Eclk_i{vlSymsp->TOP.prim_intr_hw__02Eclk_i}
    , prim_intr_hw__02Erst_ni{vlSymsp->TOP.prim_intr_hw__02Erst_ni}
    , src_clk_i{vlSymsp->TOP.src_clk_i}
    , src_rst_ni{vlSymsp->TOP.src_rst_ni}
    , dst_clk_i{vlSymsp->TOP.dst_clk_i}
    , dst_rst_ni{vlSymsp->TOP.dst_rst_ni}
    , prim_counter__02Eclk_i{vlSymsp->TOP.prim_counter__02Eclk_i}
    , prim_counter__02Erst_ni{vlSymsp->TOP.prim_counter__02Erst_ni}
    , prim_deglitch__02Eclk_i{vlSymsp->TOP.prim_deglitch__02Eclk_i}
    , prim_deglitch__02Erst_ni{vlSymsp->TOP.prim_deglitch__02Erst_ni}
    , prim_edge_detect__02Eclk_i{vlSymsp->TOP.prim_edge_detect__02Eclk_i}
    , prim_edge_detect__02Erst_ni{vlSymsp->TOP.prim_edge_detect__02Erst_ni}
    , rd_clk_i{vlSymsp->TOP.rd_clk_i}
    , wr_clk_i{vlSymsp->TOP.wr_clk_i}
    , prim_fifo__02Erst_ni{vlSymsp->TOP.prim_fifo__02Erst_ni}
    , prim_reg__02Eclk_i{vlSymsp->TOP.prim_reg__02Eclk_i}
    , prim_reg__02Erst_ni{vlSymsp->TOP.prim_reg__02Erst_ni}
    , rrarbiter__02Eclk_i{vlSymsp->TOP.rrarbiter__02Eclk_i}
    , rrarbiter__02Erst_ni{vlSymsp->TOP.rrarbiter__02Erst_ni}
    , prim_fifo_async_simple__02Eclk_wr_i{vlSymsp->TOP.prim_fifo_async_simple__02Eclk_wr_i}
    , prim_fifo_async_simple__02Erst_wr_ni{vlSymsp->TOP.prim_fifo_async_simple__02Erst_wr_ni}
    , prim_fifo_async_simple__02Eclk_rd_i{vlSymsp->TOP.prim_fifo_async_simple__02Eclk_rd_i}
    , prim_fifo_async_simple__02Erst_rd_ni{vlSymsp->TOP.prim_fifo_async_simple__02Erst_rd_ni}
    , prim_fifo_async_sram_adapter__02Eclk_wr_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Eclk_wr_i}
    , prim_fifo_async_sram_adapter__02Erst_wr_ni{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erst_wr_ni}
    , prim_fifo_async_sram_adapter__02Eclk_rd_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Eclk_rd_i}
    , prim_fifo_async_sram_adapter__02Erst_rd_ni{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erst_rd_ni}
    , prim_filter__02Eclk_i{vlSymsp->TOP.prim_filter__02Eclk_i}
    , prim_filter__02Erst_ni{vlSymsp->TOP.prim_filter__02Erst_ni}
    , prim_filter_ctr__02Eclk_i{vlSymsp->TOP.prim_filter_ctr__02Eclk_i}
    , prim_filter_ctr__02Erst_ni{vlSymsp->TOP.prim_filter_ctr__02Erst_ni}
    , clk_src_i{vlSymsp->TOP.clk_src_i}
    , rst_src_ni{vlSymsp->TOP.rst_src_ni}
    , clk_dst_i{vlSymsp->TOP.clk_dst_i}
    , rst_dst_ni{vlSymsp->TOP.rst_dst_ni}
    , prim_alert_sender__02Eclk_i{vlSymsp->TOP.prim_alert_sender__02Eclk_i}
    , prim_alert_sender__02Erst_ni{vlSymsp->TOP.prim_alert_sender__02Erst_ni}
    , tlul_adapter_host__02Eclk_i{vlSymsp->TOP.tlul_adapter_host__02Eclk_i}
    , tlul_adapter_host__02Erst_ni{vlSymsp->TOP.tlul_adapter_host__02Erst_ni}
    , tlul_adapter_sram__02Eclk_i{vlSymsp->TOP.tlul_adapter_sram__02Eclk_i}
    , tlul_adapter_sram__02Erst_ni{vlSymsp->TOP.tlul_adapter_sram__02Erst_ni}
    , clk_h_i{vlSymsp->TOP.clk_h_i}
    , rst_h_ni{vlSymsp->TOP.rst_h_ni}
    , clk_d_i{vlSymsp->TOP.clk_d_i}
    , rst_d_ni{vlSymsp->TOP.rst_d_ni}
    , tlul_socket_1n__02Eclk_i{vlSymsp->TOP.tlul_socket_1n__02Eclk_i}
    , tlul_socket_1n__02Erst_ni{vlSymsp->TOP.tlul_socket_1n__02Erst_ni}
    , tlul_socket_m1__02Eclk_i{vlSymsp->TOP.tlul_socket_m1__02Eclk_i}
    , tlul_socket_m1__02Erst_ni{vlSymsp->TOP.tlul_socket_m1__02Erst_ni}
    , my_ip__02Eclk_i{vlSymsp->TOP.my_ip__02Eclk_i}
    , my_ip__02Erst_ni{vlSymsp->TOP.my_ip__02Erst_ni}
    , testmode_i{vlSymsp->TOP.testmode_i}
    , prim_clk_div__02Een_i{vlSymsp->TOP.prim_clk_div__02Een_i}
    , prim_clk_div__02Eclk_o{vlSymsp->TOP.prim_clk_div__02Eclk_o}
    , prim_clk_gate__02Eclk_i{vlSymsp->TOP.prim_clk_gate__02Eclk_i}
    , prim_clk_gate__02Een_i{vlSymsp->TOP.prim_clk_gate__02Een_i}
    , test_en_i{vlSymsp->TOP.test_en_i}
    , prim_clk_gate__02Eclk_o{vlSymsp->TOP.prim_clk_gate__02Eclk_o}
    , A{vlSymsp->TOP.A}
    , Z{vlSymsp->TOP.Z}
    , prim_lifo__02Ewdata_i{vlSymsp->TOP.prim_lifo__02Ewdata_i}
    , prim_lifo__02Ewvalid_i{vlSymsp->TOP.prim_lifo__02Ewvalid_i}
    , prim_lifo__02Ewready_o{vlSymsp->TOP.prim_lifo__02Ewready_o}
    , prim_lifo__02Erdata_o{vlSymsp->TOP.prim_lifo__02Erdata_o}
    , prim_lifo__02Ervalid_o{vlSymsp->TOP.prim_lifo__02Ervalid_o}
    , prim_lifo__02Erready_i{vlSymsp->TOP.prim_lifo__02Erready_i}
    , lifo_full_o{vlSymsp->TOP.lifo_full_o}
    , lifo_empty_o{vlSymsp->TOP.lifo_empty_o}
    , prim_ram__02Erst_ni{vlSymsp->TOP.prim_ram__02Erst_ni}
    , prim_ram__02Een_i{vlSymsp->TOP.prim_ram__02Een_i}
    , prim_ram__02Ewe_i{vlSymsp->TOP.prim_ram__02Ewe_i}
    , prim_rom__02Erst_ni{vlSymsp->TOP.prim_rom__02Erst_ni}
    , prim_shreg__02Erst_ni{vlSymsp->TOP.prim_shreg__02Erst_ni}
    , prim_shreg__02Een_i{vlSymsp->TOP.prim_shreg__02Een_i}
    , prim_shreg__02Eserial_i{vlSymsp->TOP.prim_shreg__02Eserial_i}
    , pdata_o{vlSymsp->TOP.pdata_o}
    , serial_o{vlSymsp->TOP.serial_o}
    , prev_data_i{vlSymsp->TOP.prev_data_i}
    , prim_cdc_rand_delay__02Esrc_data_i{vlSymsp->TOP.prim_cdc_rand_delay__02Esrc_data_i}
    , prim_cdc_rand_delay__02Edst_data_o{vlSymsp->TOP.prim_cdc_rand_delay__02Edst_data_o}
    , event_intr_i{vlSymsp->TOP.event_intr_i}
    , reg2hw_intr_enable_q_i{vlSymsp->TOP.reg2hw_intr_enable_q_i}
    , reg2hw_intr_test_q_i{vlSymsp->TOP.reg2hw_intr_test_q_i}
    , reg2hw_intr_test_qe_i{vlSymsp->TOP.reg2hw_intr_test_qe_i}
    , reg2hw_intr_state_q_i{vlSymsp->TOP.reg2hw_intr_state_q_i}
    , hw2reg_intr_state_de_o{vlSymsp->TOP.hw2reg_intr_state_de_o}
    , hw2reg_intr_state_d_o{vlSymsp->TOP.hw2reg_intr_state_d_o}
    , intr_o{vlSymsp->TOP.intr_o}
    , cdc_2phase__02Esrc_data_i{vlSymsp->TOP.cdc_2phase__02Esrc_data_i}
    , src_valid_i{vlSymsp->TOP.src_valid_i}
    , src_ready_o{vlSymsp->TOP.src_ready_o}
    , cdc_2phase__02Edst_data_o{vlSymsp->TOP.cdc_2phase__02Edst_data_o}
    , dst_valid_o{vlSymsp->TOP.dst_valid_o}
    , dst_ready_i{vlSymsp->TOP.dst_ready_i}
    , prim_counter__02Een_i{vlSymsp->TOP.prim_counter__02Een_i}
    , clr_i{vlSymsp->TOP.clr_i}
    , up_down_i{vlSymsp->TOP.up_down_i}
    , step_i{vlSymsp->TOP.step_i}
    , tc_val_i{vlSymsp->TOP.tc_val_i}
    , val_o{vlSymsp->TOP.val_o}
    , tc_o{vlSymsp->TOP.tc_o}
    , prim_deglitch__02Een_i{vlSymsp->TOP.prim_deglitch__02Een_i}
    , d_i{vlSymsp->TOP.d_i}
    , q_o{vlSymsp->TOP.q_o}
    , prim_edge_detect__02Een_i{vlSymsp->TOP.prim_edge_detect__02Een_i}
    , prim_edge_detect__02Eserial_i{vlSymsp->TOP.prim_edge_detect__02Eserial_i}
    , r_edge_o{vlSymsp->TOP.r_edge_o}
    , f_edge_o{vlSymsp->TOP.f_edge_o}
    , prim_fifo__02Ewdata_i{vlSymsp->TOP.prim_fifo__02Ewdata_i}
    , prim_fifo__02Ewvalid_i{vlSymsp->TOP.prim_fifo__02Ewvalid_i}
    , prim_fifo__02Ewready_o{vlSymsp->TOP.prim_fifo__02Ewready_o}
    , prim_fifo__02Erdata_o{vlSymsp->TOP.prim_fifo__02Erdata_o}
    , prim_fifo__02Ervalid_o{vlSymsp->TOP.prim_fifo__02Ervalid_o}
    , prim_fifo__02Erready_i{vlSymsp->TOP.prim_fifo__02Erready_i}
    , fifo_full{vlSymsp->TOP.fifo_full}
    , fifo_empty{vlSymsp->TOP.fifo_empty}
    , we{vlSymsp->TOP.we}
    , de{vlSymsp->TOP.de}
    , qe{vlSymsp->TOP.qe}
    , flush_i{vlSymsp->TOP.flush_i}
    , rrarbiter__02Een_i{vlSymsp->TOP.rrarbiter__02Een_i}
    , vld_o{vlSymsp->TOP.vld_o}
    , idx_o{vlSymsp->TOP.idx_o}
    , prim_fifo_async_simple__02Ewvalid_i{vlSymsp->TOP.prim_fifo_async_simple__02Ewvalid_i}
    , prim_fifo_async_simple__02Ewready_o{vlSymsp->TOP.prim_fifo_async_simple__02Ewready_o}
    , prim_fifo_async_simple__02Ervalid_o{vlSymsp->TOP.prim_fifo_async_simple__02Ervalid_o}
    , prim_fifo_async_simple__02Erready_i{vlSymsp->TOP.prim_fifo_async_simple__02Erready_i}
    , prim_fifo_async_sram_adapter__02Ewvalid_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewvalid_i}
    , prim_fifo_async_sram_adapter__02Ewready_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewready_o}
    , wdepth_o{vlSymsp->TOP.wdepth_o}
    , prim_fifo_async_sram_adapter__02Ervalid_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ervalid_o}
    , prim_fifo_async_sram_adapter__02Erready_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erready_i}
    , rdepth_o{vlSymsp->TOP.rdepth_o}
    , r_full_o{vlSymsp->TOP.r_full_o}
    , r_notempty_o{vlSymsp->TOP.r_notempty_o}
    , w_full_o{vlSymsp->TOP.w_full_o}
    , w_sram_req_o{vlSymsp->TOP.w_sram_req_o}
    , w_sram_gnt_i{vlSymsp->TOP.w_sram_gnt_i}
    , w_sram_write_o{vlSymsp->TOP.w_sram_write_o}
    , w_sram_rvalid_i{vlSymsp->TOP.w_sram_rvalid_i}
    , w_sram_rerror_i{vlSymsp->TOP.w_sram_rerror_i}
    , r_sram_req_o{vlSymsp->TOP.r_sram_req_o}
    , r_sram_gnt_i{vlSymsp->TOP.r_sram_gnt_i}
    , r_sram_write_o{vlSymsp->TOP.r_sram_write_o}
    , r_sram_rvalid_i{vlSymsp->TOP.r_sram_rvalid_i}
    , r_sram_rerror_i{vlSymsp->TOP.r_sram_rerror_i}
    , prim_filter__02Eenable_i{vlSymsp->TOP.prim_filter__02Eenable_i}
    , prim_filter__02Efilter_i{vlSymsp->TOP.prim_filter__02Efilter_i}
    , prim_filter__02Efilter_o{vlSymsp->TOP.prim_filter__02Efilter_o}
    , prim_filter_ctr__02Eenable_i{vlSymsp->TOP.prim_filter_ctr__02Eenable_i}
    , prim_filter_ctr__02Efilter_i{vlSymsp->TOP.prim_filter_ctr__02Efilter_i}
    , thresh_i{vlSymsp->TOP.thresh_i}
    , prim_filter_ctr__02Efilter_o{vlSymsp->TOP.prim_filter_ctr__02Efilter_o}
    , src_regwen_i{vlSymsp->TOP.src_regwen_i}
    , src_we_i{vlSymsp->TOP.src_we_i}
    , src_re_i{vlSymsp->TOP.src_re_i}
    , src_busy_o{vlSymsp->TOP.src_busy_o}
    , dst_update_i{vlSymsp->TOP.dst_update_i}
    , dst_we_o{vlSymsp->TOP.dst_we_o}
    , dst_re_o{vlSymsp->TOP.dst_re_o}
    , dst_regwen_o{vlSymsp->TOP.dst_regwen_o}
    , prim_reg_we_check__02Eclk_i{vlSymsp->TOP.prim_reg_we_check__02Eclk_i}
    , prim_reg_we_check__02Erst_ni{vlSymsp->TOP.prim_reg_we_check__02Erst_ni}
    , prim_reg_we_check__02Een_i{vlSymsp->TOP.prim_reg_we_check__02Een_i}
    , prim_reg_we_check__02Eerr_o{vlSymsp->TOP.prim_reg_we_check__02Eerr_o}
    , alert_test_i{vlSymsp->TOP.alert_test_i}
    , alert_req_i{vlSymsp->TOP.alert_req_i}
    , alert_ack_o{vlSymsp->TOP.alert_ack_o}
    , alert_state_o{vlSymsp->TOP.alert_state_o}
    , alert_rx_i{vlSymsp->TOP.alert_rx_i}
    , alert_tx_o{vlSymsp->TOP.alert_tx_o}
    , sram2tlul__02Eclk_i{vlSymsp->TOP.sram2tlul__02Eclk_i}
    , sram2tlul__02Erst_ni{vlSymsp->TOP.sram2tlul__02Erst_ni}
    , mem_req_i{vlSymsp->TOP.mem_req_i}
    , mem_write_i{vlSymsp->TOP.mem_write_i}
    , mem_rvalid_o{vlSymsp->TOP.mem_rvalid_o}
    , mem_error_o{vlSymsp->TOP.mem_error_o}
    , tlul_adapter_host__02Ereq_i{vlSymsp->TOP.tlul_adapter_host__02Ereq_i}
    , gnt_o{vlSymsp->TOP.gnt_o}
    , tlul_adapter_host__02Ewe_i{vlSymsp->TOP.tlul_adapter_host__02Ewe_i}
    , wdata_intg_i{vlSymsp->TOP.wdata_intg_i}
    , be_i{vlSymsp->TOP.be_i}
    , instr_type_i{vlSymsp->TOP.instr_type_i}
    , valid_o{vlSymsp->TOP.valid_o}
    , rdata_intg_o{vlSymsp->TOP.rdata_intg_o}
    , tlul_adapter_host__02Eerr_o{vlSymsp->TOP.tlul_adapter_host__02Eerr_o}
    , intg_err_o{vlSymsp->TOP.intg_err_o}
    , en_ifetch_i{vlSymsp->TOP.en_ifetch_i}
    , req_o{vlSymsp->TOP.req_o}
    , req_type_o{vlSymsp->TOP.req_type_o}
    , gnt_i{vlSymsp->TOP.gnt_i}
    , we_o{vlSymsp->TOP.we_o}
    , intg_error_o{vlSymsp->TOP.intg_error_o}
    , rvalid_i{vlSymsp->TOP.rvalid_i}
    , rerror_i{vlSymsp->TOP.rerror_i}
    , compound_txn_in_progress_o{vlSymsp->TOP.compound_txn_in_progress_o}
    , readback_en_i{vlSymsp->TOP.readback_en_i}
    , readback_error_o{vlSymsp->TOP.readback_error_o}
    , wr_collision_i{vlSymsp->TOP.wr_collision_i}
    , write_pending_i{vlSymsp->TOP.write_pending_i}
    , tlul_assert_multiple__02Eclk_i{vlSymsp->TOP.tlul_assert_multiple__02Eclk_i}
    , tlul_assert_multiple__02Erst_ni{vlSymsp->TOP.tlul_assert_multiple__02Erst_ni}
    , dev_select_i{vlSymsp->TOP.dev_select_i}
    , port_i{vlSymsp->TOP.port_i}
    , port_o{vlSymsp->TOP.port_o}
    , prim_ram__02Eaddr_i{vlSymsp->TOP.prim_ram__02Eaddr_i}
    , prim_rom__02Eaddr_i{vlSymsp->TOP.prim_rom__02Eaddr_i}
    , rrarbiter__02Ereq_i{vlSymsp->TOP.rrarbiter__02Ereq_i}
    , ack_o{vlSymsp->TOP.ack_o}
    , prim_fifo_async_simple__02Ewdata_i{vlSymsp->TOP.prim_fifo_async_simple__02Ewdata_i}
    , prim_fifo_async_simple__02Erdata_o{vlSymsp->TOP.prim_fifo_async_simple__02Erdata_o}
    , w_sram_addr_o{vlSymsp->TOP.w_sram_addr_o}
    , r_sram_addr_o{vlSymsp->TOP.r_sram_addr_o}
    , mem_addr_i{vlSymsp->TOP.mem_addr_i}
    , addr_o{vlSymsp->TOP.addr_o}
    , prim_ram__02Ewdata_i{vlSymsp->TOP.prim_ram__02Ewdata_i}
    , prim_ram__02Erdata_o{vlSymsp->TOP.prim_ram__02Erdata_o}
    , prim_rom__02Erdata_o{vlSymsp->TOP.prim_rom__02Erdata_o}
    , wd{vlSymsp->TOP.wd}
    , ds{vlSymsp->TOP.ds}
    , qs{vlSymsp->TOP.qs}
    , d{vlSymsp->TOP.d}
    , q{vlSymsp->TOP.q}
    , prim_fifo_async_sram_adapter__02Ewdata_i{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Ewdata_i}
    , prim_fifo_async_sram_adapter__02Erdata_o{vlSymsp->TOP.prim_fifo_async_sram_adapter__02Erdata_o}
    , w_sram_wdata_o{vlSymsp->TOP.w_sram_wdata_o}
    , w_sram_wmask_o{vlSymsp->TOP.w_sram_wmask_o}
    , w_sram_rdata_i{vlSymsp->TOP.w_sram_rdata_i}
    , r_sram_wdata_o{vlSymsp->TOP.r_sram_wdata_o}
    , r_sram_wmask_o{vlSymsp->TOP.r_sram_wmask_o}
    , r_sram_rdata_i{vlSymsp->TOP.r_sram_rdata_i}
    , src_wd_i{vlSymsp->TOP.src_wd_i}
    , src_qs_o{vlSymsp->TOP.src_qs_o}
    , dst_ds_i{vlSymsp->TOP.dst_ds_i}
    , dst_qs_i{vlSymsp->TOP.dst_qs_i}
    , dst_wd_o{vlSymsp->TOP.dst_wd_o}
    , oh_i{vlSymsp->TOP.oh_i}
    , mem_wdata_i{vlSymsp->TOP.mem_wdata_i}
    , mem_rdata_o{vlSymsp->TOP.mem_rdata_o}
    , tlul_adapter_host__02Eaddr_i{vlSymsp->TOP.tlul_adapter_host__02Eaddr_i}
    , tlul_adapter_host__02Ewdata_i{vlSymsp->TOP.tlul_adapter_host__02Ewdata_i}
    , tlul_adapter_host__02Erdata_o{vlSymsp->TOP.tlul_adapter_host__02Erdata_o}
    , wdata_o{vlSymsp->TOP.wdata_o}
    , wmask_o{vlSymsp->TOP.wmask_o}
    , rdata_i{vlSymsp->TOP.rdata_i}
    , sram2tlul__02Etl_o{vlSymsp->TOP.sram2tlul__02Etl_o}
    , sram2tlul__02Etl_i{vlSymsp->TOP.sram2tlul__02Etl_i}
    , tlul_adapter_host__02Etl_o{vlSymsp->TOP.tlul_adapter_host__02Etl_o}
    , tlul_adapter_host__02Etl_i{vlSymsp->TOP.tlul_adapter_host__02Etl_i}
    , tlul_adapter_sram__02Etl_i{vlSymsp->TOP.tlul_adapter_sram__02Etl_i}
    , tlul_adapter_sram__02Etl_o{vlSymsp->TOP.tlul_adapter_sram__02Etl_o}
    , tlul_fifo_async__02Etl_h_i{vlSymsp->TOP.tlul_fifo_async__02Etl_h_i}
    , tlul_fifo_async__02Etl_h_o{vlSymsp->TOP.tlul_fifo_async__02Etl_h_o}
    , tlul_fifo_async__02Etl_d_o{vlSymsp->TOP.tlul_fifo_async__02Etl_d_o}
    , tlul_fifo_async__02Etl_d_i{vlSymsp->TOP.tlul_fifo_async__02Etl_d_i}
    , tlul_socket_1n__02Etl_h_i{vlSymsp->TOP.tlul_socket_1n__02Etl_h_i}
    , tlul_socket_1n__02Etl_h_o{vlSymsp->TOP.tlul_socket_1n__02Etl_h_o}
    , tlul_socket_m1__02Etl_d_o{vlSymsp->TOP.tlul_socket_m1__02Etl_d_o}
    , tlul_socket_m1__02Etl_d_i{vlSymsp->TOP.tlul_socket_m1__02Etl_d_i}
    , my_ip__02Etl_i{vlSymsp->TOP.my_ip__02Etl_i}
    , my_ip__02Etl_o{vlSymsp->TOP.my_ip__02Etl_o}
    , h2d{vlSymsp->TOP.h2d}
    , d2h{vlSymsp->TOP.d2h}
    , tlul_socket_1n__02Etl_d_o{vlSymsp->TOP.tlul_socket_1n__02Etl_d_o}
    , tlul_socket_1n__02Etl_d_i{vlSymsp->TOP.tlul_socket_1n__02Etl_d_i}
    , tlul_socket_m1__02Etl_h_i{vlSymsp->TOP.tlul_socket_m1__02Etl_h_i}
    , tlul_socket_m1__02Etl_h_o{vlSymsp->TOP.tlul_socket_m1__02Etl_h_o}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__0__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__1__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__2__KET____DOT__fifo_d}
    , __PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d{vlSymsp->TOP.__PVT__tlul_socket_1n__DOT__gen_dfifo__BRA__3__KET____DOT__fifo_d}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__0__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__1__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__2__KET____DOT__u_hostfifo}
    , __PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo{vlSymsp->TOP.__PVT__tlul_socket_m1__DOT__gen_host_fifo__BRA__3__KET____DOT__u_hostfifo}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_pkg::Vtop_pkg(const char* _vcname__)
    : Vtop_pkg(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_pkg::~Vtop_pkg() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_pkg___024root___eval_debug_assertions(Vtop_pkg___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop_pkg___024root___eval_static(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___eval_initial(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___eval_settle(Vtop_pkg___024root* vlSelf);
void Vtop_pkg___024root___eval(Vtop_pkg___024root* vlSelf);

void Vtop_pkg::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_pkg::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_pkg___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop_pkg___024root___eval_static(&(vlSymsp->TOP));
        Vtop_pkg___024root___eval_initial(&(vlSymsp->TOP));
        Vtop_pkg___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop_pkg___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop_pkg::eventsPending() { return false; }

uint64_t Vtop_pkg::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop_pkg::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop_pkg___024root___eval_final(Vtop_pkg___024root* vlSelf);

VL_ATTR_COLD void Vtop_pkg::final() {
    Vtop_pkg___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_pkg::hierName() const { return vlSymsp->name(); }
const char* Vtop_pkg::modelName() const { return "Vtop_pkg"; }
unsigned Vtop_pkg::threads() const { return 1; }
void Vtop_pkg::prepareClone() const { contextp()->prepareClone(); }
void Vtop_pkg::atClone() const {
    contextp()->threadPoolpOnClone();
}
