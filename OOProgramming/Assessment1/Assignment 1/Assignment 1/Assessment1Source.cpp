#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <array>
#include <stdlib.h>
#include "Image.h"
#include "Manipulation.h"
#include "Zoom.h"

using namespace std;


int main()
{
	Image function_Call;														//Creates an object to call functions
	cout << " ************************************" << endl;
	cout << "    Image Stacker / Image Scaler" << endl;
	cout << " ************************************" << endl;
	
	function_Call.user_Choice();										//Goes to main user choice menu
	/*int array_Size = sizeof(function_Call.img_Array) / sizeof(*function_Call.img_Array);
	for (int i = 0; i <= array_Size; i++) {
		cout << array_Size << endl;
		delete &function_Call.img_Array[i];
		delete[] function_Call.img_Array;
	}*/
	//for (int z = 0; z < 15; ++z) { ~function_Call(); }
	//delete[] function_Call.img_Array ;
	cin.get();
	return 0;
}

void Image::user_Choice() {
	Manipulation func_Call;
	bool exit = false;
	while (exit == false) {
		cin.clear();
		cout << " ************************************" << endl; //Used to have a menu choice for each of the manipulation parts but ran out of time for implementation
		cout << " What would you like to do to the images?" << endl;
		cout << " 1. Mean and Median Blended Image, Sigma Clipped Mean" << endl;
		cout << " 2. Zoom x2 and x4" << endl;
		//cout << " 3. Specific Image Details" << endl;
		cout << " 3. Exit" << endl;
		cout << " ************************************" << endl;
		//constexpr int choice;
		//Manipulation func_Call;
		string choice;
		cin >> choice;
		system("cls");
		switch (func_Call.strconv(&choice))
		{
		case 0:
			cout << "You have not entered a usable value, please try again" << endl;
			break;
		case 1:
			func_Call.input_Array();													//Used to create objects into an array. Used array as in many areas it is quicker than vectors
			system("cls");
			func_Call.mean_Blend();
		/*	break;
		case 2:*/
			func_Call.median_Blend();
			/*break;
		case 3:*/
			func_Call.sigma_Blend();
			func_Call.specific_Image_Details();
			break;
		case 2:
			system("cls");
			Zoom::zoom_2x4x();
			/*break;
		case 5:*/
			//Zoom4x();
			break;
		//case 3:
			//specific_Image_Details();
			//break;
		case 3:
			exit = true;
			break;
		default:
			cout << "You have not entered a usable value, please try again" << endl;
			break;
		}
	}
}
void Manipulation::specific_Image_Details() {
	string choice2;
	bool exit = false;
	while (exit == false) {
		cout << " ***********************************************" << endl;
		cout << " Would you like to see the recorded details of a " << endl;
		cout << " specific Image used in the manipulation? Y/N" << endl;
		cout << " ***********************************************" << endl;
		cin >> choice2;
		system("cls");
		switch (strconv(&choice2)) {
		case(20):
			exit = true;
			break;
		case(21):
			return;
			break;
		default: cout << "Please enter either yes or no" << endl; break;
		}
	}
	bool exit2 = false;
	while (exit2 == false) {
		system("cls");
		cout << " ************************************" << endl;
		cout << " Which Image would you like information on?" << endl;
		cout << " Type between 1 and 13 to view data on IMG_*.ppm" << endl;
		cout << " Type between 14 and 16 to view on the" << endl;
		cout << " Mean, Median, or Sigma repectively " << endl;
		cout << " where the * is the number you have chosen" << endl;
		cout << " Enter 0 or any other value to exit" << endl;
		cout << " ************************************" << endl;
		string choice2;
		cin >> choice2;
		switch (strconv(&choice2))
		{
		case 1: img_Array[0].image_Details(); break;
		case 2: img_Array[1].image_Details(); break;
		case 3: img_Array[2].image_Details(); break;
		case 4: img_Array[3].image_Details(); break;
		case 5: img_Array[4].image_Details(); break;
		case 6: img_Array[5].image_Details(); break;
		case 7: img_Array[6].image_Details(); break;
		case 8: img_Array[7].image_Details(); break;
		case 9: img_Array[8].image_Details(); break;
		case 10: img_Array[9].image_Details(); break;
		case 11: img_Array[10].image_Details(); break;
		case 12: img_Array[11].image_Details(); break;
		case 13: img_Array[12].image_Details(); break;
		case 14: img_Array[13].image_Details(); break;
		case 15: img_Array[14].image_Details(); break;
		case 16: img_Array[15].image_Details(); break;
		default: exit2 = true; break;
		}
		//cin.get();
		system("PAUSE");
	}
}

