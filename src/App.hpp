#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<memory>
#include<string>
#include<stdexcept>
#include<thread>
#include<functional>
#include "EventHandler.hpp"


struct App {
	std::shared_ptr<SDL_Window> window;
	std::shared_ptr<SDL_Renderer> renderer;
	std::shared_ptr<EventHandler> eventHandler;
	std::thread loop;

	App(
		const std::string & title,
		int height,
		int width,
		std::shared_ptr<EventHandler> eventHandler
	);

	~App();

	std::thread & run();
};
