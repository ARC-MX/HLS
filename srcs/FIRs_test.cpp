#include "FIRs.h"

#include <iostream>
using namespace std;

// 编写test_func, 传函数作为参数

int main(int argc, char const *argv[])
{
    hls::stream<input_t> input;
    for (int i = 0; i < 10; i++)
        input << i;

    hls::stream<output_t> output;

    for (int i = 0; i < 10; i++)
        standard(input, output);

    for (int i = 0; i < 10; i++)
        cout << output.read() << " ";

    return 0;
}