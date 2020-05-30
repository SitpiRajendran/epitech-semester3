/*
** EPITECH PROJECT, 2020
** CPP_rush3_2019
** File description:
** main
*/

#include <iostream>
#include <cstdlib>
#include "GetUserHostName.hpp"
#include "date.hpp"
#include "graphical.hpp"
#include <ncurses.h>
#include <curses.h>
#include "date.hpp"
#include "Sys.hpp"
#include "CoreModel.hpp"
#include "NWindow.hpp"
#include "ram.hpp"
#include "Frequency.hpp"
#include "swap.hpp"
#include "cpu.hpp"
#include "IsDisped.hpp"
#include "network.hpp"


void print_delemRam()
{
    int x = 0;
    int y = 0;
    int i = 0;
    int e = 0;

    getmaxyx(stdscr, y, x);
    i = x / 3;
    e = i * 2;
    attron(COLOR_PAIR(2));
    for (i; i < e; i++) {
        mvprintw(6, i, "-");
    }
    attroff(COLOR_PAIR(2));
    printw("\n");
}

void print_delemCPU()
{
    int x = 0;
    int y = 0;
    int i = 0;
    int e = 0;

    getmaxyx(stdscr, y, x);
    i = x / 3;
    e = i * 2;
    attron(COLOR_PAIR(2));
    for (i; i < e; i++) {
        mvprintw(24, i, "-");
    }
    attroff(COLOR_PAIR(2));
    printw("\n");
}

void dispNcurse(IsDisped disp)
{
    NWindow window;
    Time t;
    GetHostName h;
    GetUserName u;
    Sys a;
    Ram ram;
    Swap swap;
    CoreModel core;
    Frequency freq;
    Cpu cpu;
    network net;
    int i = 0;
    char key = 0;

    noecho();
    t.isDisped = disp.date;
    h.isDisped = disp.Hostname;
    u.isDisped = disp.UserName;
    a.isDisped = disp.sys;
    ram.isDisped = disp.ram;
    swap.isDisped = disp.swap;
    core.isDisped = disp.CoreModel;
    freq.isDisped = disp.frequency;
    cpu.isDisped = disp.cpu;
    window.addModule(a, a);
    window.addModule(h, h);
    window.addModule(u, u);
    window.addModule(t, t);
    window.addModule(ram, ram);
    window.addModule(swap, swap);
    window.addModule(core, core);
    window.addModule(freq, freq);
    window.addModule(cpu, cpu);

    std::vector<IMonitorDisplay *>::iterator it = window._display.begin();
    timeout(50);
    while (1)
    {
        clear(); 
        while (it != window._display.end()) {
            (*it)->displayN();
            if (it == window._display.begin() + 3)
                print_delemRam();
            if (it == window._display.begin() + 4)
                print_delemCPU();
            it++;
        }
        it = window._display.begin();
        refresh();
        key = getch();
        if (key == 'p')
            break;
    }
}

static int display_usage(char *name)
{
    std::cout << "USAGE:\n          " << name << " OPTION" << std::endl;
    std::cout << "\nOPTION:\n          text\n          graphical" << std::endl;
    return (0);
}

static int check_env(void)
{
    char *display = std::getenv("DISPLAY");

    if (display == NULL)
    {
        std::cerr << "DISPLAY not exist" << std::endl;
        return (84);
    }
    return (load_gi_and_data());
}

static int launch_text(char **av)
{
    IsDisped disp;
    disp.date = 1;
    disp.Hostname = 1;
    disp.UserName = 1;
    disp.sys = 1;
    disp.ram = 1;
    disp.swap = 1;
    disp.CoreModel = 1;
    disp.frequency = 1;
    disp.cpu = 1;
    disp.Parse(av);
    printf("%d\n", disp.swap);
    dispNcurse(disp);
    return (0);
}

static int check_arguments(int ac, char **av)
{
    std::string type;
    if (ac < 2)
        return (display_usage(av[0]));
    type = av[1];
    if (type.compare("text") == 0)
        return (launch_text(av));
    else if (type.compare("graphical") == 0)
        return (check_env());
    return (display_usage(av[0]));
}

int main(int ac, char **av)
{
    return (check_arguments(ac, av));
}