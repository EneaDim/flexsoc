module cocotb_iverilog_dump();
initial begin
    $dumpfile("sim_build/gl/soc_tb.fst");
    $dumpvars(0, soc_tb);
end
endmodule
