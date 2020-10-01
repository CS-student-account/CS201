/*
* collatz.cpp
* David Misyura
* 29 Sept 2020
* collatz.cpp for CS201
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int input = 0;

	while (input <= 0) //prompt the user for a positive integer
	{
		cout << endl << "Enter a positive integer for the collatz sequence: ";
		cin >> input;

		if (input <= 0) //indicate that the user's integer wasn't positive
		{
			cout << endl << "Your integer wasn't positive, try again." << endl;
		}
	}
	cout << endl << input;

	while (input != 1) //perform the calculations of the collatz sequence
	{
		if (input % 2) //for even integers
		{
			input = (3 * input) + 1;
		}
		else //for odd integers
		{
			input /= 2;
		}
		cout << " " << input;
	}
	cout << endl;
	return 0;
}