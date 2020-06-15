/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** CoreGame
*/

#include <list>
#include <Irrlicht.hpp>

#include "Bot.hpp"
#include "System.hpp"
#include "CoreGame.hpp"
#include "Particle.hpp"
#include "OptionMenu.hpp"
#include "MenuChooseMulti.hpp"
#include "MenuEndGame.hpp"
#include "MenuEventReceiver.hpp"

indie::CoreGame::CoreGame(const char *persoPath, const int _nbPerso, const int _nbBot)
{
    windowhdl = new WindowHandler("League of Bombers", 1920, 1080);
    manager.driver = windowhdl->getVideoDriver();
    manager.smgr = windowhdl->getSceneManager();
    manager.device = windowhdl->getDevice();
    manager.device->getTimer()->start();
    AsciiMap = new Mapper();
    nbPlayer = _nbPerso;
    nbBot = _nbBot;
    this->is_solo = true;
    this->is_load = false;
}

indie::CoreGame::~CoreGame() {
    // bot.clear();
    // PlayerPerso.clear();
    //Remote->~MyRemoteControler();
    //receiver->~MyEventReceiver();
    windowhdl->~WindowHandler();
}

void indie::CoreGame::initPerso()
{
    PlayerPerso.push_back(make_shared<indie::MyPerso>("./resources/Character/model/Bomberman.MD3", core::vector3df(1.5f),
        core::vector3df(3, -0.5, 3), 30.f, manager, "./resources/Character/texture/BlackBombermanTextures.png"));
    PlayerPerso[0]->setName("player1");
    if (nbPlayer == 2) {
        PlayerPerso.push_back(make_shared<indie::MyPerso>("./resources/Character/model/Bomberman.MD3", core::vector3df(1.5f),
            core::vector3df(60, -0.5, 60), 30.f, manager, "./resources/Character/texture/WhiteBombermanTextures.png"));
        PlayerPerso[1]->setName("player2");
        receiver = new MyEventReceiver(PlayerPerso[0]->getCharacter(), PlayerPerso[1]->getCharacter());
        Remote = new MyRemoteControler();
    } else {
        receiver = new MyEventReceiver(PlayerPerso[0]->getCharacter(), nullptr);
        Remote = new MyRemoteControler();
    }
    if (this->is_load) {
        for (int i = 0; i < PlayerPerso.size(); i++) {
            PlayerPerso[i]->loadStat(System().loadStat(PlayerPerso[i]->getName()));
        }
    }
}

std::string indie::CoreGame::getWinner()
{
    for (int i = 0; i < PlayerPerso.size(); i++) {
        if (PlayerPerso[i]->checkDead() == 1)
            return (PlayerPerso[i]->getName());
    }
    for (int i = 0; i < bot.size(); i++) {
        if (bot[i]->checkDead() == 1)
            return (bot[i]->getName());
    }
    return ("no winner");
}

void indie::CoreGame::addBomb(std::string poserName) {
    if (poserName == PlayerPerso[0]->getName() && PlayerPerso[0]->checkBomb() > 0) {
        bombList.addBomb(manager, PlayerPerso[0]->getPersoPos(), poserName,
            nbPlayer + nbBot, PlayerPerso[0]->getRange());
        PlayerPerso[0]->putBomb();
    } else if (poserName == PlayerPerso[1]->getName() && PlayerPerso[1]->checkBomb() > 0) {
        bombList.addBomb(manager, PlayerPerso[1]->getPersoPos(),
            poserName, nbPlayer + nbBot, PlayerPerso[1]->getRange());
        PlayerPerso[1]->putBomb();
    }
}

void indie::CoreGame::addCollision() {
    if (bombList.getCheckSize() > 0) {
        for (size_t i = 0; i < PlayerPerso.size(); i++) {
            if (PlayerPerso[i]->addCollision(&bombList) == 1)
                bombList.checked();
        }
    }
}

void indie::CoreGame::checkPowerUp(std::shared_ptr<indie::MapHandler> MapHandler)
{
    for (int j = 0; j < MapHandler->getPowerUpSize(); j++) {
        for (int i = 0; i < PlayerPerso.size(); i++) {
            if (PlayerPerso[i]->checkDead() == 1) {
                if (Mycollision(PlayerPerso[i]->getNode(), MapHandler->getPowerUp(j)->getNode())) {
                    PlayerPerso[i]->powerUpEvent(MapHandler->getPowerUp(j)->getPower());
                    MapHandler->removePowerUp(j);
                    return;
                }
            }
        }
    }
}

