set moduleName pe
set isTopModule 1
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
	{ input_buffers int 8 regular {bram 54 { 1 1 } 1 1 }  }
	{ weight_stream_V int 8 regular {fifo 0 volatile }  }
	{ pe_input_stream_V_0 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_1 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_2 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_3 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_4 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_5 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_6 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_7 int 8 regular {fifo 1 volatile }  }
	{ pe_input_stream_V_8 int 8 regular {fifo 1 volatile }  }
	{ pe_weight_stream_V int 8 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_buffers", "interface" : "bram", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "input_buffers","cData": "char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 53,"step" : 1}]}]}]} , 
 	{ "Name" : "weight_stream_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "weight_stream.V","cData": "char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 1,"step" : 1}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_0", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_1", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_2", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_3", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_4", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_5", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_6", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_7", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_input_stream_V_8", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_input_stream.V","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 8,"up" : 8,"step" : 2}]}]}]} , 
 	{ "Name" : "pe_weight_stream_V", "interface" : "fifo", "bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pe_weight_stream.V","cData": "char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 1,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 53
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_buffers_Addr_A sc_out sc_lv 32 signal 0 } 
	{ input_buffers_EN_A sc_out sc_logic 1 signal 0 } 
	{ input_buffers_WEN_A sc_out sc_lv 1 signal 0 } 
	{ input_buffers_Din_A sc_out sc_lv 8 signal 0 } 
	{ input_buffers_Dout_A sc_in sc_lv 8 signal 0 } 
	{ input_buffers_Clk_A sc_out sc_logic 1 signal 0 } 
	{ input_buffers_Rst_A sc_out sc_logic 1 signal 0 } 
	{ input_buffers_Addr_B sc_out sc_lv 32 signal 0 } 
	{ input_buffers_EN_B sc_out sc_logic 1 signal 0 } 
	{ input_buffers_WEN_B sc_out sc_lv 1 signal 0 } 
	{ input_buffers_Din_B sc_out sc_lv 8 signal 0 } 
	{ input_buffers_Dout_B sc_in sc_lv 8 signal 0 } 
	{ input_buffers_Clk_B sc_out sc_logic 1 signal 0 } 
	{ input_buffers_Rst_B sc_out sc_logic 1 signal 0 } 
	{ weight_stream_V_dout sc_in sc_lv 8 signal 1 } 
	{ weight_stream_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ weight_stream_V_read sc_out sc_logic 1 signal 1 } 
	{ pe_input_stream_V_0_din sc_out sc_lv 8 signal 2 } 
	{ pe_input_stream_V_0_full_n sc_in sc_logic 1 signal 2 } 
	{ pe_input_stream_V_0_write sc_out sc_logic 1 signal 2 } 
	{ pe_input_stream_V_1_din sc_out sc_lv 8 signal 3 } 
	{ pe_input_stream_V_1_full_n sc_in sc_logic 1 signal 3 } 
	{ pe_input_stream_V_1_write sc_out sc_logic 1 signal 3 } 
	{ pe_input_stream_V_2_din sc_out sc_lv 8 signal 4 } 
	{ pe_input_stream_V_2_full_n sc_in sc_logic 1 signal 4 } 
	{ pe_input_stream_V_2_write sc_out sc_logic 1 signal 4 } 
	{ pe_input_stream_V_3_din sc_out sc_lv 8 signal 5 } 
	{ pe_input_stream_V_3_full_n sc_in sc_logic 1 signal 5 } 
	{ pe_input_stream_V_3_write sc_out sc_logic 1 signal 5 } 
	{ pe_input_stream_V_4_din sc_out sc_lv 8 signal 6 } 
	{ pe_input_stream_V_4_full_n sc_in sc_logic 1 signal 6 } 
	{ pe_input_stream_V_4_write sc_out sc_logic 1 signal 6 } 
	{ pe_input_stream_V_5_din sc_out sc_lv 8 signal 7 } 
	{ pe_input_stream_V_5_full_n sc_in sc_logic 1 signal 7 } 
	{ pe_input_stream_V_5_write sc_out sc_logic 1 signal 7 } 
	{ pe_input_stream_V_6_din sc_out sc_lv 8 signal 8 } 
	{ pe_input_stream_V_6_full_n sc_in sc_logic 1 signal 8 } 
	{ pe_input_stream_V_6_write sc_out sc_logic 1 signal 8 } 
	{ pe_input_stream_V_7_din sc_out sc_lv 8 signal 9 } 
	{ pe_input_stream_V_7_full_n sc_in sc_logic 1 signal 9 } 
	{ pe_input_stream_V_7_write sc_out sc_logic 1 signal 9 } 
	{ pe_input_stream_V_8_din sc_out sc_lv 8 signal 10 } 
	{ pe_input_stream_V_8_full_n sc_in sc_logic 1 signal 10 } 
	{ pe_input_stream_V_8_write sc_out sc_logic 1 signal 10 } 
	{ pe_weight_stream_V_din sc_out sc_lv 8 signal 11 } 
	{ pe_weight_stream_V_full_n sc_in sc_logic 1 signal 11 } 
	{ pe_weight_stream_V_write sc_out sc_logic 1 signal 11 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_buffers_Addr_A", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_buffers", "role": "Addr_A" }} , 
 	{ "name": "input_buffers_EN_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "EN_A" }} , 
 	{ "name": "input_buffers_WEN_A", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "WEN_A" }} , 
 	{ "name": "input_buffers_Din_A", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "input_buffers", "role": "Din_A" }} , 
 	{ "name": "input_buffers_Dout_A", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "input_buffers", "role": "Dout_A" }} , 
 	{ "name": "input_buffers_Clk_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "Clk_A" }} , 
 	{ "name": "input_buffers_Rst_A", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "Rst_A" }} , 
 	{ "name": "input_buffers_Addr_B", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_buffers", "role": "Addr_B" }} , 
 	{ "name": "input_buffers_EN_B", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "EN_B" }} , 
 	{ "name": "input_buffers_WEN_B", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "WEN_B" }} , 
 	{ "name": "input_buffers_Din_B", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "input_buffers", "role": "Din_B" }} , 
 	{ "name": "input_buffers_Dout_B", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "input_buffers", "role": "Dout_B" }} , 
 	{ "name": "input_buffers_Clk_B", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "Clk_B" }} , 
 	{ "name": "input_buffers_Rst_B", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_buffers", "role": "Rst_B" }} , 
 	{ "name": "weight_stream_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "dout" }} , 
 	{ "name": "weight_stream_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "empty_n" }} , 
 	{ "name": "weight_stream_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "weight_stream_V", "role": "read" }} , 
 	{ "name": "pe_input_stream_V_0_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_0", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_0_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_0", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_0_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_0", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_1_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_1", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_1_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_1", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_1_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_1", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_2_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_2", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_2_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_2", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_2_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_2", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_3_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_3", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_3_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_3", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_3_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_3", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_4_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_4", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_4_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_4", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_4_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_4", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_5_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_5", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_5_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_5", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_5_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_5", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_6_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_6", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_6_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_6", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_6_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_6", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_7_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_7", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_7_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_7", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_7_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_7", "role": "write" }} , 
 	{ "name": "pe_input_stream_V_8_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_input_stream_V_8", "role": "din" }} , 
 	{ "name": "pe_input_stream_V_8_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_8", "role": "full_n" }} , 
 	{ "name": "pe_input_stream_V_8_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_input_stream_V_8", "role": "write" }} , 
 	{ "name": "pe_weight_stream_V_din", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "din" }} , 
 	{ "name": "pe_weight_stream_V_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "full_n" }} , 
 	{ "name": "pe_weight_stream_V_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pe_weight_stream_V", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8"],
		"CDFG" : "pe",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "74", "EstimateLatencyMax" : "74",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_buffers", "Type" : "Bram", "Direction" : "I"},
			{"Name" : "weight_stream_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "weight_stream_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_0", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_0_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_1", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_1_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_2", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_2_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_3", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_3_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_4", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_4_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_5", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_5_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_6", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_6_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_7", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_7_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_input_stream_V_8", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_input_stream_V_8_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "pe_weight_stream_V", "Type" : "Fifo", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "pe_weight_stream_V_blk_n", "Type" : "RtlSignal"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weight_registers_V_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_5ns_3ns_7_1_1_U1", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_0_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_1_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_0_2_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_0_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_1_V_V_fifo_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.inner_fifos_1_2_V_V_fifo_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	pe {
		input_buffers {Type I LastRead 7 FirstWrite -1}
		weight_stream_V {Type I LastRead 4 FirstWrite -1}
		pe_input_stream_V_0 {Type O LastRead -1 FirstWrite 3}
		pe_input_stream_V_1 {Type O LastRead -1 FirstWrite 2}
		pe_input_stream_V_2 {Type O LastRead -1 FirstWrite 2}
		pe_input_stream_V_3 {Type O LastRead -1 FirstWrite 3}
		pe_input_stream_V_4 {Type O LastRead -1 FirstWrite 4}
		pe_input_stream_V_5 {Type O LastRead -1 FirstWrite 2}
		pe_input_stream_V_6 {Type O LastRead -1 FirstWrite 3}
		pe_input_stream_V_7 {Type O LastRead -1 FirstWrite 4}
		pe_input_stream_V_8 {Type O LastRead -1 FirstWrite 4}
		pe_weight_stream_V {Type O LastRead -1 FirstWrite 4}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "74", "Max" : "74"}
	, {"Name" : "Interval", "Min" : "75", "Max" : "75"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	input_buffers { bram {  { input_buffers_Addr_A MemPortADDR2 1 32 }  { input_buffers_EN_A MemPortCE2 1 1 }  { input_buffers_WEN_A MemPortWE2 1 1 }  { input_buffers_Din_A MemPortDIN2 1 8 }  { input_buffers_Dout_A MemPortDOUT2 0 8 }  { input_buffers_Clk_A mem_clk 1 1 }  { input_buffers_Rst_A mem_rst 1 1 }  { input_buffers_Addr_B MemPortADDR2 1 32 }  { input_buffers_EN_B MemPortCE2 1 1 }  { input_buffers_WEN_B MemPortWE2 1 1 }  { input_buffers_Din_B MemPortDIN2 1 8 }  { input_buffers_Dout_B MemPortDOUT2 0 8 }  { input_buffers_Clk_B mem_clk 1 1 }  { input_buffers_Rst_B mem_rst 1 1 } } }
	weight_stream_V { ap_fifo {  { weight_stream_V_dout fifo_data 0 8 }  { weight_stream_V_empty_n fifo_status 0 1 }  { weight_stream_V_read fifo_update 1 1 } } }
	pe_input_stream_V_0 { ap_fifo {  { pe_input_stream_V_0_din fifo_data 1 8 }  { pe_input_stream_V_0_full_n fifo_status 0 1 }  { pe_input_stream_V_0_write fifo_update 1 1 } } }
	pe_input_stream_V_1 { ap_fifo {  { pe_input_stream_V_1_din fifo_data 1 8 }  { pe_input_stream_V_1_full_n fifo_status 0 1 }  { pe_input_stream_V_1_write fifo_update 1 1 } } }
	pe_input_stream_V_2 { ap_fifo {  { pe_input_stream_V_2_din fifo_data 1 8 }  { pe_input_stream_V_2_full_n fifo_status 0 1 }  { pe_input_stream_V_2_write fifo_update 1 1 } } }
	pe_input_stream_V_3 { ap_fifo {  { pe_input_stream_V_3_din fifo_data 1 8 }  { pe_input_stream_V_3_full_n fifo_status 0 1 }  { pe_input_stream_V_3_write fifo_update 1 1 } } }
	pe_input_stream_V_4 { ap_fifo {  { pe_input_stream_V_4_din fifo_data 1 8 }  { pe_input_stream_V_4_full_n fifo_status 0 1 }  { pe_input_stream_V_4_write fifo_update 1 1 } } }
	pe_input_stream_V_5 { ap_fifo {  { pe_input_stream_V_5_din fifo_data 1 8 }  { pe_input_stream_V_5_full_n fifo_status 0 1 }  { pe_input_stream_V_5_write fifo_update 1 1 } } }
	pe_input_stream_V_6 { ap_fifo {  { pe_input_stream_V_6_din fifo_data 1 8 }  { pe_input_stream_V_6_full_n fifo_status 0 1 }  { pe_input_stream_V_6_write fifo_update 1 1 } } }
	pe_input_stream_V_7 { ap_fifo {  { pe_input_stream_V_7_din fifo_data 1 8 }  { pe_input_stream_V_7_full_n fifo_status 0 1 }  { pe_input_stream_V_7_write fifo_update 1 1 } } }
	pe_input_stream_V_8 { ap_fifo {  { pe_input_stream_V_8_din fifo_data 1 8 }  { pe_input_stream_V_8_full_n fifo_status 0 1 }  { pe_input_stream_V_8_write fifo_update 1 1 } } }
	pe_weight_stream_V { ap_fifo {  { pe_weight_stream_V_din fifo_data 1 8 }  { pe_weight_stream_V_full_n fifo_status 0 1 }  { pe_weight_stream_V_write fifo_update 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
	weight_stream_V { fifo_read 36 has_conditional }
	pe_input_stream_V_0 { fifo_write 60 has_conditional }
	pe_input_stream_V_1 { fifo_write 36 no_conditional }
	pe_input_stream_V_2 { fifo_write 36 no_conditional }
	pe_input_stream_V_3 { fifo_write 36 no_conditional }
	pe_input_stream_V_4 { fifo_write 36 no_conditional }
	pe_input_stream_V_5 { fifo_write 36 no_conditional }
	pe_input_stream_V_6 { fifo_write 60 has_conditional }
	pe_input_stream_V_7 { fifo_write 36 no_conditional }
	pe_input_stream_V_8 { fifo_write 36 no_conditional }
	pe_weight_stream_V { fifo_write 36 no_conditional }
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
