/*
* math-catch.cpp
* David Misyura
* 12 Nov 2020
* math-catch.cpp for CS201
*/

#define CATCH_CONFIG_MAIN  //tells Catch to provide a main()
#include "catch.hpp"
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using std::sin;
using std::atan2;
using std::accumulate;
using std::inner_product;
using std::vector;

vector<int> v1 = { 1, 2, 3, 4, 5 };
vector<int> v2 = { 6, 7, 8, 9, 10 };

int Sine(int number)
{
	int x = number;
	return sin(x);
}

double Atan2(double number1, double number2)
{
	double x = number1;
	double y = number2;
	return atan2(x, y);
}

int Accumulate(vector<int>::iterator number1, vector<int>::iterator number2, int inputSum)
{
	return accumulate(number1, number2, inputSum);
}

int InnerProduct(vector<int>::iterator vector1Begin, vector<int>::iterator vector1End,
	vector<int>::iterator vector2Begin, int initial)
{
	int output = inner_product(vector1Begin, vector1End, vector2Begin, initial);
	return output;
}

TEST_CASE("Sine STL function", "[sin]")
{
	SECTION("A correct sine")
	{
		REQUIRE(Sine(3) == 0);
	}

	SECTION("An incorrect sine")
	{
		REQUIRE(Sine(3) == 5);
	}
}

TEST_CASE("Atan2 STL function", "[atan2]")
{
	SECTION("A correct atan2")
	{
		REQUIRE(Atan2(10.0, 20.0) < 24.4);
	}

	SECTION("An incorrect atan2")
	{
		REQUIRE(Atan2(10.0, 20.0) == 24.4);
	}
}

TEST_CASE("Accumulate STL function", "[accumulate]")
{
	SECTION("A correct accumulation")
	{
		REQUIRE(Accumulate(v1.begin(), v1.end(), 0) < 24);
	}

	SECTION("An incorrect accumulation")
	{
		REQUIRE(Accumulate(v1.begin(), v1.end(), 0) == 24);
	}
}

TEST_CASE("Inner Product STL function", "[inner_product]")
{
	SECTION("A correct inner product")
	{
		REQUIRE(InnerProduct(v1.begin(), v1.end(), v2.begin(), 1) >= 6);
	}

	SECTION("An incorrect inner product")
	{
		REQUIRE(InnerProduct(v1.begin(), v1.end(), v2.begin(), 1) == 6);
	}
}