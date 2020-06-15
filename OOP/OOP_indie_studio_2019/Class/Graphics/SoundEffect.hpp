/*
** EPITECH PROJECT, 2020
** indie2
** File description:
** SoundEffect
*/

#ifndef SOUNDEFFECT_HPP_
#define SOUNDEFFECT_HPP_

#include "manager.h"
#include <SFML/Audio.hpp>
#include <memory>


namespace indie
{
    class SoundEffect
    {
    public:
        SoundEffect(char const *path, int timeMax, irrManager_t manager);
        ~SoundEffect();
        int timePassed();

    protected:
    private:
        shared_ptr<sf::Music> music;
        ITimer *timer;
        u32 time;
        u32 timeMax;
    };
} // namespace indie

#endif /* !SOUNDEFFECT_HPP_ */
