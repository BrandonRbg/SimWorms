#pragma once
#include <iostream>
#include <cmath>

#include "OOSDL/OOSDL.h"
#include "AssetsManager.h"

class Terrain
{
public:
<<<<<<< HEAD
=======
	Terrain();
	~Terrain();
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011

	void loadTerrainFromFile(std::string filePath);
	void addPixel(sdl::Vector2Float position, sdl::Color color);
	void removePixel(sdl::Vector2Float position);
	sdl::Color getPixel(sdl::Vector2Float position);

	bool isPixelSolid(sdl::Vector2Float position);
	sdl::Vector2Float getNormal(sdl::Vector2Float position);

<<<<<<< HEAD
	int getWidth();
	int getHeight();
=======
	sdl::Vector2Float getSize();
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011

	void explode(sdl::Vector2Float position, float radius, float borderWidth = 0, sdl::Color& borderColor = sdl::Color::Transparent);

	void draw(sdl::Window &target);
private:
	sdl::Texture actualBitMap;
	sdl::Texture originalBitMap;
	sdl::Sprite map;
<<<<<<< HEAD
	int width;
	int height;
=======
	sdl::Vector2Float size;
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011

};
