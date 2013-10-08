#include "inbetween.h"
#include "card.h"
#include "../functions.h"
#include "button.h"
#include <SDL/SDL.h>
#include <iostream>

using namespace std;

Inbetween::Inbetween(SDL_Surface* screen) {
	game_surface = screen;
}

void Inbetween::run() {
	
	//First we need to shuffle the deck of cards
	shuffle();

	//Now we initialize variables
	SDL_WM_SetCaption("House Of Cards:Inbetween", NULL);
	SDL_FillRect(game_surface,&game_surface->clip_rect,0x008400);
	bool is_running = true;
	bool redraw = true;
	bool did_win = false;
	SDL_Event event;
	int mouse_x= 0;
	int mouse_y = 0;
	int won_amount = 0;
	int value_1 = 0;
	int value_2 = 0;
	int player_value = 0;
	string chips_bet = "";
	string number_of_chips = "";
	
	SDL_Rect card_erase_rect;
	card_erase_rect.w = 72;
	card_erase_rect.h = 96;
	card_erase_rect.x =  285;
	card_erase_rect.y = 250;
	

	Card drawn_card_1 = draw();
	Card drawn_card_2 = draw();
	Card player_card = draw();

	//Update the screen
	SDL_Flip(game_surface);

	//Lets begin by creating the button objects for the game
	Button deal_button(0,400,150,30);
	deal_button.apply_image("resources/images/inbetween/deal_button.png");
	Button bet_1_button(160,400,150,30);
	bet_1_button.apply_image("resources/images/inbetween/bet_1_button.png");
	Button bet_max_button(320,400,150,30);
	bet_max_button.apply_image("resources/images/inbetween/bet_max_button.png");
	Button reset_bet_button(480,400,150,30);
	reset_bet_button.apply_image("resources/images/poker/reset_button.png");	

	while(is_running) {
	
		if(redraw) {
			redraw = false;
			//Display our buttons	
			deal_button.show(game_surface);
			bet_1_button.show(game_surface);
			bet_max_button.show(game_surface);
			reset_bet_button.show(game_surface);
			
			//Display the number of chips bet	
			chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
			display(350,450,24,chips_bet,game_surface);
			
			//Display our chips
			number_of_chips = "Chip Count: " + chips.get_chip_string();
			display(0,450,24,number_of_chips,game_surface);

			//Display the two drawn cards
			drawn_card_1.show(135,125,game_surface);
			drawn_card_2.show(450,125,game_surface);

			SDL_Flip(game_surface);
		}
		
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				is_running = false;
				chips.save_chips();
			if(event.type == SDL_MOUSEBUTTONDOWN) {
				
				if(event.button.button == SDL_BUTTON_LEFT) {
					
					mouse_x = event.button.x;
					mouse_y = event.button.y;

					//Code block for the bet buttons being pressed
					if(bet_1_button.is_clicked(mouse_x,mouse_y)) {
						chips.bet(1);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);
						SDL_Flip(game_surface);	
					}
					if(bet_max_button.is_clicked(mouse_x,mouse_y)) {
						chips.bet(5);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);
						SDL_Flip(game_surface);	
					}
					if(reset_bet_button.is_clicked(mouse_x,mouse_y)) {
						chips.bet(-1);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);
						SDL_Flip(game_surface);
					}
					if(deal_button.is_clicked(mouse_x,mouse_y)) {
						won_amount = 0;	
							
						player_card.show(285,250,game_surface);	
						SDL_Flip(game_surface);

						//If the value of the cards are the same, and the player
						//gets a card that is the same they will get 3x their bet
						if(drawn_card_1.get_value() == drawn_card_2.get_value()) {
							if(player_card.get_value() == drawn_card_1.get_value()) {
								won_amount = chips.get_bet_chip();
								won_amount = won_amount * 3;
								chips.add_chips(won_amount);
								did_win = true;	
							} else {
								won_amount = chips.get_bet_chip();
								chips.sub_chips(won_amount);
								did_win  = false;
							}
						}

						//If the card is inbetween the two cards, lets return double
						//The bet.  Otherwise we just subtract the bet
						value_1 = drawn_card_1.get_value();
						value_2 = drawn_card_2.get_value();
						player_value = player_card.get_value();
						if(player_value > value_1 && player_value < value_2) {
							won_amount = chips.get_bet_chip();
							won_amount = won_amount * 2;
							chips.add_chips(won_amount);
							did_win = true;
						} else if(player_value < value_1 && player_value > value_2) {
							won_amount = chips.get_bet_chip();
							won_amount = won_amount * 2;
							chips.add_chips(won_amount);
							did_win = true;
						} else {
							won_amount = chips.get_bet_chip();
							chips.sub_chips(won_amount);
							did_win = false;	
						}

						//Now we display the message about whether or not the player
						//won, and delay for a bit.
						if(!did_win) {	
							display(250,0,24,"Sorry you did not win.",game_surface);
							SDL_Flip(game_surface);
							SDL_Delay(2000);
							display(250,0,24,"                                     ",game_surface);

						} else {
							display(250,0,24,"You Won!!!",game_surface);
							SDL_Flip(game_surface);
							SDL_Delay(2000);
							display(250,0,24,"                          ",game_surface);
						}

						//Because of the way redrawing works, lets reassign our cards here
						drawn_card_1 = draw();
						drawn_card_2 = draw();
						player_card = draw();

						//We also need to blit a green rectangle over the card so that it
						//Will appear to be erased
						SDL_FillRect(game_surface,&card_erase_rect,0x008400);	
							
						redraw = true;
						
					}
				
				}
			
			}
		}
	}

}
