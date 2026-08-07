puts ""
puts "=== flexsoc OpenSTA init ==="
puts "read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}"
read_liberty {/home/eneadim/github/flexsoc/pdks/sky130/lib/sky130_fd_sc_hd__ss_100C_1v40.lib}
puts "read_verilog {/home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/syn/spi_host_synth.v}"
read_verilog {/home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/syn/spi_host_synth.v}
puts "link_design spi_host"
link_design spi_host
puts "read_sdc {/home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sky130/spi_host.sdc}"
read_sdc {/home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sky130/spi_host.sdc}

puts "=== Write SDF ==="
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_tt.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_tt.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_ss.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_ss.sdf
puts "write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_ff.sdf"
write_sdf -divider . -include_typ /home/eneadim/github/flexsoc/workspace/runs/spi_host/dev/signoff/sdf/spi_host_ff.sdf
