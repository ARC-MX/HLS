#include "conv.h"
// 将规律刻画出来,然后参数化

// ceil用在参数上?
// 前提:STRIDE = 1 无视LOOP_3

// todo 厘清xy顺序
// insight 先搭架子,再填东西
void pe(input_t input_buffers[INPUT_BUFFER_NUM * INPUT_BUFFER_WIDTH * INPUT_BUFFER_DEPTH], hls::stream<kernel_t> &weight_stream,
        hls::stream<input_t> pe_input_stream[Poy][Pox], hls::stream<kernel_t> &pe_weight_stream) //todo 找到办法解决ceil和常量的问题 计算INPUT_BUFFER_DEPTH
{

    input_t input_registers[Poy][Pox + 1] = {0}; // pe registers for input
#ifndef __SYNTHESIS__
    input_t help_registers[Poy][Pox + 1] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
#endif
    kernel_t weight_registers[Nkx * Nky];           // pe registers for weights
    hls::stream<input_t> inner_fifos[Poy - 1][Pox]; // inner fifos

#ifndef __SYNTHESIS__
    std::cout << "decalration done" << std::endl;
#endif

LOOP_3:
    for (int output_x = 0; output_x < Nox / Pox; output_x++)
    {
        for (int output_y = 0; output_y < Noy / Poy; output_y++)
        {
            int output_index = output_x * (Nox / Pox) + output_y;
            for (int kernel_y = 0; kernel_y < Nky; kernel_y++)
            {
            PIPELINE:
                for (int kernel_x = 0; kernel_x < Nkx; kernel_x++)
                {
                    int kernel_index = kernel_y * Nky + kernel_x;
                    // weight registers
                    if (output_index == 0)
                        weight_registers[kernel_index] = weight_stream.read();
#pragma region concurrent
                CONCURRENT:
                    for (int dsp_y = 0; dsp_y < Poy; dsp_y++)
                    {
                        for (int dsp_x = 0; dsp_x < Pox + 1; dsp_x++) //?1 should be stride? 后面也要逐个检查
                        {
                            // input registers
                            // ?负数的模是否与我预期相同?
                            int ini = dsp_y;          // input_num_inner
                            int ino = kernel_y % Poy; //input_num_outer
                            int input_num_index = (ini + ino + Poy) % Poy;

                            int iwi = dsp_x - 1;      // input_width_inner
                            int iwo = kernel_x % Pox; // input_width_outer
                            int input_width_index = (iwi + iwo + Pox) % Pox;

                            int input_depth_index = (kernel_x + Pox - 1) / Pox + (kernel_y + Poy - 1) / Poy * INPUT_BUFFER_ROW_DEPTH;

                            int input_buffer_index = input_num_index * INPUT_BUFFER_WIDTH * INPUT_BUFFER_DEPTH +
                                                     input_width_index * INPUT_BUFFER_DEPTH + input_depth_index;

                            assert(input_num_index >= 0 && input_num_index < INPUT_BUFFER_NUM);
                            assert(input_width_index >= 0 && input_width_index < INPUT_BUFFER_WIDTH);
                            assert(input_depth_index >= 0 && input_depth_index < INPUT_BUFFER_DEPTH);

// ?how to deal with don't cares?
#ifndef __SYNTHESIS__
                            // std::cout << "index: " << input_num_index << " " << input_width_index << " " << input_depth_index << " ||| ";
#endif
                            bool part1 = (kernel_x == 0) && (dsp_x == 0) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part2 = ((kernel_x == 0) || ((dsp_x == Pox) && (kernel_x < Nkx - 1))) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part3 = (kernel_x != 0) && (dsp_x != Pox) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part4 = (dsp_y != Poy - 1) && (kernel_y != 0) && ((dsp_x != Pox));

                            if (part1)
                                input_registers[dsp_y][dsp_x] = 0;
                            else if (part2)
                                input_registers[dsp_y][dsp_x] = input_buffers[input_buffer_index];
#pragma region data_from_SRL
                            else if (part3)
                                input_registers[dsp_y][dsp_x] = input_registers[dsp_y][dsp_x + 1];
#pragma endregion
#pragma region data_from_fifo
                            else if (part4)
                                input_registers[dsp_y][dsp_x] = inner_fifos[dsp_y][dsp_x].read();
#pragma endregion data_from_fifo
                            else
                                ; // dont't cares, stay, don't access memory
#ifndef __SYNTHESIS__
                            int part = 0;
                            if (part1)
                                part = 1;
                            else if (part2)
                                part = 2;
                            else if (part3)
                                part = 3;
                            else if (part4)
                                part = 4;
                            else
                                part = 5;
                            help_registers[dsp_y][dsp_x] = part;
#endif
                            // inner fifos
                            if (dsp_y != 0 && kernel_y != Nky - 1 && dsp_x != Pox)
                                inner_fifos[dsp_y - 1][dsp_x].write(input_registers[dsp_y][dsp_x]);
                            // output buffers
                            if (dsp_x != Pox)
                            {
                                pe_input_stream[dsp_y][dsp_x].write(input_registers[dsp_x][dsp_y]);
                                pe_weight_stream.write(weight_registers[kernel_index]);
                            }
                        }
                    }
#ifndef __SYNTHESIS__
                PRINT_REGS:
                    if (output_index == 0)
                    {
                        // std::cout << "kernel_index: " << kernel_index << std::endl;
                        for (int i = 0; i < Poy; i++)
                        {
                            for (int j = 0; j < Pox + 1; j++)
                            {
                                // std ::cout << help_registers[i][j] << " ";
                                std ::cout << input_registers[i][j] << " ";
                            }
                            std::cout << " || ";
                        }
                        std::cout << std::endl;
                    }
#endif
                }
            }
#pragma endregion concurrent
        }
    }
}
