#include "Player.h"

Player::Player(sdl::Vector2Float &position){
	this->position = position;
<<<<<<< HEAD
	this->heal = 100;
=======

>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
	this->playerSprite.setTexture(&AssetsManager::getInstance().getTexture("player.png"));
	this->playerSprite.setPosition(position);
	playerSprite.setOrigin(playerSprite.getTextureRect().w / 2, playerSprite.getTextureRect().h / 2);
	velocity = sdl::Vector2Float(0, 0);
	playerSprite.setOrigin(0, 0);
}

void Player::moveLeft(){
	if (!isMovingX){
<<<<<<< HEAD
		if (physics.isInMidAir()){
=======
		if (physics.isInMidAir(*this)){
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
			physics.stopMovingX(*this);
			return;
		}
		physics.addConstraint(sdl::Vector2Float(-5, 0));
		isMovingX = true;
	}
}
void Player::moveRight(){
	if (!isMovingX){
<<<<<<< HEAD
		if (physics.isInMidAir()){
=======
		if (physics.isInMidAir(*this)){
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
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
<<<<<<< HEAD
int Player::getHeal(){
	return this->heal;
}
=======
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
void Player::setPosition(sdl::Vector2Float& position){
	this->playerSprite.setPosition(position);
}
void Player::setVelocity(sdl::Vector2Float& velocity){
	this->velocity = velocity;
}
<<<<<<< HEAD
void Player::setHeal(int heal) {
	this->heal = heal;
=======
bool Player::isPixelSolid(sdl::Vector2Float& position){
	if (position.x >= 0 && position.x <= playerSprite.getTextureRect().w && position.y >= 0 && position.y <= playerSprite.getTextureRect().h)
		return playerSprite.getTexture()->getPixel(position).a != 0;
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
}
