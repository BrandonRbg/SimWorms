#include "Mouse.h"

std::set<short> sdl::Mouse::pressedButtons;
sdl::Vector2Float sdl::Mouse::position;

void sdl::Mouse::updateMouseButtonState(short button, bool state){
	if (state)
		pressedButtons.insert(button);
	else
		pressedButtons.erase(button);
}
void sdl::Mouse::updateMousePosition(int x, int y){
	position = sdl::Vector2Float(x, y);
}

bool sdl::Mouse::isButtonPressed(short button){
	return pressedButtons.find(button) != pressedButtons.end();
}
sdl::Vector2Float sdl::Mouse::getPosition(){
	return position;
}