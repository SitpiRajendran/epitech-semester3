/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** TitleScreen
*/

#include "TitleScreen.hpp"
#include "TitleScreenEventReceiver.hpp"
#include "MyPerso.hpp"

indie::TitleScreen::TitleScreen(WindowHandler &win)
{
    try {
        _particle = std::make_shared<Particle>(win, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(1, -101, 20, -1, -101, 20));
        _particle->setMenuSettingParticleFlame();
        _particle->setVisible(false);
    }
    catch (std::bad_alloc &e) {
        throw (Exception("can't create shared ptr"));
    }
}

indie::TitleScreen::~TitleScreen() {}

int indie::TitleScreen::launch(WindowHandler &win)
{
    bool launched = true;
    TitleScreenEventReceiver receiver(launched);
    u32 time = win.getDevice()->getTimer()->getTime();

    win.getDevice()->setEventReceiver(&receiver);
    while(win.getDevice()->run() && win.getVideoDriver() != NULL && launched == true)
        if (win.getDevice()->isWindowActive()) {
            time = win.getDevice()->getTimer()->getTime();
            win.getVideoDriver()->beginScene(true, true, SColor(0, 0, 0, 0));
            win.getVideoDriver()->draw2DImage(win.getVideoDriver()->getTexture("resources/Images/credit.png"), position2d<int>(400, 900));
            win.getVideoDriver()->draw2DImage(win.getVideoDriver()->getTexture("resources/Images/logo_game_title_screen.png"), position2d<int>(520, 50));
            if ((time / 600 % 3) != 0)
                win.getVideoDriver()->draw2DImage(win.getVideoDriver()->getTexture("resources/Images/click_to_continue.png"), position2d<int>(750, 750));
            win.getVideoDriver()->endScene();
        }
    animationTransition(win);
    return (SUCCESS);
}

void indie::TitleScreen::animationTransition(WindowHandler &win)
{
    IAnimatedMeshSceneNode *perso = win.getSceneManager()->addAnimatedMeshSceneNode(win.getSceneManager()->getMesh("./resources/Character/model/Bomberman.MD3"), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);
    if (perso == NULL)
        throw(Exception("can't create perso for animation"));
    perso->setMaterialTexture(0, win.getVideoDriver()->getTexture("./resources/Character/texture/WhiteBombermanTextures.png"));
    scene::ISceneNodeAnimator *anim = win.getSceneManager()->createFlyStraightAnimator(core::vector3df(0,-101,20), core::vector3df(0,-101,-8), 3500, true);
    if (anim == NULL)
        throw(Exception("can't create perso animation"));
    perso->addAnimator(anim);
    anim->drop();
    perso->setMaterialFlag(video::EMF_LIGHTING, false);
    perso->setFrameLoop(0, 26);
    perso->setAnimationSpeed(40);
    _particle->setVisible(true);

    u32 time = win.getDevice()->getTimer()->getTime();
    u32 max_time = time + 3300;
    while (win.getDevice()->run() && time < max_time)
        if (win.getDevice()->isWindowActive()) {
            time = win.getDevice()->getTimer()->getTime();
            win.getVideoDriver()->beginScene(true, true, SColor(0, 0, 0, 0));
                win.getVideoDriver()->draw2DImage(win.getVideoDriver()->getTexture("resources/Images/logo_game_title_screen.png"), position2d<int>(520, 50));
            win.getSceneManager()->drawAll();
            win.getVideoDriver()->endScene();
        }
    perso->removeAnimator(anim);
    perso->remove();
    _particle->setVisible(false);
}