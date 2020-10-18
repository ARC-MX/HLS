// 权威指南-dsp 第10章 各种形式的fir
#include "FIRs.h"

coef_t COEFF[11] = {1, 4, 7, 13, 21, 33, 21, 13, 7, 4, 1};

void standard(hls::stream<input_t> &src, hls::stream<output_t> &dst)
{
    input_t registers[NUM_TAP];
#pragma HLS ARRAY_PARTITION variable = registers dim = 1 complete
    output_t partial_sum = 0;
    for (int i = 0; i < NUM_TAP; i++)
    {
        if (i == 0)
            registers[i] = src.read();
        else
            registers[i] = registers[i - 1];
#pragma HLS RESOURCE variable = partial_sum core = DSP48
        partial_sum += COEFF[i] * registers[i];
    }
    dst << partial_sum;
}

void top(hls::stream<input_t> &src, hls::stream<output_t> &dst)
{
LOOP:
    for (int i = 0; i < 10; i++)
    {
#pragma HLS PIPELINE II = 1
        standard(src, dst);
    }
}