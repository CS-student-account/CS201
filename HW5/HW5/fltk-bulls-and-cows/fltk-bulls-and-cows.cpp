/*
* fltk-bulls-and-cows.cpp
* David Misyura
* 31 Oct 2020
* fltk-bulls-and-cows.cpp for CS201
*/

#include "bulls-and-cows.h"
#include <string>
#include <vector>
#include <sstream>
#include <random>
#include <algorithm>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
using std::string;
using std::stringstream;
using std::vector;
using std::getline;
using std::istringstream;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::to_string;
using std::find;

Fl_Input *inputGuess = new Fl_Input(143, 200, 120, 20, "Guess ");
Fl_Output *outputResult = new Fl_Output(65, 230, 300, 20, "Result ");

void guesscb(Fl_Widget *, void *userdata) //callback function for Truncate button
{
	string inputGuessString = inputGuess->value(); //convert pointer to string
	stringstream stream(inputGuessString);
	int inputGuessInt;
	stream >> inputGuessInt; //convert string to int


	string *answerStringPointer = static_cast<string*>(userdata);
	string answerString = *answerStringPointer;
	istringstream answerStream(answerString);
	int answerInt;
	answerStream >> answerInt;

	while (true) //runs until the the game is finished or the solution is given
	{
		bool answerDigitUsed[4] = { false, false, false, false }; //check correct guesses
		bool guessDigitUsed[4] = { false, false, false, false };

		if (inputGuessInt == -1) //give solution if -1 is given
		{
			string completeAnswerString = "The correct number is " + answerString;
			const char* outputAnswer = const_cast<char*>(completeAnswerString.c_str());

			outputResult->value(outputAnswer); //push message to Result form
			break;
		}

		if (!(inputGuessInt >= 1000 && inputGuessInt <= 9999)) //give error for incorrect numbers
		{
			string completeAnswerString = "Error! Not in the range of 1000-9999";
			const char* outputAnswer = const_cast<char*>(completeAnswerString.c_str());

			outputResult->value(outputAnswer); //push message to Result form
			break;
		}

		int bulls = countBulls(answerString, inputGuessString, answerDigitUsed, guessDigitUsed);

		if (bulls == 4) //ends game when the player wins
		{
			string completeAnswerString = "Bullseye! You correctly guessed " + answerString;
			const char* outputAnswer = const_cast<char*>(completeAnswerString.c_str());

			outputResult->value(outputAnswer); //push message to Result form
			break;
		}

		int cows = countCows(answerString, inputGuessString, answerDigitUsed, guessDigitUsed);

		string completeAnswerString = "Your guess of " + inputGuessString + " has " + to_string(bulls) 
			+ " bull(s) and " + to_string(cows) + " cow(s).";
		const char* outputAnswer = const_cast<char*>(completeAnswerString.c_str());

		outputResult->value(outputAnswer); //push message to Result form
		break;
	}
}

void quitcb(Fl_Widget *, void *) //Quit button callback function
{
	exit(0);
}

int main(int argc, char **argv)
{
	Fl_Window win(380, 350, "fltk-bulls-and-cows");
	win.begin();

	Fl_Box *label1 = new Fl_Box(20, 10, 340, 20, //each of these are just instruction text
		"Welcome to the game of Bulls and Cows.");
	label1->box(FL_NO_BOX);
	label1->labelfont(FL_BOLD);
	label1->align(FL_ALIGN_WRAP);

	Fl_Box *label2 = new Fl_Box(20, 40, 340, 20,
		"In this game, you must guess a random, 4-digit number consisting of unique numbers.");
	label2->box(FL_NO_BOX);
	label2->labelfont(FL_BOLD);
	label2->align(FL_ALIGN_WRAP);

	Fl_Box *label3 = new Fl_Box(20, 80, 340, 20,
		"When you correctly guess the correct number in the right position, that's a bull.");
	label3->box(FL_NO_BOX);
	label3->labelfont(FL_BOLD);
	label3->align(FL_ALIGN_WRAP);

	Fl_Box *label4 = new Fl_Box(20, 120, 340, 20,
		"When you correctly guess the correct number but in the wrong position, that's a cow.");
	label4->box(FL_NO_BOX);
	label4->labelfont(FL_BOLD);
	label4->align(FL_ALIGN_WRAP);

	Fl_Box *label5 = new Fl_Box(20, 160, 340, 20,
		"You can also enter -1 to see the solution.\nGood luck.");
	label5->box(FL_NO_BOX);
	label5->labelfont(FL_BOLD);
	label5->align(FL_ALIGN_WRAP);

	win.add(inputGuess); //input form for user's Guess
	inputGuess->tooltip("Enter a guess.");

	win.add(outputResult); //output form for how close the user's guess was to the answer
	outputResult->tooltip("Compares your guess to the correct answer.");

	//https://stackoverflow.com/questions/29549873/stdmt19937-doesnt-return-random-number
	/*random_device device; //this method generates real, random numbers
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(0, 9);
	int rand = generator();
	rand %= 10000;
	string randomString = to_string(rand);
	void* random = &randomString;
	int distributionInt = distribution(generator);/**/
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
	for (int i = 0; i < answerIntVector.size(); ++i)
	{
		answerIntVectorStream << answerIntVector[i];
	}
	
	string answerString;
	answerIntVectorStream >> answerString; //pushes the vector into a string
	void* random = static_cast<void*>(&answerString);

	//char* answerChar = (char*) random;
	//string answerStringString(answerChar);

	Fl_Button *buttonGuess = new Fl_Button(100, 310, 80, 25, "&Guess"); //Guess button
	buttonGuess->tooltip("Checks whether the guessed number is correct or not.");
	buttonGuess->callback(guesscb, random);


	Fl_Button *buttonQuit = new Fl_Button(180, 310, 80, 25, "&Quit"); //Quit button
	buttonQuit->tooltip("Quits the application.");
	buttonQuit->callback(quitcb, 0);

	win.end();
	win.show(argc, argv);
	return Fl::run();
}