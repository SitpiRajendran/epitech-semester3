/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuChooseMulti
*/

#include "MenuChooseMulti.hpp"
#include "MenuEventReceiver.hpp"

indie::MenuChooseMulti::MenuChooseMulti(WindowHandler &win)
{
    _start_button = win.getGuiEnv()->addButton(rect<s32>(760, 460, 1160, 540), 0, PLAY, L"");
    _start_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/start.jpg"));
    _start_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/start_on.jpg"));

    _multi_button = win.getGuiEnv()->addButton(rect<s32>(760, 560, 950, 640), 0, MULTI, L"");
    _multi_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/multi.jpg"));
    _multi_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/multi_on.jpg"));
    _solo_button = win.getGuiEnv()->addButton(rect<s32>(970, 560, 1160, 640), 0, SOLO, L"");
    _solo_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/solo.jpg"));
    _solo_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/solo_on.jpg"));
    _load_button = win.getGuiEnv()->addButton(rect<s32>(760, 660, 1160, 740), 0, LOAD, L"");
    _load_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/load.jpg"));
    _load_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/load_on.jpg"));

    _back_button = win.getGuiEnv()->addButton(rect<s32>(760, 760, 1160, 840), 0, BACK, L"");
    _back_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/back.jpg"));
    _back_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/back_on.jpg"));
    _is_solo = true;
    _is_load = false;
}

indie::MenuChooseMulti::~MenuChooseMulti()
{}

bool indie::MenuChooseMulti::getIsSolo() const
{
    return (_is_solo);
}

bool indie::MenuChooseMulti::getIsLoad() const
{
    return (_is_load);
}

int indie::MenuChooseMulti::loopMenu(WindowHandler &win)
{
    MenuEventReceiver receiver(win, _is_solo, _is_load);

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