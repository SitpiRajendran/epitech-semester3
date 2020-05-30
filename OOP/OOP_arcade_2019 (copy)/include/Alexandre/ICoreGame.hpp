/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ICoreGame
*/

#ifndef ICOREGAME_HPP_
#define ICOREGAME_HPP_

#include "CoreGame.hpp"

namespace arcade
{
class ICoreGame {
    public:
        virtual ~ICoreGame() = default;

        virtual void SendInput(Input &input) = 0;
        virtual void restartGame() = 0;
        virtual CoreGame_t *getData() = 0;

    protected:

    private:
};
} // namespace arcade

#endif /* !ICOREGAME_HPP_ */
