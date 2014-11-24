#include "Player.h"

Player::Player(sdl::Vector2Float &position){
	this->position = position;
	this->direction = false;
	this->playerSprite.setTexture(&AssetsManager::getInstance().getTexture("data/textures/player.png"));
	this->playerSprite.setPosition(position);
	playerSprite.setOrigin(playerSprite.getTextureRect().w / 2, playerSprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	playerSprite.setOrigin(0, 0);
}

void Player::moveLeft(float frametime){
	if (!physics.canMove(*this)){
		physics.addConstraint(sdl::Vector2Float(-50, 0) * frametime);
		direction = false;
	}
}
void Player::moveRight(float frametime){
	if (!physics.canMove(*this)){
		physics.addConstraint(sdl::Vector2Float(50, 0) * frametime);
		direction = true;
	}
}
void Player::stop(){
	physics.stopMovingX(*this);
}

void Player::draw(sdl::Window &target){
	target.draw(&playerSprite);
}
void Player::update(float frametime, Terrain& terrain){
	input.update(*this, frametime);
	physics.update(*this, terrain, frametime);
}
sdl::Vector2Float& Player::getPosition(){
	return this->playerSprite.getPosition();
}
sdl::Vector2Float& Player::getVelocity(){
	return this->velocity;
}
sdl::RectFloat& Player::getBounds(){
	return playerSprite.getTextureRect();
}
int Player::getHeal() { // Ajout par Nathan
	return this->heal;
}
bool Player::getDirection() {
	return this->direction;
}
void Player::setHeal(int heal) { // Ajout par Nathan
	this->heal = heal;
}
void Player::setPosition(sdl::Vector2Float& position){
	this->playerSprite.setPosition(position);
}
void Player::setVelocity(sdl::Vector2Float& velocity){
	this->velocity = velocity;
}
bool Player::isPixelSolid(sdl::Vector2Float& position){
	if (position.x > 0 && position.x < playerSprite.getTextureRect().w && position.y > 0 && position.y < playerSprite.getTextureRect().h)
		return playerSprite.getTexture()->getPixel(position).a != 0;
	else
		return false;
}
