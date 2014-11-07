#include "Sprite.h"
#include "Window.h"

float degreeToRadian(float degree){
	return degree * (M_PI / 180);
}

sdl::Sprite::Sprite()
{
}
sdl::Sprite::~Sprite()
{
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
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, texture->getSurface());
	SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
	SDL_Rect source = { (int)this->textureRect.x, (int)this->textureRect.y, (int)this->textureRect.w, (int)this->textureRect.h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, tmpTexture, &source, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
	SDL_DestroyTexture(tmpTexture);
}
