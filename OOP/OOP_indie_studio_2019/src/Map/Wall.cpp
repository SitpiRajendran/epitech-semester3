/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** Wall
*/

#include "Wall.hpp"

indie::Wall::Wall(const char *path, const vector3df &pos, indie::irrManager_t manager, int nbPlayer, int destroyable)
{
    block = manager.smgr->addCubeSceneNode(3.0);
    if (block == NULL)
        throw(Exception("can't create wall"));
    blockSelec = manager.smgr->createTriangleSelectorFromBoundingBox(block);
    if (blockSelec == NULL)
        throw(Exception("can't create wall selector"));
    block->setPosition(pos);
    block->setMaterialTexture(0, manager.driver->getTexture(path));
    block->setMaterialFlag(video::EMF_LIGHTING, false);
    block->setTriangleSelector(blockSelec);
    canBeDestroyed = destroyable;
    const core::aabbox3d<f32>& box = block->getTransformedBoundingBox();
    core::vector3df radius = box.MaxEdge - box.getCenter();
    for (int i = 0; i < nbPlayer; i++) {
        animList.push_back(manager.smgr->createCollisionResponseAnimator(blockSelec, block, core::vector3df(1.4, 1.4, 1.4),
                            core::vector3df(0.f, 0.f, 0.f)));
        if (animList[animList.size() - 1] == NULL)
            throw(Exception("can't create wall animator"));
    }
    blockSelec->drop();
    it = 0;
}

indie::Wall::~Wall()
{
    block->remove();
}

void indie::Wall::setPosWall(const int _x, const int _y)
{
    x = _x;
    y = _y;
}

std::vector<int> indie::Wall::getPosWall()
{
    std::vector<int> pos;

    pos.push_back(x);
    pos.push_back(y);
    return (pos);
}

std::vector<ISceneNodeAnimator *> indie::Wall::getAllAnimator()
{
    return (animList);
}

ISceneNodeAnimator * indie::Wall::getAnimator()
{
    return (animList[it]);
}

void indie::Wall::animDrop()
{
    animList[it]->drop();
    it++;
}


IMeshSceneNode *indie::Wall::getNode()
{
    return (block);
}

int indie::Wall::getDestroyable()
{
    return (canBeDestroyed);
}