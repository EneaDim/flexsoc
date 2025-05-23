`timescale 1ns/1ps

module cache_wrapper_tb;

  parameter int CLK_PERIOD    = 10; // Clock period in ns
  parameter int ADDR_WIDTH    = 16;
  parameter int DATA_WIDTH    = 32;
  parameter int CACHE_SIZE    = 1024;
  parameter int ASSOCIATIVITY = 2;

  // Clock and reset
  logic clk_i;
  logic rst_ni;
  logic [DATA_WIDTH-1:0] data;

  // CPU Interface signals
  logic        cpu_valid_i;
  logic        cpu_ready_o;
  logic        cpu_we_i;
  logic [ADDR_WIDTH-1:0] cpu_adr_i;
  logic [DATA_WIDTH-1:0] cpu_wdata_i;
  logic [DATA_WIDTH-1:0] cpu_rdata_o;
  logic        cpu_resp_valid_o;

  // Memory Interface signals (between cache_wrapper and main memory)
  logic        mem_valid_o;
  logic        mem_ready_i;
  logic        mem_we_o;
  logic [ADDR_WIDTH-1:0] mem_adr_o;
  logic [DATA_WIDTH-1:0] mem_wdata_o;
  logic [DATA_WIDTH-1:0] mem_rdata_i;

  // Clock generation
  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_cache_wrapper.vcd");
    `else
      $dumpfile("sim/dump_cache_wrapper_syn.vcd");
    `endif
    $dumpvars(0, cache_wrapper_tb);
  end

  // Instantiate DUT
  cache_wrapper #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH),
    .CACHE_SIZE(CACHE_SIZE),
    .ASSOCIATIVITY(ASSOCIATIVITY)
  ) dut (
    .clk_i,
    .rst_ni,

    // CPU Interface
    .cpu_valid_i,
    .cpu_ready_o,
    .cpu_we_i,
    .cpu_adr_i,
    .cpu_wdata_i,
    .cpu_rdata_o,
    .cpu_resp_valid_o,

    // Memory Interface
    .mem_valid_o,
    .mem_ready_i,
    .mem_we_o,
    .mem_adr_o,
    .mem_wdata_o,
    .mem_rdata_i
  );

  // ----------------------------
  // CPU Model - drives CPU interface signals
  // ----------------------------
  task cpu_write(input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data);
    begin
      @(negedge clk_i);
      cpu_valid_i = 1;
      cpu_we_i = 1;
      cpu_adr_i = addr;
      cpu_wdata_i = data;
      $display("[%0t] CPU WRITE request: addr=0x%04h data=0x%08h", $time, addr, data);
      wait (cpu_ready_o == 1);
      @(negedge clk_i);
      cpu_valid_i = 0;
      wait (cpu_resp_valid_o == 1);
      $display("[%0t] CPU WRITE response received", $time);
    end
  endtask

  task cpu_read(input logic [ADDR_WIDTH-1:0] addr, output logic [DATA_WIDTH-1:0] data);
    begin
      @(negedge clk_i);
      cpu_valid_i = 1;
      cpu_we_i = 0;
      cpu_adr_i = addr;
      cpu_wdata_i = 0;
      $display("[%0t] CPU READ request: addr=0x%04h", $time, addr);
      wait (cpu_ready_o == 1);
      @(negedge clk_i);
      cpu_valid_i = 0;
      wait (cpu_resp_valid_o == 1);
      data = cpu_rdata_o;
      $display("[%0t] CPU READ response received: data=0x%08h", $time, data);
    end
  endtask

  // ----------------------------
  // Main Memory Model with delay to simulate latency
  // ----------------------------
  typedef enum logic [1:0] {
    IDLE,
    WAIT_MEM
  } mem_state_t;
  
  mem_state_t mem_state = IDLE;
  logic [15:0] mem_addr_reg;
  logic [31:0] mem_wdata_reg;
  logic        mem_we_reg;
  
  int wait_cycles;
  
  logic [31:0] memory_array [0:65535];  // 64K locations (16-bit address space)
  
  logic mem_valid_o_d;  // delayed version for edge detection
  
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      mem_ready_i   <= 0;
      mem_rdata_i   <= 0;
      mem_state     <= IDLE;
      wait_cycles   <= 0;
      mem_valid_o_d <= 0;
    end else begin
      mem_valid_o_d <= mem_valid_o;  // store last cycle's value
      case (mem_state)
        IDLE: begin
          mem_ready_i <= 0;
          wait_cycles <= 0;
  
          // Only trigger on rising edge of mem_valid_o
          if (mem_valid_o && !mem_valid_o_d) begin
            mem_addr_reg  <= mem_adr_o;
            mem_wdata_reg <= mem_wdata_o;
            mem_we_reg    <= mem_we_o;
            mem_state     <= WAIT_MEM;
            $display("[%0t] MEM request received: %s @ 0x%04h data=0x%08h",
                     $time, mem_we_o ? "WRITE" : "READ", mem_adr_o, mem_wdata_o);
          end
        end
        WAIT_MEM: begin
          wait_cycles <= wait_cycles + 1;
          if (wait_cycles == 3) begin
            mem_ready_i <= 1;
            if (!mem_we_reg) begin
              // Simulated read data
              mem_rdata_i <= memory_array[mem_addr_reg];
              $display("[%0t] MEM READ data ready: 0x%08h", $time, mem_rdata_i);
            end else begin
              // Perform the actual write
              memory_array[mem_addr_reg] <= mem_wdata_reg;
              $display("[%0t] MEM WRITE complete @ 0x%04h with data=0x%08h", 
                       $time, mem_addr_reg, mem_wdata_reg);
            end
          end else if (wait_cycles == 4) begin
            mem_ready_i <= 0;
            mem_state <= IDLE;
          end else begin
            mem_ready_i <= 0;
          end
        end
      endcase
    end
  end

  // ------------------------
  // Monitor
  // ------------------------
  always @(posedge clk_i) begin
    if (cpu_valid_i || cpu_resp_valid_o) begin
      $display("[%0t] CPU signals: valid=%0b ready=%0b resp_valid=%0b addr=0x%04h we=%0b rdata=0x%08h",
      $time, cpu_valid_i, cpu_ready_o, cpu_resp_valid_o, cpu_adr_i, cpu_we_i, cpu_rdata_o);
    end
  end

  // ----------------------------
  // Testbench stimulus
  // ----------------------------
  initial begin
    // Reset
    rst_ni = 0;
    cpu_valid_i = 0;
    cpu_we_i = 0;
    cpu_adr_i = 0;
    cpu_wdata_i = 0;

    #20;
    rst_ni = 1;
    $display("[%0t] Reset deasserted", $time);

    // Perform CPU transactions to test cache hit/miss:
    // First write to address (should cause cache miss, memory write)
    cpu_write(16'h0010, 32'hDEADBEEF);
    @(negedge clk_i);

    cpu_write(16'h0020, 32'hBEEFDEAD);
    @(negedge clk_i);

    // Read from same address (should hit cache, no mem access)
    cpu_read(16'h0010, data);
    @(negedge clk_i);

    cpu_read(16'h0020, data);
    @(negedge clk_i);

    // Read from different address (should cause cache miss, memory read)
    cpu_read(16'h0030, data);
    @(negedge clk_i);

    $display("[%0t] Test complete, finishing simulation", $time);
    #(CLK_PERIOD*10);
    $finish;
  end

  // Exit from stuck
  initial begin
    #1_000; // wait 100,000 cycles
    if (!cpu_resp_valid_o) begin
      $display("WARNING: CPU response never received, cache might be stuck.");
      $finish;
    end
  end

endmodule

