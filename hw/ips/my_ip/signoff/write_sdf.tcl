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
puts "Write SDF files for each corner"
puts "==========================================================================="
puts ""
puts "write_sdf -corner Typical -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_tt.sdf"
write_sdf -corner Typical -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_tt.sdf

puts "write_sdf -corner Slowest -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_ss.sdf"
write_sdf -corner Slowest -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_ss.sdf

puts "write_sdf -corner Fastest -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_ff.sdf"
write_sdf -corner Fastest -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/my_ip/dev1/signoff/sdf/my_ip_ff.sdf

