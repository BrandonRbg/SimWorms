#pragma once
#include "GameOptionsManager.h"
class Entity;
class PlayerInputComponent
{
public:
	void update(Entity *player, float frametime);
};

