#include "ap_int.h"
#include "hls_stream.h"

constexpr int NUM_TAP = 11; // 抽头数量
typedef ap_uint<16> input_t;
typedef ap_uint<16> coef_t;
typedef ap_uint<16 + 16 + 4> output_t;

void standard(hls::stream<input_t> &src, hls::stream<output_t> &dst);