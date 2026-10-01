`timescale 1ns/1ps

module uart_tb;
  logic clk_i;
  logic rst_ni;
  uart_reg_pkg::reg_req_t reg_req_i;
  uart_reg_pkg::reg_rsp_t reg_rsp_o;
  logic core_reg_req_valid;
  logic core_reg_req_write;
  logic [uart_reg_pkg::AW-1:0] core_reg_req_addr;
  logic [uart_reg_pkg::DW-1:0] core_reg_req_wdata;
  logic [uart_reg_pkg::DBW-1:0] core_reg_req_wstrb;
  logic core_reg_rsp_ready;
  logic core_reg_rsp_error;
  logic [uart_reg_pkg::DW-1:0] core_reg_rsp_rdata;



  logic rx_i;
  logic tx_o;
assign reg_req_i = '{
  valid: core_reg_req_valid, write: core_reg_req_write,
  addr: core_reg_req_addr, wdata: core_reg_req_wdata,
  wstrb: core_reg_req_wstrb
};
assign core_reg_rsp_ready = reg_rsp_o.ready;
assign core_reg_rsp_error = reg_rsp_o.error;
assign core_reg_rsp_rdata = reg_rsp_o.rdata;




  `ifdef FLEXSOC_ENABLE_SDF
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") begin
        `ifdef FLEXSOC_SDF_MIN
          $sdf_annotate(sdf_path, u_dut);
        `elsif FLEXSOC_SDF_TYP
          $sdf_annotate(sdf_path, u_dut);
        `else
          $sdf_annotate(sdf_path, u_dut);
        `endif
      end
    end
  `endif

  uart u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .rx_i                     (rx_i),
    .reg_req_i                (reg_req_i),
    .tx_o                     (tx_o),
    .reg_rsp_o                (reg_rsp_o)
  );
endmodule
