`ifdef VERILATOR
event flexsoc_core_drive_phase;
event flexsoc_core_sample_phase;
initial forever begin
  @(posedge clk_i);
  fork
    begin #(2) -> flexsoc_core_drive_phase; end
    begin #(8) -> flexsoc_core_sample_phase; end
  join_none
end
task automatic core_drive_cycle();
  @flexsoc_core_drive_phase;
endtask
task automatic core_sample_cycle();
  @flexsoc_core_sample_phase;
endtask

// One CSR transport contract; each window follows its owning clock domain.
task automatic apply_defaults();
  tl_i = '0;
  rx_i = '1;
endtask

      task automatic reset_dut(input string selector, input integer cycles);
        bit matched;
        matched = 1'b0;
        if (selector == "" || selector == "all" || selector == "*") begin
        rst_ni = 1'b0;
          fork
          begin repeat (cycles) @(posedge clk_i); @(negedge clk_i); end
          join
        rst_ni = 1'b1;
          matched = 1'b1;
        end
else if (selector == "core" || selector == "rst_ni") begin
  rst_ni = 1'b0;
  repeat (cycles) @(posedge clk_i);
  @(negedge clk_i);
  rst_ni = 1'b1;
  matched = 1'b1;
end
        if (!matched) begin
          $display("[TB][ERROR] unknown reset selector: %s", selector);
          errors++;
        end
        apply_defaults();
        repeat (8) @(posedge clk_i);
      endtask

task automatic core_write(input logic [31:0] addr, input logic [31:0] data);
  logic [2:0] opcode;
  opcode = FLEXSOC_TL_PUT_FULL;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b1, opcode, 3'b0, 2'd2, 8'h00, addr, 4'hf, data, 1'b1);
  do core_sample_cycle(); while (!tl_o[0]);
  core_drive_cycle();
  tl_i[108] = 1'b0;
  do core_sample_cycle(); while (!tl_o[65]);
  if (tl_o[1]) errors++;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b0, 3'b0, 3'b0, 2'd0, 8'h00, 32'b0, 4'b0, 32'b0, 1'b1);
endtask

task automatic core_read(input logic [31:0] addr, output logic [31:0] data);
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'h00, addr, 4'hf, 32'b0, 1'b1);
  do core_sample_cycle(); while (!tl_o[0]);
  core_drive_cycle();
  tl_i[108] = 1'b0;
  do core_sample_cycle(); while (!tl_o[65]);
  data = tl_o[47:16];
  if (tl_o[1]) errors++;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b0, 3'b0, 3'b0, 2'd0, 8'h00, 32'b0, 4'b0, 32'b0, 1'b1);
endtask


      task automatic apply_reg(input string reg_name, input logic [31:0] value);
        if (reg_name == "clk_i.CTRL" || reg_name == "core.CTRL" || reg_name == "CTRL") core_write(32'h00000000, value);
        else if (reg_name == "clk_i.WDATA" || reg_name == "core.WDATA" || reg_name == "WDATA") core_write(32'h0000000c, value);
        else if (reg_name == "clk_i.FIFO_CTRL" || reg_name == "core.FIFO_CTRL" || reg_name == "FIFO_CTRL") core_write(32'h00000010, value);
        else $display("[TB][WARN] unknown config register: %s", reg_name);
      endtask

      task automatic read_reg(input string reg_name, output logic [31:0] value);
        value = '0;
        if (reg_name == "clk_i.CTRL" || reg_name == "core.CTRL" || reg_name == "CTRL") core_read(32'h00000000, value);
        else if (reg_name == "clk_i.STATUS" || reg_name == "core.STATUS" || reg_name == "STATUS") core_read(32'h00000004, value);
        else if (reg_name == "clk_i.RDATA" || reg_name == "core.RDATA" || reg_name == "RDATA") core_read(32'h00000008, value);
        else if (reg_name == "clk_i.FIFO_STATUS" || reg_name == "core.FIFO_STATUS" || reg_name == "FIFO_STATUS") core_read(32'h00000014, value);
        else begin $display("[TB][WARN] unknown read register: %s", reg_name); errors++; end
      endtask

      task automatic apply_reg_masked(
        input string reg_name,
        input logic [31:0] value,
        input logic [31:0] mask
      );
        logic [31:0] current;
        logic [31:0] merged;
        merged = value;
        if (mask != 32'hffff_ffff) begin
          read_reg(reg_name, current);
          merged = (current & ~mask) | (value & mask);
        end
        apply_reg(reg_name, merged);
      endtask

      task automatic expect_reg(
        input string reg_name,
        input logic [31:0] expected,
        input logic [31:0] mask
      );
        logic [31:0] got;
        read_reg(reg_name, got);
        if ((got & mask) !== (expected & mask)) begin
          $display("[TB][ERROR] %s got=0x%08x exp=0x%08x mask=0x%08x", reg_name, got, expected, mask);
          errors++;
        end
      endtask

      task automatic load_config(input string path);
        integer fd;
        integer code;
        string reg_name;
        logic [31:0] value;
        logic [31:0] mask;
        string line;
        reg [8*4096-1:0] line_buf;
        begin : load_config_body
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] config file not found: %s", path);
          errors++;
          disable load_config_body;
        end
        while (!$feof(fd)) begin : tb_nclk_cfg_line
          line = "";
          line_buf = '0;
          void'($fgets(line_buf, fd));
          line = $sformatf("%0s", line_buf);
          if (line.len() == 0 || line.substr(0, 0) == "#") disable tb_nclk_cfg_line;
          code = $sscanf(line, "%s %h", reg_name, value);
          if (code == 2) begin
            mask = 32'hffff_ffff;
            if ($sscanf(line, "%s %h %h", reg_name, value, mask) != 3)
              mask = 32'hffff_ffff;
            apply_reg_masked(reg_name, value, mask);
          end
        end
        $fclose(fd);
        end
      endtask
`else

