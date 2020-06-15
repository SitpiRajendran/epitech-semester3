/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Particle
*/

#include "Particle.hpp"

indie::Particle::Particle(WindowHandler &win, std::string filepath, aabbox3d<irr::f32> box)
{
    _system = win.getSceneManager()->addParticleSystemSceneNode(false);
    _emitter = _system->createBoxEmitter(
        box, vector3df(0,0,0), 0, 0, SColor(0, 0, 0, 0), SColor(0, 255, 255, 255),
        0, 0, 0, dimension2df(0, 0), dimension2df(0, 0));
    _system->setEmitter(_emitter);
    _system->setMaterialFlag(EMF_LIGHTING, false);
    _system->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    _system->setMaterialTexture(0, win.getVideoDriver()->getTexture(filepath.c_str()));
    _system->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
    _particle_life = -1;
}

indie::Particle::Particle(irrManager_t &manager, std::string filepath, aabbox3d<irr::f32> box)
{
    _system = manager.smgr->addParticleSystemSceneNode(false);
    _emitter = _system->createBoxEmitter(
        box, vector3df(0,0,0), 0, 0, SColor(0, 0, 0, 0), SColor(0, 255, 255, 255),
        0, 0, 0, dimension2df(0, 0), dimension2df(0, 0));
    _system->setEmitter(_emitter);
    _system->setMaterialFlag(EMF_LIGHTING, false);
    _system->setMaterialFlag(EMF_ZWRITE_ENABLE, false);
    _system->setMaterialTexture(0, manager.driver->getTexture(filepath.c_str()));
    _system->setMaterialType(EMT_TRANSPARENT_ADD_COLOR);
    _particle_life = 300 + manager.device->getTimer()->getTime();
}

void indie::Particle::setMenuSettingParticleFlame()
{
    setParticleBySec(80, 120);
    setParticleColor(SColor(0, 100, 100, 100), SColor(0, 255, 255, 255));
    setParticleDimension(dimension2df(3.0f,3.0f), dimension2df(8.0f,8.0f));
    setParticleDirection(vector3df(0.0f,0.02f,0.0f));
    setParticleLifeTime(200, 600);
    setParticleMaxAngle(20);
}

void indie::Particle::setMenuSettingParticleSnow()
{
    setParticleBySec(100, 120);
    setParticleColor(SColor(0, 100, 100, 100), SColor(0, 255, 255, 255));
    setParticleDimension(dimension2df(1.0f,1.0f), dimension2df(4.0f,4.0f));
    setParticleDirection(vector3df(0.0f,-0.006f,0.0f));
    setParticleLifeTime(5000, 7000);
    setParticleMaxAngle(40);
}

void indie::Particle::setMenuSettingParticleRain()
{
    setParticleBySec(400, 500);
    setParticleColor(SColor(0, 100, 100, 100), SColor(0, 255, 255, 255));
    setParticleDimension(dimension2df(0.2f,0.5f), dimension2df(0.3f,1.0f));
    setParticleDirection(vector3df(0.0f,-0.03f,0.0f));
    setParticleLifeTime(1500, 2000);
    setParticleMaxAngle(10);
}

void indie::Particle::setMenuSettingParticleExplosion()
{
    setParticleBySec(600, 800);
    setParticleColor(SColor(0, 100, 100, 100), SColor(0, 255, 255, 255));
    setParticleDimension(dimension2df(3.0f,3.0f), dimension2df(6.0f,6.0f));
    setParticleDirection(vector3df(0.0f,0.02f,0.0f));
    setParticleLifeTime(150, 300);
    setParticleMaxAngle(360);
}

void indie::Particle::setMenuEndSettingParticle()
{
    setParticleBySec(60, 140);
    setParticleDimension(dimension2df(3.0f,3.0f), dimension2df(6.0f,6.0f));
    setParticleDirection(vector3df(0.0f,0.02f,0.0f));
    setParticleLifeTime(600, 800);
    setParticleMaxAngle(360);
}

indie::Particle::~Particle()
{
    _emitter->drop();
    _system->remove();
}

void indie::Particle::setParticleColor(SColor min, SColor max)
{
    _emitter->setMinStartColor(min);
    _emitter->setMaxStartColor(max);
    _system->setEmitter(_emitter);
}

void indie::Particle::setParticleLifeTime(u32 min, u32 max)
{
    _emitter->setMinLifeTime(min);
    _emitter->setMaxLifeTime(max);
    _system->setEmitter(_emitter);
}

void indie::Particle::setParticleMaxAngle(s32 angle)
{
    _emitter->setMaxAngleDegrees(angle);
    _system->setEmitter(_emitter);
}

void indie::Particle::setParticleDimension(dimension2df min, dimension2df max)
{
    _emitter->setMinStartSize(min);
    _emitter->setMaxStartSize(max);
    _system->setEmitter(_emitter);
}

void indie::Particle::setParticleBySec(u32 min, u32 max)
{
    _emitter->setMinParticlesPerSecond(min);
    _emitter->setMaxParticlesPerSecond(max);
    _system->setEmitter(_emitter);
}

void indie::Particle::setParticleDirection(vector3df direction)
{
    _emitter->setDirection(direction);
    _system->setEmitter(_emitter);
}

void indie::Particle::setVisible(bool state)
{
    _system->setVisible(state);
    if (state == false)
        _system->clearParticles();
}

IParticleSystemSceneNode *indie::Particle::getSystem() const
{
    return (_system);
}

int indie::Particle::getLifeTime() const
{
    return (_particle_life);
}