#include "Shape.h"


void sdl::Shape::setFillColor(sdl::Color &color){
	this->fillColor = color;
}

void sdl::Shape::setOutlineColor(sdl::Color &color){
	this->outlineColor = color;
}
void sdl::Shape::setOutlineThickness(float thickness){
	this->outlineThickness = thickness;
}

sdl::Color sdl::Shape::getFillColor(){
	return this->fillColor;
}
sdl::Color sdl::Shape::getOutlineColor(){
	return this->outlineColor;
}
float sdl::Shape::getOutlineThickness(){
	return this->outlineThickness;
}
sdl::Vector2Float sdl::Shape::getPoint(int index){
	if (index < points.size())
		return points[index];
}
