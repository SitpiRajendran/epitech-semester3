/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** mymain
*/

#include "ram.hpp"
#include <unistd.h>

int main()
{
    Ram r;

    for (; 1; sleep(1)) {
        std::cout << r.getValue() << std::endl;
    }
}