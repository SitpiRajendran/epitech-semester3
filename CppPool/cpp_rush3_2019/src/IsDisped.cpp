/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IsDisped
*/

#include "IsDisped.hpp"
#include <stddef.h>

IsDisped::IsDisped()
{
    int CoreModel = 1;
    int cpu = 1;
    int date = 1;
    int frequency = 1;
    int UserName = 1;
    int Hostname = 1;
    int ram = 1;
    int swap = 1;
    int sys = 1;
}

IsDisped::~IsDisped()
{
}

void IsDisped::Parse(char **av)
{
    int i = 2;
    std::string CoreModel  = "CoreModel";
    std::string cpu  = "cpu";
    std::string date  = "date";
    std::string frequency  = "frequency";
    std::string UserName  = "UserName";
    std::string Hostname  = "Hostname";
    std::string ram  = "ram";
    std::string swap  = "swap";
    std::string sys  = "sys";

    while (av[i] != NULL) {
        if (CoreModel.compare(av[i]) == 0)
            this->CoreModel = 0;
        if (cpu.compare(av[i]) == 0)
            this->cpu = 0;
        if (date.compare(av[i]) == 0)
            this->date = 0;
        if (frequency.compare(av[i]) == 0)
            this->frequency = 0;
        if (UserName.compare(av[i]) == 0)
            this->UserName = 0;
        if (Hostname.compare(av[i]) == 0)
            this->Hostname = 0;
        if (ram.compare(av[i]) == 0)
            this->ram = 0;
        if (swap.compare(av[i]) == 0) {
            printf("here\n");
            this->swap = 0;
        }
        if (sys.compare(av[i]) == 0)
            this->sys = 0;
        i++;
    }
}