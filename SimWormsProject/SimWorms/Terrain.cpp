#include "Terrain.h"

<<<<<<< HEAD
void Terrain::loadTerrainFromFile(std::string filePath){
	originalBitMap = AssetsManager::getInstance().getTexture(filePath);
	actualBitMap = originalBitMap;
	width = originalBitMap.getSize().x;
	height = originalBitMap.getSize().y;
=======

Terrain::Terrain(){
}


Terrain::~Terrain(){
}

void Terrain::loadTerrainFromFile(std::string filePath){
	originalBitMap = AssetsManager::getInstance().getTexture(filePath);
	actualBitMap = originalBitMap;
	size = sdl::Vector2Float(originalBitMap.getSize().x, originalBitMap.getSize().y);
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
	map.setTexture(&actualBitMap);
}

void Terrain::addPixel(sdl::Vector2Float position, sdl::Color color){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), color);
}

void Terrain::removePixel(sdl::Vector2Float position){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), sdl::Color(0, 0, 0, 0));
}

bool Terrain::isPixelSolid(sdl::Vector2Float position){
<<<<<<< HEAD
	if (position.x > 0 && position.x < width && position.y > 0 && position.y < height)
=======
	if (position.x > 0 && position.x < size.x && position.y > 0 && position.y < size.y)
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
		return actualBitMap.getPixel(sdl::Vector2Float(position.x, position.y)).a != 0;
	else if (position.x < 0 || position.x < size.x)
		return true;
	else return false;
}

void Terrain::draw(sdl::Window &target){
	target.draw(&map);
}

sdl::Color Terrain::getPixel(sdl::Vector2Float position){
	return actualBitMap.getPixel(sdl::Vector2Float(position.x, position.y));
}

sdl::Vector2Float Terrain::getNormal(sdl::Vector2Float position){
	float avgX = 0, avgY = 0;
	for (int width = -3; width <= 3; width++) {
		for (int height = -3; height <= 3; height++) {
			if (isPixelSolid(sdl::Vector2Float(position.x + width, position.y + height))) {
				avgX -= width;
				avgY -= height;
			}
		}
	}
	float length = sqrt(avgX * avgX + avgY * avgY);
	return sdl::Vector2Float(avgX / length, avgY / length);
}

<<<<<<< HEAD
int Terrain::getHeight(){
	return height;
}

int Terrain::getWidth(){
	return width;
}

void Terrain::explode(sdl::Vector2Float position, float radius, float borderWidth, sdl::Color& borderColor){
	if (position.x < 0 || position.x > width)
		return;
	if (position.y < 0 || position.y > height)
		return;
	for (int x = position.x - (int)radius; x < position.x + (int)radius; ++x){
		if (!(x >= 0 && x < width))
			continue;
		for (int y = position.y - (int)radius; y < position.y + (int)radius; ++y){
			if (!(y >= 0 && y < height))
=======
sdl::Vector2Float Terrain::getSize(){
	return size;
}

void Terrain::explode(sdl::Vector2Float position, float radius, float borderWidth, sdl::Color& borderColor){
	if (position.x < 0 || position.x > size.x)
		return;
	if (position.y < 0 || position.y > size.y)
		return;
	for (int x = position.x - (int)radius; x < position.x + (int)radius; ++x){
		if (!(x >= 0 && x < size.x))
			continue;
		for (int y = position.y - (int)radius; y < position.y + (int)radius; ++y){
			if (!(y >= 0 && y < size.y))
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
				continue;
			if (isPixelSolid(sdl::Vector2Float(x, y))){
				sdl::Vector2Float offSet(x - position.x, y - position.y);
				float offSetModule = offSet.getModule();
				if (offSetModule <= radius){
					if (offSetModule >= radius - borderWidth)
						addPixel(sdl::Vector2Float(x, y), borderColor);
					else
						removePixel(sdl::Vector2Float(x, y));
				}
			}
		}
		map.setTexture(&actualBitMap);
	}

}
