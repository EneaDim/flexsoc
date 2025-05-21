interface cache_wrapper_if #(parameter ADDR_WIDTH = 16, parameter DATA_WIDTH = 32) (
  input  logic clk_i,
  input  logic rst_ni
);

  logic                  cpu_valid_i;
  logic                  cpu_ready_o;
  logic                  cpu_we_i;
  logic [ADDR_WIDTH-1:0] cpu_adr_i;
  logic [DATA_WIDTH-1:0] cpu_wdata_i;
  logic [DATA_WIDTH-1:0] cpu_rdata_o;
  logic                  cpu_resp_valid_o;

  logic                  mem_valid_o;
  logic                  mem_ready_i;
  logic                  mem_we_o;
  logic [ADDR_WIDTH-1:0] mem_adr_o;
  logic [DATA_WIDTH-1:0] mem_wdata_o;
  logic [DATA_WIDTH-1:0] mem_rdata_i;

  modport drv (
    output cpu_valid_i,
    output cpu_we_i,
    output cpu_adr_i,
    output cpu_wdata_i,
    input  cpu_ready_o,
    input  cpu_rdata_o,
    input  cpu_resp_valid_o,

    input  mem_valid_o,
    input  mem_we_o,
    input  mem_adr_o,
    input  mem_wdata_o,
    output mem_ready_i,
    output mem_rdata_i
  );

  modport dut (
    input  cpu_valid_i,
    input  cpu_we_i,
    input  cpu_adr_i,
    input  cpu_wdata_i,
    output cpu_ready_o,
    output cpu_rdata_o,
    output cpu_resp_valid_o,

    output mem_valid_o,
    output mem_we_o,
    output mem_adr_o,
    output mem_wdata_o,
    input  mem_ready_i,
    input  mem_rdata_i
  );

endinterface

