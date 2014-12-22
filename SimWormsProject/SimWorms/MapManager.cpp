#include "MapManager.h"
#include <fstream>

MapManager::~MapManager(){
	for (auto& it : maps) {
		delete it;
	}
	maps.clear();
}

void MapManager::loadMapsFromFolder(const std::string& path){
	std::ifstream index(path + "\\index");
	if (index.is_open()){
		while (!index.eof()){
			std::string tmp;
			index >> tmp;
			std::ifstream file(path + "\\" + tmp);
			if (file.is_open()){
				std::string mapName, description, terrainPath, bgPath, thumbPath;
				int landMinesCount, maxWindForce, gravityForce;
				std::getline(file, mapName);
				std::getline(file, description);
				file >> landMinesCount;
				file >> maxWindForce;
				file >> gravityForce;
				std::getline(file, terrainPath);
				std::getline(file, terrainPath);
				std::getline(file, bgPath);
				std::getline(file, thumbPath);
				Map* tmp = new Map(mapName, description, landMinesCount, maxWindForce, gravityForce, terrainPath, bgPath, thumbPath);
				maps.push_back(tmp);
			}
			file.close();
		}
		index.close();
	}
	actualMapIndex = 0;
}

void MapManager::setActualMap(int index){
	actualMapIndex = index;
}

Map* MapManager::getActualMap(){
	return maps[actualMapIndex];
}

Map* MapManager::getMap(int index){
	return maps[index];
}

int MapManager::getMapCount(){
	return maps.size();
}

void MapManager::draw(sdl::Window &target){
	maps[actualMapIndex]->draw(target);
}