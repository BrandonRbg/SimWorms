#pragma once
#include "Entity.h"
#include <memory>
#include "Singleton.h"

class EntityManager : public Singleton<EntityManager> {
protected:
	std::list<Entity*> entities;
public:
	void addEntity(Entity* entity);
	void clear();

	void update(float frametime, Terrain &terrain, sdl::Window &target, Camera* cam);
	void draw(sdl::Window &target);

	std::list<Entity*> getEntities() { return entities; }

	bool first = true;

	~EntityManager();
};