#include "Terrain.h"


Terrain::Terrain(){
}


Terrain::~Terrain(){
}

void Terrain::loadTerrainFromFile(std::string filePath){
	actualBitMap = AssetsManager::getInstance().getTexture(filePath);
	size = sdl::Vector2Float(actualBitMap.getSize().x, actualBitMap.getSize().y);
	map.setTexture(&actualBitMap);
}

void Terrain::addPixel(sdl::Vector2Float position, sdl::Color color){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), color);
}

void Terrain::removePixel(sdl::Vector2Float position){
	actualBitMap.setPixel(sdl::Vector2Float(position.x, position.y), sdl::Color(0, 0, 0, 0));
}

bool Terrain::isPixelSolid(sdl::Vector2Float position){
	if (position.x > 0 && position.x < size.x && position.y > 0 && position.y < size.y)
		return actualBitMap.getPixel(sdl::Vector2Float(position.x, position.y)).a != 0;
	else if (position.x < 0 || position.x > size.x || position.y < 0 && position.y > size.y)
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
