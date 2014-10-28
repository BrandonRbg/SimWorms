#pragma once
#include <list>

#include "Vector2.h"
#include "Player.h"
class PlayerPhysicsComponent
{
public:
	void addConstraint(sdl::Vector2Float &constraint);
	void update(Player &player);
private:
	std::list<sdl::Vector2Float> constraints;
};

