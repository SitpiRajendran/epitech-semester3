/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(int a)
{
/*     _libs[SFML] = SFML_LIB;
    _libs[SDL] = SDL_LIB;
    _libs[NCURSES] = NCURSES_LIB; */
    _curentlib = (_graph)a;
    _currentgame = (_games)0;
}

Core::~Core()
{
}
