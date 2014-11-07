#pragma once

namespace sdl{
	class Color{
	public:
		Color(int r, int g, int b, int a = 255){
			this->r = r;
			this->b = b;
			this->g = g;
			this->a = a;
		}
		Color() : Color(0, 0, 0){}
		int r, g, b, a;
		static Color Black;
		static Color White;
		static Color Red;
		static Color Green;
		static Color Blue;
		static Color Yellow;
		static Color Magenta;
		static Color Cyan;
		static Color Transparent;
	};

}