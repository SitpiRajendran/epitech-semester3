/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GetUserHostName
*/

#include <cstdlib>
#include "GetUserHostName.hpp"

GetUserName::GetUserName() : _name("Username")
{
    this->isDisped = 1;
    if (std::getenv("USER") != NULL)
        this->_value = std::getenv("USER");
    else
        std::cerr << "USER not exist" << std::endl;
}

void GetUserName::displayN() 
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    if (this->isDisped == 0)
        return;
    this->refreshN();
    if (x > 42) {
        mvprintw(1, x - 42, "%s : %s", this->getName().c_str(), this->getValue().c_str());
    }
    this->refreshN();
}

GetHostName::GetHostName() : _name("HostName")
{
    this->isDisped = 1;
    if (std::getenv("HOSTNAME") != NULL)
        this->_value = std::getenv("HOSTNAME");
    else
        std::cerr << "HOSTUSER not exist" << std::endl;
}
void GetHostName::displayN() 
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    if (this->isDisped == 0)
        return;
    this->refreshN();
    if (x > 42) {
        mvprintw(2, x - 42, "%s : %s", this->getName().c_str(), this->getValue().c_str());
    }
    this->refreshN();
}