localparam integer FLEXSOC_TB_LINE_BYTES = 4096;
localparam integer FLEXSOC_TB_TOKEN_BYTES = 256;
typedef reg [8*FLEXSOC_TB_LINE_BYTES-1:0] tb_line_t;
typedef reg [8*FLEXSOC_TB_TOKEN_BYTES-1:0] tb_token_t;

function automatic bit tb_token_empty(input tb_token_t token);
  return token == '0;
endfunction

function automatic bit tb_token_comment(input tb_token_t token);
  tb_token_t ignored;
  integer matched;
  ignored = '0;
  matched = $sscanf(token, "#%s", ignored);
  return token == "#" || matched == 1;
endfunction

function automatic logic [32:0] tb_parse_u32(input tb_token_t raw);
  logic [31:0] value;
  integer ok;

  value = '0;
  ok = 0;
  if (!tb_token_empty(raw) && !tb_token_comment(raw)) begin
    ok = $sscanf(raw, "0x%h", value);
    if (ok != 1) ok = $sscanf(raw, "0X%h", value);
    if (ok != 1) ok = $sscanf(raw, "%d", value);
    if (ok != 1) ok = $sscanf(raw, "%h", value);
  end
  return {ok == 1, value};
endfunction

task automatic tb_tokenize9(
  input tb_line_t line,
  output integer count,
  output tb_token_t w0,
  output tb_token_t w1,
  output tb_token_t w2,
  output tb_token_t w3,
  output tb_token_t w4,
  output tb_token_t w5,
  output tb_token_t w6,
  output tb_token_t w7,
  output tb_token_t w8
);
  w0 = '0; w1 = '0; w2 = '0; w3 = '0; w4 = '0;
  w5 = '0; w6 = '0; w7 = '0; w8 = '0;
  count = $sscanf(line, "%s %s %s %s %s %s %s %s %s",
                  w0, w1, w2, w3, w4, w5, w6, w7, w8);
  if (count < 0) count = 0;
endtask

event flexsoc_core_drive_phase;
event flexsoc_core_sample_phase;
initial forever begin
  @(posedge clk_i);
  fork
    begin #(2) -> flexsoc_core_drive_phase; end
    begin #(8) -> flexsoc_core_sample_phase; end
  join_none
end
task automatic core_drive_cycle();
  @flexsoc_core_drive_phase;
endtask
task automatic core_sample_cycle();
  @flexsoc_core_sample_phase;
endtask

// One CSR transport contract; each window follows its owning clock domain.
task automatic apply_defaults();
  tl_i = '0;
  rx_i = '1;
endtask

      task automatic reset_dut(input string selector, input integer cycles);
        bit matched;
        matched = 1'b0;
        if (selector == "" || selector == "all" || selector == "*") begin
        rst_ni = 1'b0;
          fork
          begin repeat (cycles) @(posedge clk_i); @(negedge clk_i); end
          join
        rst_ni = 1'b1;
          matched = 1'b1;
        end
else if (selector == "core" || selector == "rst_ni") begin
  rst_ni = 1'b0;
  repeat (cycles) @(posedge clk_i);
  @(negedge clk_i);
  rst_ni = 1'b1;
  matched = 1'b1;
end
        if (!matched) begin
          $display("[TB][ERROR] unknown reset selector: %s", selector);
          errors++;
        end
        apply_defaults();
        repeat (8) @(posedge clk_i);
      endtask

