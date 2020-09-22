/*
* names.cpp
* David Misyura
* 21 Sept 2020
* names.cpp for CS201
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::find;
using std::reverse;
using std::copy;
using std::ostream_iterator;
using std::sort;
using std::greater;

void InputNames(vector<string> & names);
bool DoesNameExist(string & nameToFind, vector<string> & names);
void PrintNames(vector<string> & names);

int main()
{
	vector<string> names;
	string nameToFind;

	InputNames(names);
	DoesNameExist(nameToFind, names);
	PrintNames(names);
	return 0;
}

void InputNames(vector<string> & names)
{
	for (int i = 0; i < 10; i++)
	{
		string name;
		cout << "Please enter a name: ";
		getline(cin, name);
		names.push_back(name);
	}
	return;
}

bool DoesNameExist(string & nameToFind, vector<string> & names)
{
	if (find(names.begin(), names.end(), "David") != names.end())
	{
		cout << endl << "Name 'David' IS found." << endl;
		return 0;
	}
	else
	{
		cout << endl << "Name 'David' IS NOT found." << endl << endl;
		return 0;
	}
}

void PrintNames(vector<string> & names)
{
	sort(names.begin(), names.end());

	for (int i = 0; i < 10; i++)
	{
		cout <<  names[i] << " " << endl;
	}
	return;
}