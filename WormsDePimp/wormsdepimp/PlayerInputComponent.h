#pragma once
#include "Keyboard.h"
#include "InputComponent.h"


class PlayerInputComponent : public InputComponent
{
public:
	void update(Player &player);
};

