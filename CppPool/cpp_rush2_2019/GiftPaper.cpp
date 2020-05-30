/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** GiftPaper
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string &title) : Wrap(title)
{
    _object = NULL;
    this->_id = this->GIFTPAPER;
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::wrapMeThat(Object *object)
{
    if (this->_object)
        std::cerr << "There is already something in there o_O" << std::endl;
    else {
        std::cout << "tuuuut tuuut tuut" << std::endl;
        this->_object = object;
    }
}
