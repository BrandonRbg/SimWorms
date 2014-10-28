#pragma once
#include <vector>
#include <SDL2/SDL.h>

namespace sdl{
	template<typename T>
	class Vector2{
	public:
		Vector2(){
			this->x = 0;
			this->y = 0;
		}
		Vector2(T x, T y){
			this->x = x;
			this->y = y;
		}
		Vector2 operator+(Vector2<T> vect){
			return Vector2(this->x + vect.x, this->y + vect.y);
		}
		Vector2 operator-(Vector2<T> vect){
			return Vector2(this->x - vect.x, this->y - vect.y);
		}


		std::vector<T> getComponents() {
			std::vector<T> components;
			components.push_back(x);
			components.push_back(y);
			return components;
		}

		float operator[](int i) {
			return getComponents()[i];
		}

		T x, y;
	};
	typedef Vector2<int> Vector2Int;
	typedef Vector2<unsigned int> Vector2UInt;
	typedef Vector2<float> Vector2Float;
}