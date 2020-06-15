/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <SFML/Audio.hpp>
#include "MapHandler.hpp"
//#include "MyPerso.hpp"
#include "Laser.hpp"
#include "WindowHandler.hpp"

bool Mycollision(ISceneNode *sn1, ISceneNode *sn2);
namespace indie
{
    class MyPerso;
    class WindowHandler;
    class MapHandler;

    class Bomb
    {
    public:
        Bomb(const char *path, const vector3df &pos,
             irrManager_t manager, int nbPlayer, float range);
        ~Bomb();
        ISceneNodeAnimator *getAnimator();
        std::vector<ISceneNodeAnimator *> getAllAnimator();
        void createAnimator(ISceneManager *smgr);
        void animDrop();
        void setPoserName(const std::string &name);
        ISceneNode *getNode();
        std::string getPoserName();
        ITriangleSelector *getSelec();
        void addAnim(ISceneNodeAnimator *anim);
        int checkExplosion(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot, WindowHandler &win);
        void removePlayerAnim(std::vector<std::shared_ptr<MyPerso>> &Player, std::vector<std::shared_ptr<MyPerso>> Bot);
        void laserEffect(irrManager_t manager);
        void explosionEffect(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot);
        void explosionLine(irrManager_t manager, std::shared_ptr<indie::MapHandler> MapHandler, vector<core::line3d<f32>> line,
                        std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot);
        int explodeWall(scene::ISceneNode *sn, irrManager_t manager,
                        std::shared_ptr<indie::MapHandler> MapHandler, std::vector<std::shared_ptr<MyPerso>> Player, std::vector<std::shared_ptr<MyPerso>> Bot);
        int explodePerso(scene::ISceneNode *sn, std::vector<std::shared_ptr<MyPerso>> Player, vector<int> &listToKill);

    protected:
    private:
        ISceneCollisionManager *collMan;
        IMeshSceneNode *bomb;
        IMeshSceneNode *cubeColl;
        std::vector<ISceneNodeAnimator *> animBomb;
        ITriangleSelector *bombSelec;
        std::string poserName;
        int it;
        core::vector3df timeScale;
        ITimer *timer;
        u32 time;
        u32 timeMax;
        indie::Laser laser;
        vector<int> playerToKill;
        vector<int> botToKill;
    };
}

#endif /* !BOMB_HPP_ */
