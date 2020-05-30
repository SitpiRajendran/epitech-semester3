/*
** EPITECH PROJECT, 2020
** checkExcution.cpp
** File description:
** checkExecution
*/

#include "Parser.hpp"

void displayOutput()
{

}

void setInput(std::string name, int value)
{
    std::cout << name << "   value : " << value << std::endl;
}

void checkExecution(std::string command)
{
    std::string name;
    std::size_t equalPos;

    try {
        if (command == "display")
            displayOutput();
        else if (command == "loop")
            displayOutput();
        else if (command == "dump")
            displayOutput();
        else if (command == "simulate")
            displayOutput();
        else if ((equalPos = command.find("=")) != std::string::npos)
            setInput(command.substr(0, equalPos), std::stoi (command.substr(equalPos + 1)));
            // std::cout << command.substr(0, equalPos) << "value = " << command.substr(equalPos + 1);
        else
            std::cout << command << " : command not found." << std::endl;
    } catch (std::exception const& err) {
        std::cerr << "Fuck you maaaan..   "  << command << std::endl;
    }
}
