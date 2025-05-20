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
puts "read_verilog syn/cache_wrapper_synth.v"
puts "link_design cache_wrapper"
read_verilog syn/cache_wrapper_synth.v
link_design cache_wrapper
puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc signoff/cache_wrapper.sdc"
read_sdc signoff/cache_wrapper.sdc
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
puts "read_vcd -scope cache_wrapper_tb/u_cache_wrapper sim/dump_cache_wrapper.vcd"
read_vcd -scope cache_wrapper_tb/u_cache_wrapper sim/dump_cache_wrapper.vcd
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_power -corner [$corner name]
    puts ""
}
