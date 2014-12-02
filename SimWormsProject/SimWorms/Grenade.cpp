#include "Grenade.h"
#include "ExplosionsManager.h"

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
	if (clock->getElapsedTime().asSeconds() >= timer){
		ExplosionsManager::getInstance().addExplosion(sprite.getPosition(), terrain, 50);
		dead = true;
	}
	else{
		sdl::Vector2Float terrainNorm = terrain.getNormal(sprite.getPosition());
		if (terrainNorm.x == 0){
			velocity.y = -velocity.y;
		}
		else if (terrainNorm.y == 0){
			velocity.x = -velocity.x;
		}
		else if (terrainNorm.x > 0){
			if (terrainNorm.y > 0){
				velocity = sdl::Vector2Float(-velocity.y, -velocity.x);
			}
			else{
				velocity = sdl::Vector2Float(velocity.y, velocity.x);
			}
		}
		else{
			if (terrainNorm.y > 0){
				velocity = sdl::Vector2Float(velocity.y, velocity.x);
			}
			else{
				velocity = sdl::Vector2Float(-velocity.y, -velocity.x);
			}
		}
	}
}