// Color3.cpp
// Implementation for Color3 class
// Original Author: Jonathan Metzgar
// CS 201 course
#include <iomanip>
#include <string>
#include "Color3.hpp"

using std::setw;
using std::ostream;
using std::istream;
using std::stoi;

// Ensure values are in the range 0 to maxvalue
constexpr int saturate(int x, int maxvalue) 
{
	return x < 0 ? 0 : x > maxvalue ? maxvalue : x;
}

Color3::Color3()
	: r(0), g(0), b(0)
{ }

Color3::Color3(int R, int G, int B)
{
	r = saturate(R, 255);
	g = saturate(G, 255);
	b = saturate(B, 255);
}

int Color3::weightedSum() const 
{
	// Implement Y = 0.2126R + 0.7152G + 0.0722B
	// Ensure values are inside the range 0 to 255
	return (0.2126*r + 0.7152*g + 0.0722*b);
}

char Color3::asciiValue() const 
{
	// Use at least 16 characters, sort these from dark to light
	// or light to dark and then map the weightedSum() to the range
	// 0 to 15. Please pick your own characters
	const char values[] = " .,`^*:;!12O38X@"; // .,:;!(*^%$#@ACX
	unsigned darkness = weightedSum()/16;
	return values[darkness];
}

// Stream Operators for input and output

ostream& operator<<(ostream& ostr, const Color3& color) 
{
	ostr << setw(3) << (int)color.r << " ";
	ostr << setw(3) << (int)color.g << " ";
	ostr << setw(3) << (int)color.b << " ";
	return ostr;
}

istream& operator>>(istream& istr, Color3& color) 
{
	// Implement your own input for a Color3
	istr >> color.r >> color.g >> color.b;
	return istr;
}
