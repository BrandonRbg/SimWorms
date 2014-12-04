#pragma once
#include "Singleton.h"
#include "Map.h"
class MapManager : public Singleton<MapManager>
{
public:
	void loadMapsFromFolder(const std::string& path);

	Map& getMap(int index);
	int getMapCount();
private:
	std::vector<Map> maps;
};

