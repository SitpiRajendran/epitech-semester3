/*
** EPITECH PROJECT, 2020
** Parser.hpp
** File description:
** Parser
*/

#ifndef PARCER_HPP_
#define PARCER_HPP_

#include "IComponent.hpp"
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <list>
#include "Error.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "True.hpp"
#include "False.hpp"
#include "C4001.hpp"

class Parser {
    public:
        void setChipsets(std::map<std::string, nts::IComponent>);
        void setArguments(char **av);
        std::map<std::string, nts::IComponent> getChipsets() const;
        std::map<std::string, int> getArguments() const;
    private:
        std::map<std::string, int> arguments;
        std::map<std::string, nts::IComponent> chipsets;
};

void checkExecution(std::string command);
void parser(int ac, char **av);

#endif /* !PARCER_HPP_ */

