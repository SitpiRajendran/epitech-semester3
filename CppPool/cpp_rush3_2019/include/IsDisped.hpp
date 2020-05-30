/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IsDisped
*/

#ifndef ISDISPED_HPP_
#define ISDISPED_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <sstream>
#include <list>
#include <vector>
#include <cstdlib>

class IsDisped
{
public:
        IsDisped();
        ~IsDisped();
        int CoreModel;
        int cpu;
        int date;
        int frequency;
        int UserName;
        int Hostname;
        int ram;
        int swap;
        int sys;
        void Parse(char **av);

protected:
private:
};

#endif /* !ISDISPED_HPP_ */
