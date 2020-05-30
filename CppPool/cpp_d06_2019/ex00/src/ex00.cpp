/*
** EPITECH PROJECT, 2020
** CppPool - d06
** File description:
** ex00
*/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[] )
{
    std::filebuf* pbuf;

    if (argc < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return 0;
    }
    for (int i = 1; argv[i] != NULL; i++) {
        std::ifstream ifs (argv[i]);
        if (ifs.is_open()) {
            pbuf = ifs.rdbuf();
            std::cout << pbuf;
            ifs.close();
        } else {
            std::cerr << "my_cat: "<< argv[i];
            std::cerr <<": No such file or directory" << std::endl;
        }
    }
    return 0;
}