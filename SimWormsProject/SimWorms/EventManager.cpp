#include "EventManager.h"

EventManager::EventManager()
{
}

int EventManager::addCallbackToID(Uint32 Type, std::function<void(SDL_Event)> Function){
	Functions[Type].push_back(Function);
	return Functions[Type].size() - 1;
}

void EventManager::launchEvent(SDL_Event Event){
	if (Functions.find(Event.type) == Functions.end())
		return;
	for (auto& it : Functions[Event.type])
		it(Event);
}
