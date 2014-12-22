#include "Projectile.h"

void Projectile::update(float frametime, Terrain& terrain, Camera* cam) {
	if (!isLaunched) {
		physics->addFConstraint(velocity);
		isLaunched = true;
	}
	this->isTimedOut(terrain, frametime);
	if (!dead)
		physics->update(this, terrain, frametime);
}
