import numpy as np

(Nix, Niy, Nif, Nkx, Nky, Nof) = (10, 10, 3, 3, 3, 10)  # padding size is included
STRIDE = 1
Nox = int((Nix - Nkx) / STRIDE + 1)
Noy = int((Niy - Nky) / STRIDE + 1)


def sim_conv():
    inputs = np.random.rand(Nif, Nix, Niy)
    kernels = np.random.rand(Nof, Nif, Nkx, Nky)
    outputs = np.zeros((Nof, Nox, Noy))

    for output_channel in range(Nof):
        for output_row in range(Nox):
            for output_col in range(Noy):
                partial_sum = 0
                for input_channel in range(Nif):
                    for kernel_row in range(Nkx):
                        for kernel_col in range(Nky):
                            input_row = output_row * STRIDE + kernel_row
                            input_col = output_col * STRIDE + kernel_col
                            partial_sum += inputs[input_channel,
                                                  input_row, input_col] * kernels[output_channel, input_channel, kernel_row, kernel_col]
                outputs[output_channel, output_row, output_col] = partial_sum

    inputs.astype('double').tofile('inputs.data')
    kernels.astype('double').tofile('kernels.data')
    outputs.astype('double').tofile('outputs.data')

    return outputs


print(sim_conv().shape)
