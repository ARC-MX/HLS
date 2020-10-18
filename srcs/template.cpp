#include "cnn.h"

#include "ap_int.h"
#include "ap_fixed.h"
#include "hls_stream.h"

typedef ap_ufixed<8, 1> data_t;
typedef ap_ufixed<8, 1> kernel_t;

// 数据重排函数只产生unique数据流,数据流的fanout通过流复制函数实现
// todo 确定buffer尺寸

template <typename T_data, int last_Pof, int last_Pox, int last_Poy, int BUFFER_NUM, int BUFFER_WIDTH, int BUFFER_DEPTH, int TIMES>
void pe2buf(hls::stream<T_data> src[last_Pof][last_Pox][last_Poy], T_data buffer[BUFFER_NUM][BUFFER_WIDTH][BUFFER_DEPTH], bool enable);

template <typename T_data, int Pof, int Pox, int Poy, int BUFFER_NUM, int BUFFER_WIDTH, int BUFFER_DEPTH, int TIMES>
void buf2pe(T_data buffer[BUFFER_NUM][BUFFER_WIDTH][BUFFER_DEPTH], hls::stream<T_data> dst[Pox][Poy], bool enable)
{
    for (int time = 0; time < TIMES; time++)
    {
        dst << buffer;
    }
}

template <typename T_data, typename T_kernel, int Pof, int Pox, int Poy, int TIMES>
void pe(hls::stream<T_data> input[Pof][Pox][Poy], hls::stream<T_kernel> weight[Pof][Pox][Poy], hls::stream<T_data> output[Pof][Pox][Poy])
{
    for (int time = 0; time < TIMES; time++)
    {
    CONCURRENT:
        for (int i = 0; i < Pof; i++)
        {
            for (int j = 0; j < Pox; j++)
            {
                for (int k = 0; k < Poy; k++)
                {
                    output[i][j][k] << input[i][j][k] * weight[i][j][k];
                }
            }
        }
    }
}

template <typename T_data, int last_Pof, int last_Pox, int last_Poy, int Pof, int Pox, int Poy, int BUFFER_NUM, int BUFFER_WIDTH, int BUFFER_DEPTH, int TIMES>
void data_rearrange(hls::stream<T_data> src[last_Pof][last_Pox][last_Poy], hls::stream<T_data> dst[Pox][Poy])
{
    T_data ping_buffer[BUFFER_NUM][BUFFER_WIDTH][BUFFER_DEPTH];
    T_data pong_buffer[BUFFER_NUM][BUFFER_WIDTH][BUFFER_DEPTH];

    for (int time = 0; time < TIMES; time++)
    {
        if (i % 2 == 0)
        {
            pe2buf<T_data, last_Pof, last_Pox, last_Poy, BUFFER_NUM, BUFFER_WIDTH, BUFFER_WIDTH>(src, ping_buffer, i != TIMES - 1);
            buf2pe<T_data, Pof, Pox, Poy, BUFFER_NUM, BUFFER_WIDTH, BUFFER_DEPTH>(pong_buffer, dst, i != 0);
        }
        else
        {
            pe2buf<T_data, last_Pof, last_Pox, last_Poy, BUFFER_NUM, BUFFER_WIDTH, BUFFER_WIDTH>(src, pong_buffer, i != TIMES - 1);
            buf2pe<T_data, Pof, Pox, Poy, BUFFER_NUM, BUFFER_WIDTH, BUFFER_DEPTH>(ping_buffer, dst, i != 0);
        }
    }
}

template <typename T_data, int last_Pof, int last_Pox, int last_Poy, int Pof, int Pox, int Poy, int TIMES>
void layer(hls::stream<T_data> input[last_Pof][last_Pox][last_Poy], hls::stream<T_data> output[Pof][Pox][Poy])
{
    hls::stream<data_t> stream2pe[Pox][Poy];
    hls::stream<data_t> expanded_stream2pe[Pof][Pox][Poy];

    data_rearrange<T_data, last_Pof, last_Pox, last_Poy, Pof, Pox, Poy, INPUT_BUFFER_NUM, INPUT_BUFFER_WIDTH, INPUT_BUFFER_DEPTH, TIMES>(input, )
}

// 不使用template, 使用class参数化 // ? 不能使用类属性作为类方法的尺寸 ?
