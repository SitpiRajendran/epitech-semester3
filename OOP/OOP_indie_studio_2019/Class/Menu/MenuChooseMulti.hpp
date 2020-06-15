/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuChooseMulti
*/

#ifndef MENUCHOOSEMULTI_HPP_
#define MENUCHOOSEMULTI_HPP_

#include "WindowHandler.hpp"
#include "Particle.hpp"
#include "VMenu.hpp"

namespace indie
{
    class MenuChooseMulti : public VMenu {
        public:
            MenuChooseMulti(WindowHandler &win);
            ~MenuChooseMulti();

            int loopMenu(WindowHandler &win);
            bool getIsSolo() const;
            bool getIsLoad() const;

        protected:
        private:
            IGUIButton *_start_button;
            IGUIButton *_load_button;
            IGUIButton *_multi_button;
            IGUIButton *_solo_button;
            IGUIButton *_back_button;
            bool _is_solo;
            bool _is_load;
    };
}

#endif /* !MENUCHOOSEMULTI_HPP_ */
