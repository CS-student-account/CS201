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
	cout << "Normal distribution around " << mean << ":\n";
	for (auto p : hist) 
	{
		cout << fixed << setprecision(1) << setw(2)
			<< p.first << ' ' << string(p.second / 200, '*') << '\n';
	}


	//uniform_int_distribution<int> uniform_dist(1, 6);
	default_random_engine e3(r());
	default_random_engine e4(r());
	int randomInt1 = uniform_dist(e3);
	int randomInt2 = uniform_dist(e4);
	RandomBetweenU(randomInt1, randomInt2);
}