/*
* bulls-and-cows.cpp
* David Misyura
* 11 Oct 2020
* bulls-and-cows.cpp for CS201
* Some base code attributed to 
* https://www.commonlounge.com/discussion/4e8c5bfa0c5541f6bd3926b4f49417c5/main
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;
using std::stringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::to_string;
using std::find;

//returns the number of bulls for each guess
int countBulls(string &answer, string &guess, bool answerDigitUsed[], bool guessDigitUsed[])
{
	int count = 0;

	for (int i=0; i < 4; i++)
	{
		if (answer[i] == guess[i])
		{
			count++;
			answerDigitUsed[i] = true;
			guessDigitUsed[i] = true;
		}
	}
	return count;
}

//returns the number of cows for each guess
int countCows(string &answer, string &guess, bool answerDigitUsed[], bool guessDigitUsed[])
{
	int count = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (answerDigitUsed[i] || guessDigitUsed[j])
			{
				continue;
			}

			if (answer[i] == guess[j])
			{
				count++;
				answerDigitUsed[i] = true;
				guessDigitUsed[j] = true;
			}
		}
	}
	return count;
}