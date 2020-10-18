#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_src_V_0 "../tv/cdatafile/c.top.autotvin_src_V_0.dat"
#define AUTOTB_TVOUT_src_V_0 "../tv/cdatafile/c.top.autotvout_src_V_0.dat"
#define AUTOTB_TVIN_src_V_1 "../tv/cdatafile/c.top.autotvin_src_V_1.dat"
#define AUTOTB_TVOUT_src_V_1 "../tv/cdatafile/c.top.autotvout_src_V_1.dat"
#define AUTOTB_TVIN_src_V_2 "../tv/cdatafile/c.top.autotvin_src_V_2.dat"
#define AUTOTB_TVOUT_src_V_2 "../tv/cdatafile/c.top.autotvout_src_V_2.dat"
#define AUTOTB_TVIN_src_V_3 "../tv/cdatafile/c.top.autotvin_src_V_3.dat"
#define AUTOTB_TVOUT_src_V_3 "../tv/cdatafile/c.top.autotvout_src_V_3.dat"
#define AUTOTB_TVIN_src_V_4 "../tv/cdatafile/c.top.autotvin_src_V_4.dat"
#define AUTOTB_TVOUT_src_V_4 "../tv/cdatafile/c.top.autotvout_src_V_4.dat"
#define AUTOTB_TVIN_src_V_5 "../tv/cdatafile/c.top.autotvin_src_V_5.dat"
#define AUTOTB_TVOUT_src_V_5 "../tv/cdatafile/c.top.autotvout_src_V_5.dat"
#define AUTOTB_TVIN_src_V_6 "../tv/cdatafile/c.top.autotvin_src_V_6.dat"
#define AUTOTB_TVOUT_src_V_6 "../tv/cdatafile/c.top.autotvout_src_V_6.dat"
#define AUTOTB_TVIN_src_V_7 "../tv/cdatafile/c.top.autotvin_src_V_7.dat"
#define AUTOTB_TVOUT_src_V_7 "../tv/cdatafile/c.top.autotvout_src_V_7.dat"
#define AUTOTB_TVIN_src_V_8 "../tv/cdatafile/c.top.autotvin_src_V_8.dat"
#define AUTOTB_TVOUT_src_V_8 "../tv/cdatafile/c.top.autotvout_src_V_8.dat"
#define AUTOTB_TVIN_src_V_9 "../tv/cdatafile/c.top.autotvin_src_V_9.dat"
#define AUTOTB_TVOUT_src_V_9 "../tv/cdatafile/c.top.autotvout_src_V_9.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_0 "../tv/stream_size/stream_size_in_src_V_0.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_0 "../tv/stream_size/stream_ingress_status_src_V_0.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_1 "../tv/stream_size/stream_size_in_src_V_1.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_1 "../tv/stream_size/stream_ingress_status_src_V_1.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_2 "../tv/stream_size/stream_size_in_src_V_2.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_2 "../tv/stream_size/stream_ingress_status_src_V_2.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_3 "../tv/stream_size/stream_size_in_src_V_3.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_3 "../tv/stream_size/stream_ingress_status_src_V_3.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_4 "../tv/stream_size/stream_size_in_src_V_4.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_4 "../tv/stream_size/stream_ingress_status_src_V_4.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_5 "../tv/stream_size/stream_size_in_src_V_5.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_5 "../tv/stream_size/stream_ingress_status_src_V_5.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_6 "../tv/stream_size/stream_size_in_src_V_6.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_6 "../tv/stream_size/stream_ingress_status_src_V_6.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_7 "../tv/stream_size/stream_size_in_src_V_7.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_7 "../tv/stream_size/stream_ingress_status_src_V_7.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_8 "../tv/stream_size/stream_size_in_src_V_8.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_8 "../tv/stream_size/stream_ingress_status_src_V_8.dat"
#define WRAPC_STREAM_SIZE_IN_src_V_9 "../tv/stream_size/stream_size_in_src_V_9.dat"
#define WRAPC_STREAM_INGRESS_STATUS_src_V_9 "../tv/stream_size/stream_ingress_status_src_V_9.dat"
// wrapc file define:
#define AUTOTB_TVIN_dst_V_0 "../tv/cdatafile/c.top.autotvin_dst_V_0.dat"
#define AUTOTB_TVOUT_dst_V_0 "../tv/cdatafile/c.top.autotvout_dst_V_0.dat"
#define AUTOTB_TVIN_dst_V_1 "../tv/cdatafile/c.top.autotvin_dst_V_1.dat"
#define AUTOTB_TVOUT_dst_V_1 "../tv/cdatafile/c.top.autotvout_dst_V_1.dat"
#define AUTOTB_TVIN_dst_V_2 "../tv/cdatafile/c.top.autotvin_dst_V_2.dat"
#define AUTOTB_TVOUT_dst_V_2 "../tv/cdatafile/c.top.autotvout_dst_V_2.dat"
#define AUTOTB_TVIN_dst_V_3 "../tv/cdatafile/c.top.autotvin_dst_V_3.dat"
#define AUTOTB_TVOUT_dst_V_3 "../tv/cdatafile/c.top.autotvout_dst_V_3.dat"
#define AUTOTB_TVIN_dst_V_4 "../tv/cdatafile/c.top.autotvin_dst_V_4.dat"
#define AUTOTB_TVOUT_dst_V_4 "../tv/cdatafile/c.top.autotvout_dst_V_4.dat"
#define WRAPC_STREAM_SIZE_OUT_dst_V_0 "../tv/stream_size/stream_size_out_dst_V_0.dat"
#define WRAPC_STREAM_EGRESS_STATUS_dst_V_0 "../tv/stream_size/stream_egress_status_dst_V_0.dat"
#define WRAPC_STREAM_SIZE_OUT_dst_V_1 "../tv/stream_size/stream_size_out_dst_V_1.dat"
#define WRAPC_STREAM_EGRESS_STATUS_dst_V_1 "../tv/stream_size/stream_egress_status_dst_V_1.dat"
#define WRAPC_STREAM_SIZE_OUT_dst_V_2 "../tv/stream_size/stream_size_out_dst_V_2.dat"
#define WRAPC_STREAM_EGRESS_STATUS_dst_V_2 "../tv/stream_size/stream_egress_status_dst_V_2.dat"
#define WRAPC_STREAM_SIZE_OUT_dst_V_3 "../tv/stream_size/stream_size_out_dst_V_3.dat"
#define WRAPC_STREAM_EGRESS_STATUS_dst_V_3 "../tv/stream_size/stream_egress_status_dst_V_3.dat"
#define WRAPC_STREAM_SIZE_OUT_dst_V_4 "../tv/stream_size/stream_size_out_dst_V_4.dat"
#define WRAPC_STREAM_EGRESS_STATUS_dst_V_4 "../tv/stream_size/stream_egress_status_dst_V_4.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_src_V_0 "../tv/rtldatafile/rtl.top.autotvout_src_V_0.dat"
#define AUTOTB_TVOUT_PC_src_V_1 "../tv/rtldatafile/rtl.top.autotvout_src_V_1.dat"
#define AUTOTB_TVOUT_PC_src_V_2 "../tv/rtldatafile/rtl.top.autotvout_src_V_2.dat"
#define AUTOTB_TVOUT_PC_src_V_3 "../tv/rtldatafile/rtl.top.autotvout_src_V_3.dat"
#define AUTOTB_TVOUT_PC_src_V_4 "../tv/rtldatafile/rtl.top.autotvout_src_V_4.dat"
#define AUTOTB_TVOUT_PC_src_V_5 "../tv/rtldatafile/rtl.top.autotvout_src_V_5.dat"
#define AUTOTB_TVOUT_PC_src_V_6 "../tv/rtldatafile/rtl.top.autotvout_src_V_6.dat"
#define AUTOTB_TVOUT_PC_src_V_7 "../tv/rtldatafile/rtl.top.autotvout_src_V_7.dat"
#define AUTOTB_TVOUT_PC_src_V_8 "../tv/rtldatafile/rtl.top.autotvout_src_V_8.dat"
#define AUTOTB_TVOUT_PC_src_V_9 "../tv/rtldatafile/rtl.top.autotvout_src_V_9.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_dst_V_0 "../tv/rtldatafile/rtl.top.autotvout_dst_V_0.dat"
#define AUTOTB_TVOUT_PC_dst_V_1 "../tv/rtldatafile/rtl.top.autotvout_dst_V_1.dat"
#define AUTOTB_TVOUT_PC_dst_V_2 "../tv/rtldatafile/rtl.top.autotvout_dst_V_2.dat"
#define AUTOTB_TVOUT_PC_dst_V_3 "../tv/rtldatafile/rtl.top.autotvout_dst_V_3.dat"
#define AUTOTB_TVOUT_PC_dst_V_4 "../tv/rtldatafile/rtl.top.autotvout_dst_V_4.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  src_V_0_depth = 0;
  src_V_1_depth = 0;
  src_V_2_depth = 0;
  src_V_3_depth = 0;
  src_V_4_depth = 0;
  src_V_5_depth = 0;
  src_V_6_depth = 0;
  src_V_7_depth = 0;
  src_V_8_depth = 0;
  src_V_9_depth = 0;
  dst_V_0_depth = 0;
  dst_V_1_depth = 0;
  dst_V_2_depth = 0;
  dst_V_3_depth = 0;
  dst_V_4_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{src_V_0 " << src_V_0_depth << "}\n";
  total_list << "{src_V_1 " << src_V_1_depth << "}\n";
  total_list << "{src_V_2 " << src_V_2_depth << "}\n";
  total_list << "{src_V_3 " << src_V_3_depth << "}\n";
  total_list << "{src_V_4 " << src_V_4_depth << "}\n";
  total_list << "{src_V_5 " << src_V_5_depth << "}\n";
  total_list << "{src_V_6 " << src_V_6_depth << "}\n";
  total_list << "{src_V_7 " << src_V_7_depth << "}\n";
  total_list << "{src_V_8 " << src_V_8_depth << "}\n";
  total_list << "{src_V_9 " << src_V_9_depth << "}\n";
  total_list << "{dst_V_0 " << dst_V_0_depth << "}\n";
  total_list << "{dst_V_1 " << dst_V_1_depth << "}\n";
  total_list << "{dst_V_2 " << dst_V_2_depth << "}\n";
  total_list << "{dst_V_3 " << dst_V_3_depth << "}\n";
  total_list << "{dst_V_4 " << dst_V_4_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
  public:
    int src_V_0_depth;
    int src_V_1_depth;
    int src_V_2_depth;
    int src_V_3_depth;
    int src_V_4_depth;
    int src_V_5_depth;
    int src_V_6_depth;
    int src_V_7_depth;
    int src_V_8_depth;
    int src_V_9_depth;
    int dst_V_0_depth;
    int dst_V_1_depth;
    int dst_V_2_depth;
    int dst_V_3_depth;
    int dst_V_4_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void top_hw_stub(volatile void *, volatile void *);

