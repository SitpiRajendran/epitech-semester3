/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "IComponent.hpp"
#include "Parser.hpp"

int main (int ac, char **av)
{
    std::string input;
    if (ac < 2) {
        std::cerr << "[ERROR] : No arguments" << std::endl;
        return (84);
    }
    // std::cout << av[1] << std::endl;
    parser(ac, av);

    while (std::cin && std::cin >> input && input != "exit") {
        checkExecution(input);
        std::cout << "> ";
    }
    return (0);
}