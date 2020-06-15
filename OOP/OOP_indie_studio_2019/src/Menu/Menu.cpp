/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** Menu
*/

#include "Menu.hpp"
#include "MenuEventReceiver.hpp"

indie::Menu::Menu(WindowHandler &win)
{
    _play_button = win.getGuiEnv()->addButton(rect<s32>(810, 460, 1110, 560), 0, PLAY, L"");
    if (_play_button == NULL)
        throw(Exception("can't create play button"));
    _play_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/play.png"));
    _play_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/play_on.jpg"));

    _option_button = win.getGuiEnv()->addButton(rect<s32>(810, 580, 1110, 680), 0, OPTION, L"");
    if (_option_button == NULL)
        throw(Exception("can't create play button"));
    _option_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/options.png"));
    _option_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/options_on.jpg"));

    _quit_button = win.getGuiEnv()->addButton(rect<s32>(810, 700, 1110, 800), 0, QUIT, L"");
    if (_quit_button == NULL)
        throw(Exception("can't create play button"));
    _quit_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/quit.png"));
    _quit_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/quit_on.jpg"));
}

indie::Menu::~Menu()
{
}

int indie::Menu::loopMenu(WindowHandler &win)
{
    MenuEventReceiver receiver(win);
    setParticle(win);
    win.getCamera()->setPosition(vector3df(0, -100, -10));
    win.getCamera()->setTarget(vector3df(0, -100, 0));

    win.getDevice()->setEventReceiver(&receiver);
    while (win.getDevice()->run() && win.getVideoDriver() != NULL && receiver.getButtonID() == MENU_BUTTON::NOTHING) {
        if (win.getDevice()->isWindowActive()) {
            win.getVideoDriver()->beginScene(true, true, win.getBackgroundColor());
            displayGoodLogoColor(win);
            win.getGuiEnv()->drawAll();
            win.getSceneManager()->drawAll();
            win.getVideoDriver()->endScene();
        }
    }
    return (receiver.getButtonID());
}