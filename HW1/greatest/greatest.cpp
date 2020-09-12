/*
* greatest.cpp
* David Misyura
* 11 Sept 2020
* HW1 greatest.cpp for CS201
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int i, n; //integers for incrementing for-loop and storing user's input
	float arr[10]; //size-10 array for storing the user's inputs

	cout << endl << "Enter a sequence of positive integers." << endl; //introduce the application to the user
	cout << endl << "To finish, input 0." << endl;
	cout << endl << "Afterwards, this application will print the biggest of your integers." << endl;

	// Store number entered by the user
	for (i = 0; i < 10; ++i) 
	{
		cout << endl << "Enter a positive integer: "; //prompt user for an input
		cin >> n; //store user's input into variable n
		arr[i] = n;  //transfer current value of n into array
		if (n < 0) //display error for non-accepted integers
		{
			cout << endl << "Negative integers are not accepted." << endl;
			--i;
		}
		if (n == 0) //if the user inputs 0, the for-loop exits prematurely
		{
			break;
		}
	}

	for (i = 1; i < 10; ++i) //loop for storing user's input into array
	{
		if (arr[0] < arr[i])
		{
			arr[0] = arr[i];
		}
	}

	cout << endl << "The greatest number entered: " << arr[0] << endl; //print the biggest stored value in the array
	return 0;
}