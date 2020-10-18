#include "ping_pong.h"

// 前提条件: 前一个模块补充数据时间 < 后一个模块消耗数据时间
// 可以看到buffer是怎样充当两种不同读写模式之间的"最小公倍数"
// 这段代码综合得到的周期数应该为: 16 * 20 + 10 = 330,不应为: 16 * (20+10) = 480
// 同时,输出数据是"整齐"的,没有"串扰

void buf2stream(int buffer[10][10], hls::stream<int> dst[5], bool enable) //
{
    if (!enable)
        return;
LOOP_WRITE:
    for (int i = 0; i < 20; i++)
    {
#pragma HLS PIPELINE II = 1
    CONCURRENT_WRITE:
        for (int j = 0; j < 5; j++)
        {
            dst[j].write(buffer[i / 2][j + (i % 2) * 5]);
        }
    }
}

void stream2buf(hls::stream<int> src[10], int buffer[10][10], bool enable)
{
    if (!enable)
        return;
LOOP_READ:
    for (int i = 9; i >= 0; i--)
    {
#pragma HLS PIPELINE II = 1
    CONCURRENT_READ:
        for (int j = 9; j >= 0; j--)
        {
            buffer[i][j] = src[j].read();
        }
    }
}

void top(hls::stream<int> src[10], hls::stream<int> dst[5])
{
    int ping[10][10];
#pragma HLS ARRAY_PARTITION variable = ping dim = 2 complete
    int pong[10][10];
#pragma HLS ARRAY_PARTITION variable = pong dim = 2 complete
PING_PONG:
    for (ap_uint<5> i = 0; i < 16; i++)
    {
        if (i[0]) // 对于任意精度类型,可以通过[]进行bit select
        {
            stream2buf(src, ping, i != 15);
            buf2stream(pong, dst, i != 0);
        }
        else
        {
            stream2buf(src, pong, i != 15);
            buf2stream(ping, dst, i != 0);
        }
    }
}
