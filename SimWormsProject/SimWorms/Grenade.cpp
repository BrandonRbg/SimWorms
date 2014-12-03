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
// * 100 là uniquement pour tester plus facilement.
void Grenade::explode(float frametime, Terrain &terrain){
		velocity = physics->getResultingVector();
		physics->stopMovingX(this);
		physics->stopMovingY(this);

		sdl::Vector2Float terrainNorm = terrain.getNormal(sprite.getPosition());
		if (terrainNorm.x == 0){
			velocity.y = 100 * -velocity.y;
		}
		else if (terrainNorm.y == 0){
			velocity.x = 100 * -velocity.x;
		}
		else if (terrainNorm.x > 0){
			if (terrainNorm.y > 0){
				velocity = sdl::Vector2Float(-velocity.y, -velocity.x) * 100;
			}
			else{
				velocity = sdl::Vector2Float(velocity.y, velocity.x) * 100;
			}
		}
		else{
			if (terrainNorm.y > 0){
				velocity = sdl::Vector2Float(velocity.y, velocity.x) * 100;
			}
			else{
				velocity = sdl::Vector2Float(-velocity.y, -velocity.x) * 100;
			}
		}
		physics->addConstraint(velocity, frametime);
}
void Grenade::isTimedOut(Terrain &terrain) {
	if (clock->getElapsedTime().asSeconds() >= timer){
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 50);
		dead = true;
	}

}