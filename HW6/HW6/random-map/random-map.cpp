/*
* random-map.cpp
* David Misyura
* 101 Nov 2020
* random-map.cpp for CS201
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::getline;
using std::istringstream;
using std::stringstream;
using std::ostringstream;
using std::ofstream;
using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::normal_distribution;
using std::seed_seq;
using std::default_random_engine;
using std::setprecision;
using std::setw;
using std::fixed;
using std::round;
using std::sort;
using std::find;

int RandomBetweenU(int first, int last)
{
	cout << endl << endl;
	cout << "RandomBetweenU(" << "First: " << first << ", Last: " << last << ")" << endl;
	random_device r;
	default_random_engine e1(r());
	uniform_int_distribution<int> uniform_dist(first, last);
	int output = uniform_dist(e1);
	cout << "Output: " << output;
	return 0;
}

int RandomBetweenN(int first, int last)
{
	cout << endl << endl << endl;
	cout << "RandomBetweenN(" << "First: " << first << ", Last: " << last << ")" << endl;
	random_device r;
	default_random_engine e1(r());

	uniform_int_distribution<int> uniform_dist(first, last);
	double outputDouble = uniform_dist(e1);

	normal_distribution<double> normal_dist(outputDouble, 1);

	// Generate a normal distribution around that mean
	cout << "Mean: " << outputDouble << endl;

	while (true)
	{
		int output = normal_dist(e1);

		if (output >= first && output <= last)
		{
			cout << "Output: " << output;
			break;
		}
	}
	return 0;
}

int RandomBetween(int first, int last)
{
	cout << endl << endl << endl;
	cout << "RandomBetween(" << "First: " << first << ", Last: " << last << ")" << endl;
	srand(time(NULL));
	int output = first + (rand() % last - first + 1);
	cout << "Output: " << output << endl;
	return 0;
}

int main()
{
	// Seed with a real random value, if available
	random_device r;

	// Choose a random mean between 1 and 6
	default_random_engine e1(r());
	uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	cout << "Randomly-chosen mean: " << mean << '\n';

	// Generate a normal distribution around that mean
	seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	mt19937 e2(seed2);
	normal_distribution<> normal_dist(mean, 2);

	map<int, int> hist;
	for (int n = 0; n < 10000; ++n) 
	{
		++hist[round(normal_dist(e2))];
	}
	cout << "Normal distribution around: " << mean << "\n";
	for (auto p : hist) 
	{
		cout << fixed << setprecision(1) << setw(2)
			<< p.first << ' ' << string(p.second / 200, '*') << '\n';
	}


	vector<int> pair;

	while (pair.size() != 2) //pushes random numbers into the vector until it's full
	{
		int temp = uniform_dist(e1);
		//only pushes numbers that aren't already in the vector
		if (find(pair.begin(), pair.end(), temp) == pair.end())
		{
			pair.push_back(temp);
		}
	}
	sort(pair.begin(), pair.end());

	RandomBetweenU(pair.at(0), pair.at(1));
	RandomBetweenN(pair.at(0), pair.at(1));
	RandomBetween(pair.at(0), pair.at(1));
}