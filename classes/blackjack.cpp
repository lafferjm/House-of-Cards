#include "blackjack.h"
#include "card.h"
#include <iostream>
#include <SDL/SDL.h>
#include <vector>

using namespace std;

Blackjack::Blackjack(SDL_Surface* screen) {
	game_surface = screen; 
}

void Blackjack::run() {

	//Lets begin by shuffling the deck of cards	
	shuffle();
	
	//Now lets do the standard creation of variables and clearing of the screen
	SDL_WM_SetCaption("House Of Cards:Blackjack",NULL);
	SDL_FillRect(game_surface,&game_surface->clip_rect,0x008400);
	bool is_running = true;	
	SDL_Event event;
	
	//And update the display	
	SDL_Flip(game_surface);

	play_hand();	
	while(is_running) {	
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				is_running = false;	
		}
	}
}

void Blackjack::play_hand() {

	int x_position = 200;
	bool is_playing = true;
	
	vector<Card> player_card_vector;
	vector<Card> dealer_card_vector;

	Card drawn_card = draw();
	player_card_vector.push_back(drawn_card);
	drawn_card = draw();
	player_card_vector.push_back(drawn_card);


	for(int i = 0; i < player_card_vector.size(); i++) {
		
		if(i == 0) {
			player_card_vector.at(i).show(x_position,375,game_surface);
		} else {
			player_card_vector.at(i).show(x_position+(i*20),375,game_surface);	
		}
			
	}

	SDL_Flip(game_surface);

}
