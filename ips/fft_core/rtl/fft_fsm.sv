module fft_fsm 
  import fft_fsm_pkg::*;
(

  input clk_i,
  input rst_ni,
  input start_i,
  input end_samples_i,
  input end_compute_i,
  input end_algo_i,
  output logic en_cnt_samples_o,
  output logic wr_mem_o,
  output logic en_cnt_rd_o,
  output logic done_o,
  output state_fsm state_o

);

  logic en_cnt_samples_o_d;
  logic wr_mem_o_d;
  logic  en_cnt_rd_o_d;
  logic done_o_d;

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
         en_cnt_rd_o <=  en_cnt_rd_o_d;
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
        if (end_samples_i) begin
          next_state = READ_1;
        end else begin
          next_state = ACTIVE_WRITE;
        end
      end
      READ_1: begin
        next_state = READ_2;
      end
      READ_2: begin
        next_state = COMPUTE;
      end
      COMPUTE: begin
        if (end_compute_i) begin
          next_state = WRITE_RESULT;
        end else if (end_algo_i) begin
          next_state = DONE;
        end else begin
          next_state = COMPUTE;
        end
      end
      WRITE_RESULT: begin
        if (end_algo_i) begin
          next_state = DONE;
        end else begin
          next_state = READ_1;
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
        if (end_samples_i) begin
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
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        done_o_d = 1'b0;
      end
      READ_2: begin
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        done_o_d = 1'b0;
      end
      COMPUTE: begin
        if (end_compute_i) begin
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b1;
          done_o_d = 1'b0;
        end else if (end_algo_i) begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b1;
        end else begin
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      WRITE_RESULT: begin
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        done_o_d = 1'b0;
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
