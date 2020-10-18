set moduleName stream2buf
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
set C_modelName {stream2buf}
set C_modelType { void 0 }
set C_modelArgList {
	{ src_V int 32 regular {fifo 0 volatile }  }
	{ src_1_V int 32 regular {fifo 0 volatile }  }
	{ src_2_V int 32 regular {fifo 0 volatile }  }
	{ src_3_V int 32 regular {fifo 0 volatile }  }
	{ src_4_V int 32 regular {fifo 0 volatile }  }
	{ src_5_V int 32 regular {fifo 0 volatile }  }
	{ src_6_V int 32 regular {fifo 0 volatile }  }
	{ src_7_V int 32 regular {fifo 0 volatile }  }
	{ src_8_V int 32 regular {fifo 0 volatile }  }
	{ src_9_V int 32 regular {fifo 0 volatile }  }
	{ buffer_0 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_1 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_2 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_3 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_4 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_5 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_6 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_7 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_8 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ buffer_9 int 32 regular {array 10 { 0 3 } 0 1 }  }
	{ enable uint 1 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "src_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_1_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_2_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_3_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_4_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_5_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_6_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_7_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_8_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "src_9_V", "interface" : "fifo", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "buffer_0", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_1", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_2", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_3", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_4", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_5", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_6", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_7", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_8", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "buffer_9", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "enable", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 77
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ src_V_dout sc_in sc_lv 32 signal 0 } 
	{ src_V_empty_n sc_in sc_logic 1 signal 0 } 
	{ src_V_read sc_out sc_logic 1 signal 0 } 
	{ src_1_V_dout sc_in sc_lv 32 signal 1 } 
	{ src_1_V_empty_n sc_in sc_logic 1 signal 1 } 
	{ src_1_V_read sc_out sc_logic 1 signal 1 } 
	{ src_2_V_dout sc_in sc_lv 32 signal 2 } 
	{ src_2_V_empty_n sc_in sc_logic 1 signal 2 } 
	{ src_2_V_read sc_out sc_logic 1 signal 2 } 
	{ src_3_V_dout sc_in sc_lv 32 signal 3 } 
	{ src_3_V_empty_n sc_in sc_logic 1 signal 3 } 
	{ src_3_V_read sc_out sc_logic 1 signal 3 } 
	{ src_4_V_dout sc_in sc_lv 32 signal 4 } 
	{ src_4_V_empty_n sc_in sc_logic 1 signal 4 } 
	{ src_4_V_read sc_out sc_logic 1 signal 4 } 
	{ src_5_V_dout sc_in sc_lv 32 signal 5 } 
	{ src_5_V_empty_n sc_in sc_logic 1 signal 5 } 
	{ src_5_V_read sc_out sc_logic 1 signal 5 } 
	{ src_6_V_dout sc_in sc_lv 32 signal 6 } 
	{ src_6_V_empty_n sc_in sc_logic 1 signal 6 } 
	{ src_6_V_read sc_out sc_logic 1 signal 6 } 
	{ src_7_V_dout sc_in sc_lv 32 signal 7 } 
	{ src_7_V_empty_n sc_in sc_logic 1 signal 7 } 
	{ src_7_V_read sc_out sc_logic 1 signal 7 } 
	{ src_8_V_dout sc_in sc_lv 32 signal 8 } 
	{ src_8_V_empty_n sc_in sc_logic 1 signal 8 } 
	{ src_8_V_read sc_out sc_logic 1 signal 8 } 
	{ src_9_V_dout sc_in sc_lv 32 signal 9 } 
	{ src_9_V_empty_n sc_in sc_logic 1 signal 9 } 
	{ src_9_V_read sc_out sc_logic 1 signal 9 } 
	{ buffer_0_address0 sc_out sc_lv 4 signal 10 } 
	{ buffer_0_ce0 sc_out sc_logic 1 signal 10 } 
	{ buffer_0_we0 sc_out sc_logic 1 signal 10 } 
	{ buffer_0_d0 sc_out sc_lv 32 signal 10 } 
	{ buffer_1_address0 sc_out sc_lv 4 signal 11 } 
	{ buffer_1_ce0 sc_out sc_logic 1 signal 11 } 
	{ buffer_1_we0 sc_out sc_logic 1 signal 11 } 
	{ buffer_1_d0 sc_out sc_lv 32 signal 11 } 
	{ buffer_2_address0 sc_out sc_lv 4 signal 12 } 
	{ buffer_2_ce0 sc_out sc_logic 1 signal 12 } 
	{ buffer_2_we0 sc_out sc_logic 1 signal 12 } 
	{ buffer_2_d0 sc_out sc_lv 32 signal 12 } 
	{ buffer_3_address0 sc_out sc_lv 4 signal 13 } 
	{ buffer_3_ce0 sc_out sc_logic 1 signal 13 } 
	{ buffer_3_we0 sc_out sc_logic 1 signal 13 } 
	{ buffer_3_d0 sc_out sc_lv 32 signal 13 } 
	{ buffer_4_address0 sc_out sc_lv 4 signal 14 } 
	{ buffer_4_ce0 sc_out sc_logic 1 signal 14 } 
	{ buffer_4_we0 sc_out sc_logic 1 signal 14 } 
	{ buffer_4_d0 sc_out sc_lv 32 signal 14 } 
	{ buffer_5_address0 sc_out sc_lv 4 signal 15 } 
	{ buffer_5_ce0 sc_out sc_logic 1 signal 15 } 
	{ buffer_5_we0 sc_out sc_logic 1 signal 15 } 
	{ buffer_5_d0 sc_out sc_lv 32 signal 15 } 
	{ buffer_6_address0 sc_out sc_lv 4 signal 16 } 
	{ buffer_6_ce0 sc_out sc_logic 1 signal 16 } 
	{ buffer_6_we0 sc_out sc_logic 1 signal 16 } 
	{ buffer_6_d0 sc_out sc_lv 32 signal 16 } 
	{ buffer_7_address0 sc_out sc_lv 4 signal 17 } 
	{ buffer_7_ce0 sc_out sc_logic 1 signal 17 } 
	{ buffer_7_we0 sc_out sc_logic 1 signal 17 } 
	{ buffer_7_d0 sc_out sc_lv 32 signal 17 } 
	{ buffer_8_address0 sc_out sc_lv 4 signal 18 } 
	{ buffer_8_ce0 sc_out sc_logic 1 signal 18 } 
	{ buffer_8_we0 sc_out sc_logic 1 signal 18 } 
	{ buffer_8_d0 sc_out sc_lv 32 signal 18 } 
	{ buffer_9_address0 sc_out sc_lv 4 signal 19 } 
	{ buffer_9_ce0 sc_out sc_logic 1 signal 19 } 
	{ buffer_9_we0 sc_out sc_logic 1 signal 19 } 
	{ buffer_9_d0 sc_out sc_lv 32 signal 19 } 
	{ enable sc_in sc_logic 1 signal 20 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "src_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_V", "role": "dout" }} , 
 	{ "name": "src_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V", "role": "empty_n" }} , 
 	{ "name": "src_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_V", "role": "read" }} , 
 	{ "name": "src_1_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_1_V", "role": "dout" }} , 
 	{ "name": "src_1_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_1_V", "role": "empty_n" }} , 
 	{ "name": "src_1_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_1_V", "role": "read" }} , 
 	{ "name": "src_2_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_2_V", "role": "dout" }} , 
 	{ "name": "src_2_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_2_V", "role": "empty_n" }} , 
 	{ "name": "src_2_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_2_V", "role": "read" }} , 
 	{ "name": "src_3_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_3_V", "role": "dout" }} , 
 	{ "name": "src_3_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_3_V", "role": "empty_n" }} , 
 	{ "name": "src_3_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_3_V", "role": "read" }} , 
 	{ "name": "src_4_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_4_V", "role": "dout" }} , 
 	{ "name": "src_4_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_4_V", "role": "empty_n" }} , 
 	{ "name": "src_4_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_4_V", "role": "read" }} , 
 	{ "name": "src_5_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_5_V", "role": "dout" }} , 
 	{ "name": "src_5_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_5_V", "role": "empty_n" }} , 
 	{ "name": "src_5_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_5_V", "role": "read" }} , 
 	{ "name": "src_6_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_6_V", "role": "dout" }} , 
 	{ "name": "src_6_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_6_V", "role": "empty_n" }} , 
 	{ "name": "src_6_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_6_V", "role": "read" }} , 
 	{ "name": "src_7_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_7_V", "role": "dout" }} , 
 	{ "name": "src_7_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_7_V", "role": "empty_n" }} , 
 	{ "name": "src_7_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_7_V", "role": "read" }} , 
 	{ "name": "src_8_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_8_V", "role": "dout" }} , 
 	{ "name": "src_8_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_8_V", "role": "empty_n" }} , 
 	{ "name": "src_8_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_8_V", "role": "read" }} , 
 	{ "name": "src_9_V_dout", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "src_9_V", "role": "dout" }} , 
 	{ "name": "src_9_V_empty_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_9_V", "role": "empty_n" }} , 
 	{ "name": "src_9_V_read", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "src_9_V", "role": "read" }} , 
 	{ "name": "buffer_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_0", "role": "address0" }} , 
 	{ "name": "buffer_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_0", "role": "ce0" }} , 
 	{ "name": "buffer_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_0", "role": "we0" }} , 
 	{ "name": "buffer_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_0", "role": "d0" }} , 
 	{ "name": "buffer_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_1", "role": "address0" }} , 
 	{ "name": "buffer_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_1", "role": "ce0" }} , 
 	{ "name": "buffer_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_1", "role": "we0" }} , 
 	{ "name": "buffer_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_1", "role": "d0" }} , 
 	{ "name": "buffer_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_2", "role": "address0" }} , 
 	{ "name": "buffer_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_2", "role": "ce0" }} , 
 	{ "name": "buffer_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_2", "role": "we0" }} , 
 	{ "name": "buffer_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_2", "role": "d0" }} , 
 	{ "name": "buffer_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_3", "role": "address0" }} , 
 	{ "name": "buffer_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_3", "role": "ce0" }} , 
 	{ "name": "buffer_3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_3", "role": "we0" }} , 
 	{ "name": "buffer_3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_3", "role": "d0" }} , 
 	{ "name": "buffer_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_4", "role": "address0" }} , 
 	{ "name": "buffer_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_4", "role": "ce0" }} , 
 	{ "name": "buffer_4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_4", "role": "we0" }} , 
 	{ "name": "buffer_4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_4", "role": "d0" }} , 
 	{ "name": "buffer_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_5", "role": "address0" }} , 
 	{ "name": "buffer_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_5", "role": "ce0" }} , 
 	{ "name": "buffer_5_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_5", "role": "we0" }} , 
 	{ "name": "buffer_5_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_5", "role": "d0" }} , 
 	{ "name": "buffer_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_6", "role": "address0" }} , 
 	{ "name": "buffer_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_6", "role": "ce0" }} , 
 	{ "name": "buffer_6_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_6", "role": "we0" }} , 
 	{ "name": "buffer_6_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_6", "role": "d0" }} , 
 	{ "name": "buffer_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_7", "role": "address0" }} , 
 	{ "name": "buffer_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_7", "role": "ce0" }} , 
 	{ "name": "buffer_7_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_7", "role": "we0" }} , 
 	{ "name": "buffer_7_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_7", "role": "d0" }} , 
 	{ "name": "buffer_8_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_8", "role": "address0" }} , 
 	{ "name": "buffer_8_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_8", "role": "ce0" }} , 
 	{ "name": "buffer_8_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_8", "role": "we0" }} , 
 	{ "name": "buffer_8_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_8", "role": "d0" }} , 
 	{ "name": "buffer_9_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "buffer_9", "role": "address0" }} , 
 	{ "name": "buffer_9_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_9", "role": "ce0" }} , 
 	{ "name": "buffer_9_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "buffer_9", "role": "we0" }} , 
 	{ "name": "buffer_9_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "buffer_9", "role": "d0" }} , 
 	{ "name": "enable", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "enable", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
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
	{"Name" : "Latency", "Min" : "1", "Max" : "12"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "12"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	src_V { ap_fifo {  { src_V_dout fifo_data 0 32 }  { src_V_empty_n fifo_status 0 1 }  { src_V_read fifo_update 1 1 } } }
	src_1_V { ap_fifo {  { src_1_V_dout fifo_data 0 32 }  { src_1_V_empty_n fifo_status 0 1 }  { src_1_V_read fifo_update 1 1 } } }
	src_2_V { ap_fifo {  { src_2_V_dout fifo_data 0 32 }  { src_2_V_empty_n fifo_status 0 1 }  { src_2_V_read fifo_update 1 1 } } }
	src_3_V { ap_fifo {  { src_3_V_dout fifo_data 0 32 }  { src_3_V_empty_n fifo_status 0 1 }  { src_3_V_read fifo_update 1 1 } } }
	src_4_V { ap_fifo {  { src_4_V_dout fifo_data 0 32 }  { src_4_V_empty_n fifo_status 0 1 }  { src_4_V_read fifo_update 1 1 } } }
	src_5_V { ap_fifo {  { src_5_V_dout fifo_data 0 32 }  { src_5_V_empty_n fifo_status 0 1 }  { src_5_V_read fifo_update 1 1 } } }
	src_6_V { ap_fifo {  { src_6_V_dout fifo_data 0 32 }  { src_6_V_empty_n fifo_status 0 1 }  { src_6_V_read fifo_update 1 1 } } }
	src_7_V { ap_fifo {  { src_7_V_dout fifo_data 0 32 }  { src_7_V_empty_n fifo_status 0 1 }  { src_7_V_read fifo_update 1 1 } } }
	src_8_V { ap_fifo {  { src_8_V_dout fifo_data 0 32 }  { src_8_V_empty_n fifo_status 0 1 }  { src_8_V_read fifo_update 1 1 } } }
	src_9_V { ap_fifo {  { src_9_V_dout fifo_data 0 32 }  { src_9_V_empty_n fifo_status 0 1 }  { src_9_V_read fifo_update 1 1 } } }
	buffer_0 { ap_memory {  { buffer_0_address0 mem_address 1 4 }  { buffer_0_ce0 mem_ce 1 1 }  { buffer_0_we0 mem_we 1 1 }  { buffer_0_d0 mem_din 1 32 } } }
	buffer_1 { ap_memory {  { buffer_1_address0 mem_address 1 4 }  { buffer_1_ce0 mem_ce 1 1 }  { buffer_1_we0 mem_we 1 1 }  { buffer_1_d0 mem_din 1 32 } } }
	buffer_2 { ap_memory {  { buffer_2_address0 mem_address 1 4 }  { buffer_2_ce0 mem_ce 1 1 }  { buffer_2_we0 mem_we 1 1 }  { buffer_2_d0 mem_din 1 32 } } }
	buffer_3 { ap_memory {  { buffer_3_address0 mem_address 1 4 }  { buffer_3_ce0 mem_ce 1 1 }  { buffer_3_we0 mem_we 1 1 }  { buffer_3_d0 mem_din 1 32 } } }
	buffer_4 { ap_memory {  { buffer_4_address0 mem_address 1 4 }  { buffer_4_ce0 mem_ce 1 1 }  { buffer_4_we0 mem_we 1 1 }  { buffer_4_d0 mem_din 1 32 } } }
	buffer_5 { ap_memory {  { buffer_5_address0 mem_address 1 4 }  { buffer_5_ce0 mem_ce 1 1 }  { buffer_5_we0 mem_we 1 1 }  { buffer_5_d0 mem_din 1 32 } } }
	buffer_6 { ap_memory {  { buffer_6_address0 mem_address 1 4 }  { buffer_6_ce0 mem_ce 1 1 }  { buffer_6_we0 mem_we 1 1 }  { buffer_6_d0 mem_din 1 32 } } }
	buffer_7 { ap_memory {  { buffer_7_address0 mem_address 1 4 }  { buffer_7_ce0 mem_ce 1 1 }  { buffer_7_we0 mem_we 1 1 }  { buffer_7_d0 mem_din 1 32 } } }
	buffer_8 { ap_memory {  { buffer_8_address0 mem_address 1 4 }  { buffer_8_ce0 mem_ce 1 1 }  { buffer_8_we0 mem_we 1 1 }  { buffer_8_d0 mem_din 1 32 } } }
	buffer_9 { ap_memory {  { buffer_9_address0 mem_address 1 4 }  { buffer_9_ce0 mem_ce 1 1 }  { buffer_9_we0 mem_we 1 1 }  { buffer_9_d0 mem_din 1 32 } } }
	enable { ap_none {  { enable in_data 0 1 } } }
}
