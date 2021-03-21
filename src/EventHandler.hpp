#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<atomic>

#include<iostream>

struct EventHandler {
	std::atomic<SDL_Event> last;
	void loop();
};
