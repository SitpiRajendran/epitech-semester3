/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Sys
*/

#include "Sys.hpp"

Sys::Sys()
{
    this->_name = "System name and version";
    this->isDisped = 1;
    this->setSys();
}

Sys::~Sys()
{
}

const std::string &Sys::getName() const
{
    return (this->_name);
}

const std::string &Sys::getValue()
{
    return (this->_sysName);
}

void Sys::setSys()
{
    struct utsname *name = new utsname;
    uname(name);
    this->_sysName.append("Sysname : ");
    this->_sysName.append(name->sysname); 
    this->_sysName.append("\n");
    this->_sysName.append("Version : ");
    this->_sysName.append(name->release);
    this->_sysName.append("\n");
    delete name; 
}

void Sys::displayN() 
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, x, y);

    if (this->isDisped == 0)
        return;
    this->refreshN();
    mvprintw(0, 0, "%s", this->getValue().c_str());
}