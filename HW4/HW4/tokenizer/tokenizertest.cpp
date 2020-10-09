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
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;



//cout << typeid(tokens[i]).name() << endl;



int main()
{
	string str;
	vector<string> tokens;

	while (true)
	{
		cout << endl;
		ReadLine(str);
		StringToTokenWS(str, tokens);

		if (tokens.back() == "end")
		{
			break;
		}
	}



	return 0;
}