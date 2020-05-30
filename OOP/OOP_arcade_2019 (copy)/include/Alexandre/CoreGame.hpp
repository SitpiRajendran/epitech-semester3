/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CoreGame
*/

#ifndef COREGAME_HPP_
#define COREGAME_HPP_

#include "Element.hpp"

typedef struct CoreGame_s {
    std::vector<std::string> map;
    arcade::Element map_style;
    std::vector<arcade::Element> allElements;
    std::string name;

    bool end;
    bool pause;
    bool restart;
    int score;
} CoreGame_t;

namespace arcade
{
    enum Input
    {
        NOTHING = -2,
        QUIT,
        PAUSE,
        RESTART,
        NEXT_LIB,
        PREV_LIB,
        NEXT_GAME,
        PREV_GAME,
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
}

#endif /* !COREGAME_HPP_ */