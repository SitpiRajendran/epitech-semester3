/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** date
*/

#include "date.hpp"

const std::string &Time::getValue()
{
    time_t date = time(0);
    std::string value(ctime(&date));
    _value = value;

    return _value;
}

void Time::displayN()
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    if (this->isDisped == 0)
        return;
    this->refreshN();
    if (x > 41) {
        mvprintw(0, x - 42, "%s : ", this->getName().c_str());
        printw("%s",  this->getValue().c_str());
    }
}