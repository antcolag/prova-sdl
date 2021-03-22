#pragma once

#include<SDL2/SDL.h>
#include<atomic>

struct EventHandler {
	std::atomic<SDL_Event> last;
	void loop();
};
