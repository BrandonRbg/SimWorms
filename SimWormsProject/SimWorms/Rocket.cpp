#include "Rocket.h"
#include "ExplosionsManager.h"

Rocket::Rocket(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force) {
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/doom_rocket.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	velocity = (orientation * force);
	sprite.setOrigin(0, (0 + (sprite.getBounds().h / 2)));
	std::cout << sprite.getPosition().x << sprite.getPosition().y << std::endl;
	dead = false;
}

bool Rocket::isDead() {
	return dead;
}

void Rocket::update(float frametime, Terrain &terrain) {
	physics.update(this, frametime, terrain);
	if (terrain.isPixelSolid(sprite.getPosition())) {
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 75);
		dead = true;
	}

	if (sdl::Keyboard::isKeyPressed(SDLK_0))
		sprite.rotate(2);
	if (sdl::Keyboard::isKeyPressed(SDLK_9))
		sprite.rotate(-2);
	if (sdl::Keyboard::isKeyPressed(SDLK_LEFT))
		sprite.move(-50 * frametime, 0);
	if (sdl::Keyboard::isKeyPressed(SDLK_RIGHT))
		sprite.move(50 * frametime, 0);
}

void Rocket::draw(sdl::Window &target) {
	target.draw(&sprite);
}