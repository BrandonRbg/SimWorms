#include "Map.h"


Map::Map(std::string& name, std::string& description, int landMinesCount, int maxWindForce, std::string& terrainPath, std::string& bgPath){
	this->name = name;
	this->description = description;
	this->landMinesCount = landMinesCount;
	this->maxWindForce = maxWindForce;
	this->terrain.loadTerrainFromFile(terrainPath);
	this->bg.setTexture(&AssetsManager::getInstance().getTexture(bgPath));
	updateWindForce();
	std::default_random_engine engine;
	std::uniform_int_distribution<int> dist(50, terrain.getSize().x - 50);
	for (int i = 0; i < landMinesCount; i++)
		landMinesPositions.push_back(sdl::Vector2Float(dist(engine), dist(engine)));
}

void Map::updateWindForce(){
	std::default_random_engine engine;
	std::uniform_int_distribution<int> dist(-maxWindForce, maxWindForce);
	windForce.x = dist(engine);
	windForce.y = dist(engine);
}

void Map::update(){

}

void Map::draw(sdl::Window &target){
	target.draw(&bg);
	terrain.draw(target);
}