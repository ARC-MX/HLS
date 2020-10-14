#include "conv.h"

int main(int argc, char const *argv[])
{
    input_t input_buffers[3][3][6] = {
        {{0, 0, 31, 34, 61, 64},
         {0, 0, 32, 35, 62, 65},
         {0, 0, 33, 36, 63, 66}},

        {{11, 14, 41, 44, 0, 0},
         {12, 15, 42, 45, 0, 0},
         {13, 16, 43, 46, 0, 0}},

        {{21, 24, 51, 54, -1, -1},
         {22, 25, 52, 55, -1, -1},
         {23, 26, 53, 56, -1, -1}}};

    hls::stream<kernel_t> kernel_stream;
    for (int i = 0; i < 9; i++)
        kernel_stream.write(i);

    hls::stream<input_t> pe_input_stream[Poy][Pox];
    hls::stream<kernel_t> pe_weight_stream;

    output_t output_buffers[3][3] = {0};

    std::cout << "Hello?" << std::endl;

    pe(input_buffers, kernel_stream, pe_input_stream, pe_weight_stream);
}
