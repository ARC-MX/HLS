#include "cnn.h"

template <typename T>
void read_mat_bin(const char *file_path, int N, T *input)
{
    FILE *f = fopen(file_path, "rb");
    fread(input, sizeof(T), N, f);
    fclose(f);
}

int main(int argc, char const *argv[])
{

    check_params();

    int fail = 0;

    double input[Nif * Nix * Niy];
    double kernel[Nof * Nif * Nkx * Nky];
    double output[Nof * Nox * Noy] = {0};
    double golden[Nof * Nox * Noy];

    read_mat_bin<double>("E:\\LtrProjects\\HLSProjects\\CONV\\inputs.data", INPUT_SIZE, input);
    read_mat_bin<double>("E:\\LtrProjects\\HLSProjects\\CONV\\kernels.data", KERNEL_SIZE, kernel);
    read_mat_bin<double>("E:\\LtrProjects\\HLSProjects\\CONV\\outputs.data", OUTPUT_SIZE, golden);

    input_t fpga_input[INPUT_SIZE];
    kernel_t fpga_kernel[KERNEL_SIZE];
    output_t fpga_output[OUTPUT_SIZE];

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        fpga_input[i] = input[i];
    }
    for (int i = 0; i < KERNEL_SIZE; i++)
    {
        fpga_kernel[i] = kernel[i];
    }
    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        fpga_output[i] = output[i];
    }

    packed_conv_cpu(input, kernel, output);
    packed_conv_paper(fpga_input, fpga_kernel, fpga_output);

    // todo 固化为compare_array
    for (int i = 0; i < OUTPUT_SIZE; i++)
    {
        double error = abs((double)fpga_output[i] - golden[i]);
        if (error / golden[i] > 0.01) // 1%的相对误差容限
        {
            std::cout << "yours: " << fpga_output[i] << " golden: " << golden[i] << " error: " << error / golden[i] << std::endl;
            fail = 1;
        }
    }

    return 0;
}