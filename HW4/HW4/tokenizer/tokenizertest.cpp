/*
* tokenizertest.cpp
* David Misyura
* 10 Oct 2020
* tokenizertest.cpp for CS201
*/

#include "tokenizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

int main()
{
	string str; //string for user's input
	vector<string> tokens; //vector of strings for tokenizing the user's input strings

	cout << endl;
	cout << "Please type in some text, separated by spaces. When you're done, type \"end\"." << endl;

	while (true) //a simple loop to operate the program until "end" is typed
	{
		cout << endl;
		ReadLine(str); 
		StringToTokenWS(str, tokens);
		AnalyzeTokens(tokens);
		if (!tokens.empty())
		{
			if (tokens[tokens.size() - 2] == "end") //if the second to last string entered is "end", the program will end
			{
				break;
			}
		}
	}
	return 0;
}