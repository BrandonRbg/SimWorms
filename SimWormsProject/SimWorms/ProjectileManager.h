#pragma once
#include "Singleton.h"
#include "Projectile.h"

class ProjectileManager : public Singleton<ProjectileManager> {
private:
	std::list<Projectile*> projectile;
public:
	void addProjectile(sdl::Vector2Float position);

	void update(sdl::Window& window);
};