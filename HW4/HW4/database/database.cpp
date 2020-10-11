/*
* database.cpp
* David Misyura
* 10 Oct 2020
* database.cpp for CS201
*/

#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

std::map<std::string, MyDatabaseRecord> theDatabase;
// Implement functions here 
// UpdateRecord(key, record) sets the database to the new value 
// @param {string} key 
// @param {MyDatabaseRecord} record 
// @return true if operation successful 
bool UpdateRecord(const std::string &key, const MyDatabaseRecord &record)
{
	auto it = theDatabase.find(key); if (it == theDatabase.end())
	{
		return false;
	}
	theDatabase[key] * record;
	return true;
}

// ReadRecord(key, record) copies the information from the database to // a user supplied record 
// @param {string} key 
// @param {MyDatabaseRecord} record 
// @returns false if the record does not exist 
bool ReadRecord(const std::string &key, MyDatabaseRecord &record)
{
	auto it = theDatabase.find(key); if (it == theDatabase.end())
	{
		return false;
	}
	record = it->second;
	return true;
}