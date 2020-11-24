#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>
//#include <stdio.h>
#include <cstdio>
#include "Image.h"
#include "Manipulation.h"
//#include "Zoom.h"

using namespace std;

template<typename T1, size_t Arr_Size> constexpr size_t get_Size(T1 (&)[Arr_Size]) {
	return Arr_Size;
}

void Manipulation::input_Array() {
	//Image Call;
	img_Array[0] = readPPM("Images/ReadPPM/IMG_1.ppm");		//Black Image sent to function readPMM to be replaced by image in designated file (1.1)
	img_Array[0].image_Details();
	img_Array[1] = readPPM("Images/ReadPPM/IMG_2.ppm");
	img_Array[1].image_Details();
	img_Array[2] = readPPM("Images/ReadPPM/IMG_3.ppm");
	img_Array[2].image_Details();
	img_Array[3] = readPPM("Images/ReadPPM/IMG_4.ppm");
	img_Array[3].image_Details();
	img_Array[4] = readPPM("Images/ReadPPM/IMG_5.ppm");
	img_Array[4].image_Details();
	img_Array[5] = readPPM("Images/ReadPPM/IMG_6.ppm");
	img_Array[5].image_Details();
	img_Array[6] = readPPM("Images/ReadPPM/IMG_7.ppm");
	img_Array[6].image_Details();
	img_Array[7] = readPPM("Images/ReadPPM/IMG_8.ppm");
	img_Array[7].image_Details();
	img_Array[8] = readPPM("Images/ReadPPM/IMG_9.ppm");
	img_Array[8].image_Details();
	img_Array[9] = readPPM("Images/ReadPPM/IMG_10.ppm");
	img_Array[9].image_Details();
	img_Array[10] = readPPM("Images/ReadPPM/IMG_11.ppm");
	img_Array[10].image_Details();
	img_Array[11] = readPPM("Images/ReadPPM/IMG_12.ppm");
	img_Array[11].image_Details();
	img_Array[12] = readPPM("Images/ReadPPM/IMG_13.ppm");
	img_Array[12].image_Details();

	Image *Meanmedsig = new Image(3264, 2448);
	img_Array[13] = *Meanmedsig; //Used as an error handling in case Mean.ppm is deleted or the executable is closed before finishing the writing
	img_Array[13] = readPPM("Images/WritePPM/Mean.ppm"); //Mean
	img_Array[13].image_Details();
	img_Array[14] = *Meanmedsig;
	img_Array[14] = readPPM("Images/WritePPM/Median.ppm"); //Median
	img_Array[14].image_Details();
	img_Array[15] = *Meanmedsig;
	img_Array[15] = readPPM("Images/WritePPM/Sigma.ppm"); //Sigma Clipping
	img_Array[15].image_Details();
	system("PAUSE"); 
}

void Manipulation::mean_Blend() {
	/*int siz_Array = sizeof(img_Array[0].pixels)/ sizeof(*img_Array[0].pixels);
	int siz_Array2 = sizeof(img_Array)/sizeof(*img_Array);
	cout << siz_Array << endl;
	cout << siz_Array2 << endl;*/
	//	printf("Size of the array: %i \n", img_Array[0].h);
	cout << " ************************************" << endl;
	cout << "            Mean Blending            " << endl;
	cout << " ************************************" << endl;
	cout << "     Preparing to write to File...   " << endl;
#pragma loop(hint_parallel(8)) 
	for (int b = 0; b < img_Array[0].w * img_Array[0].h; ++b) {
		for (int a = 0; a <= 12; ++a) {

			img_Array[13].pixels[b] += img_Array[a].pixels[b];
		}
	}
	for (int c = 0; c < img_Array[0].w * img_Array[0].h; ++c) {
		img_Array[13].pixels[c] /= 13.0f;
	}

	writePPM(img_Array[13], "Images/WritePPM/Mean.ppm");
}


void Manipulation::median_Blend() {
	//vector<Image> MedVect;
	cout << " ************************************" << endl;
	cout << "            Median Blending          " << endl;
	cout << " ************************************" << endl;
	cout << "     Preparing to write to File...   " << endl;

	float red[13] = {}, green[13] = {}, blue[13] = {};
	//for (int d = 0; d < 13; ++d) {
	//	MedVect.push_back(img_Array[d]);
	//}
	//vector<Image>::iterator it1;
	for (int d = 0; d < 3264 * 2448; ++d) {
		for (int e = 0; e < 13; ++e)//it1 = MedVect.begin(); it1 != MedVect.end(); it1++)
		{
			red[e] = img_Array[e].pixels[d].r;
			green[e] = img_Array[e].pixels[d].g;
			blue[e] = img_Array[e].pixels[d].b;
		}
		sort(red, red + 13);
		sort(green, green + 13);
		sort(blue, blue + 13);

		img_Array[14].pixels[d].r = red[6];
		img_Array[14].pixels[d].g = green[6];
		img_Array[14].pixels[d].b = blue[6];
	}
	writePPM(img_Array[14], "Images/WritePPM/Median.ppm");
}


