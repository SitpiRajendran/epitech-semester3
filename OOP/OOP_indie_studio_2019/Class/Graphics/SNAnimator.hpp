/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** SNAnimator
*/

#ifndef SNANIMATOR_HPP_
#define SNANIMATOR_HPP_

#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace indie {
    class SNAnimator {
        public:
            SNAnimator(ITriangleSelector *selector, IMeshSceneNode *node,
                vector3df radius, vector3df gravity, ISceneManager *smgr);
            ~SNAnimator();
            void animDrop();
            ISceneNodeAnimator *getAnim();
        protected:
        private:
            ISceneNodeAnimator *anim;
    };
}

#endif /* !SNANIMATOR_HPP_ */
