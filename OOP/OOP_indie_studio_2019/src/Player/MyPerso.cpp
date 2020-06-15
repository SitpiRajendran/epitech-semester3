/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** MyPerso
*/

#include <irrlicht.h>
#include <fstream>
#include <dirent.h>
#include <sstream>
#include "MyPerso.hpp"

bool Mycollision(ISceneNode *sn1, ISceneNode *sn2) {
    return (sn1->getTransformedBoundingBox().intersectsWithBox(sn2->getTransformedBoundingBox()));
}

indie::MyPerso::MyPerso(char const *path, const core::vector3df &scale,
    const core::vector3df &pos, const f32 &animation, irrManager_t manager, char const *colorPath)
{
    node = manager.smgr->addAnimatedMeshSceneNode(manager.smgr->getMesh(path), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    if (!node)
        throw (Exception("can't load player"));
    selec = manager.smgr->createTriangleSelector(node);
    if (!selec)
        throw (Exception("can't load player"));
    node->setMaterialTexture(0, manager.driver->getTexture(colorPath));
    node->setScale(scale);
    node->setPosition(pos);
    node->setRotation(core::vector3df(0, 0, 0));
    node->setAnimationSpeed(animation);
    node->setMD2Animation(scene::EMAT_POINT);
    if (node) {
        node->setTriangleSelector(selec);
        node->setMaterialFlag(EMF_LIGHTING, false);
        node->setFrameLoop(0, 0);
        selec->drop();
    }
    _smgr = manager.smgr;
    const core::aabbox3d<f32>& box = node->getBoundingBox();
    radius = box.MaxEdge - box.getCenter();
    try {
        animator = std::make_shared<Character>(node, core::vector3df(0, 0, -0.2));
    }
    catch (std::bad_alloc &e) {
        throw (Exception("can't create shared ptr"));
    }
    powerUp = Stat();
    isDead = 1;
}

indie::MyPerso::~MyPerso()
{
}

void indie::MyPerso::addAnim(ISceneNodeAnimator *anim)
{
    node->addAnimator(anim);
}

void indie::MyPerso::remAnim(ISceneNodeAnimator *anim)
{
    node->removeAnimator(anim);
}

void indie::MyPerso::putBomb()
{
    powerUp.putBomb();
}

void indie::MyPerso::remBomb()
{
    powerUp.remBomb();
}

void indie::MyPerso::setName(const std::string &_name)
{
    name = _name;
}

void indie::MyPerso::savePerso()
{
    std::string fileName = "Maps/.";
    fileName.append(name);
    std::ofstream file(fileName);
    std::string stat;

    file << getName() << " stats" << std::endl;
    stat = std::to_string(powerUp.getMaxBomb());
    file << "Max Bomb: " << stat << std::endl;
    stat = std::to_string(powerUp.getRange());
    file << "Bomb range: " << stat << std::endl;
    stat = std::to_string(powerUp.getSpeed().Z);
    file << "Speed : " << stat << std::endl;
    file.close();
}

void indie::MyPerso::loadStat(std::vector<std::string> load)
{
    std::string maxBomb = load[1].substr(10, load[1].size() - 1);
    std::string bombRange = load[2].substr(12, load[1].size() - 1);
    std::string speed = load[3].substr(8, load[1].size() - 1);
    int maxB = std::stoi(maxBomb);
    float bombR = std::stof(bombRange);
    float s = std::stof(speed);
    f32 anim;
    powerUp = Stat(maxB, bombR, vector3df(0.f, 0.f, s));
    animator->setNewMov(powerUp.getSpeed());
    anim = node->getAnimationSpeed();
    anim += std::abs(s) / 0.2;
    node->setAnimationSpeed(anim);
}

void indie::MyPerso::die(std::shared_ptr<indie::MapHandler> MapHandler)
{
    std::shared_ptr<indie::Wall> copyWall;

    if (isDead == 1) {
        isDead = 0;
        animator->setDead();
        for (int j = 0; j < MapHandler->getMapSize(); j++) {
            copyWall = MapHandler->getWall(j);
            removeBombAnim(copyWall->getAllAnimator());
        }
        node->remove();
        std::cout << name << " has been slayed" << std::endl;
    }
}

void indie::MyPerso::powerUpEvent(indie::powerUp type)
{
    f32 anim;

    if (type == indie::powerUp::BombUp)
        powerUp.remBomb();
    if (type == indie::powerUp::FireUp)
        powerUp.fireUp();
    if (type == indie::powerUp::SpeedUp) {
        powerUp.incSpeed();
        animator->setNewMov(powerUp.getSpeed());
        anim = node->getAnimationSpeed();
        anim += 3;
        node->setAnimationSpeed(anim);
    }
}

IAnimatedMeshSceneNode *indie::MyPerso::getNode()
{
    return (this->node);
}

std::shared_ptr<indie::Character> indie::MyPerso::getCharacter()
{
    return (this->animator);
}

core::list<ISceneNodeAnimator*> indie::MyPerso::getAllAnimator()
{
    return (node->getAnimators());
}

core::vector3df indie::MyPerso::getPersoPos() const
{
    return (node->getAbsolutePosition());
}

std::string indie::MyPerso::getName() const
{
    return (name);
}

int indie::MyPerso::checkBomb() const
{
    return (powerUp.getMaxBomb());
}

float indie::MyPerso::getRange() const
{
    return (powerUp.getRange());
}

int indie::MyPerso::checkDead() const
{
    return (isDead);
}
bool indie::MyPerso::ifAnimatorAlreadyAssigned(std::vector<ISceneNodeAnimator *> list)
{
    core::list<ISceneNodeAnimator*>::ConstIterator animListP1 = node->getAnimators().begin();

    animListP1 = node->getAnimators().begin();
    while (animListP1 != node->getAnimators().end()) {
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == *animListP1)
                return (true);
        }
        animListP1++;
    }
    return (false);
}

int indie::MyPerso::addCollision(BombList *list)
{
    int i = list->getBombListSize();
    bool exist = false;
    int j = 0;
    ISceneNodeAnimator *bombAnim;

    if (i == 0 || checkDead() == 0)
        return (0);
    for (int j = 0; j < i; j++) {
        bombAnim = list->getAnimator(j);
        exist = false;
        exist = ifAnimatorAlreadyAssigned(list->getAllAnimator(j));
        node->getMesh()->getMeshBuffer(0)->recalculateBoundingBox();
        if (exist == false && Mycollision(node, list->getBomb(j)) == false) {
            addAnim(bombAnim);
            list->dropBomb(j);
            list->checked();
        }
    }
    return (j);
}

void indie::MyPerso::removeBombAnim(std::vector<ISceneNodeAnimator *> animBomb)
{
    core::list<ISceneNodeAnimator*>::ConstIterator animListP;
    core::list<ISceneNodeAnimator*>::ConstIterator end;

    if (checkDead() == 0)
        return;
    animListP = getAllAnimator().begin();
    end = getAllAnimator().end();
    for (int j = 0; j < animBomb.size(); j++)
        remAnim(animBomb[j]);
}