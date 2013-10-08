#ifndef CHIP_H
#define CHIP_H

#include <string>

class Chip {

	private:
		long m_chip_count;
		long m_chip_bet;
	public:
		Chip();
		long get_chips();
		std::string get_chip_string();
		void add_chips(int);
		void sub_chips(int);
		void save_chips();
		void load_chips();
		std::string get_bet_chip_string();
		long get_bet_chip();
		void bet(int);
};

#endif
