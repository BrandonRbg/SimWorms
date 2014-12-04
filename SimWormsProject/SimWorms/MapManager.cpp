#include "MapManager.h"
#include <fstream>

void MapManager::loadMapsFromFolder(const std::string& path){
	std::ifstream index(path + "\\index");
	if (index.is_open()){
		while (!index.eof()){
			std::string tmp;
			index >> tmp;
			std::ifstream file(path + "\\" + tmp);
			if (file.is_open()){
				std::string mapName, description, terrainPath, bgPath;
				int landMinesCount, maxWindForce;
				std::getline(file, mapName);
				std::getline(file, description);
				file >> landMinesCount;
				file >> maxWindForce;
				std::getline(file, terrainPath);
				std::getline(file, terrainPath);
				std::getline(file, bgPath);
				Map map(mapName, description, landMinesCount, maxWindForce, terrainPath, bgPath);
				maps.push_back(map);
			}
		}
	}
}

Map& MapManager::getMap(int index){
	return maps[index];
}

int MapManager::getMapCount(){
	return maps.size();
}