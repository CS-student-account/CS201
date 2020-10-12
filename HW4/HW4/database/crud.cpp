/*
* crud.cpp
* David Misyura
* 11 Oct 2020
* crud.cpp for CS201
*/

#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::istringstream;
using std::map;

int main()
{
	int option;
	cout << endl << "Enter 1 to insert" << endl;
	cout << endl << "Enter 2 to update" << endl;
	cout << endl << "Enter 3 to read" << endl;
	cout << endl << "Enter 4 to delete" << endl;
	cout << endl << "Enter 5 to print" << endl << endl;
	cout << endl << "Please select an option: ";

	if (cin >> option)
	{
		if (option == 1)
		{
			InputRecord(record);
		}

		if (option == 2)
		{
			//UpdateRecord(key, record);
		}

		if (option == 3)
		{
			//ReadRecord(key, record);
		}

		if (option == 4)
		{
			//DeleteRecord(key);
		}

		if (option == 5)
		{
			//PrintRecord(key);
		}
	}
	return 0;
}