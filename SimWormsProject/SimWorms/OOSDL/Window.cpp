#include "Window.h"

int sdl::Window::instances = 0;

sdl::Window::Window(sdl::VideoMode vm, const std::string& title, bool fs) {
	++instances;
	if (instances == 1)
		SDL_Init(SDL_INIT_VIDEO);
	isWindowOpen = true;

	this->size.x = vm.w;
	this->size.y = vm.h;
	this->windowID = SDL_GetWindowID(this->sdlWindow);

	sdlWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (int)size.x, (int)size.y, 0);
	sdlRender = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	this->setTitle(title);
	this->view = sdl::View(sdl::Vector2Float(this->size.x / 2, this->size.y / 2), sdl::Vector2Float(this->size.x, this->size.y));
	setFullScreen(fs);
	isOnFullscreen = fs;
}

sdl::Window::~Window()
{
	SDL_DestroyRenderer(sdlRender);
	SDL_DestroyWindow(sdlWindow);

	--instances;
	if (instances == 0)
		SDL_Quit();
}

void sdl::Window::setVideoMode(sdl::VideoMode vm){
	this->size = sdl::Vector2Float(vm.w, vm.h);
	bool tmpFs = isOnFullscreen;
	setFullScreen(false);
	SDL_SetWindowSize(sdlWindow, size.x, size.y);
	SDL_SetWindowPosition(sdlWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	if (tmpFs)
		setFullScreen(true);
}


void sdl::Window::setFullScreen(bool fs){
	if (fs)
		SDL_SetWindowFullscreen(sdlWindow, SDL_WINDOW_FULLSCREEN);
	else
		SDL_SetWindowFullscreen(sdlWindow, 0);
	isOnFullscreen = fs;
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