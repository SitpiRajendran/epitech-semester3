/*
** EPITECH PROJECT, 2020
** TonyPart
** File description:
** MenuEventReceiver
*/

#include "MenuEventReceiver.hpp"

indie::MenuEventReceiver::MenuEventReceiver(indie::WindowHandler &win)
{
    _win = &win;
    _button_clicked = MENU_BUTTON::NOTHING;
}

indie::MenuEventReceiver::MenuEventReceiver(indie::WindowHandler &win, bool &is_solo, bool &is_load)
{
    _win = &win;
    _button_clicked = MENU_BUTTON::NOTHING;
    _is_solo = &is_solo;
    _is_load = &is_load;
}

bool indie::MenuEventReceiver::OnEvent(const SEvent &event)
{
    if (event.EventType == EET_GUI_EVENT) {
        s32 id = event.GUIEvent.Caller->getID();
        switch(event.GUIEvent.EventType) {
        case EGET_BUTTON_CLICKED:
            switch(id) {
            case MENU_BUTTON::PLAY: _button_clicked = MENU_BUTTON::PLAY; return (true);
            case MENU_BUTTON::OPTION: _button_clicked = MENU_BUTTON::OPTION; return (true);
            case MENU_BUTTON::BACK: _button_clicked = MENU_BUTTON::BACK; return (true);
            case MENU_BUTTON::PARTICLE_ACTIVATED:
                _button_clicked = MENU_BUTTON::PARTICLE_ACTIVATED;
                if (_win->getParticleActivated() == true)
                    _win->desactivateParticle();
                else
                    _win->activateParticle();
                return (true);
            case MENU_BUTTON::PARTICLE_FLAME:
                _button_clicked = MENU_BUTTON::PARTICLE_FLAME;
                _win->clearParticle();
                _win->setParticleType(PARTICLE_TYPE::FLAME);
                return (true);
            case MENU_BUTTON::PARTICLE_SNOW:
                _button_clicked = MENU_BUTTON::PARTICLE_FLAME;
                _win->clearParticle();
                _win->setParticleType(PARTICLE_TYPE::SNOW);
                return (true);
            case MENU_BUTTON::PARTICLE_RAIN:
                _button_clicked = MENU_BUTTON::PARTICLE_FLAME;
                _win->clearParticle();
                _win->setParticleType(PARTICLE_TYPE::RAIN);
                return (true);
            case MENU_BUTTON::MULTI:
                _button_clicked = MENU_BUTTON::MULTI;
                *_is_solo = false;
                return (true);
            case MENU_BUTTON::SOLO:
                _button_clicked = MENU_BUTTON::SOLO;
                *_is_solo = true;
                return (true);
            case MENU_BUTTON::LOAD:
                _button_clicked = MENU_BUTTON::LOAD;
                *_is_load = (*_is_load == false ? true : false);
                return (true);
            case MENU_BUTTON::QUIT:
                _button_clicked = MENU_BUTTON::QUIT;
                _win->getDevice()->closeDevice();
                return (true);
            }
        case EGET_SCROLL_BAR_CHANGED:
            switch(id) {
            case MENU_BUTTON::VOLUME:
                _button_clicked = MENU_BUTTON::VOLUME;
                _win->setVolume(((IGUIScrollBar*)event.GUIEvent.Caller)->getPos());
                return (true);
            case MENU_BUTTON::RED:
                _button_clicked = MENU_BUTTON::RED;
                _win->setBackgroundColor(SColor(0, ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos(), _win->getBackgroundColor().getGreen(), _win->getBackgroundColor().getBlue()));
                return (true);
            case MENU_BUTTON::GREEN:
                _button_clicked = MENU_BUTTON::GREEN;
                _win->setBackgroundColor(SColor(0, _win->getBackgroundColor().getRed(), ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos(), _win->getBackgroundColor().getBlue()));
                return (true);
            case MENU_BUTTON::BLUE:
                _button_clicked = MENU_BUTTON::BLUE;
                _win->setBackgroundColor(SColor(0, _win->getBackgroundColor().getRed(), _win->getBackgroundColor().getGreen(), ((IGUIScrollBar*)event.GUIEvent.Caller)->getPos()));
                return (true);
            }
        }
    }
    return (false);
}

indie::MENU_BUTTON indie::MenuEventReceiver::getButtonID() const
{
    return (_button_clicked);
}

void indie::MenuEventReceiver::setButtonID(indie::MENU_BUTTON id)
{
    _button_clicked = id;
}