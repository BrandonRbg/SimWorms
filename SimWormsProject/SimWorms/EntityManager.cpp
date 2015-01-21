#include "EntityManager.h"

void EntityManager::addEntity(Entity* entity) {
	entities.push_back(entity);
}

void EntityManager::clear(){
	for (auto& it : entities) {
		delete it;
		it = nullptr;
	}
	entities.clear();
}

void EntityManager::update(float frametime, Terrain &terrain, sdl::Window &target, Camera* cam) {
	entities.remove_if([](Entity* exp){
		bool dead = exp->isDead();
		if (dead) delete exp;
		exp = nullptr;
		return dead;
	});
	for (auto& it : entities){
		it->update(frametime, terrain, cam);
	}
}

void EntityManager::draw(sdl::Window &target){
	for (auto& it : entities){
		it->draw(target);
	}
}

EntityManager::~EntityManager() {
	for (auto& it : entities) {
		delete it;
	}
	entities.clear();
}