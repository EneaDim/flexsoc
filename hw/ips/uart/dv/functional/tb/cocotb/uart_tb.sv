      `timescale 1ns/1ps
      module uart_tb;
        logic clk_i;
        logic rst_ni;
        logic cio_rx_i;
logic cio_tx_o;
logic cio_tx_en_o;
        logic         tl_i_a_valid;
        logic [2:0]   tl_i_a_opcode;
        logic [2:0]   tl_i_a_param;
        logic [1:0]   tl_i_a_size;
        logic [7:0]   tl_i_a_source;
        logic [31:0]  tl_i_a_address;
        logic [3:0]   tl_i_a_mask;
        logic [31:0]  tl_i_a_data;
        logic         tl_i_d_ready;
        logic         tl_o_d_valid;
        logic [2:0]   tl_o_d_opcode;
        logic [31:0]  tl_o_d_data;
        logic         tl_o_d_error;
        logic         tl_o_a_ready;
        logic [108:0] tl_i;
        logic [65:0]  tl_o;

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

        initial begin
          cio_rx_i = '1;
        end

        assign tl_i = flexsoc_tlul_h2d(
          tl_i_a_valid, tl_i_a_opcode, tl_i_a_param, tl_i_a_size,
          tl_i_a_source, tl_i_a_address, tl_i_a_mask, tl_i_a_data, tl_i_d_ready
        );
        assign tl_o_d_valid  = tl_o[65];
        assign tl_o_d_opcode = tl_o[64:62];
        assign tl_o_d_data   = tl_o[47:16];
        assign tl_o_d_error  = tl_o[1];
        assign tl_o_a_ready  = tl_o[0];

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
              $dumpvars(0, uart_tb);
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
                $display("[TB] sdf = %s scope=u_uart mode=MINIMUM", sdf_path);
                $sdf_annotate(sdf_path, u_uart);
              `elsif FLEXSOC_SDF_TYP
                $display("[TB] sdf = %s scope=u_uart mode=TYPICAL", sdf_path);
                $sdf_annotate(sdf_path, u_uart);
              `else
                $display("[TB] sdf = %s scope=u_uart mode=MAXIMUM", sdf_path);
                $sdf_annotate(sdf_path, u_uart);
              `endif
            end
          end
        `endif
        uart u_uart (
          .clk_i(clk_i),
          .rst_ni(rst_ni),
          .*
        );
      endmodule
