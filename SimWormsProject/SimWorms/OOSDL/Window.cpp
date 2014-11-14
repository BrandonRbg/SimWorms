#include "Window.h"

int sdl::Window::instances = 0;

sdl::Window::Window(float x, float y, const std::string& title, Uint32 flags) {
	++instances;
	if (instances == 1)
		SDL_Init(SDL_INIT_VIDEO);
	isWindowOpen = true;

	this->size.x = x;
	this->size.y = y;
	this->windowID = SDL_GetWindowID(this->sdlWindow);
	sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)size.x, (int)size.y, flags);
	sdlRender = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	this->setTitle(title);
	this->view = sdl::View(sdl::Vector2Float(this->size.x / 2, this->size.y / 2), sdl::Vector2Float(this->size.x, this->size.y));
}

sdl::Window::~Window()
{
	SDL_DestroyRenderer(this->sdlRender);
	SDL_DestroyWindow(this->sdlWindow);

	SDL_DestroyRenderer(sdlRender);
	SDL_DestroyWindow(sdlWindow);

	--instances;
	if (instances == 0)
		SDL_Quit();
}

void sdl::Window::show(){
	SDL_RenderPresent(sdlRender);
}

void sdl::Window::clear(){
	SDL_RenderClear(sdlRender);
	drawables.clear();
}

void sdl::Window::clear(sdl::Color& color){
	SDL_SetRenderDrawColor(sdlRender, color.r, color.g, color.b, color.a);
	SDL_RenderClear(sdlRender);
	drawables.clear();
}

void sdl::Window::setTitle(const std::string& title){
	this->title = title;
	SDL_SetWindowTitle(sdlWindow, title.c_str());
}

void sdl::Window::draw(sdl::Drawable* drawable){
	this->drawables.push_back(drawable);
	drawable->draw(sdlRender, this->view);
}

SDL_Renderer* sdl::Window::getRenderer(){
	return sdlRender;
}

void sdl::Window::setView(sdl::View &view){
	this->view = view;
	SDL_Rect viewport = { (int)view.getViewport().x, (int)view.getViewport().y, (int)view.getViewport().w, (int)view.getViewport().h };
	SDL_RenderSetViewport(this->sdlRender, &viewport);
}

sdl::View sdl::Window::getDefaultView(){
	return sdl::View(sdl::Vector2Float(this->size.x / 2, this->size.y / 2), size);
}
bool sdl::Window::pollEvent(SDL_Event &event){
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_KEYDOWN){
			sdl::Keyboard::updateKeyState(event.key.keysym.sym, true);
		}
		if (event.type == SDL_KEYUP){
			sdl::Keyboard::updateKeyState(event.key.keysym.sym, false);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN){
			sdl::Mouse::updateMouseButtonState(event.button.button, true);
		}
		if (event.type == SDL_MOUSEBUTTONUP){
			sdl::Mouse::updateMouseButtonState(event.button.button, false);
		}
		if (event.type == SDL_MOUSEMOTION)
			sdl::Mouse::updateMousePosition(event.motion.x, event.motion.y);
		return true;
	}
	return false;
}

sdl::View sdl::Window::getView(){
	return this->view;
}

bool sdl::Window::isOpen(){
	if (isWindowOpen)
		return true;
	return false;
}

void sdl::Window::close(){
	isWindowOpen = false;
}