#pragma once

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<memory>
#include<string>
#include<stdexcept>
#include<vector>


struct Entity {
	std::shared_ptr<SDL_Renderer> renderer;
	std::shared_ptr<SDL_Texture> texture;
	std::vector<float> position;
	SDL_Rect frame;
	Entity(
		std::shared_ptr<SDL_Renderer> renderer,
		std::string path,
		SDL_Rect frame,
		std::vector<float> position = std::vector<float>{0.0, 0.0}
	) : renderer(
		renderer
	),
	texture(
		std::shared_ptr<SDL_Texture>(
			IMG_LoadTexture(renderer.get(), path.c_str()),
			SDL_DestroyTexture
		)
	),
	position(position),
	frame(frame)
	{
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

	void update(std::vector<float> newPosition){
		position = newPosition;
	}

	int render() {
		SDL_Rect dst {
			(int) position[0],
			(int) position[1],
			frame.w * 2,
			frame.h * 2
		};

		return SDL_RenderCopy(renderer.get(), *this, *this, &dst);
	}

	operator SDL_Texture *() {
		return texture.get();
	}

	operator SDL_Rect *() {
		return &frame;
	}
};
