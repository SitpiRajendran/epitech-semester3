/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** network
*/

#include "network.hpp"

const std::string &network::getValue()
{
    std::filebuf* pbuf;
    std::string line;
    std::ifstream ifs("/proc/net/dev");
    _value = "";

    if (ifs.is_open()) {
        while (!ifs.eof()) {
            getline(ifs, line);
            _value += "\n" + line;
        }
        ifs.close();
    }
    return _value;
}

void network::displayN()
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    this->refreshN();
    printw("%s : ", this->getValue().c_str());
}