#include "ProjectileManager.h"

void ProjectileManager::addProjectile(Projectile* projectile){
	this->projectile.push_back(projectile);
}

void ProjectileManager::update(sdl::Window &window) {
	
}

ProjectileManager::~ProjectileManager() {
	for (auto& it : projectile)
		delete it;
	projectile.clear();
}
