/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** WindowHandler
*/

#ifndef __WINDOW_HANDLER__
#define __WINDOW_HANDLER__

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <ostream>
#include <iostream>
#include <irrlicht.h>
#include <SFML/Audio.hpp>
#include <vector>

#include "Irrlicht.hpp"
#include "MyRemoteControler.hpp"
#include "Particle.hpp"
#include "SoundEffect.hpp"

namespace indie {
    class MyRemoteControler;
    class Particle;

    enum PARTICLE_TYPE {
        FLAME,
        SNOW,
        RAIN,
    };

    class WindowHandler {
        public:
            WindowHandler(std::string name, int width, int heigh);
            ~WindowHandler();
            WindowHandler &operator=(const WindowHandler &to_cmp);

            void setName(std::string name);
            void drawing(bool one, bool two, SColor color);
            void endScene();
            IrrlichtDevice *getDevice();
            ISceneManager *getSceneManager();
            IVideoDriver *getVideoDriver();
            ICameraSceneNode *getCamera();
            IGUIEnvironment *getGuiEnv();
            void playNewMusic(const std::string filename);
            bool musicIsActivated() const;
            void clearGuiEnv();
            void clearSmgr();
            void setVolume(float new_volume);
            float getVolume(void) const;
            void setBackgroundColor(SColor color);
            SColor getBackgroundColor() const;

            void addParticule(shared_ptr<Particle> &particle);
            void addParticuleExplosion(shared_ptr<Particle> &particle);
            void activateParticle();
            void desactivateParticle();
            void clearParticle();
            void clearParticleExplosion();
            void clearExplosionMusic();
            bool getParticleActivated() const;
            PARTICLE_TYPE getParticleType() const;
            void setParticleType(PARTICLE_TYPE type);
            void checkParticleExplosion();
            void addExplosionSound();
            void checkExplosionMusic();

        private:
            ISceneNode *node;
            ISceneManager *smgr;
            IVideoDriver *driver;
            IrrlichtDevice *device;
            ICameraSceneNode *camera;
            IGUIEnvironment *guienv;
            bool music_activated;
            shared_ptr<sf::Music> music;
            float volume;
            SColor backgroundColor;
            vector<shared_ptr<Particle>> particles;
            vector<shared_ptr<Particle>> particles_explosion;
            vector<shared_ptr<SoundEffect>> explosion_sound;
            bool particle_activated;
            PARTICLE_TYPE particle_type;
    };
}

#endif