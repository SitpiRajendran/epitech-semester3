/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** ConveyorBelt
*/

#include "Wrap.hpp"
#include "ConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

ConveyorBelt::ConveyorBelt()
{
    this->_object = NULL;
}

ConveyorBelt::~ConveyorBelt()
{
}

void ConveyorBelt::putObject(Object *object)
{
    if (this->_object)
        this->_object = object;
}

Object *ConveyorBelt::takeObject(void)
{
    Object *new_obj = this->_object;

    if (this->_object) {
        this->_object = NULL;
        return (new_obj);
    }
    return (NULL);
}

void ConveyorBelt::santaVanished(void)
{
    this->_object = NULL;
}

Wrap *ConveyorBelt::IN(void)
{
    int number = random() % 2;

    if (this->_object == NULL) {
        if (number == 0)
            _object = new Box("Carboard Box");
        if (number == 1)
            _object = new GiftPaper("PaperGift");
        return (Wrap*) _object;
    } else
        std::cerr << "There is already an object into the ConveyorBlet" << std::endl;
    return (NULL);
}

void ConveyorBelt::OUT(void)
{
    this->_object = NULL;
}

IConveyorBelt *ConveyorBelt::createConveyorBelt(void)
{
    IConveyorBelt *iconveyorbelt = new ConveyorBelt;
    return (iconveyorbelt);
}