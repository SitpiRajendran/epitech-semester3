/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** OptionMenu
*/

#include <SFML/Audio.hpp>
#include "OptionMenu.hpp"

indie::OptionMenu::OptionMenu(WindowHandler &win)
{
    this->_volume = win.getVolume();
    _quit_button = win.getGuiEnv()->addButton(rect<s32>(760, 840, 1160, 920), 0, BACK, L"");
    _quit_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/back.jpg"));
    _quit_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/back_on.jpg"));
    _particle_activated_button = win.getGuiEnv()->addButton(rect<s32>(760, 640, 1160, 720), 0, PARTICLE_ACTIVATED, L"");
    _particle_activated_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/particules.png"));
    _particle_activated_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/particules_on.png"));
    _particle_flame_button = win.getGuiEnv()->addButton(rect<s32>(760, 740, 880, 820), 0, PARTICLE_FLAME, L"");
    _particle_flame_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/flame.png"));
    _particle_flame_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/flame_on.png"));
    _particle_snow_button = win.getGuiEnv()->addButton(rect<s32>(900, 740, 1020, 820), 0, PARTICLE_SNOW, L"");
    _particle_snow_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/snow.png"));
    _particle_snow_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/snow_on.png"));
    _particle_rain_button = win.getGuiEnv()->addButton(rect<s32>(1040, 740, 1160, 820), 0, PARTICLE_RAIN, L"");
    _particle_rain_button->setImage(win.getVideoDriver()->getTexture("resources/buttons/rain.png"));
    _particle_rain_button->setPressedImage(win.getVideoDriver()->getTexture("resources/buttons/rain_on.png"));
    win.getGuiEnv()->addStaticText(L"Volume:", rect<s32>(720, 450, 755, 460), true, false, 0, -1, true);
    win.getGuiEnv()->addStaticText(L"Red Background:", rect<s32>(685, 500, 755, 510), true, false, 0, -1, true);
    win.getGuiEnv()->addStaticText(L"Green Background:", rect<s32>(680, 550, 755, 560), true, false, 0, -1, true);
    win.getGuiEnv()->addStaticText(L"Blue Background:", rect<s32>(685, 600, 755, 610), true, false, 0, -1, true);
    _volume_bar = win.getGuiEnv()->addScrollBar(true, rect<s32>(760, 440, 1160, 470), 0, VOLUME);
    _volume_bar->setMax(100);
    _volume_bar->setPos(this->_volume);
    _red_bar = win.getGuiEnv()->addScrollBar(true, rect<s32>(760, 490, 1160, 520), 0, RED);
    _red_bar->setMax(255);
    _red_bar->setPos(win.getBackgroundColor().getRed());
    _green_bar = win.getGuiEnv()->addScrollBar(true, rect<s32>(760, 540, 1160, 570), 0, GREEN);
    _green_bar->setMax(255);
    _green_bar->setPos(win.getBackgroundColor().getGreen());
    _blue_bar = win.getGuiEnv()->addScrollBar(true, rect<s32>(760, 590, 1160, 620), 0, BLUE);
    _blue_bar->setMax(255);
    _blue_bar->setPos(win.getBackgroundColor().getBlue());
}

indie::OptionMenu::~OptionMenu()
{
}

void indie::OptionMenu::particleTypeActivation(indie::WindowHandler &win, MenuEventReceiver &receiver)
{
    if (receiver.getButtonID() == MENU_BUTTON::PARTICLE_FLAME ||
        receiver.getButtonID() == MENU_BUTTON::PARTICLE_SNOW ||
        receiver.getButtonID() == MENU_BUTTON::PARTICLE_RAIN) {
        setParticle(win);
        receiver.setButtonID(MENU_BUTTON::NOTHING);
    }
}

void indie::OptionMenu::loopOptionMenu(indie::WindowHandler &win)
{
    MenuEventReceiver receiver(win);

    win.getDevice()->setEventReceiver(&receiver);
    while (win.getDevice()->run() && win.getVideoDriver() != NULL && receiver.getButtonID() != MENU_BUTTON::BACK) {
        if (win.getDevice()->isWindowActive()) {
            particleTypeActivation(win, receiver);
            win.getVideoDriver()->beginScene(true, true, win.getBackgroundColor());
            displayGoodLogoColor(win);
            win.getGuiEnv()->drawAll();
            win.getSceneManager()->drawAll();
            win.getVideoDriver()->endScene();
        }
    }
}