#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>

struct MyDatabaseRecord
{
	// replace this with information related to your database 
	std::string objectName{"obj"}; 
	std::string materialName{ "mtl" };
	std::string diffuseColor{ "diff" };
	std::string specularColor{ "spec" };
	bool twoSided{ false };
};

bool CreateRecord(const std::string &key);
bool ReadRecord(const std::string &key, MyDatabaseRecord &record);
bool UpdateRecord(const std::string &key, const MyDatabaseRecord &record); 
bool DeleteRecord(const std::string &key);
bool InputRecord(MyDatabaseRecord &record); 
bool PrintRecord(const std::string & key);

#endif 