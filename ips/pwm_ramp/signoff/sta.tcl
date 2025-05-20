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
puts "read_verilog syn/pwm_ramp_synth.v"
puts "link_design pwm_ramp"
read_verilog syn/pwm_ramp_synth.v
link_design pwm_ramp
puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc signoff/pwm_ramp.sdc"
read_sdc signoff/pwm_ramp.sdc
puts ""
puts "==========================================================================="
puts "(Hold) report_checks -path_delay min"
puts "==========================================================================="
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ===================================
"
    report_checks -sort_by_slack -path_delay min -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]
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
    report_checks -sort_by_slack -path_delay max -fields {slew cap input nets fanout} -format full_clock_expanded -group_path_count 1000 -corner [$corner name]
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
    report_checks -unconstrained -fields {slew cap input nets fanout} -format full_clock_expanded -corner [$corner name]
    puts ""
}
puts "==========================================================================="
puts "(All Violators) report_check_types -max_slew -max_cap -max_fanout -violators"
puts "============================================================================"
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_check_types -max_slew -max_capacitance -max_fanout -violators -corner [$corner name]
    puts ""
    set net "NULL"
    set violators 1
    set min_max "max"
    set slew_pins [sta::check_slew_limits $net $violators $corner $min_max]
    puts "max slew violations count [$corner name]: [llength $slew_pins]"
    set fanout_pins [sta::check_fanout_limits $net $violators $min_max]
    puts "max fanout violations count [$corner name]: [llength $fanout_pins]"
    set cap_pins [sta::check_capacitance_limits $net $violators $corner $min_max]
    puts "max cap violations count [$corner name]: [llength $cap_pins]"
    puts ""
}
puts "==========================================================================="
puts "report_parasitic_annotation -report_unannotated"
puts "============================================================================"
report_parasitic_annotation -report_unannotated
puts ""
puts "==========================================================================="
puts "max slew violation count [sta::max_slew_violation_count]"
puts "max fanout violation count [sta::max_fanout_violation_count]"
puts "max cap violation count [sta::max_capacitance_violation_count]"
puts "============================================================================"
puts ""
puts "==========================================================================="
puts "check_setup -verbose -unconstrained_endpoints -multiple_clock -no_clock -no_input_delay -loops -generated_clocks"
puts "==========================================================================="
check_setup -verbose -unconstrained_endpoints -multiple_clock -no_clock -no_input_delay -loops -generated_clocks
puts "============================================================================"
puts "(Clock Skew) report_clock_skew"
puts "============================================================================"
report_clock_skew
puts ""
puts "==========================================================================="
puts "report_tns"
puts "============================================================================"
report_tns
puts ""
puts "==========================================================================="
puts "report_wns"
puts "============================================================================"
report_wns
puts ""
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
