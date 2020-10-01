/*
* boxer.cpp
* David Misyura
* 29 Sept 2020
* boxer.cpp for CS201
* based off code from https://stackoverflow.com/questions/17988493
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int boxer(string inputString, int inputInt)
{
	int pad = 2; //blank space padding
	int rows = (pad * 2) + inputString.size() + (2 * inputInt); //ensuring proper width
	int columns = 1 + (pad * 2) + (2 * inputInt); //ensuring proper height
	int columnCounter = 0;

	cout << endl;

	while (columnCounter != columns)
	{
		int rowCounter = 0;

		while (rowCounter != rows)
		{
			if (rowCounter <= inputInt - 1 || rowCounter >= rows - inputInt || columnCounter <= inputInt - 1
				|| columnCounter >= columns - inputInt) //print * based off user-selected thickness
			{
				cout << "*";
			}
			else
			{
				if (rowCounter == pad + inputInt && columnCounter == pad + inputInt) //print user's string in middle of box
				{
					cout << inputString;
					rowCounter += (inputString.size() - 1);
				}
				else
				{
					cout << " "; //print blank spaces for padding everywhere else in-between the box
				}
			}
			++rowCounter;
		}
		++columnCounter;
		cout << endl;
	}
	return 0;
}