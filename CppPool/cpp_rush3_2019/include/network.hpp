/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class network : public IMonitorModule, public IMonitorDisplay {
    public:
        network(): _name("Networking") {};
        ~network() {};
        const std::string &getName() const {return _name;};
        const std::string &getValue();
        void refreshN() { this->_value = this->getValue(); };
		void displayN();
        sf::Text _text;
    protected:
        std::string _name;
        std::string _value;
};


#endif /* !NETWORK_HPP_ */
