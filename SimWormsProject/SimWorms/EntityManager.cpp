#include "EntityManager.h"

void EntityManager::addEntity(Entity* entity) {
	entities.push_back(entity);
}

void EntityManager::update(float frametime, Terrain &terrain, sdl::Window &target) {
	entities.remove_if([](Entity* exp){
		bool dead = exp->isDead();
		if (dead) delete exp;
		return dead;
	});
	for (auto& it : entities){
		it->update(frametime, terrain);
		it->draw(target);
	}
}

EntityManager::~EntityManager() {
	for (auto& it : entities) {
		delete it;
	}
	entities.clear();
}