#ifndef CARD_H
#define CARD_H

#include <SDL/SDL.h>
#include <iostream>

class Card {

	private:
		std::string m_suit;
		int m_value;
		SDL_Surface* m_card_image;	
	public:
		Card(int);
		void show(int,int,SDL_Surface*);	
		std::string get_suit();
		int get_value();
		
};

#endif
