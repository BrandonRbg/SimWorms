#include "Projectile.h"

void Projectile::update(float frametime, Terrain &terrain) {
	if (!isLaunched) {
		physics->addConstraint(velocity, frametime);
		isLaunched = true;
	}
	if (!dead)
		physics->update(this, terrain, frametime);
}
