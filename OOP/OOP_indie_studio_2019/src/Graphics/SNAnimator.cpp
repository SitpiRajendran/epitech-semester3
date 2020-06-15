/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** SNAnimator
*/

#include "SNAnimator.hpp"

indie::SNAnimator::SNAnimator(ITriangleSelector *selector, IMeshSceneNode *node,
    vector3df radius, vector3df gravity, ISceneManager *smgr)
{
    anim = smgr->createCollisionResponseAnimator(selector, node, radius, gravity);
}

indie::SNAnimator::~SNAnimator()
{
}

void indie::SNAnimator::animDrop()
{
    anim->drop();
}

ISceneNodeAnimator *indie::SNAnimator::getAnim()
{
    return (this->anim);
}