/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuEndGame
*/

#include "MenuEndGame.hpp"
#include "MenuEventReceiver.hpp"

indie::MenuEndGame::MenuEndGame(WindowHandler &win)
{
    _replay_button = win.getGuiEnv()->addButton(rect<s32>(760, 760, 1160, 840), 0, PLAY, L"");
    if (_replay_button == NULL)
        throw(Exception("can't create play button"));
    _replay_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/replay.jpg"));
    _replay_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/replay_on.jpg"));

    _back_button = win.getGuiEnv()->addButton(rect<s32>(760, 860, 1160, 940), 0, BACK, L"");
    if (_back_button == NULL)
        throw(Exception("can't create play button"));
    _back_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/back.jpg"));
    _back_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/back_on.jpg"));

    try {
        _particle = std::make_shared<Particle>(win, "resources/particle/particle_white.bmp", aabbox3d<irr::f32>(1, -95, 20, -1, -95, 20));
        _particle->setMenuEndSettingParticle();
        _particle->setVisible(false);
    }
    catch (std::bad_alloc &e) {
        throw (Exception("can't create shared ptr"));
    }
}

indie::MenuEndGame::~MenuEndGame()
{
}

void indie::MenuEndGame::initializeAnimation(WindowHandler &win, std::string &winner_name)
{
    _perso = win.getSceneManager()->addAnimatedMeshSceneNode(win.getSceneManager()->getMesh("./resources/Character/model/Bomberman.MD3"), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    if (_perso == NULL)
        throw(Exception("can't create perso for animation"));
    if (winner_name.compare("player1") == 0)
        _perso->setMaterialTexture(0, win.getVideoDriver()->getTexture("./resources/Character/texture/BlackBombermanTextures.png"));
    else
        _perso->setMaterialTexture(0, win.getVideoDriver()->getTexture("./resources/Character/texture/WhiteBombermanTextures.png"));
    _anim = win.getSceneManager()->createFlyStraightAnimator(core::vector3df(0,-101,-6), core::vector3df(0,-101,-6), 3500, true);
    if (_anim == NULL)
        throw(Exception("can't create perso animation"));
    _perso->addAnimator(_anim);
    _anim->drop();
    _perso->setMaterialFlag(video::EMF_LIGHTING, false);
    _perso->setFrameLoop(0, 26);
    _perso->setAnimationSpeed(40);
    _particle->setVisible(true);
}

void indie::MenuEndGame::changeParticleColor(WindowHandler &win)
{
    u32 time = win.getDevice()->getTimer()->getTime();

    switch (time % 8)
    {
        case 0: _particle->setParticleColor(SColor(0, 0, 255, 255), SColor(0, 0, 255, 255)); break;
        case 1: _particle->setParticleColor(SColor(0, 255, 0, 255), SColor(0, 255, 0, 255)); break;
        case 2: _particle->setParticleColor(SColor(0, 255, 255, 0), SColor(0, 255, 255, 0)); break;
        case 3: _particle->setParticleColor(SColor(0, 0, 0, 255), SColor(0, 0, 0, 255)); break;
        case 4: _particle->setParticleColor(SColor(0, 255, 0, 0), SColor(0, 255, 0, 0)); break;
        case 5: _particle->setParticleColor(SColor(0, 0, 255, 0), SColor(0, 0, 255, 0)); break;
        case 6: _particle->setParticleColor(SColor(0, 0, 0, 0), SColor(0, 0, 0, 0)); break;
        case 7: _particle->setParticleColor(SColor(0, 255, 255, 255), SColor(0, 255, 255, 255)); break;
    }
}

int indie::MenuEndGame::loopMenu(WindowHandler &win, std::string &winner_name)
{
    MenuEventReceiver receiver(win);
    initializeAnimation(win, winner_name);
    win.getCamera()->setPosition(vector3df(0, -100, -10));
    win.getCamera()->setTarget(vector3df(0, -100, 0));

    win.getDevice()->setEventReceiver(&receiver);
    while (win.getDevice()->run() && win.getVideoDriver() != NULL && receiver.getButtonID() == MENU_BUTTON::NOTHING) {
        if (win.getDevice()->isWindowActive()) {
            changeParticleColor(win);
            win.getVideoDriver()->beginScene(true, true, win.getBackgroundColor());
            win.getVideoDriver()->draw2DImage(win.getVideoDriver()->getTexture("resources/Images/win.png"), core::position2d<s32>(810,100), core::rect<s32>(0,0,300,200), 0, video::SColor(255,255,255,255), true);
            win.getGuiEnv()->drawAll();
            win.getSceneManager()->drawAll();
            win.getVideoDriver()->endScene();
        }
    }
    _particle->setVisible(false);
    _perso->removeAnimator(_anim);
    _perso->remove();
    return (receiver.getButtonID());
}