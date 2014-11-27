#include "Player.h"

Player::Player(sdl::Vector2Float &position){
	this->position = position;
	this->direction = false;
	this->sprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	this->sprite.setPosition(position);
	this->physics = new PlayerPhysicsComponent;
	sprite.setOrigin(sprite.getTextureRect().w / 2, sprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	sprite.setOrigin(0, 0);
}

void Player::draw(sdl::Window &target){
	target.draw(&sprite);
}
void Player::update(float frametime, Terrain& terrain){
	input.update(this, frametime);
	physics->update(this, terrain, frametime);
}
int Player::getHeal() { // Ajout par Nathan
	return this->heal;
}
// true = droite et false = gauche
bool Player::getDirection() {
	return this->direction;
}
void Player::setHeal(int heal) { // Ajout par Nathan
	this->heal = heal;
}
bool Player::isDead(){
	return getHeal() <= 0;
}