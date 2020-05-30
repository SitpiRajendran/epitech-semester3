/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CoreModel
*/

#ifndef COREMODEL_HPP_
#define COREMODEL_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"


class CoreModel : public IMonitorModule, public IMonitorDisplay {
	public:
		CoreModel();
		~CoreModel();
        const std::string &getName() const;
        const std::string &getValue();
		void refreshN() { this->_model = this->getValue(); };
		void displayN();
        sf::Text _text;
		int isDisped;

	protected:
        std::string _name;
        std::string _model;

	private:
};

#endif /* !COREMODEL_HPP_ */
