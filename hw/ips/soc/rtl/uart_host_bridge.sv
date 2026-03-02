module uart_host_bridge (
  input  logic clk_i,
  input  logic rst_ni,

  // Stream dalla UART core
  input  logic       rx_valid_i,
  input  logic [7:0] rx_data_i,
  output logic       rx_pop_o,

  // ===== Stream TX verso UART core =====
  output logic        tx_valid_o,
  output logic [7:0]  tx_data_o,
  input  logic        tx_ready_i,

  // ===== Interfaccia "host" verso tlul_adapter_host =====
  output logic        req_o,
  input  logic        gnt_i,
  output logic [31:0] addr_o,
  output logic        we_o,
  output logic [31:0] wdata_o,
  output logic [3:0]  be_o,

  // Risposta dall'adapter (già dopo il fabric)
  input  logic        valid_i,
  input  logic [31:0] rdata_i,
  input  logic        err_i

);

  // === costanti ===
  localparam byte SOF_REQ   = 8'hA5;
  localparam byte SOF_RESP  = 8'h5A;
  localparam byte PROTO_VER = 8'h01;
  localparam byte OP_RD     = 8'd0;
  localparam byte OP_WR     = 8'd1;

  // === RX parser (come il tuo) ===
  typedef enum logic [2:0] {
    RXF_IDLE     = 3'b000, 
    RXF_HDR      = 3'b001,
    RXF_ADDR     = 3'b010,
    RXF_WDATA    = 3'b011,
    RXF_LAUNCH   = 3'b100,
    RXF_WAIT_GNT = 3'b101,
    RXF_WAIT_RV  = 3'b110 
  } rxf_e;

  rxf_e rxf_st_q, rxf_st_d;

  logic [1:0]  idx_q, idx_d;
  logic [31:0] sh_q,  sh_d;
  byte         op_q,  op_d;
  byte         bebyte_q, bebyte_d;

  logic [31:0] addr_q, addr_d;
  logic [31:0] wdata_q, wdata_d;
  logic [3:0]  be_q, be_d;
  logic        we_q, we_d;
  logic        req_q, req_d;

  // holding risposta
  logic [31:0] rdata_q, rdata_d;
  logic        any_err_q, any_err_d;

  // === TX serializzatore con idx ===
  typedef enum logic [1:0] { TX_IDLE, TX_SEND } txf_e;
  txf_e tx_st_q, tx_st_d;
  logic [3:0] tx_idx_q, tx_idx_d; // conta i byte inviati

  // Come prima: consumiamo byte solo negli stati attivi del parser
  assign rx_pop_o = (rxf_st_q != RXF_IDLE) && rx_valid_i;

  // ====== FF ======
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      rxf_st_q  <= RXF_IDLE;
      idx_q     <= '0;
      sh_q      <= '0;
      op_q      <= '0;
      bebyte_q  <= 8'hF;
      addr_q    <= '0;
      wdata_q   <= '0;
      be_q      <= 4'hF;
      we_q      <= 1'b0;
      req_q     <= 1'b0;
      rdata_q   <= '0;
      any_err_q <= 1'b0;
      tx_st_q   <= TX_IDLE;
      tx_idx_q  <= '0;
    end else begin
      rxf_st_q  <= rxf_st_d;
      idx_q     <= idx_d;
      sh_q      <= sh_d;
      op_q      <= op_d;
      bebyte_q  <= bebyte_d;
      addr_q    <= addr_d;
      wdata_q   <= wdata_d;
      be_q      <= be_d;
      we_q      <= we_d;
      req_q     <= req_d;
      rdata_q   <= rdata_d;
      any_err_q <= any_err_d;
      tx_st_q   <= tx_st_d;
      tx_idx_q  <= tx_idx_d;
    end
  end

  // ====== combinational ======
  always_comb begin
    // default hold
    rxf_st_d  = rxf_st_q;
    idx_d     = idx_q;
    sh_d      = sh_q;
    op_d      = op_q;
    bebyte_d  = bebyte_q;
    addr_d    = addr_q;
    wdata_d   = wdata_q;
    be_d      = be_q;
    we_d      = we_q;
    req_d     = req_q;
    rdata_d   = rdata_q;
    any_err_d = any_err_q;
    tx_st_d   = tx_st_q;
    tx_idx_d  = tx_idx_q;
    tx_valid_o= 1'b0;
    tx_data_o = 8'h00;

    // ===== Parser / Bus =====
    unique case (rxf_st_q)
      RXF_IDLE: begin
        idx_d = '0; sh_d = '0; we_d = 1'b0;
        // Non consumiamo qui: solo transizione su SOF
        if (rx_valid_i && rx_data_i == SOF_REQ) begin
          rxf_st_d = RXF_HDR;
        end
      end

      RXF_HDR: begin
        if (rx_valid_i) begin
          case (idx_q)
            2'd0: /* A5 or 5A */;
            2'd1: op_d     = rx_data_i;
            2'd2: bebyte_d = rx_data_i;
            2'd3: /**/;
          endcase
          if (idx_q==2'd2) begin
            idx_d    = '0;
            rxf_st_d = RXF_ADDR;
          end else idx_d = idx_q + 2'd1;
        end
      end

      RXF_ADDR: begin
        if (rx_valid_i) begin
          sh_d = {rx_data_i, sh_q[31:8]}; // MSB-first
          if (idx_q==2'd3) begin
            addr_d = {rx_data_i, sh_q[31:8]};
            if (op_q==OP_WR) begin
              idx_d    = '0;
              rxf_st_d = RXF_WDATA;
            end else begin
              we_d     = 1'b0;   // READ
              be_d     = 4'hF;
              wdata_d  = '0;
              rxf_st_d = RXF_LAUNCH;
            end
          end else idx_d = idx_q + 2'd1;
        end
      end

      RXF_WDATA: begin
        if (rx_valid_i) begin
          sh_d = {rx_data_i, sh_q[31:8]}; // MSB-first
          if (idx_q==2'd3) begin
            wdata_d  = {rx_data_i, sh_q[31:8]};
            be_d     = bebyte_q[3:0];
            we_d     = 1'b1;     // WRITE
            rxf_st_d = RXF_LAUNCH;
          end else idx_d = idx_q + 2'd1;
        end
      end

      RXF_LAUNCH: begin
        req_d    = 1'b1;
        rxf_st_d = RXF_WAIT_GNT;
      end

      RXF_WAIT_GNT: begin
        if (req_q && gnt_i) begin
          req_d    = 1'b0;
          rxf_st_d = RXF_WAIT_RV; // aspetta sempre la risposta del fabric
        end
      end

      RXF_WAIT_RV: begin
        if (valid_i) begin
          rdata_d   = rdata_i;
          any_err_d = err_i;
          // WRITE → finito; READ → manda risposta su UART
          if (op_q == OP_WR) begin
            rxf_st_d = RXF_IDLE;         // nessun TX per le write
          end else begin
            // prepara il TX stream
            tx_st_d  = TX_SEND;
            tx_idx_d = 4'd0;
            rxf_st_d = RXF_IDLE;         // parser libero per nuovo comando
          end
        end
      end
    endcase

    // ===== TX: un solo stato con indice =====
    if (tx_st_q == TX_SEND) begin
      if (tx_ready_i) begin
        tx_valid_o = 1'b1;
        unique case (tx_idx_q)
          4'd0:  tx_data_o = SOF_RESP;
          4'd1:  tx_data_o = PROTO_VER;
          4'd2:  tx_data_o = op_q;                     // echo
          4'd3:  tx_data_o = {7'b0, any_err_q};        // status
          4'd4:  tx_data_o = rdata_q[31:24];           // MSB
          4'd5:  tx_data_o = rdata_q[23:16];
          4'd6:  tx_data_o = rdata_q[15:8];
          4'd7:  tx_data_o = rdata_q[7:0];             // LSB
          default: tx_data_o = 8'h00;
        endcase

        // avanzamento
        if (tx_idx_q == 4'd7) begin
          tx_idx_d = '0;
          tx_st_d  = TX_IDLE;
        end else begin
          tx_idx_d = tx_idx_q + 4'd1;
          // per sicurezza: se fosse una WRITE, invia solo fino a STATUS (non dovrebbe capitare)
          if (op_q == OP_WR && tx_idx_q == 4'd3) begin
            tx_idx_d = '0;
            tx_st_d  = TX_IDLE;
          end
        end
      end
    end
  end

  // ===== Uscite verso TL host =====
  assign req_o    = req_q;
  assign addr_o   = addr_q & 32'hFFFF_FFFC;
  assign we_o     = we_q;
  assign wdata_o  = wdata_q;
  assign be_o     = be_q;

endmodule

