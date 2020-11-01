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

int main()
{
	random_device device; //this method generates real, random numbers
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0, 9);
	vector<int> answerIntVector;

	while (answerIntVector.size() != 4) //pushes random numbers into the vector until it's full
	{
		int distributionInt = distribution(generator);
		if (find(answerIntVector.begin(), answerIntVector.end(), distributionInt) 
			== answerIntVector.end()) //only pushes numbers that aren't already in the vector
		{
			answerIntVector.push_back(distributionInt);
		}
	}

	stringstream answerIntVectorStream;
	for (size_t i = 0; i < answerIntVector.size(); ++i)
	{
		answerIntVectorStream << answerIntVector[i]; 

	}

	string answerString = answerIntVectorStream.str(); //pushes the vector into a string
	istringstream answerStream(answerString);
	int answerInt;
	answerStream >> answerInt;
	string guess;
	cout << endl << "Welcome to the game of Bulls and Cows." << endl;
	cout << endl << "In this game, you must guess a random, ";
	cout << "4-digit number consisting of unique numbers." << endl;
	cout << endl << "When you correctly guess the correct number in the right position, ";
	cout << "that's a bull." << endl;
	cout << endl << "When you correctly guess the correct number but in the wrong position, ";
	cout << "that's a cow." << endl;
	cout << endl << "You can also enter -1 to see the solution. Good luck." << endl << endl;

	while (true) //runs until the the game is finished or the solution is given
	{
		bool answerDigitUsed[4] = {false, false, false, false}; //check correct guesses
		bool guessDigitUsed[4] = {false, false, false, false};
		cout << endl << "Please enter 4 digits: ";
		cin >> guess;
		istringstream guessStream(guess);
		int guessInt;
		guessStream >> guessInt;

		if (guessInt == -1) //give solution if -1 is given
		{
			cout << "The correct number is " << answerString << endl;
			break;
		}

		if (!(guessInt >= 1000 && guessInt <= 9999)) //gives error for incorrect numbers
		{
			cout << endl << "Error! Not in the range of 1000-9999" << endl;
			continue;
		}

		int bulls = countBulls(answerString, guess, answerDigitUsed, guessDigitUsed);

		if (bulls == 4) //ends game when the player wins
		{
			cout << endl << "Bullseye! You correctly guessed " << answerString << endl;
			break;
		}

		int cows = countCows(answerString, guess, answerDigitUsed, guessDigitUsed);

		cout << "Your guess of " << guess << " has " << bulls << " bull(s) and " << cows 
			<< " cow(s)." << endl;
	}

	return 0;
}