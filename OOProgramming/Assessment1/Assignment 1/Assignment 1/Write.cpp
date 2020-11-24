#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include <string>
//#include <stdio.h>
#include "Image.h"
#include "Manipulation.h"

using namespace std;

																								//Write data out to a ppm file
																								//Constructs the header as above
void Manipulation::writePPM(Image &img, const char *filename)
{

	cout << "       Writing image to: " << endl;
	cout << "       " << filename << endl;
	if (img.w == 0 || img.h == 0) { fprintf(stderr, " Can't save an empty image\n"); return; }
	ofstream ofs;
	
	try {
		auto start_Time1 = chrono::high_resolution_clock::now();
		ofs.open(filename, ios::binary);														// need to spec. binary mode for Windows users 
		if (ofs.fail()) throw(" Can't open output file");										//Confirm image write
		ofs << "P6\n" << img.w << " " << img.h << "\n255\n";									// Places at the start of the file to be read using readppm
		unsigned char r, g, b;																	// loop over each pixel in the image, clamp and convert to byte format
		#pragma loop(hint_parallel(8)) 
		for (int i = 0; i < img.w * img.h; ++i) {
			r = static_cast<unsigned char>(min(1.f, img.pixels[i].r) * 255);					//conversion back to ppm interactable filetype
			g = static_cast<unsigned char>(min(1.f, img.pixels[i].g) * 255);
			b = static_cast<unsigned char>(min(1.f, img.pixels[i].b) * 255);
			ofs << r << g << b;
		}
		ofs.close();
		auto end_Time1 = chrono::high_resolution_clock::now();
		//size_t elap = chrono::duration_cast<chrono::milliseconds>(end_Time1 - start_Time1).count();
		chrono::duration<double> elap = end_Time1 - start_Time1;
		double elaps = elap.count();
		cout << "  Image written, Time Taken: " << elaps << " seconds" << endl;			
		//img.image_Details( filename , &img);

//		auto start_Time2 = chrono::high_resolution_clock::now();								//Attempted second image read type, did not speed up writing and was hence removed
//		FILE* wrifile;
//		errno_t op = fopen_s(&wrifile, filename, "wb");
//		//unsigned char r, g, b;
////#pragma loop(hint_parallel(8))
//		if (op != 0) { throw ("Second file failed to open"); }
//		else {
//			wrifile = fopen(filename, "wb");
//			for (int i = 0; i < img.w * img.h; ++i) {
//				r = static_cast<unsigned char>(min(1.f, img.pixels[i].r) * 255);				//conversion back to ppm interactable filetype
//				g = static_cast<unsigned char>(min(1.f, img.pixels[i].g) * 255);
//				b = static_cast<unsigned char>(min(1.f, img.pixels[i].b) * 255);
//				unsigned char str[3] = { r,g,b };
//				fwrite(str, sizeof(unsigned char), sizeof(str), wrifile);
//			}
//			fclose(wrifile);
//			auto end_Time2 = chrono::high_resolution_clock::now();
//			size_t elap2 = chrono::duration_cast<chrono::milliseconds>(end_Time2 - start_Time2).count();
//			cout << "        Image written, Time Taken:" << elap2 << endl;
//		}
//		cin.get();
	}
	
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ofs.close();
	}

}

