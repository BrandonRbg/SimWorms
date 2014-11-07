#include "Clock.h"


sdl::Clock::Clock()
{
	this->elapsedTimeSinceLastRestart = high_resolution_clock::now();
}

sdl::Time sdl::Clock::getElapsedTime(){
	std::chrono::duration<double> span = duration_cast<duration<double>>(high_resolution_clock::now() - elapsedTimeSinceLastRestart);
	return sdl::Time(span.count());
} 

sdl::Time sdl::Clock::restart(){
	double time = getElapsedTime().asSeconds();
	this->elapsedTimeSinceLastRestart = high_resolution_clock::now();
	return sdl::Time(time);
}