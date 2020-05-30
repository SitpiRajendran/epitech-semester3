/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Core.hpp"
#include "Launcher.hpp"
#include "Exception.hpp"

// ./arcade ./lib/lib_arcade_XXX.so

int get_lib(char *str)
{
    if (strcmp(str, SFML_LIB) == 0)
        return 0;
    if (strcmp(str, NCURSES_LIB) == 0)
        return 1;
    if (strcmp(str, SDL_LIB) == 0)
        return 2;
    return (3);
}

int main (int ac, char **av)
{
    int lib;
    try {
        if (ac != 2)
            throw Exception("Usage\n ./arcade lib \n lib : sfml, ncurses, sdl2");
        arcade::Launcher coc(av[1]);
        coc.menu();
    } catch (const Exception &Exception) {
        std::cerr << "Error: " << Exception.what() << std::endl;
        return 84;
    }
    return 0;
}
