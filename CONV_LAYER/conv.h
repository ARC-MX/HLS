#ifndef __CONV_H__
#define __CONV_H__

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"
#include <iostream>
#include "assert.h"

// 定义数据类型
typedef ap_fixed<8, 1> input_t;
typedef ap_int<8> kernel_t;
typedef ap_int<16> output_t;

constexpr int STRIDE = 1;

// 定义4-level conv循环的尺寸,unroll系数和piling系数
// kernel(filter)相关(loop-1)
constexpr int Nkx = 3;
constexpr int Nky = 3;
constexpr int Tkx = 3;
constexpr int Tky = 3;
constexpr int Pkx = 3;
constexpr int Pky = 3;

// input feature map(loop-3)相关
constexpr int Nix = 10;
constexpr int Niy = 10;
constexpr int Tix = 10;
constexpr int Tiy = 10;
constexpr int Pix = 10;
constexpr int Piy = 10;

// output feature map(loop-3)相关,由input,kernel和stride决定
constexpr int Nox = (Nix - Nkx) / STRIDE + 1;
constexpr int Noy = (Niy - Nky) / STRIDE + 1;
constexpr int Tox = (Tix - Nkx) / STRIDE + 1;
constexpr int Toy = (Tiy - Nky) / STRIDE + 1;
constexpr int Pox = Pix;
constexpr int Poy = Piy;

// input channel相关(loop-2)
constexpr int Nif = 3;
constexpr int Tif = 3;
constexpr int Pif = 3;

// output channel相关(loop-4)
constexpr int Nof = 10;
constexpr int Tof = 10;
constexpr int Pof = 10;

constexpr int INPUT_SIZE = Nif * Nix * Niy;
constexpr int KERNEL_SIZE = Nof * Nif * Nkx * Nky;
constexpr int OUTPUT_SIZE = Nof * Nox * Noy;

// 下面的内容采用和论文中一样的符号
constexpr int Nm = Nif * Nkx * Nky * Nof * Nox * Noy; // (5)
constexpr int intertile_cycles = (Nif / Tif) * (Nkx / Tkx) * (Nky / Tky) * (Nof / Tof) * (Nkx / Tkx) * (Nky / Tky);
constexpr int intratile_cycles = (Tif / Pif) * (Tkx / Pkx) * (Tky / Pky) * (Tof / Pof) * (Tkx / Pkx) * (Tky / Pky);
constexpr int cycles = intertile_cycles * intratile_cycles; // (6) (7) (8)

// 函数原型
template <typename T>
void conv_cpu(T *input, T *kernel, T *output);

void packed_conv_cpu(double *input, double *kernel, double *output);

void check_params();

void packed_conv_paper(input_t *input, kernel_t *kernel, output_t *output);

#endif // __CONV_H__