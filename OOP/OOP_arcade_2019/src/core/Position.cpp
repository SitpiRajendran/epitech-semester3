/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Position
*/

#include "Position.hpp"

namespace arcade
{
    Position::Position(int x, int y)
    {
        _x = x;
        _y = y;
    }

    Position::Position()
    {
    }

    Position::~Position()
    {
    }

    void Position::operator=(const Position &pos) {
        _x = pos._x;
        _y = pos._y;
    }

    bool Position::operator==(const Position &pos){
        if (_x == pos._x && _y == pos._y)
            return true;
        return false;
    }

    void Position::setPosition(int x, int y) {
        _x = x;
        _y = y;
    }

    int Position::getPositionX() const {
        return _x;
    }

    int Position::getPositionY() const {
        return _y;
    }
}