/*
* fltk-trunc.cpp
* David Misyura
* 29 Oct 2020
* fltk-trunc.cpp for CS201
*/

#include "truncstruct.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;
using std::setprecision;
using std::setw;
using std::fixed;
using std::getline;

int main()
{
	string input;
	getline(cin, input);

	StringInfo output = trunc8(input);

	cout << output.str;

	return 0;
}