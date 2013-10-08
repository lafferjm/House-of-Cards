#include "button.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>

Button::Button(int x_position, int y_position, int width, int height) {
	m_box.x = x_position;
	m_box.y = y_position;
	m_box.w = width;
	m_box.h = height;
	m_button_image = NULL;
}

Button::~Button() {
	SDL_FreeSurface(m_button_image);
}

bool Button::is_clicked(int x, int y) {
	int box_max_x = m_box.x + m_box.w;
	int box_max_y = m_box.y + m_box.h;

	if(x > m_box.x && x < box_max_x && y > m_box.y && y < box_max_y)
		return true;
	return false;

}

void Button::apply_image(std::string path) {

	SDL_Surface* loaded_image = NULL;
	loaded_image = IMG_Load(path.c_str());
	m_button_image = SDL_DisplayFormat(loaded_image);
	SDL_FreeSurface(loaded_image);

}

void Button::show(SDL_Surface* screen) {
	SDL_BlitSurface(m_button_image, NULL, screen, &m_box);
}
