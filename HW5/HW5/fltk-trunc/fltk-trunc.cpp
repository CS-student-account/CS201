/*
* fltk-trunc.cpp
* David Misyura
* 29 Oct 2020
* fltk-trunc.cpp for CS201
*/

#include "truncstruct.hpp"
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

Fl_Input *inputString = new Fl_Input(70, 60, 180, 20, "String ");
Fl_Input *inputLength = new Fl_Input(70, 90, 180, 20, "Length ");
Fl_Output *output = new Fl_Output(70, 120, 180, 20, "Output ");

int main(int argc, char **argv) 
{
	Fl_Window win(320, 190, "fltk-truncstruct");
	win.begin();

	Fl_Box *box = new Fl_Box(10, 20, 300, 20, 
		"Enter a string and an integer for the string's length. Then, click the Truncate button.");
	box->box(FL_NO_BOX);
	box->labelfont(FL_BOLD);
	box->align(FL_ALIGN_WRAP);

	win.add(inputString);
	inputString->tooltip("Enter any string you like.");

	win.add(inputLength);
	inputLength->tooltip("Enter the length you wish to truncate your string to.");

	win.add(output);

	Fl_Button *buttonTruncate = new Fl_Button(60, 150, 80, 25, "&Truncate");
	buttonTruncate->tooltip("Truncates the input string.");
	buttonTruncate->callback(truncatecb, 0);

	Fl_Button *buttonQuit = new Fl_Button(180, 150, 80, 25, "&Quit");
	buttonQuit->tooltip("Quits the application.");
	buttonQuit->callback(quitcb, 0);

	win.end();
	win.show(argc,argv);
	return Fl::run();
}