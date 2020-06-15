/*
** EPITECH PROJECT, 2020
** TonyPart
** File description:
** MenuEventReceiver
*/

#ifndef MENUEVENTRECEIVER_HPP_
#define MENUEVENTRECEIVER_HPP_

#include "Irrlicht.hpp"
#include "Menu.hpp"
#include "WindowHandler.hpp"

namespace indie
{
    enum MENU_BUTTON {
        NOTHING,
        PLAY,
        OPTION,
        BACK,
        VOLUME,
        RED,
        GREEN,
        BLUE,
        PARTICLE_ACTIVATED,
        PARTICLE_FLAME,
        PARTICLE_SNOW,
        PARTICLE_RAIN,
        MULTI,
        SOLO,
        LOAD,
        QUIT,
    };

    class MenuEventReceiver : public IEventReceiver
    {
        public:
            MenuEventReceiver(WindowHandler &win);
            MenuEventReceiver(WindowHandler &win, bool &is_solo, bool &is_load);
            virtual bool OnEvent(const SEvent &event);
            MENU_BUTTON getButtonID() const;
            void setButtonID(MENU_BUTTON id);

        private:
            WindowHandler *_win;
            MENU_BUTTON _button_clicked;
            bool *_is_solo;
            bool *_is_load;
    };
}

#endif /* !MENUEVENTRECEIVER_HPP_ */
