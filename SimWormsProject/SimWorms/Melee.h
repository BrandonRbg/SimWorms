#pragma once
#include <SDL2\SDL.h>
#include "Player.h"

class Melee {
protected:
	SDL_Rect MeleeHitBox;

public:
	Melee(float x, float y, float h, float w) {
		MeleeHitBox.x = x;
		MeleeHitBox.y = y;
		MeleeHitBox.h = h;
		MeleeHitBox.w = w;
	}

	bool isPlayerTouch(Player Cible);

	SDL_Rect GetMeleeHitbox(void){ return MeleeHitBox; }
};