int Manipulation::strconv(string *inp) {
	if ((*inp) == "1" || (*inp) == "one" || (*inp) == "One" || (*inp) == "ONE")
	{
		return 1;
	}
	else if ((*inp) == "2" || (*inp) == "two" || (*inp) == "Two" || (*inp) == "TWO")
	{
		return 2;
	}
	else if ((*inp) == "3" || (*inp) == "three" || (*inp) == "Three" || (*inp) == "THREE")
	{
		return 3;
	}
	else if ((*inp) == "4" || (*inp) == "four" || (*inp) == "Four" || (*inp) == "FOUR")
	{
		return 4;
	}
	else if ((*inp) == "5" || (*inp) == "five" || (*inp) == "Five" || (*inp) == "FIVE")
	{
		return 5;
	}
	else if ((*inp) == "6" || (*inp) == "six" || (*inp) == "Six" || (*inp) == "SIX")
	{
		return 6;
	}
	else if ((*inp) == "7" || (*inp) == "seven" || (*inp) == "Seven" || (*inp) == "SEVEN")
	{
		return 7;
	}
	else if ((*inp) == "8" || (*inp) == "eight" || (*inp) == "Eight" || (*inp) == "EIGHT")
	{
		return 8;
	}
	else if ((*inp) == "9" || (*inp) == "nine" || (*inp) == "Nine" || (*inp) == "NINE")
	{
		return 9;
	}
	else if ((*inp) == "10" || (*inp) == "ten" || (*inp) == "Ten" || (*inp) == "TEN")
	{
		return 10;
	}
	else if ((*inp) == "11" || (*inp) == "eleven" || (*inp) == "Eleven" || (*inp) == "ELEVEN")
	{
		return 11;
	}
	else if ((*inp) == "12" || (*inp) == "twelve" || (*inp) == "Twelve" || (*inp) == "TWELVE")
	{
		return 12;
	}
	else if ((*inp) == "13" || (*inp) == "thirteen" || (*inp) == "Thirteen" || (*inp) == "THIRTEEN")
	{
		return 13;
	}
	else if ((*inp) == "14" || (*inp) == "fourteen" || (*inp) == "Fourteen" || (*inp) == "FOURTEEN")
	{
		return 14;
	}
	else if ((*inp) == "15" || (*inp) == "fifteen" || (*inp) == "Fifteen" || (*inp) == "FIFTEEN")
	{
		return 15;
	}
	else if ((*inp) == "16" || (*inp) == "sixeen" || (*inp) == "Sixeen" || (*inp) == "SIXTEEN")
	{
		return 16;
	}
	else if ((*inp) == "y"|| (*inp) == "Y" || (*inp) == "yes" || (*inp) == "Yes" || (*inp) == "YES")
	{
		return 20;
	}
	else if ((*inp) == "n" || (*inp) == "N" || (*inp) == "no" || (*inp) == "No" || (*inp) == "NO")
	{
		return 21;
	}
	else return 0;
}


//Questions/Notable details
//How does ifs send specifically the file type to header
//Same for when it sends length, width and binary range to h,w,b respectively, are they just the first ints in the ifs data file
//When writing the file the code puts the data writen in the above two lines into the file, is there storage allocated for this data?
//are ifs and ofs objects and if so how are the strings being stored?
//The casting in Readppm and writeppm is there to convert from the format the image uses to one that can be manipulated in code, not sure
//Look up Virtual Methods, Iterators, Vectors, Pointers, chronos

//Use Release and x64 when running code as it will run quicker
//Vectors vs Arrays: Vectors seem to work better for smaller amounts of data, may be worth using arrays for the large set of data for part A and vectors for Part B
//Can also decrease lines of code by putting Image objects directly into array as written Objects rather than Create them all, read them all then store them all, 1 process rather than 3
// May be possible to read and write using parallel Processing, look into it.

