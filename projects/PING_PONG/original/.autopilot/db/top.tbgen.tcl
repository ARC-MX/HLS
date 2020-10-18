set moduleName top
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
set C_modelName {top}
set C_modelType { void 0 }
set C_modelArgList {
	{ src_V_0 int 32 regular {fifo 0 volatile }  }
	{ src_V_1 int 32 regular {fifo 0 volatile }  }
	{ src_V_2 int 32 regular {fifo 0 volatile }  }
	{ src_V_3 int 32 regular {fifo 0 volatile }  }
	{ src_V_4 int 32 regular {fifo 0 volatile }  }
	{ src_V_5 int 32 regular {fifo 0 volatile }  }
	{ src_V_6 int 32 regular {fifo 0 volatile }  }
	{ src_V_7 int 32 regular {fifo 0 volatile }  }
	{ src_V_8 int 32 regular {fifo 0 volatile }  }
	{ src_V_9 int 32 regular {fifo 0 volatile }  }
	{ dst_V_0 int 32 regular {fifo 1 volatile }  }
	{ dst_V_1 int 32 regular {fifo 1 volatile }  }
	{ dst_V_2 int 32 regular {fifo 1 volatile }  }
	{ dst_V_3 int 32 regular {fifo 1 volatile }  }
	{ dst_V_4 int 32 regular {fifo 1 volatile }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "src_V_0", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_1", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_2", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_3", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_4", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_5", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_6", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_7", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_8", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 8,"up" : 8,"step" : 2}]}]}]} , 
 	{ "Name" : "src_V_9", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "src.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 9,"up" : 9,"step" : 2}]}]}]} , 
 	{ "Name" : "dst_V_0", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dst.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "dst_V_1", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dst.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "dst_V_2", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dst.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "dst_V_3", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dst.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "dst_V_4", "interface" : "fifo", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dst.V","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 4,"up" : 4,"step" : 2}]}]}]} ]}
