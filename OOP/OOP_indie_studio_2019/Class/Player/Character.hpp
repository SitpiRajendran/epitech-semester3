/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <manager.h>
#include <cmath>

namespace indie {
    enum Movement {
        NoMove = 0,
        MoveUp = -1,
        MoveDown = 1,
        MoveLeft = -2,
        MoveRight = 2,
    };
    class Character {
        public:
            Character(IAnimatedMeshSceneNode *_node, vector3df move);
            Character &operator=(const Character &to_cmp);
            ~Character();

            IAnimatedMeshSceneNode *getNode();
            void addAnimator(ISceneNodeAnimator *anim);
            void dropAnim();
            ISceneNodeAnimator *getAnim();
            void updatePosRot();
            void animUp();
            void animDown();
            void animLeft();
            void animRight();
            void bombPos();
            void reInitAnim();
            void reInitBombPos();
            int getDead() const;
            void setDead();
            void setNewMov(core::vector3df mov);

        protected:
        private:
            IAnimatedMeshSceneNode *node;
            vector3df move;
            irr::core::matrix4 Mat;
            vector3df v;
            vector3df r;
            Movement mov;
            int isDead;

    };
}

#endif /* !CHARACTER_HPP_ */
