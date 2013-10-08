#include "card.h"
#include <iostream>
#include <sstream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

Card::Card(int card_value) {

	m_suit = "";
	m_value = 0;
	m_card_image = NULL;
	std::string card_string;
	std::ostringstream sin;

	/*
	  Because of the image numbering, card values are not sequential, the
	  following shows which numbers belong to each suit.
	  1-13 = clubs
	  21-33 = hearts
	  41-53 = spades
	  61-73 = diamonds
	*/

	//The numbers 1-13 are fine for card values	
	if(card_value >= 1 && card_value <= 13) {
		m_value = card_value;
		m_suit = "clubs";		
	}

	//We need to convert the following range to numbers between 1 and 13
	//So we just subtract 20
	if(card_value >= 21 && card_value <= 33) {
		m_value = card_value - 20;
		m_suit = "hearts";	
	}

	//We need to convert the following range to numbers between 1 and 13
	//So we just subtract 40	
	if(card_value >= 41 && card_value <= 53) {
		m_value = card_value - 40;
		m_suit = "spades";	
	}

	//We need to convert the following range to numbers between 1 and 13
	//So we just subtract 60
	if(card_value >= 61 && card_value <= 73) {
		m_value = card_value - 60;
		m_suit = "diamonds";	
	}
	
	SDL_Surface* loaded_image = NULL;
	sin << card_value;
	card_string = sin.str();
	card_string = "resources/images/cards/" + card_string + ".png";
	loaded_image = IMG_Load(card_string.c_str());
	m_card_image = SDL_DisplayFormat(loaded_image);
	SDL_FreeSurface(loaded_image);
	
}

void Card::show(int x_position, int y_position,SDL_Surface* screen) {

	SDL_Rect offset;
	offset.x = x_position;
	offset.y = y_position;
	SDL_BlitSurface(m_card_image, NULL, screen, &offset);

}

std::string Card::get_suit() {
	return m_suit;
}

int Card::get_value() {
	return m_value;
}
