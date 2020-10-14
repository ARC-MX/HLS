############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project CONV_LAYER
set_top packed_conv_paper
add_files CONV_LAYER/buf2pe.cpp
add_files -tb CONV_LAYER/test_buf2pe.cpp
open_solution "original" -flow_target vivado
set_part {xcvu11p-flga2577-1-e}
create_clock -period 10 -name default
source "./CONV_LAYER/original/directives.tcl"
csim_design -ldflags {-Wl,--stack,10485760}
csynth_design
cosim_design -ldflags {-Wl,--stack,10485760}
export_design -format ip_catalog
