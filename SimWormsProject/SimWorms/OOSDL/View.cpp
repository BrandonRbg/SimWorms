#include "View.h"


sdl::View::View()
: View(sdl::RectFloat(0, 0, 0, 0)) {

}

sdl::View::View(const sdl::RectFloat &rect){
	this->center = sdl::Vector2Float(rect.x, rect.y);
	this->orientation = 0;
	this->size = sdl::Vector2Float(rect.w, rect.h);
	this->originalSize = this->size;
	this->viewport = sdl::RectFloat(this->center.x - (size.x / 2), this->center.y - (size.y / 2), this->size.x, this->size.y);
}
sdl::View::View(sdl::Vector2Float& center, sdl::Vector2Float& size){
	this->center = center;
	this->orientation = 0;
	this->size = size;
	this->originalSize = this->size;
	this->viewport = sdl::RectFloat(this->center.x - (size.x / 2), this->center.y - (size.y / 2), this->size.x, this->size.y);
}

void sdl::View::setCenter(float x, float y){
	this->center = sdl::Vector2Float(x, y);
}
void sdl::View::setCenter(sdl::Vector2Float &center){
	this->center = center;
}

void sdl::View::setSize(float w, float h){
	this->size = sdl::Vector2Float(w, h);
	this->originalSize = this->size;
}
void sdl::View::setSize(sdl::Vector2Float &size){
	this->size = size;
	this->originalSize = this->size;
}

void sdl::View::setRotation(float angle){
	this->orientation = angle;
}

void sdl::View::setViewport(const sdl::RectFloat &viewport){
	this->viewport = viewport;
}

void sdl::View::reset(const sdl::RectFloat &rect){
	this->center = sdl::Vector2Float(rect.x, rect.y);
	this->size = sdl::Vector2Float(rect.w, rect.h);
}

sdl::Vector2Float& sdl::View::getCenter(){
	return this->center;
}

sdl::Vector2Float& sdl::View::getSize(){
	return this->size;
}

float sdl::View::getRotation(){
	return this->orientation;
}

sdl::RectFloat& sdl::View::getViewport(){
	return this->viewport;
}

void sdl::View::move(float x, float y){
	this->center.x += x;
	this->center.y += y;
}
void sdl::View::move(sdl::Vector2Float& vect){
	this->center.x += vect.x;
	this->center.y += vect.y;
}

void sdl::View::rotate(float angle){
	this->orientation += angle;
}

void sdl::View::zoom(float factor){
	this->zoomFactor = factor;
	this->size.x *= zoomFactor;
	this->size.y *= zoomFactor;
}