//To save on code for mean blending use the overlodaed operators to add all values up and create one to divide by whatever is needed (13 in this case).

// When doing median blend, sorting is a source of inefficiency, using vectors and then std::sort uses QuickSort or IntroSort (Similar to heapsort). 
//Both have a very good space complexity (O(log(n)) and O(1) respectively) but they can be poor in time complexity (O(n^2) and O(n log(n)) respectively for a worst case scenario), 
//to improve this I need to learn counting or radix sort to improve efficiency as they have both reasonable space complexity (O(k) and O(n+k)) and incredibly efficient 
//Time complecity (O(n+k) and O(nk)).


//Things to do:

//Part A
//Noise Reduction using Image Stacking
//You are provided with a number of images of the same subject.Your aim is, using C++ (code is supplied in the accompanying VS2017 project1), to reduce or remove the noise by
//‘stacking’ the images and using (at least) these three different algorithms and to compare the output(i.e.the final image) of each :
//Mean blending (done)
//Median blending
//Sigma clipped mean
//For more information on these blending methods, have a look at :
// https: //petapixel.com/2013/05/29/a-look-at-reducing-noise-in-photographs-usingmedian-blending/
// https: //www.gnu.org/software/gnuastro/manual/html_node/Sigma-clipping.html
//You should make this code as ‘object oriented’ as possible – eg.the read / write ppm functions should be in their own class, use the STL wherever possible, etc. (partial done aprox 60%, organize better)
//You should also include a member function of the Image class which displays image information(filename, image dimensions, colour depth, image statistics etc).
//This could output its data to a logfile for example. (partial done aprox 90%, Add more data e.g time taken to read and number/average of rgb values)

//Stretch Exercise (1)
//Optimise your code to obtain the best output in the shortest time(and which uses the smallest resources) (In Progress)


//Part B
//Image scaling
//You are provided with an image which can be scaled.Your aim is, using C++, to:
//Extend the Image class from Part A
//Scale the image 2x and 4x
//Use the ‘nearest neighbour zoom’ algorithm
//For more information on scaling algorithms, have a look at :
// http ://www.datagenetics.com/blog/december32013/index.html
// http ://tech-algorithm.com/articles/nearest-neighbor-image-scaling/
//Include a member function of this class which displays polymorphism.
//Recall that “C++ polymorphism means that a call to a member function will cause a different function to be
//executed depending on the type of object that invokes the function”.This function displays
//image information as in Part A, however it should also include zoom details, etc.

//Stretch Exercise (2)
//Apply a more effective zoom algorithm to improve the visual nature of the output(such as the bilinear image scaling algorithm)
//	Select a region of interest(ROI) of the image
//	Extract this ROI as a new image
//	Scale the ROI 2x, 4x



//	Report
//	The report should use the included template, and contain:
// A description of the implementation of Part A and Part B
//o Outline how polymorphism has been implemented in your inheritance
//relationship.
//o Outline how other OO principles have been used in your code.
// A pseudocode description of the Part A and Part B algorithms
// The results of Part A and Part B
// An analysis of these results.Indicate how(if) you have optimised the code for Part
//A and the outcome.

//Old Code:
//****************************************************
//As an example, read one ppm file and write it out to testPPM.ppm
//We need to specify the dimensions of the image
//****************************************************
//***************************************************
//Output the image data to a file for viewing
//***************************************************
//Manipulation::writePPM(*img1, "Images/WritePPM/testPPM.ppm");

