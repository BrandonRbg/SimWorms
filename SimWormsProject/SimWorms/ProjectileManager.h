#pragma once
#include "Singleton.h"
#include "Projectile.h"

class ProjectileManager : public Singleton<ProjectileManager> {
private:
	std::list<Projectile*> projectile;
public:
	void addProjectile(Projectile* projectile);

	void update(sdl::Window &window);

	~ProjectileManager();
};