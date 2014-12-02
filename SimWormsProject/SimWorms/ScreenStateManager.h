#pragma once
#include <vector>

#include "Singleton.h"
#include "ScreenState.h"
class ScreenStateManager : public Singleton<ScreenStateManager>
{
public:
	ScreenStateManager();
	~ScreenStateManager();
	void addScreenState(ScreenState* screenState);
	void clear();
	void update(float frametime);
	void draw(sdl::Window &target);
private:
	std::vector<ScreenState*> screenStates;
};

