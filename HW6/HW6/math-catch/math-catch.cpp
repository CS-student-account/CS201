#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include <cmath>
using std::sin;

unsigned int Factorial(unsigned int number) 
{
	return number <= 1 ? number : Factorial(number - 1)*number;
}

unsigned int Sine(unsigned int number)
{
	int x = number;
	return sin(x);
}

TEST_CASE("Factorials are computed", "[factorial]") 
{
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
	REQUIRE(Sine(3) == 35);
}