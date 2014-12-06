#include "AssetsManager.h"

AssetsManager::~AssetsManager() {

}

void AssetsManager::loadTexture(const std::string& path){
	textures[path].loadFromFile(path);
}

sdl::Texture& AssetsManager::getTexture(const std::string& path){
	if (textures.find(path) == textures.end())
		loadTexture(path);
	return textures[path];
}