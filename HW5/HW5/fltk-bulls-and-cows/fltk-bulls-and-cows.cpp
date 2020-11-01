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

int main(int argc, char **argv)
{
	Fl_Window win(380, 270, "fltk-bulls-and-cows");
	win.begin();

	win.add(inputGuess);
	inputGuess->tooltip("Enter a guess.");

	win.add(outputResult);
	outputResult->tooltip("Compares your guess to the correct answer.");

	win.end();
	win.show(argc, argv);
	return Fl::run();
}