#pragma once
#include "ScreenState.h"
#include "GameManager.h"

class GameState : public ScreenState
{
public:
	GameState(sdl::Window &target);
	~GameState();
	void update(sdl::Window &target, float frametime);
	void draw(sdl::Window &target);
private:
	Map* actualMap;
	Camera* cam;
	GuiWeaponMenu weaponMenu;
};