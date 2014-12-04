#include "Explosion.h"
#include "PhysicsComponent.h"


Explosion::Explosion(sdl::Vector2Float &position, Terrain &terrain, float radius){
	delay = 65;
	numberOfFrames = 5;
	explosionSprite = new sdl::AnimatedSprite(&AssetsManager::getInstance().getTexture("data/textures/explosion.png"), numberOfFrames, delay);
	int frameWidth = explosionSprite->getTexture()->getSize().x / numberOfFrames;
	int frameHeight = explosionSprite->getTexture()->getSize().y;
	explosionSprite->setPosition(sdl::Vector2Float(position.x, position.y));
	explosionSprite->setScale(3 * radius / frameWidth, 3 * radius / frameHeight);
	explosionSprite->setOrigin((frameWidth * explosionSprite->getScale().x) / 2, (frameHeight * explosionSprite->getScale().y) / 2);
	terrain.explode(position, radius);
	for (auto& it : EntityManager::getInstance().getEntities()) {
		if ((it->getPosition().x - position.x < radius) && (it->getPosition().y - position.y < radius)) {
			//it->setHealth(it->getHealth() - (radius - (it->getPosition().x - position.x)) * 2);
		}
	}
}
Explosion::~Explosion(){
	delete explosionSprite;
}
void Explosion::update(float frametime, Terrain &terrain) {
	for (auto& it : EntityManager::getInstance().getEntities()) {
		Explosion* tmp = dynamic_cast<Explosion*>(it);
		if (tmp != 0)
			continue;
		if ((it->getPosition().x - explosionSprite->getPosition().x < radius) && (it->getPosition().y - explosionSprite->getPosition().y < radius)) {
			if ((it->getPosition() - explosionSprite->getPosition()) != sdl::Vector2Float(0, 0))
				it->addConstraint(it->getPosition() - explosionSprite->getPosition(), frametime);
		}
	}
}
void Explosion::draw(sdl::Window& target){
	target.draw(explosionSprite);
}
void Explosion::explode(float frametime, Terrain &terrain) {
	
}
bool Explosion::isDead(){
	if (explosionClock.getElapsedTime().asMilliseconds() >= (numberOfFrames * delay))
		return true;
	return false;
}