#include "AnimatedSprite.h"


sdl::AnimatedSprite::AnimatedSprite(sdl::Texture* texture, int numberOfFrames, int delay) {
	this->texture = texture;
	this->numberOfFrames = numberOfFrames;
	this->delay = delay;

	reset();

	this->active = true;
	this->looping = true;
}
void sdl::AnimatedSprite::reset() {
	int frameWidth = (int)texture->getSize().x / numberOfFrames;
	int frameHeight = (int)texture->getSize().y;

	this->textureRect = sdl::RectFloat(0, 0, (float)frameWidth, (float)frameHeight);
}
void sdl::AnimatedSprite::nextFrame() {
	++currentFrame;

	int frameWidth = (int)texture->getSize().x / numberOfFrames;
	int frameHeight = (int)texture->getSize().y;

	this->textureRect = sdl::RectFloat((float)frameWidth * currentFrame, 0, (float)frameWidth, (float)frameHeight);

	if (currentFrame >= numberOfFrames) {
		if (looping) {
			currentFrame = 0;
			reset();
		} else
			active = false;
	}
}
void sdl::AnimatedSprite::updateFrame() {
	if (!active)
		return;
	if (clock.getElapsedTime().asMilliseconds() >= delay) {
		nextFrame();
		clock.restart();
	}
}
void sdl::AnimatedSprite::draw(SDL_Renderer* renderer, sdl::View &view) {
	updateFrame();
	SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, texture->getSurface());
	int frameWidth = (int)texture->getSize().x / numberOfFrames;
	SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
	SDL_Rect source = { (int) this->textureRect.x, (int)this->textureRect.y, (int)this->textureRect.w, (int)this->textureRect.h };
	SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
	SDL_RenderCopyEx(renderer, tmpTexture, &source, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
	SDL_DestroyTexture(tmpTexture);
}

sdl::RectFloat sdl::AnimatedSprite::getRenderDestination(sdl::View& view) {
	std::vector<float> components;
	Vector2Float viewRatio = { view.getViewport().w / view.getSize().x, view.getViewport().h / view.getSize().y };
	for (int i = 0; i < 2; ++i) {
		float truePosition = position[i] - origin[i];
		float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
		float viewScaledPosition = (truePosition - viewBound) * viewRatio[i];
		components.push_back(viewScaledPosition);
	}
		float scaledTexturePositionX = (texture->getSize().x / numberOfFrames) * scaleFactors.x;
		float viewScaledX = scaledTexturePositionX * viewRatio.x;
		components.push_back(viewScaledX);
		float scaledTexturePositionY = texture->getSize().y * scaleFactors.y;
		float viewScaledY = scaledTexturePositionY * viewRatio.y;
		components.push_back(viewScaledY);
	return sdl::RectFloat(components[0], components[1], components[2], components[3]);
}