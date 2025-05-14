puts ""
puts "==========================================================================="
puts "Define corners Slowest Typical Fastest"
puts "==========================================================================="
puts ""
puts "define_corners Slowest Typical Fastest"
define_corners Slowest Typical Fastest
puts ""
puts "==========================================================================="
puts "Read liberty files"
puts "==========================================================================="
puts ""
puts "read_liberty -corner Slowest lib/sky130_fd_sc_hd__ss_100C_1v40.lib"
read_liberty -corner Slowest lib/sky130_fd_sc_hd__ss_100C_1v40.lib
puts "read_liberty -corner Typical lib/sky130_fd_sc_hd__tt_025C_1v80.lib"
read_liberty -corner Typical lib/sky130_fd_sc_hd__tt_025C_1v80.lib
puts "read_liberty -corner Fastest lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"
read_liberty -corner Fastest lib/sky130_fd_sc_hd__ff_n40C_1v95.lib
puts ""
puts "==========================================================================="
puts "Read verilog and link top module"
puts "==========================================================================="
puts ""
puts "read_verilog syn/spi_host_synth.v"
puts "link_design spi_host"
read_verilog syn/spi_host_synth.v
link_design spi_host
puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc signoff/spi_host.sdc"
read_sdc signoff/spi_host.sdc
puts ""
puts ""
puts "==========================================================================="
puts "(Probability Power Analysis) report_power"
puts "============================================================================"
puts "set_power_activity -input -activity .10"
puts "set_power_activity -input_port rst_ni -activity 0"
set_power_activity -input -activity .10
set_power_activity -input_port rst_ni -activity 0
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}
puts "==========================================================================="
puts "(VCD Power Analysis) report_power"
puts "============================================================================"
puts "read_vcd -scope spi_host_tb/u_spi_host sim/dump_spi_host.vcd"
read_vcd -scope spi_host_tb/u_spi_host sim/dump_spi_host.vcd
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}
