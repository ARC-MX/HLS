#include "cnn.h"

// 使用ROM来实现"编译时"坐标计算

void top(hls::stream<kernel_t> &weight_stream, hls::stream<input_t> pe_input_stream[Poy * Pox], hls::stream<kernel_t> &pe_weight_stream)
{
    input_t input_buffers[INPUT_BUFFER_NUM * INPUT_BUFFER_WIDTH * INPUT_BUFFER_DEPTH] = {0};
#pragma HLS ARRAY_PARTITION variable = input_buffers dim = 1 complete
    pe(input_buffers, weight_stream, pe_input_stream, pe_weight_stream)
}

void init_index_table(address_t_8 index_table[Nkx * Nky * (Pox + 1) * Poy])
{
    for (int kernel_y = 0; kernel_y < Nky; kernel_y++)
    {
        for (int kernel_x = 0; kernel_x < Nkx; kernel_x++)
        {
            for (int dsp_y = 0; dsp_y < Poy; dsp_y++)
            {
                for (int dsp_x = 0; dsp_x < Pox + 1; dsp_x++)
                {
                    int input_num_index = (dsp_y + kernel_y) % Poy;
                    int input_width_index = (dsp_x - 1 + kernel_x + Pox) % Pox;
                    int input_depth_index = (kernel_x + Pox - 1) / Pox + (kernel_y + Poy - 1) / Poy * INPUT_BUFFER_ROW_DEPTH;
                    assert(input_num_index >= 0 && input_num_index < INPUT_BUFFER_NUM);
                    assert(input_width_index >= 0 && input_width_index < INPUT_BUFFER_WIDTH);
                    assert(input_depth_index >= 0 && input_depth_index < INPUT_BUFFER_DEPTH);
                    int input_buffer_index = input_num_index * INPUT_BUFFER_WIDTH * INPUT_BUFFER_DEPTH + input_width_index * INPUT_BUFFER_DEPTH + input_depth_index;
                    int table_index = kernel_y * Nkx * Poy * (Pox + 1) + kernel_x * Poy * (Pox + 1) + dsp_y * (Pox + 1) + dsp_x;
                    index_table[table_index] = input_buffer_index;
                } // end of dsp_x loop
            }     // end of dsp_y loop
        }         // end of kernel_x loop
    }             // end of kernel_y loop
}

void pe(input_t input_buffers[INPUT_BUFFER_NUM * INPUT_BUFFER_WIDTH * INPUT_BUFFER_DEPTH], hls::stream<kernel_t> &weight_stream,
        hls::stream<input_t> pe_input_stream[Poy * Pox], hls::stream<kernel_t> &pe_weight_stream)
{
    input_t input_registers[Poy][Pox + 1] = {0};
    // pe registers for input
#ifndef __SYNTHESIS__
    input_t help_registers[Poy][Pox + 1] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
#endif
    kernel_t weight_registers[Nkx * Nky]; // pe registers for weights
    hls::stream<input_t> inner_fifos[Poy - 1][Pox];
#pragma HLS STREAM variable = inner_fifos depth = 6 dim = 1
    // inner fifos
    address_t_8 index_table[Nkx * Nky * (Pox + 1) * Poy];
    init_index_table(index_table);

LOOP_3:
    for (int output_x = 0; output_x < Nox / Pox; output_x++) // todo 应该向上取整
    {
        for (int output_y = 0; output_y < Noy / Poy; output_y++)
        {
            int table_index = 0;
            for (int kernel_y = 0; kernel_y < Nky; kernel_y++)
            {
            PIPELINE:
                for (int kernel_x = 0; kernel_x < Nkx; kernel_x++)
                {
#pragma HLS PIPELINE II = 1
                    // weight registers
                    if (output_x == 0 && output_y == 0)
                        weight_registers[kernel_y * Nky + kernel_x] = weight_stream.read();
#pragma region concurrent
                CONCURRENT:
                    for (int dsp_y = 0; dsp_y < Poy; dsp_y++)
                    {
                        for (int dsp_x = 0; dsp_x < Pox + 1; dsp_x++) //?1 should be stride? �?��?�也�?�?个检查
                        {
                            bool part1 = (kernel_x == 0) && (dsp_x == 0) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part2 = (((kernel_x == 0) && (dsp_x != 0)) || ((dsp_x == Pox) && (kernel_x < Nkx - 1))) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part3 = (kernel_x != 0) && (dsp_x != Pox) && ((dsp_y == Poy - 1) || (kernel_y == 0));
                            bool part4 = (dsp_y != Poy - 1) && (kernel_y != 0) && ((dsp_x != Pox));
                            int input_buffer_index = index_table[table_index];
                            if (part1)
                                input_registers[dsp_y][dsp_x] = 0;
                            else if (part2)
                                input_registers[dsp_y][dsp_x] = input_buffers[input_buffer_index];
                            else if (part3)
                                input_registers[dsp_y][dsp_x] = input_registers[dsp_y][dsp_x + 1];
                            else if (part4)
                                input_registers[dsp_y][dsp_x] = inner_fifos[dsp_y][dsp_x].read();
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
                                pe_input_stream[dsp_y * Pox + dsp_x].write(input_registers[dsp_x][dsp_y]);

                            table_index++;

                        } // end of dsp_x loop
                    }     // end of dsp_y loop
                    pe_weight_stream.write(weight_registers[kernel_y * Nky + kernel_x]);
#ifndef __SYNTHESIS__
                PRINT_REGS:
                    if (output_x == 0 && output_y == 0)
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
                } // end of kernel_x loop
            }     // end of kernel_y loop
#pragma endregion concurrent
        } // end of output_y loop
    }     // end of output_x loop
}
