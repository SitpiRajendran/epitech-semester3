/*
** EPITECH PROJECT, 2020
** CppPool - d06
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string str)
{
    name = str;
}

SickKoala::~SickKoala(void)
{
    std::cout << "Mr." << name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke(void)
{
    std::cout << "Mr." << name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
    if (str.compare("Mars") == 0) {
        std::cout << "Mr." << name << ": Mars, and it kreogs!" << std::endl;
        return true;
    } else if (str.compare("Buronzand") == 0) {
        std::cout << "Mr." << name;
        std::cout << ": And you'll sleep right away!" << std::endl;
        return true;
    } else {
        std::cout << "Mr." << name << ": Goerkreog!" << std::endl;
        return false;
    }
}

void SickKoala::overDrive(std::string str)
{
    std::cout << "Mr." << name <<  ": ";
    while (str.find("Kreog!") != std::string::npos)
        str.replace(str.find("Kreog!"), 6, "1337!");
    std::cout << str << std::endl;
}

std::string SickKoala::getName(void)
{
    return name;
}

