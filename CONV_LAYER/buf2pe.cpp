#include "conv.h"
// 将规律刻画出来,然后参数化

// ceil用在参数上?
// 前提:STRIDE = 1 无视LOOP_3

// todo 厘清xy顺序
// insight 先搭架子,再填东西
void pe(input_t input_buffers[INPUT_BUFFER_NUM][INPUT_BUFFER_WIDTH][INPUT_BUFFER_DEPTH], hls::stream<kernel_t> &weight_stream, output_t output_buffers[Poy][Pox]) //todo 找到办法解决ceil和常量的问题 计算INPUT_BUFFER_DEPTH
{

    input_t input_registers[Poy][Pox + 1] = {0};    // pe registers for input
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
                for (int kernel_x = 0; kernel_x < Nkx; kernel_x++)

                {
                    int kernel_index = kernel_y * Nky + kernel_y;
                    // weight registers
                    if (output_index == 0)
                        weight_registers[kernel_index] = weight_stream.read();
                CONCURRENT:
                    for (int dsp_y = 0; dsp_y < Poy; dsp_y++)
                    {
                        for (int dsp_x = 0; dsp_x < Pox + 1; dsp_x++) //?1 should be stride? 后面也要逐个检查
                        {
                            // input registers
                            // ?负数的模是否与我预期相同?
                            if (kernel_x == 0 && dsp_y == Poy - 1 && dsp_x != 0 && dsp_x != Pox)                                                                                                                         // part1
                                input_registers[dsp_y][dsp_x] = input_buffers[(kernel_y - 1 + Poy) % Poy][dsp_x - 1][(kernel_y - 1 + Poy) / Poy * INPUT_BUFFER_ROW_DEPTH];                                               //todo
                            else if (kernel_x == 0 && dsp_y == Poy - 1 && dsp_x == Pox)                                                                                                                                  // part2 // insight 如果调换顺序,从最特殊开始,会更简单
                                input_registers[dsp_y][dsp_x] = input_buffers[(kernel_y - 1 + Poy) % Poy][(kernel_x + Pox - 1) % Pox][(kernel_x + Pox - 1) / Pox + (kernel_y - 1 + Poy) / Poy * INPUT_BUFFER_ROW_DEPTH]; //todo
                            else if (kernel_x == 0 && dsp_y != Poy - 1 && kernel_y != 0 && dsp_x != 0 && dsp_x != Pox)                                                                                                   // part3
                                input_registers[dsp_y][dsp_x] = input_buffers[dsp_y][dsp_x - 1][0];                                                                                                                      // insight 除-模模式
                            else if (kernel_x == 0 && dsp_y != Poy - 1 && kernel_y != 0 && dsp_x == Pox)                                                                                                                 // part4
                                input_registers[dsp_y][dsp_x] = input_buffers[dsp_y][(kernel_x + Pox - 1) % Pox][(kernel_x + Pox - 1) / Pox];
#pragma region data_from_SRL
                            else if (kernel_x != 0 && dsp_y == Poy - 1 && dsp_x != Pox)
                                input_registers[dsp_y][dsp_x] = input_registers[dsp_y][dsp_x + 1];
                            else if (kernel_x != 0 && kernel_y == 0 && dsp_x != Pox)
                                input_registers[dsp_y][dsp_x] = input_registers[dsp_y][dsp_x + 1];
#pragma endregion
#pragma region data_from_fifo
                            else if (dsp_y != Poy - 1 && kernel_y != 0 && dsp_x != Pox)
                                input_registers[dsp_y][dsp_x] = inner_fifos[dsp_y][dsp_x].read();
#pragma endregion data_from_fifo
                            std::cout << "reg good" << std::endl;
                            // inner fifos
                            if (dsp_y != Poy - 1 && kernel_y != Nky - 1 && dsp_x != Pox)
                                inner_fifos[dsp_y][dsp_x].write(input_registers[dsp_y + 1][dsp_x]);
                            std::cout << "fifo good" << std::endl;
                            // output buffers
                            output_buffers[dsp_x][dsp_y] += input_registers[dsp_x][dsp_y] * weight_registers[kernel_index];
                            std::cout << "output good" << std::endl;
                        }
                    }
                }
            }
        }
    }
}