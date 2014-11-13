#pragma once
#include "Singleton.h"
#include <map>

#include "OOSDL/OOSDL.h"

class AssetsManager : public Singleton<AssetsManager>
{
public:
	void loadTexture(const std::string& path);
	sdl::Texture& getTexture(const std::string& path);

private:
	std::map<std::string, sdl::Texture> textures;
};

