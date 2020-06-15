/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** manager
*/

#ifndef MANAGER_H_
#define MANAGER_H_

#include <iostream>
#include "Exception.hpp"
#include <irrlicht.h>

using namespace std;
using namespace irr;
using namespace gui;
using namespace core;
using namespace scene;
using namespace video;

    namespace indie {
    enum EventParticular {
        Nothing = -2,
        Quit = -1,
        Pause = 0,
        BombPosP1 = 1,
        BombPosP2 = 2,
    };

    typedef struct irrManager_s {
        IVideoDriver* driver;
        ISceneManager* smgr;
        IrrlichtDevice *device;
    } irrManager_t;

    enum powerUp {
        FireUp = 0,
        BombUp = 1,
        WallPass = 2,
        SpeedUp = 3,
    };
    enum
    {
        // I use this ISceneNode ID to indicate a scene node that is
        // not pickable by getSceneNodeAndCollisionPointFromRay()
        ID_IsNotPickable = 0,
        // I use this flag in ISceneNode IDs to indicate that the
        // scene node can be picked by ray selection.
        IDFlag_IsPickable = 1 << 0,
        // I use this flag in ISceneNode IDs to indicate that the
        // scene node can be highlighted.  In this example, the
        // homonids can be highlighted, but the level mesh can't.
        IDFlag_IsHighlightable = 1 << 1
    };
}

#endif /* !MANAGER_H_ */
