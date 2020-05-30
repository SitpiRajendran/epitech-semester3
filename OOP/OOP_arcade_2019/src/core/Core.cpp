/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

namespace arcade {
    Core::Core(int a)
    {
        _libs[SFML] = SFML_LIB;
        _libs[SDL] = SDL_LIB;
        _libs[NCURSES] = NCURSES_LIB;
        _currentlib = (_graph)a;
        _currentgame = (_games)0;
    }

    Core::~Core()
    {
    }

    std::string Core::getLib(_graph gr)
    {
        return this->_libs[gr];
    }

    _games Core::getGame()
    {
        return _currentgame;
    }

    _graph Core::getPath()
    {
        return _currentlib;
    }

    void Core::setLib(_graph gr)
    {
        _currentlib = gr;
    }

    void Core::setGame(_games ga)
    {
        _currentgame = ga;
    }
};
