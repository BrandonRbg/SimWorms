#pragma once
#include <iostream>
#include <cmath>

#include "Window.h"
#include "Texture.h"
#include "Sprite.h"
#include "AnimatedSprite.h"
#include "AssetsManager.h"

class Terrain
{
public:
	Terrain();

	void loadTerrainFromFile(std::string filePath);
	void addPixelAtPosition(sdl::Vector2Int position, sdl::Color color);
	void removePixelAtPosition(sdl::Vector2Int position);
	sdl::Color getPixelAtPosition(sdl::Vector2Int position);

	bool isPixelAtPositionSolid(sdl::Vector2Int position);
	sdl::Vector2Float getNormalAtPosition(sdl::Vector2Int position);

	int getWidth();
	int getHeight();

	void explode(sdl::Vector2Int position, float radius);

	void drawTerrain(sdl::Window &target);
private:
	sdl::Texture actualBitMap;
	sdl::Sprite map;
	int width;
	int height;

	int pixelWidth;
};

