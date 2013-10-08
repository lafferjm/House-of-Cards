#ifndef GAME_H
#define GAME_H

#include "card.h"

class Game {

	private:
		bool has_shuffled;
		int cards_drawn;
	protected:
		int m_card_array[52];
		void shuffle();
		Card draw();

	public:
		Game();
		virtual void run() = 0;
};

#endif
