#include "App.hpp"

std::thread & App::run(){
	std::cout << "start" << std::endl;
	isRunning = true;
	loop = std::thread {
		[&](){
			SDL_Event sdlEvent;
			do {
				while(SDL_PollEvent(&sdlEvent)){
					switch (sdlEvent.type)
					{
					default:
						std::cout << sdlEvent.type << std::endl;
						lastEvent = sdlEvent;
					}
				}
			} while (sdlEvent.type != SDL_QUIT);
		}
	};
	return loop;
}