#include "EventHandler.hpp"

void EventHandler::loop() {
	SDL_Event sdlEvent;
	do {
		while(SDL_PollEvent(&sdlEvent)){
			switch (sdlEvent.type)
			{
			default:
				std::cout << sdlEvent.type << std::endl;
				last = sdlEvent;
			}
		}
	} while (sdlEvent.type != SDL_QUIT);
}