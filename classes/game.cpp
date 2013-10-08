#include <SDL/SDL.h>
#include <iostream>
#include "game.h"
#include "card.h"
#include <stdlib.h>

Game::Game() {

	/*
	  I am not using traditional number of 1-52 so I cannot populate in that
	  manner.
	  1-13 = clubs
	  21-33 = hearts
	  41-53 = spades
	  61-73 = diamonds
	*/

	int i = 1;
	for(int j = 0; j < 13; j++) {
		m_card_array[j] = i;
		i++;
	}
	
	i = 21;
	for(int j = 13;j < 26;j++) {
		m_card_array[j] = i;
		i++;
	}

	i = 41;
	for(int j = 26; j < 39; j++) {
		m_card_array[j] = i;
		i++;
	}

	i = 61;
	for(int j = 39; j < 52; j++) {
		m_card_array[j] = i;
		i++;
	}

	has_shuffled = false;
	cards_drawn = 0;
}

void Game::shuffle() {

	srand(time(NULL));
	int temp = 0;
	int j = 0;
	for(int i = 51; i >= 0; i--) {
		j = (rand() % 51);
		temp = m_card_array[i];
		m_card_array[i] = m_card_array[j];
		m_card_array[j] = temp;	
	}

	has_shuffled = true;
}

Card Game::draw() {
	
	if(!has_shuffled)
		shuffle();
	if(cards_drawn == 52) {
		cards_drawn = 0;
		shuffle();	
	}

	Card drawn_card(m_card_array[cards_drawn]);
	
	cards_drawn = cards_drawn + 1;
	
	return drawn_card;		
}
