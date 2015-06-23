/*
ex2.cpp
ImageProcesing
2015/06/23
Histogram equalization
*/

#include <stdio.h>
#include <stdlib.h>
#include "myImageIO.h"
#include <iostream>
#include <fstream>

using namespace std;


// design of table
//==========================================
int* CreateTable(myImageData *img, int binsize){

	int W = img->getWidth();
	int H = img->getHeight();

	int nBins = 256/binsize;
	int * histdata = new int [nBins];

	int * table = new int[nBins];
	int sum = 0;

	// init
	for(int idx = 0; idx < nBins; idx++){
		histdata[idx] = 0;
		table[idx] = 0;
	}

	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){

			int value = img->get(x,y);
			int bin = value/binsize;
			histdata[bin]++;
		}
	}

	for (int value = 0; value < 256; value++){
		sum += histdata[value];
		double r = sum/double(W*H);
		// ratio of pixels not greater than value
		table[value] = round(255*r);
	}


	// print the histogram
	ofstream ofs( "table.csv" );

	cout << "table.csv" << endl;
	for(int idx = 0; idx < nBins-1; idx++){
		int num = table[idx];
		ofs << num << ',';
	}
	ofs << histdata[nBins-1] << endl;


	return table;
}


int main(int argc, char **argv){

	// read image data to img1
	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();

	// prepare img2
	myImageData *img2  = new myImageData();
	img2->init(W, H, 1);

	// create table
	int binsize = 1;
	int nBins = 256/binsize;
	int  * table = new int[nBins];
	table = CreateTable(img1, binsize);

	// processing
	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){

			int value = img1->get(x,y);
			img2->set(x,y,table[value]);

		}
	}

	img2->save("result");


	delete img1;
	delete img2;

	return 0; // normal termination

}
