#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "game.h"
#include "card.h"
#include <SDL/SDL.h>

class Blackjack : public Game {

	private:
		SDL_Surface* game_surface;
		void play_hand();

	public:
		Blackjack(SDL_Surface*);
		void run();

};

#endif
