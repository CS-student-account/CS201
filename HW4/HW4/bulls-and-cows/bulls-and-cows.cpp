/*
* bulls-and-cows.cpp
* David Misyura
* 11 Oct 2020
* bulls-and-cows.cpp for CS201
* Some base code attributed to https://www.commonlounge.com/discussion/4e8c5bfa0c5541f6bd3926b4f49417c5/main
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

int main()
{
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0, 9);
	vector<int> answerIntVector;

	while (answerIntVector.size() != 4)
	{
		int distributionInt = distribution(generator);
		if (find(answerIntVector.begin(), answerIntVector.end(), distributionInt) == answerIntVector.end())
		{
			answerIntVector.push_back(distributionInt);
		}
	}

	stringstream answerIntVectorStream;
	for (size_t i = 0; i < answerIntVector.size(); ++i)
	{
		answerIntVectorStream << answerIntVector[i];

	}

	string answerString = answerIntVectorStream.str();
	istringstream answerStream(answerString);
	int answerInt;
	answerStream >> answerInt;
	string guess;
	cout << endl << "Welcome to the game of Bulls and Cows." << endl;
	cout << endl << "In this game, you must guess a random, 4-digit number consisting of unique numbers." << endl;
	cout << endl << "When you correctly guess the correct number in the right position, that's a bull." << endl;
	cout << endl << "When you correctly guess the correct number but in the wrong position, that's a cow." << endl;
	cout << endl << "You can also enter -1 to see the solution. Good luck." << endl << endl;



	return 0;
}