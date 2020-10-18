############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project PING_PONG
set_top top
add_files ../srcs/ping_pong.cpp
open_solution "original" -flow_target vivado
set_part {xczu7ev-ffvc1156-2-e}
create_clock -period 10 -name default
source "./PING_PONG/original/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