task automatic core_write(input logic [31:0] addr, input logic [31:0] data);
  logic [2:0] opcode;
  opcode = FLEXSOC_TL_PUT_FULL;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b1, opcode, 3'b0, 2'd2, 8'h00, addr, 4'hf, data, 1'b1);
  do core_sample_cycle(); while (!tl_o[0]);
  core_drive_cycle();
  tl_i[108] = 1'b0;
  do core_sample_cycle(); while (!tl_o[65]);
  if (tl_o[1]) errors++;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b0, 3'b0, 3'b0, 2'd0, 8'h00, 32'b0, 4'b0, 32'b0, 1'b1);
endtask

task automatic core_read(input logic [31:0] addr, output logic [31:0] data);
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b1, FLEXSOC_TL_GET, 3'b0, 2'd2, 8'h00, addr, 4'hf, 32'b0, 1'b1);
  do core_sample_cycle(); while (!tl_o[0]);
  core_drive_cycle();
  tl_i[108] = 1'b0;
  do core_sample_cycle(); while (!tl_o[65]);
  data = tl_o[47:16];
  if (tl_o[1]) errors++;
  core_drive_cycle();
  tl_i = flexsoc_tlul_h2d(1'b0, 3'b0, 3'b0, 2'd0, 8'h00, 32'b0, 4'b0, 32'b0, 1'b1);
endtask


      task automatic apply_reg(input tb_token_t reg_name, input logic [31:0] value);
        if (reg_name == "clk_i.CTRL" || reg_name == "core.CTRL" || reg_name == "CTRL") core_write(32'h00000000, value);
        else if (reg_name == "clk_i.WDATA" || reg_name == "core.WDATA" || reg_name == "WDATA") core_write(32'h0000000c, value);
        else if (reg_name == "clk_i.FIFO_CTRL" || reg_name == "core.FIFO_CTRL" || reg_name == "FIFO_CTRL") core_write(32'h00000010, value);
        else $display("[TB][WARN] unknown config register: %s", reg_name);
      endtask

      task automatic read_reg(input tb_token_t reg_name, output logic [31:0] value);
        value = '0;
        if (reg_name == "clk_i.CTRL" || reg_name == "core.CTRL" || reg_name == "CTRL") core_read(32'h00000000, value);
        else if (reg_name == "clk_i.STATUS" || reg_name == "core.STATUS" || reg_name == "STATUS") core_read(32'h00000004, value);
        else if (reg_name == "clk_i.RDATA" || reg_name == "core.RDATA" || reg_name == "RDATA") core_read(32'h00000008, value);
        else if (reg_name == "clk_i.FIFO_STATUS" || reg_name == "core.FIFO_STATUS" || reg_name == "FIFO_STATUS") core_read(32'h00000014, value);
        else begin $display("[TB][WARN] unknown read register: %s", reg_name); errors++; end
      endtask

      task automatic apply_reg_masked(
        input tb_token_t reg_name,
        input logic [31:0] value,
        input logic [31:0] mask
      );
        logic [31:0] current;
        logic [31:0] merged;
        merged = value;
        if (mask != 32'hffff_ffff) begin
          read_reg(reg_name, current);
          merged = (current & ~mask) | (value & mask);
        end
        apply_reg(reg_name, merged);
      endtask

      task automatic expect_reg(
        input tb_token_t reg_name,
        input logic [31:0] expected,
        input logic [31:0] mask
      );
        logic [31:0] got;
        read_reg(reg_name, got);
        if ((got & mask) !== (expected & mask)) begin
          $display("[TB][ERROR] %s got=0x%08x exp=0x%08x mask=0x%08x", reg_name, got, expected, mask);
          errors++;
        end
      endtask

      task automatic load_config(input string path);
        integer fd;
        integer code;
        tb_token_t reg_name;
        logic [31:0] value;
        logic [31:0] mask;
              tb_line_t line_buf;
        begin : load_config_body
        fd = $fopen(path, "r");
        if (fd == 0) begin
          $display("[TB][ERROR] config file not found: %s", path);
          errors++;
          disable load_config_body;
        end
        while (!$feof(fd)) begin : tb_nclk_cfg_line
                line_buf = '0;
          code = $fgets(line_buf, fd);
          code = $sscanf(line_buf, "%s %h", reg_name, value);
          if (code == 2) begin
            mask = 32'hffff_ffff;
            if ($sscanf(line_buf, "%s %h %h", reg_name, value, mask) != 3)
              mask = 32'hffff_ffff;
            apply_reg_masked(reg_name, value, mask);
          end
        end
        $fclose(fd);
        end
      endtask
`endif
