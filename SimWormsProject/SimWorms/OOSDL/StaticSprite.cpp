#include "StaticSprite.h"


void sdl::StaticSprite::draw(SDL_Renderer* renderer, sdl::View &view){
	this->bounds = sdl::RectFloat(position.x, position.y, texture->getSize().x * scaleFactors.x, texture->getSize().y * scaleFactors.y);
	if (texture->hasChanged(true) || sdlTexture == NULL){
		SDL_DestroyTexture(sdlTexture);
		sdlTexture = SDL_CreateTextureFromSurface(renderer, texture->getSurface());
	}
	SDL_Rect destination = { position.x, position.y, texture->getSurface()->w, texture->getSurface()->h };
	SDL_Rect source = { (int)this->textureRect.x, (int)this->textureRect.y, (int)this->textureRect.w, (int)this->textureRect.h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, sdlTexture, &source, &destination, orientation, &destinationOrigin, flipSide);
}
