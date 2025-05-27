module fft_core #(
  parameter int FFT_SIZE   = 1024,
  parameter int DATA_WIDTH = 16,
  parameter int FIFO_DEPTH = FFT_SIZE/2,
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

  localparam int STAGE_COUNT = $clog2(FFT_SIZE);
  localparam int COMPLEX_WIDTH = 2 * DATA_WIDTH;

  typedef struct packed {
    logic signed [DATA_WIDTH-1:0] re;
    logic signed [DATA_WIDTH-1:0] im;
  } complex_t;

  // ---------------------------------------------------
  // Input buffering: pack two re samples into one complex sample
  // ---------------------------------------------------
  logic [DATA_WIDTH-1:0] adc_sample_buf;
  logic                  adc_buf_valid;
  logic                  sample_pair_valid;
  complex_t              input_sample;

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      adc_buf_valid <= 1'b0;
      sample_pair_valid <= 1'b0;
    end else begin
      sample_pair_valid <= 1'b0;
      if (adc_valid_i && !adc_buf_valid) begin
        adc_sample_buf <= adc_data_i;
        adc_buf_valid <= 1'b1;
      end else if (adc_valid_i && adc_buf_valid) begin
        input_sample.re <= adc_sample_buf;
        input_sample.im <= adc_data_i;
        adc_buf_valid <= 1'b0;
        sample_pair_valid <= 1'b1;
      end
    end
  end

  assign adc_ready_o = !adc_buf_valid;

  // ---------------------------------------------------
  // FIFO interface for complex input samples
  // ---------------------------------------------------
  logic [COMPLEX_WIDTH-1:0] fifo_in_data;
  logic fifo_in_valid, fifo_in_ready;
  logic [COMPLEX_WIDTH-1:0] fifo_out_data;
  logic fifo_out_valid, fifo_out_ready;

  assign fifo_in_data = {input_sample.re, input_sample.im};
  assign fifo_in_valid = sample_pair_valid;
  assign fifo_out_ready = 1'b1;  // Always ready to read

  prim_fifo #(
    .DEPTH(FIFO_DEPTH),
    .WIDTH(COMPLEX_WIDTH),
    .ASYNC(ASYNC),
    .RD_BUFFER(1)
  ) input_fifo (
    .rd_clk_i(clk_i),
    .wr_clk_i(clk_i),
    .rst_ni(rst_ni),
    .wdata_i(fifo_in_data),
    .wvalid_i(fifo_in_valid),
    .wready_o(fifo_in_ready),
    .rdata_o(fifo_out_data),
    .rvalid_o(fifo_out_valid),
    .rready_i(fifo_out_ready),
    .fifo_full(),
    .fifo_empty()
  );

  // ---------------------------------------------------
  // Bit reversal function
  // ---------------------------------------------------
  // Function for bit reversal (assumed synthesized)
  function automatic logic [$clog2(FFT_SIZE)-1:0] bit_reverse(input logic [$clog2(FFT_SIZE)-1:0] val, input int bits);
    logic [$clog2(FFT_SIZE)-1:0] reversed;
    reversed = 0;
    for (int i = 0; i < bits; i++) begin
      reversed[i] = val[bits - 1 - i];
    end
    return reversed;
  endfunction
  //function automatic [STAGE_COUNT-1:0] bit_reverse(input [STAGE_COUNT-1:0] in);
  //  bit_reverse = '0;
  //  for (int i = 0; i < STAGE_COUNT; i++) begin
  //    bit_reverse[i] = in[STAGE_COUNT - 1 - i];
  //  end
  //endfunction

  // ---------------------------------------------------
  // Complex math helpers
  // ---------------------------------------------------
  function automatic complex_t cmul(input complex_t a, input complex_t b);
    complex_t res;
    // Multiply and shift by DATA_WIDTH to keep scale
    logic signed [2*DATA_WIDTH-1:0] mult_re, mult_im;
    mult_re = a.re * b.re - a.im * b.im;
    mult_im = a.re * b.im + a.im * b.re;
    res.re = mult_re >>> (DATA_WIDTH - 1);  // adjust shift for scaling
    res.im = mult_im >>> (DATA_WIDTH - 1);
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
complex_t stage_buffer [0:FFT_SIZE-1];
logic [STAGE_COUNT-1:0] stage_reg;
logic [$clog2(FFT_SIZE)-1:0] load_count_reg;
logic [$clog2(FFT_SIZE)-1:0] output_count_reg;
logic compute_done_reg;

