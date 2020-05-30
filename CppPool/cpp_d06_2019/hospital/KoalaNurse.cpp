/*
** EPITECH PROJECT, 2020
** CppPool - d6
** File description:
** ex 3 - KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int val)
{
    id = val;
    working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string str, SickKoala *patient)
{
    patient->takeDrug(str);
}

std::string KoalaNurse::readReport(std::string file)
{
    std::ifstream ifs (file);
    std::ostringstream pbuf;
    std::string str;

    if (ifs.is_open()) {
        file.erase(file.end()-7, file.end());
        std::cout << "Nurse " << id << ": Kreog! Mr." << file << " needs a ";
        pbuf << ifs.rdbuf();
        str = pbuf.str();
        std::cout << str << "!" << std::endl;
        return str;
    }
    return str;
}

void KoalaNurse::timeCheck(void)
{
    if (working == false) {
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
        working = true;
    } else if (working == true) {
        std::cout << "Nurse " << id;
        std::cout <<  ": Time to go home to my eucalyptus forest!" << std::endl;
        working = false;
    }
}

int KoalaNurse::getID()
{
    return id;
}