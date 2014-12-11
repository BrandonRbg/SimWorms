#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <map>
#include "Singleton.h"

class PersonNameGenerator : public Singleton<PersonNameGenerator>
{
public:
	PersonNameGenerator();
	std::string generateFirstName(std::string nationality, std::string sex);
	std::string generateLastName(std::string nationality);
private:
	std::map<std::string, std::vector<std::string>> dataBase;
};

