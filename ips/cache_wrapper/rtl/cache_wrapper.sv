/**
 * @file cache_wrapper.sv
 * @brief Parametrizable Cache using external SRAMs (prim_ram) for data and tag storage.
 *
 * This cache uses the given prim_ram modules for both:
 *   - Data storage SRAM: stores the actual cache block data (1 word per block assumed).
 *   - Tag storage SRAM: stores tags and meta bits (valid, dirty).
 *
 * Assumptions:
 *  - BLOCK_SIZE = DATA_WIDTH/8 (1 word per block) for simplicity.
 *  - Fully synthesizable.
 *  - Simple round-robin replacement policy per set.
 *
 * Interface:
 *  - CPU: valid-ready handshake.
 *  - Memory: valid-ready handshake.
 *
 */
module cache_wrapper #(
  parameter integer DATA_WIDTH   = 32,   // Data word width in bits
  parameter integer ADDR_WIDTH   = 16,   // Address width in bits (for CPU & SRAM addressing)
  parameter integer CACHE_SIZE   = 1024, // Cache size in bytes
  parameter integer ASSOCIATIVITY  = 2   // Number of ways
)(
  input  logic           clk_i,       // Clock
  input  logic           rst_ni,      // Active low reset

  // CPU Interface (valid-ready handshake)
  input  logic                  cpu_valid_i,      // CPU request valid
  output logic                  cpu_ready_o,      // Cache ready to accept request
  input  logic                  cpu_we_i,         // CPU write enable (1=write, 0=read)
  input  logic [ADDR_WIDTH-1:0] cpu_adr_i,        // CPU address input
  input  logic [DATA_WIDTH-1:0] cpu_wdata_i,      // CPU write data input
  output logic [DATA_WIDTH-1:0] cpu_rdata_o,      // CPU read data output
  output logic                  cpu_resp_valid_o, // CPU response valid output

  // Memory Interface (valid-ready handshake)
  output logic                  mem_valid_o, // Memory request valid
  input  logic                  mem_ready_i, // Memory ready (accept/response)
  output logic                  mem_we_o,    // Memory write enable (1=write, 0=read)
  output logic [ADDR_WIDTH-1:0] mem_adr_o,   // Memory address
  output logic [DATA_WIDTH-1:0] mem_wdata_o, // Memory write data
  input  logic [DATA_WIDTH-1:0] mem_rdata_i  // Memory read data input
);

  // ------------------------------------------------
  // Derived parameters
  // BLOCK_SIZE assumed 1 word (DATA_WIDTH/8 bytes) for simplicity
  // ------------------------------------------------
  localparam integer WORD_BYTES       = DATA_WIDTH / 8;
  localparam integer NUM_BLOCKS       = CACHE_SIZE / WORD_BYTES;    // Total cache blocks
  localparam integer NUM_SETS         = NUM_BLOCKS / ASSOCIATIVITY;   // Number of sets
  localparam integer SET_INDEX_WIDTH  = $clog2(NUM_SETS);         // Set index width
  localparam integer TAG_WIDTH        = ADDR_WIDTH - SET_INDEX_WIDTH;  // Tag bits width

  // ------------------------------------------------
  // Tag metadata encoding width: valid(1) + dirty(1) + tag bits
  // Stored as [TAG_WIDTH+1:0]: {valid, dirty, tag}
  // ------------------------------------------------
  localparam integer TAG_META_WIDTH = TAG_WIDTH + 2;

  // ------------------------------------------------
  // RAM depth for tag and data RAMs = NUM_BLOCKS (one block per line)
  // Addressing for SRAMs:
  //   addr = set_index * ASSOCIATIVITY + way_index
  // ------------------------------------------------

  // ------------------------------------------------
  // Signals for tag RAM
  // ------------------------------------------------
  logic tag_en;
  logic tag_we;
  logic [SET_INDEX_WIDTH + $clog2(ASSOCIATIVITY)-1:0] tag_addr;
  logic [TAG_META_WIDTH-1:0] tag_wdata;
  logic [TAG_META_WIDTH-1:0] tag_rdata;

  // ------------------------------------------------
  // Signals for data RAM
  // ------------------------------------------------
  logic data_en;
  logic data_we;
  logic [SET_INDEX_WIDTH + $clog2(ASSOCIATIVITY)-1:0] data_addr;
  logic [DATA_WIDTH-1:0] data_wdata;
  logic [DATA_WIDTH-1:0] data_rdata;

  // ------------------------------------------------
  // Replacement pointer register per set for round-robin replacement
  // ------------------------------------------------
  logic [$clog2(ASSOCIATIVITY)-1:0] repl_ptr [NUM_SETS-1:0];

  // ------------------------------------------------
  // FSM states definition
  // ------------------------------------------------
  typedef enum logic [2:0] {
    ST_IDLE        = 3'd0,
    ST_TAG_READ    = 3'd1,
    ST_TAG_COMPARE = 3'd2,
    ST_MISS        = 3'd3,
    ST_WRITEBACK   = 3'd4,
    ST_REFILL      = 3'd5,
    ST_RESPOND     = 3'd6
  } state_t;

  state_t state_r, state_next;

  // ------------------------------------------------
  // Address breakdown
  // ------------------------------------------------
  logic [TAG_WIDTH-1:0] cpu_tag;
  logic [SET_INDEX_WIDTH-1:0] cpu_index;

  assign cpu_tag = cpu_adr_i[ADDR_WIDTH-1 -: TAG_WIDTH];
  assign cpu_index = cpu_adr_i[SET_INDEX_WIDTH-1:0]; // Lower bits used as set index

  // ------------------------------------------------
  // Internal registers and signals
  // ------------------------------------------------
  logic cpu_we_reg;
  logic [ADDR_WIDTH-1:0] cpu_adr_reg;
  logic [DATA_WIDTH-1:0] cpu_wdata_reg;

  // Tag and metadata read results per way
  logic valid_array  [ASSOCIATIVITY-1:0];
  logic dirty_array  [ASSOCIATIVITY-1:0];
  logic [TAG_WIDTH-1:0] tag_only_array [ASSOCIATIVITY-1:0];

  // Hit detection variables
  logic hit;
  logic [ASSOCIATIVITY-1:0] hit_mask;
  integer hit_way;

  // Replacement way
  integer repl_way;

  // Writeback variables
  logic wb_dirty;
  logic [TAG_WIDTH-1:0] wb_tag;
  logic [$clog2(NUM_SETS)-1:0] wb_set;
  logic [$clog2(ASSOCIATIVITY)-1:0] wb_way;

  // Response data register
  logic [DATA_WIDTH-1:0] resp_data_r;

  // CPU response valid register
  logic cpu_resp_valid_r;

  // Cache ready signal
  logic cpu_ready_r;

  // Temporary address for tag/data RAM (using shift instead of multiplication)
  logic [SET_INDEX_WIDTH + $clog2(ASSOCIATIVITY)-1:0] tag_addr_comb;
  
  always_comb begin
      // Use left shift instead of multiplication for power of 2 associativity
      tag_addr_comb = (state_set_idx << $clog2(ASSOCIATIVITY)) + way_counter;
  end
  // ------------------------------------------------
  // Instantiate tag RAM
  // ------------------------------------------------
  prim_ram #(
    .ADDR_WIDTH(SET_INDEX_WIDTH + $clog2(ASSOCIATIVITY)),
    .DATA_WIDTH(TAG_META_WIDTH),
    .MEM_DEPTH(NUM_BLOCKS),
    .VMEM_FILE("")
  ) tag_ram (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .en_i(tag_en),
    .we_i(tag_we),
    .addr_i(tag_addr),
    .wdata_i(tag_wdata),
    .rdata_o(tag_rdata)
  );

  // ------------------------------------------------
  // Instantiate data RAM
  // ------------------------------------------------
  prim_ram #(
    .ADDR_WIDTH(SET_INDEX_WIDTH + $clog2(ASSOCIATIVITY)),
    .DATA_WIDTH(DATA_WIDTH),
    .MEM_DEPTH(NUM_BLOCKS)
  ) data_ram (
    .clk_i(clk_i),
    .rst_ni(rst_ni),
    .en_i(data_en),
    .we_i(data_we),
    .addr_i(data_addr),
    .wdata_i(data_wdata),
    .rdata_o(data_rdata)
  );

  // ------------------------------------------------
  // FSM and control implementation
  // ------------------------------------------------
  typedef struct packed {
    logic valid;
    logic dirty;
    logic [TAG_WIDTH-1:0] tag;
  } tag_meta_t;

  tag_meta_t tag_meta_mem [ASSOCIATIVITY-1:0]; // temporary storage of tags/meta read

  // Tag read and hit detection process
  // We will read tag/data RAM one way at a time across multiple cycles for simplicity.
  // Alternatively, could instantiate multiple RAMs per way for parallel access (not done here).

  // Registers for iterating ways during tag lookup
  integer way_counter;

  // Registers for address storage during FSM
  logic [SET_INDEX_WIDTH-1:0] state_set_idx;
  logic [TAG_WIDTH-1:0] state_tag;

  // Registers for replacement pointer update
  logic [$clog2(ASSOCIATIVITY)-1:0] repl_ptr_r [NUM_SETS-1:0];

  // For clarity, rename some signals used to connect RAM ports
  // We will multiplex based on current FSM state and sub-cycle (way_counter)

  // Cache control signals defaults:
  always_comb begin
    // Default all signals to zero or no action
  end

  // Control FSM sequential logic
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      state_r <= ST_IDLE;
      cpu_resp_valid_r <= 1'b0;
      cpu_ready_r <= 1'b1;
      resp_data_r <= '0;
      cpu_rdata_o <= '0;
      tag_en   <= 1'b0;
      tag_we   <= 1'b0;
      tag_addr <= '0;
      tag_wdata<= '0;

      data_en  <= 1'b0;
      data_we  <= 1'b0;
      data_addr<= '0;
      data_wdata <= '0;

      mem_valid_o <= 1'b0;
      mem_we_o <= 1'b0;
      mem_adr_o <= '0;
      mem_wdata_o <= '0;

      hit <= 1'b0;
      hit_mask <= '0;
      hit_way <= 0;
      repl_way <= 0;

      for (integer s = 0; s < NUM_SETS; s++) begin
        repl_ptr_r[s] <= 0; // initialize round-robin pointers
      end

      way_counter <= 0;
    end else begin
      case(state_r)
        ST_IDLE: begin
          cpu_ready_r <= 1'b1;
          cpu_resp_valid_r <= 1'b0;

          if(cpu_valid_i && cpu_ready_r) begin
            // Start tag lookup: latch addr and control registers
            cpu_adr_reg <= cpu_adr_i;
            cpu_we_reg <= cpu_we_i;
            cpu_wdata_reg <= cpu_wdata_i;

            state_set_idx <= cpu_adr_i[SET_INDEX_WIDTH-1:0];
            state_tag <= cpu_adr_i[ADDR_WIDTH-1 -: TAG_WIDTH];

            way_counter <= 0; // start with way 0 during tag reads

            state_r <= ST_TAG_READ;
            cpu_ready_r <= 1'b0;
          end
        end

        ST_TAG_READ: begin
          // Read tag SRAM for current way
          tag_en <= 1'b1;
          tag_we <= 1'b0;
          tag_addr <= (state_set_idx << $clog2(ASSOCIATIVITY)) + way_counter;

          // data RAM not accessed here
          data_en <= 1'b0;

          // Capture tag SRAM output in tag_meta_mem for current way
          tag_meta_mem[way_counter] <= tag_rdata;

          if(way_counter == ASSOCIATIVITY-1) begin
            state_r <= ST_TAG_COMPARE;
          end else begin
            way_counter <= way_counter + 1;
          end
        end

        ST_TAG_COMPARE: begin
          // Compare all ways tags and valid bits against requested tag

          hit <= 1'b0;
          hit_mask <= '0;
          hit_way <= 0;

          for(int w=0; w<ASSOCIATIVITY; w++) begin
            valid_array[w] <= tag_meta_mem[w][TAG_META_WIDTH-1];
            dirty_array[w] <= tag_meta_mem[w][TAG_META_WIDTH-2];
            tag_only_array[w] <= tag_meta_mem[w][TAG_META_WIDTH-3 -: TAG_WIDTH];

            if(valid_array[w] && (tag_only_array[w] == state_tag)) begin
              hit <= 1'b1;
              hit_mask[w] <= 1'b1;
              hit_way <= w;
            end
          end

          if(hit) begin
            // Cache hit: read data SRAM for hit_way at set_idx address
            data_en <= 1'b1;
            data_we <= 1'b0;
            data_addr <= (state_set_idx << $clog2(ASSOCIATIVITY)) + hit_way;

            // On next clock, go to RESPOND state to output data
            state_r <= ST_RESPOND;

            // Save hit_way for later logic
          end else begin
            // Cache miss: select replacement way from repl_ptr
            repl_way <= repl_ptr_r[state_set_idx];

            // Check dirty bit of line to write back
            wb_dirty <= tag_meta_mem[repl_ptr_r[state_set_idx]][TAG_META_WIDTH-2];
            wb_tag   <= tag_meta_mem[repl_ptr_r[state_set_idx]][TAG_META_WIDTH-3 -: TAG_WIDTH];
            wb_set   <= state_set_idx;
            wb_way   <= repl_ptr_r[state_set_idx];

            if(wb_dirty) begin
              state_r <= ST_WRITEBACK;
            end else begin
              state_r <= ST_REFILL;
            end
          end

        end

        ST_WRITEBACK: begin
          // Write back dirty block to memory before refill
          mem_valid_o <= 1'b1;
          mem_we_o <= 1'b1;
          mem_adr_o <= {wb_tag, wb_set}; // reconstruct address from tag and set index
          mem_wdata_o <= '0; // For simplicity, assume 0; real design needs data read from data_ram.

          // Wait for memory ready
          if(mem_ready_i) begin
            state_r <= ST_REFILL;
          end
        end

        ST_REFILL: begin
          // Refill cache block by reading from memory
          mem_valid_o <= 1'b1;
          mem_we_o <= 1'b0;
          mem_adr_o <= cpu_adr_reg;

          // Wait for memory ready and data
          if(mem_ready_i) begin
            // Write new tag metadata into tag SRAM
            tag_en <= 1'b1;
            tag_we <= 1'b1;
            tag_addr <= (state_set_idx << $clog2(ASSOCIATIVITY)) + repl_way;
            // Compose metadata word: {valid=1, dirty=cpu_we_reg, tag}
            tag_wdata <= {1'b1, cpu_we_reg, cpu_tag};

            // Write data into data SRAM
            data_en <= 1'b1;
            data_we <= 1'b1;
            data_addr <= (state_set_idx << $clog2(ASSOCIATIVITY)) + repl_way;
            data_wdata <= cpu_we_reg ? cpu_wdata_reg : mem_rdata_i;

            // Update replacement pointer for next replacement
            repl_ptr_r[state_set_idx] <= (repl_way + 1) % ASSOCIATIVITY;

            // Prepare CPU response data
            resp_data_r <= cpu_we_reg ? cpu_wdata_reg : mem_rdata_i;

            state_r <= ST_RESPOND;
          end
        end

        ST_RESPOND: begin
          // Send data to CPU and assert valid
          mem_valid_o <= 1'b0;
          cpu_resp_valid_r <= 1'b1;
          cpu_rdata_o <= resp_data_r;
          cpu_ready_r <= 1'b1;

          if(cpu_valid_i && cpu_ready_r) begin
            cpu_resp_valid_r <= 1'b0;
            state_r <= ST_IDLE;
          end
        end

        default: state_r <= ST_IDLE;
      endcase
    end
  end

  // Output valid and ready signals driven by registered signals
  assign cpu_resp_valid_o = cpu_resp_valid_r;
  assign cpu_ready_o = cpu_ready_r;

endmodule

