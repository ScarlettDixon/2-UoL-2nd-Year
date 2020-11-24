#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
//#include <stdio.h>
//#include "Image.pch"
//#include "Manipulation.pch"
#include "Image.h"
#include "Manipulation.h"

using namespace std;

const Image::Rgb Image::kBlack = Image::Rgb(0);								//Only Const taht is used in the code at this point in time
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);