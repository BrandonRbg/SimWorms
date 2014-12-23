#pragma once
#include "Singleton.h"
#include <sstream>
#include <time.h>

#include "OOSDL/OOSDL.h"

#include "AssetsManager.h"
#include "GameOptionsManager.h"
#include "Player.h"
#include "EventManager.h"
#include "Gui/GuiTextBox.h"
#include "Gui/GuiMainMenu.h"
#include "Grenade.h"
#include "HealPack.h"
#include "Mine.h"
#include "Rocket.h"
#include "Melee.h"
#include "Gui/GuiWeaponMenu.h"
#include "GUI/GuiPauseMenu.h"

#include "Camera.h"

#include "MapManager.h"


class GameManager : public Singleton<GameManager> {
private:
	int turn;
	sdl::Clock turnClock;
	bool paused;
	sdl::StaticText turnText;

	sdl::StaticText movesText;

	std::vector<Team> teams;
	Player* actualPlayer;
	std::vector<Player*> players;

	bool canPlayersSpawn;
	bool started;


public:
	GameManager();

	void startGame(std::vector<Team> teams);

	void update(sdl::Window& renderWindow, Camera* cam, Map* actualMap, float frametime, int weapon);
	void draw(sdl::Window &target);

	int getActualTurn();

	void setActualTurn(int turn);

	bool isPaused();
	bool isStarted() { return started; }

	void reset();
};