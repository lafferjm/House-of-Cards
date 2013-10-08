#include "poker.h"
#include "card.h"
#include "button.h"
#include "chip.h"
#include <iostream>
#include <vector>
#include <SDL/SDL.h>
#include "../functions.h"
#include <algorithm>

using namespace std;

Poker::Poker(SDL_Surface* screen) {
	game_surface = screen;
}

void Poker::run() {
	
	bool redraw = true;	
	int x_position = 175;
	bool is_running = true;
	int mouse_x = 0;
	int mouse_y = 0;
	vector<Card> player_card_vector;
	SDL_Event event;
	SDL_Rect clicked_rect;
	string chips_bet = "";
	string number_of_chips = "";

	//So that we know if the color needs to be inverted
	bool button_1_clicked = false;
	bool button_2_clicked = false;
	bool button_3_clicked = false;
	bool button_4_clicked = false;
	bool button_5_clicked = false;

	Card drawn_card = draw();

	clicked_rect.w = 26;
	clicked_rect.h = 5;
	
	//First we need to shuffle the deck of cards
	shuffle();
	
	//Now we initialize variables	
	SDL_WM_SetCaption("House Of Cards:Poker", NULL);
	SDL_FillRect(game_surface,&game_surface->clip_rect,0x008400);

	//Update the screen
	SDL_Flip(game_surface);


	//We need five buttons, one for each card
	Button hold_button_1(175,300,76,30);
	Button hold_button_2(255,300,76,30);
	Button hold_button_3(335,300,76,30);
	Button hold_button_4(415,300,76,30);
	Button hold_button_5(495,300,76,30);

	//Lets apply the image to each button
	string resource_string = "resources/images/poker/hold_button.png";
	hold_button_1.apply_image(resource_string);
	hold_button_2.apply_image(resource_string);
	hold_button_3.apply_image(resource_string);
	hold_button_4.apply_image(resource_string);
	hold_button_5.apply_image(resource_string);

	//And now we show the buttons
	//Lets draw our deal button
	Button deal_button(0,400,150,30);
	deal_button.apply_image("resources/images/poker/deal_button.png");

	//Display the bet button
	Button bet_1_button(160,400,150,300);
	bet_1_button.apply_image("resources/images/poker/bet_1_button.png");

	//Display the bet max button
	Button bet_max_button(320,400,150,30);
	bet_max_button.apply_image("resources/images/poker/bet_max_button.png");
	
	//Display the reset button
	Button reset_bet_button(480,400,150,30);
	reset_bet_button.apply_image("resources/images/poker/reset_button.png");

	clicked_rect.y = 323;

	while(is_running) {

		if(redraw) {
			
			button_1_clicked = false;
			button_2_clicked = false;
			button_3_clicked = false;
			button_4_clicked = false;
			button_5_clicked = false;
			
			//Display the number of chips bet
			chips_bet = "Chips Bet: " + chips.get_bet_chip_string(); 	
			display(350,450,24,chips_bet,game_surface);
			//Display our chips
			number_of_chips = "Chip Count: " + chips.get_chip_string();
			display(0,450,24,number_of_chips,game_surface);	
			
			bet_max_button.show(game_surface);
			bet_1_button.show(game_surface);
			deal_button.show(game_surface);
			
			hold_button_1.show(game_surface);
			hold_button_2.show(game_surface);
			hold_button_3.show(game_surface);
			hold_button_4.show(game_surface);
			hold_button_5.show(game_surface);

			reset_bet_button.show(game_surface);

			player_card_vector.clear();	
		
			for(int i = 0; i < 5; ++i) {
				drawn_card = draw();		
				player_card_vector.push_back(drawn_card);
			}

			//Lets place the cards on the screen
			for(int i = 0; i < player_card_vector.size(); ++i) {
				player_card_vector.at(i).show(x_position+(i*80),200,game_surface);	
			}
			
			redraw = false;
			SDL_Flip(game_surface);
				
		}
		
		while(SDL_PollEvent(&event)) {
		
			if(event.type == SDL_QUIT) {
				is_running = false;
				chips.save_chips();
			}
			
			if(event.type == SDL_MOUSEBUTTONDOWN) {
			
				if(event.button.button == SDL_BUTTON_LEFT) {
				
					mouse_x = event.button.x;
					mouse_y = event.button.y;
					
					
					
					//Code block for the hold buttons being clicked
					if(hold_button_1.is_clicked(mouse_x,mouse_y)) {
					
						clicked_rect.x = 200;
						
						if(button_1_clicked) {
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_1_clicked = false;
						} else {
							SDL_FillRect(game_surface,&clicked_rect,0xb09517);
							button_1_clicked = true;
						}
						
						SDL_Flip(game_surface);
					}

					if(hold_button_2.is_clicked(mouse_x,mouse_y)) {
						
						clicked_rect.x = 280;

						if(button_2_clicked) {
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_2_clicked = false;
						} else {
							SDL_FillRect(game_surface,&clicked_rect,0xb09517);
							button_2_clicked = true;
						}
						
						SDL_Flip(game_surface);
							
					}

					if(hold_button_3.is_clicked(mouse_x,mouse_y)) {
						
						clicked_rect.x = 360;
					
						if(button_3_clicked) {
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_3_clicked = false;
						} else {
							SDL_FillRect(game_surface,&clicked_rect,0xb09517);
							button_3_clicked = true;
						}
						
						SDL_Flip(game_surface);	
					
					}

					if(hold_button_4.is_clicked(mouse_x,mouse_y)) {
						
						clicked_rect.x = 440;
						
						if(button_4_clicked) {
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_4_clicked = false;
						} else {
							SDL_FillRect(game_surface,&clicked_rect,0xb09517);
							button_4_clicked = true;
						}
						
						SDL_Flip(game_surface);
							
					}

					if(hold_button_5.is_clicked(mouse_x,mouse_y)) {
						
						clicked_rect.x = 520;
						
						if(button_5_clicked) {
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_5_clicked = false;
						} else {
							SDL_FillRect(game_surface,&clicked_rect,0xb09517);
							button_5_clicked = true;
						}

						SDL_Flip(game_surface);
					
					}
					
					//Code for dealing with the deal button being clicked
					if(deal_button.is_clicked(mouse_x,mouse_y)) {
					
						int won_amount = -1;
							
						if(!button_1_clicked) {
							drawn_card = draw();
							player_card_vector[0] = drawn_card;	
							player_card_vector.at(0).show(175,200,game_surface);	
						
							clicked_rect.x = 200;		
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_1_clicked = false;	
						}
						
						if(!button_2_clicked) {
							drawn_card = draw();
							player_card_vector[1] = drawn_card;
							player_card_vector.at(1).show(255,200,game_surface);
					
							clicked_rect.x = 280;	
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_2_clicked = false;
						}
						
						if(!button_3_clicked) {
							drawn_card = draw();
							player_card_vector[2] = drawn_card;
							player_card_vector.at(2).show(335,200,game_surface);
				
							clicked_rect.x = 360;	
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_3_clicked = false;	
						}
						
						if(!button_4_clicked) {
							drawn_card = draw();
							player_card_vector[3] = drawn_card;
							player_card_vector.at(3).show(415,200,game_surface);
			
							clicked_rect.x = 440;	
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_4_clicked = false;
						}
						
						if(!button_5_clicked) {
							drawn_card = draw();
							player_card_vector[4] = drawn_card;
							player_card_vector.at(4).show(495,200,game_surface);
							
							clicked_rect.x = 520;	
							SDL_FillRect(game_surface,&clicked_rect,0xbd0404);
							button_5_clicked = false;
						}

						SDL_Flip(game_surface);	
						
						//Now we need to figure out if the hand is a winning hand
						won_amount = determine_hand(player_card_vector);
						if(won_amount == 0) {
							chips.sub_chips(chips.get_bet_chip());
							display(250,0,24,"Sorry you did not win.",game_surface);
							SDL_Flip(game_surface);
							SDL_Delay(2000);
							display(250,0,24,"                                     ",game_surface);
						} else {
							chips.add_chips(chips.get_bet_chip()*won_amount);
							display(250,0,24,"You Won!!!",game_surface);
							SDL_Flip(game_surface);
							SDL_Delay(2000);
							display(250,0,24,"                          ",game_surface);
						}
						
						//To lazy to figure out the real way so ill just write spaces
						//instead of erasing	
						number_of_chips = "Chip Count:                            ";
						display(0,450,24,number_of_chips,game_surface);	
						number_of_chips = "Chip Count: " + chips.get_chip_string();
						display(0,450,24,number_of_chips,game_surface);	
						SDL_Flip(game_surface);

						redraw = true;

					}

					//Now we need to deal with the pressing of the bet buttons
					if(bet_1_button.is_clicked(mouse_x, mouse_y)) {
						chips.bet(1);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);
						SDL_Flip(game_surface);	
					}
					if(bet_max_button.is_clicked(mouse_x, mouse_y)) {
						chips.bet(5);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);
						SDL_Flip(game_surface);
					}
					if(reset_bet_button.is_clicked(mouse_x, mouse_y)) {
						chips.bet(-1);
						chips_bet = "Chips Bet: " + chips.get_bet_chip_string();
						display(350,450,24,chips_bet,game_surface);	
						SDL_Flip(game_surface);
					}
				}
			}

		}
	}
}

