#include "Sprite.h"
#include "Window.h"

sdl::Sprite::Sprite(){
	texture = nullptr;
}
sdl::Sprite::~Sprite(){
	if (sdlTexture != NULL) 
			SDL_DestroyTexture(sdlTexture);
}
void sdl::Sprite::setTexture(sdl::Texture *texture){
	this->texture = texture;
	this->textureRect = sdl::RectFloat(0, 0, texture->getSize().x, texture->getSize().y);
}
void sdl::Sprite::setTexture(sdl::Texture *texture, sdl::RectFloat& textureRect){
	this->texture = texture;
	this->textureRect = textureRect;
}
void sdl::Sprite::setTextureRect(sdl::RectFloat& rect){
	this->textureRect = rect;
}
sdl::Texture* sdl::Sprite::getTexture(){
	return this->texture;
}
sdl::RectFloat& sdl::Sprite::getTextureRect(){
	return this->textureRect;
}
sdl::RectFloat sdl::Sprite::getBounds(){
	return sdl::RectFloat(position.x, position.y, texture->getSize().x, texture->getSize().y);
}
void sdl::Sprite::draw(SDL_Renderer* renderer, sdl::View &view){
	this->bounds = sdl::RectFloat(position.x, position.y, texture->getSize().x * scaleFactors.x, texture->getSize().y * scaleFactors.y);
	if (texture->hasChanged(true) || sdlTexture == NULL){
		SDL_DestroyTexture(sdlTexture);
		sdlTexture = SDL_CreateTextureFromSurface(renderer, texture->getSurface());
	}
	SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
	SDL_Rect source = { (int)this->textureRect.x, (int)this->textureRect.y, (int)this->textureRect.w, (int)this->textureRect.h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, sdlTexture, &source, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
}
