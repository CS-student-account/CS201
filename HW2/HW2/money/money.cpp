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
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::setprecision;

int main()
{
	//float variables for the currencies to ensure decimal points are retained
	float pennies;
	float nickels;
	float dimes;
	float quarters;
	float dollars;

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

	//if-else statements for each currency to ensure grammatical correctness
	if (pennies == 1)
	{
		cout << endl << "You have " << pennies << " penny." << endl;
	}
	else
	{
		cout << endl << "You have " << pennies << " pennies." << endl;
	}

	if (nickels == 1)
	{
		cout << "You have " << nickels << " nickel." << endl;
	}
	else
	{
		cout << "You have " << nickels << " nickels." << endl;
	}

	if (dimes == 1)
	{
		cout << "You have " << dimes << " dime." << endl;
	}
	else
	{
		cout << "You have " << dimes << " dimes." << endl;
	}

	if (quarters == 1)
	{
		cout << "You have " << quarters << " quarter." << endl;
	}
	else
	{
		cout << "You have " << quarters << " quarters." << endl;
	}

	if (dollars == 1)
	{
		cout << "You have " << dollars << " dollar." << endl;
	}
	else
	{
		cout << "You have " << dollars << " dollars." << endl;
	}

	//print the total sum of money in either cents or dollars
	if (((pennies*0.01) + (nickels*0.05) + (dimes*0.10) + (quarters*0.25) 
		+ (dollars)) == 0)
	{
		cout <<endl << "You have nothing, sir!" << endl;
	}
	else if (((pennies*0.01) + (nickels*0.05) + (dimes*0.10) + (quarters*0.25) 
		+ (dollars)) < 1)
	{
		cout << endl << "You have a total of " << ((pennies*0.01) + (nickels*0.05) 
			+ (dimes*0.10) + (quarters*0.25))*100 << " cents" << endl;
	}
	else
	{
		cout << endl << "You have a total of $" << setprecision(3) << (pennies*0.01) 
			+ (nickels*0.05) + (dimes*0.10) + (quarters*0.25) + (dollars) << endl;
	}
	return 0;
}