`ifdef VERILATOR
// Auto-generated vector driver for rv_timer.
// data_in.vec supports signal drives, @write, @cfg, and @reset.

int tb_vector_apply_count;

// Same IO phase contract used by TL-UL, functional simulation and GLS.
localparam realtime FLEXSOC_VEC_DRIVE_NS  = 2;
localparam realtime FLEXSOC_VEC_SAMPLE_NS = 8;
event flexsoc_vec_drive_phase;
event flexsoc_vec_sample_phase;

initial forever begin
  @(posedge clk_i);
  fork
    begin #(FLEXSOC_VEC_DRIVE_NS)  -> flexsoc_vec_drive_phase;  end
    begin #(FLEXSOC_VEC_SAMPLE_NS) -> flexsoc_vec_sample_phase; end
  join_none
end

task automatic tb_wait_drive_phase();
  @flexsoc_vec_drive_phase;
endtask

task automatic tb_wait_sample_phase();
  @flexsoc_vec_sample_phase;
endtask

task automatic tb_drive_input(input string name, input logic [31:0] value);
  if (1'b0) begin
    tb_vector_apply_count = tb_vector_apply_count;
  end
  else if (name == "gpio_intr_i") begin
    gpio_intr_i = value;
    tb_vector_apply_count++;
    $display("[TB][DRV] gpio_intr_i <= 0x%08h", value);
  end
  else begin
    error_count++;
    $display("[TB][ERROR] unknown input vector signal: %s", name);
  end
endtask

task automatic tb_drive_raw(input string name, input string raw);
  logic [31:0] value;
  logic [32:0] parsed;

  begin : tb_drive_raw_body
    if (name == "") disable tb_drive_raw_body;
    parsed = tb_parse_u32(raw);
    if (!parsed[32]) disable tb_drive_raw_body;
    value = parsed[31:0];
    tb_drive_input(name, value);
  end
endtask

task automatic tb_apply_reg_write(input string reg_key, input string data_raw, input string mask_raw);
  logic [31:0] data;
  logic [31:0] mask;
  logic [32:0] parsed;
  bit ok;

  begin : tb_apply_reg_write_body
    parsed = tb_parse_u32(data_raw);
    if (!parsed[32]) disable tb_apply_reg_write_body;
    data = parsed[31:0];

    parsed = tb_parse_u32(mask_raw);
    if (mask_raw.len() > 0 && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    tb_reg_write_key(reg_key, data, mask, ok);
    if (ok) tb_vector_apply_count++;
  end
endtask

task automatic tb_step(input string data_out_path, inout int now_cycle);
  tb_wait_sample_phase();
  now_cycle++;
  tb_check_outputs(data_out_path, now_cycle);
endtask

task automatic tb_apply_reset(
  input string selector,
  input int cycles,
  input string data_out_path,
  inout int now_cycle
);
  int i;
  bit selected;
  gpio_intr_i = '0;
  selected = (selector == "" || selector == "all" || selector == "*" ||
              selector == "core" || selector == "rst_ni");
  if (!selected) begin
    error_count++;
    $display("[TB][ERROR] unknown reset selector: %s", selector);
  end else begin
    rst_ni = 1'b0;
    for (i = 0; i < cycles; i++) tb_step(data_out_path, now_cycle);
    @(negedge clk_i); #1;
    rst_ni = 1'b1;
    tb_vector_apply_count++;
  end
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
  tb_wait_drive_phase();
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
  int guarded_total;
  int guarded_deadline;
  bit cycle_open;
  logic [31:0] cycle_value;
  logic [31:0] reset_cycles;
  logic [32:0] parsed;
  string cycle_raw;
  string reset_selector;
  string line;
  reg [8*4096-1:0] line_buf;
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
  tb_guarded_output_next = 0;
  tb_last_output_cycle(data_out_path, final_cycle);
  tb_guarded_output_count(data_out_path, guarded_total);

  begin : run_vectors_body
  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    disable run_vectors_body;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);

  while (!$feof(fd)) begin : tb_input_line
    line = "";
    line_buf = '0;
    void'($fgets(line_buf, fd));
    line = $sformatf("%0s", line_buf);
    tb_tokenize9(line, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) disable tb_input_line;
    if (cycle_raw.len() > 0 && cycle_raw.substr(0, 0) == "#") disable tb_input_line;
    if (t0.len() > 0 && t0.substr(0, 0) == "#") disable tb_input_line;
    parsed = tb_parse_u32(cycle_raw);
    if (!parsed[32]) disable tb_input_line;
    cycle_value = parsed[31:0];

    cycle = int'(cycle_value);

    if (t0 == "@cfg" || t0 == "cfg" || t0 == "@config" || t0 == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, t1);
      run_reg_config(t1);
      tb_vector_apply_count++;
      disable tb_input_line;
    end

    if (t0 == "@reset" || t0 == "reset") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      if (code >= 4) begin
        parsed = tb_parse_u32(t2);
      end else begin
        parsed = tb_parse_u32(t1);
      end
      reset_cycles = parsed[32] ? parsed[31:0] : 32'd2;
      if (reset_cycles == 0) reset_cycles = 2;
      reset_selector = code >= 4 ? t1 : "all";
      $display(
        "[TB][RESET] cycle=%0d selector=%s cycles=%0d",
        cycle, reset_selector, reset_cycles
      );
      tb_apply_reset(reset_selector, int'(reset_cycles), data_out_path, now_cycle);
      disable tb_input_line;
    end

    if (t0 == "@write" || t0 == "write" || t0 == "@reg_write" || t0 == "reg_write") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @write row: %s", line);
        disable tb_input_line;
      end

      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][VEC-WR] cycle=%0d reg=%s", cycle, t1);
      tb_apply_reg_write(t1, t2, t3);
      disable tb_input_line;
    end

    if ((code - 1) % 2 != 0) begin
      error_count++;
      $display("[TB][ERROR] malformed signal vector row: %s", line);
      disable tb_input_line;
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
  guarded_deadline = now_cycle + 4096;

  while ((now_cycle < final_cycle || tb_guarded_output_next < guarded_total) &&
         now_cycle < guarded_deadline) begin
    tb_step(data_out_path, now_cycle);
  end
  if (tb_guarded_output_next < guarded_total) begin
    error_count++;
    $display("[TB][ERROR] timed out waiting for guarded output row %0d/%0d",
             tb_guarded_output_next + 1, guarded_total);
  end

  if (tb_vector_apply_count == apply_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs or register writes were applied from %s", data_in_path);
  end
  end
endtask
`else
// Auto-generated vector driver for rv_timer.
// data_in.vec supports signal drives, @write, @cfg, and @reset.

