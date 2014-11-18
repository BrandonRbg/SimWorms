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
<<<<<<< HEAD
	Vector2Float viewRatio = { view.getViewport().w / view.getSize().x, view.getViewport().h / view.getSize().y };
	for (int i = 0; i < 2; ++i) {
		float truePosition = position[i];
		float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
		float viewScaledPosition = (truePosition + viewBound) * viewRatio[i];
=======
	Vector2Float viewRatio = { view.getSize().x / view.getViewport().w, view.getSize().y / view.getViewport().h };
	for (int i = 0; i < 2; ++i) {
		float truePosition = position[i];
		float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
		float viewScaledPosition = (truePosition * viewRatio[i]) + viewBound;
>>>>>>> 16bd493bb2c4d248f78827fc2ca8b0ccd5b6e011
		components.push_back(viewScaledPosition);
	} return sdl::Vector2Float(components[0], components[1]);
}