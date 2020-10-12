/*
* database.cpp
* David Misyura
* 11 Oct 2020
* database.cpp for CS201
*/

#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::vector;
using std::istringstream;
using std::map;

map<string, MyDatabaseRecord> database;

/*bool CreateRecord(const string &key)
{
	string database = key;
	map<string, MyDatabaseRecord> database;
	return 0;
}*/

// Implement functions here 
// UpdateRecord(key, record) sets the database to the new value 
// @param {string} key 
// @param {MyDatabaseRecord} record 
// @return true if operation successful 
bool UpdateRecord(const string &key, const MyDatabaseRecord &record)
{
	auto it = database.find(key); 
	if (it == database.end())
	{
		return false;
	}
	database[key] = record;
	return true;
}

// ReadRecord(key, record) copies the information from the database to // a user supplied record 
// @param {string} key 
// @param {MyDatabaseRecord} record 
// @returns false if the record does not exist 
bool ReadRecord(const string &key, MyDatabaseRecord &record)
{
	auto it = database.find(key); 
	if (it == database.end())
	{
		return false;
	}
	record = it->second;
	return true;
}

bool DeleteRecord(const string &key)
{
	return 0;
}

bool InputRecord(MyDatabaseRecord &record)
{
	
	return 0;
}

bool PrintRecord(const std::string & key)
{
	return 0;
}