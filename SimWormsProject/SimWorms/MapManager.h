#pragma once
#include "Singleton.h"
#include "Map.h"
class MapManager : public Singleton<MapManager>
{
public:

	~MapManager();
	void loadMapsFromFolder(const std::string& path);

	void setActualMap(int index);
	Map* getActualMap();

	Map* getMap(int index);
	int getMapCount();

	void draw(sdl::Window& target);
private:
	int actualMapIndex;
	std::vector<Map*> maps;
};

