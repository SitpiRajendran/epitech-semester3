/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Particle
*/

#ifndef PARTICLE_HPP_
#define PARTICLE_HPP_

#include "Irrlicht.hpp"
#include "WindowHandler.hpp"
#include "manager.h"

namespace indie
{
    class WindowHandler;

    class Particle {
        public:
            Particle(WindowHandler &win, std::string filepath, aabbox3d<irr::f32> box);
            Particle(irrManager_t &manager, std::string filepath, aabbox3d<irr::f32> box);
            ~Particle();
            void setParticleColor(SColor min, SColor max);
            void setParticleLifeTime(u32 min, u32 max);
            void setParticleMaxAngle(s32 angle);
            void setParticleDimension(dimension2df min, dimension2df max);
            void setParticleBySec(u32 min, u32 max);
            void setParticleDirection(vector3df direction);
            void setMenuSettingParticleFlame();
            void setMenuSettingParticleSnow();
            void setMenuSettingParticleRain();
            void setMenuSettingParticleExplosion();
            void setMenuEndSettingParticle();
            void setVisible(bool state);
            IParticleSystemSceneNode *getSystem() const;
            int getLifeTime() const;

        protected:
        private:
            IParticleSystemSceneNode *_system;
            IParticleEmitter *_emitter;
            int _particle_life;
    };
}

#endif /* !PARTICLE_HPP_ */
