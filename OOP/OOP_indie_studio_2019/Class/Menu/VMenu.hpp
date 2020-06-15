/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** VMenu
*/

#ifndef VMENU_HPP_
#define VMENU_HPP_

#include "WindowHandler.hpp"

namespace indie {
    class VMenu {
        public:
            virtual ~VMenu() = default;
            void setParticle(WindowHandler &win);
            void displayGoodLogoColor(WindowHandler &win);
    };
}

#endif /* !VMENU_HPP_ */
