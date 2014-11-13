#pragma once

#include <chrono>

namespace sdl{
	class Time{
	public:
		Time(){

		}
		Time(double timeAsSeconds){
			this->timeAsSeconds = timeAsSeconds;
		}
		double asSeconds(){
			return this->timeAsSeconds;
		}
		double asMilliseconds(){
			return this->timeAsSeconds * 1000;
		}
		double asMicroSeconds(){
			return this->timeAsSeconds * 1000000;
		}
		void setTime(double timeAsSeconds){
			this->timeAsSeconds = timeAsSeconds;
		}
	private:
		double timeAsSeconds;
	};
}