extern "C" void apatb_top_hw(volatile void * __xlx_apatb_param_src, volatile void * __xlx_apatb_param_dst) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;long __xlx_apatb_param_src_V_0_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_0_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_0_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->read();
long __xlx_apatb_param_src_V_1_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_1_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_1_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->read();
long __xlx_apatb_param_src_V_2_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_2_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_2_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->read();
long __xlx_apatb_param_src_V_3_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_3_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_3_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->read();
long __xlx_apatb_param_src_V_4_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_4_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_4_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->read();
long __xlx_apatb_param_src_V_5_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_5);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_5_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_5_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->read();
long __xlx_apatb_param_src_V_6_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_6);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_6_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_6_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->read();
long __xlx_apatb_param_src_V_7_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_7);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_7_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_7_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->read();
long __xlx_apatb_param_src_V_8_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_8);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_8_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_8_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->read();
long __xlx_apatb_param_src_V_9_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_src_V_9);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_src_V_9_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_src_V_9_stream_buf_final_size; ++i)(&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->read();
long __xlx_apatb_param_dst_V_0_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_dst_V_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_dst_V_0_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dst_V_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dst_V_0_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dst_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dst_V_0_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
int xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = dst_V_0_pc_buffer[j].to_int64();
          (&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_dst_V_1_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_dst_V_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_dst_V_1_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dst_V_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dst_V_1_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dst_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dst_V_1_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
int xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = dst_V_1_pc_buffer[j].to_int64();
          (&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_dst_V_2_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_dst_V_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_dst_V_2_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dst_V_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dst_V_2_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dst_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dst_V_2_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
int xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = dst_V_2_pc_buffer[j].to_int64();
          (&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_dst_V_3_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_dst_V_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_dst_V_3_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dst_V_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dst_V_3_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dst_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dst_V_3_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
int xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = dst_V_3_pc_buffer[j].to_int64();
          (&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_dst_V_4_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_dst_V_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_dst_V_4_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_dst_V_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > dst_V_4_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "dst_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              dst_V_4_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
int xlx_stream_elt;

            ((int*)&xlx_stream_elt)[0] = dst_V_4_pc_buffer[j].to_int64();
          (&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//src_V
aesl_fh.touch(AUTOTB_TVIN_src_V_0);
aesl_fh.touch(AUTOTB_TVOUT_src_V_0);
aesl_fh.touch(AUTOTB_TVIN_src_V_1);
aesl_fh.touch(AUTOTB_TVOUT_src_V_1);
aesl_fh.touch(AUTOTB_TVIN_src_V_2);
aesl_fh.touch(AUTOTB_TVOUT_src_V_2);
aesl_fh.touch(AUTOTB_TVIN_src_V_3);
aesl_fh.touch(AUTOTB_TVOUT_src_V_3);
aesl_fh.touch(AUTOTB_TVIN_src_V_4);
aesl_fh.touch(AUTOTB_TVOUT_src_V_4);
aesl_fh.touch(AUTOTB_TVIN_src_V_5);
aesl_fh.touch(AUTOTB_TVOUT_src_V_5);
aesl_fh.touch(AUTOTB_TVIN_src_V_6);
aesl_fh.touch(AUTOTB_TVOUT_src_V_6);
aesl_fh.touch(AUTOTB_TVIN_src_V_7);
aesl_fh.touch(AUTOTB_TVOUT_src_V_7);
aesl_fh.touch(AUTOTB_TVIN_src_V_8);
aesl_fh.touch(AUTOTB_TVOUT_src_V_8);
aesl_fh.touch(AUTOTB_TVIN_src_V_9);
aesl_fh.touch(AUTOTB_TVOUT_src_V_9);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_0);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_0);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_1);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_1);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_2);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_2);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_3);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_3);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_4);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_4);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_5);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_5);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_6);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_6);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_7);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_7);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_8);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_8);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_src_V_9);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_src_V_9);
//dst_V
aesl_fh.touch(AUTOTB_TVIN_dst_V_0);
aesl_fh.touch(AUTOTB_TVOUT_dst_V_0);
aesl_fh.touch(AUTOTB_TVIN_dst_V_1);
aesl_fh.touch(AUTOTB_TVOUT_dst_V_1);
aesl_fh.touch(AUTOTB_TVIN_dst_V_2);
aesl_fh.touch(AUTOTB_TVOUT_dst_V_2);
aesl_fh.touch(AUTOTB_TVIN_dst_V_3);
aesl_fh.touch(AUTOTB_TVOUT_dst_V_3);
aesl_fh.touch(AUTOTB_TVIN_dst_V_4);
aesl_fh.touch(AUTOTB_TVOUT_dst_V_4);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_dst_V_0);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_dst_V_0);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_dst_V_1);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_dst_V_1);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_dst_V_2);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_dst_V_2);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_dst_V_3);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_dst_V_3);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_dst_V_4);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_dst_V_4);
CodeState = DUMP_INPUTS;
std::vector<int> __xlx_apatb_param_src0_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->empty())
    __xlx_apatb_param_src0_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->read());
  for (int i = 0; i < __xlx_apatb_param_src0_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->write(__xlx_apatb_param_src0_stream_buf[i]);
  }
