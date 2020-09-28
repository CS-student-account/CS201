/*
* rice.cpp
* David Misyura
* 22 Sept 2020
* rice.cpp for CS201
*/

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;
using std::pow;

int main()
{
	int sum = 0; //integer variable for sum all rice
	int current = 0; //integer variable for current amount of rice
	bool flag1 = false; //boolean flags for terminating the if-statements
	bool flag2 = false;
	bool flag3 = false;


	//iterative loop for all 64 squares of chessboard
	for (int i = 0; i < 64; i++)
	{
		current = pow(2, i); //perform exponential calculation once per loop iteration
		//cout << current << endl;

		if (sum >= 1000 && !flag1)
		{
			cout << endl << "For 1,000 grains of rice, you need " << i+1 
				<< " chess squares." << endl << endl;
			flag1 = true;
		}

		if (sum >= 1'000'000 && !flag2)
		{
			cout << endl << "For 1,000,000 grains of rice, you need " 
				<< i+1 << " chess squares." << endl << endl;
			flag2 = true;
		}

		if (sum >= 1'000'000'000 && !flag3)
		{
			cout << endl << "For 1,000,000,000 grains of rice, you need " 
				<< i+1 << " chess squares." << endl << endl;
			flag3 = true;
		}
		sum += current;
	}

	cout << endl << "Using integers, the largest number of squares ";
	cout << "capable of representing the grains of rice is 31." << endl;
	cout << endl << "Using doubles, the largest number of squares ";
	cout << "capable of representing the grains of rice is 20." << endl;

	return 0;
}