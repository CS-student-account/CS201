/*
* tokenizertest.cpp
* David Misyura
* 6 Oct 2020
* tokenizertest.cpp for CS201
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <cctype>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

int main()
{
	string str;
	vector<string> tokens;

	cout << endl;
	cout << "Please type in some text, separated by spaces. When you're done, type 'end'." << endl;

	while (true)
	{
		cout << endl;
		ReadLine(str);
		StringToTokenWS(str, tokens);
		AnalyzeTokens(tokens);
		if (!tokens.empty())
		{
			if (tokens[tokens.size() - 2] == "end")
			{
				break;
			}
		}
	}
	return 0;
}