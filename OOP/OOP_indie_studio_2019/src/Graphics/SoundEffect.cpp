/*
** EPITECH PROJECT, 2020
** indie2
** File description:
** SoundEffect
*/

#include "SoundEffect.hpp"

indie::SoundEffect::SoundEffect(char const *path, int _timeMax, irrManager_t manager)
{
    try {
        music = make_shared<sf::Music>();
        if (this->music->openFromFile(path) == false)
            throw(Exception("can't load music"));
        music->play();
        music->setVolume(20);
        timer = manager.device->getTimer();
        time = timer->getTime();
        timeMax = timer->getTime() + _timeMax;
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Music"));
    }
}

indie::SoundEffect::~SoundEffect()
{
    music->stop();
}

int indie::SoundEffect::timePassed()
{
    time = timer->getTime();
    if (time > timeMax)
        return (1);
    return (0);
}