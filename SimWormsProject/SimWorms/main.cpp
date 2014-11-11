<<<<<<< HEAD
#include "OOSDL.h"
=======
#include "OOSDL/OOSDL.h"
>>>>>>> origin/Brandon

int main(int argc, char** argv){
	sdl::Window renderWindow(640, 480, "SimWorms");
	
	while (renderWindow.isOpen()){
		SDL_Event event;
		while (renderWindow.pollEvent(event)){
			if (event.type == SDL_WINDOWEVENT)
				if (event.window.event == SDL_WINDOWEVENT_CLOSE)
					renderWindow.close();
		}
		
		renderWindow.clear(sdl::Color::White);
		renderWindow.show();
	}
	return 0;
}