/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** swap
*/

#include <ncurses.h>
#include "swap.hpp"
#include "ram.hpp"

const std::string &Swap::getValue()
{
    usedSwap r;
    float f = std::stof(getOnFile("/proc/meminfo", "SwapTotal:"));
    std::string str = std::to_string(f / 1024000);
    str = str.substr(0, 4);
    _used = std::stof(str) - std::stof(r.getValue());

    _total = std::stof(str);
    _value = "";

    _value.clear();
    _value += "{";
    for (int i = 0; i < 21; i += 1)
    {
        if ((i * 0.05) <= (_used / _total))
            _value += "#";
        else
            _value += "-";
    }
    _value += "} ";
    _value += std::to_string(_used).substr(0, 4) + " / " + std::to_string(_total).substr(0, 4);
    return _value;
}

const std::string &usedSwap::getValue()
{
    float f = std::stof(getOnFile("/proc/meminfo", "SwapFree:"));
    std::string str = std::to_string(f / 1024000);
    _value = str.substr(0, 4);
    return _value;
}

void Swap::displayN()
{
    int x = 0;
    int y = 0;
    int i = 0;
    int e = 0;
    getmaxyx(stdscr, y, x);

    std::string mem;
    std::string un;
    std::string end;

    if (this->isDisped == 0)
        return;
    this->refreshN();
    for (int j = 0; j != this->_value.size(); j++)
    {
        if (this->_value[j] == '#')
            i = j;
        if (this->_value[j] == '}') {
            e = j;
        }
    }
    mem = this->_value.substr(1, i);
    un = this->_value.substr(i + 1, e - i - 1);
    end = this->_value.substr(e + 1, this->_value.size());
    mvprintw(16, 0, " ######  ##      ##    ###    ######## \n");
    printw("##    ## ##  ##  ##   ## ##   ##     ## \n");
    printw("##       ##  ##  ##  ##   ##  ##     ##  \n");
    printw(" ######  ##  ##  ## ##     ## ######## \n");
    printw("      ## ##  ##  ## ######### ##       \n");
    printw("##    ## ##  ##  ## ##     ## ##        \n");
    printw(" ######   ###  ###  ##     ## ##        \n");
    mvprintw(19, 45, "{", mem.c_str());
    attron(COLOR_PAIR(4));
    printw("%s", mem.c_str());
    attroff(COLOR_PAIR(4));
    printw("%s", un.c_str());
    printw("} ");
    printw("%s", end.c_str());
}