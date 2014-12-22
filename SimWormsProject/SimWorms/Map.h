#pragma once
#include <random>
#include "Terrain.h"

class Map
{
public:
	
	Map(const std::string& name, const std::string& description, int landMinesCount, int maxWindForce, int gravityForce, const std::string& terrainPath, const std::string& bgPath, const std::string& thumbnailPath);
	Map() : Map("", "", 0, 0, 0, "", "", ""){};
	void updateWindForce();

	void update();

	void draw(sdl::Window &target);

	sdl::RectFloat getBounds();

	std::string name;
	std::string description;

	int landMinesCount;
	int maxWindForce;
	int gravityForce;

	std::vector<sdl::Vector2Float> landMinesPositions;

	sdl::Vector2Float windForce;

	Terrain terrain;
	sdl::StaticSprite bg;
	sdl::StaticSprite thumbnail;

private:

};

