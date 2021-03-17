#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<memory>
#include<string>
#include<stdexcept>
#include<iostream>
#include<thread>
#include<atomic>

struct App {
	std::shared_ptr<SDL_Window> window;
	std::shared_ptr<SDL_Renderer> renderer;
	std::atomic<bool> isRunning{false};
	std::atomic<SDL_Event> lastEvent;
	std::thread loop;

	App(
		const std::string & title,
		int height,
		int width
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
	)
	{
		if(!window){
			throw std::runtime_error("Error creating the window\n");
		}
		auto videoErr = SDL_Init(SDL_INIT_VIDEO);
		if(videoErr){
			throw std::runtime_error(
				std::string{
					"Error initializing video "
				} +
				std::to_string(videoErr) +
				":\n" +
				SDL_GetError()
			);
		}
	}

	~App(){
		SDL_Quit();
	}

	std::thread & run();
};
