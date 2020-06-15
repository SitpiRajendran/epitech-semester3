/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** BombList
*/

#ifndef BOMBLIST_HPP_
#define BOMBLIST_HPP_

#include <vector>
#include "Bomb.hpp"
#include "WindowHandler.hpp"
//#include "manager.h"

namespace indie {
    class Bomb;
    class MyPerso;
    class WindowHandler;
    class MapHandler;

    class BombList {
        public:
            BombList();
            ~BombList();
            void addBomb(irrManager_t manager, const vector3df &pos,
                std::string poserName, int playerNb, float range);
            void removeBomb(int pos);
            int canPosBomb(std::string playerName);
            ISceneNodeAnimator *getAnimator(int i);
            ISceneNode *getBomb(int i);
            ITriangleSelector *getSelec(int i);
            int getBombListSize();
            int getCheckSize();
            std::vector<ISceneNodeAnimator *> getAllAnimator(int i);
            void addAnim(ISceneNodeAnimator *anim, int i);
            void dropBomb(int i);
            void checked();
            void checkExplosion(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot, WindowHandler &win);
            void explosionEffect(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot);
            void laserEffect(irrManager_t manager);
            void clearBomb();
            //int checkExplosion()

        protected:
        private:
            std::vector<shared_ptr<indie::Bomb>> bombList;
            std::vector<bool> to_check;
            int collideToAll;
    };
}

#endif /* !BOMBLIST_HPP_ */
