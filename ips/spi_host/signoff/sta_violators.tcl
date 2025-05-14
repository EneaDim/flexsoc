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
puts "==========================================================================="
puts "(Hold) report_checks -path_delay min"
puts "==========================================================================="
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ===================================
"
    report_checks -slack_max -0.01 -path_delay min -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]
    puts ""
    set ws [sta::format_time [sta::worst_slack_corner $corner "min"] 4]
    puts "worst slack hold corner [$corner name]: $ws"
    puts ""
}
puts "==========================================================================="
puts "(Setup) report_checks -path_delay max"
puts "============================================================================"
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_checks -slack_max -0.01 -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]
    puts ""
    set ws [sta::format_time [sta::worst_slack_corner $corner "max"] 4]
    puts "worst slack setup corner [$corner name]: $ws"
    puts ""
}
puts "==========================================================================="
puts "(Unconstrained) report_checks -unconstrained"
puts "==========================================================================="
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ===================================
"
    report_checks -slack_max -0.01 -unconstrained -fields {slew cap input nets fanout} -format full_clock_expanded -corner [$corner name]
    puts ""
}
puts "==========================================================================="
puts "report_worst_slack -max (Setup)"
puts "============================================================================"
report_worst_slack -max
puts ""
puts "==========================================================================="
puts "report_worst_slack -min (Hold)"
puts "============================================================================"
report_worst_slack -min
puts ""
