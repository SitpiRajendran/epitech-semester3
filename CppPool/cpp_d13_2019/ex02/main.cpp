/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** main
*/

#include <iostream>
#include "Toy.hpp"
#include "Woody.hpp"
#include "Buzz.hpp"

int main()
{
    Toy toto;
    Buzz ET("wehs");
    Woody dd("audd");

    toto.setName("TOTO !");
    if (toto.getType () == Toy::BASIC_TOY)
        std::cout  << "basic  toy: " << toto.getName () << std::endl<< toto.getAscii() << std::endl;
    if (ET.getType () == Toy::BUZZ)
        std::cout  << "this  BUZZ is: " << ET.getName () << std::endl<< ET.getAscii () << std::endl;
    if (dd.getType () == Toy::WOODY)
        std::cout  << "this  WOODY is: " << dd.getName () << std::endl<< dd.getAscii () << std::endl;
    return  0;
}