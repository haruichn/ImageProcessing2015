/*
ex1.cpp
ImageProcesing
2015/06/23
ヒストグラム生成(output using txt→excel)
*/

#include <stdio.h>
#include <stdlib.h>
#include "myImageIO.h"
#include <iostream>
#include <fstream>

using namespace std;


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
	ofstream ofs( "output.csv" );

	cout << "output.csv" << endl;
	for(int idx = 0; idx < nBins-1; idx++){
		int num = histdata[idx];
		ofs << num << ',';
	}
	ofs << histdata[nBins-1] << endl;

	delete [] histdata;

	return;

}


int main(int argc, char **argv){

	// read image data to img1

	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();

	Histogram(img1, 1);

	delete img1;

	return 1; // normal termination

}
