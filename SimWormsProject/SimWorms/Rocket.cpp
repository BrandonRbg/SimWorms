#include "Rocket.h"
#include "ExplosionsManager.h"

Rocket::Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force) {
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/doom_rocket.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	velocity = (orientation * force);
	sprite.setOrigin(0, (0 + (sprite.getBounds().h / 2)));
	dead = false;
}

bool Rocket::isDead() {
	return dead;
}

void Rocket::update(float frametime, Terrain &terrain) {
	//physics->update(this, terrain, frametime);
	if (terrain.isPixelSolid(sprite.getPosition())) {
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 75);
		dead = true;
	}
}

void Rocket::draw(sdl::Window &target) {
	target.draw(&sprite);
}