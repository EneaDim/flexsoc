module fsm_example import fsm_example_pkg::*; (
  input  logic clk_i,
  input  logic rst_ni,
  input  logic clear_error_i,
  input  logic cmd_pending_i,
  input  logic cmd_valid_i,
  input  logic error_i,
  input  logic exec_done_i,
  input  logic fatal_error_i,
  input  logic flush_done_i,
  input  logic flush_req_i,
  input  logic prefetch_done_i,
  input  logic reset_done_i,
  input  logic restart_i,
  input  logic sleep_req_i,
  input  logic wake_i,
  input  logic writeback_done_i,
  output logic busy_o,
  output logic valid_o,
  output logic error_o,
  output logic low_power_o,
  output logic dbg_o,
  output state_fsm state_o
);

  logic busy_o_d;
  logic valid_o_d;
  logic error_o_d;
  logic low_power_o_d;
  logic dbg_o_d;

  state_fsm current_state, next_state;

  assign state_o = current_state;

  // STATE LATCHING
  always_ff @(posedge clk_i or negedge rst_ni)
    begin: state_latching
      if (~rst_ni) begin
        current_state <= RESET;
      end else begin
        current_state <= next_state;
      end
    end

  // OUTPUT LATCHING
  always_ff @(posedge clk_i or negedge rst_ni)
    begin: output_latching
      if (~rst_ni) begin
        busy_o <= 1'b1;
        valid_o <= 1'b0;
        error_o <= 1'b0;
        low_power_o <= 1'b0;
        dbg_o <= 1'b0;
      end else begin
        busy_o <= busy_o_d;
        valid_o <= valid_o_d;
        error_o <= error_o_d;
        low_power_o <= low_power_o_d;
        dbg_o <= dbg_o_d;
      end
    end

  // STATE TRANSITION AND OUTPUT DEFINITION
  always_comb begin
    next_state = current_state;
    busy_o_d = 1'b0; // overwritten below per-state
    valid_o_d = 1'b0; // overwritten below per-state
    error_o_d = 1'b0; // overwritten below per-state
    low_power_o_d = 1'b0; // overwritten below per-state
    dbg_o_d = 1'b0; // overwritten below per-state
    unique case (current_state)
      RESET: begin
        if (reset_done_i) begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = RESET;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
      end
      IDLE: begin
        if (cmd_pending_i) begin
          next_state = WAIT_CMD;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else if (sleep_req_i) begin
          next_state = LOW_POWER;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b1;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
      end
      WAIT_CMD: begin
        if (cmd_valid_i & ~flush_req_i) begin
          next_state = PREFETCH;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
        else if (flush_req_i) begin
          next_state = FLUSH;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
        else begin
          next_state = WAIT_CMD;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
      end
      PREFETCH: begin
        if (prefetch_done_i) begin
          next_state = EXECUTE;
          busy_o_d = 1'b1;
          valid_o_d = 1'b1;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = PREFETCH;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
      end
      EXECUTE: begin
        if (exec_done_i & ~error_i) begin
          next_state = WRITEBACK;
          busy_o_d = 1'b1;
          valid_o_d = 1'b1;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else if (error_i) begin
          next_state = ERROR;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b1;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
        else begin
          next_state = EXECUTE;
          busy_o_d = 1'b1;
          valid_o_d = 1'b1;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
      end
      WRITEBACK: begin
        if (writeback_done_i & ~cmd_pending_i) begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else if (writeback_done_i & cmd_pending_i) begin
          next_state = WAIT_CMD;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = WRITEBACK;
          busy_o_d = 1'b1;
          valid_o_d = 1'b1;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
      end
      FLUSH: begin
        if (flush_done_i & ~cmd_pending_i) begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else if (flush_done_i & cmd_pending_i) begin
          next_state = WAIT_CMD;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = FLUSH;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
      end
      ERROR: begin
        if (fatal_error_i) begin
          next_state = SHUTDOWN;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b1;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
        else if (clear_error_i & ~fatal_error_i) begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = ERROR;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b1;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
      end
      LOW_POWER: begin
        if (wake_i) begin
          next_state = IDLE;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = LOW_POWER;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b1;
          dbg_o_d = 1'b0;
        end
      end
      SHUTDOWN: begin
        if (restart_i) begin
          next_state = RESET;
          busy_o_d = 1'b1;
          valid_o_d = 1'b0;
          error_o_d = 1'b0;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b0;
        end
        else begin
          next_state = SHUTDOWN;
          busy_o_d = 1'b0;
          valid_o_d = 1'b0;
          error_o_d = 1'b1;
          low_power_o_d = 1'b0;
          dbg_o_d = 1'b1;
        end
      end
      default: begin
        next_state = RESET;
        busy_o_d = 1'b1;
        valid_o_d = 1'b0;
        error_o_d = 1'b0;
        low_power_o_d = 1'b0;
        dbg_o_d = 1'b0;
      end
    endcase
  end

endmodule
