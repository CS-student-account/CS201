// Image3.hpp
// Implementation for Image3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include "Image3.hpp"
#include <iostream>
#include <fstream>
#include <string>
using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::istream;
using std::ostream;

// Image3 Constructor
Image3::Image3(unsigned width, unsigned height):w(width),h(height)
{
	// TODO: resize the pixels vector
	pixels.resize(width*height);
	// TODO: initialize the internal w and h members
}

// Return a pixel from the image
const Color3& Image3::getPixel(unsigned x, unsigned y) const 
{
	// TODO: Add error handling for unknown pixels
	// TERRIBLE OPTION 1: throw
	// BETTER OPTION 2: return a color
	// Hint: maybe this is already in the class?

	return pixels[y * w + x];
}

void Image3::setPixel(unsigned x, unsigned y, const Color3& color) 
{
	// TODO: Set the pixel to the new color
	pixels[y * w + x] = color;
}

bool Image3::savePPM(const string& path) const
{
	// TODO: Save the image to the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	ofstream fout(path);
	if (!fout)
	{
		cout << "Error saving " << path << endl;
		return false;
	}
	cout << "Saved " << path << endl;
	return true;
}

bool Image3::loadPPM(const string& path) 
{
	// TODO: Load an image from the disk
	// REQUIREMENT: Use the STREAM operators for the file contents
	ifstream fin(path);
	if (!fin)
	{
		cout << "Error opening " << path << endl;
		return false;
	}
	cout << "Opened " << path << endl;
	return true;
}

void Image3::printASCII(ostream& ostr) const 
{
	// TODO: Print an ASCII version of this image
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << pixels[i * w + j].asciiValue();
		}
		cout << endl;
	}
}

// STREAM OPERATORS for IMAGE3 class

ostream& operator<<(ostream& ostr, const Image3& image) 
{
	// TODO: Write out PPM image format to stream
	// ASSUME FORMAT WILL BE GOOD
	ostr << "P3" << endl;
	ostr << image.w << " ";
	ostr << image.h << endl;
	ostr << "255" << endl;
	for (auto i : image.pixels)
	{
		ostr << i.r << " " << i.g << " " << i.b << endl;
	}

	return ostr;
}

istream& operator>>(istream& istr, Image3& image) 
{
	// TODO: Read in PPM image format from stream
	// MAKE SURE FORMAT IS GOOD!!!

	string line, magicNumber;
	getline(istr, line);
	if (line[0] == 'P' && line[1] == '3')
	{
		cout << "PPM image" << endl;
		magicNumber = "P3";
	}
	else
	{
		cout << "This is not a PPM image" << endl;
	}

	getline(istr, line);
	if (line[0] == '#')
	{
		cout << "Ignoring comment(s)" << endl;
	}

	int xres, yres, maxval;
	istr >> xres >> yres >> maxval;
	if (!istr)
	{
		cout << "Error reading" << endl; 
	}

	for (auto &i : image.pixels) //stream in every pixel by reference
	{
		istr >> i;
	}

	return istr;
}
