#include "PhysicsComponent.h"

PhysicsComponent::PhysicsComponent(){
	resultingVector = sdl::Vector2Float(0, 0);
}


PhysicsComponent::~PhysicsComponent(){
}

void PhysicsComponent::addConstraint(sdl::Vector2Float &vector){
	resultingVector += vector;
}
