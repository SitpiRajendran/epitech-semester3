/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GetUserHostName
*/

#ifndef __GETUSERHOSTNAME_HPP__
#define __GETUSERHOSTNAME_HPP__

#include <iostream>
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class GetUserName : public IMonitorDisplay, public IMonitorModule {
	public:
		GetUserName();
		~GetUserName() {};
		const std::string &getName() const {return _name;};
		const std::string &getValue() {return _value;};
		void refreshN() { this->_value = this->getValue(); };
		void displayN();
		sf::Text _text;
		int isDisped;
	private:
		std::string _name;
		std::string _value;
};

class GetHostName : public IMonitorDisplay, public IMonitorModule {
	public:
		GetHostName();
		~GetHostName() {};
		const std::string &getName() const {return _name;};
		const std::string &getValue() {return _value;};
		void refreshN() { this->_value = this->getValue(); };
		void displayN();
		int isDisped;
		sf::Text _text;
	private:
		std::string _name;
		std::string _value;
};

#endif