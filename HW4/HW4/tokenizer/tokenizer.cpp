/*
* tokenizer.cpp
* David Misyura
* 6 Oct 2020
* tokenizer.cpp for CS201
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

bool ReadLine(std::string &str)
{
	if (getline(cin, str))
	{
		return true;
	}
	else return false;
}

unsigned StringToTokenWS(const std::string &input, std::vector<std::string> &tokens)
{
	istringstream instream(input);
	string token;

	cout << endl;
	while (instream >> token)
	{
		tokens.push_back(token);
		if (token != "end")
		{
			cout << token << '\n';
		}

		if (' ')
		{
			cout << "";
		}
	}
	return tokens.size();
}