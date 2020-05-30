/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** cpu
*/

#include "cpu.hpp"

Cpu::Cpu()
{
    setData();
    this->isDisped = 1;
}

void Cpu::getfirstline()
{
    std::string model;
    std::ifstream ifs("/proc/stat");
    std::string line;
    std::string num;

    if (ifs.is_open() == false) {
        model.append("Can't open stat\n");
        return;
    }
    getline(ifs, line);
    std::istringstream iss(line.substr(5, line.size()));
    _usage = 0;
    _total = 0;
    std::getline(iss, num, ' ');
    _usage += (std::stof(num));
    std::getline(iss, num, ' ');
    _total += (std::stof(num));
    std::getline(iss, num, ' ');
    _usage += (std::stof(num));
    _total += _usage;
    for (int i = 0; i < 3; i++) {
        std::getline(iss, num, ' ');
        _total += (std::stof(num));
    }
    _percent = std::to_string((_usage / _total)*100);
}

const std::string &Cpu::getValue()
{
    setData();
    return _percent;
}

eachCPU createEach(int i, std::string line)
{
    std::string num;
    eachCPU data;
    std::istringstream iss(line.substr(5, line.size()));

    data._usage = 0;
    for (int i = 0; i < 3; i++) {
        std::getline(iss, num, ' ');
        data._usage += (std::stof(num));
    }
    data._total = data._usage;
    for (int i = 0; i < 4; i++) {
        std::getline(iss, num, ' ');
        data._total += (std::stof(num));
    }
    data._percent = std::to_string((data._usage / data._total)*100);
    return data;
}

void Cpu::getAllCpu(int noc)
{
    std::string model;
    std::ifstream ifs("/proc/stat");
    std::string line;
    std::string num;

    if (ifs.is_open() == false) {
        model.append("Can't open stat\n");
        return;
    }
    _list.clear();
    getline(ifs, line);
    for (int i = 0; i <= noc; i++) {
        getline(ifs, line);
        _list.push_back(createEach(i, line));
    }
}

void Cpu::setData()
{
    std::string model;
    std::ifstream inFile("/proc/stat");
    std::string line;
    int liner = 0;

    if (inFile.is_open() == false) {
        model.append("Can't open stat\n");
        return;
    }
    while (!inFile.eof()) {
        getline(inFile, line);
        if (line.find("cpu") == std::string::npos) {
            _value = std::to_string(liner++);
        }
    }
    _value = std::to_string(liner--);
    getfirstline();
    getAllCpu(liner);
    return;
}

void Cpu::displayN() 
{
    if (this->isDisped == 0)
        return;

    this->refreshN();
    int pos = (atoi(this->getPercent().c_str()) * 50) / 100;
    int max = 50;
    int n = 0;
    int maxForEach = 15;
    std::string percent = "";
    std::string non_use = "";
    std::string name = "";
    for (int i = 0; i < pos; i++) 
        percent.append("|");
    for (int i = 0; i < 50 - pos; i++) 
        non_use.append(" ");
    mvprintw(28, 0, "Usage : ", this->getPercent().c_str());
    printw("[");
    attron(COLOR_PAIR(4));
    printw("%s", percent.c_str());
    attroff(COLOR_PAIR(4));
    printw("%s", non_use.c_str());
    printw("]\n\n");
    std::vector<eachCPU>::iterator it = this->_list.begin();

    while (it != _list.end()) {
        name.clear();
        name.append("cpu");
        name.append(std::to_string(n));
        pos = (atoi((*it)._percent.c_str()) * 15) / 100;
        percent.clear();
        non_use.clear();
        for (int i = 0; i < pos; i++)
            percent.append("|");
        for (int i = 0; i < 15- pos; i++) 
            non_use.append(" ");
        printw("%s ", name.c_str());
        printw("[");
        attron(COLOR_PAIR(4));
        printw("%s", percent.c_str());
        attroff(COLOR_PAIR(4));
        printw("%s", non_use.c_str());
        printw("] ");
        n++;
        if (n % 2 == 0)
            printw("\n");
        it++;
    }
}