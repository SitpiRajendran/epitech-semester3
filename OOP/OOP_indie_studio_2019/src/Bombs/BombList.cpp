/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** BombList
*/

#include "BombList.hpp"

indie::BombList::BombList()
{
}

indie::BombList::~BombList()
{
}

void indie::BombList::addBomb(irrManager_t manager, const vector3df &pos,
    std::string poserName, int playerNb, float range)
{
    try {
        shared_ptr<Bomb> Bomb = make_shared<indie::Bomb>("resources/bomb/bomb.obj", pos, manager, playerNb, range);
        bombList.push_back(Bomb);
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Bomb"));
    }
    bombList[bombList.size() - 1]->setPoserName(poserName);
    collideToAll = 0;
    for (int i = 0; i < playerNb; i++)
        to_check.push_back(false);
}

ISceneNodeAnimator *indie::BombList::getAnimator(int i)
{
    return (bombList[i]->getAnimator());
}

int indie::BombList::getBombListSize()
{
    return (bombList.size());
}

int indie::BombList::getCheckSize()
{
    return (to_check.size());
}

ISceneNode *indie::BombList::getBomb(int i)
{
    return (bombList[i]->getNode());
}

ITriangleSelector *indie::BombList::getSelec(int i)
{
    return (bombList[i]->getSelec());
}

void indie::BombList::addAnim(ISceneNodeAnimator *anim, int i)
{
    bombList[i]->addAnim(anim);
}

void indie::BombList::checked()
{
    if (to_check.empty() == false)
        to_check.erase(to_check.begin());
}

void indie::BombList::dropBomb(int i)
{
    bombList[i]->animDrop();
}

std::vector<ISceneNodeAnimator *> indie::BombList::getAllAnimator(int i)
{
    return (bombList[i]->getAllAnimator());
}

void indie::BombList::checkExplosion(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler,
        std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot, WindowHandler &win)
{
    for (int i = 0; i < bombList.size(); i++) {
        if (bombList[i]->checkExplosion(manager, MapHandler, Player, Bot, win) == 1) {
            bombList.erase(bombList.begin() + i);
        }
    }
}

void indie::BombList::explosionEffect(indie::irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot)
{
    for (int i = 0; i < bombList.size(); i++)
        bombList[i]->explosionEffect(manager, MapHandler, Player, Bot);
}

void indie::BombList::laserEffect(irrManager_t manager)
{
    for (int i = 0; i < bombList.size(); i++)
        bombList[i]->laserEffect(manager);
}

void indie::BombList::clearBomb()
{
    bombList.clear();
}