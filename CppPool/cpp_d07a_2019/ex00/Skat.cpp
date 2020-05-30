/*
** EPITECH PROJECT, 2020
** CppPool - D07a
** File description:
** Skat
*/

#include "Skat.hpp"

Skat::Skat(const std::string &name, int stimPaks)
{
    _name = name;
    _stim = stimPaks;
}

Skat::Skat(const std::string &name)
{
    _name = name;
    _stim = 15;
}

Skat::Skat(int stimPaks)
{
    _name = "bob";
    _stim = stimPaks;
}

Skat::Skat(void)
{
    _name = "bob";
    _stim = 15;
}

Skat::~Skat()
{
}

int &Skat::stimPaks()
{
    return _stim;
}

const std::string &Skat::name()
{
    return _name;
}

void Skat::shareStimPaks(int number, int &stock)
{
    if (number > _stim)
        std::cout << "Don't be greedy" << std::endl;
    else {
        _stim -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0)
        std::cout << "Hey boya, did you forget something?" << std::endl;
    else
        _stim += number;
}

void Skat::useStimPaks()
{
    if (_stim > 0) {
        std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
        _stim--;
    } else
        std::cout << "Mediiiiiic" << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << _name << " reporting " << _stim;
    std::cout << " stimpaks remaining sir!" << std::endl;
}