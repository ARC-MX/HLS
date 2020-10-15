set moduleName pe
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {pe}
set C_modelType { void 0 }
set C_modelArgList {
	{ weight_stream_V int 8 regular {fifo 0 volatile }  }
	{ pe_weight_stream_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_1_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_2_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_3_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_4_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_5_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_6_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_7_V_V int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_8_V_V int 8 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "weight_stream_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "pe_weight_stream_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_1_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_2_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_3_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_4_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_5_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_6_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_7_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "pe_input_stream_8_V_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 39
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ weight_stream_V_dout sc_in sc_lv 8 signal 0 } 
	{ weight_stream_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ weight_stream_V_read sc_out sc_logic 1 signal 0 } 
	{ pe_weight_stream_V_din sc_out sc_lv 8 signal 1 } 
	{ pe_weight_stream_V_full_n sc_in sc_logic 1 signal 1 } 
	{ pe_weight_stream_V_write sc_out sc_logic 1 signal 1 } 
	{ pe_input_stream_V_V_din sc_out sc_lv 8 signal 2 } 
	{ pe_input_stream_V_V_full_n sc_in sc_logic 1 signal 2 } 
	{ pe_input_stream_V_V_write sc_out sc_logic 1 signal 2 } 
	{ pe_input_stream_1_V_V_din sc_out sc_lv 8 signal 3 } 
	{ pe_input_stream_1_V_V_full_n sc_in sc_logic 1 signal 3 } 
	{ pe_input_stream_1_V_V_write sc_out sc_logic 1 signal 3 } 
	{ pe_input_stream_2_V_V_din sc_out sc_lv 8 signal 4 } 
	{ pe_input_stream_2_V_V_full_n sc_in sc_logic 1 signal 4 } 
	{ pe_input_stream_2_V_V_write sc_out sc_logic 1 signal 4 } 
	{ pe_input_stream_3_V_V_din sc_out sc_lv 8 signal 5 } 
	{ pe_input_stream_3_V_V_full_n sc_in sc_logic 1 signal 5 } 
	{ pe_input_stream_3_V_V_write sc_out sc_logic 1 signal 5 } 
	{ pe_input_stream_4_V_V_din sc_out sc_lv 8 signal 6 } 
	{ pe_input_stream_4_V_V_full_n sc_in sc_logic 1 signal 6 } 
	{ pe_input_stream_4_V_V_write sc_out sc_logic 1 signal 6 } 
	{ pe_input_stream_5_V_V_din sc_out sc_lv 8 signal 7 } 
	{ pe_input_stream_5_V_V_full_n sc_in sc_logic 1 signal 7 } 
	{ pe_input_stream_5_V_V_write sc_out sc_logic 1 signal 7 } 
	{ pe_input_stream_6_V_V_din sc_out sc_lv 8 signal 8 } 
	{ pe_input_stream_6_V_V_full_n sc_in sc_logic 1 signal 8 } 
	{ pe_input_stream_6_V_V_write sc_out sc_logic 1 signal 8 } 
	{ pe_input_stream_7_V_V_din sc_out sc_lv 8 signal 9 } 
	{ pe_input_stream_7_V_V_full_n sc_in sc_logic 1 signal 9 } 
	{ pe_input_stream_7_V_V_write sc_out sc_logic 1 signal 9 } 
	{ pe_input_stream_8_V_V_din sc_out sc_lv 8 signal 10 } 
	{ pe_input_stream_8_V_V_full_n sc_in sc_logic 1 signal 10 } 
	{ pe_input_stream_8_V_V_write sc_out sc_logic 1 signal 10 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "weight_stream_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "dout" }} , 
 	{ "name": "weight_stream_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "empty_n" }} , 
 	{ "name": "weight_stream_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "read" }} , 
 	{ "name": "pe_weight_stream_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "din" }} , 
 	{ "name": "pe_weight_stream_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "full_n" }} , 
 	{ "name": "pe_weight_stream_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_1_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_1_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_1_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_1_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_1_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_1_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_2_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_2_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_2_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_2_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_2_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_2_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_3_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_3_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_3_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_3_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_3_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_3_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_4_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_4_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_4_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_4_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_4_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_4_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_5_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_5_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_5_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_5_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_5_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_5_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_6_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_6_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_6_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_6_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_6_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_6_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_7_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_7_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_7_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_7_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_7_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_7_V_V", "role": "write" }} , 
 	{ "name": "pe_input_stream_8_V_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_8_V_V", "role": "din" }} , 
 	{ "name": "pe_input_stream_8_V_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_8_V_V", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_8_V_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_8_V_V", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8"],
		"CDFG" : "pe",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "43", "EstimateLatencyMax" : "43",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "weight_stream_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "weight_stream_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_weight_stream_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_weight_stream_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_1_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_1_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_2_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_2_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_3_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_3_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_4_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_4_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_5_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_5_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_6_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_6_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_7_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_7_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_8_V_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_8_V_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "index_table", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.index_table_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weight_registers_V_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_0_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_1_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_2_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_0_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_1_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_2_V_V_fifo_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	pe {
		weight_stream_V {Type I LastRead 3 FirstWrite -1}
		pe_weight_stream_V {Type O LastRead -1 FirstWrite 7}
		pe_input_stream_V_V {Type O LastRead -1 FirstWrite 7}
		pe_input_stream_1_V_V {Type O LastRead -1 FirstWrite 5}
		pe_input_stream_2_V_V {Type O LastRead -1 FirstWrite 5}
		pe_input_stream_3_V_V {Type O LastRead -1 FirstWrite 7}
		pe_input_stream_4_V_V {Type O LastRead -1 FirstWrite 6}
		pe_input_stream_5_V_V {Type O LastRead -1 FirstWrite 5}
		pe_input_stream_6_V_V {Type O LastRead -1 FirstWrite 7}
		pe_input_stream_7_V_V {Type O LastRead -1 FirstWrite 6}
		pe_input_stream_8_V_V {Type O LastRead -1 FirstWrite 5}
		index_table {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "43", "Max" : "43"}
	, {"Name" : "Interval", "Min" : "43", "Max" : "43"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	weight_stream_V { ap_fifo {  { weight_stream_V_dout fifo_data 0 8 }  { weight_stream_V_empty_n fifo_status 0 1 }  { weight_stream_V_read fifo_update 1 1 } } }
	pe_weight_stream_V { ap_fifo {  { pe_weight_stream_V_din fifo_data 1 8 }  { pe_weight_stream_V_full_n fifo_status 0 1 }  { pe_weight_stream_V_write fifo_update 1 1 } } }
	pe_input_stream_V_V { ap_fifo {  { pe_input_stream_V_V_din fifo_data 1 8 }  { pe_input_stream_V_V_full_n fifo_status 0 1 }  { pe_input_stream_V_V_write fifo_update 1 1 } } }
	pe_input_stream_1_V_V { ap_fifo {  { pe_input_stream_1_V_V_din fifo_data 1 8 }  { pe_input_stream_1_V_V_full_n fifo_status 0 1 }  { pe_input_stream_1_V_V_write fifo_update 1 1 } } }
	pe_input_stream_2_V_V { ap_fifo {  { pe_input_stream_2_V_V_din fifo_data 1 8 }  { pe_input_stream_2_V_V_full_n fifo_status 0 1 }  { pe_input_stream_2_V_V_write fifo_update 1 1 } } }
	pe_input_stream_3_V_V { ap_fifo {  { pe_input_stream_3_V_V_din fifo_data 1 8 }  { pe_input_stream_3_V_V_full_n fifo_status 0 1 }  { pe_input_stream_3_V_V_write fifo_update 1 1 } } }
	pe_input_stream_4_V_V { ap_fifo {  { pe_input_stream_4_V_V_din fifo_data 1 8 }  { pe_input_stream_4_V_V_full_n fifo_status 0 1 }  { pe_input_stream_4_V_V_write fifo_update 1 1 } } }
	pe_input_stream_5_V_V { ap_fifo {  { pe_input_stream_5_V_V_din fifo_data 1 8 }  { pe_input_stream_5_V_V_full_n fifo_status 0 1 }  { pe_input_stream_5_V_V_write fifo_update 1 1 } } }
	pe_input_stream_6_V_V { ap_fifo {  { pe_input_stream_6_V_V_din fifo_data 1 8 }  { pe_input_stream_6_V_V_full_n fifo_status 0 1 }  { pe_input_stream_6_V_V_write fifo_update 1 1 } } }
	pe_input_stream_7_V_V { ap_fifo {  { pe_input_stream_7_V_V_din fifo_data 1 8 }  { pe_input_stream_7_V_V_full_n fifo_status 0 1 }  { pe_input_stream_7_V_V_write fifo_update 1 1 } } }
	pe_input_stream_8_V_V { ap_fifo {  { pe_input_stream_8_V_V_din fifo_data 1 8 }  { pe_input_stream_8_V_V_full_n fifo_status 0 1 }  { pe_input_stream_8_V_V_write fifo_update 1 1 } } }
}
