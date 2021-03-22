#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<memory>
#include<string>
#include<stdexcept>


struct Entity {
	std::shared_ptr<SDL_Texture> texture;
	std::shared_ptr<SDL_Renderer> renderer;
	SDL_Rect rect;
	Entity(
		std::shared_ptr<SDL_Renderer> renderer,
		std::string path,
		SDL_Rect rect
	) : renderer(
		renderer
	),
	texture(
		std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(renderer.get(), path.c_str()),
			SDL_DestroyTexture
		)
	), rect(rect) {
		if(!texture.get()) {
			throw std::runtime_error(
				std::string{
					"Error initializing texture"
				} +
				": " +
				SDL_GetError()
			);
		}
	}

	int render(std::shared_ptr<SDL_Rect> dst) {
		return SDL_RenderCopy(renderer.get(), *this, *this, dst.get());
	}

	operator SDL_Texture *() {
		return texture.get();
	}

	operator SDL_Rect *() {
		return &rect;
	}
};
