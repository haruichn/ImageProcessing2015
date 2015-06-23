/*
ImageProcesing
20150512
ヒストグラム生成
*/

#include <stdio.h>
#include <stdlib.h>
#include "myImageIO.h"


void Histogram(myImageData *img, int binsize){

	int W = img->getWidth();
	int H = img->getHeight();

	int nBins = 256/binsize;
	int * histdata = new int [nBins];

	for(int idx = 0; idx < nBins; idx++){
		histdata[idx] = 0;
	}

	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){

			int value = img->get(x,y);
			int bin = value/binsize;
			histdata[bin]++;
		}
	}

	// print the histogram

	for(int idx = 0; idx < nBins; idx++){

		printf("[%.03d-%.03d]\t", idx*binsize, (idx+1)*binsize-1);

		int num = histdata[idx];
		int denom = 0.1*W*H/nBins;
		for(int cnt = 0; cnt < num/denom; cnt++){
			printf("*");
		}

		printf("\n");
	}

	delete [] histdata;

	return;

}


int main(int argc, char **argv){

	// read image data to img1

	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();

	Histogram(img1, 8);

	delete img1;

	return 1; // normal termination

}
