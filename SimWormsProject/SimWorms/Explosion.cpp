#include "Explosion.h"
#include "PhysicsComponent.h"
#include "GameManager.h"

Explosion::Explosion(sdl::Vector2Float &position, Terrain &terrain, float radius, float frametime){
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
		if ((abs(it->getPosition().x - explosionSprite->getPosition().x) < radius) && (abs(it->getPosition().y - explosionSprite->getPosition().y) < radius)) {
			it->setHealth(it->getHealth() - (radius - (it->getPosition().x - position.x)) * 2);
			Explosion* tmp = dynamic_cast<Explosion*>(it);
			if (tmp != 0)
				continue;
			if ((abs(it->getPosition().x - explosionSprite->getPosition().x) < radius) && (abs(it->getPosition().y - explosionSprite->getPosition().y) < radius)) {
				if ((it->getPosition() - explosionSprite->getPosition()) != sdl::Vector2Float(0, 0)){
					sdl::Vector2Float distance = it->getPosition() - explosionSprite->getPosition();
					float speed = 10 * (1 - (distance.getModule() / radius));
					it->addConstraint(distance * speed , frametime);
				}
			}
		}
	}
}
Explosion::~Explosion(){
	delete explosionSprite;
}
void Explosion::update(float frametime, Terrain &terrain) {
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