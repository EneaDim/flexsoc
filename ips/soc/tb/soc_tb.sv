// Timescale 
`timescale 1ns/1ps 
// Include files 
`include "tb/include_soc_tb.sv"

module soc_tb;
  //Parameters
  parameter int CLK_PERIOD = 20; // Clock period in ns
  // Inputs
  reg clk_i;
  reg rst_ni;
  reg cio_rx_i;
  reg [3:0] cio_gpio_i;
  // Outputs
  wire cio_tx_o;
  wire cio_tx_en_o;
  wire [1:0] cio_pwm_o;
  wire [1:0] cio_pwm_en_o;
  wire [3:0] cio_gpio_o;
  wire [3:0] cio_gpio_en_o;

  integer error_count;


  // Device Under Test Instance
  soc
  u_soc (
    .clk_i,
    .rst_ni,
    .cio_rx_i,
    .cio_gpio_i,
    .cio_tx_o,
    .cio_tx_en_o,
    .cio_pwm_o,
    .cio_pwm_en_o,
    .cio_gpio_o,
    .cio_gpio_en_o
  );

  initial begin
    clk_i = 0;
    forever #(CLK_PERIOD / 2) clk_i = ~clk_i;
  end

  // Dump vcd file 
  initial begin
    `ifndef SYN
      $dumpfile("sim/dump_soc.vcd");
    `else
      $dumpfile("sim/dump_soc_syn.vcd");
    `endif
    $dumpvars(0, soc_tb);
  end
  
  // Convenienza: invia un byte UART (usa send_pattern)
  task automatic uart_send_byte(input logic [7:0] b);
    begin
      // Start bit
      cio_rx_i = 1'b0; 
      #8680; // Wait for half a bit period
      // Send each bit of the pattern
      for (int i = 0; i < 8; i++) begin
        cio_rx_i = b[i]; // Send each bit of the pattern
        #8680; // Wait for half a bit period
      end
      // Stop bit
      cio_rx_i = 1'b1; 
      #86800; // Wait for half a bit period
    end
  endtask
  
  // Frame helper: manda un 32b LSB-first
  task automatic uart_send_word32(input logic [31:0] w);
    uart_send_byte(w[7:0]);
    uart_send_byte(w[15:8]);
    uart_send_byte(w[23:16]);
    uart_send_byte(w[31:24]);
  endtask
  
  // WRITE: A5 | 01 | 01 | {0000,BE} | 00 | ADDR(4) | DATA(4)
  task automatic uart_write32(input logic [31:0] addr, input logic [31:0] data, input logic [3:0] be = 4'hF);
    begin
      uart_send_byte(8'hA5);      // SOF
      uart_send_byte(8'h01);      // VER
      uart_send_byte(8'h01);      // OP=WRITE
      uart_send_byte({4'h0,be});  // BE
      uart_send_word32(addr);     // ADDR (LSB-first)
      uart_send_word32(data);     // DATA (LSB-first)
    end
  endtask
  
  // READ: A5 | 01 | 00 | {0000,1111} | 00 | ADDR(4)
  task automatic uart_read32(input logic [31:0] addr);
    begin
      uart_send_byte(8'hA5);     // SOF
      uart_send_byte(8'h01);     // VER
      uart_send_byte(8'h00);     // OP=READ
      uart_send_byte(8'h0F);     // BE (ignored for read)
      uart_send_byte(8'h00);     // RSV
      uart_send_word32(addr);    // ADDR (LSB-first)
    end
  endtask
  
  // ===================
  // Indirizzi (ADATTA!)
  // ===================
  localparam logic [31:0] UART_BASE   = 32'h8000_0000; // <-- metti i tuoi
  localparam logic [31:0] PWM_BASE    = 32'h8002_0000;
  localparam logic [31:0] GPIO_BASE   = 32'h8004_0000;
  localparam logic [31:0] TIMER_BASE  = 32'h8006_0000;
  
  // Offsets (ADATTA ai tuoi registri reali)
  localparam logic [31:0] UART_CTRL_OFF   = 32'h0000_0010;  // CTRL: abilita tx/rx, nco ecc.
  //////////////////////////////////////////////////////////////////////////////////////////
  localparam logic [31:0] PWM_CFG_OFF     = 32'h0000_0004;  // duty del canale 0
  localparam logic [31:0] PWM_EN_OFF      = 32'h0000_0008;  // enable pwm block
  localparam logic [31:0] PWM_PHASE_OFF   = 32'h0000_0010;  // duty del canale 0
  localparam logic [31:0] PWM_DUTY0_OFF   = 32'h0000_0014;  // duty del canale 0
  //////////////////////////////////////////////////////////////////////////////////////////
  localparam logic [31:0] GPIO_INT_EN     = 32'h0000_0004;  // enable bit nello SPI host
  localparam logic [31:0] GPIO_INT_RISE   = 32'h0000_0028;  // enable bit nello SPI host
  //////////////////////////////////////////////////////////////////////////////////////////
  
  initial begin
    error_count = 0;
  end

  // ===================
  // Stimolo principale
  // ===================
  initial begin
    // Init inputs
    rst_ni = 0;
    cio_rx_i = 1'b1;
    cio_gpio_i = '0;
    // Asynch Reset
    #(CLK_PERIOD);
    rst_ni = 1;
    #(CLK_PERIOD*20);
  
    // 1) Abilita TX (e RX) della UART + set NCO coerente al tuo bit-banging (qui irrilevante per RX; serve per TX)
    //    Se la tua UART al reset ha RX già abilitata, questo step serve soprattutto ad accendere il TX.
    //assign ctrl_val = uart_ctrl_val(/*tx*/1, /*rx*/1, /*parity_en*/0, /*parity_odd*/0, /*nco*/16'd0);
    uart_write32(UART_BASE + UART_CTRL_OFF, 32'h0970_0001); // For 100MHz fclk
    #(CLK_PERIOD*2000);
  
    // 2) Imposta duty cycle PWM (esempio 50%) e abilita PWM
    uart_write32(PWM_BASE + PWM_CFG_OFF,   32'hB8000010);
    uart_write32(PWM_BASE + PWM_PHASE_OFF, 32'h0000_7FFF);
    uart_write32(PWM_BASE + PWM_EN_OFF,   32'h1);       // enable
    #(CLK_PERIOD*2000);

    // Enable interrupt in GPIO
    uart_write32(GPIO_BASE + GPIO_INT_EN,   32'h1);       // enable
    uart_write32(GPIO_BASE + GPIO_INT_RISE,   32'h1);       // enable
    #(CLK_PERIOD*2000);

    // Raise GPIO pin
    cio_gpio_i = 'h1;
    #(CLK_PERIOD*2000);
  
    // fine
    #(CLK_PERIOD*80000);
    $finish;
  end
endmodule
