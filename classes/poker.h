#ifndef POKER_H
#define POKER_H

#include "game.h"
#include "card.h"
#include "chip.h"
#include <SDL/SDL.h>
#include <vector>

class Poker : public Game {

	private:
		Chip chips;	
		SDL_Surface* game_surface;
		int determine_hand(std::vector<Card>&);
			
	public:
		Poker(SDL_Surface*);	
		void run();
};

#endif