//Image checks;
//Manipulation::img_Declare();
//Image *img1 = new Image(3264, 2448);
/*Image *img1 = new Image(3264, 2448);
*img1 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_1.ppm");
Img_Manip::writePPM(*img1, "Images/WritePPM/testPPM.ppm");*/
//Image *img2 = new Image(3264, 2448);
//Image *img3 = new Image(3264, 2448);
//Image *img4 = new Image(3264, 2448);
//Image *img5 = new Image(3264, 2448);
//Image *img6 = new Image(3264, 2448);
//Image *img7 = new Image(3264, 2448);
//Image *img8 = new Image(3264, 2448);
//Image *img9 = new Image(3264, 2448);
//Image *img10 = new Image(3264, 2448);
//Image *img11 = new Image(3264, 2448);
//Image *img12 = new Image(3264, 2448);
//Image *img13 = new Image(3264, 2448);
//Image *img14 = new Image(3264, 2448); // The extra three image objects are used for storage of mean, median and sigma
//Image *img15 = new Image(3264, 2448);
//Image *img16 = new Image(3264, 2448);
//Img_Manip::userChoice();
//int num = checks.img_Count; //Attempt at making the img_Array below has size specific to number of objects created // Would not allow a non constant number even when it was const so created a dynamic array instead
//Num not technically needed but takes less time to type to type
//Image *img1 = new Image(3264, 2448); //Pointer img1 created with size of image sent to Image Constructer (0.2)
//Img_Manip test1; //Could create an object like so to use the class Img_Manip but making the classes static may be an easier and less wasteful option
//img1 -> readPPM("Images/ImageStacker_set1/IMG_1.ppm"); //Black Image sent to function readPMM to be replaced by image in designated file (1.1)
/*vector<Image> Img_store;
Img_store.push_back(*img1);*/
//*img1 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_1.ppm"); //Black Image sent to function readPMM to be replaced by image in designated file (1.1)
//*img2 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_2.ppm");
//*img3 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_3.ppm");
//*img4 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_4.ppm");
//*img5 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_5.ppm");
//*img6 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_6.ppm");
//*img7 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_7.ppm");
//*img8 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_8.ppm");
//*img8 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_9.ppm");
//*img10 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_10.ppm");
//*img11 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_11.ppm");
//*img12 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_12.ppm");
//*img13 = Img_Manip::readPPM("Images/ImageStacker_set1/IMG_13.ppm");
////You can access the individual pixel data
////This accesses and writes out the r, g, b pixel values for the first pixel
////Values are multiplied by 255 as they are 'clamped' between 0 and 1
//*cout << (img1->pixels[0].r) * 255 << endl;
//cout << (img1->pixels[0].g) * 255 << endl;
//cout << (img1->pixels[0].b) * 255 << endl;*/
//Image *img_Array = new Image[num];
//img_Array[0] = (*img1);
//
//////cout << arra;
////for (int i = 0; i < num; i++){
////	
////}
////
////for (int i = 0; i < num; i++)
////	delete[] img_Array[num];
////delete[] img_Array;
////Image *Amta = (Image *)malloc(sizeof(Image) * size);

//Quicksort Implementation attempt (Failed)
//for (int d = 0; d <= 3264 * 2448; ++d) { //Quick Sorting the arrays // Look up Counting sort
//	int left = 0, right = 12, i = 0, j = 12, pivot = (left + right) / 2;
//	while (img_Array[i].pixels[d].r <= img_Array[j].pixels[d].r)
//	{
//
//	}
//	left = 0, right = 12, i = 0, j = 12, pivot = (left + right) / 2;
//	left = 0, right = 12, i = 0, j = 12, pivot = (left + right) / 2;
//}