int tb_vector_apply_count;

// Same IO phase contract used by TL-UL, functional simulation and GLS.
localparam realtime FLEXSOC_VEC_DRIVE_NS  = 2;
localparam realtime FLEXSOC_VEC_SAMPLE_NS = 8;
event flexsoc_vec_drive_phase;
event flexsoc_vec_sample_phase;

initial forever begin
  @(posedge clk_i);
  fork
    begin #(FLEXSOC_VEC_DRIVE_NS)  -> flexsoc_vec_drive_phase;  end
    begin #(FLEXSOC_VEC_SAMPLE_NS) -> flexsoc_vec_sample_phase; end
  join_none
end

task automatic tb_wait_drive_phase();
  @flexsoc_vec_drive_phase;
endtask

task automatic tb_wait_sample_phase();
  @flexsoc_vec_sample_phase;
endtask

task automatic tb_drive_input(input tb_token_t name, input logic [31:0] value);
  if (1'b0) begin
    tb_vector_apply_count = tb_vector_apply_count;
  end
  else if (name == "gpio_intr_i") begin
    gpio_intr_i = value;
    tb_vector_apply_count++;
    $display("[TB][DRV] gpio_intr_i <= 0x%08h", value);
  end
  else begin
    error_count++;
    $display("[TB][ERROR] unknown input vector signal: %s", name);
  end
endtask

task automatic tb_drive_raw(input tb_token_t name, input tb_token_t raw);
  logic [31:0] value;
  logic [32:0] parsed;

  begin : tb_drive_raw_body
    if (tb_token_empty(name)) disable tb_drive_raw_body;
    parsed = tb_parse_u32(raw);
    if (!parsed[32]) disable tb_drive_raw_body;
    value = parsed[31:0];
    tb_drive_input(name, value);
  end
endtask

task automatic tb_apply_reg_write(input tb_token_t reg_key, input tb_token_t data_raw, input tb_token_t mask_raw);
  logic [31:0] data;
  logic [31:0] mask;
  logic [32:0] parsed;
  bit ok;

  begin : tb_apply_reg_write_body
    parsed = tb_parse_u32(data_raw);
    if (!parsed[32]) disable tb_apply_reg_write_body;
    data = parsed[31:0];

    parsed = tb_parse_u32(mask_raw);
    if (!tb_token_empty(mask_raw) && parsed[32]) begin
      mask = parsed[31:0];
    end else begin
      mask = 32'hffff_ffff;
    end

    tb_reg_write_key(reg_key, data, mask, ok);
    if (ok) tb_vector_apply_count++;
  end
endtask

task automatic tb_step(input string data_out_path, inout int now_cycle);
  tb_wait_sample_phase();
  now_cycle++;
  tb_check_outputs(data_out_path, now_cycle);
endtask

task automatic tb_apply_reset(
  input tb_token_t selector,
  input int cycles,
  input string data_out_path,
  inout int now_cycle
);
  int i;
  bit selected;
  gpio_intr_i = '0;
  selected = (selector == "" || selector == "all" || selector == "*" ||
              selector == "core" || selector == "rst_ni");
  if (!selected) begin
    error_count++;
    $display("[TB][ERROR] unknown reset selector: %s", selector);
  end else begin
    rst_ni = 1'b0;
    for (i = 0; i < cycles; i++) tb_step(data_out_path, now_cycle);
    @(negedge clk_i); #1;
    rst_ni = 1'b1;
    tb_vector_apply_count++;
  end
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
  tb_wait_drive_phase();
endtask

task automatic tb_drive_signal_pairs(
  input int code,
  input tb_token_t t0,
  input tb_token_t t1,
  input tb_token_t t2,
  input tb_token_t t3,
  input tb_token_t t4,
  input tb_token_t t5,
  input tb_token_t t6,
  input tb_token_t t7
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
  int guarded_total;
  int guarded_deadline;
  bit cycle_open;
  logic [31:0] cycle_value;
  logic [31:0] reset_cycles;
  logic [32:0] parsed;
  tb_token_t cycle_raw;
  tb_token_t reset_selector;
  tb_line_t line_buf;
  tb_token_t t0;
  tb_token_t t1;
  tb_token_t t2;
  tb_token_t t3;
  tb_token_t t4;
  tb_token_t t5;
  tb_token_t t6;
  tb_token_t t7;

  now_cycle = -1;
  current_cycle = -1;
  cycle_open = 1'b0;
  apply_start = tb_vector_apply_count;
  tb_guarded_output_next = 0;
  tb_last_output_cycle(data_out_path, final_cycle);
  tb_guarded_output_count(data_out_path, guarded_total);

  begin : run_vectors_body
  fd = $fopen(data_in_path, "r");
  if (fd == 0) begin
    $display("[TB][ERROR] input vector file not found: %s", data_in_path);
    error_count++;
    disable run_vectors_body;
  end

  $display("[TB] running vectors: in=%s out=%s", data_in_path, data_out_path);

  while (!$feof(fd)) begin : tb_input_line
    line_buf = '0;
    code = $fgets(line_buf, fd);
    tb_tokenize9(line_buf, code, cycle_raw, t0, t1, t2, t3, t4, t5, t6, t7);

    if (code < 3) disable tb_input_line;
    if (tb_token_comment(cycle_raw)) disable tb_input_line;
    if (tb_token_comment(t0)) disable tb_input_line;
    parsed = tb_parse_u32(cycle_raw);
    if (!parsed[32]) disable tb_input_line;
    cycle_value = parsed[31:0];

    cycle = int'(cycle_value);

    if (t0 == "@cfg" || t0 == "cfg" || t0 == "@config" || t0 == "config") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][CFG] cycle=%0d path=%s", cycle, t1);
      run_reg_config(t1);
      tb_vector_apply_count++;
      disable tb_input_line;
    end

    if (t0 == "@reset" || t0 == "reset") begin
      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      if (code >= 4) begin
        parsed = tb_parse_u32(t2);
      end else begin
        parsed = tb_parse_u32(t1);
      end
      reset_cycles = parsed[32] ? parsed[31:0] : 32'd2;
      if (reset_cycles == 0) reset_cycles = 2;
      reset_selector = code >= 4 ? t1 : "all";
      $display(
        "[TB][RESET] cycle=%0d selector=%s cycles=%0d",
        cycle, reset_selector, reset_cycles
      );
      tb_apply_reset(reset_selector, int'(reset_cycles), data_out_path, now_cycle);
      disable tb_input_line;
    end

    if (t0 == "@write" || t0 == "write" || t0 == "@reg_write" || t0 == "reg_write") begin
      if (code < 4) begin
        error_count++;
        $display("[TB][ERROR] malformed @write row: %0s", line_buf);
        disable tb_input_line;
      end

      tb_finish_cycle(data_out_path, now_cycle, cycle_open);
      tb_wait_before_drive(cycle, data_out_path, now_cycle);
      current_cycle = -1;
      $display("[TB][VEC-WR] cycle=%0d reg=%s", cycle, t1);
      tb_apply_reg_write(t1, t2, t3);
      disable tb_input_line;
    end

    if ((code - 1) % 2 != 0) begin
      error_count++;
      $display("[TB][ERROR] malformed signal vector row: %0s", line_buf);
      disable tb_input_line;
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
  guarded_deadline = now_cycle + 4096;

  while ((now_cycle < final_cycle || tb_guarded_output_next < guarded_total) &&
         now_cycle < guarded_deadline) begin
    tb_step(data_out_path, now_cycle);
  end
  if (tb_guarded_output_next < guarded_total) begin
    error_count++;
    $display("[TB][ERROR] timed out waiting for guarded output row %0d/%0d",
             tb_guarded_output_next + 1, guarded_total);
  end

  if (tb_vector_apply_count == apply_start) begin
    error_count++;
    $display("[TB][ERROR] no vector inputs or register writes were applied from %s", data_in_path);
  end
  end
endtask
`endif
