/*
ImageProcessing
20150512
ex2
RGB reversal
*/
#include <stdio.h>
#include <stdlib.h>
#include "myImageIO.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv){

	// read image data to img1

	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();
	int CH = img1->getCH();
	cout << "CH = " << CH << endl;

	printf("resolution: %d x %d\n", W, H);

	// prepare img2

	myImageData *img2  = new myImageData();
	img2->init(W, H, 3);

	// processing

	for(int y = 0; y < H; y++){
		for(int x = 0; x < W; x++){

			double value1 = img1->get(x,y,1);
			double value2 = img1->get(x,y,2);
			double value3 = img1->get(x,y,3);
			img2->set(x,y,2,value1);
			img2->set(x,y,0,value2);
			img2->set(x,y,1,value3);

		}
	}



	img2->save("result");


	delete img1;
	delete img2;

	return 0; // normal termination

}
