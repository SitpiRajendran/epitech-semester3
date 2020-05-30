/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Core.hpp"
#include "error.hpp"

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
            throw ArgvError("Usage\n ./arcade lib \n lib : sfml, ncurses, sdl2");
        lib = get_lib(av[1]);
        if (lib == 3)
            throw ArgvError("Usage\n ./arcade lib \n lib : sfml, ncurses, sdl2");
        Core core(lib);
    } catch (const Error &error) {
        std::cerr << "Error: " << error.what() << std::endl;
        return 84;
    }
    return 0;
}
