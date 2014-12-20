#pragma once
#include <SDL2\SDL.h>
#include "Player.h"
#include "Entity.h"

class Melee {
protected:
	SDL_Rect MeleeHitBox;

public:
	Melee(sdl::Vector2Float position) {
		MeleeHitBox.x = position.x;
		MeleeHitBox.y = position.y;
		MeleeHitBox.w = 50;
		MeleeHitBox.h = 8;
	}

	bool checkPlayerTouch(Player* cible, float frametime);

	SDL_Rect GetMeleeHitbox(void){ return MeleeHitBox; }
};