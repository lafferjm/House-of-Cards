#include <iostream>
#include "slots.h"
#include <SDL/SDL.h>

Slots::Slots(SDL_Surface* screen) {
	game_surface = screen;
}

void Slots::run() {

	SDL_WM_SetCaption("House Of Cards:Slots",NULL);
	SDL_FillRect(game_surface,&game_surface->clip_rect,0x008400);
	bool is_running = true;
	SDL_Event event;

	SDL_Flip(game_surface);

	while(is_running) {
	
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				is_running = false;	
		}
	}
}
