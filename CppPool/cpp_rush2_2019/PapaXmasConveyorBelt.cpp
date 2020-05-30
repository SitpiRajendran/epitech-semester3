/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** PapaXmasConveyorBelt
*/

#include "Wrap.hpp"
#include "PapaXmasConveyorBelt.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    this->_object = NULL;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
}

void PapaXmasConveyorBelt::putObject(Object *object)
{
    if (this->_object)
        this->_object = object;
}

Object *PapaXmasConveyorBelt::takeObject(void)
{
    Object *new_obj = this->_object;

    if (this->_object) {
        this->_object = NULL;
        return (new_obj);
    }
    return (NULL);
}

void PapaXmasConveyorBelt::santaVanished(void)
{
    this->_object = NULL;
}

Wrap *PapaXmasConveyorBelt::IN(void)
{
    Wrap *wrap;

    if (this->_object != NULL && (this->takeObject()->GIFTPAPER || this->takeObject()->BOX)) {
        wrap = (Wrap *)this->_object;
        this->_object = NULL;
        return (wrap);
    }
    else
        std::cerr << "There is no object into the ConveyorBlet" << std::endl;
    return (NULL);
}

void PapaXmasConveyorBelt::OUT(void)
{
    this->_object = NULL;
}

IConveyorBelt *PapaXmasConveyorBelt::createConveyorBelt(void)
{
    IConveyorBelt *iconveyorbelt = new PapaXmasConveyorBelt;
    return (iconveyorbelt);
}