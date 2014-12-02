#include "PhysicsComponent.h"
#include "Entity.h"
PhysicsComponent::PhysicsComponent(){
	resultingVector = sdl::Vector2Float(0, 0);
}

void PhysicsComponent::addConstraint(sdl::Vector2Float &vector, float frametime){
		resultingVector += vector * frametime;
}