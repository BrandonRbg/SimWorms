#include "Rocket.h"

Rocket::Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force) {
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/doom_rocket.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	velocity = (orientation * force);
	sprite.setOrigin(0, (0 + (sprite.getBounds().h / 2)));
	std::cout << sprite.getPosition().x << sprite.getPosition().y << std::endl;
	dead = false;
	isLaunched = false;
	this->physics = new ProjectilePhysicsComponents;
}


void Rocket::update(float frametime, Terrain &terrain) {
	if (!isLaunched) {
		physics->addConstraint(velocity, frametime);
		isLaunched = true;
	}
	if (!dead)
		physics->update(this, terrain, frametime);
	if(dead){
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 75);
	}
}

void Rocket::draw(sdl::Window &target) {
	target.draw(&sprite);
}
