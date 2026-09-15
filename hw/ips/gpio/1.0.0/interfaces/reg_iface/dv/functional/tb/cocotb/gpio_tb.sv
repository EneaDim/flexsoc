`timescale 1ns/1ps
module gpio_tb;
  import gpio_reg_pkg::*;
  logic clk_i;
  logic rst_ni;
  logic [3:0] cio_gpio_i;
  logic [3:0] cio_gpio_o;
  logic [3:0] cio_gpio_en_o;
  logic [3:0] intr_gpio_o;
  reg_req_t reg_req_i;
  reg_rsp_t reg_rsp_o;
  logic reg_req_valid;
  logic reg_req_write;
  logic [gpio_reg_pkg::AW-1:0] reg_req_addr;
  logic [gpio_reg_pkg::DW-1:0] reg_req_wdata;
  logic [gpio_reg_pkg::DBW-1:0] reg_req_wstrb;
  logic reg_rsp_ready;
  logic reg_rsp_error;
  logic [gpio_reg_pkg::DW-1:0] reg_rsp_rdata;

  assign reg_req_i = '{
    valid: reg_req_valid,
    write: reg_req_write,
    addr:  reg_req_addr,
    wdata: reg_req_wdata,
    wstrb: reg_req_wstrb
  };
  assign reg_rsp_ready = reg_rsp_o.ready;
  assign reg_rsp_error = reg_rsp_o.error;
  assign reg_rsp_rdata = reg_rsp_o.rdata;

  initial begin
    cio_gpio_i = '0;
    reg_req_valid = 1'b0;
    reg_req_write = 1'b0;
    reg_req_addr = '0;
    reg_req_wdata = '0;
    reg_req_wstrb = '0;
  end

  string wave_path;
  initial begin
    if (!$value$plusargs("WAVE=%s", wave_path)) begin
      if (!$value$plusargs("VCD=%s", wave_path)) wave_path = "";
    end
    if (wave_path != "") begin
      `ifdef FLEXSOC_COCOTB_WAVE_OWNER
        $display("[TB] dumpfile = %s owner=cocotb", wave_path);
      `else
        $display("[TB] dumpfile = %s owner=wrapper", wave_path);
        $dumpfile(wave_path);
        $dumpvars(0, gpio_tb);
      `endif
    end
    #1;
  end
  `ifdef FLEXSOC_ENABLE_SDF
    string sdf_path;
    initial begin
      if (!$value$plusargs("SDF=%s", sdf_path)) sdf_path = "";
      if (sdf_path != "") begin
        `ifdef FLEXSOC_SDF_MIN
          $sdf_annotate(sdf_path, u_gpio);
        `elsif FLEXSOC_SDF_TYP
          $sdf_annotate(sdf_path, u_gpio);
        `else
          $sdf_annotate(sdf_path, u_gpio);
        `endif
      end
    end
  `endif
  gpio u_gpio (.*);
endmodule
