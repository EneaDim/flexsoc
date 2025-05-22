/**
 * @file cache_wrapper.sv
 * @brief Cache with parallel tag compare and proper writeback.
 */
module cache_wrapper #(
  parameter int DATA_WIDTH = 32,
  parameter int ADDR_WIDTH = 16,
  parameter int CACHE_SIZE = 1024,
  parameter int ASSOCIATIVITY = 2
)(
  input  logic                  clk_i,
  input  logic                  rst_ni,

  input  logic                  cpu_valid_i,
  output logic                  cpu_ready_o,
  input  logic                  cpu_we_i,
  input  logic [ADDR_WIDTH-1:0] cpu_adr_i,
  input  logic [DATA_WIDTH-1:0] cpu_wdata_i,
  output logic [DATA_WIDTH-1:0] cpu_rdata_o,
  output logic                  cpu_resp_valid_o,

  output logic                  mem_valid_o,
  input  logic                  mem_ready_i,
  output logic                  mem_we_o,
  output logic [ADDR_WIDTH-1:0] mem_adr_o,
  output logic [DATA_WIDTH-1:0] mem_wdata_o,
  input  logic [DATA_WIDTH-1:0] mem_rdata_i
);

  localparam int WORD_BYTES      = DATA_WIDTH / 8;
  localparam int NUM_BLOCKS      = CACHE_SIZE / WORD_BYTES;
  localparam int NUM_SETS        = NUM_BLOCKS / ASSOCIATIVITY;
  localparam int SET_INDEX_WIDTH = $clog2(NUM_SETS);
  localparam int TAG_WIDTH       = ADDR_WIDTH - SET_INDEX_WIDTH;
  localparam int TAG_META_WIDTH  = TAG_WIDTH + 2;

  typedef struct packed {
    logic valid;
    logic dirty;
    logic [TAG_WIDTH-1:0] tag;
  } tag_meta_t;

  typedef enum logic [2:0] {
    ST_IDLE       = 3'b000,
    ST_TAG_ACCESS = 3'b001,
    ST_TAG_CHECK  = 3'b010,
    ST_WRITEBACK  = 3'b011,
    ST_REFILL     = 3'b100,
    ST_RESPOND    = 3'b101
  } state_t;

  state_t state_r, state_n;

  logic cpu_we_reg;
  logic [ADDR_WIDTH-1:0] cpu_adr_reg;
  logic [DATA_WIDTH-1:0] cpu_wdata_reg;

  logic [TAG_WIDTH-1:0]       cpu_tag;
  logic [SET_INDEX_WIDTH-1:0] cpu_index;

  assign cpu_index = cpu_adr_i[SET_INDEX_WIDTH-1:0];
  assign cpu_tag   = cpu_adr_i[ADDR_WIDTH-1 -: TAG_WIDTH];

  tag_meta_t tag_meta_array [ASSOCIATIVITY-1:0];
  logic [TAG_META_WIDTH-1:0] tag_rdata_way [ASSOCIATIVITY-1:0];
  logic [TAG_META_WIDTH-1:0] tag_wdata_way;
  logic [ASSOCIATIVITY-1:0]  tag_we_way;

  logic [DATA_WIDTH-1:0]    data_rdata_way [ASSOCIATIVITY-1:0];
  logic [DATA_WIDTH-1:0]    data_wdata_way;
  logic [ASSOCIATIVITY-1:0] data_we_way;

  logic hit;
  logic [$clog2(ASSOCIATIVITY)-1:0] hit_way;

  logic [$clog2(ASSOCIATIVITY)-1:0] repl_ptr [NUM_SETS-1:0];
  logic [$clog2(ASSOCIATIVITY)-1:0] repl_way;

  // FSM
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      state_r <= ST_IDLE;
    end else begin
      state_r <= state_n;
    end
  end

  // Registered inputs for stable FSM signals
  always_ff @(posedge clk_i) begin
    if (!rst_ni) begin
      cpu_adr_reg <= '0;
      cpu_we_reg <= 1'b0;
      cpu_wdata_reg <= '0;
      for (int i = 0; i < NUM_SETS; i++) begin
        repl_ptr[i] <= '0;
      end
    end else begin
      cpu_adr_reg <= cpu_adr_i;
      cpu_we_reg <= cpu_we_i;
      cpu_wdata_reg <= cpu_wdata_i;
      if (state_r == ST_REFILL && mem_ready_i) begin
        repl_ptr[cpu_index] <= repl_ptr[cpu_index] + 1'b1;
      end
    end
  end

  always_comb begin
    state_n        = state_r;
    tag_we_way     = '0;
    tag_wdata_way  = '0;
    data_we_way    = '0;
    data_wdata_way = '0;
    mem_valid_o    = 1'b0;
    mem_we_o       = 1'b0;
    mem_adr_o      = '0;
    mem_wdata_o    = '0;
    hit            = 1'b0;
    hit_way        = '0;
    repl_way       = '0;
    for (int w = 0; w < ASSOCIATIVITY; w++) begin
      tag_meta_array[w] = '0;  // Clear to default to prevent latches
    end

    case (state_r)
      ST_IDLE: begin
        if (cpu_valid_i) begin
          state_n = ST_TAG_ACCESS;
        end
      end

      ST_TAG_ACCESS: begin
        state_n = ST_TAG_CHECK;
      end

      ST_TAG_CHECK: begin
        hit = 1'b0;
        for (int w = 0; w < ASSOCIATIVITY; w++) begin
          tag_meta_array[w] = tag_rdata_way[w];
          if (tag_meta_array[w].valid && tag_meta_array[w].tag == cpu_tag) begin
            hit     = 1'b1;
            hit_way = $clog2(ASSOCIATIVITY)'(w);
          end
        end
        if (hit) begin
          state_n = ST_RESPOND;
        end else begin
          repl_way = repl_ptr[cpu_index];
          if (tag_meta_array[repl_way].dirty) begin
            state_n = ST_WRITEBACK;
          end else begin
            state_n = ST_REFILL;
          end
        end
      end

      ST_WRITEBACK: begin
        mem_valid_o = 1'b1;
        mem_we_o    = 1'b1;
        mem_adr_o   = {tag_meta_array[repl_way].tag, cpu_index};
        mem_wdata_o = data_rdata_way[repl_way];
        if (mem_ready_i) begin
          state_n = ST_REFILL;
        end
      end

      ST_REFILL: begin
        mem_valid_o = 1'b1;
        mem_we_o    = 1'b0;
        mem_adr_o   = cpu_adr_reg;
        if (mem_ready_i) begin
          tag_we_way[repl_way]  = 1'b1;
          tag_wdata_way         = {1'b1, cpu_we_reg, cpu_tag};
          data_we_way[repl_way] = 1'b1;
          data_wdata_way        = cpu_we_reg ? cpu_wdata_reg : mem_rdata_i;
          state_n               = ST_RESPOND;
        end
      end

      ST_RESPOND: begin
        state_n = ST_IDLE;
      end

      default: begin
        state_n = ST_IDLE; // fail-safe fallback
      end
    endcase
  end

  // Instantiate Tag RAMs
  generate
    for (genvar w = 0; w < ASSOCIATIVITY; w++) begin : gen_tag_rams
      prim_ram #(
        .ADDR_WIDTH(SET_INDEX_WIDTH),
        .DATA_WIDTH(TAG_META_WIDTH),
        .MEM_DEPTH(NUM_SETS)
      ) tag_ram_inst (
        .clk_i(clk_i),
        .rst_ni(rst_ni),
        .en_i(1'b1),
        .we_i(tag_we_way[w]),
        .addr_i(cpu_index),
        .wdata_i(tag_wdata_way),
        .rdata_o(tag_rdata_way[w])
      );
    end
  endgenerate

  // Instantiate Data RAMs
  generate
    for (genvar w = 0; w < ASSOCIATIVITY; w++) begin : gen_data_rams
      prim_ram #(
        .ADDR_WIDTH(SET_INDEX_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .MEM_DEPTH(NUM_SETS)
      ) data_ram_inst (
        .clk_i(clk_i),
        .rst_ni(rst_ni),
        .en_i(1'b1),
        .we_i(data_we_way[w]),
        .addr_i(cpu_index),
        .wdata_i(data_wdata_way),
        .rdata_o(data_rdata_way[w])
      );
    end
  endgenerate

  assign cpu_ready_o      = (state_r == ST_IDLE);
  assign cpu_rdata_o      = data_rdata_way[hit_way];
  assign cpu_resp_valid_o = (state_r == ST_RESPOND);

endmodule

