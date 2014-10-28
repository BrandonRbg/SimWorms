#include "Terrain.h"


Terrain::Terrain()
{
	pixelWidth = 1;
}


void Terrain::loadTerrainFromFile(const std::string filePath){
	actualBitMap = AssetsManager::getInstance().getTexture(filePath);
	width = actualBitMap.getSize().x;
	height = actualBitMap.getSize().y;
	map.setTexture(&actualBitMap);
}

void Terrain::addPixelAtPosition(sdl::Vector2Int position, sdl::Color color){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), color);
}

void Terrain::removePixelAtPosition(sdl::Vector2Int position){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), sdl::Color(0, 0, 0, 0));

}

bool Terrain::isPixelAtPositionSolid(sdl::Vector2Int position){
	if (position.x > 0 && position.x < width && position.y > 0 && position.y < height)
	if (actualBitMap.getPixel(sdl::Vector2Float(position.x, position.y)).a == 0)
		return false;
	return true;
}

void Terrain::drawTerrain(sdl::Window &target){
	target.draw(&map);
}

sdl::Color Terrain::getPixelAtPosition(sdl::Vector2Int position){
	return actualBitMap.getPixel(sdl::Vector2Float(position.x, position.y));
}

sdl::Vector2Float Terrain::getNormalAtPosition(sdl::Vector2Int position){
	float avgX = 0, avgY = 0;
	for (int width = -3; width <= 3; width++) {
		for (int height = -3; height <= 3; height++) {
			if (isPixelAtPositionSolid(sdl::Vector2Int(position.x + width, position.y + height))) {
				avgX -= width;
				avgY -= height;
			}
		}
	}
	float length = sqrt(avgX * avgX + avgY * avgY);
	return sdl::Vector2Float(avgX / length, avgY / length);
}

int Terrain::getHeight(){
	return height;
}

int Terrain::getWidth(){
	return width;
}

void Terrain::explode(sdl::Vector2Int position, float radius){
	float radiusSquare = pow(radius, 2);
	if (position.x < 0 || position.x > width)
		return;
	if (position.y < 0 || position.y > height)
		return;
	for (int x = position.x - (int)radius; x < position.x + (int)radius; x += pixelWidth){
		if (x >= 0 && x < width){
			for (int y = position.y - (int)radius; y < position.y + (int)radius; y += pixelWidth){
				if (y >= 0 && y < height){

					if (isPixelAtPositionSolid(sdl::Vector2Int(x, y))){
						float xOffset = x - position.x;
						float yOffset = y - position.y;
						float distanceSquare = pow(xOffset, 2) + pow(yOffset, 2);
						if (distanceSquare <= radiusSquare){
							float distance = sqrt(distanceSquare);

							if (distance == 0)
								distance = 0.001;

							for (int i = 0; i < pixelWidth; i++) {
								for (int j = 0; j < pixelWidth; j++) {
									if (distance >= radius - 2)
										addPixelAtPosition(sdl::Vector2Int(x, y), sdl::Color(0, 0, 0));
									else
										removePixelAtPosition(sdl::Vector2Int(x, y));
								}
							}
						}

					}
				}
			}
		}
		map.setTexture(&actualBitMap);
	}

}
