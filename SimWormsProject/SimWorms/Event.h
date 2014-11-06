#pragma once

namespace sdl{
	class Event{
	public:
		unsigned int type;
		union {
			unsigned int keycode;
			unsigned int button;
		};
	};
}