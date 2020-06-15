/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** Character
*/

#include "Character.hpp"

indie::Character::Character(IAnimatedMeshSceneNode *_node, vector3df _move)
{
    node = _node;
    move = _move;
    r = node->getRotation();
    mov = indie::Movement::MoveRight;
    isDead = 1;
}

indie::Character &indie::Character::operator=(const Character &to_cmp)
{
    if (this == &to_cmp)
        return (*this);
    node = to_cmp.node;
    move = to_cmp.move;
    mov = to_cmp.mov;
    return (*this);
}

indie::Character::~Character()
{
}

IAnimatedMeshSceneNode *indie::Character::getNode()
{
    return (this->node);
}

void indie::Character::updatePosRot()
{
    v = node->getPosition();
    r = node->getRotation();
}

void indie::Character::animUp()
{
    int rot = node->getRotation().Y;

    updatePosRot();
    if (node->getStartFrame() != 1)
        node->setFrameLoop(1, 26);
    Mat.setRotationDegrees(node->getRotation());
    if ((rot % 360) == -90 || (rot % 360) == 270) {
        core::vector3df Target(move.X, move.Y, move.Z);
        Mat.transformVect(Target);
        core::vector3df NewPos = node->getPosition();
        NewPos += Target;
        node->setPosition(NewPos);
        mov = Movement::MoveUp;
    } else {
        r.Y = 270;
        node->setRotation(r);
    }
}

void indie::Character::animDown()
{
    int rot = node->getRotation().Y;

    updatePosRot();
    if (node->getStartFrame() != 1)
        node->setFrameLoop(1, 26);
    Mat.setRotationDegrees(node->getRotation());
    if ((rot % 360) == 90 || (rot % 360) == -270) {
        core::vector3df Target(move.X, move.Y, move.Z);
        Mat.transformVect(Target);
        core::vector3df NewPos = node->getPosition();
        NewPos += Target;
        node->setPosition(NewPos);
        mov = Movement::MoveDown;
    } else {
        r.Y = 90;
        node->setRotation(r);
    }
}

void indie::Character::animLeft()
{
    int rot = std::abs(node->getRotation().Y);

    updatePosRot();
    if (node->getStartFrame() != 1)
        node->setFrameLoop(1, 14);
    Mat.setRotationDegrees(node->getRotation());
    if ((rot % 360) == 180) {
        core::vector3df Target(move.X, move.Y, move.Z);
        Mat.transformVect(Target);
        core::vector3df NewPos = node->getPosition();
        NewPos += Target;
        node->setPosition(NewPos);
        mov = Movement::MoveLeft;
    } else {
        r.Y = 180;
        node->setRotation(r);
    }
}
void indie::Character::animRight()
{
    int rot = std::abs(node->getRotation().Y);

    updatePosRot();
    if (node->getStartFrame() != 1)
        node->setFrameLoop(1, 14);
    Mat.setRotationDegrees(node->getRotation());
    if ((rot % 360) == 0) {
        core::vector3df Target(move.X, move.Y, move.Z);
        Mat.transformVect(Target);
        core::vector3df NewPos = node->getPosition();
        NewPos += Target;
        node->setPosition(NewPos);
        mov = Movement::MoveRight;
    } else {
        r.Y = 0;
        node->setRotation(r);
    }
}

void indie::Character::bombPos()
{
    if (node->getStartFrame() != 33)
        node->setFrameLoop(33, 44);
}

void indie::Character::reInitAnim()
{
    if (node->getStartFrame() != 0 && node->getFrameNr() < 33)
        node->setFrameLoop(0, 0);
}

void indie::Character::reInitBombPos()
{
    if (node->getFrameNr() >= 43.0)
        node->setFrameLoop(0, 0);
}


void indie::Character::setDead()
{
    isDead = 0;
}

int indie::Character::getDead() const
{
    return (isDead);
}

void indie::Character::setNewMov(core::vector3df mov)
{
    move = mov;
}