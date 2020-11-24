#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
#include <chrono>
//#include <stdio.h>
#include <cstdio>
#include "Image.h"
#include "Manipulation.h"
#include "Zoom.h"

using namespace std;

//Read ppm files into the code
//They need to be in 'binary' format (P6) with no comments in the header
//The first line is the 'P'number - P6 indicates it is a binary file, then the image dimensions and finally the colour range
//This header is then followed by the pixel colour data
//eg:	P6
//		3264 2448
//		255
//Open a .ppm file in notepad++ to see this header (caution: they are large files!)


Image Manipulation::readPPM(const char *filename)										// Function (1.1)
{
	
							//cout << "Reading image ..." << endl;					//Remove this cout to prevent multiple outputs
	auto start = chrono::system_clock::now();
	ifstream ifs;
	ifs.open(filename, ios::binary);												//File manipulation
	Image src;// = new Image(3264, 2448);											//Creates src object, goes to constructor (0.1)
	try {
		if (ifs.fail()) {															// If statement to make sure file is accessed correctly
			throw("Can't open the input file - is it named correctly/is it in the right directory?");
		} 
		string header;
		int w, h, b;																//Width, Height and Binary Colour Range
		ifs >> header;																// header contains name of file format
							//cout << header << endl;
		if (strcmp(header.c_str(), "P6") != 0) throw("Can't read the input file - is it in binary format (Has P6 in the header)?"); //Checks if the file is in P6
		ifs >> w >> h >> b;
							//cout << w << " " << h << " " << b << endl;
		src.w = w;
		src.h = h;
		src.bin = b;
		src.filnm = filename;
							//cout << w << " " << h << endl;
		auto start = chrono::high_resolution_clock::now();
		src.pixels = new Image::Rgb[w * h];											// this is throw an exception if bad_allocation // Used to create an intitial empty 1D array
		ifs.ignore(256, '\n');														// skip empty lines in necessary until we get to the binary data 
		size_t CompletePercent = 0;
		size_t onepercent = (w * h) / 100;
		unsigned char pix[3];														// read each pixel one by one and convert bytes to floats 
		for (int i = 0; i < w * h; ++i) {
			ifs.read(reinterpret_cast<char *>(pix), 3);								// converts each pixel being read by ifs into a char pointer that are stored in pixs. 
																					//Reads first three characters each iteteration, when loop implemented it starts from where it stopped
			src.pixels[i].r = pix[0] / 255.f;										//Puts all the primary colours of the pixel into the empty src object, divides nby 255 to make sure it's between 0 and 1
			src.pixels[i].g = pix[1] / 255.f; 
			src.pixels[i].b = pix[2] / 255.f;										//src is an object of the head class Image, RBG is a structure which is a class data structure, so pixels is an object with values r, g and b
			//cout << "\rPercentage Image Read: "<< CompletePercent << "%";
			//if (i % onepercent == 0) {
				//CompletePercent++;
				//cout << "\rPercentage Image Read: " << CompletePercent << "%";
			//}

							//cout << src.pixels[i].r << endl;
							//system("PAUSE");
		}
		ifs.close();																//Closes the stream
		auto finish = chrono::high_resolution_clock::now();
		chrono::duration<double> elapsed = finish - start;
		src.elap = elapsed.count();
		//src.elap = elapsed;
							//cout << filename << endl;
							//cout << *filename << endl;
		//if (filename == "Images/Zoom/zIMG_1.ppm") { src.Img = false; }
		//if (src.Img == true) {  }
	}
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		ifs.close();
	}
							//cout << "Image read" << endl;							//Confirm image read. Delete this to prevent multiple lines output
	return src;
}

 void Image::image_Details(){//const char *filename /*Image *src*/) {
	stringstream data;
	ofstream detailOut;
						//boost::filesystem::path p(filename);						//Look into using boost to get the name cut down
	data << "File Name: " << this->filnm << "\n";//<<endl;								//Would still work for the stringstream, added \n instead to atTemp1t to get different lines when uploaded to the txt file, unsuccesful
	data << "Image Dimensions: " << "Width: " << this->w << " Height: " << this->h << "\n";
	data << "colour depth: " << this->bin << "\n";
	data << "Time taken to read Image: " << this-> elap << " Seconds"<< "\n";	//Could enter in how many r, g and b values there are
	//data << "\n";
	string data2 = data.str();
	cout << data2;
	cout << "This Data will now be outputted to: Images/Image_Details/ImgDet.txt" << endl;
	cout << endl;
	
		try {
			if (this->filnm == "Images/ReadPPM/IMG_1.ppm") {
				detailOut.open("Images/Image_Details/ImgDet.txt", ios::out | ios::trunc);
				if (detailOut.fail()) throw("Can't open Img output file to write");
				detailOut << data2;
			}
			else {
				detailOut.open("Images/Image_Details/ImgDet.txt", ios::app);
				if (detailOut.fail()) throw("Can't open Img output file to append");
				detailOut << data2;
			}
		}
	
	
	catch (const char *err) {
		fprintf(stderr, "%s\n", err);
		detailOut.close();
	}
}

 void Zoom::image_Details() {//const char *filename/*, Image v1*/) {
	 stringstream datazoom;
	 ofstream detailOut;

	 datazoom << "Image taken from: " << this->filnm << "\n";
	 datazoom << "Image Dimensions: " << "Width: " << this->w << " Height: " << this->h << "\n";
	 datazoom << "colour depth: " << this->bin << "\n";
	 datazoom << "Time taken to read Image: " << this->elap << " seconds" << "\n";
	 datazoom << "Number of times zoomed: " << this->zoom_Times << "\n";
	 string datazoom2 = datazoom.str();
	 cout << datazoom2;
	 cout << "This Data will now be outputted to: Images/Image_Details/ZoomDet.txt" << endl;
	 cout << endl;

	 try {
		 if (this->filnm == "Images\Zoom/zIMG_1.ppm") {
			 detailOut.open("Images/Image_Details/ZoomDet.txt", ios::out | ios::trunc);
			 if (detailOut.fail()) throw("Can't open Zoom output file to write");
			 detailOut << datazoom2;
		 }
		 else {
			 detailOut.open("Images/Image_Details/ZoomDet.txt", ios::app);
			 if (detailOut.fail()) throw("Can't open Zoom output file to append");
			 detailOut << datazoom2;
		 }
	 }


	 catch (const char *err) {
		 fprintf(stderr, "%s\n", err);
		 detailOut.close();
	 }

 }



