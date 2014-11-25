#pragma once
#include <memory>

#include "Singleton.h"
#include "ScreenState.h"
class ScreenStateManager : public Singleton<ScreenStateManager>
{
public:
	ScreenStateManager();
	~ScreenStateManager();
	void setScreenState(ScreenState* screenState);
	void update(float frametime);
	void draw(sdl::Window &target);
private:
	ScreenState* actualScreenState;
};