int Poker::determine_hand(vector<Card>& player_card_vector) {

	int temp[13];
	int temp_value = 0;
	vector<int> results_vector;
	bool has_same_suit = false;
	string suit1 = "";
	string suit2 = "";
	string suit3 = "";
	string suit4 = "";
	string suit5 = "";

	suit1 = player_card_vector.at(0).get_suit();
	suit2 = player_card_vector.at(1).get_suit();
	suit3 = player_card_vector.at(2).get_suit();
	suit4 = player_card_vector.at(3).get_suit();
	suit5 = player_card_vector.at(4).get_suit();

	//First lets determine if there is some sort of flush
	if(suit1 == suit2 && suit1 == suit3 && suit1 == suit4 && suit1 == suit5)
		has_same_suit = true;
	
	//Initialize the temp array to all 0's
	for(int i = 0; i < 13; ++i) {
		temp[i] = 0;	
	}

	//Lets get a total count of the cards that are the same.	
	for(int i = 0; i <  5; ++i) {
		temp_value = player_card_vector.at(i).get_value() - 1;
		temp[temp_value] = temp[temp_value] + 1;
	}

	//Now to see how many unique values we have lets push the non zero
	//Values onto the vector
	for(int i = 0; i < 13; ++i) {
		if(temp[i] != 0)
			results_vector.push_back(temp[i]);	
	}
	
	//If size is 5 then the only possible result is a straight
	//So we must sort the array and make sure they are in ascending order
	if(results_vector.size() == 5) {
		
		//Lets assume it is a straight and prove otherwise	
		bool is_straight = true;
		vector<int> card_values;
		
		for(int i = 0; i < player_card_vector.size(); ++i)
			card_values.push_back(player_card_vector.at(i).get_value());
		sort(card_values.begin(),card_values.end());
		for(int i = 0; i < card_values.size() - 1; ++i) {
			if(card_values.at(i+1) == (card_values.at(i) + 1)) {
				continue;
			} else {
				is_straight = false;
				break;
			}
		}
		
		if(has_same_suit && is_straight)
			return 50;
		else if(is_straight)
			return 4;
	}

	//If size is 4, then we have a pair.  In my game one pair will be considered
	//The same as a jacks or better victory.
	if(results_vector.size() == 4) {
		vector<int> card_values;
		for(int i = 0; i < player_card_vector.size();++i)
			card_values.push_back(player_card_vector.at(i).get_value());
		return 1;	
	}

	//If size is 3, then we have two pair or a three of a kind
	if(results_vector.size() == 3) {
		//If we have a three of a kind
		if(results_vector.at(0) == 3 || results_vector.at(1) == 3 || results_vector.at(2) == 3)
			return 3;	
		//Otherwise it is two pair	
		return 2;	
	}

	//If size is 2, then we have full house or four of a kind
	if(results_vector.size() == 2) {
		//If we have a full house
		if(results_vector.at(0) == 3 || results_vector.at(1) == 3)
			return 9;
		else //We have a four of a kind
			return 45; 			
	}
	
	//If we have just a flush
	if(has_same_suit)
		return 6;
	else //You didn't win anything
		return 0;
}
