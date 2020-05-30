/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Sys
*/

#ifndef SYS_HPP_
#define SYS_HPP_

#include <iostream>
#include <memory>
#include <sys/utsname.h>
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Sys : public IMonitorModule, public IMonitorDisplay {
	public:
	Sys();
	~Sys();
        const std::string &getName() const;
        const std::string &getValue();
        void refreshN() { this->_sysName = this->getValue(); };
        void displayN();
        void setSys();
        sf::Text _text;
        int isDisped;
	protected:
        std::string _name;
        std::string _sysName;
	private:
};

#endif /* !SYS_HPP_ */
