/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Frequency
*/

#ifndef FREQUENCY_HPP_
#define FREQUENCY_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "CoreModel.hpp"

class Frequency : public IMonitorDisplay, public IMonitorModule{
	public:
		Frequency();
		~Frequency();
        const std::string &getName() const;
        const std::string &getValue();
		void refreshN() { this->_frequency = this->getValue(); };
		void displayN();
        sf::Text _text;
		int isDisped;

	protected:
        std::string _name;
        std::string _frequency;
	private:
};

#endif /* !FREQUENCY_HPP_ */
