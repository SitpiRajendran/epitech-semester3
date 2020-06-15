/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** MenuEndGame
*/

#ifndef MENUENDGAME_HPP_
#define MENUENDGAME_HPP_

#include "WindowHandler.hpp"
#include "VMenu.hpp"

namespace indie {
    class MenuEndGame : public VMenu {
        public:
            MenuEndGame(WindowHandler &win);
            ~MenuEndGame();

            int loopMenu(WindowHandler &win, std::string &winner_name);
            void initializeAnimation(WindowHandler &win, std::string &winner_name);
            void changeParticleColor(WindowHandler &win);

        protected:
        private:
            IGUIButton *_replay_button;
            IGUIButton *_back_button;
            IAnimatedMeshSceneNode *_perso;
            scene::ISceneNodeAnimator *_anim;
            shared_ptr<Particle> _particle;
    };
}

#endif /* !MENUENDGAME_HPP_ */