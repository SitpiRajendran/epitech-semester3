/*
** EPITECH PROJECT, 2020
** TonyPart
** File description:
** MapHandler
*/

#ifndef MAPHANDLER_HPP_
#define MAPHANDLER_HPP_

#include <vector>
#include <memory>
#include "Wall.hpp"
#include "Power.hpp"
#include "MyPerso.hpp"

namespace indie {
    class MyPerso;

    class MapHandler
    {
        public:
            MapHandler(irrManager_t manager, std::vector<std::string> mapA, int nbPlayer);
            ~MapHandler();
            void initCollision(std::vector<std::shared_ptr<MyPerso>> PlayerPerso,
                std::vector<std::shared_ptr<MyPerso>> bot);
            void removeBlock(int i);
            int getMapSize() const;
            int getGroudSize() const;
            int getPowerUpSize() const;
            shared_ptr<indie::Wall> getWall(int i);
            shared_ptr<indie::Wall> getGround(int i);
            shared_ptr<indie::Power> getPowerUp(int i);
            std::vector<std::string> getStringMap();
            void addPowerUp(int i, irrManager_t manager);
            void removePowerUp(int j);

        private:
            ISceneManager *cp_smgr;
            std::vector<std::string> stringMap;
            std::vector<shared_ptr<indie::Wall>> map;
            std::vector<shared_ptr<indie::Wall>> ground;
            std::vector<shared_ptr<indie::Power>> powerUp;
    };
}

#endif /* !MAPHANDLER_HPP_ */
