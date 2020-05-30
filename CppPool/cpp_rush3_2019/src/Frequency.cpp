/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** Frequency
*/

#include "Frequency.hpp"

static std::string getFrequency()
{
    std::string model; 
    std::ifstream inFile;
    std::string line;
    int i = 0;

    inFile.open("/proc/cpuinfo");
    if (inFile.fail()) {
        model.append("Can't open cpuinfo\n");
        return (model);
    }
    while (!inFile.eof()) {
        getline(inFile, line);
        if (line.find("model name") != std::string::npos) 
            break;
    }
    for (int j = 0; j != line.size(); j++) {
        if (line[j] == ' ') 
            i = j;
    }
    model.assign(line.substr(i, line.size() - 1));
    inFile.close();
    return (model);
}

Frequency::Frequency()
{
    this->_name = "Core frequency ";
    this->_frequency = getFrequency();
    this->isDisped = 1;
}

Frequency::~Frequency()
{
}

const std::string &Frequency::getName() const
{
    return (this->_name);
}
const std::string &Frequency::getValue()
{
    return (this->_frequency);
}

void Frequency::displayN()
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);
    CoreModel model;

    if (this->isDisped == 0)
        return;
    if (y <= 27)
        return;
    this->refreshN();
    if (x > this->getName().size() + this->getValue().size()) {
        mvprintw(27, x - model.getName().size() - model.getValue().size() - 4, "%s : %s", this->getName().c_str(), this->getValue().c_str());
    }
}