long __xlx_apatb_param_src0_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->size();
std::vector<int> __xlx_apatb_param_src1_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->empty())
    __xlx_apatb_param_src1_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->read());
  for (int i = 0; i < __xlx_apatb_param_src1_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->write(__xlx_apatb_param_src1_stream_buf[i]);
  }
long __xlx_apatb_param_src1_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->size();
std::vector<int> __xlx_apatb_param_src2_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->empty())
    __xlx_apatb_param_src2_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->read());
  for (int i = 0; i < __xlx_apatb_param_src2_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->write(__xlx_apatb_param_src2_stream_buf[i]);
  }
long __xlx_apatb_param_src2_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->size();
std::vector<int> __xlx_apatb_param_src3_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->empty())
    __xlx_apatb_param_src3_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->read());
  for (int i = 0; i < __xlx_apatb_param_src3_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->write(__xlx_apatb_param_src3_stream_buf[i]);
  }
long __xlx_apatb_param_src3_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->size();
std::vector<int> __xlx_apatb_param_src4_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->empty())
    __xlx_apatb_param_src4_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->read());
  for (int i = 0; i < __xlx_apatb_param_src4_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->write(__xlx_apatb_param_src4_stream_buf[i]);
  }
long __xlx_apatb_param_src4_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->size();
std::vector<int> __xlx_apatb_param_src5_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->empty())
    __xlx_apatb_param_src5_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->read());
  for (int i = 0; i < __xlx_apatb_param_src5_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->write(__xlx_apatb_param_src5_stream_buf[i]);
  }
