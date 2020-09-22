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
using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

void InputNames(vector<string> & names);
bool DoesNameExist(const string & nameToFind, const vector<string> & names);

int main()
{
	vector<string> names;
	InputNames(names);
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

bool DoesNameExist(const string & nameToFind, const vector<string> & names)
{

}