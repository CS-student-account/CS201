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
	cout << "Please type in some text: ";
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

	//cout << endl;
	while (instream >> token)
	{
		tokens.push_back(token);
		/*if (token != "end")
		{
			cout << token << '\n';
			tokens.push_back(" ");
		}*/

		/*if (' ')
		{
			cout << ' ';
		}*/
	}
	tokens.push_back(" ");
	return tokens.size();
}

void AnalyzeTokens(const std::vector<std::string> &tokens)
{
	vector<string> final;

	for (const auto &i : tokens)
	{

		for (const int &character : i)
		{
			if (character <= 122 && character >= 97)
			{
				final.push_back("[identifier] \"" + i + "\"" + ' ');
				break;
			}

			if (character <= 57 && character >= 48)
			{
				final.push_back("[integer] \"" + i + "\"" + ' ');
				break;
			}

			if (character == 34)
			{
				final.push_back("[quote] \"" + i + "\"" + ' ');
				break;
			}

			if (character >= 33 && character <= 47)
			{
				final.push_back("[other] \"" + i + "\"" + ' ');
				break;
			}

			if (character >= 58 && character <= 64)
			{
				final.push_back("[other] \"" + i + "\"" + ' ');
				break;
			}

			if (character == 32)
			{
				final.push_back("[whitespace] \"\"");
				break;
			}
		}
	}

	if (tokens[tokens.size() - 2] == "end")
	{
		for (int j = 0; j < final.size() - 2; j++)
		{
			cout << endl << final[j] << endl;
		}
	}
}