#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

int boxer(string inputString, int inputInt)
{
	int pad = 2;
	int rows = (pad * 2) + inputString.size() + (2 * inputInt);
	int columns = 1 + (pad * 2) + (2 * inputInt);
	int columnCounter = 0;

	cout << endl;

	while (columnCounter != columns)
	{
		int rowCounter = 0;

		while (rowCounter != rows)
		{
			if (rowCounter <= inputInt - 1 || rowCounter >= rows - inputInt || columnCounter <= inputInt - 1 || columnCounter >= columns - inputInt)
			{
				cout << "*";
			}
			else
			{
				if (rowCounter == pad + inputInt && columnCounter == pad + inputInt)
				{
					cout << inputString;
					rowCounter += (inputString.size() - 1);
				}
				else
				{
					cout << " ";
				}
			}
			++rowCounter;
		}
		++columnCounter;
		cout << endl;
	}
	return 0;
}