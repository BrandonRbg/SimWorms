#pragma once
#include <map>

#include "Singleton.h"
#include "OOSDL/VideoMode.h"
#include "OOSDL/Window.h"
class GameOptionsManager : public Singleton<GameOptionsManager>
{
public:

	GameOptionsManager();

	void setVideoMode(sdl::VideoMode& vm = sdl::VideoMode::getModes()[0]);
	sdl::VideoMode& getVideoMode();
	
	void setFullScreen(bool fs = true);
	bool isFullScreen();

	void update(sdl::Window& window);

	void setKeyControl(const std::string& control, Uint32 key);
	void setMouseControl(const std::string& control, Uint32 button);

	Uint32 getKeyControl(const std::string& control);
	Uint32 getMouseControl(const std::string& control);

private:
	bool fullScreen;
	sdl::VideoMode videoMode;

	std::map<std::string, std::vector<Uint32>> controls;
};

