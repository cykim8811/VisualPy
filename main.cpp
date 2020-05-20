#include "SDL.h"
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {

	// Initializing SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error initializing SDL: %s\n", SDL_GetError());
	}

	// Creating SDL window and renderer
	SDL_Window* window = SDL_CreateWindow(
		"VisualPy",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1280, 960, SDL_WINDOW_RESIZABLE
	);
	SDL_Renderer* renderer = SDL_CreateRenderer(
		window, -1, SDL_RENDERER_ACCELERATED
	);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);

	// Main Loop
	bool running = true;
	while (running) {
		// Handling Event
		SDL_Event evt;
		while (SDL_PollEvent(&evt)) {
			switch (evt.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			case SDL_WINDOWEVENT_RESIZED:

				break;
			default:
				break;
			}
		}
		// Draw Screen
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();
	return 0;
}