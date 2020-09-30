/*
* boxprint.cpp
* David Misyura
* 27 Sept 2020
* boxprint.cpp for CS201
*/

#include "boxer.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string inputString;
	int inputInt;

	cout << endl;
	cout << "Please enter a word: ";
	cin >> inputString;
	cout << "For the thickness of the box's frame, please enter an integer: ";
	cin >> inputInt;

	boxer(inputString, inputInt);
	return 0;
}