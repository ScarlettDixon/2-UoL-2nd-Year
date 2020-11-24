#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>
#include <cstdio>
#include "Image.h"
#include "Manipulation.h"
#include "Zoom.h"

using namespace std;

void Zoom::zoom_2x4x() {
	cout << " ************************************" << endl;
	cout << "            Zoom x2 and x4           " << endl; //Can either zoom from the original image twice or zoom to x2 then use that to go to x4
	cout << " ************************************" << endl;
	cout << "     Preparing to write to File...   " << endl;
	Image *ZoomOrig = new Zoom(750, 750);
	/*Zoom Orig;
	Zoom Orig2x;
	Zoom Orig4x;*/
	/*ZoomOrig = &Orig;*/
	*ZoomOrig = Manipulation::readPPM("Images/Zoom/zIMG_1.ppm");
	ZoomOrig->image_Details();
	/*Zoom *Orig = &ZoomOrig;*/
	Image *Zoom2xFinal = new Zoom(1500, 1500);
	Zoom2xFinal->zoom_Times = 2;
	Image *Zoom4xFinal = new Zoom(3000, 3000);
	Zoom4xFinal->zoom_Times = 4;
	*Zoom2xFinal = Manipulation::readPPM("Images/Zoom/zIMG_2.ppm");
	Zoom2xFinal->image_Details(); //Problems with not sending through data edited in the vector, need to see if the whole vector can be passed through. //Ended up not needing to send anything in as used the 'this' type
	*Zoom4xFinal = Manipulation::readPPM("Images/Zoom/zIMG_3.ppm");
	Zoom4xFinal->image_Details();
	/*Zoom2xFinal = &Orig2x;
	Zoom4xFinal = &Orig4x;*/
	vector <Image> VectZoom = { *ZoomOrig, *Zoom2xFinal, *Zoom4xFinal };
	//ZoomOrig->image_Details(VectZoom, *ZoomOrig);
	VectZoom[1].zoom_Times = 2;
	near_Neighb(VectZoom, 2);
	
	VectZoom[2].zoom_Times = 4;
	near_Neighb(VectZoom, 4);
	
	ROI(ZoomOrig);

}


void Zoom::near_Neighb(vector<Image> Vect, int times) {
	auto start = chrono::high_resolution_clock::now();
	int w1, h1, w2, h2;
	int store = 1;
	double px, py;
	w1 = Vect[0].w;
	h1 = Vect[0].h;
	w2 = w1 * times;
	h2 = h1 * times;
	double x_ratio = w1 / (double)w2;
	double y_ratio = h1 / (double)h2;
	if (times == 2) { store = 1; }
	else if (times == 4) { store = 2; }
	for (int i = 0; i < h2; i++) {
		for (int j = 0; j < w2; j++) {  //Completing nearest neighbour processing
			px = floor(j * x_ratio);
			py = floor(i * y_ratio);
			Vect[store].pixels[(i*w2)+j]= Vect[0].pixels[(int)((py*w1) + px)]; // V1[0] = V0[0], V1[1] = V0[0], V1[2] = V0[1], V1[3] = V0[1] etc...
		}
	}
	stringstream ofile;
	int store2 = store + 1;
	Vect[store].zoom_Times = times;
	ofile << "Images/Zoom/zImg_" << store2 << ".ppm";
	const string& OFile = ofile.str();
	const char* Ofilec = OFile.c_str();
	Manipulation::writePPM(Vect[store], Ofilec);
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;
	Vect[store].elap = elapsed.count();
}


