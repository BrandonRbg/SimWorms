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

sdl::Vector2Float sdl::Mouse::getPosition(sdl::View &view){
	std::vector<float> components;
	Vector2Float viewRatio = { view.getSize().x / view.getViewport().w, view.getSize().y / view.getViewport().h };
	for (int i = 0; i < 2; ++i) {
		float truePosition = position[i];
		float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
		float viewScaledPosition = (truePosition * viewRatio[i]) + viewBound;
		components.push_back(viewScaledPosition);
	} return sdl::Vector2Float(components[0], components[1]);
}