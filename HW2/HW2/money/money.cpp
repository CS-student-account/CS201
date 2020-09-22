/*
* money.cpp
* David Misyura
* 21 Sept 2020
* money.cpp for CS201
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int pennies;
	int nickels;
	int dimes;
	int quarters;
	int dollars;

	cout << "How many pennies? ";
	cin >> pennies;
	cout << "How many nickels? ";
	cin >> nickels;
	cout << "How many dimes? ";
	cin >> dimes;
	cout << "How many quarters? ";
	cin >> quarters;
	cout << "How many dollars? ";
	cin >> dollars;

	cout << endl << "You have " << pennies << " pennies." << endl;
	cout << "You have " << nickels << " nickels." << endl;
	cout << "You have " << dimes << " dimes." << endl;
	cout << "You have " << quarters << " quarters." << endl;
	cout << "You have " << dollars << " dollars." << endl;
	return 0;
}