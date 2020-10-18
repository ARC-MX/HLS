set moduleName buf2stream
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
set C_modelName {buf2stream}
set C_modelType { void 0 }
set C_modelArgList {
	{ buffer_0 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_1 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_2 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_3 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_4 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_5 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_6 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_7 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_8 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ buffer_9 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ dst_V int 32 regular {fifo 1 volatile }  }
	{ dst_1_V int 32 regular {fifo 1 volatile }  }
	{ dst_2_V int 32 regular {fifo 1 volatile }  }
	{ dst_3_V int 32 regular {fifo 1 volatile }  }
	{ dst_4_V int 32 regular {fifo 1 volatile }  }
	{ enable uint 1 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "buffer_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_4", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_5", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_6", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_7", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_8", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_9", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "dst_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "dst_1_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "dst_2_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "dst_3_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "dst_4_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "enable", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 52
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ buffer_0_address0 sc_out sc_lv 4 signal 0 } 
	{ buffer_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ buffer_0_q0 sc_in sc_lv 32 signal 0 } 
	{ buffer_1_address0 sc_out sc_lv 4 signal 1 } 
	{ buffer_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ buffer_1_q0 sc_in sc_lv 32 signal 1 } 
	{ buffer_2_address0 sc_out sc_lv 4 signal 2 } 
	{ buffer_2_ce0 sc_out sc_logic 1 signal 2 } 
	{ buffer_2_q0 sc_in sc_lv 32 signal 2 } 
	{ buffer_3_address0 sc_out sc_lv 4 signal 3 } 
	{ buffer_3_ce0 sc_out sc_logic 1 signal 3 } 
	{ buffer_3_q0 sc_in sc_lv 32 signal 3 } 
	{ buffer_4_address0 sc_out sc_lv 4 signal 4 } 
	{ buffer_4_ce0 sc_out sc_logic 1 signal 4 } 
	{ buffer_4_q0 sc_in sc_lv 32 signal 4 } 
	{ buffer_5_address0 sc_out sc_lv 4 signal 5 } 
	{ buffer_5_ce0 sc_out sc_logic 1 signal 5 } 
	{ buffer_5_q0 sc_in sc_lv 32 signal 5 } 
	{ buffer_6_address0 sc_out sc_lv 4 signal 6 } 
	{ buffer_6_ce0 sc_out sc_logic 1 signal 6 } 
	{ buffer_6_q0 sc_in sc_lv 32 signal 6 } 
	{ buffer_7_address0 sc_out sc_lv 4 signal 7 } 
	{ buffer_7_ce0 sc_out sc_logic 1 signal 7 } 
	{ buffer_7_q0 sc_in sc_lv 32 signal 7 } 
	{ buffer_8_address0 sc_out sc_lv 4 signal 8 } 
	{ buffer_8_ce0 sc_out sc_logic 1 signal 8 } 
	{ buffer_8_q0 sc_in sc_lv 32 signal 8 } 
	{ buffer_9_address0 sc_out sc_lv 4 signal 9 } 
	{ buffer_9_ce0 sc_out sc_logic 1 signal 9 } 
	{ buffer_9_q0 sc_in sc_lv 32 signal 9 } 
	{ dst_V_din sc_out sc_lv 32 signal 10 } 
	{ dst_V_full_n sc_in sc_logic 1 signal 10 } 
	{ dst_V_write sc_out sc_logic 1 signal 10 } 
	{ dst_1_V_din sc_out sc_lv 32 signal 11 } 
	{ dst_1_V_full_n sc_in sc_logic 1 signal 11 } 
	{ dst_1_V_write sc_out sc_logic 1 signal 11 } 
	{ dst_2_V_din sc_out sc_lv 32 signal 12 } 
	{ dst_2_V_full_n sc_in sc_logic 1 signal 12 } 
	{ dst_2_V_write sc_out sc_logic 1 signal 12 } 
	{ dst_3_V_din sc_out sc_lv 32 signal 13 } 
	{ dst_3_V_full_n sc_in sc_logic 1 signal 13 } 
	{ dst_3_V_write sc_out sc_logic 1 signal 13 } 
	{ dst_4_V_din sc_out sc_lv 32 signal 14 } 
	{ dst_4_V_full_n sc_in sc_logic 1 signal 14 } 
	{ dst_4_V_write sc_out sc_logic 1 signal 14 } 
	{ enable sc_in sc_logic 1 signal 15 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "buffer_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_0", "role": "address0" }} , 
 	{ "name": "buffer_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_0", "role": "ce0" }} , 
 	{ "name": "buffer_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_0", "role": "q0" }} , 
 	{ "name": "buffer_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_1", "role": "address0" }} , 
 	{ "name": "buffer_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_1", "role": "ce0" }} , 
 	{ "name": "buffer_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_1", "role": "q0" }} , 
 	{ "name": "buffer_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_2", "role": "address0" }} , 
 	{ "name": "buffer_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_2", "role": "ce0" }} , 
 	{ "name": "buffer_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_2", "role": "q0" }} , 
 	{ "name": "buffer_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_3", "role": "address0" }} , 
 	{ "name": "buffer_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_3", "role": "ce0" }} , 
 	{ "name": "buffer_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_3", "role": "q0" }} , 
 	{ "name": "buffer_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_4", "role": "address0" }} , 
 	{ "name": "buffer_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_4", "role": "ce0" }} , 
 	{ "name": "buffer_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_4", "role": "q0" }} , 
 	{ "name": "buffer_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_5", "role": "address0" }} , 
 	{ "name": "buffer_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_5", "role": "ce0" }} , 
 	{ "name": "buffer_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_5", "role": "q0" }} , 
 	{ "name": "buffer_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_6", "role": "address0" }} , 
 	{ "name": "buffer_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_6", "role": "ce0" }} , 
 	{ "name": "buffer_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_6", "role": "q0" }} , 
 	{ "name": "buffer_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_7", "role": "address0" }} , 
 	{ "name": "buffer_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_7", "role": "ce0" }} , 
 	{ "name": "buffer_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_7", "role": "q0" }} , 
 	{ "name": "buffer_8_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_8", "role": "address0" }} , 
 	{ "name": "buffer_8_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_8", "role": "ce0" }} , 
 	{ "name": "buffer_8_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_8", "role": "q0" }} , 
 	{ "name": "buffer_9_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_9", "role": "address0" }} , 
 	{ "name": "buffer_9_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_9", "role": "ce0" }} , 
 	{ "name": "buffer_9_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_9", "role": "q0" }} , 
 	{ "name": "dst_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V", "role": "din" }} , 
 	{ "name": "dst_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V", "role": "full_n" }} , 
 	{ "name": "dst_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V", "role": "write" }} , 
 	{ "name": "dst_1_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_1_V", "role": "din" }} , 
 	{ "name": "dst_1_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_1_V", "role": "full_n" }} , 
 	{ "name": "dst_1_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_1_V", "role": "write" }} , 
 	{ "name": "dst_2_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_2_V", "role": "din" }} , 
 	{ "name": "dst_2_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_2_V", "role": "full_n" }} , 
 	{ "name": "dst_2_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_2_V", "role": "write" }} , 
 	{ "name": "dst_3_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_3_V", "role": "din" }} , 
 	{ "name": "dst_3_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_3_V", "role": "full_n" }} , 
 	{ "name": "dst_3_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_3_V", "role": "write" }} , 
 	{ "name": "dst_4_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_4_V", "role": "din" }} , 
 	{ "name": "dst_4_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_4_V", "role": "full_n" }} , 
 	{ "name": "dst_4_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_4_V", "role": "write" }} , 
 	{ "name": "enable", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "enable", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "buf2stream",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "22",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "buffer_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "buffer_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "dst_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "dst_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "dst_1_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "dst_1_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "dst_2_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "dst_2_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "dst_3_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "dst_3_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "dst_4_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "dst_4_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "enable", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	buf2stream {
		buffer_0 {Type I LastRead 1 FirstWrite -1}
		buffer_1 {Type I LastRead 1 FirstWrite -1}
		buffer_2 {Type I LastRead 1 FirstWrite -1}
		buffer_3 {Type I LastRead 1 FirstWrite -1}
		buffer_4 {Type I LastRead 1 FirstWrite -1}
		buffer_5 {Type I LastRead 1 FirstWrite -1}
		buffer_6 {Type I LastRead 1 FirstWrite -1}
		buffer_7 {Type I LastRead 1 FirstWrite -1}
		buffer_8 {Type I LastRead 1 FirstWrite -1}
		buffer_9 {Type I LastRead 1 FirstWrite -1}
		dst_V {Type O LastRead -1 FirstWrite 2}
		dst_1_V {Type O LastRead -1 FirstWrite 2}
		dst_2_V {Type O LastRead -1 FirstWrite 2}
		dst_3_V {Type O LastRead -1 FirstWrite 2}
		dst_4_V {Type O LastRead -1 FirstWrite 2}
		enable {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "1", "Max" : "22"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "22"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	buffer_0 { ap_memory {  { buffer_0_address0 mem_address 1 4 }  { buffer_0_ce0 mem_ce 1 1 }  { buffer_0_q0 mem_dout 0 32 } } }
	buffer_1 { ap_memory {  { buffer_1_address0 mem_address 1 4 }  { buffer_1_ce0 mem_ce 1 1 }  { buffer_1_q0 mem_dout 0 32 } } }
	buffer_2 { ap_memory {  { buffer_2_address0 mem_address 1 4 }  { buffer_2_ce0 mem_ce 1 1 }  { buffer_2_q0 mem_dout 0 32 } } }
	buffer_3 { ap_memory {  { buffer_3_address0 mem_address 1 4 }  { buffer_3_ce0 mem_ce 1 1 }  { buffer_3_q0 mem_dout 0 32 } } }
	buffer_4 { ap_memory {  { buffer_4_address0 mem_address 1 4 }  { buffer_4_ce0 mem_ce 1 1 }  { buffer_4_q0 mem_dout 0 32 } } }
	buffer_5 { ap_memory {  { buffer_5_address0 mem_address 1 4 }  { buffer_5_ce0 mem_ce 1 1 }  { buffer_5_q0 mem_dout 0 32 } } }
	buffer_6 { ap_memory {  { buffer_6_address0 mem_address 1 4 }  { buffer_6_ce0 mem_ce 1 1 }  { buffer_6_q0 mem_dout 0 32 } } }
	buffer_7 { ap_memory {  { buffer_7_address0 mem_address 1 4 }  { buffer_7_ce0 mem_ce 1 1 }  { buffer_7_q0 mem_dout 0 32 } } }
	buffer_8 { ap_memory {  { buffer_8_address0 mem_address 1 4 }  { buffer_8_ce0 mem_ce 1 1 }  { buffer_8_q0 mem_dout 0 32 } } }
	buffer_9 { ap_memory {  { buffer_9_address0 mem_address 1 4 }  { buffer_9_ce0 mem_ce 1 1 }  { buffer_9_q0 mem_dout 0 32 } } }
	dst_V { ap_fifo {  { dst_V_din fifo_data 1 32 }  { dst_V_full_n fifo_status 0 1 }  { dst_V_write fifo_update 1 1 } } }
	dst_1_V { ap_fifo {  { dst_1_V_din fifo_data 1 32 }  { dst_1_V_full_n fifo_status 0 1 }  { dst_1_V_write fifo_update 1 1 } } }
	dst_2_V { ap_fifo {  { dst_2_V_din fifo_data 1 32 }  { dst_2_V_full_n fifo_status 0 1 }  { dst_2_V_write fifo_update 1 1 } } }
	dst_3_V { ap_fifo {  { dst_3_V_din fifo_data 1 32 }  { dst_3_V_full_n fifo_status 0 1 }  { dst_3_V_write fifo_update 1 1 } } }
	dst_4_V { ap_fifo {  { dst_4_V_din fifo_data 1 32 }  { dst_4_V_full_n fifo_status 0 1 }  { dst_4_V_write fifo_update 1 1 } } }
	enable { ap_none {  { enable in_data 0 1 } } }
}
