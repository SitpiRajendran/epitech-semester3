/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Element
*/

#include "Element.hpp"
namespace arcade {
    Element::Element(Position pos, std::string elem, Color color, Image image)
    {
        _position = pos;
        _element = elem;
        _color = color;
        _image = image;
    }

    Element::Element()
    {
    }

    Element::~Element()
    {
    }


    Position Element::getPosition() const {
        return _position;
    }

    std::string Element::getElement() const {
        return _element;
    }

    Color Element::getColor() const {
        return _color;
    }

    Image Element::getImage() const {
        return _image;
    }

    void Element::setPosition(Position position) {
        _position = position;
    }

    void Element::setElement(std::string &element) {
        _element = element;
    }

    void Element::setColor(Color &color) {
        _color = color;
    }

    void Element::setImage(Image &image) {
        _image = image;
    }
};