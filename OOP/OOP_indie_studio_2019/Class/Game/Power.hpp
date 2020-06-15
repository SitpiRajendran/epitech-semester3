/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Power
*/

#ifndef POWER_HPP_
#define POWER_HPP_

#include <time.h>
#include "manager.h"

namespace indie
{
    class Power {
    public:
        Power(const char *path, const vector3df pos,
            irrManager_t manager, powerUp power);
        ~Power();
        void setTexture(irrManager_t manager, const char *path);
        IMeshSceneNode *getNode() const;
        indie::powerUp getPower() const;
        void remove();

    protected:
    private:
        IMeshSceneNode *powerUp;
        IMeshSceneNode *cubeColl;
        indie::powerUp type;
    };
} // namespace indie

#endif /* !POWER_HPP_ */
