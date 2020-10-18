############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project CONV_LAYER
set_top top
add_files CONV_LAYER/buf2pe_indexing.cpp
add_files -tb CONV_LAYER/test_buf2pe.cpp -cflags "-Wno-unknown-pragmas"
open_solution "SOTA" -flow_target vivado
set_part {xcu200-fsgd2104-2-e}
create_clock -period 3 -name default
source "./CONV_LAYER/SOTA/directives.tcl"
csim_design -ldflags {-Wl,--stack,10485760}
csynth_design
cosim_design -ldflags {-Wl,--stack,10485760}
export_design -rtl verilog -format ip_catalog
