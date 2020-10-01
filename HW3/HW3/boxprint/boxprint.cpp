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
	string answer;
	int inputInt = 0;

	cout << endl;
	cout << "Please enter a word: ";
	cin >> inputString;
	while (inputInt <= 0) //prompt the user for a positive integer
	{
		cout << "For the thickness of the box's frame, please enter a positive integer: ";
		cin >> inputInt;
		if (inputInt <= 0) //indicate that the user's integer wasn't positive
		{
			cout << "Your integer wasn't positive, try again." << endl;
		}
	}
	boxer(inputString, inputInt);

	while (true) //after first call of boxer(), repeatedly ask to make boxes until the user opts out
	{
		cout << endl << "Would you like to try again? (y/n) ";
		cin >> answer;

		if (answer == "n") //the string to opt out of any more boxes
		{
			break;
		}

		if (answer == "y") //the string to make another box
		{
			cout << endl;
			cout << "Please enter a word: ";
			cin >> inputString;
			inputInt = 0;
			while (inputInt <= 0)
			{
				cout << "For the thickness of the box's frame, please enter a positive integer: ";
				cin >> inputInt;
				if (inputInt <= 0)
				{
					cout << "Your integer wasn't positive, try again." << endl;
				}
			}
			boxer(inputString, inputInt);
		}
	}

	cout << endl << "Thanks for playing, come again." << endl;
	return 0;
}