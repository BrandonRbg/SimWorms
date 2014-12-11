#pragma once
#include "Entity.h"
#include "PhysicsComponent.h"

sdl::Vector2Float& Entity::getPosition(){
	return this->sprite.getPosition();
}
sdl::Vector2Float& Entity::getVelocity(){
	return this->velocity;
}
sdl::RectFloat& Entity::getBounds(){
	return this->sprite.getTextureRect();
}
void Entity::setPosition(sdl::Vector2Float& position){
	this->position = position;
	this->sprite.setPosition(position);
}
void Entity::setVelocity(sdl::Vector2Float& velocity){
	this->velocity = velocity;
}
void Entity::addConstraint(sdl::Vector2Float &vector,float frametime) {
	physics->addConstraint(vector, frametime);
}
bool Entity::isPixelSolid(sdl::Vector2Float& position){
	if (position.x > 0 && position.x < sprite.getTextureRect().w && position.y > 0 && position.y < sprite.getTextureRect().h)
		return sprite.getTexture()->getPixel(position).a != 0;
	else
		return false;
}
void Entity::moveLeft(float frametime){
	if (jetpack){
		physics->addConstraint(sdl::Vector2Float(-4, 0), frametime);
		direction = LEFT;
	}
	else{
		if (!physics->cantMove(this)){
			physics->addConstraint(sdl::Vector2Float(-50, 0), frametime);
			direction = LEFT;
		}
	}
}
void Entity::moveRight(float frametime){
	if (jetpack){
		physics->addConstraint(sdl::Vector2Float(4, 0), frametime);
		direction = RIGHT;
	}
	else{
		if (!physics->cantMove(this)){
			physics->addConstraint(sdl::Vector2Float(50, 0), frametime);
			direction = RIGHT;
		}
	}
}
void Entity::jump(float frametime){
	if (!physics->cantMove(this)){
		isOnGround = false;
		if (direction)
			physics->addConstraint(sdl::Vector2Float(20, -80), frametime);
		else
			physics->addConstraint(sdl::Vector2Float(-20, -80), frametime);
	}
}
void Entity::stop(){
	physics->stopMovingX(this);
}
int Entity::getHealth() {
	return this->health;
}
void Entity::setHealth(int heal) {
	this->health = heal;
}