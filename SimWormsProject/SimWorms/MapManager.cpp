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
				maps.emplace_back(mapName, description, landMinesCount, maxWindForce, gravityForce, terrainPath, bgPath, thumbPath);
			}
		}
	}
	actualMapIndex = 0;
}

void MapManager::setActualMap(int index){
	actualMapIndex = index;
}

Map& MapManager::getActualMap(){
	return maps[actualMapIndex];
}

Map& MapManager::getMap(int index){
	return maps[index];
}

int MapManager::getMapCount(){
	return maps.size();
}

void MapManager::update(sdl::Window &target){
	maps[actualMapIndex].update();
	maps[actualMapIndex].draw(target);
}