typedef enum logic [1:0] {IDLE, LOAD, COMPUTE, OUTPUT} state_t;
state_t state_reg, next_state;

// Counters for butterflies in COMPUTE stage
logic [$clog2(FFT_SIZE/2)-1:0] butterfly_count;

// Derived values for compute stage
logic [STAGE_COUNT:0] m;        // Butterfly length = 2^(stage+1)
logic [STAGE_COUNT-1:0] half_m; // Half butterfly length = m/2

logic [$clog2(FFT_SIZE)-1:0] k_idx;
logic [$clog2(FFT_SIZE)-1:0] j_idx;

logic [STAGE_COUNT-1:0] twiddle_shift;

complex_t u, v, w, t;

// ---------------------------------------------------
// Combinational calculations for butterfly indices & twiddle address
// ---------------------------------------------------
assign m = 1 << (stage_reg + 1);
assign half_m = m >> 1;

assign k_idx = (butterfly_count / half_m) * m;
assign j_idx = butterfly_count % half_m;

assign twiddle_shift = STAGE_COUNT - 1 - stage_reg;
assign twiddle_addr = j_idx << twiddle_shift;

// Fetch butterfly inputs
assign u = stage_buffer[k_idx + j_idx];
assign v = stage_buffer[k_idx + j_idx + half_m];

// Twiddle factors assumed output from twiddle_rom synchronously with twiddle_addr
assign w = '{re: tw_re, im: tw_im}; 

assign t = cmul(w, v);

// Calculate bit-reversed index for current load_count
logic [$clog2(FFT_SIZE)-1:0] bit_rev_idx;
assign bit_rev_idx = bit_reverse(load_count_reg, STAGE_COUNT);

// ---------------------------------------------------
// FSM sequential logic
// ---------------------------------------------------
always_ff @(posedge clk_i or negedge rst_ni) begin
  if (!rst_ni) begin
    state_reg <= IDLE;
    load_count_reg <= 0;
    output_count_reg <= 0;
    stage_reg <= 0;
    compute_done_reg <= 0;
    butterfly_count <= 0;
  end else begin
    state_reg <= next_state;

    case (state_reg)
      IDLE: begin
        load_count_reg <= 0;
        output_count_reg <= 0;
        stage_reg <= 0;
        compute_done_reg <= 0;
        butterfly_count <= 0;
      end

      LOAD: begin
        if (fifo_out_valid) begin
          stage_buffer[bit_rev_idx] <= '{re: fifo_out_data[COMPLEX_WIDTH-1:DATA_WIDTH], im: fifo_out_data[DATA_WIDTH-1:0]};
          load_count_reg <= load_count_reg + 1;
        end
      end

      COMPUTE: begin
        if (!compute_done_reg) begin
          // Perform one butterfly per cycle
          stage_buffer[k_idx + j_idx] <= cadd(u, t);
          stage_buffer[k_idx + j_idx + half_m] <= csub(u, t);

          if (butterfly_count == (FFT_SIZE >> 1) - 1) begin
            butterfly_count <= 0;
            stage_reg <= stage_reg + 1;
            if (stage_reg == STAGE_COUNT - 1) begin
              compute_done_reg <= 1;
            end
          end else begin
            butterfly_count <= butterfly_count + 1;
          end
        end
      end

      OUTPUT: begin
        if (fft_out_ready_i) begin
          output_count_reg <= output_count_reg + 1;
        end
      end
    endcase
  end
end

// ---------------------------------------------------
// FSM combinational next state logic
// ---------------------------------------------------
always_comb begin
  next_state = state_reg;
  case (state_reg)
    IDLE:    if (fifo_out_valid) next_state = LOAD;
    LOAD:    if (load_count_reg == FFT_SIZE - 1) next_state = COMPUTE;
    COMPUTE: if (compute_done_reg) next_state = OUTPUT;
    OUTPUT:  if (output_count_reg == FFT_SIZE - 1) next_state = IDLE;
  endcase
end

// ---------------------------------------------------
// Output assignments
// ---------------------------------------------------
assign fft_out_valid_o = (state_reg == OUTPUT);
assign fft_out_data_o = {stage_buffer[output_count_reg].re, stage_buffer[output_count_reg].im};

endmodule
