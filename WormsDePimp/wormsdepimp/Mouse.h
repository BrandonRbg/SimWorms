#pragma once
#include <SDL2/SDL.h>
#include <set>

#include "Vector2.h"

namespace sdl{
	class Mouse
	{
	public:
		static void updateMouseButtonState(short button, bool state);
		static void updateMousePosition(int x, int y);

		static bool isButtonPressed(short button);
		static sdl::Vector2Int getPosition();
	private:
		static std::set<short> pressedButtons;
		static sdl::Vector2Int position;
	};
}
