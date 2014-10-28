#include "ExplosionsManager.h"


ExplosionsManager::~ExplosionsManager()
{
	for (auto& it : explosions)
		delete it;
	explosions.clear();
}

void ExplosionsManager::addExplosion(sdl::Vector2Int position, float radius){
	Explosion* tmp = new Explosion(position, radius);
	explosions.push_back(tmp);
}
void ExplosionsManager::update(sdl::Window &target){
	explosions.remove_if([](Explosion* exp){
		bool ended = exp->isEnded();
		if (ended) delete exp;
		return ended;
	});
	std::list<Explosion*>::iterator it;
	for (it = explosions.begin(); it != explosions.end(); it++){
			(*it)->draw(target);
	}
}