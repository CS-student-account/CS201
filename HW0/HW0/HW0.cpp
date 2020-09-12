/*
* HW0.cpp
* David Misyura
* 3 Sept 2020
* HW0 for CS201
*/


#include <iostream>
using std::cout;
using std::endl;


int main()
{
	for (int i = 0; i < 5; i++) //Main Program: Print out "Hello World" 5 times with a simple for-loop.
	{
		cout << "Hello, world!" << endl;
	}

	cout << endl << "But the raven," << endl;  //Program 1: Print out excerpt from a favorite poem.
	cout << "sitting lonely on the placid bust," << endl;
	cout << "spoke only that one word," << endl;
	cout << "as if his soul in that one word he did outpour." << endl;

	cout << endl << "One of my favorite games, The Witcher 3," << endl; //Program 2: Description about a favorite game
	cout << "tells the tale of Geralt of Rivia." << endl;
	cout << "The player takes Geralt across vast lands" << endl;
	cout << "in search of Ciri, his adopted" << endl;
	cout << "daughter whom he'd protect with his life." << endl;
	cout << "The player engages in combat," << endl;
	cout << "loots treasure, completes quests," << endl;
	cout << "and much more in this expansive game." << endl;
	return 0;
}