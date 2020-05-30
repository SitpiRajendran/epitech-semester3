/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <map>
#include <iostream>
#include <cstring>


#define SFML_LIB "./lib/lib_arcade_sfml.so"
#define NCURSES_LIB "./lib/lib_arcade_ncurses.so"
#define SDL_LIB "./lib/lib_arcade_sdl2.so"


class Core {
    public:
        Core(int a);
        ~Core();
    private:
        enum _graph {
            SFML,
            NCURSES,
            SDL,
            NOTHING
        };
        enum _games {
            MENU,
            SNAKE,
            CENTIPEDE,
            PAUSE,
            NONE
        };
        std::map<_graph, std::string> _libs;
        _graph _curentlib;
        _games _currentgame;
};
#endif /* !CORE_HPP_ */