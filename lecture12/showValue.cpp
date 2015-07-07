#include "myImageIO.h"
#include <iostream>

using namespace std;


int main(int argc, char **argv){

	// read image data to img1
	myImageData * img1 = new myImageData();
	img1->read(argv[1]);

	int W = img1->getWidth();
	int H = img1->getHeight();

	printf("resolution: %d x %d\n", W, H);


    for (int y=0; y<H; y+=32){
		for (int x=0; x<W; x+=32){

            cout << img1->get(x,y) << "\t";

        }
        cout << "\n\n\n";
    }

    cout << endl;

	delete img1;

	return 0; // normal termination

}
