/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CoreModel
*/

#include "CoreModel.hpp"

static std::string getModel()
{
    std::string model; 
    std::ifstream inFile;
    std::string line;

    inFile.open("/proc/cpuinfo");
    if (inFile.fail()) {
        model.append("Can't open cpuinfo\n");
        return (model);
    }
    while (!inFile.eof()) {
        getline(inFile, line);
        if (line.find("model name") != std::string::npos) {
            model.assign(line.substr(13, line.size() -2));
            break;
        }
    }
    inFile.close();
    return (model);
}

CoreModel::CoreModel()
{
    this->_name = "Core model";
    this->_model = getModel();
    this->isDisped = 1;
}

CoreModel::~CoreModel()
{
}

const std::string &CoreModel::getName() const
{
    return (this->_name);
}
const std::string &CoreModel::getValue()
{
    return (this->_model);
}

void CoreModel::displayN()
{
    int x = 0;
    int y = 0;
    getmaxyx(stdscr, y, x);

    if (this->isDisped == 0)
        return;
    if (y <= 26)
        return;
    this->refreshN();
    if (x > this->getName().size() + this->getValue().size()) {
        mvprintw(26, x - this->getName().size() - this->getValue().size() - 4, "%s : %s", this->getName().c_str(), this->getValue().c_str());
    }
}