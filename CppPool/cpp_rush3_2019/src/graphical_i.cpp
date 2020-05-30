/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** graphical_i
*/

#include "GetUserHostName.hpp"
#include "graphical.hpp"

graphical_i::graphical_i()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "graphical interface");
    this->_window->setFramerateLimit(1);
    this->_font.loadFromFile("./resources/ariali.ttf");
    this->addShape(sf::Vector2f(520, 290), sf::Color(50, 50, 50), sf::Vector2f(10, 10));
    this->addShape(sf::Vector2f(500, 270), sf::Color(120, 120, 120), sf::Vector2f(20, 20));
    this->addShape(sf::Vector2f(460, 70), sf::Color(50, 50, 50), sf::Vector2f(40, 40));
    this->addShape(sf::Vector2f(452, 62), sf::Color(140, 140, 180), sf::Vector2f(44, 44));
    this->addShape(sf::Vector2f(460, 70), sf::Color(50, 50, 50), sf::Vector2f(40, 120));
    this->addShape(sf::Vector2f(452, 62), sf::Color(140, 140, 180), sf::Vector2f(44, 124));
    this->addShape(sf::Vector2f(460, 70), sf::Color(50, 50, 50), sf::Vector2f(40, 200));
    this->addShape(sf::Vector2f(452, 62), sf::Color(140, 140, 180), sf::Vector2f(44, 204));
    this->addShape(sf::Vector2f(620, 140), sf::Color(50, 50, 50), sf::Vector2f(1290, 10));
    this->addShape(sf::Vector2f(600, 120), sf::Color(120, 120, 180), sf::Vector2f(1300, 20));
    this->addShape(sf::Vector2f(620, 10), sf::Color(50, 50, 50), sf::Vector2f(1290, 74));
    this->addShape(sf::Vector2f(610, 60), sf::Color(50, 50, 50), sf::Vector2f(625, 15));
    this->addShape(sf::Vector2f(600, 50), sf::Color(120, 120, 120), sf::Vector2f(630, 20));
    this->addShape(sf::Vector2f(500, 30), sf::Color::White, sf::Vector2f(720, 30));
    this->addShape(sf::Vector2f(470, 140), sf::Color(50, 50, 50), sf::Vector2f(40, 340));
    this->addShape(sf::Vector2f(460, 130), sf::Color(150, 120, 120), sf::Vector2f(45, 345));
    this->addShape(sf::Vector2f(470, 10), sf::Color(50, 50, 50), sf::Vector2f(40, 400));
    this->addShape(sf::Vector2f(300, 30), sf::Color::White, sf::Vector2f(180, 426));
    this->addShape(sf::Vector2f(1200, 600), sf::Color(50, 50, 50), sf::Vector2f(640, 200));
    this->addShape(sf::Vector2f(1190, 590), sf::Color(120, 120, 120), sf::Vector2f(645, 205));
    this->addShape(sf::Vector2f(1200, 5), sf::Color(50, 50, 50), sf::Vector2f(640, 270));
    this->addShape(sf::Vector2f(5, 530), sf::Color(50, 50, 50), sf::Vector2f(940, 270));
    this->addShape(sf::Vector2f(5, 530), sf::Color(50, 50, 50), sf::Vector2f(1240, 270));
    this->addShape(sf::Vector2f(5, 530), sf::Color(50, 50, 50), sf::Vector2f(1540, 270));
    this->addShape(sf::Vector2f(1200, 5), sf::Color(50, 50, 50), sf::Vector2f(640, 525));
    this->addShape(sf::Vector2f(800, 600), sf::Color(120, 120, 120), sf::Vector2f(20, 820));
}

graphical_i::~graphical_i()
{
}

void graphical_i::addShape(sf::Vector2f size, sf::Color color, sf::Vector2f pos)
{
    sf::RectangleShape shape(size);
    shape.setFillColor(color);
    shape.setPosition(pos.x, pos.y);
    this->_shapes.push_back(shape);
}

void graphical_i::display_shape()
{
    for (int i = 0; i < this->_shapes.size(); i++)
        this->_window->draw(this->_shapes[i]);
}