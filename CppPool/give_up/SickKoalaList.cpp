/*
** EPITECH PROJECT, 2020
** CppPool - d6
** File description:
** SickKoalaList
*/

#include "SickKoalaList.hpp"

SickKoalaList::SickKoalaList(SickKoala *newkoala)
{
    patient = newkoala;
    next = NULL;
}

SickKoalaList::~SickKoalaList()
{
}

bool SickKoalaList::isEnd()
{
    if (this->next == NULL)
        return true;
    else
        return false;
}

void SickKoalaList::append(SickKoalaList *newkoala)
{

}

SickKoala *SickKoalaList::getFromName(std::string name)
{

}

SickKoala *SickKoalaList::removeFromName(std::string name)
{

}

SickKoala *SickKoalaList::getContent()
{
    return patient;
}

SickKoalaList *SickKoalaList::getNext()
{
    return next;
}

void SickKoalaList::dump(void)
{
    SickKoalaList *now = this;
    if (patient) {
        std::cout << "Patient: " << patient->name;
        while (now->next != NULL) {
            now = now->next;
            std::cout << ", " << patient->name;
        }
        std::cout << "." << std::endl;
    }
}