long __xlx_apatb_param_src5_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->size();
std::vector<int> __xlx_apatb_param_src6_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->empty())
    __xlx_apatb_param_src6_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->read());
  for (int i = 0; i < __xlx_apatb_param_src6_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->write(__xlx_apatb_param_src6_stream_buf[i]);
  }
long __xlx_apatb_param_src6_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->size();
std::vector<int> __xlx_apatb_param_src7_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->empty())
    __xlx_apatb_param_src7_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->read());
  for (int i = 0; i < __xlx_apatb_param_src7_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->write(__xlx_apatb_param_src7_stream_buf[i]);
  }
long __xlx_apatb_param_src7_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->size();
std::vector<int> __xlx_apatb_param_src8_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->empty())
    __xlx_apatb_param_src8_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->read());
  for (int i = 0; i < __xlx_apatb_param_src8_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->write(__xlx_apatb_param_src8_stream_buf[i]);
  }
long __xlx_apatb_param_src8_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->size();
std::vector<int> __xlx_apatb_param_src9_stream_buf;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->empty())
    __xlx_apatb_param_src9_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->read());
  for (int i = 0; i < __xlx_apatb_param_src9_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->write(__xlx_apatb_param_src9_stream_buf[i]);
  }
long __xlx_apatb_param_src9_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->size();
std::vector<int> __xlx_apatb_param_dst0_stream_buf;
long __xlx_apatb_param_dst0_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->size();
std::vector<int> __xlx_apatb_param_dst1_stream_buf;
long __xlx_apatb_param_dst1_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->size();
std::vector<int> __xlx_apatb_param_dst2_stream_buf;
long __xlx_apatb_param_dst2_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->size();
std::vector<int> __xlx_apatb_param_dst3_stream_buf;
long __xlx_apatb_param_dst3_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->size();
std::vector<int> __xlx_apatb_param_dst4_stream_buf;
long __xlx_apatb_param_dst4_stream_buf_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->size();
CodeState = CALL_C_DUT;
top_hw_stub(__xlx_apatb_param_src, __xlx_apatb_param_dst);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_src0_stream_buf_final_size = __xlx_apatb_param_src0_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[0]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_0, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src0_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src0_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_0, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src0_stream_buf_final_size, &tcl_file.src_V_0_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_0, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_0, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src0_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_0, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_0, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src1_stream_buf_final_size = __xlx_apatb_param_src1_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[1]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_1, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src1_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src1_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_1, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src1_stream_buf_final_size, &tcl_file.src_V_1_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_1, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_1, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src1_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_1, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_1, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src2_stream_buf_final_size = __xlx_apatb_param_src2_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[2]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_2, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src2_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src2_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_2, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src2_stream_buf_final_size, &tcl_file.src_V_2_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_2, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_2, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src2_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_2, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_2, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src3_stream_buf_final_size = __xlx_apatb_param_src3_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[3]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_3, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src3_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src3_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_3, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src3_stream_buf_final_size, &tcl_file.src_V_3_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_3, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_3, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src3_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_3, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_3, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src4_stream_buf_final_size = __xlx_apatb_param_src4_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[4]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_4, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src4_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src4_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_4, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src4_stream_buf_final_size, &tcl_file.src_V_4_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_4, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_4, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src4_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_4, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_4, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src5_stream_buf_final_size = __xlx_apatb_param_src5_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[5]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_5, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src5_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src5_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_5, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src5_stream_buf_final_size, &tcl_file.src_V_5_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_5, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_5, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src5_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_5, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_5, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src6_stream_buf_final_size = __xlx_apatb_param_src6_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[6]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_6, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src6_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src6_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_6, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src6_stream_buf_final_size, &tcl_file.src_V_6_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_6, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_6, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src6_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_6, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_6, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src7_stream_buf_final_size = __xlx_apatb_param_src7_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[7]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_7, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src7_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src7_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_7, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src7_stream_buf_final_size, &tcl_file.src_V_7_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_7, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_7, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src7_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_7, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_7, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src8_stream_buf_final_size = __xlx_apatb_param_src8_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[8]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_8, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src8_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src8_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_8, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src8_stream_buf_final_size, &tcl_file.src_V_8_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_8, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_8, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src8_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_8, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_8, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_src9_stream_buf_final_size = __xlx_apatb_param_src9_stream_buf_size - (&(((hls::stream<int>*)__xlx_apatb_param_src)[9]))->size();

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_src_V_9, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_src9_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_src9_stream_buf[j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVIN_src_V_9, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_src9_stream_buf_final_size, &tcl_file.src_V_9_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_src_V_9, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_9, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_src9_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_9, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_src_V_9, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_dst0_stream_buf_final_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->size() - __xlx_apatb_param_dst0_stream_buf_size;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->empty())
    __xlx_apatb_param_dst0_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->read());
  for (int i = 0; i < __xlx_apatb_param_dst0_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_dst)[0]))->write(__xlx_apatb_param_dst0_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dst_V_0, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_dst0_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_dst0_stream_buf[__xlx_apatb_param_dst0_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_dst_V_0, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_dst0_stream_buf_final_size, &tcl_file.dst_V_0_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dst_V_0, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_0, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_dst0_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_0, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_0, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_dst1_stream_buf_final_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->size() - __xlx_apatb_param_dst1_stream_buf_size;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->empty())
    __xlx_apatb_param_dst1_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->read());
  for (int i = 0; i < __xlx_apatb_param_dst1_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_dst)[1]))->write(__xlx_apatb_param_dst1_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dst_V_1, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_dst1_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_dst1_stream_buf[__xlx_apatb_param_dst1_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_dst_V_1, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_dst1_stream_buf_final_size, &tcl_file.dst_V_1_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dst_V_1, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_1, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_dst1_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_1, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_1, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_dst2_stream_buf_final_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->size() - __xlx_apatb_param_dst2_stream_buf_size;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->empty())
    __xlx_apatb_param_dst2_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->read());
  for (int i = 0; i < __xlx_apatb_param_dst2_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_dst)[2]))->write(__xlx_apatb_param_dst2_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dst_V_2, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_dst2_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_dst2_stream_buf[__xlx_apatb_param_dst2_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_dst_V_2, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_dst2_stream_buf_final_size, &tcl_file.dst_V_2_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dst_V_2, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_2, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_dst2_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_2, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_2, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_dst3_stream_buf_final_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->size() - __xlx_apatb_param_dst3_stream_buf_size;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->empty())
    __xlx_apatb_param_dst3_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->read());
  for (int i = 0; i < __xlx_apatb_param_dst3_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_dst)[3]))->write(__xlx_apatb_param_dst3_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dst_V_3, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_dst3_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_dst3_stream_buf[__xlx_apatb_param_dst3_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_dst_V_3, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_dst3_stream_buf_final_size, &tcl_file.dst_V_3_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dst_V_3, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_3, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_dst3_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_3, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_3, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_dst4_stream_buf_final_size = (&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->size() - __xlx_apatb_param_dst4_stream_buf_size;
{
  while (!(&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->empty())
    __xlx_apatb_param_dst4_stream_buf.push_back((&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->read());
  for (int i = 0; i < __xlx_apatb_param_dst4_stream_buf.size(); ++i)
    (&(((hls::stream<int>*)__xlx_apatb_param_dst)[4]))->write(__xlx_apatb_param_dst4_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_dst_V_4, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_dst4_stream_buf_final_size; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)&__xlx_apatb_param_dst4_stream_buf[__xlx_apatb_param_dst4_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_dst_V_4, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_dst4_stream_buf_final_size, &tcl_file.dst_V_4_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_dst_V_4, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_4, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_dst4_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_4, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_dst_V_4, __xlx_sprintf_buffer.data());
}CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
