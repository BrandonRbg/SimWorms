#include "Grenade.h"
#include "ExplosionsManager.h"

Grenade::Grenade(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force, double timer) {
	this->clock = new sdl::Clock();
	clock->getElapsedTime().setTime(timer);
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/W4_Grenade.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	velocity = (orientation * force);
	dead = false;
}

bool Grenade::isDead() {
	return dead;
}

void Grenade::update(float frametime, Terrain &terrain) {
	if (clock->getElapsedTime().asSeconds() == 0) {
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 50);
		delete clock;
		dead = true;
	}
}

void Grenade::draw(sdl::Window &target) {
	target.draw(&sprite);
}