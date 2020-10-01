/*
* kelvin.cpp
* David Misyura
* 29 Sept 2020
* kelvin.cpp for CS201
*/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

double ctok(double c)
{
	if (c <= -273.15) //produce error if user inputs below zero kelvin
	{
		cout << endl << "Please don't enter -273.15 degrees celsius or below. Try again later."
			<< endl;
	}
	else
	{
		int k = c + 273.15;
		return k;
	}
}

int main()
{
	double c;
	cout << endl << "This program converts celsius to kelvin." << endl 
		<< "Please enter a temperature in celsius you wish to convert to kelvin: ";
	cin >> c;
	double k = ctok(c);
	if (c > -273.15) //only converts celsius to kelvin if greater than zero kelvin
	{
		cout << endl << c << " degrees celsius converted to kelvin is " << k << " K" << endl;
	}
	return 0;
}

/*original, faulty code with comments

double ctok(double c) //will produce error when given -273.15 C or below
{
	int k = c + 273.15;
	return int; //should be "return k" instead
}

int main()
{
	double c = 0;
	cin >> d; //should be "cin >> c" instead
	double k = ctok("c"); //there shouldn't be apostrophes around c
	Cout << k << '/n'; //cout should be lowercase, and '/n' can
	                   be replaced with endl
}*/