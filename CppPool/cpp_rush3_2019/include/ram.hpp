/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** date
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "sys/types.h"
#include "sys/sysinfo.h"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"

class Ram : public IMonitorModule, public IMonitorDisplay {
    public:
        Ram() : _name("Ram"), isDisped(1) {};
        ~Ram() {};
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

class usedRam : public IMonitorModule {
    public:
        usedRam() : _name("Used Ram"), isDisped(1) {};
        ~usedRam() {};
        const std::string &getName() const {return _name;};
        const std::string &getValue();
        int isDisped;
    protected:
        std::string _name;
        std::string _value;
};

std::string getOnFile(std::string filenam, std::string search);

#endif /* !RAM_HPP_ */
