#include "conv.h"

// 设计思路:
// 能否将stream转化为DAG?

// 检查参数合法性
void check_params()
{
    // 整除问题
    assert((Nix - Nkx) % STRIDE == 0);
    assert((Niy - Nky) % STRIDE == 0);
    assert((Tix - Nkx) % STRIDE == 0);
    assert((Tiy - Nky) % STRIDE == 0);
    // 不等式约束
    assert((1 <= Pkx) && (Pkx <= Tkx) && (Tkx <= Nkx));
    std::cout << "kx constraint satisfied" << std::endl;
    assert((1 <= Pky) && (Pky <= Tky) && (Tky <= Nky));
    std::cout << "ky constraint satisfied" << std::endl;
    // 输出信息
    std::cout << "number or multiplications: " << Nm << std::endl;
    std::cout << "expected cycles: " << cycles << std::endl;
    std::cout << "expected dsps: " << std::endl;
    std::cout << "expected brams: " << std::endl;
    std::cout << "expected luts: " << std::endl;
}

template <typename T>
void conv_cpu(T *input, T *kernel, T *output)
{

LOOP_4:
    for (int channel_out = 0; channel_out < Nof; channel_out++)
    {
    LOOP_3:
        for (int x_out = 0; x_out < Nox; x_out++)
        {
            for (int y_out = 0; y_out < Noy; y_out++)
            {
                T partial_sum = 0;
                int output_index = channel_out * Nox * Noy + x_out * Nox + y_out;
            LOOP_2:
                for (int channel_in = 0; channel_in < Nif; channel_in++)
                {
                LOOP_1:
                    for (int x_kernel = 0; x_kernel < Nkx; x_kernel++)
                    {
                        for (int y_kernel = 0; y_kernel < Nky; y_kernel++)
                        {
                            int x_in = x_out * STRIDE + x_kernel;
                            int y_in = y_out * STRIDE + y_kernel;

                            int input_index = channel_in * Nix * Niy + x_in * Niy + y_in;
                            int kernel_index = channel_out * Nif * Nkx * Nky + channel_in * Nkx * Nky + x_kernel * Nkx + y_kernel;

                            partial_sum += input[input_index] * kernel[kernel_index];

#ifndef __SYNTHESIS__
                            // std::cout << "input_index: " << input_index << " input: " << input[input_index] << std::endl;
                            // std::cout << "kernel_index: " << kernel_index << " kernel: " << kernel[kernel_index] << std::endl;
                            // std::cout << "partial_sum: " << partial_sum << std::endl;
#endif
                        }
                    }
                }
                output[output_index] = partial_sum;
            }
        }
    }
}

void packed_conv_cpu(double *input, double *kernel, double *output)
{
    conv_cpu<double>(input, kernel, output);
}

// for type of architectures
// ? 论证以下内容: 完全展开内层之后再展开外层是best practice
// * 得出以下结论: unroll多层,内层总是完全展开,外层可能部分展开,哪一层为最外层,关乎访存设计和data locality
// A: Unroll 1, 2, 4, loop order(inside out) =
// B: Unroll 2, 4
//
// D: (Ma Paper) Unroll 3, 4, loop order = 2, 1, 4, 3

template <typename T_in, typename T_kernel, typename T_out>
void conv_paper(T_in *input, T_kernel *kernel, T_out *output)
{
LOOP_2:
    for (int channel_in = 0; channel_in < Nif; channel_in++)
    {
    LOOP_1:
        for (int x_kernel = 0; x_kernel < Nkx; x_kernel++)
        {
            for (int y_kernel = 0; y_kernel < Nky; y_kernel++)
            {
            LOOP_4:
                for (int channel_out = 0; channel_out < Nof; channel_out++)
                {
                LOOP_3:
                    for (int x_out = 0; x_out < Nox; x_out++)
                    {
                        for (int y_out = 0; y_out < Noy; y_out++)
                        {
                            int x_in = x_out * STRIDE + x_kernel;
                            int y_in = y_out * STRIDE + y_kernel;
                            int input_index = channel_in * Nix * Niy + x_in * Niy + y_in;
                            int kernel_index = channel_out * Nif * Nkx * Nky + channel_in * Nkx * Nky + x_kernel * Nkx + y_kernel;
                            int output_index = channel_out * Nox * Noy + x_out * Nox + y_out;
                            output[output_index] += input[input_index] * kernel[kernel_index];
                            // #ifndef __SYNTHESIS__
                            //                             std::cout << "output[" << output_index << "] = " << output[output_index] << std::endl;
                            // #endif
                        }
                    }
                }
            }
        }
    }
}

void packed_conv_paper(input_t *input, kernel_t *kernel, output_t *output)
{
    conv_paper<input_t, kernel_t, output_t>(input, kernel, output);
}

template <typename T_in, typename T_kernel, typename T_out>
void conv_paper(T_in *input, T_kernel *kernel, T_out *output)