void indie::CoreGame::handleParticularEvent(EventParticular event)
{
    if (event == EventParticular::BombPosP1) {
        addBomb(PlayerPerso[0]->getName());
        event = EventParticular::Nothing;
    } if (event == EventParticular::BombPosP2) {
        addBomb(PlayerPerso[1]->getName());
        event = EventParticular::Nothing;
    }
}


int indie::CoreGame::LaunchGameAndReplayMenu()
{
    int action = indie::MENU_BUTTON::NOTHING;
    this->windowhdl->clearGuiEnv();

    while (action != indie::MENU_BUTTON::BACK && this->windowhdl->getDevice()->run()) {
        action = indie::MENU_BUTTON::NOTHING;
        this->Core();
        this->windowhdl->clearParticle();
        MenuEndGame MenuEndGame(*this->windowhdl);
        action = MenuEndGame.loopMenu(*this->windowhdl, this->winner_name);
    }
    return (SUCCESS);
}

int indie::CoreGame::LaunchChooseMultiMenu()
{
    int action = indie::MENU_BUTTON::NOTHING;
    this->windowhdl->clearGuiEnv();
    indie::MenuChooseMulti MenuChooseMulti(*this->windowhdl);
    this->is_solo = true;
    this->is_load = false;

    while (action != indie::MENU_BUTTON::BACK && this->windowhdl->getDevice()->run()) {
        action = indie::MENU_BUTTON::NOTHING;
        action = MenuChooseMulti.loopMenu(*this->windowhdl);
        if (action == indie::MENU_BUTTON::MULTI || action == indie::MENU_BUTTON::SOLO)
            this->is_solo = MenuChooseMulti.getIsSolo();
        if (action == indie::MENU_BUTTON::PLAY || action == indie::MENU_BUTTON::LOAD) {
            this->is_load = MenuChooseMulti.getIsLoad();
            this->windowhdl->clearParticle();
            this->LaunchGameAndReplayMenu();
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}

int indie::CoreGame::LaunchMenu()
{
    int action = indie::MENU_BUTTON::NOTHING;

    while (action != indie::MENU_BUTTON::QUIT && this->windowhdl->getDevice()->run()) {
        action = indie::MENU_BUTTON::NOTHING;
        indie::Menu Menu(*this->windowhdl);
        action = Menu.loopMenu(*this->windowhdl);
        this->windowhdl->clearGuiEnv();
        if (action == indie::MENU_BUTTON::OPTION) {
            OptionMenu optionMenu(*this->windowhdl);
            optionMenu.loopOptionMenu(*this->windowhdl);
        } else if (action == indie::MENU_BUTTON::PLAY)
            this->LaunchChooseMultiMenu();
        this->windowhdl->clearGuiEnv();
        this->windowhdl->clearParticle();
    }
    return (SUCCESS);
}

int indie::CoreGame::LaunchTitleScreenAndMenu() {
    indie::TitleScreen TitleScreen(*this->windowhdl);

    TitleScreen.launch(*this->windowhdl);
    this->windowhdl->clearGuiEnv();
    return (this->LaunchMenu());
}

void indie::CoreGame::initializeGameParticleFlame()
{
    try {
        shared_ptr<Particle> particle_1 = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(-4, -5, 66, 66, -5, 66));
        shared_ptr<Particle> particle_2 = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(69, -5, -4, 66, -5, 69));
        shared_ptr<Particle> particle_3 = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(-4, -5, -6, 66, -5, -6));
        shared_ptr<Particle> particle_4 = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(-6, -5, -4, -6, -5, 66));
        windowhdl->addParticule(particle_1);
        particle_1->setMenuSettingParticleFlame();
        particle_1->setParticleBySec(240, 280);
        windowhdl->addParticule(particle_2);
        particle_2->setMenuSettingParticleFlame();
        particle_2->setParticleBySec(240, 280);
        windowhdl->addParticule(particle_3);
        particle_3->setMenuSettingParticleFlame();
        particle_3->setParticleBySec(240, 280);
        windowhdl->addParticule(particle_4);
        particle_4->setMenuSettingParticleFlame();
        particle_4->setParticleBySec(240, 280);
    } catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for particle"));
    }
}

void indie::CoreGame::initializeGameParticleSnow()
{
    try {
        shared_ptr<Particle> particle = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_white.bmp", aabbox3d<irr::f32>(-28, 30, -28, 76, 30, 76));
        windowhdl->addParticule(particle);
        particle->setMenuSettingParticleSnow();
        particle->setParticleBySec(100, 150);
    } catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for particle"));
    }
}

