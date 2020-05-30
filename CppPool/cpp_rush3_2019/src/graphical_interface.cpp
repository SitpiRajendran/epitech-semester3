/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** graphical_interface
*/

#include "graphical.hpp"

float calcul_ram(float f1, std::string str)
{
    std::string::size_type i = 0;
    str = str.substr(31);
    std::cout << f1 << std::endl;
    std::cout << str << std::endl;
    float f2 = std::stof(str.substr(i));
    if (f1 / f2 < 0)
        return ((f1 / f2) * -1);
    return (f1 / f2);
}

void draw_graph(data_t data, graphical_i gi)
{
    std::vector<sf::RectangleShape>::iterator graph = data.graph.begin();
    int x = 700;
    int y = 330;
    int i = 0;

    if (graph == data.graph.end())
        return;
    while (i < data.graph.size()) {
        gi._window->draw(graph[i]);
        i++;
        if (x < 1500)
            x += 300;
        else {
            x = 700;
            y += 290;
        }
    }
}

int manage_disp(graphical_i &gi, data_t data)
{
    std::vector<eachCPU>::iterator cpu = data.cpu._list.begin();
    //std::vector<²>::iterator graph = data.graph.begin();
    sf::RectangleShape shape;
    int i = 1;
    int x = 700;
    int y = 290;
    float f = cpu->_usage;

    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(1, 100));
    while (cpu != data.cpu._list.end()) {
        cpu->_text.setFont(gi._font);
        cpu->_text.setCharacterSize(24);
        cpu->_text.setFillColor(sf::Color::White);
        cpu->_text.setPosition(x, y);
        cpu->_text.setString("CPU" + std::to_string(i) + ": " + cpu->_percent.c_str() + "%");
        //shape.setPosition(x, y + 40)
        //data.graph.begin()->push_back(shape);
        cpu++;
        i++;
        if (x < 1500)
            x += 300;
        else {
            x = 700;
            y += 250;
        }
    }

    cpu = data.cpu._list.begin();
    gi._window->clear();
    gi._window->draw(data.background);
    gi.display_shape();
    while (cpu != data.cpu._list.end()) {
        gi._window->draw(cpu->_text);
        cpu++;
    }
    draw_graph(data, gi);
    gi._window->draw(data.username._text);
    gi._window->draw(data.hostname._text);
    gi._window->draw(data.time._text);
    gi._window->draw(data.sys._text);
    gi._window->draw(data.coremodel._text);
    gi._window->draw(data.ram._shape);
    gi._window->draw(data.ram._text);
    gi._window->draw(data.freq._text);
    gi._window->draw(data.swap._shape);
    gi._window->draw(data.swap._text);
    gi._window->draw(data.cpu._text);
    gi._window->draw(data.network_v._text);
    gi._window->display();
    return (0);
}

int manage_event(graphical_i &gi)
{
    sf::Event event;

    while (gi._window->pollEvent(event))
        if (event.type == sf::Event::Closed)
            gi._window->close();
    return (0);
}

int update_info(graphical_i &gi, data_t &data)
{
    data.swap.getValue();
    data.ram.getValue();
    data.cpu.getValue();
    data.network_v.getValue();
    data.network_v._text.setString(data.network_v.getName() + ": " + data.network_v.getValue());
    data.freq._text.setString(data.freq.getName() + ": " + data.freq.getValue());
    data.swap._text.setString(data.swap.getName() + ": ");
    data.swap._shape.setScale(sf::Vector2f(data.swap.getUsed() / data.swap.getTotal(), 1));
    data.ram._text.setString(data.ram.getName() + ": ");
    data.time._text.setString(data.time.getName() + data.time.getValue());
    data.sys._text.setString(data.sys.getName() + ": " + data.sys.getValue());
    data.coremodel._text.setString(data.coremodel.getName() + ": " + data.coremodel.getValue());
    data.username._text.setString(data.username.getName() + ": " + data.username.getValue());
    data.hostname._text.setString(data.hostname.getName() + ": " + data.hostname.getValue());
    data.cpu._text.setString("Usage : " + data.cpu.getPercent() + "%");
    data.time._text.setString(data.time.getName() + data.time.getValue());
    data.ram._shape.setScale(sf::Vector2f(data.ram.getUsed() / data.ram.getTotal(), 1));
    return (0);
}

int graphical_interface(graphical_i &gi, data_t data)
{
    while (gi._window->isOpen()) {
        update_info(gi, data);
        manage_disp(gi, data);
        manage_event(gi);
    }
    return (0);
}