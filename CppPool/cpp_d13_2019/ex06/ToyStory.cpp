/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** ToyStory
*/

#include "ToyStory.hpp"

ToyStory::ToyStory()
{
}

ToyStory::~ToyStory()
{
}

void ToyStory::tellMeAStory(std::string filename, Toy &t1, bool (Toy::*func1)(std::string const), Toy &t2, bool (Toy::*func2)(std::string const))
{
    std::string line;
    bool one = true;

    std::ifstream ifs (filename);
    if (ifs.is_open()) {
        std::cout << t1.getAscii() << std::endl;
        std::cout << t2.getAscii() << std::endl;
        while (getline(ifs, line) && t1.getLastError().type == 0 && t2.getLastError().type == 0) {
            if (one == true) {
                if (line.find("picture:") != 0)
                    (t1.*func1)(line);
                else {
                    t1.setAscii(line.substr(8));
                    std::cout << t1.getAscii() << std::endl;
                }
                one = false;
            } else if (one == false) {
                if (line.find("picture:") != 0)
                    (t2.*func2)(line);
                else {
                    t2.setAscii(line.substr(8));
                    std::cout << t2.getAscii() << std::endl;
                }
            }
        }
        if (t1.getLastError().type != 0)
            std::cout << t1.getLastError().where() << ": " << t2.getLastError().what() << std::endl;
        if (t2.getLastError().type != 0)
            std::cout << t2.getLastError().where() << ": " << t2.getLastError().what() << std::endl;
    } else
        std::cout << "Bad Story" << std::endl;
}