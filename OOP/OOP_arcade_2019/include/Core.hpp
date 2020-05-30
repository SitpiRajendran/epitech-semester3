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
namespace arcade {
    class Core {
        public:
            Core(int a);
            ~Core();
            std::string getLib(_graph gr);
            _games getGame();
            _graph getPath();
            void setLib(_graph gr);
            void setGame(_games ga);
        private:
            std::map<_graph, std::string> _libs;
            _graph _currentlib;
            _games _currentgame;
    };
};
#endif /* !CORE_HPP_ */