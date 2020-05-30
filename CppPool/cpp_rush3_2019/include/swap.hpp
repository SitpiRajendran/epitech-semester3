/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** date
*/

#ifndef SWAP_HPP_
#define SWAP_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Swap : public IMonitorModule, public IMonitorDisplay {
    public:
        Swap() : _name("Swap"), isDisped(1) {};
        ~Swap() {};
        const std::string &getName() const {return _name;};
        const std::string &getValue();
        float getUsed() {return _used;};
        float getTotal() {return _total;};
        void refreshN() { this->_value = this->getValue(); };
		void displayN();
        sf::Text _text;
        sf::RectangleShape _shape;
        int isDisped;
    protected:
        std::string _name;
        std::string _value;
        float _used;
        float _total;
};

class usedSwap : public IMonitorModule {
    public:
        usedSwap() : _name("Used Swap"), isDisped(1) {};
        ~usedSwap() {};
        const std::string &getName() const {return _name;};
        const std::string &getValue();
        int isDisped;
    protected:
        std::string _name;
        std::string _value;
};

std::string getOnFile(std::string filenam, std::string search);

#endif /* !SWAP_HPP_ */
