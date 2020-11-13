/*
* random-map.cpp
* David Misyura
* 12 Nov 2020
* random-map.cpp for CS201
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
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

//returns a uniform random number between two integers
int RandomBetweenU(const int &first, const int &last)
{
	random_device r;
	default_random_engine e1(r());
	uniform_int_distribution<int> uniform_dist(first, last);
	int output = uniform_dist(e1);
	return output;
}

//returns a normal random number between two integers
int RandomBetweenN(const int &first, const int &last)
{
	random_device r;
	default_random_engine e1(r());

	uniform_int_distribution<int> uniform_dist(first, last);
	double outputDouble = uniform_dist(e1);

	seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	mt19937 e2(seed2);

	normal_distribution<double> normal_dist(outputDouble, 2);

	int output = normal_dist(e2);
	return output;
}

//returns a pseudo random number between two integers using rand()
int RandomBetween(const int &first, const int &last)
{
	int output = first + (rand() % last - first + 1);
	return output;
}

//prints a histogram of a given map of the three random number functions
void PrintDistribution(const map<int, int> &numbers)
{
	for (auto p : numbers)
	{
		cout << fixed << setprecision(1) << setw(2)
			<< p.first << ' ' << string(p.second / 100, '*') << endl;
	}
	cout << endl;
}

int main()
{
	//code for creating and printing a uniformly distributed histrogram
	cout << "Uniformly distributed histogram" << endl;
	map<int, int> histogram1;
	for (int n = 0; n < 10000; ++n) 
	{
		++histogram1[RandomBetweenU(1, 10)];
	}
	PrintDistribution(histogram1);

	//code for creating and printing a normally distributed histrogram
	cout << "Normally distributed histogram" << endl;
	map<int, int> histogram2;
	for (int n = 0; n < 10000; ++n) 
	{
		++histogram2[RandomBetweenN(1, 10)];
	}
	PrintDistribution(histogram2);
	
	//code for creating and printing a pseudorandom distributed histrogram
	cout << "Rand() histogram" << endl;
	map<int, int> histogram3;
	for (int n = 0; n < 10000; ++n) 
	{
		++histogram3[RandomBetween(1, 10)];
	}
	PrintDistribution(histogram3);
}