#include "AssetsManager.h"


void AssetsManager::loadTexture(const std::string& path){
	sdl::Texture tmpTexture;
	tmpTexture.loadFromFile(path);
	textures[path] = tmpTexture;
}

sdl::Texture& AssetsManager::getTexture(const std::string& path){
	if (textures.find(path) == textures.end())
		textures[path].loadFromFile(path);
	return textures[path];
}