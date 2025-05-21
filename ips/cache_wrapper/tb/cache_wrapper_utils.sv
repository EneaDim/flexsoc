class CacheDriver;
  virtual interface cache_if;

  function new(virtual interface cache_if if_inst);
    this.cache_if = if_inst;
  endfunction

  // Write Task
  task write(input logic [15:0] addr, input logic [31:0] data);
    @(posedge cache_if.clk_i);
    cache_if.cpu_adr_i     <= addr;
    cache_if.cpu_wdata_i   <= data;
    cache_if.cpu_we_i      <= 1;
    cache_if.cpu_valid_i   <= 1;

    // Wait for cache to accept request
    wait (cache_if.cpu_ready_o);
    @(posedge cache_if.clk_i);
    cache_if.cpu_valid_i <= 0;

    // Wait for response
    wait (cache_if.cpu_resp_valid_o);
    @(posedge cache_if.clk_i);
  endtask

  // Read Task
  task read(input logic [15:0] addr, output logic [31:0] data);
    @(posedge cache_if.clk_i);
    cache_if.cpu_adr_i   <= addr;
    cache_if.cpu_we_i    <= 0;
    cache_if.cpu_valid_i <= 1;

    // Wait for cache to accept request
    wait (cache_if.cpu_ready_o);
    @(posedge cache_if.clk_i);
    cache_if.cpu_valid_i <= 0;

    // Wait for response
    wait (cache_if.cpu_resp_valid_o);
    @(posedge cache_if.clk_i);
    data = cache_if.cpu_rdata_o;
  endtask

endclass

