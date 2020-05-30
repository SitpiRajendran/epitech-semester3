/*
** EPITECH PROJECT, 2020
** argumentParsing.cpp
** File description:
** argumentParcing
*/

#include "Parser.hpp"

void Parser::setArguments(char **av)
{
    std::map<std::string, int> argument;
    std::string tmp;

    for (int i = 2; av[i]; i++) {
        tmp = av[i];
        argument[tmp.substr(0, tmp.find("="))] = std::stoi (tmp.substr(tmp.find("=") + 1));
    }
    this->arguments = argument;
}

std::map<std::string, int> Parser::getArguments() const
{
    return (this->arguments);
}