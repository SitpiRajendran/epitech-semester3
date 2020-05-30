/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string str)
{
    name = str;
    working = false;
    std::cout << "Dr." << name << ": I'm Dr." << name;
    std::cout << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::string p_name = patient->getName();
    std::ofstream outfile (p_name + ".report");
    int ran;
    char array[5][16] = {"Mars", "Buronzand", "Viagra", "Extasy", "Eucalyptus leaf"};

    std::cout << "Dr." << name << ": So what's goerking you Mr.";
    std::cout << p_name << "?" << std::endl;
    patient->poke();
    ran = random()%5;
    if (outfile.is_open()) {
        outfile << array[ran];
        outfile.close();
    }
}

void KoalaDoctor::timeCheck(void)
{
    if (working == false) {
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
        working = true;
    } else if (working == true) {
        std::cout << "Dr." << name;
        std::cout <<  ": Time to go home to my eucalyptus forest!" << std::endl;
        working = false;
    }
}

std::string KoalaDoctor::getName()
{
    return name;
}