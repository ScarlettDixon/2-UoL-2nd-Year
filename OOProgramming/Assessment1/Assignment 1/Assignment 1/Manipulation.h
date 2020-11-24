#ifndef MANIPULATION_H
#define MANIPULATION_H
#pragma once
#include <string>
#include <vector>
#include "Image.h"

using namespace std;

class Manipulation {																//Image_Manipulation class
public:
	Manipulation() {}
	//Manipulation(Manipulation& obj) {
	 
	//}
	~Manipulation() {}

	Image img_Array[16];														// The extra three image objects are used for storage of mean, median and sigma
	Image img_ArrCopy[16];
	void input_Array();
	static Image readPPM(const char* file);										//Choice of using friend classes, inheritance, creating static functions or creating an object specifically to call functions.
	static void writePPM(Image &img, const char* file);

	static int strconv(string *inp);

	void mean_Blend();
	void median_Blend();
	void sigma_Blend();
	
	
	void specific_Image_Details();
	friend class Image;
};



#endif
																				
