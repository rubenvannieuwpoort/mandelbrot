#pragma once

#include <iostream>


void display(std::string caption, Uint32* image, Resolution resolution) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cerr << "SDL_Init(SDL_INIT_VIDEO) failed\n";
		return;
	}

	//SDL_Window* window = SDL_CreateWindow(caption.c_str(),
	//	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, resolution.Width, resolution.Height, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_Window* window = SDL_CreateWindow(caption.c_str(),
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, resolution.Width, resolution.Height, SDL_WINDOW_RESIZABLE);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STATIC, resolution.Width, resolution.Height);

	SDL_UpdateTexture(texture, NULL, image, resolution.Width * sizeof(Uint32));

	bool quit = false, fullscreen = false;
	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
				break;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					quit = true;
					break;
				}
			}
		}
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}