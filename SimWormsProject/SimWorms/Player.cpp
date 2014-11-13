#include "Player.h"

Player::Player(sdl::Vector2Float &position){
	this->position = position;

	this->playerSprite.setTexture(&AssetsManager::getInstance().getTexture("player.png"));
	this->playerSprite.setPosition(position);
	playerSprite.setOrigin(playerSprite.getTextureRect().w / 2, playerSprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	playerSprite.setOrigin(0, 0);
}

void Player::moveLeft(){
	if (!isMovingX){
		if (physics.isInMidAir()){
			physics.stopMovingX(*this);
			return;
		}
		physics.addConstraint(sdl::Vector2Float(-5, 0));
		isMovingX = true;
	}
}
void Player::moveRight(){
	if (!isMovingX){
		if (physics.isInMidAir()){
			physics.stopMovingX(*this);
			return;
		}
		physics.addConstraint(sdl::Vector2Float(5, 0));
		isMovingX = true;
	}
}
void Player::stop(){
	physics.stopMovingX(*this);
	isMovingX = false;

}

void Player::draw(sdl::Window &target){
	target.draw(&playerSprite);
}

void Player::update(float frametime, Terrain& terrain){
	input.update(*this);
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
void Player::setPosition(sdl::Vector2Float& position){
	this->playerSprite.setPosition(position);
}
void Player::setVelocity(sdl::Vector2Float& velocity){
	this->velocity = velocity;
}
