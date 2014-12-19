#include "personnamegenerator.h"


PersonNameGenerator::PersonNameGenerator()
{
	srand(time(NULL));
	std::ifstream openFile;
	std::vector<std::string> files;

	files.push_back("frenchLastNames");
	files.push_back("englishLastNames");
	files.push_back("spanishLastNames");
	files.push_back("chineseLastNames");

	files.push_back("frenchMFirstNames");
	files.push_back("frenchFFirstNames");

	files.push_back("englishMFirstNames");
	files.push_back("englishFFirstNames");

	files.push_back("spanishMFirstNames");
	files.push_back("spanishFFirstNames");

	for (int i = 0; i < files.size(); ++i){
		openFile.open("names/" + files[i] + ".txt");
		if (openFile.is_open()){
			std::vector<std::string> names;
			while (!openFile.eof())	{
				std::string tmp;
				std::getline(openFile, tmp);
				names.push_back(tmp);
			}
			dataBase.insert(std::pair<std::string, std::vector<std::string>>(files[i], names));
		}
		openFile.close();
	}
}

std::string PersonNameGenerator::generateFirstName(std::string nationality, std::string sex){
	if (dataBase[nationality + sex + "FirstNames"].size() == 0)
		return "";
	int randomNumber = rand() % dataBase[nationality + sex + "FirstNames"].size();
	return dataBase[nationality + sex + "FirstNames"][randomNumber];
}
std::string PersonNameGenerator::generateLastName(std::string nationality){
	if (dataBase[nationality + "LastNames"].size() == 0)
		return "";
	int randomNumber = rand() % dataBase[nationality + "LastNames"].size();
	return dataBase[nationality + "LastNames"][randomNumber];

}
