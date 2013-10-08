#include "chip.h"
#include <fstream>
#include <sstream>
#include <string>

Chip::Chip() {
	load_chips();
	m_chip_bet = 1;
}

long Chip::get_chips() {

	return m_chip_count;

}

std::string Chip::get_chip_string() {

	std::stringstream chip_stream;
	chip_stream << m_chip_count;
	return chip_stream.str();
}

void Chip::add_chips(int chips) {

	m_chip_count = m_chip_count + chips;
}

void Chip::sub_chips(int chips) {
	
	m_chip_count = m_chip_count - chips;

}

void Chip::save_chips() {

	std::ofstream chip_file("saved_chips.txt");
	if(chip_file.is_open())
		chip_file << m_chip_count;
}

void Chip::load_chips() {
	std::ifstream chip_file("saved_chips.txt");
	if(chip_file.is_open())
		chip_file >> m_chip_count;
	else
		m_chip_count = 1000;
}

long Chip::get_bet_chip() {
	return m_chip_bet;
}

std::string Chip::get_bet_chip_string() {
	
	std::stringstream chip_stream;
	chip_stream << m_chip_bet;
	return chip_stream.str();

}

void Chip::bet(int bet_amount) {
	//If the amount bet is negative it should only be because of me
	//And it will be, because the reset button was pushed	
	if(bet_amount == -1) {
		m_chip_bet = 1;	
	} else if(bet_amount == 5) {
		m_chip_bet = 5;
	} else if(bet_amount + m_chip_bet > 5) {
		m_chip_bet = m_chip_bet + 0;	
	} else {
		m_chip_bet = m_chip_bet + bet_amount;	
	}
	
}
