module fft_fsm (
  input  logic clk_i,
  input  logic rst_ni,
  input  logic read_ram_i,
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
  output logic read_ram_o,
  output logic done_o
);

  logic en_cnt_samples_o_d;
  logic wr_mem_o_d;
  logic en_cnt_rd_o_d;
  logic read_ram_o_d;
  logic done_o_d;

  typedef enum logic [3:0] { 
    IDLE,
    READ_RAM,
    ACTIVE_WRITE,
    READ_1,
    READ_2,
    COMPUTE,
    WRITE_RESULT_1,
    WRITE_RESULT_2,
    DONE
  } state_fsm ;

  state_fsm current_state, next_state; 

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
        read_ram_o <= 1'b0;
        done_o <= 1'b0;
      end else begin
        en_cnt_samples_o <= en_cnt_samples_o_d;
        wr_mem_o <= wr_mem_o_d;
        en_cnt_rd_o <= en_cnt_rd_o_d;
        read_ram_o <= read_ram_o_d;
        done_o <= done_o_d;
      end
    end

  // STATE TRANSITION AND OUTPUT DEFINITION
  always_comb begin
    next_state = current_state;
    unique case (current_state)
      IDLE: begin
        if (read_ram_i) begin
          next_state = READ_RAM;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b1;
          done_o_d = 1'b0;
        end else if (start_i) begin
          next_state = ACTIVE_WRITE;
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = IDLE;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      READ_RAM: begin
        if (~read_ram_i) begin
          next_state = IDLE;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = READ_RAM;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b1;
          done_o_d = 1'b0;
        end
      end
      ACTIVE_WRITE: begin
        if (end_samples_i) begin
          next_state = READ_1;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = ACTIVE_WRITE;
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      READ_1: begin
        if (end_read_1) begin
          next_state = READ_2;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = READ_1;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      READ_2: begin
        if (end_read_2) begin
          next_state = COMPUTE;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = READ_2;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      COMPUTE: begin
        if (end_compute_i) begin
          next_state = WRITE_RESULT_1;
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b1;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = COMPUTE;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      WRITE_RESULT_1: begin
        if (end_write_1) begin
          next_state = WRITE_RESULT_2;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else begin
          next_state = WRITE_RESULT_1;
          en_cnt_samples_o_d = 1'b1;
          wr_mem_o_d = 1'b1;
          en_cnt_rd_o_d = 1'b1;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      WRITE_RESULT_2: begin
        if (~end_algo_i) begin
          next_state = READ_1;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end else if (end_algo_i) begin
          next_state = DONE;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b1;
        end else begin
          next_state = WRITE_RESULT_2;
          en_cnt_samples_o_d = 1'b0;
          wr_mem_o_d = 1'b0;
          en_cnt_rd_o_d = 1'b0;
          read_ram_o_d = 1'b0;
          done_o_d = 1'b0;
        end
      end
      DONE: begin
        next_state = IDLE;
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        read_ram_o_d = 1'b0;
        done_o_d = 1'b0;
      end
      default: begin
        next_state = IDLE;
        en_cnt_samples_o_d = 1'b0;
        wr_mem_o_d = 1'b0;
        en_cnt_rd_o_d = 1'b0;
        read_ram_o_d = 1'b0;
        done_o_d = 1'b0;
      end
    endcase
  end

endmodule
