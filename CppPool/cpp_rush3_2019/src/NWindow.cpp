/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NWindow
*/

#include <ncurses.h>
#include <vector>
#include "NWindow.hpp"
#include "GetUserHostName.hpp"
#include "date.hpp"
#include "graphical.hpp"
#include "date.hpp"
#include "Sys.hpp"
#include "CoreModel.hpp"
#include "ram.hpp"


NWindow::NWindow()
{
    initscr();
    getmaxyx(stdscr, _height, _lenght);
    clear();
    refresh();
    if (has_colors() == FALSE) {
        endwin();
        exit(1);
    }
    start_color();
    init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);    
}

NWindow::~NWindow()
{
    endwin();
}

int NWindow::getHeight() const
{
    return this->_height;
}
int NWindow::getLenght() const
{
    return this->_lenght;
}

const std::vector<IMonitorModule *> &NWindow::getModule() const
{
    return (this->_modules);
}
const std::vector<IMonitorDisplay *> &NWindow::getDisplay() const
{
    return (this->_display);
}

void NWindow::setHeight(int height)
{
    this->_height = height;
}
void NWindow::setLenght(int lenght)
{
    this->_lenght = lenght;
}

void NWindow::addModule(IMonitorModule &module, IMonitorDisplay &display)
{
    this->_modules.push_back(&module);
    this->_display.push_back(&display);
}

void NWindow::addAllModule()
{
    NWindow window;
    Time t;
    GetHostName h;
    GetUserName u;
    Sys a;
    CoreModel b;
    Ram ram;

    window.addModule(a, a);
    window.addModule(h, h);
    window.addModule(u, u);
    window.addModule(t, t);
    window.addModule(ram, ram);
}