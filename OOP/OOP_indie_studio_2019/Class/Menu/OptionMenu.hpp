/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** OptionMenu
*/

#ifndef OPTIONMENU_HPP_
#define OPTIONMENU_HPP_

#include "WindowHandler.hpp"
#include "MenuEventReceiver.hpp"
#include "VMenu.hpp"

namespace indie {
    class OptionMenu : public VMenu {
        public:
            OptionMenu(WindowHandler &win);
            ~OptionMenu();

            void loopOptionMenu(WindowHandler &win);
            void particleTypeActivation(WindowHandler &win, MenuEventReceiver &receiver);


        protected:
        private:
            float _volume;
            IGUIButton *_quit_button;
            IGUIButton *_particle_activated_button;
            IGUIButton *_particle_flame_button;
            IGUIButton *_particle_rain_button;
            IGUIButton *_particle_snow_button;
            IGUIScrollBar *_volume_bar;
            IGUIScrollBar *_red_bar;
            IGUIScrollBar *_green_bar;
            IGUIScrollBar *_blue_bar;
    };
}

#endif /* !OPTIONMENU_HPP_ */
