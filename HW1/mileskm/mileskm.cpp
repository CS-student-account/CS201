/*
* mileskm.cpp
* David Misyura
* 11 Sept 2020
* HW1 mileskm.cpp for CS201
*/

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

int main()
{
	float miles;

	//state purpose of application
	cout << "This application converts miles to kilometers to 3 sig figs." << endl;
	cout << endl << "Please enter the number of miles to convert: ";
	cin >> miles; //store user's input as a float representing the number of miles

	//convert the user's input value to km as a float to 3 sig figs
	cout << endl << "Your miles converted to kilometers is: " ; 
	cout << setprecision(3) << (miles*1.609) << " km" << endl;
	return 0;
}