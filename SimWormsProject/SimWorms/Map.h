#pragma once
#include <fstream>
#include <random>

#include "Terrain.h"


class Map
{
public:
	Map();

	void loadFromFile(std::string& path);

	void updateWindForce();
	sdl::Vector2Float& getWindForce;

	std::string& getName();
	sdl::Texture& getThumbnail();

	Terrain& getTerrain();

private:
	std::string name;
	
	int landMinesCount;
	int maxWindForce;

	std::vector<sdl::Vector2Float> landMinesPositions;

	sdl::Vector2Float windForce;

	Terrain terrain;
	sdl::StaticSprite bg;
	sdl::Texture thumbnail;
};

