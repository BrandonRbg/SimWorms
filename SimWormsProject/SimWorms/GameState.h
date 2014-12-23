#pragma once
#include "ScreenState.h"
#include "GameManager.h"
#include "Compass.h"

class GameState : public ScreenState
{
public:
	GameState(sdl::Window &target, std::vector<Team> teams);
	~GameState();
	void update(sdl::Window &target, float frametime);
	void draw(sdl::Window &target);

	void onKeyPressed(SDL_Event event);
private:
	Camera* cam;
	GuiWeaponMenu weaponMenu;
	Compass compass;
};