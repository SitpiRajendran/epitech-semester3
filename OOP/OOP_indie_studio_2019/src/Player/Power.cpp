/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Power
*/

#include "Power.hpp"

indie::Power::Power(const char *path, const vector3df pos,
            irrManager_t manager, indie::powerUp power)
{
    powerUp = manager.smgr->addMeshSceneNode(manager.smgr->getMesh(path), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    cubeColl = manager.smgr->addCubeSceneNode(2.8);
    if (powerUp == NULL || cubeColl == NULL)
        throw(Exception("can't create new power up"));
    cubeColl->setPosition(pos);
    cubeColl->setMaterialTexture(0, manager.driver->getTexture("resources/bomb/ag-square.png"));
    if (power == powerUp::BombUp) {
        powerUp->setScale(core::vector3df(1.2f));
        powerUp->setPosition(pos);
        powerUp->setRotation(core::vector3df(0, 0, 90.f));
    }
    if (power == powerUp::FireUp) {
        powerUp->setScale(core::vector3df(0.8f));
        powerUp->setPosition(pos);
    }
    if (power == powerUp::SpeedUp) {
        powerUp->setScale(core::vector3df(0.2f));
        powerUp->setRotation(core::vector3df(35.f, 0, 90.f));
        powerUp->setPosition(pos);
    }
    if (powerUp) {
        cubeColl->setMaterialFlag(EMF_LIGHTING, false);
        cubeColl->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
        powerUp->setMaterialFlag(EMF_LIGHTING, false);
    }
    type = power;
}

indie::Power::~Power()
{
    powerUp->remove();
    cubeColl->remove();
}

void indie::Power::setTexture(irrManager_t manager, const char *path)
{
    powerUp->setMaterialTexture(0, manager.driver->getTexture(path));
}

IMeshSceneNode *indie::Power::getNode() const
{
    return (cubeColl);
}

void indie::Power::remove()
{
    powerUp->remove();
    cubeColl->remove();
}

indie::powerUp indie::Power::getPower() const
{
    return (type);
}