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
	if (!fin) 
	{
		cout << "Error opening parrot.ppm" << endl;
		exit(1);
	}
	cout << "Opened parrot.ppm" << endl;

	// read the magic number
	string line;
	getline(fin, line);
	if (line[0] == 'P' && line[1] == '3') 
	{
		cout << "PPM (text)" << endl;
	}
	else 
	{
		cout << "Unable to read magic number P3" << endl;
		exit(2);
	}

	// quick and dirty - process the comment
	getline(fin, line);
	if (line[0] == '#') 
	{
		cout << "Ignoring comment" << endl;
	}

	// read the image size xres x yres
	int xres, yres, maxval;
	fin >> xres >> yres >> maxval;
	if (!fin) 
	{ 
		cout << "Error reading" << endl; 
		exit(1); 
	}
	cout << "Image size " << xres << "x" << yres << endl;
	cout << "Maxval = " << maxval << endl;

	int r, g, b, y;
	int pixels2read = xres * yres;
	for (int i = 0; i < pixels2read; i++)
	{
		fin >> r >> g >> b;
		//    cout << "<" << r << "," << g << "," << b << ">";
			// Implement Y = 0.2126R + 0.7152G + 0.0722B
		y = 0.2126 * r + 0.7152 * g + 0.0722 * b;
		//    cout << " -> " << y;
			// Make sure y is [0, 255]
		if (y < 0 || y>255) 
		{
			cout << "ERROR: y out of range" << endl;
			exit(6);
		}
		// map y to a character
		const char values[] = " .,`^*:;!12O38X@";
		// values [0, 7] and y [0, 255] so / by 32
		int val_map = y / 16;
		//    cout << " -> " << val_map << " -> " << values[val_map] << endl;

		cout << values[val_map];
		if (i % xres == xres-1) cout << endl;

	}

	// finish reading - store R,G,B into a vector
	// move read to a function
	// create a class for PPM files
	// HW7 - convert to grayscale (R,G,B) -> Gray
	// HW7 - convert Gray to ASCII char

	cout << endl << "Done" << endl;


	Image3 ppmObject;
	std::ifstream image;
	std::ofstream outFile;

	image.open("C:\\Desktop\\PPMImage.ppm", std::ios::binary);
	image >> ppmObject;

	image.clear();
	image.close();

	outFile.open("C:\\Desktop\\NewImage.ppm", std::ios::binary);
	outFile << ppmObject;

	outFile.clear();
	outFile.close();

	return 0;
}