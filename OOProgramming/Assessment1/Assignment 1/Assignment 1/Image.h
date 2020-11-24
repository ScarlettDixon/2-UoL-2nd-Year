#ifndef IMAGE_H																	//Included to attempt speed up of code compilation
#define IMAGE_H
#pragma once
//*********************************************
//Image class to hold and allow manipulation of images once read into the code
//from https://www.scratchapixel.com/
//*********************************************
#include <cstdlib> 
#include <cstdio>
#include <vector>
#include <string>
#include <chrono>
//#include "Manipulation.h"

class Image																//: public Manipulation
{
public:
	int img_Count;
	
																				// Rgb structure, i.e. a pixel 
	struct Rgb
	{

		Rgb() : r(0), g(0), b(0) {}												// RGB constructer (1.0)
		Rgb(float c) : r(c), g(c), b(c) {}										// RGB constructer (1.1)
		Rgb(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}				// RGB constructer (1.2)
		
		
		bool operator != (const Rgb &c) const
		{
			return c.r != r || c.g != g || c.b != b;
		}
		Rgb& operator *= (const Rgb &rgb)
		{
			r *= rgb.r, g *= rgb.g, b *= rgb.b; return *this;
		}
		Rgb& operator += (const Rgb &rgb)
		{
			r += rgb.r, g += rgb.g, b += rgb.b; return *this;
		}
		Rgb& operator /= (const float f)
		{
			r /= f, g /= f, b /= f; return *this;
		}
		friend float& operator += (float &f, const Rgb rgb)
		{
			f += (rgb.r + rgb.g + rgb.b) / 3.f; return f;
		}
		float r, g, b;
	};
	const Rgb& operator [] (const unsigned int &i) const
	{
		return pixels[i];
	}
	Rgb& operator [] (const unsigned int &i)
	{
		return pixels[i];
	}
	Image& operator = (const Image& other)									//copy assignment operator
	{
		w = other.w;
		h = other.h;
		bin = other.bin;
		elap = other.elap;
		filnm = other.filnm;
		pixels = new Rgb[other.w * other.h];
		for (int i = 0; i < other.w * other.h; ++i)
			pixels[i] = other.pixels[i];

		return *this;

	}
						// Preset colors 

	Image() : w(0), h(0), pixels(nullptr) { /* empty image */ }				//Blank Image Constructor (0.1)
	Image(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack) : w(_w), h(_h), pixels(NULL) //Image Constructer (0.2), creates Image and then makes every pixel black
	{
		pixels = new Rgb[w * h];											//New Array created with the length width*height
		for (int i = 0; i < w * h; ++i)
			pixels[i] = c;													//The original image is created fully black
		img_Count++;
	}
	
	Image(const Image &im)													//copy constructor
	{
		w = im.w;
		h = im.h;
		pixels = new Rgb[im.w * im.h];
		for (int i = 0; i < im.w * im.h; ++i)
			pixels[i] = im.pixels[i];
	}
	
	
	~Image()
	{
		if (pixels != NULL) delete[] pixels;
							//delete[] pixels;
	}
	static void user_Choice();
	int w, h, bin;															// Image resolution 
	std::string filnm = "";
	Rgb *pixels;															// 1D array of pixels 
	double elap;
	bool Img = true;
	int zoom_Times = 1;
	static const Rgb kBlack, kWhite, kRed, kGreen, kBlue;
	virtual void image_Details();//const char *filename/*,*Image *src*/);
	
	//friend class Manipulation;
	
};
#endif
