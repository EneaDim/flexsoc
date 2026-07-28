// Reset top-level scalar IO and both TL-UL register ports.
task automatic apply_defaults();
  cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  cfg_tl_i.a_valid = 1'b0;
  dsp_tl_i.a_valid = 1'b0;
  cfg_tl_i.d_ready = 1'b1;
  dsp_tl_i.d_ready = 1'b1;
  rx_valid_i = 1'b0;
  rx_sample_i = '0;
  rx_coeff_i = '0;
  dsp_ready_i = 1'b1;
  test_en_i = 1'b1;
  devmode_i = 1'b1;
endtask

// Perform one cfg-domain TL-UL write into the generated cfg regblock.
task automatic cfg_write(input logic [31:0] addr, input logic [31:0] data);
  @(negedge cfg_clk_i);
  cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  cfg_tl_i.a_valid   = 1'b1;
  cfg_tl_i.a_opcode  = tlul_pkg::PutFullData;
  cfg_tl_i.a_param   = '0;
  cfg_tl_i.a_size    = 3'd2;
  cfg_tl_i.a_source  = '0;
  cfg_tl_i.a_address = addr;
  cfg_tl_i.a_mask    = 4'hf;
  cfg_tl_i.a_data    = data;
  cfg_tl_i.d_ready   = 1'b1;
  do @(posedge cfg_clk_i); while (!cfg_tl_o.a_ready);
  @(negedge cfg_clk_i);
  cfg_tl_i.a_valid = 1'b0;
  do @(posedge cfg_clk_i); while (!cfg_tl_o.d_valid);
  @(negedge cfg_clk_i);
  cfg_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  cfg_tl_i.d_ready = 1'b1;
endtask

// Perform one dsp-domain TL-UL write into the generated dsp regblock.
task automatic dsp_write(input logic [31:0] addr, input logic [31:0] data);
  @(negedge dsp_clk_i);
  dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  dsp_tl_i.a_valid   = 1'b1;
  dsp_tl_i.a_opcode  = tlul_pkg::PutFullData;
  dsp_tl_i.a_param   = '0;
  dsp_tl_i.a_size    = 3'd2;
  dsp_tl_i.a_source  = '0;
  dsp_tl_i.a_address = addr;
  dsp_tl_i.a_mask    = 4'hf;
  dsp_tl_i.a_data    = data;
  dsp_tl_i.d_ready   = 1'b1;
  do @(posedge dsp_clk_i); while (!dsp_tl_o.a_ready);
  @(negedge dsp_clk_i);
  dsp_tl_i.a_valid = 1'b0;
  do @(posedge dsp_clk_i); while (!dsp_tl_o.d_valid);
  @(negedge dsp_clk_i);
  dsp_tl_i = tlul_pkg::TL_H2D_DEFAULT;
  dsp_tl_i.d_ready = 1'b1;
endtask

// Apply one generated config register write through the top-level regblocks.
task automatic apply_reg(input string reg_name, input logic [31:0] value);
  if (reg_name == "cfg.CTRL") begin
    cfg_write(32'h0000_0000, value);
  end else if (reg_name == "cfg.GAIN") begin
    cfg_write(32'h0000_0004, value);
  end else if (reg_name == "dsp.DSP_CTRL") begin
    dsp_write(32'h0000_0000, value);
  end else if (reg_name == "dsp.THRESHOLD") begin
    dsp_write(32'h0000_0004, value);
  end else begin
    $display("[TB][WARN] unknown config register: %s", reg_name);
  end
endtask

// Load config.regs. cfg.CTRL should remain the final enable write.
task automatic load_config(input string path);
  integer fd;
  integer code;
  string reg_name;
  logic [31:0] value;
  string line;
  fd = $fopen(path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] config file not found: %s", path);
    errors++;
    return;
  end
  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    if (line.len() == 0 || line.substr(0, 0) == "#") continue;
    code = $sscanf(line, "%s %h", reg_name, value);
    if (code == 2) begin
      if (reg_name.len() > 6 && reg_name.substr(0, 5) == "clk_i.") reg_name = reg_name.substr(6, reg_name.len() - 1);
      apply_reg(reg_name, value);
    end
  end
  $fclose(fd);
endtask