void Manipulation::sigma_Blend() {
	cout << " ************************************" << endl;
	cout << "            Sigma Blending           " << endl;
	cout << " ************************************" << endl;
	cout << " What value Would you like to use as sigma?" << endl;
	float sigma;
	cin >> sigma;
	cout << "     Preparing to write to File...   " << endl;
	Image *Temp1 = new Image(3264, 2448);
	//(*Temp1).pixels = {0};
	Image *Temp2 = new Image(3264, 2448);
	Image *StandDev = new Image(3264, 2448);
	vector <float> RStore;
	vector <float> GStore;
	vector <float> BStore;
	float medr, medg, medb;
	for (int j = 0; j < 3264 * 2448; ++j) {
		RStore.clear();
		GStore.clear();
		BStore.clear();
		for (int k = 0; k <= 12; ++k) {
			(*Temp1).pixels[j].r += ((img_Array[k].pixels[j].r - img_Array[14].pixels[j].r) * (img_Array[k].pixels[j].r - img_Array[14].pixels[j].r));
			(*Temp1).pixels[j].g += ((img_Array[k].pixels[j].g - img_Array[14].pixels[j].g) * (img_Array[k].pixels[j].g - img_Array[14].pixels[j].g));
			(*Temp1).pixels[j].b += ((img_Array[k].pixels[j].b - img_Array[14].pixels[j].b) * (img_Array[k].pixels[j].b - img_Array[14].pixels[j].b));
		}
		(*Temp1).pixels[j] /= 13.0f;
		(*StandDev).pixels[j].r = sqrt((*Temp1).pixels[j].r);
		(*StandDev).pixels[j].g = sqrt((*Temp1).pixels[j].g);
		(*StandDev).pixels[j].b = sqrt((*Temp1).pixels[j].b);
		(*Temp1).pixels[j].r = img_Array[14].pixels[j].r + (sigma * (*StandDev).pixels[j].r);
		(*Temp1).pixels[j].g = img_Array[14].pixels[j].g + (sigma * (*StandDev).pixels[j].g);
		(*Temp1).pixels[j].b = img_Array[14].pixels[j].b + (sigma * (*StandDev).pixels[j].b);
		(*Temp2).pixels[j].r = img_Array[14].pixels[j].r - (sigma * (*StandDev).pixels[j].r);
		(*Temp2).pixels[j].g = img_Array[14].pixels[j].g - (sigma * (*StandDev).pixels[j].g);
		(*Temp2).pixels[j].b = img_Array[14].pixels[j].b - (sigma * (*StandDev).pixels[j].b);
		for (int l = 0; l <= 12; ++l) {
			if (img_Array[l].pixels[j].r > (*Temp1).pixels[j].r || img_Array[l].pixels[j].r < (*Temp2).pixels[j].r) {
				img_Array[l].pixels[j].r = 0.0f;
			}
			if (img_Array[l].pixels[j].g > (*Temp1).pixels[j].g || img_Array[l].pixels[j].g < (*Temp2).pixels[j].g) {
				img_Array[l].pixels[j].g = 0.0f;
			}
			if (img_Array[l].pixels[j].b > (*Temp1).pixels[j].b || img_Array[l].pixels[j].b < (*Temp2).pixels[j].b) {
				img_Array[l].pixels[j].b = 0.0f;
			}
			
			if (img_Array[l].pixels[j].r != 0.0f) RStore.push_back(img_Array[l].pixels[j].r);
			if (img_Array[l].pixels[j].g != 0.0f) GStore.push_back(img_Array[l].pixels[j].g);
			if (img_Array[l].pixels[j].b != 0.0f) BStore.push_back(img_Array[l].pixels[j].b);
		}
		
		size_t sizer = RStore.size();
		size_t sizeg = GStore.size();
		size_t sizeb = BStore.size();
		sort(RStore.begin(), RStore.end());
		sort(GStore.begin(), GStore.end());
		sort(BStore.begin(), BStore.end());

		if (sizer % 2 == 0) medr = (RStore[sizer / 2 - 1] + RStore[sizer / 2]) / 2;
		else medr = RStore[sizer / 2];
		img_Array[15].pixels[j].r = RStore[medr];

		if (sizeg % 2 == 0) medg = (GStore[sizeg / 2 - 1] + GStore[sizeg / 2]) / 2;
		else medg = GStore[sizeg / 2];
		img_Array[15].pixels[j].g = GStore[medg];

		if (sizeb % 2 == 0) medb = (BStore[sizeb / 2 - 1] + BStore[sizeb / 2]) / 2;
		else medb = BStore[sizeb / 2];
		img_Array[15].pixels[j].b = BStore[medb];
	}
	writePPM(img_Array[15], "Images/WritePPM/Sigma.ppm");
	
}



