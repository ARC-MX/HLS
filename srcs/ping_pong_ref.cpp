
#include <ap_int.h>
#include <hls_stream.h>
#include <stdbool.h>

typedef ap_uint<8> pixel_t;

#define IMAGE_HEIGHT 1000
#define IMAGE_WIDTH 1000
#define BLOCK_SIZE 3
#define IMAGE_WIDTH_BLOCKS (IMAGE_WIDTH/BLOCK_SIZE)
#define IMAGE_HEIGHT_BLOCKS (IMAGE_HEIGHT/BLOCK_SIZE)

void readNextRow(pixel_t * dataIn, pixel_t buffer[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE], ap_uint<16> row, bool enable);
void processRow(pixel_t buffer[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE], hls::stream<pixel_t> & dataOut, bool enable);


void top(pixel_t * dataIn, hls::stream<pixel_t> & dataOut) {

#pragma HLS INTERFACE m_axi port=dataIn offset=slave
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE axis port=dataOut

	pixel_t bufferA[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE];
	pixel_t bufferB[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE];
#pragma HLS ARRAY_PARTITION variable=bufferA dim=3 complete
#pragma HLS ARRAY_PARTITION variable=bufferA dim=2 complete
#pragma HLS ARRAY_PARTITION variable=bufferB dim=3 complete
#pragma HLS ARRAY_PARTITION variable=bufferB dim=2 complete



	for (ap_uint<16> by = 0; by < IMAGE_HEIGHT_BLOCKS; by ++) {
		if (by[0]) {
			readNextRow(dataIn,bufferA,by*BLOCK_SIZE,by != (IMAGE_HEIGHT_BLOCKS-1));
			processRow(bufferB,dataOut,by != 0);
		} else {
			readNextRow(dataIn,bufferB,by*BLOCK_SIZE,by != (IMAGE_HEIGHT_BLOCKS-1));
			processRow(bufferA,dataOut,by != 0);
		}
	}
}

void readNextRow(pixel_t * dataIn, pixel_t buffer[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE], ap_uint<16> row, bool enable) {
	if (!enable) {
		return;
	}
	for (int y = 0; y < BLOCK_SIZE; y++) {
		for (int x = 0; x < IMAGE_WIDTH_BLOCKS*BLOCK_SIZE; x++) {
	#pragma HLS PIPELINE II=1
			pixel_t p = dataIn[(row + y)*IMAGE_WIDTH + x];
			buffer[x/BLOCK_SIZE][x % BLOCK_SIZE][y] = p;
		}
	}
}

void processRow(pixel_t buffer[IMAGE_WIDTH_BLOCKS][BLOCK_SIZE][BLOCK_SIZE], hls::stream<pixel_t> & dataOut, bool enable) {
	if (!enable) {
		return;
	}
	ap_uint<12> sum = 0;
	for (int bx = 0; bx < IMAGE_WIDTH_BLOCKS; bx++) {
#pragma HLS PIPELINE II=1
		for (int x = 0; x < BLOCK_SIZE; x++) {
			for (int y = 0; y < BLOCK_SIZE; y++) {
				sum += buffer[bx][x][y];
			}
		}
		dataOut.write(sum/9);
	}
}