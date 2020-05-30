/*
** EPITECH PROJECT, 2020
** Parser.cpp
** File description:
** Parser
*/

#include "Parser.hpp"

std::map<std::string, nts::IComponent> Parser::getChipsets() const
{
    return (this->chipsets);
}

void Parser::setChipsets(std::map<std::string, nts::IComponent> chipsets)
{
    this->chipsets = chipsets;
}

std::map<std::string, nts::IComponent> chipsetsMap(std::map<std::string, nts::IComponent> map, std::string line)
{

    std::string key;
    std::string value;

    key = line.substr(0, line.find(" "));
    value = line.substr(key.size(), line.size());
    value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
    try {
        if (key == "input")
        {
            Input i(value);
            if (!map[value].getName().empty())
                throw Error("Multiple definition of \"" + map[value].getName() + "\".");
            map[value] = i;
            // Attention : Input must 1 or 0 and is provided in the command line arguments;
        }
        if (key == "output")
        {
            Output o(value);
            if (!map[value].getName().empty())
                throw Error("Multiple definition of \"" + map[value].getName() + "\".");
            map[value] = o;
            // c'est ici qu'on va crée les composant ex : map[key] =  createComponent(value);
        }
        // if (key == "4008")
        // {
        //     componentList.push_back(value);
        //     map[key] = componentList;
        //     // c'est ici qu'on va crée les composant ex : map[key] =  createComponent(value);
        // }
        if (key == "true")
        {
            // Créer un component toujours TRUE ! (single pin)
        }
        if (key == "false")
        {
            // Créer un component toujours FALSE ! (single pin)
        }
        if (key == "clock")
        {
            // pas compris ..
        }
    } catch (std::exception const& err) {
        throw Error(err.what());
    }
    return map;
}

void openfile(std::string path, Parser *Parser)
{
    std::ifstream openFile(path);
    std::string line;

    bool chipsInit = false;
    bool linksInit = false;

    try {
        if (!openFile)
            throw Error("Invalid file.");
        while (openFile.good()) {
            getline(openFile, line);
            std::replace(line.begin(), line.end(), '\t', ' ');
            if (linksInit == true)
            {
                // std::cout << "We have Links !!";
            }
            if (std::string::npos != line.find(".link"))
            {
                chipsInit = false;
                linksInit = true;
            }
            if (chipsInit == true)
                Parser->setChipsets(chipsetsMap(Parser->getChipsets(), line));
            if (std::string::npos != line.find(".chipset"))
                chipsInit = true;
        }
    } catch (std::exception const &err) {
        std::cerr << "Erreur : " << err.what() << std::endl;
        // exit(84);
    }
}

void parser(int ac, char **av)
{
    Parser Parser;
    std::string path = av[1];

    if (ac > 2)
        Parser.setArguments(av);

    // for (auto elem : Parser.getArguments())
    // {
    //     std::cout << "Input : " << elem.first << " ==> " << elem.second << std::endl;
    // }
    openfile(path, &Parser);
    for (auto elem : Parser.getChipsets())
    {
        std::cout  << "map[" << elem.first <<  "] = " << " " << elem.second.getName();

        std::cout << std::endl;
    }
    // std::cout << fileContent->chipsets << std::endl;
    // mapChipset(fileContent);
}

std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value)
{
    if (type == "4001")
        return std::make_unique<C4001>(value);
}