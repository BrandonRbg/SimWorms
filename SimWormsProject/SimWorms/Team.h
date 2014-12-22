#pragma once
#include "OOSDL/OOSDL.h"
class Team
{
public:
	Team(const std::string& name, sdl::Color& color);
	Team() : Team("", sdl::Color::Black){}
	std::string& getName();
	sdl::Color& getColor();
	int getId();
private:
	static int teams;
	int id;
	std::string name;
	sdl::Color color;

}; 

