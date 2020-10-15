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
#define AUTOTB_TVIN_input_buffers "../tv/cdatafile/c.pe.autotvin_input_buffers.dat"
#define AUTOTB_TVOUT_input_buffers "../tv/cdatafile/c.pe.autotvout_input_buffers.dat"
// wrapc file define:
#define AUTOTB_TVIN_weight_stream_V "../tv/cdatafile/c.pe.autotvin_weight_stream_V.dat"
#define AUTOTB_TVOUT_weight_stream_V "../tv/cdatafile/c.pe.autotvout_weight_stream_V.dat"
#define WRAPC_STREAM_SIZE_IN_weight_stream_V "../tv/stream_size/stream_size_in_weight_stream_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_weight_stream_V "../tv/stream_size/stream_ingress_status_weight_stream_V.dat"
// wrapc file define:
#define AUTOTB_TVIN_pe_input_stream_V_0 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_0.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_0 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_0.dat"
#define AUTOTB_TVIN_pe_input_stream_V_1 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_1.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_1 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_1.dat"
#define AUTOTB_TVIN_pe_input_stream_V_2 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_2.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_2 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_2.dat"
#define AUTOTB_TVIN_pe_input_stream_V_3 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_3.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_3 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_3.dat"
#define AUTOTB_TVIN_pe_input_stream_V_4 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_4.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_4 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_4.dat"
#define AUTOTB_TVIN_pe_input_stream_V_5 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_5.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_5 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_5.dat"
#define AUTOTB_TVIN_pe_input_stream_V_6 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_6.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_6 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_6.dat"
#define AUTOTB_TVIN_pe_input_stream_V_7 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_7.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_7 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_7.dat"
#define AUTOTB_TVIN_pe_input_stream_V_8 "../tv/cdatafile/c.pe.autotvin_pe_input_stream_V_8.dat"
#define AUTOTB_TVOUT_pe_input_stream_V_8 "../tv/cdatafile/c.pe.autotvout_pe_input_stream_V_8.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0 "../tv/stream_size/stream_size_out_pe_input_stream_V_0.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_0 "../tv/stream_size/stream_egress_status_pe_input_stream_V_0.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1 "../tv/stream_size/stream_size_out_pe_input_stream_V_1.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_1 "../tv/stream_size/stream_egress_status_pe_input_stream_V_1.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2 "../tv/stream_size/stream_size_out_pe_input_stream_V_2.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_2 "../tv/stream_size/stream_egress_status_pe_input_stream_V_2.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3 "../tv/stream_size/stream_size_out_pe_input_stream_V_3.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_3 "../tv/stream_size/stream_egress_status_pe_input_stream_V_3.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4 "../tv/stream_size/stream_size_out_pe_input_stream_V_4.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_4 "../tv/stream_size/stream_egress_status_pe_input_stream_V_4.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5 "../tv/stream_size/stream_size_out_pe_input_stream_V_5.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_5 "../tv/stream_size/stream_egress_status_pe_input_stream_V_5.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6 "../tv/stream_size/stream_size_out_pe_input_stream_V_6.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_6 "../tv/stream_size/stream_egress_status_pe_input_stream_V_6.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7 "../tv/stream_size/stream_size_out_pe_input_stream_V_7.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_7 "../tv/stream_size/stream_egress_status_pe_input_stream_V_7.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8 "../tv/stream_size/stream_size_out_pe_input_stream_V_8.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_8 "../tv/stream_size/stream_egress_status_pe_input_stream_V_8.dat"
// wrapc file define:
#define AUTOTB_TVIN_pe_weight_stream_V "../tv/cdatafile/c.pe.autotvin_pe_weight_stream_V.dat"
#define AUTOTB_TVOUT_pe_weight_stream_V "../tv/cdatafile/c.pe.autotvout_pe_weight_stream_V.dat"
#define WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V "../tv/stream_size/stream_size_out_pe_weight_stream_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_pe_weight_stream_V "../tv/stream_size/stream_egress_status_pe_weight_stream_V.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_input_buffers "../tv/rtldatafile/rtl.pe.autotvout_input_buffers.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_weight_stream_V "../tv/rtldatafile/rtl.pe.autotvout_weight_stream_V.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pe_input_stream_V_0 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_0.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_1 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_1.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_2 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_2.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_3 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_3.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_4 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_4.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_5 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_5.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_6 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_6.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_7 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_7.dat"
#define AUTOTB_TVOUT_PC_pe_input_stream_V_8 "../tv/rtldatafile/rtl.pe.autotvout_pe_input_stream_V_8.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_pe_weight_stream_V "../tv/rtldatafile/rtl.pe.autotvout_pe_weight_stream_V.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  input_buffers_depth = 0;
  weight_stream_V_depth = 0;
  pe_input_stream_V_0_depth = 0;
  pe_input_stream_V_1_depth = 0;
  pe_input_stream_V_2_depth = 0;
  pe_input_stream_V_3_depth = 0;
  pe_input_stream_V_4_depth = 0;
  pe_input_stream_V_5_depth = 0;
  pe_input_stream_V_6_depth = 0;
  pe_input_stream_V_7_depth = 0;
  pe_input_stream_V_8_depth = 0;
  pe_weight_stream_V_depth = 0;
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
  total_list << "{input_buffers " << input_buffers_depth << "}\n";
  total_list << "{weight_stream_V " << weight_stream_V_depth << "}\n";
  total_list << "{pe_input_stream_V_0 " << pe_input_stream_V_0_depth << "}\n";
  total_list << "{pe_input_stream_V_1 " << pe_input_stream_V_1_depth << "}\n";
  total_list << "{pe_input_stream_V_2 " << pe_input_stream_V_2_depth << "}\n";
  total_list << "{pe_input_stream_V_3 " << pe_input_stream_V_3_depth << "}\n";
  total_list << "{pe_input_stream_V_4 " << pe_input_stream_V_4_depth << "}\n";
  total_list << "{pe_input_stream_V_5 " << pe_input_stream_V_5_depth << "}\n";
  total_list << "{pe_input_stream_V_6 " << pe_input_stream_V_6_depth << "}\n";
  total_list << "{pe_input_stream_V_7 " << pe_input_stream_V_7_depth << "}\n";
  total_list << "{pe_input_stream_V_8 " << pe_input_stream_V_8_depth << "}\n";
  total_list << "{pe_weight_stream_V " << pe_weight_stream_V_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
  public:
    int input_buffers_depth;
    int weight_stream_V_depth;
    int pe_input_stream_V_0_depth;
    int pe_input_stream_V_1_depth;
    int pe_input_stream_V_2_depth;
    int pe_input_stream_V_3_depth;
    int pe_input_stream_V_4_depth;
    int pe_input_stream_V_5_depth;
    int pe_input_stream_V_6_depth;
    int pe_input_stream_V_7_depth;
    int pe_input_stream_V_8_depth;
    int pe_weight_stream_V_depth;
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
struct __cosim_s1__ { char data[1]; };
extern "C" void pe_hw_stub(volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_pe_hw(volatile void * __xlx_apatb_param_input_buffers, volatile void * __xlx_apatb_param_weight_stream, volatile void * __xlx_apatb_param_pe_input_stream, volatile void * __xlx_apatb_param_pe_weight_stream) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;long __xlx_apatb_param_weight_stream_V_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_IN_weight_stream_V);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_weight_stream_V_stream_buf_final_size = atoi(AESL_token.c_str());

            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  for (long i = 0; i < __xlx_apatb_param_weight_stream_V_stream_buf_final_size; ++i)((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->read();
long __xlx_apatb_param_pe_input_stream_V_0_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_0_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_0);
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
          std::vector<sc_bv<8> > pe_input_stream_V_0_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_0_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_0_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_1_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_1_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_1);
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
          std::vector<sc_bv<8> > pe_input_stream_V_1_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_1_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_1_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_2_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_2_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_2);
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
          std::vector<sc_bv<8> > pe_input_stream_V_2_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_2_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_2_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_3_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_3_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_3);
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
          std::vector<sc_bv<8> > pe_input_stream_V_3_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_3_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_3_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_4_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_4_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_4);
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
          std::vector<sc_bv<8> > pe_input_stream_V_4_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_4_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_4_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_5_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_5_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_5);
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
          std::vector<sc_bv<8> > pe_input_stream_V_5_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_5_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_5_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_6_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_6_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_6);
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
          std::vector<sc_bv<8> > pe_input_stream_V_6_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_6_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_6_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_7_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_7_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_7);
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
          std::vector<sc_bv<8> > pe_input_stream_V_7_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_7_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_7_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_input_stream_V_8_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_input_stream_V_8_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_input_stream_V_8);
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
          std::vector<sc_bv<8> > pe_input_stream_V_8_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_input_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_input_stream_V_8_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_input_stream_V_8_pc_buffer[j].to_int64();
          (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->write(xlx_stream_elt);
}
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  long __xlx_apatb_param_pe_weight_stream_V_stream_buf_final_size;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V);
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
          while (AESL_token != "[[/transaction]]"){__xlx_apatb_param_pe_weight_stream_V_stream_buf_final_size = atoi(AESL_token.c_str());

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
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_pe_weight_stream_V);
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
          std::vector<sc_bv<8> > pe_weight_stream_V_pc_buffer;
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "pe_weight_stream_V");
  
            // push token into output port buffer
            if (AESL_token != "") {
              pe_weight_stream_V_pc_buffer.push_back(AESL_token.c_str());
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {for (int j = 0, e = i; j != e; ++j) {
__cosim_s1__ xlx_stream_elt;

            ((char*)&xlx_stream_elt)[0] = pe_weight_stream_V_pc_buffer[j].to_int64();
          ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->write(xlx_stream_elt);
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
//input_buffers
aesl_fh.touch(AUTOTB_TVIN_input_buffers);
aesl_fh.touch(AUTOTB_TVOUT_input_buffers);
//weight_stream_V
aesl_fh.touch(AUTOTB_TVIN_weight_stream_V);
aesl_fh.touch(AUTOTB_TVOUT_weight_stream_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_IN_weight_stream_V);
aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V);
//pe_input_stream_V
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_0);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_0);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_1);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_1);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_2);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_2);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_3);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_3);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_4);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_4);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_5);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_5);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_6);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_6);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_7);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_7);
aesl_fh.touch(AUTOTB_TVIN_pe_input_stream_V_8);
aesl_fh.touch(AUTOTB_TVOUT_pe_input_stream_V_8);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_0);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_1);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_2);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_3);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_4);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_5);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_6);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_7);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_input_stream_V_8);
//pe_weight_stream_V
aesl_fh.touch(AUTOTB_TVIN_pe_weight_stream_V);
aesl_fh.touch(AUTOTB_TVOUT_pe_weight_stream_V);
aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V);
aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_pe_weight_stream_V);
CodeState = DUMP_INPUTS;
// print input_buffers Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_input_buffers, __xlx_sprintf_buffer.data());
  {  if (__xlx_apatb_param_input_buffers) {
    for (int j = 0, e = 54; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)__xlx_apatb_param_input_buffers)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_input_buffers, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(54, &tcl_file.input_buffers_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_input_buffers, __xlx_sprintf_buffer.data());
}
std::vector<__cosim_s1__> __xlx_apatb_param_weight_stream_stream_buf;
{
  while (!((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->empty())
    __xlx_apatb_param_weight_stream_stream_buf.push_back(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->read());
  for (int i = 0; i < __xlx_apatb_param_weight_stream_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->write(__xlx_apatb_param_weight_stream_stream_buf[i]);
  }
long __xlx_apatb_param_weight_stream_stream_buf_size = ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream0_stream_buf;
long __xlx_apatb_param_pe_input_stream0_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream1_stream_buf;
long __xlx_apatb_param_pe_input_stream1_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream2_stream_buf;
long __xlx_apatb_param_pe_input_stream2_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream3_stream_buf;
long __xlx_apatb_param_pe_input_stream3_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream4_stream_buf;
long __xlx_apatb_param_pe_input_stream4_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream5_stream_buf;
long __xlx_apatb_param_pe_input_stream5_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream6_stream_buf;
long __xlx_apatb_param_pe_input_stream6_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream7_stream_buf;
long __xlx_apatb_param_pe_input_stream7_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_input_stream8_stream_buf;
long __xlx_apatb_param_pe_input_stream8_stream_buf_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->size();
std::vector<__cosim_s1__> __xlx_apatb_param_pe_weight_stream_stream_buf;
long __xlx_apatb_param_pe_weight_stream_stream_buf_size = ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->size();
CodeState = CALL_C_DUT;
pe_hw_stub(__xlx_apatb_param_input_buffers, __xlx_apatb_param_weight_stream, __xlx_apatb_param_pe_input_stream, __xlx_apatb_param_pe_weight_stream);
CodeState = DUMP_OUTPUTS;
long __xlx_apatb_param_weight_stream_stream_buf_final_size = __xlx_apatb_param_weight_stream_stream_buf_size - ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->size();
// print weight_stream_V Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_weight_stream_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_stream_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_weight_stream_stream_buf[j])[0];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_weight_stream_V, __xlx_sprintf_buffer.data()); 
  }

  tcl_file.set_num(__xlx_apatb_param_weight_stream_stream_buf_final_size, &tcl_file.weight_stream_V_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_weight_stream_V, __xlx_sprintf_buffer.data());
}

// dump stream ingress status to file
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V, __xlx_sprintf_buffer.data());
  if (__xlx_apatb_param_weight_stream_stream_buf_final_size > 0) {
  long weight_stream_V_stream_ingress_size = __xlx_apatb_param_weight_stream_stream_buf_size;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_stream_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_weight_stream_stream_buf_final_size; j != e; j++) {
    weight_stream_V_stream_ingress_size--;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_stream_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V, __xlx_sprintf_buffer.data());
  }
} else {
  long weight_stream_V_stream_ingress_size = 0;
sprintf(__xlx_sprintf_buffer.data(), "%d\n", weight_stream_V_stream_ingress_size);
 aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V, __xlx_sprintf_buffer.data());
}

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_weight_stream_V, __xlx_sprintf_buffer.data());
}{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_stream_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_weight_stream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_stream_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_IN_weight_stream_V, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream0_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->size() - __xlx_apatb_param_pe_input_stream0_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->empty())
    __xlx_apatb_param_pe_input_stream0_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream0_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[0]))->write(__xlx_apatb_param_pe_input_stream0_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream0_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream0_stream_buf[__xlx_apatb_param_pe_input_stream0_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream0_stream_buf_final_size, &tcl_file.pe_input_stream_V_0_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream0_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_0, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream1_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->size() - __xlx_apatb_param_pe_input_stream1_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->empty())
    __xlx_apatb_param_pe_input_stream1_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream1_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[1]))->write(__xlx_apatb_param_pe_input_stream1_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream1_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream1_stream_buf[__xlx_apatb_param_pe_input_stream1_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream1_stream_buf_final_size, &tcl_file.pe_input_stream_V_1_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream1_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_1, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream2_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->size() - __xlx_apatb_param_pe_input_stream2_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->empty())
    __xlx_apatb_param_pe_input_stream2_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream2_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[2]))->write(__xlx_apatb_param_pe_input_stream2_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream2_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream2_stream_buf[__xlx_apatb_param_pe_input_stream2_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream2_stream_buf_final_size, &tcl_file.pe_input_stream_V_2_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream2_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_2, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream3_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->size() - __xlx_apatb_param_pe_input_stream3_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->empty())
    __xlx_apatb_param_pe_input_stream3_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream3_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[3]))->write(__xlx_apatb_param_pe_input_stream3_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream3_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream3_stream_buf[__xlx_apatb_param_pe_input_stream3_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream3_stream_buf_final_size, &tcl_file.pe_input_stream_V_3_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream3_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_3, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream4_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->size() - __xlx_apatb_param_pe_input_stream4_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->empty())
    __xlx_apatb_param_pe_input_stream4_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream4_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[4]))->write(__xlx_apatb_param_pe_input_stream4_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream4_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream4_stream_buf[__xlx_apatb_param_pe_input_stream4_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream4_stream_buf_final_size, &tcl_file.pe_input_stream_V_4_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream4_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_4, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream5_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->size() - __xlx_apatb_param_pe_input_stream5_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->empty())
    __xlx_apatb_param_pe_input_stream5_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream5_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[5]))->write(__xlx_apatb_param_pe_input_stream5_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream5_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream5_stream_buf[__xlx_apatb_param_pe_input_stream5_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream5_stream_buf_final_size, &tcl_file.pe_input_stream_V_5_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream5_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_5, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream6_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->size() - __xlx_apatb_param_pe_input_stream6_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->empty())
    __xlx_apatb_param_pe_input_stream6_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream6_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[6]))->write(__xlx_apatb_param_pe_input_stream6_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream6_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream6_stream_buf[__xlx_apatb_param_pe_input_stream6_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream6_stream_buf_final_size, &tcl_file.pe_input_stream_V_6_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream6_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_6, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream7_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->size() - __xlx_apatb_param_pe_input_stream7_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->empty())
    __xlx_apatb_param_pe_input_stream7_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream7_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[7]))->write(__xlx_apatb_param_pe_input_stream7_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream7_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream7_stream_buf[__xlx_apatb_param_pe_input_stream7_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream7_stream_buf_final_size, &tcl_file.pe_input_stream_V_7_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream7_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_7, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_input_stream8_stream_buf_final_size = (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->size() - __xlx_apatb_param_pe_input_stream8_stream_buf_size;
{
  while (!(&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->empty())
    __xlx_apatb_param_pe_input_stream8_stream_buf.push_back((&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->read());
  for (int i = 0; i < __xlx_apatb_param_pe_input_stream8_stream_buf.size(); ++i)
    (&(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)[8]))->write(__xlx_apatb_param_pe_input_stream8_stream_buf[i]);
  }

  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_input_stream8_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_input_stream8_stream_buf[__xlx_apatb_param_pe_input_stream8_stream_buf_size+j])[0];
sprintf(__xlx_sprintf_buffer.data(), "%s\n",__xlx_tmp_lv.to_string(SC_HEX).c_str());
aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());
}
tcl_file.set_num(__xlx_apatb_param_pe_input_stream8_stream_buf_final_size, &tcl_file.pe_input_stream_V_8_depth);

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_input_stream8_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_input_stream_V_8, __xlx_sprintf_buffer.data());
}long __xlx_apatb_param_pe_weight_stream_stream_buf_final_size = ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->size() - __xlx_apatb_param_pe_weight_stream_stream_buf_size;
{
  while (!((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->empty())
    __xlx_apatb_param_pe_weight_stream_stream_buf.push_back(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->read());
  for (int i = 0; i < __xlx_apatb_param_pe_weight_stream_stream_buf.size(); ++i)
    ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->write(__xlx_apatb_param_pe_weight_stream_stream_buf[i]);
  }
// print pe_weight_stream_V Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_pe_weight_stream_V, __xlx_sprintf_buffer.data());
  for (int j = 0, e = __xlx_apatb_param_pe_weight_stream_stream_buf_final_size; j != e; ++j) {
sc_bv<8> __xlx_tmp_lv = ((char*)&__xlx_apatb_param_pe_weight_stream_stream_buf[__xlx_apatb_param_pe_weight_stream_stream_buf_size+j])[0];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_pe_weight_stream_V, __xlx_sprintf_buffer.data()); 
  }

  tcl_file.set_num(__xlx_apatb_param_pe_weight_stream_stream_buf_final_size, &tcl_file.pe_weight_stream_V_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_pe_weight_stream_V, __xlx_sprintf_buffer.data());
}
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V, __xlx_sprintf_buffer.data());
  sprintf(__xlx_sprintf_buffer.data(), "%d\n", __xlx_apatb_param_pe_weight_stream_stream_buf_final_size);
 aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V, __xlx_sprintf_buffer.data());

  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(WRAPC_STREAM_SIZE_OUT_pe_weight_stream_V, __xlx_sprintf_buffer.data());
}CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
