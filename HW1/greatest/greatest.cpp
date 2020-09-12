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
	int i, n;
	float arr[10];

	cout << endl << "Enter a sequence of positive integers." << endl;  //state purpose of application
	cout << endl << "To finish, input 0." << endl;  //state purpose of application
	cout << endl << "Afterwards, this application will print the biggest of your integers." << endl;  //state purpose of application

	// Store number entered by the user
	for (i = 0; i < 10; ++i)
	{
		cout << endl << "Enter a positive integer: ";
		cin >> n;
		arr[i] = n;
		if (n < 0) //display error for non-accepted integers
		{
			cout << endl << "Negative integers are not accepted." << endl;
			--i;
		}
		if (n == 0)
		{
			break;
		}

	}

	// Loop to store largest number to arr[0]
	for (i = 1; i < 10; ++i)
	{
		// Change < to > if you want to find the smallest element
		if (arr[0] < arr[i])
			arr[0] = arr[i];
	}

	cout << endl << "The greatest number entered: " << arr[0] << endl;
	return 0;
}