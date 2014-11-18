#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(){
	resultingVector = sdl::Vector2Float(0, 0);
}

void PhysicsComponent::addConstraint(sdl::Vector2Float &vector){
	resultingVector += vector;
}
void PhysicsComponent::update(Terrain &terrain){}
void PhysicsComponent::checkCollision(Terrain &terrain){}
