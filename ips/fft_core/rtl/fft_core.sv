module fft_core 
  import fft_fsm_pkg::*;
#(
  parameter int FFT_SIZE   = 16,
  parameter int DATA_WIDTH = 16,
  parameter bit ASYNC = 0
)(
  input  logic                      clk_i,
  input  logic                      rst_ni,

  input  logic                      read_ram_i,

  // ADC input interface (re samples)
  input  logic signed [DATA_WIDTH-1:0] adc_data_i,
  input  logic                         adc_valid_i,
  output logic                         adc_ready_o,

  // FFT output interface (complex samples)
  output logic                           fft_out_valid_o,
  output logic signed [2*DATA_WIDTH-1:0] fft_out_data_o,
  input  logic                           fft_out_ready_i
);
 
  // Log2 FFT_SIZE usefull in different sections
  localparam int LOG2_FFT_SIZE = $clog2(FFT_SIZE);
  
  // Complex width
  localparam int COMPLEX_WIDTH = 2 * DATA_WIDTH;
  
  // Complex data structure
  typedef struct packed {
    logic signed [DATA_WIDTH-1:0] re;
    logic signed [DATA_WIDTH-1:0] im;
  } complex_t;

  typedef struct packed {
    logic signed [2*DATA_WIDTH-1:0] re;
    logic signed [2*DATA_WIDTH-1:0] im;
  } complex_ext_t;

  // Bit reversal function
  function automatic logic [31:0] bit_reverse(input logic [31:0] val, input int N);
    logic [31:0] reversed;
    reversed = '0;
    for (int i = 0; i < N; i++) begin
      reversed[i] = val[N - 1 - i];
    end
    return reversed;
  endfunction

  // Multiply
  function automatic complex_ext_t cmul(input complex_t a, input complex_t b);
    complex_ext_t res;
    res.re = a.re * b.re - a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;
    return res;
  endfunction
  
  // Add
  function automatic complex_t cadd(input complex_ext_t a, input complex_ext_t b);
    complex_ext_t add;
    complex_t res;
    add.re = a.re + b.re;
    add.im = a.im + b.im;
    res.re = add.re >>> (DATA_WIDTH-1);
    res.im = add.im >>> (DATA_WIDTH-1);
    return '{re: res.re, im: res.im};
  endfunction

  // Sub
  function automatic complex_t csub(input complex_ext_t a, input complex_ext_t b);
    complex_ext_t sub;
    complex_t res;
    sub.re = a.re - b.re;
    sub.im = a.im - b.im;
    res.re = sub.re >>> (DATA_WIDTH-1);
    res.im = sub.im >>> (DATA_WIDTH-1);
    return '{re: res.re, im: res.im};
  endfunction

  ///////////////////////
  // Index Computation //
  ///////////////////////

  // Counters for butterflies in COMPUTE stage
  logic [LOG2_FFT_SIZE-1:0] stage_count;
  logic [LOG2_FFT_SIZE-1:0] group_count;
  logic [LOG2_FFT_SIZE-1:0] butterfly_count;
  
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
    n_rst = n >> (LOG2_FFT_SIZE - stage_count);
  end
  assign rst_butterfly_count = (butterfly_count == n_rst-1) && (state_w==WRITE_RESULT_1);
  
  // Group count
  logic rst_group_count, en_group_cnt_rd;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if(!rst_ni) begin
      group_count <= '0;
    end else if (rst_group_count) begin
      group_count <= '0;
    end else if (en_group_cnt_rd) begin
      group_count <= group_count +'d1;
    end
  end
  
  // Enable and reset logic
  assign en_group_cnt_rd = rst_butterfly_count;
  assign rst_group_count = (group_count == groups-1) && (state_w==WRITE_RESULT_1) && rst_butterfly_count;
 
  // Stage count
  logic rst_stage_count, en_stage_cnt_rd;
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if(!rst_ni) begin
      stage_count <= '0;
    end else if (rst_stage_count) begin
      stage_count <= '0;
    end else if (en_stage_cnt_rd) begin
      stage_count <= stage_count +'d1;
    end
  end

  // Enable and reset logic
  assign en_stage_cnt_rd = rst_group_count;
  assign rst_stage_count = end_algo_w;  


  // Address index computation
  int m, d, groups, n;
  
  always_comb begin
    m      = 1 << (stage_count + 1);
    d      = 1 << stage_count;
    groups = FFT_SIZE >> (stage_count+1);
  end

  assign n = 1<<$clog2(FFT_SIZE-1); // n-butterflyes

  // u_idx, v_idx, w_idx
  always_comb begin
    u_idx = (group_count << (stage_count + 1)) + butterfly_count;
    v_idx = u_idx + d;
    w_idx = butterfly_count << (LOG2_FFT_SIZE - (stage_count + 1));      
  end

  ///////////////////////////
  // End Index Computation //
  ///////////////////////////



  //////////////////////////////
  // Twiddle address => w_idx //
  //////////////////////////////

  logic [LOG2_FFT_SIZE-1:0] twiddle_addr;
  assign twiddle_addr = w_idx;

  // Twiddle ROM interface
  logic signed [DATA_WIDTH-1:0] tw_re, tw_im;

  twiddle_rom_64 #(
    .N(FFT_SIZE),
    .WIDTH(DATA_WIDTH)
  ) tw_rom (
    .addr(twiddle_addr),
    .re  (tw_re),
    .im  (tw_im)
  );
  
  /////////////////////////////////////////////
  // First Stage : Fetching data from memory //
  /////////////////////////////////////////////

  // Complex data
  complex_t w, w_q, u_q, v_q, w_q;
  complex_t u_mac, v_mac, u_mac_q, v_mac_q;
  complex_ext_t t, t_q, u_ext;
  
  assign w = '{re: tw_re, im: tw_im}; 

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (~rst_ni) begin
      u_q <= '0;
      v_q <= '0;
      w_q <= '0;
    end else begin
      if (state_w==READ_2) begin
        u_q <= mem_out_data;
      end else if (state_w==READ_1) begin
        v_q <= mem_out_data;
        w_q <= w;
      end
    end
  end

  // Note: 
  // - u_q ready on COMPUTE
  // - v_q ready on READ_2
  // - w_q ready on READ_2


  ///////////////////////////////
  // Second Stage: Comple MULT //
  ///////////////////////////////
  
  assign t = cmul(w_q, v_q);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (~rst_ni) begin
      t_q <= '0;
    end else begin
      if (state_w==READ_2) begin
        t_q <= t;
      end
    end
  end

  // Note:
  // - t_q ready on COMPUTE

  //////////////////////////////////////////
  // Prepare data parallelism for add/sub //
  //////////////////////////////////////////

  // Sign extention for 2*DATA_WIDTH add/sub
  assign u_ext.re = {{DATA_WIDTH{u_q.re[DATA_WIDTH-1]}}, u_q.re};
  assign u_ext.im = {{DATA_WIDTH{u_q.im[DATA_WIDTH-1]}}, u_q.im};


  //////////////////////////////////
  // Third Stage: Complex ADD/SUB //
  //////////////////////////////////
  
  assign u_mac = cadd(u_ext, t_q);
  assign v_mac = csub(u_ext, t_q);

  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      u_mac_q <= 'd0;
      v_mac_q <= 'd0;
    end else begin
      if (state_w==COMPUTE) begin
        u_mac_q <= u_mac;
        v_mac_q <= v_mac;
      end
    end
  end
  
  //////////////
  // MAIN FSM //
  //////////////
  logic en_cnt_samples, end_algo_w, done_w, we_mem_w;
  
  state_fsm state_w;
  
  fft_fsm u_fft_fsm (
    .clk_i,
    .rst_ni,
    .start_i(adc_valid_i),
    .end_samples_i(counter_samples == FFT_SIZE-1),
    .end_read_1(1'b1),
    .end_read_2(1'b1),
    .end_compute_i(1'b1),
    .end_write_1(1'b1),
    .end_algo_i(end_algo_w),
    .en_cnt_samples_o(en_cnt_samples),
    .wr_mem_o(wr_mem_w),
    .en_cnt_rd_o(en_cnt_rd),
    .done_o(done_w),
    .state_o(state_w)
  );

  assign end_algo_w = (stage_count==LOG2_FFT_SIZE);

  // ---------------------------------------------------
  // Input buffering: pack two re samples into one complex sample
  // ---------------------------------------------------
  logic [LOG2_FFT_SIZE-1:0] counter_samples, reversed_addr;
  logic                     sample_pair_valid;
  complex_t                 input_sample;
  
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
      end else if (read_ram_i) begin
        counter_samples   <= counter_samples + 'd1;
      end
    end
  end

  assign adc_ready_o = !done_w;

  // ---------------------------------------------------
  // Memory interface for complex input samples
  // ---------------------------------------------------
  logic [COMPLEX_WIDTH-1:0] mem_in_data;
  logic mem_in_valid, mem_in_ready;
  logic [COMPLEX_WIDTH-1:0] mem_out_data;
  logic mem_out_valid, mem_out_ready;
  logic [LOG2_FFT_SIZE-1:0] mem_address, u_idx, v_idx, w_idx;

  // Reverse address from counter value
  assign reversed_addr = bit_reverse(counter_samples, LOG2_FFT_SIZE);

  // Complex data
  assign mem_in_data = (state_w==ACTIVE_WRITE)   ? {input_sample.re, input_sample.im} :
                       (state_w==WRITE_RESULT_1) ? u_mac_q : v_mac_q;

  // Address selection based on state
  assign mem_address = (state_w==ACTIVE_WRITE)   ? reversed_addr   : 
                       (state_w==WRITE_RESULT_1 || read_ram_i) ? counter_samples :
                       (state_w==WRITE_RESULT_2) ? counter_samples :
                       // Read v_idx before to perform MUL
                       (state_w==READ_1)         ? v_idx           : u_idx; 

  assign mem_out_ready = 1'b1;  // Always ready to read

  // RAM instance
  prim_ram #(
    .ADDR_WIDTH(LOG2_FFT_SIZE),
    .DATA_WIDTH(COMPLEX_WIDTH),
    .MEM_DEPTH(FFT_SIZE)
  ) data_ram_inst (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .en_i(1'b1),
    .we_i(adc_valid_i || wr_mem_w),
    .addr_i(mem_address),
    .wdata_i(mem_in_data),
    .rdata_o(mem_out_data)
  );

endmodule
