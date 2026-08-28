`timescale 1ns/1ps

interface tlul_if (
  input logic clk_i,
  input logic rst_ni
);

  logic [108:0] h2d /* simulator public*/;
  logic [65:0]  d2h /* simulator public*/;

  localparam logic [2:0] FLEXSOC_TL_PUT_FULL    = 3'h0;
  localparam logic [2:0] FLEXSOC_TL_PUT_PARTIAL = 3'h1;
  localparam logic [2:0] FLEXSOC_TL_GET         = 3'h4;

  function automatic logic [6:0] flexsoc_tlul_data_intg(input logic [31:0] data_i);
    logic [38:0] data_o;
    begin
      data_o = {7'b0, data_i};
      data_o[32] = ^(data_o & 39'h002606BD25);
      data_o[33] = ^(data_o & 39'h00DEBA8050);
      data_o[34] = ^(data_o & 39'h00413D89AA);
      data_o[35] = ^(data_o & 39'h0031234ED1);
      data_o[36] = ^(data_o & 39'h00C2C1323B);
      data_o[37] = ^(data_o & 39'h002DCC624C);
      data_o[38] = ^(data_o & 39'h0098505586);
      data_o = data_o ^ 39'h2A00000000;
      flexsoc_tlul_data_intg = data_o[38:32];
    end
  endfunction

  function automatic logic [6:0] flexsoc_tlul_cmd_intg(
    input logic [2:0] opcode,
    input logic [31:0] address,
    input logic [3:0] mask
  );
    logic [56:0] payload;
    logic [63:0] data_o;
    begin
      payload = {14'b0, 4'h9, address, opcode, mask};
      data_o = {7'b0, payload};
      data_o[57] = ^(data_o & 64'h0103FFF800007FFF);
      data_o[58] = ^(data_o & 64'h017C1FF801FF801F);
      data_o[59] = ^(data_o & 64'h01BDE1F87E0781E1);
      data_o[60] = ^(data_o & 64'h01DEEE3B8E388E22);
      data_o[61] = ^(data_o & 64'h01EF76CDB2C93244);
      data_o[62] = ^(data_o & 64'h01F7BB56D5525488);
      data_o[63] = ^(data_o & 64'h01FBDDA769A46910);
      data_o = data_o ^ 64'h5400000000000000;
      flexsoc_tlul_cmd_intg = data_o[63:57];
    end
  endfunction

  function automatic logic [108:0] flexsoc_tlul_h2d(
    input logic valid,
    input logic [2:0] opcode,
    input logic [2:0] param,
    input logic [1:0] size,
    input logic [7:0] source,
    input logic [31:0] address,
    input logic [3:0] mask,
    input logic [31:0] data,
    input logic ready
  );
    logic [108:0] value;
    begin
      value = '0;
      value[108]     = valid;
      value[107:105] = opcode;
      value[104:102] = param;
      value[101:100] = size;
      value[99:92]   = source;
      value[91:60]   = address;
      value[59:56]   = mask;
      value[55:24]   = data;
      value[23:19]   = 5'b0;
      value[18:15]   = 4'h9;
      value[14:8]    = flexsoc_tlul_cmd_intg(opcode, address, mask);
      value[7:1]     = flexsoc_tlul_data_intg(data);
      value[0]       = ready;
      flexsoc_tlul_h2d = value;
    end
  endfunction

  modport drv (output h2d, input d2h);
  modport dut (input h2d, output d2h);

  // Shared timing intent: drive at input-delay phase, sample at output-deadline phase.
  localparam realtime FLEXSOC_TB_DRIVE_NS  = 2;
  localparam realtime FLEXSOC_TB_SAMPLE_NS = 8;
  event flexsoc_tb_drive_phase;
  event flexsoc_tb_sample_phase;

  initial forever begin
    @(posedge clk_i);
    fork
      begin #(FLEXSOC_TB_DRIVE_NS)  -> flexsoc_tb_drive_phase;  end
      begin #(FLEXSOC_TB_SAMPLE_NS) -> flexsoc_tb_sample_phase; end
    join_none
  end

  task automatic sample_cycle();
    @flexsoc_tb_sample_phase;
  endtask

  task automatic drive_cycle();
    @flexsoc_tb_drive_phase;
  endtask

  task automatic drive_idle();
    h2d <= flexsoc_tlul_h2d(1'b0, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'b0,
                            32'b0, 4'b0, 32'b0, 1'b1);
  endtask

  task automatic init();
    drive_idle();
    sample_cycle();
  endtask

  task automatic wait_d2h_high(input integer bit_index, input string signal_name);
    integer guard;
    guard = 0;
    sample_cycle();
    while (d2h[bit_index] !== 1'b1) begin
      if (d2h[bit_index] !== 1'b0)
        $fatal(1, "[%0t] TLUL %s is X/Z; check reset and gate-level cell model mode",
               $time, signal_name);
      guard++;
      if (guard > 1000)
        $fatal(1, "[%0t] TLUL timeout waiting for %s", $time, signal_name);
      sample_cycle();
    end
  endtask

  task automatic tlul_write(
    input logic [31:0] addr,
    input logic [31:0] data,
    input logic [7:0] source,
    input logic [3:0] mask = 4'hf
  );
    logic [2:0] opcode;
    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    opcode = (mask == 4'hf) ? FLEXSOC_TL_PUT_FULL : FLEXSOC_TL_PUT_PARTIAL;
    drive_cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, opcode, 3'b0, 2'd2, source,
                            addr, mask, data, 1'b1);
    wait_d2h_high(0, "write a_ready");
    drive_cycle();
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "write d_valid");
    if (d2h[1])
      $fatal(1, "[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    drive_cycle();
    drive_idle();
    sample_cycle();
    #1;
  endtask

  task automatic tlul_read(
    input logic [31:0] addr,
    output logic [31:0] data,
    input logic [7:0] source
  );
    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;
    drive_cycle();
    h2d <= flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, source,
                            addr, 4'hf, 32'b0, 1'b1);
    wait_d2h_high(0, "read a_ready");
    drive_cycle();
    h2d[108] <= 1'b0;
    wait_d2h_high(65, "read d_valid");
    data = d2h[47:16];
    if (d2h[1])
      $fatal(1, "[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    drive_cycle();
    drive_idle();
    sample_cycle();
    #1;
  endtask

endinterface
