#include "functions.h"
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

void display(int x_position,int y_position,int size,std::string display_string,SDL_Surface* game_surface) {

	TTF_Init();
	TTF_Font *font = NULL;
	SDL_Color text_color = {0,0,0};
	SDL_Color back_color = {0x00,0x84,0x00};
	SDL_Surface* text_surface = NULL;
	font = TTF_OpenFont("resources/fonts/FreeSerif.ttf",size);
	text_surface = TTF_RenderText_Shaded(font,display_string.c_str(),text_color,back_color);
	SDL_Rect text_position;
	text_position.x = x_position;
	text_position.y = y_position;
	SDL_BlitSurface(text_surface,NULL,game_surface, &text_position);

}

