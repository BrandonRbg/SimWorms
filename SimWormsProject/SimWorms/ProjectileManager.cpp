#include "ProjectileManager.h"
#include "ExplosionsManager.h"

void ProjectileManager::addProjectile(sdl::Vector2Float position, sdl::Vector2Float direction, float puissance) {
	Projectile* projectiletmp = new Projectile(position, direction, puissance);
	projectile.push_back(projectiletmp);
}

void ProjectileManager::update(sdl::Window &window) {
	
}

ProjectileManager::~ProjectileManager() {
	for (auto& it : projectile)
		delete it;
	projectile.clear();
}
