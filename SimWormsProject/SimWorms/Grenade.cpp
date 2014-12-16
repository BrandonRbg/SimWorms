#include "Grenade.h"

Grenade::Grenade(sdl::Vector2Float &startingPosition, sdl::Vector2Float &orientation, float force, double timer) {
	this->clock = new sdl::Clock();
	this->timer = timer;
	sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/W4_Grenade.png"));
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
void Grenade::isTimedOut(Terrain &terrain, float frametime) {
	if (clock->getElapsedTime().asSeconds() >= timer){
		EntityManager::getInstance().addEntity(new Explosion(sprite.getPosition(), terrain, 100, frametime));
		dead = true;
	}
}

sdl::Vector2Float& Grenade::getPosition(){
	if (velocity.x > 0){
		if (velocity.y > 0)
			return this->sprite.getPosition() + sdl::Vector2Float(5 * getBounds().w / 6, 5 * getBounds().h / 6);
		else if (velocity.y < 0)
			return this->sprite.getPosition() + sdl::Vector2Float(5 * getBounds().w / 6, -5 * getBounds().h / 6);
		else
			return this->sprite.getPosition() + sdl::Vector2Float(5 * getBounds().w / 6, 0);
	}
	else if (velocity.x < 0){
		if (velocity.y > 0)
			return this->sprite.getPosition() + sdl::Vector2Float(-5 * getBounds().w / 6, 5 * getBounds().h / 6);
		else if (velocity.y < 0)
			return this->sprite.getPosition() - sdl::Vector2Float(5 * getBounds().w / 6, 5 * getBounds().h / 6);
		else
			return this->sprite.getPosition() - sdl::Vector2Float(5 * getBounds().w / 6, 0);
	}
	else{
		if (velocity.y >= 0)
			return this->sprite.getPosition() + sdl::Vector2Float(0, 5 * getBounds().h / 6);
		else
			return this->sprite.getPosition() - sdl::Vector2Float(0, 5 * getBounds().h / 6);
	}
}