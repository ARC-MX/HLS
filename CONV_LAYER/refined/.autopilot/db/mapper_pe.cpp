#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
unsigned int ap_apatb_weight_stream_V_cap_bc;
static AESL_RUNTIME_BC __xlx_weight_stream_V_size_Reader("../tv/stream_size/stream_size_in_weight_stream_V.dat");
unsigned int ap_apatb_pe_input_stream_V_cap_bc;
static AESL_RUNTIME_BC __xlx_pe_input_stream_V_size_Reader("../tv/stream_size/stream_size_out_pe_input_stream_V.dat");
unsigned int ap_apatb_pe_weight_stream_V_cap_bc;
static AESL_RUNTIME_BC __xlx_pe_weight_stream_V_size_Reader("../tv/stream_size/stream_size_out_pe_weight_stream_V.dat");
struct __cosim_s1__ { char data[1]; };
extern "C" void pe(char*, __cosim_s1__*, __cosim_s1__*, __cosim_s1__*);
extern "C" void apatb_pe_hw(volatile void * __xlx_apatb_param_input_buffers, volatile void * __xlx_apatb_param_weight_stream, volatile void * __xlx_apatb_param_pe_input_stream, volatile void * __xlx_apatb_param_pe_weight_stream) {
  // Collect __xlx_input_buffers__tmp_vec
  vector<sc_bv<8> >__xlx_input_buffers__tmp_vec;
  for (int j = 0, e = 54; j != e; ++j) {
    __xlx_input_buffers__tmp_vec.push_back(((char*)__xlx_apatb_param_input_buffers)[j]);
  }
  int __xlx_size_param_input_buffers = 54;
  int __xlx_offset_param_input_buffers = 0;
  int __xlx_offset_byte_param_input_buffers = 0*1;
  char* __xlx_input_buffers__input_buffer= new char[__xlx_input_buffers__tmp_vec.size()];
  for (int i = 0; i < __xlx_input_buffers__tmp_vec.size(); ++i) {
    __xlx_input_buffers__input_buffer[i] = __xlx_input_buffers__tmp_vec[i].range(7, 0).to_uint64();
  }
  // collect __xlx_weight_stream_tmp_vec
  unsigned __xlx_weight_stream_V_tmp_Count = 0;
  unsigned __xlx_weight_stream_V_read_Size = __xlx_weight_stream_V_size_Reader.read_size();
  vector<__cosim_s1__> __xlx_weight_stream_tmp_vec;
  while (!((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->empty() && __xlx_weight_stream_V_tmp_Count < __xlx_weight_stream_V_read_Size) {
    __xlx_weight_stream_tmp_vec.push_back(((hls::stream<__cosim_s1__>*)__xlx_apatb_param_weight_stream)->read());
    __xlx_weight_stream_V_tmp_Count++;
  }
  ap_apatb_weight_stream_V_cap_bc = __xlx_weight_stream_tmp_vec.size();
  // store input buffer
  __cosim_s1__* __xlx_weight_stream_input_buffer= new __cosim_s1__[__xlx_weight_stream_tmp_vec.size()];
  for (int i = 0; i < __xlx_weight_stream_tmp_vec.size(); ++i) {
    __xlx_weight_stream_input_buffer[i] = __xlx_weight_stream_tmp_vec[i];
  }
  //Create input buffer for pe_input_stream
  ap_apatb_pe_input_stream_V_cap_bc = __xlx_pe_input_stream_V_size_Reader.read_size();
  __cosim_s1__* __xlx_pe_input_stream_input_buffer= new __cosim_s1__[ap_apatb_pe_input_stream_V_cap_bc];
  //Create input buffer for pe_weight_stream
  ap_apatb_pe_weight_stream_V_cap_bc = __xlx_pe_weight_stream_V_size_Reader.read_size();
  __cosim_s1__* __xlx_pe_weight_stream_input_buffer= new __cosim_s1__[ap_apatb_pe_weight_stream_V_cap_bc];
  // DUT call
  pe(__xlx_input_buffers__input_buffer, __xlx_weight_stream_input_buffer, __xlx_pe_input_stream_input_buffer, __xlx_pe_weight_stream_input_buffer);
// print __xlx_apatb_param_input_buffers
  sc_bv<8>*__xlx_input_buffers_output_buffer = new sc_bv<8>[__xlx_size_param_input_buffers];
  for (int i = 0; i < __xlx_size_param_input_buffers; ++i) {
    __xlx_input_buffers_output_buffer[i] = __xlx_input_buffers__input_buffer[i+__xlx_offset_param_input_buffers];
  }
  for (int i = 0; i < __xlx_size_param_input_buffers; ++i) {
    ((char*)__xlx_apatb_param_input_buffers)[i] = __xlx_input_buffers_output_buffer[i].to_uint64();
  }
  for (unsigned i = 0; i <ap_apatb_pe_input_stream_V_cap_bc; ++i)
    ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_input_stream)->write(__xlx_pe_input_stream_input_buffer[i]);
  for (unsigned i = 0; i <ap_apatb_pe_weight_stream_V_cap_bc; ++i)
    ((hls::stream<__cosim_s1__>*)__xlx_apatb_param_pe_weight_stream)->write(__xlx_pe_weight_stream_input_buffer[i]);
}
