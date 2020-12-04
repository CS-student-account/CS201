/*
* aciiart.cpp
* David Misyura
* 29 Nov 2020
* aciiart.cpp for CS201
*/

#include "Color3.hpp"
#include "Image3.hpp"
#include <fstream>
#include <iostream>
using std::cout;
using std::ifstream;

int main()
{
	ifstream fin("parrot.ppm"); //manually load in a standard PPM image
	Image3 image(80,80); //create an Image3 object and give it the image's dimensions
	fin >> image; //insert the file input stream into the Image3 object for processing
	image.printASCII(cout); //call the member function of the image responsible for printing

	return 0;
}