# RTL Port declarations: 
set portNum 51
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ src_V_0_dout sc_in sc_lv 32 signal 0 } 
	{ src_V_0_empty_n sc_in sc_logic 1 signal 0 } 
	{ src_V_0_read sc_out sc_logic 1 signal 0 } 
	{ src_V_1_dout sc_in sc_lv 32 signal 1 } 
	{ src_V_1_empty_n sc_in sc_logic 1 signal 1 } 
	{ src_V_1_read sc_out sc_logic 1 signal 1 } 
	{ src_V_2_dout sc_in sc_lv 32 signal 2 } 
	{ src_V_2_empty_n sc_in sc_logic 1 signal 2 } 
	{ src_V_2_read sc_out sc_logic 1 signal 2 } 
	{ src_V_3_dout sc_in sc_lv 32 signal 3 } 
	{ src_V_3_empty_n sc_in sc_logic 1 signal 3 } 
	{ src_V_3_read sc_out sc_logic 1 signal 3 } 
	{ src_V_4_dout sc_in sc_lv 32 signal 4 } 
	{ src_V_4_empty_n sc_in sc_logic 1 signal 4 } 
	{ src_V_4_read sc_out sc_logic 1 signal 4 } 
	{ src_V_5_dout sc_in sc_lv 32 signal 5 } 
	{ src_V_5_empty_n sc_in sc_logic 1 signal 5 } 
	{ src_V_5_read sc_out sc_logic 1 signal 5 } 
	{ src_V_6_dout sc_in sc_lv 32 signal 6 } 
	{ src_V_6_empty_n sc_in sc_logic 1 signal 6 } 
	{ src_V_6_read sc_out sc_logic 1 signal 6 } 
	{ src_V_7_dout sc_in sc_lv 32 signal 7 } 
	{ src_V_7_empty_n sc_in sc_logic 1 signal 7 } 
	{ src_V_7_read sc_out sc_logic 1 signal 7 } 
	{ src_V_8_dout sc_in sc_lv 32 signal 8 } 
	{ src_V_8_empty_n sc_in sc_logic 1 signal 8 } 
	{ src_V_8_read sc_out sc_logic 1 signal 8 } 
	{ src_V_9_dout sc_in sc_lv 32 signal 9 } 
	{ src_V_9_empty_n sc_in sc_logic 1 signal 9 } 
	{ src_V_9_read sc_out sc_logic 1 signal 9 } 
	{ dst_V_0_din sc_out sc_lv 32 signal 10 } 
	{ dst_V_0_full_n sc_in sc_logic 1 signal 10 } 
	{ dst_V_0_write sc_out sc_logic 1 signal 10 } 
	{ dst_V_1_din sc_out sc_lv 32 signal 11 } 
	{ dst_V_1_full_n sc_in sc_logic 1 signal 11 } 
	{ dst_V_1_write sc_out sc_logic 1 signal 11 } 
	{ dst_V_2_din sc_out sc_lv 32 signal 12 } 
	{ dst_V_2_full_n sc_in sc_logic 1 signal 12 } 
	{ dst_V_2_write sc_out sc_logic 1 signal 12 } 
	{ dst_V_3_din sc_out sc_lv 32 signal 13 } 
	{ dst_V_3_full_n sc_in sc_logic 1 signal 13 } 
	{ dst_V_3_write sc_out sc_logic 1 signal 13 } 
	{ dst_V_4_din sc_out sc_lv 32 signal 14 } 
	{ dst_V_4_full_n sc_in sc_logic 1 signal 14 } 
	{ dst_V_4_write sc_out sc_logic 1 signal 14 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "src_V_0_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_0", "role": "dout" }} , 
 	{ "name": "src_V_0_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_0", "role": "empty_n" }} , 
 	{ "name": "src_V_0_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_0", "role": "read" }} , 
 	{ "name": "src_V_1_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_1", "role": "dout" }} , 
 	{ "name": "src_V_1_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_1", "role": "empty_n" }} , 
 	{ "name": "src_V_1_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_1", "role": "read" }} , 
 	{ "name": "src_V_2_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_2", "role": "dout" }} , 
 	{ "name": "src_V_2_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_2", "role": "empty_n" }} , 
 	{ "name": "src_V_2_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_2", "role": "read" }} , 
 	{ "name": "src_V_3_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_3", "role": "dout" }} , 
 	{ "name": "src_V_3_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_3", "role": "empty_n" }} , 
 	{ "name": "src_V_3_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_3", "role": "read" }} , 
 	{ "name": "src_V_4_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_4", "role": "dout" }} , 
 	{ "name": "src_V_4_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_4", "role": "empty_n" }} , 
 	{ "name": "src_V_4_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_4", "role": "read" }} , 
 	{ "name": "src_V_5_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_5", "role": "dout" }} , 
 	{ "name": "src_V_5_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_5", "role": "empty_n" }} , 
 	{ "name": "src_V_5_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_5", "role": "read" }} , 
 	{ "name": "src_V_6_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_6", "role": "dout" }} , 
 	{ "name": "src_V_6_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_6", "role": "empty_n" }} , 
 	{ "name": "src_V_6_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_6", "role": "read" }} , 
 	{ "name": "src_V_7_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_7", "role": "dout" }} , 
 	{ "name": "src_V_7_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_7", "role": "empty_n" }} , 
 	{ "name": "src_V_7_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_7", "role": "read" }} , 
 	{ "name": "src_V_8_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_8", "role": "dout" }} , 
 	{ "name": "src_V_8_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_8", "role": "empty_n" }} , 
 	{ "name": "src_V_8_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_8", "role": "read" }} , 
 	{ "name": "src_V_9_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V_9", "role": "dout" }} , 
 	{ "name": "src_V_9_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_9", "role": "empty_n" }} , 
 	{ "name": "src_V_9_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V_9", "role": "read" }} , 
 	{ "name": "dst_V_0_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V_0", "role": "din" }} , 
 	{ "name": "dst_V_0_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_0", "role": "full_n" }} , 
 	{ "name": "dst_V_0_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_0", "role": "write" }} , 
 	{ "name": "dst_V_1_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V_1", "role": "din" }} , 
 	{ "name": "dst_V_1_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_1", "role": "full_n" }} , 
 	{ "name": "dst_V_1_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_1", "role": "write" }} , 
 	{ "name": "dst_V_2_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V_2", "role": "din" }} , 
 	{ "name": "dst_V_2_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_2", "role": "full_n" }} , 
 	{ "name": "dst_V_2_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_2", "role": "write" }} , 
 	{ "name": "dst_V_3_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V_3", "role": "din" }} , 
 	{ "name": "dst_V_3_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_3", "role": "full_n" }} , 
 	{ "name": "dst_V_3_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_3", "role": "write" }} , 
 	{ "name": "dst_V_4_din", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "dst_V_4", "role": "din" }} , 
 	{ "name": "dst_V_4_full_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_4", "role": "full_n" }} , 
 	{ "name": "dst_V_4_write", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "dst_V_4", "role": "write" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22"],
		"CDFG" : "top",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "49", "EstimateLatencyMax" : "385",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_buf2stream_fu_161"},
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_buf2stream_fu_161"},
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_stream2buf_fu_186"},
			{"State" : "ap_ST_fsm_state3", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_stream2buf_fu_186"}],
		"Port" : [
			{"Name" : "src_V_0", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_V"}]},
			{"Name" : "src_V_1", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_1_V"}]},
			{"Name" : "src_V_2", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_2_V"}]},
			{"Name" : "src_V_3", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_3_V"}]},
			{"Name" : "src_V_4", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_4_V"}]},
			{"Name" : "src_V_5", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_5_V"}]},
			{"Name" : "src_V_6", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_6_V"}]},
			{"Name" : "src_V_7", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_7_V"}]},
			{"Name" : "src_V_8", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_8_V"}]},
			{"Name" : "src_V_9", "Type" : "Fifo", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "22", "SubInstance" : "grp_stream2buf_fu_186", "Port" : "src_9_V"}]},
			{"Name" : "dst_V_0", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "21", "SubInstance" : "grp_buf2stream_fu_161", "Port" : "dst_V"}]},
			{"Name" : "dst_V_1", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "21", "SubInstance" : "grp_buf2stream_fu_161", "Port" : "dst_1_V"}]},
			{"Name" : "dst_V_2", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "21", "SubInstance" : "grp_buf2stream_fu_161", "Port" : "dst_2_V"}]},
			{"Name" : "dst_V_3", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "21", "SubInstance" : "grp_buf2stream_fu_161", "Port" : "dst_3_V"}]},
			{"Name" : "dst_V_4", "Type" : "Fifo", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "21", "SubInstance" : "grp_buf2stream_fu_161", "Port" : "dst_4_V"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_3_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_4_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_5_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_6_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_7_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_8_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ping_9_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_0_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_1_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_2_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_3_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_4_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_5_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_6_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_7_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_8_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pong_9_U", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_buf2stream_fu_161", "Parent" : "0",
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
			{"Name" : "enable", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_stream2buf_fu_186", "Parent" : "0",
		"CDFG" : "stream2buf",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "12",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "src_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_1_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_1_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_2_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_2_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_3_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_3_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_4_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_4_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_5_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_5_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_6_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_6_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_7_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_7_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_8_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_8_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "src_9_V", "Type" : "Fifo", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "src_9_V_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "buffer_0", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_1", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_2", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_3", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_4", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_5", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_6", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_7", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_8", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "buffer_9", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "enable", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	top {
		src_V_0 {Type I LastRead 2 FirstWrite -1}
		src_V_1 {Type I LastRead 2 FirstWrite -1}
		src_V_2 {Type I LastRead 2 FirstWrite -1}
		src_V_3 {Type I LastRead 2 FirstWrite -1}
		src_V_4 {Type I LastRead 2 FirstWrite -1}
		src_V_5 {Type I LastRead 2 FirstWrite -1}
		src_V_6 {Type I LastRead 2 FirstWrite -1}
		src_V_7 {Type I LastRead 2 FirstWrite -1}
		src_V_8 {Type I LastRead 2 FirstWrite -1}
		src_V_9 {Type I LastRead 2 FirstWrite -1}
		dst_V_0 {Type O LastRead -1 FirstWrite 2}
		dst_V_1 {Type O LastRead -1 FirstWrite 2}
		dst_V_2 {Type O LastRead -1 FirstWrite 2}
		dst_V_3 {Type O LastRead -1 FirstWrite 2}
		dst_V_4 {Type O LastRead -1 FirstWrite 2}}
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
		enable {Type I LastRead 0 FirstWrite -1}}
	stream2buf {
		src_V {Type I LastRead 2 FirstWrite -1}
		src_1_V {Type I LastRead 2 FirstWrite -1}
		src_2_V {Type I LastRead 2 FirstWrite -1}
		src_3_V {Type I LastRead 2 FirstWrite -1}
		src_4_V {Type I LastRead 2 FirstWrite -1}
		src_5_V {Type I LastRead 2 FirstWrite -1}
		src_6_V {Type I LastRead 2 FirstWrite -1}
		src_7_V {Type I LastRead 2 FirstWrite -1}
		src_8_V {Type I LastRead 2 FirstWrite -1}
		src_9_V {Type I LastRead 2 FirstWrite -1}
		buffer_0 {Type O LastRead -1 FirstWrite 2}
		buffer_1 {Type O LastRead -1 FirstWrite 2}
		buffer_2 {Type O LastRead -1 FirstWrite 2}
		buffer_3 {Type O LastRead -1 FirstWrite 2}
		buffer_4 {Type O LastRead -1 FirstWrite 2}
		buffer_5 {Type O LastRead -1 FirstWrite 2}
		buffer_6 {Type O LastRead -1 FirstWrite 2}
		buffer_7 {Type O LastRead -1 FirstWrite 2}
		buffer_8 {Type O LastRead -1 FirstWrite 2}
		buffer_9 {Type O LastRead -1 FirstWrite 2}
		enable {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "49", "Max" : "385"}
	, {"Name" : "Interval", "Min" : "50", "Max" : "386"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	src_V_0 { ap_fifo {  { src_V_0_dout fifo_data 0 32 }  { src_V_0_empty_n fifo_status 0 1 }  { src_V_0_read fifo_update 1 1 } } }
	src_V_1 { ap_fifo {  { src_V_1_dout fifo_data 0 32 }  { src_V_1_empty_n fifo_status 0 1 }  { src_V_1_read fifo_update 1 1 } } }
	src_V_2 { ap_fifo {  { src_V_2_dout fifo_data 0 32 }  { src_V_2_empty_n fifo_status 0 1 }  { src_V_2_read fifo_update 1 1 } } }
	src_V_3 { ap_fifo {  { src_V_3_dout fifo_data 0 32 }  { src_V_3_empty_n fifo_status 0 1 }  { src_V_3_read fifo_update 1 1 } } }
	src_V_4 { ap_fifo {  { src_V_4_dout fifo_data 0 32 }  { src_V_4_empty_n fifo_status 0 1 }  { src_V_4_read fifo_update 1 1 } } }
	src_V_5 { ap_fifo {  { src_V_5_dout fifo_data 0 32 }  { src_V_5_empty_n fifo_status 0 1 }  { src_V_5_read fifo_update 1 1 } } }
	src_V_6 { ap_fifo {  { src_V_6_dout fifo_data 0 32 }  { src_V_6_empty_n fifo_status 0 1 }  { src_V_6_read fifo_update 1 1 } } }
	src_V_7 { ap_fifo {  { src_V_7_dout fifo_data 0 32 }  { src_V_7_empty_n fifo_status 0 1 }  { src_V_7_read fifo_update 1 1 } } }
	src_V_8 { ap_fifo {  { src_V_8_dout fifo_data 0 32 }  { src_V_8_empty_n fifo_status 0 1 }  { src_V_8_read fifo_update 1 1 } } }
	src_V_9 { ap_fifo {  { src_V_9_dout fifo_data 0 32 }  { src_V_9_empty_n fifo_status 0 1 }  { src_V_9_read fifo_update 1 1 } } }
	dst_V_0 { ap_fifo {  { dst_V_0_din fifo_data 1 32 }  { dst_V_0_full_n fifo_status 0 1 }  { dst_V_0_write fifo_update 1 1 } } }
	dst_V_1 { ap_fifo {  { dst_V_1_din fifo_data 1 32 }  { dst_V_1_full_n fifo_status 0 1 }  { dst_V_1_write fifo_update 1 1 } } }
	dst_V_2 { ap_fifo {  { dst_V_2_din fifo_data 1 32 }  { dst_V_2_full_n fifo_status 0 1 }  { dst_V_2_write fifo_update 1 1 } } }
	dst_V_3 { ap_fifo {  { dst_V_3_din fifo_data 1 32 }  { dst_V_3_full_n fifo_status 0 1 }  { dst_V_3_write fifo_update 1 1 } } }
	dst_V_4 { ap_fifo {  { dst_V_4_din fifo_data 1 32 }  { dst_V_4_full_n fifo_status 0 1 }  { dst_V_4_write fifo_update 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
	src_V_0 { fifo_read 32 has_conditional }
	src_V_1 { fifo_read 32 has_conditional }
	src_V_2 { fifo_read 32 has_conditional }
	src_V_3 { fifo_read 32 has_conditional }
	src_V_4 { fifo_read 32 has_conditional }
	src_V_5 { fifo_read 32 has_conditional }
	src_V_6 { fifo_read 32 has_conditional }
	src_V_7 { fifo_read 32 has_conditional }
	src_V_8 { fifo_read 32 has_conditional }
	src_V_9 { fifo_read 32 has_conditional }
	dst_V_0 { fifo_write 32 has_conditional }
	dst_V_1 { fifo_write 32 has_conditional }
	dst_V_2 { fifo_write 32 has_conditional }
	dst_V_3 { fifo_write 32 has_conditional }
	dst_V_4 { fifo_write 32 has_conditional }
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
