/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** date
*/

#ifndef DATE_HPP_
#define DATE_HPP_

#include <iostream>
#include <ncurses.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include <SFML/Graphics.hpp>

class Time : public IMonitorModule, public IMonitorDisplay {
    public:
        Time() : _name("Date and Time"), isDisped(1) {};
        ~Time() {};
        const std::string &getName() const {return _name;};
        const std::string &getValue();
        void refreshN() { this->_value = this->getValue(); };
        void displayN();
        sf::Text _text;
        int isDisped;
    protected:
        std::string _name;
        std::string _value;
};

#endif /* !DATE_HPP_ */
