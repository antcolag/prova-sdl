#include "App.hpp"


#include<iostream>

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
				"Error initializing video"
			} +
			std::to_string(videoErr) +
			": " +
			SDL_GetError()
		);
	}

	if(!IMG_Init(IMG_INIT_PNG)) {
		throw std::runtime_error(
			std::string{
				"Error initializing images"
			} +
			": " +
			SDL_GetError()
		);
	}
}

App::~App(){
	SDL_Quit();
}


void App::render() {
	Entity grass {renderer, "assets/soil.png", {0,0,32,32}};

	do {
		auto r = renderer.get();
		SDL_RenderClear(r);
		grass.render(std::make_shared<SDL_Rect>(SDL_Rect{0,0,32,32}));
		SDL_RenderPresent(r);
	} while(eventHandler.get()->last.load().type != SDL_QUIT);
}


void App::run(){
	event_thread = std::thread {
		&EventHandler::loop,
		eventHandler.get()
	};
	render_thread = std::thread {
		&App::render,
		this
	};

	event_thread.join();
	render_thread.join();
}

