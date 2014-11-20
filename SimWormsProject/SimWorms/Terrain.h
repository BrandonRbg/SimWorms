#pragma once
#include <iostream>
#include <cmath>

#include "OOSDL/OOSDL.h"
#include "AssetsManager.h"

class Terrain
{
public:
	Terrain();
	~Terrain();

	void loadTerrainFromFile(std::string filePath);
	void addPixel(sdl::Vector2Float position, sdl::Color color);
	void removePixel(sdl::Vector2Float position);
	sdl::Color getPixel(sdl::Vector2Float position);

	bool isPixelSolid(sdl::Vector2Float position);
	sdl::Vector2Float getNormal(sdl::Vector2Float position);

	sdl::Vector2Float getSize();

	void explode(sdl::Vector2Float position, float radius, float borderWidth = 0, sdl::Color& borderColor = sdl::Color::Transparent);

	void draw(sdl::Window &target);
private:
	sdl::Texture actualBitMap;
	sdl::Texture originalBitMap;
	sdl::Sprite map;
	sdl::Vector2Float size;

};
