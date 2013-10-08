#ifndef BUTTON_H
#define BUTTON_H

#include <SDL/SDL.h>
#include <string>

class Button {
	
	private:
		SDL_Rect m_box;
		SDL_Surface* m_button_image;
	
	public:
		Button(int, int, int, int);
		~Button();	
		void apply_image(std::string);	
		void show(SDL_Surface*);
		bool is_clicked(int,int);
};

#endif
