#include "Text.h"

int sdl::Text::instances = 0;

sdl::Text::Text(const std::string &text, const std::string &fontPath, int characterSize)
{
	if (++instances == 1)
		TTF_Init();
	this->fontPath = fontPath;
	this->font = nullptr;
	this->text = text;
	this->characterSize = characterSize;
	this->textSurface = nullptr;
	update();
}


sdl::Text::~Text()
{
	SDL_FreeSurface(textSurface);
	if (font != nullptr)
		TTF_CloseFont(font);
	if (--instances == 0)
		TTF_Quit();
}

void sdl::Text::setString(const std::string &text){
	this->text = text;
	update();
}
void sdl::Text::setFont(const std::string &fontPath){
	this->fontPath = fontPath;
	update();
}
void sdl::Text::setCharacterSize(int size){
	this->characterSize = size;
	update();
}
void sdl::Text::setStyle(Uint32 style){
	this->style = style;
	update();
}
void sdl::Text::setColor(sdl::Color &color){
	this->color = color;
	update();
}

std::string& sdl::Text::getString(){
	return this->text;
}
int sdl::Text::getCharacterSize(){
	return this->characterSize;
}
Uint32 sdl::Text::getStyle(){
	return this->style;
}
sdl::Color& sdl::Text::getColor(){
	return this->color;
}

sdl::RectFloat sdl::Text::getBounds(){
	if (this->textSurface != nullptr)
		return sdl::RectFloat(this->position.x, this->position.y, this->textSurface->w * this->scaleFactors.x, this->textSurface->h * this->scaleFactors.y);
	return sdl::RectFloat(0, 0, 0, 0);
}

void sdl::Text::update(){
	if (fontPath == "")
		return;
	if (textSurface != nullptr)
		SDL_FreeSurface(textSurface);
	if (font != nullptr)
		TTF_CloseFont(font);
	font = TTF_OpenFont(fontPath.c_str(), characterSize);
	if (font == NULL)
		return;
	TTF_SetFontStyle(font, style);
	SDL_Color colorDestination = { color.r, color.g, color.b, color.a };
	textSurface = TTF_RenderText_Blended(font, text.c_str(), colorDestination);
	SDL_SetSurfaceBlendMode(textSurface, SDL_BLENDMODE_BLEND);
}

void sdl::Text::draw(SDL_Renderer* renderer, sdl::View &view){
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	if (textSurface != NULL){
		SDL_Texture* tmpTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
		SDL_SetTextureBlendMode(tmpTexture, SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(tmpTexture, color.a);
		SDL_Rect destination = { (int)getRenderDestination(view).x, (int)getRenderDestination(view).y, (int)getRenderDestination(view).w, (int)getRenderDestination(view).h };
		SDL_Point destinationOrigin = { (int)origin.x, (int)origin.y };
		SDL_RenderCopyEx(renderer, tmpTexture, NULL, &destination, orientation - view.getRotation(), &destinationOrigin, flipSide);
		SDL_DestroyTexture(tmpTexture);
	}
}

sdl::RectFloat sdl::Text::getRenderDestination(sdl::View& view) {

		std::vector<float> components;
		Vector2Float viewRatio = { view.getViewport().w / view.getSize().x, view.getViewport().h / view.getSize().y };
		for (int i = 0; i < 2; ++i) {
			float truePosition = position[i] - origin[i];
			float viewBound = view.getCenter()[i] - view.getSize()[i] / 2;
			float viewScaledPosition = (truePosition - viewBound) * viewRatio[i];
			components.push_back(viewScaledPosition);
		}
		float scaledTexturePositionX = textSurface->w * scaleFactors.x;
		float viewScaledX = scaledTexturePositionX * viewRatio.x;
		components.push_back(viewScaledX);
		float scaledTexturePositionY = textSurface->h * scaleFactors.y;
		float viewScaledY = scaledTexturePositionY * viewRatio.y;
		components.push_back(viewScaledY);
		return sdl::RectFloat(components[0], components[1], components[2], components[3]);

}