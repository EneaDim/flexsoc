// -----------------------------------------------------------------------------
// CORDIC iterative core
// -----------------------------------------------------------------------------
// This block implements an iterative circular CORDIC engine controlled through
// CSR registers.
//
// Main features:
// - Rotation mode   (MODE = 0)
// - Vectoring mode  (MODE = 1)
// - Full-range support through quadrant mapping / pre-rotation
// - Internal guard bits on x/y datapath
// - Saturating x/y outputs to the software-visible width
// - Sticky VALID / ERROR flags for software polling
// - START edge detection through a primitive
//
// Register interface policy:
// - Inputs are taken from reg2hw.* CSR fields
// - Outputs and status are driven through hw2reg.*
// - STATUS / X_OUT / Y_OUT / Z_OUT / CFG are hwext-backed
// -----------------------------------------------------------------------------
module cordic_core
  import cordic_reg_pkg::*;
  import cordic_lut_pkg::*;
(
  input  logic         clk_i,
  input  logic         rst_ni,
  input  cordic_reg2hw_t reg2hw,
  output cordic_hw2reg_t hw2reg
);

  // ---------------------------------------------------------------------------
  // Numerical configuration
  // ---------------------------------------------------------------------------
  localparam int DATA_W       = 16;
  localparam int DATA_FRAC_W  = 14;
  localparam int ANGLE_W      = 16;
  localparam int ANGLE_FRAC_W = 13;
  localparam int GUARD_W      = 3;
  localparam int INT_W        = DATA_W + GUARD_W;
  localparam int MAX_ITER     = 16;
  localparam int ITER_W       = $clog2(MAX_ITER + 1);

  localparam logic [7:0] DATA_W_U8      = 8'(DATA_W);
  localparam logic [7:0] DATA_FRAC_W_U8 = 8'(DATA_FRAC_W);
  localparam logic [7:0] MAX_ITER_U8    = 8'(MAX_ITER);

  //////////////
  // Signals  //
  //////////////
  logic ctrl_start;
  logic ctrl_mode;
  logic ctrl_soft_rst;
  logic [4:0] ctrl_rsvd;
  logic [7:0] ctrl_n_iter;
  logic [15:0] ctrl_rsvd2;
  logic status_busy;
  logic status_valid;
  logic status_error;
  logic [28:0] status_rsvd;
  logic [31:0] x_in_value;
  logic [31:0] y_in_value;
  logic [31:0] z_in_value;
  // CSR-visible aliases.  The actual registered state is kept at the native
  // CORDIC widths below so synthesis does not have to collapse replicated
  // sign-bit flops.
  logic [31:0] x_out_value;
  logic [31:0] y_out_value;
  logic [31:0] z_out_value;
  logic signed [DATA_W-1:0]  x_out_q;
  logic signed [DATA_W-1:0]  y_out_q;
  logic signed [ANGLE_W-1:0] z_out_q;
  logic [7:0] cfg_data_width;
  logic [7:0] cfg_frac_width;
  logic [7:0] cfg_max_iter;
  logic [7:0] cfg_rsvd;

  //////////////
  // CTRL2REG //
  //////////////
  assign ctrl_start    = reg2hw.ctrl.start.q;
  assign ctrl_mode     = reg2hw.ctrl.mode.q;
  assign ctrl_soft_rst = reg2hw.ctrl.soft_rst.q;
  assign ctrl_rsvd     = reg2hw.ctrl.rsvd.q;
  assign ctrl_n_iter   = reg2hw.ctrl.n_iter.q;
  assign ctrl_rsvd2    = reg2hw.ctrl.rsvd2.q;
  assign x_in_value    = reg2hw.x_in.q;
  assign y_in_value    = reg2hw.y_in.q;
  assign z_in_value    = reg2hw.z_in.q;

  assign x_out_value = {{(32-DATA_W){x_out_q[DATA_W-1]}}, x_out_q};
  assign y_out_value = {{(32-DATA_W){y_out_q[DATA_W-1]}}, y_out_q};
  assign z_out_value = {{(32-ANGLE_W){z_out_q[ANGLE_W-1]}}, z_out_q};

  //////////////
  // REG2CTRL //
  //////////////
  assign hw2reg.status.busy.d    = status_busy;
  assign hw2reg.status.valid.d   = status_valid;
  assign hw2reg.status.error.d   = status_error;
  assign hw2reg.status.rsvd.d    = status_rsvd;
  assign hw2reg.x_out.d          = x_out_value;
  assign hw2reg.y_out.d          = y_out_value;
  assign hw2reg.z_out.d          = z_out_value;
  assign hw2reg.cfg.data_width.d = cfg_data_width;
  assign hw2reg.cfg.frac_width.d = cfg_frac_width;
  assign hw2reg.cfg.max_iter.d   = cfg_max_iter;
  assign hw2reg.cfg.rsvd.d       = cfg_rsvd;

  // ---------------------------------------------------------------------------
  // FSM and datapath state
  // ---------------------------------------------------------------------------
  typedef enum logic [0:0] {
    StIdle = 1'b0,
    StRun  = 1'b1
  } cordic_state_e;

  cordic_state_e state_q, state_d;

  logic signed [INT_W-1:0]   x_q, x_d;
  logic signed [INT_W-1:0]   y_q, y_d;
  logic signed [ANGLE_W-1:0] z_q, z_d;
  logic signed [ANGLE_W-1:0] atan_q, atan_d;

  logic [ITER_W-1:0] iter_q, iter_d;
  logic [7:0]        n_iter_q, n_iter_d;
  logic              mode_q, mode_d;

  logic status_valid_d;
  logic status_error_d;

  logic start_rise;
  logic start_fall_unused;

  logic [7:0] n_iter_eff;
  logic       n_iter_invalid;

  logic signed [INT_W-1:0]   x_init;
  logic signed [INT_W-1:0]   y_init;
  logic signed [ANGLE_W-1:0] z_init;

  logic signed [INT_W-1:0]   x_shift;
  logic signed [INT_W-1:0]   y_shift;
  logic signed [INT_W-1:0]   x_step;
  logic signed [INT_W-1:0]   y_step;
  logic signed [ANGLE_W-1:0] z_step;

  logic signed [DATA_W-1:0]  x_out_next;
  logic signed [DATA_W-1:0]  y_out_next;
  logic signed [ANGLE_W-1:0] z_out_next;

  // ---------------------------------------------------------------------------
  // Helper functions
  // ---------------------------------------------------------------------------

  function automatic logic signed [INT_W-1:0] csr_to_data_int(input logic [31:0] csr_word);
    logic signed [DATA_W-1:0] narrow_value;
    begin
      narrow_value    = csr_word[DATA_W-1:0];
      csr_to_data_int = {{(INT_W-DATA_W){narrow_value[DATA_W-1]}}, narrow_value};
    end
  endfunction

  function automatic logic signed [ANGLE_W-1:0] csr_to_angle_int(input logic [31:0] csr_word);
    logic signed [ANGLE_W-1:0] narrow_value;
    begin
      narrow_value     = csr_word[ANGLE_W-1:0];
      csr_to_angle_int = narrow_value;
    end
  endfunction

  function automatic logic signed [DATA_W-1:0] sat_data_to_visible(
    input logic signed [INT_W-1:0] value_i
  );
    logic signed [INT_W-1:0] max_val;
    logic signed [INT_W-1:0] min_val;
    begin
      max_val = {{(INT_W-DATA_W){1'b0}}, {1'b0, {(DATA_W-1){1'b1}}}};
      min_val = {{(INT_W-DATA_W){1'b1}}, {1'b1, {(DATA_W-1){1'b0}}}};

      if (value_i > max_val) begin
        sat_data_to_visible = {1'b0, {(DATA_W-1){1'b1}}};
      end else if (value_i < min_val) begin
        sat_data_to_visible = {1'b1, {(DATA_W-1){1'b0}}};
      end else begin
        sat_data_to_visible = value_i[DATA_W-1:0];
      end
    end
  endfunction

  // ---------------------------------------------------------------------------
  // Static CFG register contents
  // ---------------------------------------------------------------------------
  assign cfg_data_width = DATA_W_U8;
  assign cfg_frac_width = DATA_FRAC_W_U8;
  assign cfg_max_iter   = MAX_ITER_U8;
  assign cfg_rsvd       = '0;

  assign status_rsvd = '0;
  assign status_busy = (state_q == StRun);

  // ---------------------------------------------------------------------------
  // START edge detection
  // ---------------------------------------------------------------------------
  prim_edge_detect u_start_edge_detect (
    .clk_i    (clk_i),
    .rst_ni   (rst_ni),
    .en_i     (1'b1),
    .serial_i (ctrl_start),
    .r_edge_o (start_rise),
    .f_edge_o (start_fall_unused)
  );

  // ---------------------------------------------------------------------------
  // Iteration count sanitization
  // ---------------------------------------------------------------------------
  always_comb begin
    n_iter_eff     = MAX_ITER_U8;
    n_iter_invalid = 1'b0;

    if (ctrl_n_iter == 8'd0) begin
      n_iter_eff     = MAX_ITER_U8;
      n_iter_invalid = 1'b0;
    end else if (ctrl_n_iter > MAX_ITER_U8) begin
      n_iter_eff     = MAX_ITER_U8;
      n_iter_invalid = 1'b1;
    end else begin
      n_iter_eff     = ctrl_n_iter;
      n_iter_invalid = 1'b0;
    end
  end

  // ---------------------------------------------------------------------------
  // Pre-rotation / quadrant mapping
  // ---------------------------------------------------------------------------
  always_comb begin
    logic signed [INT_W-1:0]   x_in_int;
    logic signed [INT_W-1:0]   y_in_int;
    logic signed [ANGLE_W-1:0] z_in_int;

    x_in_int = csr_to_data_int(x_in_value);
    y_in_int = csr_to_data_int(y_in_value);
    z_in_int = csr_to_angle_int(z_in_value);

    x_init = x_in_int;
    y_init = y_in_int;
    z_init = z_in_int;

    if (ctrl_mode == 1'b0) begin
      // Rotation mode:
      // bring z into the main convergence interval around zero.
      if (z_in_int > HALF_PI_Q) begin
        x_init = -x_in_int;
        y_init = -y_in_int;
        z_init = z_in_int - PI_Q;
      end else if (z_in_int < -HALF_PI_Q) begin
        x_init = -x_in_int;
        y_init = -y_in_int;
        z_init = z_in_int + PI_Q;
      end
    end else begin
      // Vectoring mode:
      // map the vector to the right half-plane and bias z by +/- pi.
      z_init = '0;

      // Explicit zero-vector handling.
      // The angle of the null vector is undefined mathematically, but the RTL
      // chooses a deterministic software-friendly behavior: return z = 0.
      if ((x_in_int == 0) && (y_in_int == 0)) begin
        x_init = '0;
        y_init = '0;
        z_init = '0;
      end else if (x_in_int < 0) begin
        x_init = -x_in_int;
        y_init = -y_in_int;

        if (y_in_int >= 0) begin
          z_init = PI_Q;
        end else begin
          z_init = -PI_Q;
        end
      end
    end
  end

  // ---------------------------------------------------------------------------
  // One iterative CORDIC step
  // ---------------------------------------------------------------------------
  // atan_q is prefetched one cycle ahead from AtanLut. The z arithmetic sees
  // only this registered value, breaking the LUT-select -> z-adder path while
  // preserving one completed CORDIC iteration per StRun cycle.
  always_comb begin
    x_shift = x_q >>> iter_q;
    y_shift = y_q >>> iter_q;

    x_step = x_q;
    y_step = y_q;
    z_step = z_q;

    if (mode_q == 1'b0) begin
      // Rotation mode
      if (z_q >= 0) begin
        x_step = x_q - y_shift;
        y_step = y_q + x_shift;
        z_step = z_q - atan_q;
      end else begin
        x_step = x_q + y_shift;
        y_step = y_q - x_shift;
        z_step = z_q + atan_q;
      end
    end else begin
      // Vectoring mode
      if (y_q >= 0) begin
        x_step = x_q + y_shift;
        y_step = y_q - x_shift;
        z_step = z_q + atan_q;
      end else begin
        x_step = x_q - y_shift;
        y_step = y_q + x_shift;
        z_step = z_q - atan_q;
      end
    end
  end

  // ---------------------------------------------------------------------------
  // Output quantization
  // ---------------------------------------------------------------------------
  always_comb begin
    logic signed [DATA_W-1:0] x_final_visible;
    logic signed [DATA_W-1:0] y_final_visible;

    x_final_visible = sat_data_to_visible(x_step);
    y_final_visible = sat_data_to_visible(y_step);

    x_out_next = x_final_visible;
    y_out_next = y_final_visible;
    z_out_next = z_step;
  end

  // ---------------------------------------------------------------------------
  // Next-state logic
  // ---------------------------------------------------------------------------
  always_comb begin
    state_d        = state_q;
    x_d            = x_q;
    y_d            = y_q;
    z_d            = z_q;
    atan_d         = atan_q;
    iter_d         = iter_q;
    n_iter_d       = n_iter_q;
    mode_d         = mode_q;
    status_valid_d = status_valid;
    status_error_d = status_error;

    if (start_rise && (state_q != StIdle)) begin
      status_error_d = 1'b1;
    end

    unique case (state_q)
      StIdle: begin
        if (start_rise) begin
          state_d        = StRun;
          x_d            = x_init;
          y_d            = y_init;
          z_d            = z_init;
          atan_d         = AtanLut[0];
          iter_d         = '0;
          n_iter_d       = n_iter_eff;
          mode_d         = ctrl_mode;
          status_valid_d = 1'b0;
          status_error_d = n_iter_invalid;
        end
      end

      StRun: begin
        x_d = x_step;
        y_d = y_step;
        z_d = z_step;

        if (iter_q == (n_iter_q - 1'b1)) begin
          state_d        = StIdle;
          iter_d         = '0;
          status_valid_d = 1'b1;
        end else begin
          iter_d = iter_q + 1'b1;
          atan_d = AtanLut[iter_q + 1'b1];
        end
      end

      default: begin
        state_d        = StIdle;
        x_d            = '0;
        y_d            = '0;
        z_d            = '0;
        iter_d         = '0;
        n_iter_d       = MAX_ITER_U8;
        mode_d         = 1'b0;
        status_valid_d = 1'b0;
        status_error_d = 1'b1;
      end
    endcase
  end

  // ---------------------------------------------------------------------------
  // Sequential registers
  // ---------------------------------------------------------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_q       <= StIdle;
      x_q           <= '0;
      y_q           <= '0;
      z_q           <= '0;
      atan_q        <= '0;
      iter_q        <= '0;
      n_iter_q      <= MAX_ITER_U8;
      mode_q        <= 1'b0;
      status_valid  <= 1'b0;
      status_error  <= 1'b0;
      x_out_q       <= '0;
      y_out_q       <= '0;
      z_out_q       <= '0;
    end else if (ctrl_soft_rst) begin
      state_q       <= StIdle;
      x_q           <= '0;
      y_q           <= '0;
      z_q           <= '0;
      atan_q        <= '0;
      iter_q        <= '0;
      n_iter_q      <= MAX_ITER_U8;
      mode_q        <= 1'b0;
      status_valid  <= 1'b0;
      status_error  <= 1'b0;
      x_out_q       <= '0;
      y_out_q       <= '0;
      z_out_q       <= '0;
    end else begin
      state_q      <= state_d;
      x_q          <= x_d;
      y_q          <= y_d;
      z_q          <= z_d;
      atan_q       <= atan_d;
      iter_q       <= iter_d;
      n_iter_q     <= n_iter_d;
      mode_q       <= mode_d;
      status_valid <= status_valid_d;
      status_error <= status_error_d;

      if ((state_q == StRun) && (iter_q == (n_iter_q - 1'b1))) begin
        x_out_q <= x_out_next;
        y_out_q <= y_out_next;
        z_out_q <= z_out_next;
      end
    end
  end

endmodule
