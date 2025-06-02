module fft_core 
  import fft_fsm_pkg::*;
#(
  parameter int FFT_SIZE   = 1024,
  parameter int DATA_WIDTH = 16,
  parameter bit ASYNC = 0
)(
  input  logic                      clk_i,
  input  logic                      rst_ni,

  // ADC input interface (re samples)
  input  logic signed [DATA_WIDTH-1:0] adc_data_i,
  input  logic                      adc_valid_i,
  output logic                      adc_ready_o,

  // FFT output interface (complex samples)
  output logic                      fft_out_valid_o,
  output logic signed [2*DATA_WIDTH-1:0] fft_out_data_o,
  input  logic                      fft_out_ready_i
);
 
  localparam int LOG2_FFT_SIZE = $clog2(FFT_SIZE);
  localparam int STAGE_COUNT = LOG2_FFT_SIZE;
  localparam int COMPLEX_WIDTH = 2 * DATA_WIDTH;

  typedef struct packed {
    logic signed [DATA_WIDTH-1:0] re;
    logic signed [DATA_WIDTH-1:0] im;
  } complex_t;

  // ---------------------------------------------------
  // Bit reversal function
  // ---------------------------------------------------
  function automatic logic [31:0] bit_reverse(input logic [31:0] val, input int N);
    logic [31:0] reversed;
    reversed = '0;
    for (int i = 0; i < N; i++) begin
      reversed[i] = val[N - 1 - i];
    end
    return reversed;
  endfunction

  //
  // Complex math helpers
  // ---------------------------------------------------
  function automatic complex_t cmul(input complex_t a, input complex_t b);
    complex_t res;
    // Multiply and shift by DATA_WIDTH to keep scale
    logic signed [2*DATA_WIDTH-1:0] mult_re, mult_im;
    assign mult_re = a.re * b.re - a.im * b.im;
    assign mult_im = a.re * b.im + a.im * b.re;
    assign res.re = mult_re >>> (DATA_WIDTH - 1);  // adjust shift for scaling
    assign res.im = mult_im >>> (DATA_WIDTH - 1);
    return res;
  endfunction

  function automatic complex_t cadd(input complex_t a, input complex_t b);
    return '{re: a.re + b.re, im: a.im + b.im};
  endfunction

  function automatic complex_t csub(input complex_t a, input complex_t b);
    return '{re: a.re - b.re, im: a.im - b.im};
  endfunction

  // ---------------------------------------------------
  // Twiddle ROM interface (instantiate your twiddle_rom module here)
  // Must be synchronous read
  // ---------------------------------------------------
  logic [STAGE_COUNT-1:0] twiddle_addr;
  logic signed [DATA_WIDTH-1:0] tw_re, tw_im;

  twiddle_rom #(
    .N(FFT_SIZE),
    .WIDTH(DATA_WIDTH)
  ) tw_rom (
    .addr(twiddle_addr),
    .re(tw_re),
    .im(tw_im)
  );

  // ---------------------------------------------------
  // FFT internal buffers and control signals
  // ---------------------------------------------------
  logic [STAGE_COUNT-1:0] stage_reg;
  logic [LOG2_FFT_SIZE-1:0] load_count_reg;
  logic [LOG2_FFT_SIZE-1:0] output_count_reg;
  logic compute_done_reg;
  
  // Counters for butterflies in COMPUTE stage
  logic [$clog2(FFT_SIZE/2)-1:0] stage_count;
  logic [$clog2(FFT_SIZE/2)-1:0] group_count;
  logic [$clog2(FFT_SIZE/2)-1:0] butterfly_count;
  
  logic [STAGE_COUNT-1:0] twiddle_shift;
  
  complex_t u, v, w, t;
  
  // Butterfly Count
  logic rst_butterfly_count;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if(!rst_ni) begin
      butterfly_count <= '0;
    end else if (rst_butterfly_count) begin
      butterfly_count <= '0;
    end else if (en_butterfly_cnt_rd) begin
      butterfly_count <= butterfly_count +'d1;
    end
  end
  // Enable
  assign en_butterfly_cnt_rd = en_cnt_rd;
  // Reset after n_butterflyes//groups
  int n_rst;
  always_comb begin
    n_rst = (1 << $clog2(groups));
  end
  assign rst_butterfly_count = (butterfly_count == n_rst-1) && (state_w==WRITE_RESULT);
  // Group count
  logic rst_group_count, en_group_cnt_rd;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if(!rst_ni) begin
      group_count     <= '0;
    end else if (rst_group_count) begin
      group_count <= '0;
    end else if (en_group_cnt_rd) begin
      group_count <= group_count +'d1;
    end
  end
  assign en_group_cnt_rd = rst_butterfly_count;
  assign rst_group_count = (group_count == groups-1) && (state_w==WRITE_RESULT);
  // Stage count
  logic rst_stage_count, en_stage_cnt_rd;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if(!rst_ni) begin
      stage_count     <= '0;
    end else if (rst_stage_count) begin
      stage_count <= '0;
    end else if (en_stage_cnt_rd) begin
      stage_count <= stage_count +'d1;
    end
  end
  assign en_stage_cnt_rd = rst_group_count;
  // Address index computation
  int m, d, groups, n;
  
  always_comb begin
    m      = 1 << (stage_count + 1);
    d      = 1 << stage_count;
    groups = FFT_SIZE >> (stage_count+ 2);
  end

  assign n = 1<<$clog2(FFT_SIZE-1); // n-butterflyes

  // u_idx, v_idx, w_idx
  always_comb begin
    u_idx = (group_count << (stage_count + 1)) + butterfly_count;
    v_idx = u_idx + d;
    w_idx = butterfly_count << (LOG2_FFT_SIZE - (stage_count + 1));      
  end

  //assign twiddle_shift = STAGE_COUNT - 1 - stage_reg;
  //assign twiddle_addr = j_idx << twiddle_shift;
  //
  //// Fetch butterfly inputs
  //assign u = stage_buffer[k_idx + j_idx];
  //assign v = stage_buffer[k_idx + j_idx + half_m];
  //
  //// Twiddle factors assumed output from twiddle_rom synchronously with twiddle_addr
  //assign w = '{re: tw_re, im: tw_im}; 
  //
  //assign t = cmul(w, v);
  //
  //// Calculate bit-reversed index for current load_count
  //logic [LOG2_FFT_SIZE-1:0] bit_rev_idx;
  //assign bit_rev_idx = bit_reverse(load_count_reg, STAGE_COUNT);

  // MAIN FSM
  logic en_cnt_samples, end_algo_w, done_w;
  state_fsm state_w;
  fft_fsm
  u_fft_fsm (
    .clk_i,
    .rst_ni,
    .start_i(adc_valid_i),
    .end_samples_i(counter_samples == FFT_SIZE-1),
    .end_compute_i(1'b1),
    .end_algo_i(end_algo_w),
    .en_cnt_samples_o(en_cnt_samples),
    .wr_mem_o,
    .en_cnt_rd_o(en_cnt_rd),
    .done_o(done_w),
    .state_o(state_w)
  );

  assign end_algo_w = (groups==1 && butterfly_count==FFT_SIZE-1);

  // ---------------------------------------------------
  // Input buffering: pack two re samples into one complex sample
  // ---------------------------------------------------
  logic sample_pair_valid;
  logic [LOG2_FFT_SIZE-1:0] counter_samples;
  complex_t              input_sample;
  
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      sample_pair_valid <= 1'b0;
      counter_samples   <= '0;
      input_sample.re   <= '0;
      input_sample.im   <= '0;
    end else begin
      sample_pair_valid <= 1'b0;
      if (en_cnt_samples) begin
        input_sample.re   <= adc_data_i;
        input_sample.im   <= '0;
        sample_pair_valid <= 1'b1;
        counter_samples   <= counter_samples + 'd1;
      end
    end
  end

  assign adc_ready_o = !done_w;

  // ---------------------------------------------------
  // FIFO interface for complex input samples
  // ---------------------------------------------------
  logic [COMPLEX_WIDTH-1:0] mem_in_data;
  logic mem_in_valid, mem_in_ready;
  logic [COMPLEX_WIDTH-1:0] mem_out_data;
  logic mem_out_valid, mem_out_ready;
  logic [LOG2_FFT_SIZE-1:0] mem_address, u_idx, v_idx, w_idx;

  assign mem_in_data = {input_sample.re, input_sample.im};
  assign mem_address = (state_w==ACTIVE_WRITE || state_w==WRITE_RESULT) ? counter_samples : 
                       (state_w==READ_1) ? u_idx : v_idx;
  assign mem_in_valid = sample_pair_valid;
  assign mem_out_ready = 1'b1;  // Always ready to read

  prim_ram #(
    .ADDR_WIDTH(STAGE_COUNT),
    .DATA_WIDTH(COMPLEX_WIDTH),
    .MEM_DEPTH(FFT_SIZE)
  ) data_ram_inst (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .en_i(1'b1),
    .we_i(mem_i_valid),
    .addr_i(mem_address),
    .wdata_i(mem_in_data),
    .rdata_o(mem_out_data)
  );

  

endmodule
