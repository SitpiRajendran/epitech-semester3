/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** Wall
*/

#ifndef WALL_HPP_
#define WALL_HPP_


#include <iostream>
#include <vector>
#include "manager.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace indie {
    class Wall {
        public:
            Wall(const char *path, const vector3df &pos,
                irrManager_t manager, int nbPlayer, int canBeDestroyed);
            ~Wall();
            void setPosWall(const int _x, const int _y);
            IMeshSceneNode *getNode();
            std::vector<ISceneNodeAnimator *> getAllAnimator();
            ISceneNodeAnimator *getAnimator();
            std::vector<int> getPosWall();
            void animDrop();
            int getDestroyable();

        protected:
        private:
            IMeshSceneNode *block;
            std::vector<ISceneNodeAnimator *> animList;
            ITriangleSelector *blockSelec;
            int canBeDestroyed;
            int it;
            int x;
            int y;
    };
}

#endif /* !WALL_HPP_ */
