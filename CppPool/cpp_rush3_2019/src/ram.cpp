/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** ram
*/

#include <ncurses.h>
#include "ram.hpp"

std::string getOnFile(std::string filenam, std::string search)
{
    std::ifstream ifs("/proc/meminfo");
    std::string line;
    std::string gettingline;

    if (ifs.is_open() == false) {
        gettingline.append("Can't open cpuinfo\n");
        return gettingline;
    }
    while (!ifs.eof()) {
        getline(ifs, line);
        if (line.find(search.c_str()) != std::string::npos) {
            gettingline.assign(line.substr(search.size() + 1, line.size() -4));
            return gettingline;
        }
    }
    gettingline.append("Error\n");
    return gettingline;
}

const std::string &Ram::getValue()
{
    usedRam r;
    float f = std::stof(getOnFile("/proc/meminfo", "MemTotal:"));
    std::string str = std::to_string(f / 1048576);
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

const std::string &usedRam::getValue()
{
    float f = std::stof(getOnFile("/proc/meminfo", "MemAvailable:"));
    std::string str = std::to_string(f / 1048576);
    _value = str.substr(0, 4);
    return _value;
}

void Ram::displayN()
{
    int x = 0;
    int y = 0;
    int i = 0;
    int e = 0;
    getmaxyx(stdscr, y, x);

    if (this->isDisped == 0)
        return;
    std::string mem;
    std::string un;
    std::string end;

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
    mvprintw(8, 0, "######     #    #     # \n");
    printw("#     #   # #   ##   ##  \n");
    printw("#     #  #   #  # # # #  \n");
    printw("######  #     # #  #  #  \n");
    printw("#   #   ####### #     #  \n");
    printw("#    #  #     # #     #  \n");
    printw("#     # #     # #     #  \n");
    mvprintw(11, 29, "{", mem.c_str());
    attron(COLOR_PAIR(4));
    printw("%s", mem.c_str());
    attroff(COLOR_PAIR(4));
    printw("%s", un.c_str());
    printw("} ");
    printw("%s", end.c_str());
}