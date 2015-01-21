#include "Team.h"

int Team::teams = 0;
Team::Team(const std::string& name, sdl::Color& color){
	this->name = name;
	this->color = color;
	this->id = teams++;
}

int Team::getId(){
	return this->id;
}

std::string& Team::getName(){
	return this->name;
}

sdl::Color& Team::getColor(){
	return this->color;
}