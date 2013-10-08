#ifndef SLOTS_H
#define SLOTS_H

#include <SDL/SDL.h>

class Slots {

	private:
		SDL_Surface* game_surface;
	public:
		Slots(SDL_Surface*);
		void run();

};

#endif
