#include "App.hpp"

std::thread & App::run(){
	loop = std::thread {
		&EventHandler::loop,
		eventHandler.get()
	};
	return loop;
}


App::App(
	const std::string & title,
	int height,
	int width,
	std::shared_ptr<EventHandler> eventHandler
) : window(
	SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		height,
		width,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
	),
	SDL_DestroyWindow
),
renderer(
	SDL_CreateRenderer(
		window.get(),
		-1,
		SDL_RENDERER_ACCELERATED
	),
	SDL_DestroyRenderer
),
eventHandler(eventHandler)
{
	if(!window){
		throw std::runtime_error("Error creating the window");
	}
	auto videoErr = SDL_Init(SDL_INIT_VIDEO);
	if(videoErr){
		throw std::runtime_error(
			std::string{
				"Error initializing video "
			} +
			std::to_string(videoErr) +
			": " +
			SDL_GetError()
		);
	}

	if(!IMG_Init(IMG_INIT_PNG)) {
		throw std::runtime_error(
			std::string{
				"Error initializing images "
			} +
			": " +
			SDL_GetError()
		);
	}
}

App::~App(){
	SDL_Quit();
}