void indie::CoreGame::initializeGameParticleRain()
{
    try {
        shared_ptr<Particle> particle = std::make_shared<Particle>(*windowhdl, "resources/particle/particle_green.jpg", aabbox3d<irr::f32>(-10, 30, -10, 76, 30, 76));
        windowhdl->addParticule(particle);
        particle->setMenuSettingParticleRain();
        particle->setParticleBySec(1000, 1200);
    } catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for particle"));
    }
}

void indie::CoreGame::initializeGameParticle()
{
    if (windowhdl->getParticleType() == PARTICLE_TYPE::FLAME)
        initializeGameParticleFlame();
    else if (windowhdl->getParticleType() == PARTICLE_TYPE::SNOW)
        initializeGameParticleSnow();
    else
        initializeGameParticleRain();
}

int indie::CoreGame::CheckEnd()
{
    int nb = 0;

    for (size_t i = 0; i < PlayerPerso.size(); i ++) {
        if (PlayerPerso[i]->checkDead() == 1)
            nb ++;
    } for (size_t i = 0; i < bot.size(); i ++) {
        if (bot[i]->checkDead() == 1)
            nb ++;
    }
    return (nb);
}

void indie::CoreGame::resetPerso(std::shared_ptr<indie::MapHandler> MapHandler)
{
    if (CheckEnd() > 1) {
        for (int i = 0; i < PlayerPerso.size(); i++)
            PlayerPerso[i]->savePerso();
    } for (size_t i = 0; i < PlayerPerso.size(); i++)
        PlayerPerso[i]->die(MapHandler);
    PlayerPerso.clear();
    bot.clear();
}

int indie::CoreGame::Core(void)
{
    indie::Bot robot;
    bool RemoteChoice = false;
    EventParticular eventAI = Nothing;
    std::vector<std::string> map = !this->is_load ? MapGenerator().generate() : System().loadMap();
    std::shared_ptr<indie::MapHandler> MapHandler = std::make_shared<indie::MapHandler>(manager, map, nbPlayer + nbBot);

    initPerso();
    initializeGameParticle();
    this->windowhdl->getCamera()->setPosition(core::vector3df(33, 52, 33));
    this->windowhdl->getCamera()->setTarget(core::vector3df(33, 0, 33));
    MapHandler->initCollision(PlayerPerso, bot);

    this->AsciiMap->setMap(map);
    if (RemoteChoice)
        manager.device->setEventReceiver(Remote);
    else
        manager.device->setEventReceiver(receiver);
    Remote->RemoteInfos(manager.device);
    Remote->setFpsSignal(50);
    map.clear();
    while (windowhdl->getDevice()->run() && CheckEnd() > 1) {
        if (manager.device->isWindowActive()) {
            windowhdl->drawing(true, true, windowhdl->getBackgroundColor());
            bombList.laserEffect(manager);
            windowhdl->endScene();
            addCollision();
            if (RemoteChoice) {
                Remote->updatePlayer((*windowhdl), *this->PlayerPerso[0], *this->AsciiMap);
                handleParticularEvent(Remote->getParticularEvent());
            } else {
                receiver->majPosMesh(*this->AsciiMap);
                handleParticularEvent(receiver->getParticularEvent());
            }
            Remote->avoidMultipleSignal();
            if (this->is_solo)
                robot.updatePlayer(*this->PlayerPerso[1], this->AsciiMap->getMap(), *this->AsciiMap, eventAI);
            bombList.checkExplosion(manager, MapHandler, PlayerPerso, bot, *this->windowhdl);
            handleParticularEvent(eventAI);
            eventAI = Nothing;
            checkPowerUp(MapHandler);
            for (size_t i = 0; i < bombList.getBombListSize(); i ++)
                this->AsciiMap->setCharPos('Q', ((int)bombList.getBomb(i)->getPosition().X / 3) + 1, (int)bombList.getBomb(i)->getPosition().Z / 3 + 1);
            windowhdl->checkParticleExplosion();
            windowhdl->checkExplosionMusic();
        }
    }
    windowhdl->clearExplosionMusic();
    bombList.clearBomb();
    winner_name = getWinner();
    if (CheckEnd() > 1)
        System().saveMap(MapHandler->getStringMap());
    windowhdl->clearParticleExplosion();
    resetPerso(MapHandler);
    return 0;
}
