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

#include "Camera.h"

#include "MapManager.h"


class GameManager : public Singleton<GameManager> {
private:
	int tour;
	bool playerIsOnGround;
	int numberPlayer;
	sdl::Clock tourClock;
public:
	GameManager();

	void startGame(int numberTeam);

	void update(sdl::Window& renderWindow, Camera cam, sdl::StaticText fpsText, Map actualMap, sdl::Clock fpsClock, sdl::Clock fpsDisplayUpdateClock);

	int getTour();

	void setTour(int tour);

	int getNumberPlayer();

	void setNumberPlayer(int numberPlayer);
};