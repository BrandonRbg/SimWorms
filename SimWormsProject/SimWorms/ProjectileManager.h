#pragma once
#include "Singleton.h"
#include "Projectile.h"

class ProjectileManager : public Singleton<ProjectileManager> {
public:
	void addProjectile(Projectile projectile);

	void update();
};