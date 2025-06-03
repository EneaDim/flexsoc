module fft_fsm 
  import fft_fsm_pkg::*;
(
  input  logic clk_i,
  input  logic rst_ni,
  input  logic start_i,
  input  logic end_samples_i,
  input  logic end_read_1,
  input  logic end_read_2,
  input  logic end_compute_i,
  input  logic end_write_1,
  input  logic end_algo_i,
  output logic en_cnt_samples_o,
  output logic wr_mem_o,
  output logic en_cnt_rd_o,
  output logic done_o,
  output state_fsm state_o
);

  logic en_cnt_samples_o_d;
  logic wr_mem_o_d;
  logic en_cnt_rd_o_d;
  logic done_o_d;

  state_fsm current_state, next_state; 

  assign state_o = current_state;

  // STATE LATCHING
  always_ff @(posedge clk_i or negedge rst_ni)
    begin: state_latching
      if (~rst_ni) begin
        current_state <= IDLE;
      end else begin
        current_state <= next_state;
      end
    end

  // OUTPUT LATCHING
  always_ff @(posedge clk_i or negedge rst_ni)
    begin: output_latching
      if (~rst_ni) begin
        en_cnt_samples_o <= 1'b0;
        wr_mem_o <= 1'b0;
        en_cnt_rd_o <= 1'b0;
        done_o <= 1'b0;
      end else begin
        en_cnt_samples_o <= en_cnt_samples_o_d;
        wr_mem_o <= wr_mem_o_d;
        en_cnt_rd_o <= en_cnt_rd_o_d;
        done_o <= done_o_d;
      end
    end

  // STATE TRANSITION
  always_comb begin
    next_state = current_state;
    unique case (current_state)
      IDLE: begin
        if (start_i) begin
          next_state = ACTIVE_WRITE;
        end else begin
          next_state = IDLE;
        end
      end
      ACTIVE_WRITE: begin
        if ( end_samples_i) begin
          next_state = READ_1;
        end else begin
          next_state = ACTIVE_WRITE;
        end
      end
      READ_1: begin
        if (end_read_1) begin
          next_state = READ_2;
        end else begin
          next_state = READ_1;
        end
      end
      READ_2: begin
        if (end_read_2) begin
          next_state = COMPUTE;
        end else begin
          next_state = READ_2;
        end
      end
      COMPUTE: begin
        if (end_compute_i) begin
          next_state = WRITE_RESULT_1;
        end else begin
          next_state = COMPUTE;
        end
      end
      WRITE_RESULT_1: begin
        if (end_write_1) begin
          next_state = WRITE_RESULT_2;
        end else begin
          next_state = WRITE_RESULT_1;
        end
      end
      WRITE_RESULT_2: begin
        if (~end_algo_i) begin
          next_state = READ_1;
        end else if (end_algo_i) begin
          next_state = DONE;
        end else begin
          next_state = WRITE_RESULT_2;
        end
      end
      DONE: begin
        next_state = IDLE;
      end
      default: begin
        next_state = IDLE;
      end
    endcase
  end

  // OUTPUT DEFINITION
  always_comb begin
    en_cnt_samples_o_d = 1'b0;
    wr_mem_o_d = 1'b0;
    en_cnt_rd_o_d = 1'b0;
    done_o_d = 1'b0;
    unique case (current_state)
      IDLE: begin
        if (start_i) begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      ACTIVE_WRITE: begin
        if ( end_samples_i) begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      READ_1: begin
        if (end_read_1) begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      READ_2: begin
        if (end_read_2) begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      COMPUTE: begin
        if (end_compute_i) begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b1;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      WRITE_RESULT_1: begin
        if (end_write_1) begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      WRITE_RESULT_2: begin
        if (~end_algo_i) begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end else if (end_algo_i) begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b1;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      DONE: begin
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        done_o_d = 1'b0;
      end
      default: begin
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        done_o_d = 1'b0;
      end
    endcase
  end
endmodule
