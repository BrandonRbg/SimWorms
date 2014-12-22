#pragma once
#include "OOSDL/OOSDL.h"

class ScreenState{
public:
	ScreenState(){
		paused = false;
	}
	virtual void update(sdl::Window &target, float frametime) = 0;
	virtual void draw(sdl::Window &target) = 0;
	void pause(bool paused){
		this->paused = paused;
	}
protected:
	bool paused;
};