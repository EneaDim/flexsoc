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
puts "read_liberty -corner Slowest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ss_100C_1v40.lib"
read_liberty -corner Slowest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ss_100C_1v40.lib
puts "read_liberty -corner Typical /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__tt_025C_1v80.lib"
read_liberty -corner Typical /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__tt_025C_1v80.lib
puts "read_liberty -corner Fastest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"
read_liberty -corner Fastest /home/eneadim/github/flexsoc/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib

puts ""
puts "==========================================================================="
puts "Read verilog and link top module"
puts "==========================================================================="
puts ""
puts "read_verilog /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/syn/my_ip_synth.v"
puts "link_design my_ip"
read_verilog /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/syn/my_ip_synth.v
link_design my_ip

puts ""
puts "==========================================================================="
puts "Read SDC"
puts "==========================================================================="
puts ""
puts "read_sdc /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/openroad/my_ip.sdc"
read_sdc /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/openroad/my_ip.sdc
puts ""

puts "==========================================================================="
puts "(Hold) report_checks -path_delay min"
puts "==========================================================================="
foreach corner [sta::corners] {
    puts ""
    puts "======================= [$corner name] Corner ==================================="
    report_checks -slack_max -0.01 -path_delay min         -fields {slew cap input nets fanout}         -format full_clock_expanded         -group_path_count 1000         -corner [$corner name]
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
    report_checks -slack_max -0.01 -path_delay max         -fields {slew cap input nets fanout}         -format full_clock_expanded         -group_path_count 1000         -corner [$corner name]
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
    puts "======================= [$corner name] Corner ==================================="
    report_checks -slack_max -0.01 -unconstrained         -fields {slew cap input nets fanout}         -format full_clock_expanded         -corner [$corner name]
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