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
			for (sdl::Vector2 point : getPoints()) {
				if (contains(point))
					return true;
			} return false;
		}
		std::set<sdl::Vector2<T>> getPoints() {
			std::set<sdl::Vector2> points;
			points.insert(sdl::Vector2(x, y));
			points.insert(sdl::Vector2(x, y + h));
			points.insert(sdl::Vector2(x + w, y));
			points.insert(sdl::Vector2(x + w, y + h));
			return points;
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
