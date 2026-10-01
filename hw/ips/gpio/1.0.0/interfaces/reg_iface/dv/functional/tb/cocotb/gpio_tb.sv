`timescale 1ns/1ps

module gpio_tb;
  logic clk_i;
  logic rst_ni;
  gpio_reg_pkg::reg_req_t reg_req_i;
  gpio_reg_pkg::reg_rsp_t reg_rsp_o;
  logic core_reg_req_valid;
  logic core_reg_req_write;
  logic [gpio_reg_pkg::AW-1:0] core_reg_req_addr;
  logic [gpio_reg_pkg::DW-1:0] core_reg_req_wdata;
  logic [gpio_reg_pkg::DBW-1:0] core_reg_req_wstrb;
  logic core_reg_rsp_ready;
  logic core_reg_rsp_error;
  logic [gpio_reg_pkg::DW-1:0] core_reg_rsp_rdata;



  logic [3:0] cio_gpio_i;
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;
  logic [3:0] intr_gpio_o;
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

  gpio u_dut (
    .clk_i                    (clk_i),
    .rst_ni                   (rst_ni),
    .cio_gpio_i               (cio_gpio_i),
    .reg_req_i                (reg_req_i),
    .cio_gpio_o               (cio_gpio_o),
    .cio_gpio_en_o            (cio_gpio_en_o),
    .intr_gpio_o              (intr_gpio_o),
    .reg_rsp_o                (reg_rsp_o)
  );
endmodule
