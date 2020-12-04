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
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

int main()
{
	ifstream fin("parrot.ppm");
	Image3 image(80,80);
	fin >> image;
	image.printASCII(cout);

	return 0;
}