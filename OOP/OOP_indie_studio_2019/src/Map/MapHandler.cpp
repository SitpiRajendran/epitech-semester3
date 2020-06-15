/*
** EPITECH PROJECT, 2020
** TonyPart
** File description:
** MapHandler
*/

#include <iostream>
#include "MapHandler.hpp"

indie::MapHandler::MapHandler(indie::irrManager_t manager, std::vector<std::string> mapA, int nbPlayer)
{
    try {
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++) {
                if (mapA[i][j] == '#' || mapA[i][j] == 'C') {
                    if (mapA[i][j] == '#') {
                        map.push_back(make_shared<indie::Wall>("resources/cube/iron.png", vector3df(i * 3, -1, j * 3), manager, nbPlayer, 0));
                        map[map.size() - 1]->setPosWall(j, i);
                    }
                    else {
                        map.push_back(make_shared<indie::Wall>("resources/cube/wood.png", vector3df(i * 3, -1, j * 3), manager, nbPlayer, 1));
                        map[map.size() - 1]->setPosWall(j, i);
                    }
                }
            }
        }
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++)
                ground.push_back(make_shared<indie::Wall>("resources/cube/floor.png", vector3df(i * 3, -4, j * 3), manager, nbPlayer, 0));
        }
        cp_smgr = manager.smgr;
        stringMap = mapA;
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Wall"));
    }
}

indie::MapHandler::~MapHandler()
{
    map.clear();
    ground.clear();
    powerUp.clear();
}


void indie::MapHandler::initCollision(std::vector<std::shared_ptr<indie::MyPerso>> PlayerPerso, std::vector<std::shared_ptr<indie::MyPerso>> bot) {
    int mS = getMapSize();

    for (int i = 0; i < mS; i ++) {
        for (size_t j = 0; j < PlayerPerso.size(); j ++) {
            PlayerPerso[j]->addAnim(map[i]->getAnimator());
            map[i]->animDrop();
        } for (size_t j = 0; j < bot.size(); j ++) {
            bot[j]->addAnim(map[i]->getAnimator());
            map[i]->animDrop();
        }
    }
}

void indie::MapHandler::removeBlock(int i)
{
    std::vector<int> pos = map[i]->getPosWall();

    stringMap[pos[1]][pos[0]] = ' ';
    map.erase(map.begin() + i);
}

void indie::MapHandler::removePowerUp(int j)
{
    powerUp.erase(powerUp.begin() + j);
}

void indie::MapHandler::addPowerUp(int i, irrManager_t manager)
{
    int time = rand();

    try {
        if (time % 5 == 0) {
            powerUp.push_back(make_shared<indie::Power>("./resources/powerUp/estrellica.obj", map[i]->getNode()->getPosition(), manager, powerUp::SpeedUp));
            return;
        }
        if (time % 4 == 0) {
            powerUp.push_back(make_shared<indie::Power>("./resources/powerUp/Dynamite/dinamite.obj", map[i]->getNode()->getPosition(), manager, powerUp::BombUp));
            powerUp[powerUp.size() - 1]->setTexture(manager, "./resources/powerUp/Dynamite/D.png");
            return;
        }
        if (time % 3 == 0) {
            powerUp.push_back(make_shared<indie::Power>("./resources/powerUp/9mm.obj", map[i]->getNode()->getPosition(), manager, powerUp::FireUp));
            powerUp[powerUp.size() - 1]->setTexture(manager, "./resources/powerUp/9mm_texture.jpg");
            return;
        }
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Power"));
    }
}

shared_ptr<indie::Wall> indie::MapHandler::getWall(int i)
{
    return (map[i]);
}
shared_ptr<indie::Wall> indie::MapHandler::getGround(int i)
{
    return (ground[i]);
}

shared_ptr<indie::Power> indie::MapHandler::getPowerUp(int i)
{
    return (powerUp[i]);
}

int indie::MapHandler::getMapSize() const
{
    return (map.size());
}
int indie::MapHandler::getGroudSize() const
{
    return (ground.size());
}

int indie::MapHandler::getPowerUpSize() const
{
    return (powerUp.size());
}

std::vector<std::string> indie::MapHandler::getStringMap()
{
    return (stringMap);
}