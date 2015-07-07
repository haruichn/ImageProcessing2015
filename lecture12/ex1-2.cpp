/*
ImageProcesing
2015/07/07
Reconstruction from Quantizationed image
*/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include "myImageIO.h"
#include "myDCT2.h"

using namespace std;


void get8Block(int x, int y, double iblock[8][8], myImageData * img1){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			iblock[j][i] = img1->get(j+x,i+y);
		}
	}
}

void put8Block(int x, int y, double oblock[8][8], myImageData * img2){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			img2->set(j+x,i+y, oblock[j][i]);
		}
	}
}


int main(int argc, char **argv){

	// init 2d array
	// vector< vector<double> > iblock;
	// iblock.resize(8);
	// for( int i=0; i<8; i++ ){
	// 	iblock[i].resize(8);
	// }
	//
	// vector< vector<double> > oblock;
	// oblock.resize(8);
	// for( int i=0; i<8; i++ ){
	// 	oblock[i].resize(8);
	// }
	double iblock[8][8];
	double mblock[8][8];
	double oblock[8][8];


	// read image data to img1
	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();

	printf("resolution: %d x %d\n", W, H);

	// prepare img2
	myImageData *img2  = new myImageData();
	img2->init(W, H, 1);

	// processing

	for (int i=0; i<H; i+=8){
		for (int j=0; j<W; j+=8){
			get8Block(j, i, iblock, img1);
			Reconstruction(iblock, mblock, 0.3);
			IDCT8x8(mblock, oblock);
			put8Block(j, i, oblock, img2);
		}
	}
	// for(int y = 0; y < H; y++){
	// 	for(int x = 0; x < W; x++){
	//
	// 		double value = img1->get(x,y);
	// 		img2->set(x,y,value);
	//
	// 	}
	// }



	img2->save("result");


	delete img1;
	delete img2;

	return 0; // normal termination

}
