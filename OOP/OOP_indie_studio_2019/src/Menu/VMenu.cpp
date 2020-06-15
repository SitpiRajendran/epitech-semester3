/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** VMenu
*/

#include "VMenu.hpp"
#include "Particle.hpp"

void indie::VMenu::displayGoodLogoColor(WindowHandler &win)
{
    ITexture *texture = NULL;

    if (win.getBackgroundColor().getRed() >= 150 || win.getBackgroundColor().getGreen() >= 150 || win.getBackgroundColor().getBlue() >= 150)
        texture = win.getVideoDriver()->getTexture("resources/Images/logo_game_black.png");
    else
        texture = win.getVideoDriver()->getTexture("resources/Images/logo_game_white.png");

    win.getVideoDriver()->draw2DImage(texture, core::position2d<s32>(760,100), core::rect<s32>(0,0,420,300), 0, video::SColor(255,255,255,255), true);
}

void indie::VMenu::setParticle(WindowHandler &win)
{
    try {
        if (win.getParticleType() == PARTICLE_TYPE::FLAME) {
            shared_ptr<Particle> particle_col1 = std::make_shared<Particle>(win, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(20, -111, 20, 20, -111, 20));
            shared_ptr<Particle> particle_col2 = std::make_shared<Particle>(win, "resources/particle/particle_red.bmp", aabbox3d<irr::f32>(-20, -111, 20, -20, -111, 20));

            win.addParticule(particle_col1);
            particle_col1->setMenuSettingParticleFlame();
            particle_col1->setParticleLifeTime(600, 1200);
            particle_col1->setParticleDirection(vector3df(0.005f,0.02f,0.005f));
            win.addParticule(particle_col2);
            particle_col2->setMenuSettingParticleFlame();
            particle_col2->setParticleLifeTime(600, 1200);
            particle_col2->setParticleDirection(vector3df(0.005f,0.02f,0.005f));
        } else if (win.getParticleType() == PARTICLE_TYPE::SNOW) {
            shared_ptr<Particle> particle = std::make_shared<Particle>(win, "resources/particle/particle_white.bmp", aabbox3d<irr::f32>(-40, -81, -10, 40, -81, 40));

            win.addParticule(particle);
            particle->setMenuSettingParticleSnow();
        } else {
            shared_ptr<Particle> particle = std::make_shared<Particle>(win, "resources/particle/particle_green.jpg", aabbox3d<irr::f32>(-40, -71, -10, 40, -71, 40));

            win.addParticule(particle);
            particle->setMenuSettingParticleRain();
        }
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for particle"));
    }
}