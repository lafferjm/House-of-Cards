#ifndef INBETWEEN_H
#define INBETWEEN_H

#include "game.h"
#include "card.h"
#include "chip.h"

class Inbetween : public Game {

	private:
		SDL_Surface* game_surface;
		Chip chips;

	public:
		Inbetween(SDL_Surface*);	
		void run();
};

#endif
