# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set axilite_register_dict [dict create]
# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 20 \
    name weight_stream_V \
    type fifo \
    dir I \
    reset_level 1 \
    sync_rst true \
    corename dc_weight_stream_V \
    op interface \
    ports { weight_stream_V_dout { I 8 vector } weight_stream_V_empty_n { I 1 bit } weight_stream_V_read { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 21 \
    name pe_input_stream_V_0 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_0 \
    op interface \
    ports { pe_input_stream_V_0_din { O 8 vector } pe_input_stream_V_0_full_n { I 1 bit } pe_input_stream_V_0_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 22 \
    name pe_input_stream_V_1 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_1 \
    op interface \
    ports { pe_input_stream_V_1_din { O 8 vector } pe_input_stream_V_1_full_n { I 1 bit } pe_input_stream_V_1_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 23 \
    name pe_input_stream_V_2 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_2 \
    op interface \
    ports { pe_input_stream_V_2_din { O 8 vector } pe_input_stream_V_2_full_n { I 1 bit } pe_input_stream_V_2_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 24 \
    name pe_input_stream_V_3 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_3 \
    op interface \
    ports { pe_input_stream_V_3_din { O 8 vector } pe_input_stream_V_3_full_n { I 1 bit } pe_input_stream_V_3_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 25 \
    name pe_input_stream_V_4 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_4 \
    op interface \
    ports { pe_input_stream_V_4_din { O 8 vector } pe_input_stream_V_4_full_n { I 1 bit } pe_input_stream_V_4_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 26 \
    name pe_input_stream_V_5 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_5 \
    op interface \
    ports { pe_input_stream_V_5_din { O 8 vector } pe_input_stream_V_5_full_n { I 1 bit } pe_input_stream_V_5_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 27 \
    name pe_input_stream_V_6 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_6 \
    op interface \
    ports { pe_input_stream_V_6_din { O 8 vector } pe_input_stream_V_6_full_n { I 1 bit } pe_input_stream_V_6_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 28 \
    name pe_input_stream_V_7 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_7 \
    op interface \
    ports { pe_input_stream_V_7_din { O 8 vector } pe_input_stream_V_7_full_n { I 1 bit } pe_input_stream_V_7_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 29 \
    name pe_input_stream_V_8 \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_input_stream_V_8 \
    op interface \
    ports { pe_input_stream_V_8_din { O 8 vector } pe_input_stream_V_8_full_n { I 1 bit } pe_input_stream_V_8_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id 30 \
    name pe_weight_stream_V \
    type fifo \
    dir O \
    reset_level 1 \
    sync_rst true \
    corename dc_pe_weight_stream_V \
    op interface \
    ports { pe_weight_stream_V_din { O 8 vector } pe_weight_stream_V_full_n { I 1 bit } pe_weight_stream_V_write { O 1 bit } } \
} "
}

# Direct connection:
if {${::AESL::PGuard_autoexp_gen}} {
eval "cg_default_interface_gen_dc { \
    id -1 \
    name ap_ctrl \
    type ap_ctrl \
    reset_level 1 \
    sync_rst true \
    corename ap_ctrl \
    op interface \
    ports { ap_start { I 1 bit } ap_ready { O 1 bit } ap_done { O 1 bit } ap_idle { O 1 bit } } \
} "
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -2 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -3 \
    name ${PortName} \
    reset_level 1 \
    sync_rst true \
    corename apif_ap_rst \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


