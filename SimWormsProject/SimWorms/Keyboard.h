#pragma once
#include <SDL2/SDL.h>

#include <set>

namespace sdl{
	class Keyboard
	{
	public:
		static void updateKeyState(short key, bool state);

		static bool isKeyPressed(short key);
		static bool isKeyReleased(short key);
	private:
		static std::set<short> pressedKeys;
	};
}
