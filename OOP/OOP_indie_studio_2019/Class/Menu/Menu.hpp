/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "WindowHandler.hpp"
#include "Particle.hpp"
#include "VMenu.hpp"

namespace indie {
    class Menu : public VMenu {
        public:
            Menu(WindowHandler &win);
            ~Menu();

            int loopMenu(WindowHandler &win);

        protected:
        private:
            IGUIButton *_play_button;
            IGUIButton *_option_button;
            IGUIButton *_quit_button;
    };
}

#endif
