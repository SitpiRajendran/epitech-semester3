/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** MyPerso
*/

#ifndef MYPERSO_HPP_
#define MYPERSO_HPP_

#include <iostream>
#include <memory>
#include "MyEventReceiver.hpp"
#include "SNAnimator.hpp"
#include "Character.hpp"
#include "BombList.hpp"
#include "Stat.hpp"
#include "MapHandler.hpp"

namespace indie {
    class BombList;
    class MapHandler;

    class MyPerso {
        public:
            MyPerso(char const *path, const  core::vector3df &scale, const core::vector3df &pos,
                const float &animation, irrManager_t manager, char const *colorPath);
            ~MyPerso();

            std::string getName() const;
            core::vector3df getPersoPos() const;
            IAnimatedMeshSceneNode *getNode();
            int addCollision(BombList *list);
            void addAnim(ISceneNodeAnimator *anim);
            void remAnim(ISceneNodeAnimator *anim);
            void setName(const std::string &_name);
            std::shared_ptr<Character> getCharacter();
            core::list<ISceneNodeAnimator*> getAllAnimator();
            void removeBombAnim(std::vector<ISceneNodeAnimator *> animBomb);
            bool ifAnimatorAlreadyAssigned(std::vector<ISceneNodeAnimator *> list);
            void putBomb();
            void remBomb();
            int checkBomb() const;
            float getRange() const;
            int checkDead() const;
            void die(std::shared_ptr<indie::MapHandler> MapHandler);
            void powerUpEvent(indie::powerUp type);
            void savePerso();
            void loadStat(std::vector<std::string> stats);

        protected:
        private:
            std::shared_ptr<Character> animator;
            IAnimatedMeshSceneNode *node;
            ISceneManager *_smgr;
            ITriangleSelector *selec;
            std::string name;
            Stat powerUp;
            vector3df radius;
            int isDead;
    };
}

#endif /* !MYPERSO_HPP_ */
