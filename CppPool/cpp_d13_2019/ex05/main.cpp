#include <iostream>
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int  main()
{
    Woody w("wood");

    if (w.setAscii("file_who_does_not_exist.txt") ==  false) {
        auto e = w.getLastError ();
        if (e.type == Toy:: Error:: PICTURE){
            std::cout  << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }
    if (w.speak_es("Woody  does  not  have  spanish  mode") ==  false){
        auto e = w.getLastError ();
        if (e.type == Toy:: Error:: SPEAK){
            std::cout  << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }
    if (w.speak_es("Woody  does  not  have  spanish  mode") ==  false){
        auto e = w.getLastError ();
        if (e.type == Toy:: Error:: SPEAK){
            std::cout  << "Error in " << e.where() << ": " << e.what() <<std::endl;
        }
    }
}
