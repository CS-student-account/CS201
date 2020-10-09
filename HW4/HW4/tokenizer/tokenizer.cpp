/*
* tokenizer.cpp
* David Misyura
* 6 Oct 2020
* tokenizer.cpp for CS201
*/

#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool ReadLine(std::string &str)
{
	if (getline(cin, str))
	{
		return true;
	}
	else return false;
}