set moduleName packed_conv_paper
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
set C_modelName {packed_conv_paper}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_r int 10 regular {pointer 0}  }
	{ kernel int 10 regular {pointer 0}  }
	{ output_r int 20 regular {pointer 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_r", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY", "bitSlice":[{"low":0,"up":9,"cElement": [{"cName": "input","cData": "int10","bit_use": { "low": 0,"up": 9},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "kernel", "interface" : "wire", "bitwidth" : 10, "direction" : "READONLY", "bitSlice":[{"low":0,"up":9,"cElement": [{"cName": "kernel","cData": "int10","bit_use": { "low": 0,"up": 9},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "output_r", "interface" : "wire", "bitwidth" : 20, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":19,"cElement": [{"cName": "output","cData": "int20","bit_use": { "low": 0,"up": 19},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 11
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_r sc_in sc_lv 10 signal 0 } 
	{ kernel sc_in sc_lv 10 signal 1 } 
	{ output_r_i sc_in sc_lv 20 signal 2 } 
	{ output_r_o sc_out sc_lv 20 signal 2 } 
	{ output_r_o_ap_vld sc_out sc_logic 1 outvld 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_r", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "input_r", "role": "default" }} , 
 	{ "name": "kernel", "direction": "in", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "kernel", "role": "default" }} , 
 	{ "name": "output_r_i", "direction": "in", "datatype": "sc_lv", "bitwidth":20, "type": "signal", "bundle":{"name": "output_r", "role": "i" }} , 
 	{ "name": "output_r_o", "direction": "out", "datatype": "sc_lv", "bitwidth":20, "type": "signal", "bundle":{"name": "output_r", "role": "o" }} , 
 	{ "name": "output_r_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "output_r", "role": "o_ap_vld" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "packed_conv_paper",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "17285", "EstimateLatencyMax" : "17285",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel", "Type" : "None", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "OVld", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_mul_10ns_10ns_20_4_1_U1", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	packed_conv_paper {
		input_r {Type I LastRead 0 FirstWrite -1}
		kernel {Type I LastRead 0 FirstWrite -1}
		output_r {Type IO LastRead 4 FirstWrite 4}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "17285", "Max" : "17285"}
	, {"Name" : "Interval", "Min" : "17286", "Max" : "17286"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	input_r { ap_none {  { input_r in_data 0 10 } } }
	kernel { ap_none {  { kernel in_data 0 10 } } }
	output_r { ap_ovld {  { output_r_i in_data 0 20 }  { output_r_o out_data 1 20 }  { output_r_o_ap_vld out_vld 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
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