//void Zoom::Bilinear(vector<Image> Vect, int times) {
//	Manipulation *Write;
//	auto start = chrono::high_resolution_clock::now();
//	int w1, h1, w2, h2;
//	float Comp[4];
//	int store = 1;
//	w1 = Vect[0].w;
//	h1 = Vect[0].h;
//	w2 = w1 * times;
//	h2 = h1 * times;
//	double x_ratio = w1 / (double)w2;
//	double y_ratio = h1 / (double)h2;
//	if (times == 2) { store = 1; }
//	else if (times == 4) { store = 2; }
//	//float x_diff, y_diff, blue, red, green;
//	int offset = 0;
//	for (int i = 0; i < h1; ++i) {
//		for (int j = 0; j < w1; ++j) {	
//			Vect[0].pixels[(i * w2) +((2 * j) - 1)] = Vect[store].pixels[(i * w1) + j];
//
//		}
//		//R1 = ((x2 – x)/(x2 – x1))*Q11 + ((x – x1)/(x2 – x1))*Q21
//		//R2 = ((x2 – x) / (x2 – x1))*Q12 + ((x – x1) / (x2 – x1))*Q22
//		//P = ((y2 – y) / (y2 – y1))*R1 + ((y – y1) / (y2 – y1))*R2
//	}
//	
//	stringstream ofile;
//	int store2 = store + 1;
//	Vect[store].zoom_Times = times;
//	ofile << "Images/Zoom/zImg_" << store2 << ".ppm";
//	const string& OFile = ofile.str();
//	const char* Ofilec = OFile.c_str();
//	Write->writePPM(Vect[store], Ofilec);
//	auto finish = chrono::high_resolution_clock::now();
//	chrono::duration<double> elapsed = finish - start;
//	Vect[store].elap = elapsed.count();
//}

void Zoom::ROI(Image *Orig) {
	cout << " ************************************" << endl;
	cout << "            ROI x2 and x4            " << endl; 
	cout << " ************************************" << endl;
	cout << " The 2x and 4x Zoom Scaling will now be performed" << endl;
	cout << " It will be performed on the Top leftmost 2/3s of the Image" << endl;
	cout << " This is taken as a region of interest" << endl;
	cout << "     Preparing to write to File...   " << endl;
	Image *TLTROI = new Image(500,500); //The Top Left Third of the Image is used as A region of interest
	double px, py;
	double x_ratio = (*TLTROI).w / (double)(*Orig).w;
	double y_ratio = (*TLTROI).h / (double)(*Orig).h;
	for (int i = 0; i < (*TLTROI).h; i++) {
		for (int j = 0; j < (*TLTROI).w; j++) {
			px = floor(j * x_ratio);
			py = floor(i * y_ratio);
			(*TLTROI).pixels[(i * (*TLTROI).w) + j] = (*Orig).pixels[(int)((py*(*Orig).w) + px)];
		}
	}
	Manipulation::writePPM(*TLTROI, "Images/Zoom/zImg_4.ppm");
	Image *TLTROI2x = new Image(1000, 1000);
	
	x_ratio = (*TLTROI).w / (double)(*TLTROI2x).w;
	y_ratio = (*TLTROI).h / (double)(*TLTROI2x).h;
	for (int k = 0; k < (*TLTROI2x).h; k++) {
		for (int l = 0; l < (*TLTROI2x).w; l++) {  //Completing nearest neighbour processing
			px = floor(l * x_ratio);
			py = floor(k * y_ratio);
			(*TLTROI2x).pixels[(k * (*TLTROI2x).w)+ l] = (*TLTROI).pixels[(int)((py*(*TLTROI).w) + px)]; // V1[0] = V0[0], V1[1] = V0[0], V1[2] = V0[1], V1[3] = V0[1] etc...
		}
	}
	Manipulation::writePPM(*TLTROI2x, "Images/Zoom/zImg_5.ppm");
	Image *TLTROI4x = new Image(2000, 2000);
	x_ratio = (*TLTROI).w / (double)(*TLTROI4x).w;
	y_ratio = (*TLTROI).h / (double)(*TLTROI4x).h;
	for (int m = 0; m < (*TLTROI4x).h; m++) {
		for (int n = 0; n < (*TLTROI4x).w; n++) {  //Completing nearest neighbour processing
			px = floor(n * x_ratio);
			py = floor(m * y_ratio);
			(*TLTROI4x).pixels[(m * (*TLTROI4x).w)+ n] = (*TLTROI).pixels[(int)((py*(*TLTROI).w) + px)]; // V1[0] = V0[0], V1[1] = V0[0], V1[2] = V0[1], V1[3] = V0[1] etc...
		}
	}
	Manipulation::writePPM(*TLTROI4x, "Images/Zoom/zImg_6.ppm");
	
}