//Counting sort Implementation (Completed but not usable for float values, lose data if done this way, can be used as part of the radix sort instead)
//std::array <int, 13> red{1};
//int red[13] = {}, green[13] = {}, blue[13] = {}, Test[5] = { 5,7,8,10,2 };
//int r_count[257] = {}, g_count[257] = {}, b_count[257] = {}, T_count[11] = {}; //used = {} as the arrays were not initialising with values zero
//int r_end[13] = {}, g_end[13] = {}, b_end[13] = {}, T_end[5] = {};
////fill_n(r_count, 256, 0);
////int pixel_Size = sizeof(img_Array[0].pixels) / sizeof(*img_Array[0].pixels); //Use the 0 value of img_array as it will always generally contain an image
////cout << pixel_Size << endl;
////cin.get();
//for (int d = 0; d < img_Array[0].w * img_Array[0].h; ++d) {
//	memset(red, 0, sizeof(red)); memset(green, 0, sizeof(green)); memset(blue, 0, sizeof(blue));
//	memset(r_count, 0, sizeof(r_count)); memset(g_count, 0, sizeof(g_count)); memset(b_count, 0, sizeof(b_count));
//	memset(r_end, 0, sizeof(r_end)); memset(g_end, 0, sizeof(g_end)); memset(b_end, 0, sizeof(b_end));
//	for (int e = 0; e < 13; ++e) {
//		red[e] = img_Array[e].pixels[d].r * 255;
//		green[e] = img_Array[e].pixels[d].g * 255;
//		blue[e] = img_Array[e].pixels[d].b * 255;
//	}
//	for (int f = 0; f < 13; ++f) {
//		++r_count[red[f]];
//		++g_count[green[f]];
//		++b_count[blue[f]];
//		//++T_count[Test[f]];
//	}
//	for (int g = 1; g < 257; ++g) {
//		r_count[g] = r_count[g] + r_count[g - 1]; //Did not use += incase of operator overloading issues from mean blending
//		g_count[g] = g_count[g] + g_count[g - 1];
//		b_count[g] = b_count[g] + b_count[g - 1];
//		//T_count[g] += T_count[g - 1];
//	}
//	for (int h = 0; h < 13; ++h) {
//		r_end[r_count[red[h]] - 1] = red[h]; //Changes the red[] array value to that of the r_count[] array index that corresponds to the original red[] array value - 1
//		r_count[red[h]] = r_count[red[h]] - 1;				//Decreases the number at count to make sure two of the same number don't go to the same array location
//		g_end[g_count[green[h]] - 1] = green[h];
//		--g_count[green[h]];
//		b_end[b_count[blue[h]] - 1] = blue[h];
//		--b_count[blue[h]];
//		/*T_end[T_count[Test[h]]-1] = Test[h];
//		--T_count[Test[h]];*/
//	}
//	/*for (int i = 0; i < 5; ++i ) {
//	cout << T_end[i] << endl;
//	}*/
//
//	img_Array[14].pixels[d].r = r_end[7] / 255;
//	img_Array[14].pixels[d].g = g_end[7] / 255;
//	img_Array[14].pixels[d].b = b_end[7] / 255;
//	/*memset(red, 0, sizeof(red)); memset(green, 0, sizeof(green)); memset(blue, 0, sizeof(blue));
//	memset(r_count, 0, sizeof(r_count)); memset(g_count, 0, sizeof(g_count)); memset(b_count, 0, sizeof(b_count));
//	memset(r_end, 0, sizeof(r_end)); memset(g_end, 0, sizeof(g_end)); memset(b_end, 0, sizeof(b_end));*/

//RadixSort


/*vector <Image>::iterator It1;
vector <Image>::iterator It2 = It1+1;*/
//for (int m = 0; m < 2; ++m) {
//	//cout << &It1 << endl;
//	for (int n = 0; n < It1->h * It1->w; ++n) {
//		//It1->pixels[m].r = It1->;
//		VectZoom[m+1].pixels[(2*n) - 1].r = VectZoom[m].pixels[n].r
//	}//It1->pixels
//	/*int[] pixels,*/
//	/*
//}
//writePPM(VectZoom., "Images/WritePPM/Sigma.ppm");
//writePPM(img_Array[15], "Images/WritePPM/Sigma.ppm");
//}
//void Img_Manip::Zoom4x() {}


/*red[l] = img_Array[l].pixels[j].r;
green[l] = img_Array[l].pixels[j].g;
blue[l] = img_Array[l].pixels[j].b;*/


//References::
// Timing the reading of images: https: //www.pluralsight.com/blog/software-development/how-to-measure-execution-time-intervals-in-c--
// Formulae for Standard Deviation: http: //libweb.surrey.ac.uk/library/skills/Number%20Skills%20Leicester/page_19.htm
// Using Template to find out the array size: https: //coderwall.com/p/nb9ngq/better-getting-array-size-in-c
// Using the nearest neighbour algorithm on zoom: http ://tech-algorithm.com/articles/nearest-neighbor-image-scaling/
//Other bilinear algorithm http ://supercomputingblog.com/graphics/coding-bilinear-interpolation/