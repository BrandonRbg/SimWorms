#include "Explosion.h"


Explosion::Explosion(sdl::Vector2Float &position, float radius){
	delay = 65;
	numberOfFrames = 5;
	explosionSprite = new sdl::AnimatedSprite(&AssetsManager::getInstance().getTexture("data/textures/explosion.png"), numberOfFrames, delay);
	int frameWidth = explosionSprite->getTexture()->getSize().x / numberOfFrames;
	int frameHeight = explosionSprite->getTexture()->getSize().y;
	explosionSprite->setPosition(sdl::Vector2Float(position.x, position.y));
	explosionSprite->setScale(radius / frameWidth, radius / frameHeight);
	explosionSprite->setOrigin((frameWidth * explosionSprite->getScale().x) / 2, (frameHeight * explosionSprite->getScale().y) / 2);
}
Explosion::~Explosion(){
	delete explosionSprite;
}
void Explosion::draw(sdl::Window& target){
	target.draw(explosionSprite);
}
bool Explosion::isEnded(){
	if (explosionClock.getElapsedTime().asMilliseconds() >= (numberOfFrames * delay))
		return true;
	return false;
}