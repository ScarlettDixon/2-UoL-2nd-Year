#ifndef ZOOM_H																	//Included to attempt speed up of code compilation
#define ZOOM_H
#pragma once
#include <cstdlib> 
#include <cstdio>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

class Zoom : public Image
{
public:
	Zoom() : Image() {}
	Zoom(int a, int b) : Image(a, b) {}
	//~Zoom();
	
	
	static void zoom_2x4x();
	void image_Details();//const char *filename/*, Image v1*/);
	static void near_Neighb(vector<Image>, int);
	static void Bilinear(vector<Image>, int);
	static void ROI(Image*);
private:

};
#endif