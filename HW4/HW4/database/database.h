#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>

struct MyDatabaseRecord
{
	std::string firstName; 
	std::string lastName;
	std::string city;
	std::string grade;
};

bool CreateRecord(const std::string &key);
bool ReadRecord(const std::string &key, MyDatabaseRecord &record);
bool UpdateRecord(const std::string &key, const MyDatabaseRecord &record); 
bool DeleteRecord(const std::string &key);
bool InputRecord(MyDatabaseRecord &record); 
bool PrintRecord(const std::string & key);

#endif 