#pragma once
#include <vector>

#include "Singleton.h"
#include "ScreenState.h"
class ScreenStateManager : public Singleton<ScreenStateManager>
{
public:
	ScreenStateManager();
	~ScreenStateManager();
	void pushScreenState(ScreenState* screenState);
	void popScreenState();
	void clear();
	void update(sdl::Window &target, float frametime);
	void draw(sdl::Window &target);
private:
	std::vector<ScreenState*> screenStates;
};

