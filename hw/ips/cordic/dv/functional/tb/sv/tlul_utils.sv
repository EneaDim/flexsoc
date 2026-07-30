class tlul_utils;

  virtual tlul_if.drv drv_if;

  function new(virtual tlul_if.drv drv_if);
    this.drv_if = drv_if;
  endfunction

  task automatic cycle();
    @(posedge drv_if.clk_i);
  endtask

  task automatic drive_idle();
    drv_if.h2d.a_valid   <= 1'b0;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= '0;
    drv_if.h2d.a_size    <= '0;
    drv_if.h2d.a_source  <= '0;
    drv_if.h2d.a_address <= '0;
    drv_if.h2d.a_mask    <= '0;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;
    drv_if.h2d.d_ready   <= 1'b0;
  endtask

  task automatic init();
    drive_idle();
    cycle();
  endtask

  task automatic tlul_write(input logic [top_pkg::TL_AW-1:0]  addr,
                            input logic [top_pkg::TL_DW-1:0]  data,
                            input logic [top_pkg::TL_AIW-1:0] source,
                            input logic [top_pkg::TL_DBW-1:0] mask = '1);

    $display("[%0t] TLUL WRITE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::PutFullData;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= mask;
    drv_if.h2d.a_data    <= data;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL WRITE ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL WRITE DONE: Addr = 0x%08x", $time, addr);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

  task automatic tlul_read(input  logic [top_pkg::TL_AW-1:0]  addr,
                           output logic [top_pkg::TL_DW-1:0]  data,
                           input  logic [top_pkg::TL_AIW-1:0] source);

    $display("[%0t] TLUL READ: Addr = 0x%08x", $time, addr);
    data = '0;

    drive_idle();
    cycle();

    drv_if.h2d.d_ready   <= 1'b1;
    drv_if.h2d.a_valid   <= 1'b1;
    drv_if.h2d.a_opcode  <= tlul_pkg::Get;
    drv_if.h2d.a_param   <= 3'b000;
    drv_if.h2d.a_size    <= 2;
    drv_if.h2d.a_source  <= source;
    drv_if.h2d.a_address <= addr;
    drv_if.h2d.a_mask    <= 4'b1111;
    drv_if.h2d.a_data    <= '0;
    drv_if.h2d.a_user    <= '0;

    do cycle(); while (!drv_if.d2h.a_ready);
    drv_if.h2d.a_valid <= 1'b0;

    do cycle(); while (!drv_if.d2h.d_valid);
    data = drv_if.d2h.d_data;

    if (drv_if.d2h.d_error) begin
      $display("[%0t] TLUL READ ERROR: Addr = 0x%08x, d_error = 1", $time, addr);
    end else begin
      $display("[%0t] TLUL READ DONE: Addr = 0x%08x, Data = 0x%08x", $time, addr, data);
    end

    cycle();
    drive_idle();
    cycle();

    #1;
  endtask

endclass
