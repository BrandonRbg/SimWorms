#include "Rocket.h"

Rocket::Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force) {
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/Bullet_bill.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	sprite.setOrigin(startingPosition.x, (startingPosition.y + (sprite.getBounds().h / 2)));
	dead = false;
}

bool Rocket::isDead() {
	return dead;
}

void Rocket::update(float frametime, Terrain &terrain) {

}

void Rocket::draw(sdl::Window &target) {
	target.draw(&sprite);
}