	#include <stdio.h>
#include <math.h>

int QTable[8][8] = {
	{16, 11, 10, 16, 24, 40, 51, 61},
	{12, 12, 14, 19, 26, 58, 60, 55},
	{14, 13, 16, 24, 40, 57, 69, 56},
	{14, 17, 22, 29, 51, 87, 80, 62},
	{18, 22, 37, 56, 68,109,103, 77},
	{24, 35, 55, 64, 81,104,113, 92},
	{49, 64, 78, 87,103,121,120,101},
	{72, 92, 95, 98,112,100,103, 99}
};


void DCT8x8(double input[8][8], double output[8][8]){

	for(int l = 0; l < 8; l++){
		for(int k = 0; k < 8; k++){

			double value = 0.0;

			for(int n = 0; n < 8; n++){
				for(int m = 0; m < 8; m++){

					double cosx = cos(M_PI*(2*m+1)*k/16);
					double cosy = cos(M_PI*(2*n+1)*l/16);
					double Cx = 1.0;
					double Cy = 1.0;
					if(k == 0) Cx = 1/sqrt(2.0);
					if(l == 0) Cy = 1/sqrt(2.0);

					double temp = input[m][n];
					temp = temp*cosx*cosy*Cx*Cy/4;

					value = value + temp;
				}
			}
			output[k][l] = value;
		}
	}
}

void IDCT8x8(double input[8][8], double output[8][8]){

	for(int n = 0; n < 8; n++){
		for(int m = 0; m < 8; m++){

			double value = 0.0;

			for(int l = 0; l < 8; l++){
				for(int k = 0; k < 8; k++){

					double cosx = cos(M_PI*(2*m+1)*k/16);
					double cosy = cos(M_PI*(2*n+1)*l/16);
					double Cx = 1.0;
					double Cy = 1.0;
					if(k == 0) Cx = 1/sqrt(2.0);
					if(l == 0) Cy = 1/sqrt(2.0);

					double temp = input[k][l];
					temp = temp*cosx*cosy*Cx*Cy/4;

					value = value + temp;
				}
			}
			output[m][n] = value;
		}
	}

}
