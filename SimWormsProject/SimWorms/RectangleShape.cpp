#include "RectangleShape.h"


sdl::RectangleShape::RectangleShape(sdl::RectFloat& rect){
	this->rect = rect;
}

sdl::RectangleShape::~RectangleShape(){
	if (surface->format != NULL)
		SDL_FreeSurface(surface);
}

void sdl::RectangleShape::setSize(sdl::Vector2Float &size){
	this->rect.w = size.x;
	this->rect.h = size.y;
}

sdl::Vector2Float sdl::RectangleShape::getSize(){
	return sdl::Vector2Float(rect.w, rect.h);
}

unsigned int sdl::RectangleShape::getPointCount(){
	return points.size();
}

sdl::RectFloat sdl::RectangleShape::getBounds(){
	return sdl::RectFloat(position.x, position.y, rect.w, rect.h);
}

void sdl::RectangleShape::draw(SDL_Renderer* renderer, sdl::View& view){
	update();
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, tmpTexture, NULL, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
	SDL_DestroyTexture(tmpTexture);
}

void sdl::RectangleShape::update(){
	if (surface->format != NULL)
		SDL_FreeSurface(surface);
	points.clear();
	for (auto& i : points)
		i = sdl::Vector2Float(cos(degreeToRadian(orientation)) * (i.x - origin.x) - sin(degreeToRadian(orientation)) * (i.y - origin.y), sin(degreeToRadian(orientation)) * (i.x - origin.x) - cos(degreeToRadian(orientation)) * (i.y - origin.y));
	rectangleRGBA(surface, bounds.x, bounds.y, bounds.w, bounds.h, fillColor.r, fillColor.g, fillColor.b, fillColor.a);
}