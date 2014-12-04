#pragma once
#include "Singleton.h"
#include "Map.h"
class MapManager : public Singleton<MapManager>
{
public:
	void loadMapsFromFolder(const std::string& path);

	void setActualMap(int index);
	Map& getActualMap();

	Map& getMap(int index);
	int getMapCount();

	void update(sdl::Window& target);
private:
	int actualMapIndex;
	std::vector<Map> maps;
};

