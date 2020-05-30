/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** cpu
*/

#ifndef CPU_HPP_
#define CPU_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <sstream>
#include <list>
#include <vector>
#include <cstdlib>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "ram.hpp"

struct eachCPU
{
    int num;
    float _usage;
    float _total;
    std::string _percent;
    sf::Text _text;
};

class Cpu : public IMonitorModule, public IMonitorDisplay {
    public :
        Cpu();
        ~Cpu() {};
        const std::string &getName() const {return _name;};
        const std::string &getModel() const {return _model;};
        const std::string &getValue();
        const std::string &getPercent() const {return _percent;};
        float getUsage() {return _usage;};
        float getTotal() {return _total;};
        void setData();
        void getinfos(std::string);
        void getfirstline();
        void getAllCpu(int noc);
        void refreshN() {this->_value = this->getValue();};
        void displayN();
        std::vector<eachCPU> _list;
        int isDisped;
        sf::Text _text;
    protected:
        std::string _name;
        std::string _model;
        std::string _value;
        std::string _percent;
        float _usage;
        float _total;
};

eachCPU createEach(int i, std::string line);

#endif /* !CPU_HPP_ */
