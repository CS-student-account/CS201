/*
* fltk-bulls-and-cows.cpp
* David Misyura
* 31 Oct 2020
* fltk-bulls-and-cows.cpp for CS201
*/

#include "bulls-and-cows.h"
#include <string>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Box.H>
using std::string;
using std::stringstream;

Fl_Input *inputGuess = new Fl_Input(143, 200, 120, 20, "Guess ");
Fl_Output *outputResult = new Fl_Output(143, 230, 120, 20, "Result ");

void quitcb(Fl_Widget *, void *)
{
	exit(0);
}

int main(int argc, char **argv)
{
	Fl_Window win(380, 290, "fltk-bulls-and-cows");
	win.begin();

	Fl_Box *label1 = new Fl_Box(20, 10, 340, 20,
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

	win.add(inputGuess);
	inputGuess->tooltip("Enter a guess.");

	win.add(outputResult);
	outputResult->tooltip("Compares your guess to the correct answer.");

	Fl_Button *buttonQuit = new Fl_Button(180, 250, 80, 25, "&Quit");
	buttonQuit->tooltip("Quits the application.");
	buttonQuit->callback(quitcb, 0);

	win.end();
	win.show(argc, argv);
	return Fl::run();
}