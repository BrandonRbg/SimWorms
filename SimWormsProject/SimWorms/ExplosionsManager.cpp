#include "ExplosionsManager.h"


ExplosionsManager::~ExplosionsManager()
{
	for (auto& it : explosions)
		delete it;
	explosions.clear();
}

void ExplosionsManager::addExplosion(sdl::Vector2Float position, Terrain &terrain, float radius){
	Explosion* tmp = new Explosion(position, radius * 3);
	terrain.explode(position, radius, 2, sdl::Color::Black);
	explosions.push_back(tmp);
}
void ExplosionsManager::update(sdl::Window &target){
	explosions.remove_if([](Explosion* exp){
		bool ended = exp->isEnded();
		if (ended) delete exp;
		return ended;
	});
	for (auto& it : explosions){
			it->draw(target);
	}
}