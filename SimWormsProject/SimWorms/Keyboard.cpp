#include "Keyboard.h"

std::set<short> sdl::Keyboard::pressedKeys;

void sdl::Keyboard::updateKeyState(short key, bool state) {
	if (state)
		pressedKeys.insert(key);
	else
		pressedKeys.erase(key);
}

bool sdl::Keyboard::isKeyPressed(short key){
	return pressedKeys.find(key) != pressedKeys.end();
}

bool sdl::Keyboard::isKeyReleased(short key){
	return !(pressedKeys.find(key) != pressedKeys.end());
}
