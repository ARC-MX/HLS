############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project CONV_LAYER
open_solution "original" -flow_target vivado
set_part {xcvu11p-flga2577-1-e}
create_clock -period 10 -name default
#source "./CONV_LAYER/original/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
