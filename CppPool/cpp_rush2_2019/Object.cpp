/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Object
*/

#include "Object.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"

Object::Object(const std::string &title)
{
    this->_title = title;
    this->_id = this->NOTHING;
}

Object::~Object(void)
{
}

Object **MyUnitTests(void)
{
    Object **object = new Object*[2];

    object[0] = new LittlePony("happy pony");
    object[1] = new Teddy("cuddles");
    return object;
}

Object *MyUnitTests(Object **items)
{
    if (!items || !items[0] || !items[1] || !items[2]) {
        std::cerr << "[MyUnitTests][Object.cpp]: Null **Object \"items\" :/" << std::endl;
        exit(84);
    } else if (items[0]->getID() != 1 || items[1]->getID() != 3 || items[2]->getID() != 4) {
        std::cerr << "[MyUnitTests][Object.cpp]: Bad id for ted, cardboard or giftpaper :/" << std::endl;
        exit(84);
    }
    Teddy *ted = (Teddy *)items[0];
    Box *cardboard = (Box *)items[1];
    GiftPaper *paper = (GiftPaper *)items[2];

    cardboard->openMe();
    cardboard->wrapMeThat(ted);
    cardboard->closeMe();
    paper->wrapMeThat(cardboard);

    return paper;
}