/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** initialize_graphicals_data
*/

#include "graphical.hpp"

int load_gi_and_data4(graphical_i &gi, data_t data)
{
    data.cpu._text.setFont(gi._font);
    data.cpu._text.setCharacterSize(30);
    data.cpu._text.setFillColor(sf::Color::White);
    data.cpu._text.setString("Usage : " + data.cpu.getValue());
    data.cpu._text.setPosition(675, 220);
    data.network_v._text.setFont(gi._font);
    data.network_v._text.setCharacterSize(14);
    data.network_v._text.setFillColor(sf::Color::White);
    data.network_v._text.setString(data.network_v.getName() + ": " + data.network_v.getValue());
    data.network_v._text.setPosition(30, 840);
    return (graphical_interface(gi, data));
}

int load_gi_and_data3(graphical_i &gi, data_t data)
{
    sf::Texture texture;

    texture.loadFromFile("./resources/space.png");
    data.background.setTexture(texture);
    data.ram._shape.setFillColor(sf::Color::Green);
    data.ram._shape.setPosition(720, 30);
    data.ram._shape.setSize(sf::Vector2f(500, 30));
    data.freq._text.setFont(gi._font);
    data.freq._text.setCharacterSize(20);
    data.freq._text.setFillColor(sf::Color::White);
    data.freq._text.setString(data.freq.getName() + ": " + data.freq.getValue());
    data.freq._text.setPosition(85, 365);
    data.swap._text.setFont(gi._font);
    data.swap._text.setCharacterSize(30);
    data.swap._text.setFillColor(sf::Color::White);
    data.swap._text.setString(data.swap.getName() + ": ");
    data.swap._text.setPosition(85, 420);
    data.swap._shape.setFillColor(sf::Color::Green);
    data.swap._shape.setPosition(180, 426);
    data.swap._shape.setSize(sf::Vector2f(300, 30));
    return (load_gi_and_data4(gi, data));
}

int load_gi_and_data2(graphical_i &gi, data_t data)
{
    data.time._text.setFont(gi._font);
    data.time._text.setCharacterSize(24);
    data.time._text.setFillColor(sf::Color::White);
    data.time._text.setString(data.time.getName() + data.time.getValue());
    data.time._text.setPosition(55, 220);
    data.sys._text.setFont(gi._font);
    data.sys._text.setCharacterSize(16);
    data.sys._text.setFillColor(sf::Color::White);
    data.sys._text.setString(data.sys.getName() + ": " + data.sys.getValue());
    data.sys._text.setPosition(1310, 30);
    data.coremodel._text.setFont(gi._font);
    data.coremodel._text.setCharacterSize(20);
    data.coremodel._text.setFillColor(sf::Color::White);
    data.coremodel._text.setString(data.coremodel.getName() + ": " + data.coremodel.getValue());
    data.coremodel._text.setPosition(1310, 100);
    return (load_gi_and_data3(gi, data));
}

int load_gi_and_data()
{
    graphical_i gi;
    data_t data;

    data.username._text.setFont(gi._font);
    data.username._text.setCharacterSize(24);
    data.username._text.setFillColor(sf::Color::White);
    data.username._text.setString(data.username.getName() + ": " + data.username.getValue());
    data.username._text.setPosition(55, 60);
    data.hostname._text.setFont(gi._font);
    data.hostname._text.setCharacterSize(24);
    data.hostname._text.setFillColor(sf::Color::White);
    data.hostname._text.setString(data.hostname.getName() + ": " + data.hostname.getValue());
    data.hostname._text.setPosition(55, 140);
    data.ram._text.setFont(gi._font);
    data.ram._text.setCharacterSize(30);
    data.ram._text.setFillColor(sf::Color::White);
    data.ram._text.setString(data.ram.getName() + ": ");
    data.ram._text.setPosition(640, 24);
    return (load_gi_and_data2(gi, data));
}