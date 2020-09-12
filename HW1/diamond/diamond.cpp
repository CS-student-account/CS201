/*
* diamond.cpp
* David Misyura
* 11 Sept 2020
* HW1 diamond.cpp for CS201
*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int i, j, r; //integer variables for counters

	cout << "Create a diamond pattern!" << endl;  //state purpose of application
	cout << endl << "Input an integer: "; //ask user for an integer input
	cin >> r; //accept user's input

	for (i = 0; i <= r; i++) //print top half of diamond
	{
		for (j = 1; j <= r - i; j++)
			cout << " ";
		for (j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << endl;
	}

	for (i = r - 1; i >= 1; i--) //print bottom half of diamond
	{
		for (j = 1; j <= r - i; j++)
			cout << " ";
		for (j = 1; j <= 2 * i - 1; j++)
			cout << "*";
		cout << endl;;
	}
	return 0;
}