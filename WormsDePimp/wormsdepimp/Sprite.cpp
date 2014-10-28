#include "Sprite.h"
#include "Window.h"


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
void sdl::Sprite::draw(SDL_Renderer* renderer, sdl::View &view){
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, texture->getSurface());
	SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
	SDL_Rect source = { (int)this->textureRect.x, (int)this->textureRect.y, (int)this->textureRect.w, (int)this->textureRect.h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, tmpTexture, &source, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
	SDL_DestroyTexture(tmpTexture);
}
sdl::RectFloat sdl::Sprite::getRenderDestination(sdl::View& view) {
	std::vector<float> components;
	Vector2Float viewRatio = { view.getViewport().w / view.getSize().x, view.getViewport().h / view.getSize().y };
	for (int i = 0; i < 2; ++i) {
		float truePosition = position[i] - origin[i];
		float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
		float viewScaledPosition = (truePosition - viewBound) * viewRatio[i];
		components.push_back(viewScaledPosition);
	} for (int i = 0; i < 2; ++i) {
		float scaledTexturePosition = texture->getSize()[i] * scaleFactors[i];
		float viewScaled = scaledTexturePosition * viewRatio[i];
		components.push_back(viewScaled);
	} return sdl::RectFloat(components[0], components[1], components[2], components[3]);
}