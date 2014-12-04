#include "Grenade.h"

Grenade::Grenade(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force, double timer) {
	this->clock = new sdl::Clock();
	this->timer = timer;
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	sprite.setPosition(sdl::Vector2Float(startingPosition.x, startingPosition.y));
	sprite.setOrigin(sdl::Vector2Float(sprite.getBounds().w / 2, sprite.getBounds().h / 2));
	velocity = (orientation * force);
	dead = false;
	this->physics = new ProjectilePhysicsComponents;
}
Grenade::~Grenade(){
	delete clock;
}


void Grenade::draw(sdl::Window &target) {
	target.draw(&sprite);
}

void Grenade::explode(float frametime, Terrain &terrain){
		velocity = physics->getResultingVector() * (1/frametime);
		physics->stopMovingX(this);
		physics->stopMovingY(this);

		sdl::Vector2Float terrainNorm = terrain.getNormal(sprite.getPosition());
		terrainNorm.x = -terrainNorm.x;
		terrainNorm.y = -terrainNorm.y;
		velocity = velocity - terrainNorm * (2 * (velocity.x * terrainNorm.x + velocity.y * terrainNorm.y));
		physics->addConstraint(velocity * 0.5, frametime);
}
void Grenade::isTimedOut(Terrain &terrain) {
	if (clock->getElapsedTime().asSeconds() >= timer){
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 30);
		dead = true;
	}
}