#pragma once
#include <random>
#include "Terrain.h"

class Map
{
public:
	Map(std::string& name, std::string& description, int landMinesCount, int maxWindForce, std::string& terrainPath, std::string& bgPath);

	void updateWindForce();


	void update();

	void draw(sdl::Window &target);


	std::string name;
	std::string description;

	int landMinesCount;
	int maxWindForce;

	std::vector<sdl::Vector2Float> landMinesPositions;

	sdl::Vector2Float windForce;

	Terrain terrain;
	sdl::StaticSprite bg;
	sdl::Texture thumbnail;

private:

};

