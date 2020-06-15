/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** TitleScreen
*/

#ifndef TITLESCREEN_HPP_
#define TITLESCREEN_HPP_

#include "WindowHandler.hpp"
#include "Particle.hpp"

namespace indie
{
    class TitleScreen
    {
        public:
            TitleScreen(WindowHandler &win);
            ~TitleScreen();
            int launch(WindowHandler &win);
            void animationTransition(WindowHandler &win);
        private:
            shared_ptr<Particle> _particle;
    };
}

#endif /* !TITLESCREEN_HPP_ */
