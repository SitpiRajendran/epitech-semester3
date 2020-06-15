 /*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "MyPerso.hpp"
#include "Particle.hpp"

bool collision(ISceneNode *sn1, ISceneNode *sn2) {
    return (sn1->getTransformedBoundingBox().intersectsWithBox(sn2->getTransformedBoundingBox()));
}

indie::Bomb::Bomb(const char *path, const vector3df &pos,
                  irrManager_t manager, int nbPlayer, float range)
{
    core::vector3df newVec = pos;
    IMeshManipulator *manip = manager.smgr->getMeshManipulator();

    newVec.X -= 3;
    collMan = manager.smgr->getSceneCollisionManager();
    bomb = manager.smgr->addMeshSceneNode(manager.smgr->getMesh(path), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    cubeColl = manager.smgr->addCubeSceneNode(2.8);
    bombSelec = manager.smgr->createOctreeTriangleSelector(cubeColl->getMesh(), cubeColl, 128);
    bomb->setScale(core::vector3df(1.6f));
    bomb->setPosition(newVec);
    cubeColl->setMaterialTexture(0, manager.driver->getTexture("resources/bomb/ag-square.png"));
    cubeColl->setPosition(pos);
    cubeColl->setTriangleSelector(bombSelec);
    bomb->setTriangleSelector(bombSelec);
    if (bomb) {
        cubeColl->setMaterialFlag(EMF_LIGHTING, false);
        cubeColl->setMaterialType(EMT_TRANSPARENT_ALPHA_CHANNEL);
        bomb->setMaterialFlag(EMF_LIGHTING, false);
        bombSelec->drop();
    }
    const core::aabbox3d<f32> &box = cubeColl->getBoundingBox();
    core::vector3df radius = box.MaxEdge - box.getCenter();
    for (int i = 0; i < nbPlayer; i++)
        animBomb.push_back(manager.smgr->createCollisionResponseAnimator(bombSelec, cubeColl, radius,
                                                                        core::vector3df(0.f, 0.f, 0.f)));
    it = 0;
    timer = manager.device->getTimer();
    time = timer->getTime();
    timeMax = timer->getTime() + 5000;
    laser = Laser(pos, radius, 0.4, range);
}

indie::Bomb::~Bomb()
{
    bomb->remove();
    cubeColl->remove();
}

void indie::Bomb::createAnimator(ISceneManager *smgr)
{
    animBomb.push_back(smgr->createCollisionResponseAnimator(bombSelec, bomb, core::vector3df(9, 9, 9),
                                                             core::vector3df(0, 0, 0)));
}

ISceneNodeAnimator *indie::Bomb::getAnimator()
{
    ISceneNodeAnimator *temp = animBomb[it];
    return (temp);
}

ITriangleSelector *indie::Bomb::getSelec()
{
    return (bombSelec);
}
std::vector<ISceneNodeAnimator *> indie::Bomb::getAllAnimator()
{
    return (animBomb);
}

void indie::Bomb::animDrop()
{
    animBomb[it]->drop();
    it++;
}

void indie::Bomb::addAnim(ISceneNodeAnimator *anim)
{
    bomb->addAnimator(anim);
}

void indie::Bomb::setPoserName(const std::string &name)
{
    poserName = name;
}

std::string indie::Bomb::getPoserName()
{
    return (poserName);
}

ISceneNode *indie::Bomb::getNode()
{
    return (bomb);
}

int indie::Bomb::checkExplosion(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler,
        std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot, WindowHandler &win)
{
    core::list<ISceneNodeAnimator *>::ConstIterator animListP;
    core::list<ISceneNodeAnimator *>::ConstIterator animListB;
    int r = 0;

    time = timer->getTime();
    if (time > timeMax) {
        vector3df pos = bomb->getPosition();

        win.addExplosionSound();
        try {
            shared_ptr<Particle> particle = std::make_shared<Particle>(manager, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(pos.X + 3, pos.Y, pos.Z, pos.X + 3, pos.Y, pos.Z));
            particle->setMenuSettingParticleExplosion();
            win.addParticuleExplosion(particle);
        }
        catch (std::bad_alloc &e) {
            throw(Exception("can't create shared_ptr for particle"));
        }

        removePlayerAnim(Player, Bot);
        explosionEffect(manager, MapHandler, Player, Bot);
        return (1);
    }
    return (0);
}

void indie::Bomb::removePlayerAnim(std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot)
{
    for (int i = 0; i < Player.size(); i++) {
        if (Player[i]->checkDead() == 1) {
            Player[i]->removeBombAnim(getAllAnimator());
            if (poserName == Player[i]->getName())
                Player[i]->remBomb();
        }
    }
    for (int i = 0; i < Bot.size(); i++) {
        if (Bot[i]->checkDead() == 1) {
            Bot[i]->removeBombAnim(getAllAnimator());
            if (poserName == Bot[i]->getName())
                Bot[i]->remBomb();
        }
    }
}

void indie::Bomb::laserEffect(irrManager_t manager)
{
    core::vector3df intersection1;
    core::vector3df intersection2;
    core::vector3df intersection3;
    core::vector3df intersection4;
    core::triangle3df hitTriangle1;
    core::triangle3df hitTriangle2;
    core::triangle3df hitTriangle3;
    core::triangle3df hitTriangle4;
    scene::ISceneNode *snXp = collMan->getSceneNodeAndCollisionPointFromRay(
        laser.getXp()[0], intersection1, hitTriangle1, IDFlag_IsPickable | IDFlag_IsHighlightable, 0);
    scene::ISceneNode *snXm = collMan->getSceneNodeAndCollisionPointFromRay(
        laser.getXm()[0], intersection2, hitTriangle2, IDFlag_IsPickable | IDFlag_IsHighlightable, 0);
    scene::ISceneNode *snZp = collMan->getSceneNodeAndCollisionPointFromRay(
        laser.getZp()[0], intersection3, hitTriangle3, IDFlag_IsPickable | IDFlag_IsHighlightable, 0);
    scene::ISceneNode *snZm = collMan->getSceneNodeAndCollisionPointFromRay(
        laser.getZm()[0], intersection4, hitTriangle4, IDFlag_IsPickable | IDFlag_IsHighlightable, 0);
    ISceneNode *persoNode;

    laser.setEndLaserXp(laser.getXp()[0].end);
    laser.setEndLaserXm(laser.getXm()[0].end);
    laser.setEndLaserZp(laser.getZm()[0].end);
    laser.setEndLaserZm(laser.getZp()[0].end);
    if (snXp)
        laser.setEndLaserXp(intersection1);
    if (snXm)
        laser.setEndLaserXm(intersection2);
    if (snZp)
        laser.setEndLaserZm(intersection3);
    if (snZm)
        laser.setEndLaserZp(intersection4);
    laser.dispLaser(manager);
}

void indie::Bomb::explosionEffect(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler,
                                  std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot)
{
    explosionLine(manager, MapHandler, laser.getXp(), Player, Bot);
    explosionLine(manager, MapHandler, laser.getXm(),Player, Bot);
    explosionLine(manager, MapHandler, laser.getZp(),Player, Bot);
    explosionLine(manager, MapHandler, laser.getZm(),Player, Bot);
    for (int i = 0; i < playerToKill.size(); i++) {
        if (Player[playerToKill[i]]->checkDead() == 1)
            Player[playerToKill[i]]->die(MapHandler);
    }
    for (int i = 0; i < botToKill.size(); i++) {
        if (Bot[botToKill[i]]->checkDead() == 1)
            Bot[botToKill[i]]->die(MapHandler);
    }
    playerToKill.clear();
    botToKill.clear();
}

void indie::Bomb::explosionLine(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, vector<core::line3d<f32>> line,
                        std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot)
{
    core::vector3df intersection;
    core::triangle3df hitTriangle;
    shared_ptr<indie::Wall> copyWall;
    scene::ISceneNode *snXp;

    for (int i = 0; i < line.size(); i++) {
        snXp = collMan->getSceneNodeAndCollisionPointFromRay(line[i], intersection,
                hitTriangle, IDFlag_IsPickable | IDFlag_IsHighlightable, 0);
        if (explodePerso(snXp, Player, playerToKill) == 1)
            return;
        if (explodePerso(snXp, Bot, botToKill) == 1)
            return;
        if (explodeWall(snXp, manager, MapHandler, Player, Bot) == 1)
            return;
    }
}

int indie::Bomb::explodePerso(scene::ISceneNode *sn, std::vector<std::shared_ptr<MyPerso>> Player, vector<int> &listToKill)
{
    ISceneNode *persoNode;

    for (int i = 0; i < Player.size(); i++) {
        if (Player[i]->checkDead() == 1) {
            persoNode = Player[i]->getNode();
            if (sn == persoNode) {
                listToKill.push_back(i);
                return (1);
            }
            else if (Mycollision(cubeColl, persoNode) == true) {
                listToKill.push_back(i);
                return (1);
            }
        }
    }
    return (0);
}

int indie::Bomb::explodeWall(scene::ISceneNode *sn, irrManager_t manager,
                              std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot)
{
    shared_ptr<indie::Wall> copyWall;

    for (int j = 0; j < MapHandler->getMapSize(); j++) {
        copyWall = MapHandler->getWall(j);
        if (copyWall->getNode() == sn) {
            if (copyWall->getDestroyable() == 1) {
                for (int i = 0; i < Player.size(); i++)
                    Player[i]->removeBombAnim(copyWall->getAllAnimator());
                for (int i = 0; i < Bot.size(); i++)
                    Bot[i]->removeBombAnim(copyWall->getAllAnimator());
                MapHandler->addPowerUp(j, manager);
                MapHandler->removeBlock(j);
                return (1);
            }
        }
    }
    return (0);
}