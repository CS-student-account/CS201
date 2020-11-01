/*
* fltk-bulls-and-cows.cpp
* David Misyura
* 31 Oct 2020
* fltk-bulls-and-cows.cpp for CS201
*/

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

int main(int argc, char **argv)
{
	Fl_Window win(320, 190, "fltk-bulls-and-cows");
	win.begin();

	win.end();
	win.show(argc, argv);
	return Fl::run();
}