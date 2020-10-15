############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_top -name pe "pe"
set_directive_pipeline -II 1 "pe/PIPELINE"
set_directive_array_partition -type complete -dim 1 "pe" input_registers
set_directive_array_partition -type complete -dim 1 "pe" inner_fifos
set_directive_array_partition -type complete -dim 2 "pe" input_registers
set_directive_array_partition -type complete -dim 1 "pe" input_buffers
set_directive_array_partition -type complete -dim 1 "pe" pe_input_stream
set_directive_stream -depth 6 -dim 1 "pe" inner_fifos
set_directive_interface -mode bram -storage_type ram_t2p "pe" input_buffers
