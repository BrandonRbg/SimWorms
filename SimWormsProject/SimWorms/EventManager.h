#pragma once
#include "OOSDL/OOSDL.h"
#include "Singleton.h"
#include <functional>
#include <map>
#include <vector>

class EventManager :  public Singleton<EventManager>
{
public:
	EventManager();
	int addCallbackToID(Uint32 Type, std::function<void(SDL_Event)> Function);
	void launchEvent(SDL_Event Event);
private:
	std::map<Uint32, std::vector<std::function<void(SDL_Event)>>> Functions;
};

