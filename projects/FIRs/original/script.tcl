############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FIRs
set_top top
add_files ../srcs/FIRs.cpp
add_files -tb ../srcs/FIRs_test.cpp
open_solution "original" -flow_target vitis
set_part {xcu200-fsgd2104-2-e}
create_clock -period 1.5 -name default
config_interface  -default_slave_interface s_axilite -m_axi_addr64 -m_axi_alignment_byte_size 64  -m_axi_latency 64 -m_axi_max_widen_bitwidth 512 -m_axi_offset off -register_io off 
config_rtl   -module_auto_prefix  -register_reset_num 3 -reset control  -reset_level high
source "./FIRs/original/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format xo
