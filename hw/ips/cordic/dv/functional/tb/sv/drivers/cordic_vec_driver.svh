// Auto-generated vector driver for cordic.
// data_in.vec supports signal drives, @write register operations, and @cfg.

int tb_vector_apply_count;

task automatic tb_drive_input(input string name, input logic [31:0] value);
  if (1'b0) begin
    tb_vector_apply_count = tb_vector_apply_count;
  end
  else begin
    error_count++;
    $display("[TB][ERROR] unknown input vector signal: %s", name);
  end
endtask

task automatic tb_drive_raw(input string name, input string raw);
  logic [31:0] value;

  if (name == "") return;
  if (!tb_parse_u32(raw, value)) return;

  tb_drive_input(name, value);
endtask

task automatic tb_apply_reg_write(input string reg_key, input string data_raw, input string mask_raw);
  logic [31:0] data;
  logic [31:0] mask;
  bit ok;

  if (!tb_parse_u32(data_raw, data)) return;

  if (mask_raw.len() > 0 && tb_parse_u32(mask_raw, mask)) begin
    // parsed explicit mask
  end else begin
    mask = 32'hffff_ffff;
  end

  tb_reg_write_key(reg_key, data, mask, ok);
  if (ok) tb_vector_apply_count++;
endtask

task automatic tb_step(input string data_out_path, inout int now_cycle);
  @(posedge clk_i); #1;
  now_cycle++;
  tb_check_outputs(data_out_path, now_cycle);
endtask

task automatic tb_finish_cycle(input string data_out_path, inout int now_cycle, inout bit cycle_open);
  if (cycle_open) begin
    tb_step(data_out_path, now_cycle);
    cycle_open = 1'b0;
  end
endtask

task automatic tb_wait_before_drive(input int target_cycle, input string data_out_path, inout int now_cycle);
  while (now_cycle < target_cycle - 1) begin
    tb_step(data_out_path, now_cycle);
  end
  @(negedge clk_i); #1;
endtask

task automatic tb_drive_signal_pairs(
  input int code,
  input string t0,
  input string t1,
  input string t2,
  input string t3,
  input string t4,
  input string t5,
  input string t6,
  input string t7
);
  tb_drive_raw(t0, t1);
  if (code >= 5) tb_drive_raw(t2, t3);
  if (code >= 7) tb_drive_raw(t4, t5);
  if (code >= 9) tb_drive_raw(t6, t7);
endtask

task automatic run_vectors(input string data_in_path, input string data_out_path);
  int fd;
  int code;
  int cycle;
  int final_cycle;
  int now_cycle;
  int current_cycle;
  int apply_start;
  bit cycle_open;
  logic [31:0] cycle_value;
  string cycle_raw;
  string line;
  string t0;
  string t1;
  string t2;
  string t3;
  string t4;
  string t5;
  string t6;
  string t7;

  now_cycle = -1;
  current_cycle = -1;
  cycle_open = 1'b0;
  apply_start = tb_vector_apply_count;
  final_cycle = tb_last_output_cycle(data_out_path);

  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    return;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);

  while (!$feof(fd)) begin
    line = "";
    void'($fgets(line, fd));
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) continue;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") continue;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") continue;
    if (!tb_parse_u32(cycle_raw, cycle_value)) continue;

    cycle = int'(cycle_value);

    if (t0 == "@cfg" || t0 == "cfg" || t0 == "@config" || t0 == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, t1);
      run_reg_config(t1);
      tb_vector_apply_count++;
      continue;
    end

    if (t0 == "@write" || t0 == "write" || t0 == "@reg_write" || t0 == "reg_write") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @write row: %s", line);
        continue;
      end

      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][VEC-WR] cycle=%0d reg=%s", cycle, t1);
      tb_apply_reg_write(t1, t2, t3);
      continue;
    end

    if ((code - 1) % 2 != 0) begin
      error_count++;
      $display("[TB][ERROR] malformed signal vector row: %s", line);
      continue;
    end

    if (!cycle_open || cycle != current_cycle) begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = cycle;
      cycle_open = 1'b1;
      $display("[TB][VEC] cycle=%0d", cycle);
    end

    tb_drive_signal_pairs(code, t0, t1, t2, t3, t4, t5, t6, t7);
  end

  $fclose(fd);

  tb_finish_cycle(data_out_path, now_cycle, cycle_open);

  if (final_cycle < now_cycle + 8) begin
    final_cycle = now_cycle + 8;
  end

  while (now_cycle < final_cycle) begin
    tb_step(data_out_path, now_cycle);
  end

  if (tb_vector_apply_count == apply_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs or register writes were applied from %s", data_in_path);
  end
endtask
