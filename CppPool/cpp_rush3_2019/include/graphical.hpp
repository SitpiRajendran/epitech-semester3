/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** graphical
*/

#ifndef __GRAPHICAL_OPTION_HPP__
#define __GRAPHICAL_OPTION_HPP__

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "swap.hpp"
#include "GetUserHostName.hpp"
#include "ram.hpp"
#include "date.hpp"
#include "CoreModel.hpp"
#include "Sys.hpp"
#include "Frequency.hpp"
#include "cpu.hpp"
#include "network.hpp"

typedef struct data_s {
    GetUserName username;
    GetHostName hostname;
    Time time;
    Sys sys;
    CoreModel coremodel;
    Ram ram;
    sf::Sprite background;
    Frequency freq;
    Swap swap;
    Cpu cpu;
    network network_v;
    std::vector<sf::RectangleShape> graph;
} data_t;

class graphical_i {
    public:
        graphical_i();
        ~graphical_i();
        void addShape(sf::Vector2f, sf::Color, sf::Vector2f);
        void display_shape();
        sf::RenderWindow *_window;
        std::vector<sf::RectangleShape> _shapes;
        sf::Font _font;
};

int load_gi_and_data();
int graphical_interface(graphical_i &, data_t);
float get_ram_scale(std::string);

#endif