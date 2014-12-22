#pragma once 
#include <set>
#include <vector>
#include "Vector2.h"

namespace sdl{
	template<typename T>
	class Rect{
	public:
		Rect(T x = 0, T y = 0, T w = 0, T h = 0){
			this->h = h;
			this->w = w;
			this->y = y;
			this->x = x;
		}

		bool contains(float x, float y){
			bool isWithinX = x >= this->x && x <= (this->x + this->w);
			bool isWithinY = y >= this->y && y <= (this->y + this->h);
			return isWithinX && isWithinY;
		}
		bool contains(sdl::Vector2<T> &point){
			return contains(point.x, point.y);
		}
		bool intersects(sdl::Rect<T>& rect){
			if (contains(rect.x, rect.y) || contains(rect.x, rect.y + rect.h) || contains(rect.x + rect.w, rect.y) || contains(rect.x + rect.w, rect.y + rect.h))
				return true;
			return false;
		}
		
		std::vector<T> getComponents() {
			std::vector<T> components;
			components.push_back(x);
			components.push_back(y);
			components.push_back(w);
			components.push_back(h);
			return components;
		}

		float operator[](int i) { 
			return getComponents()[i]; 
		}

		T x, y, w, h;
	};
	typedef Rect<int> RectInt;
	typedef Rect<float> RectFloat;
}
