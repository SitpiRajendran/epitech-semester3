/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MapGenerator
*/

#ifndef __MAP_GENERATOR__
#define __MAP_GENERATOR__

#include <time.h>
#include <vector>
#include <ostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "PathFinder.hpp"

namespace indie {
    class MapGenerator {
        public:
            MapGenerator(size_t width = 20, size_t heigh = 20);
            ~MapGenerator();

            std::string wallline(void);
            std::string line(bool);
            size_t getWidth(void) const;
            size_t getHeigh(void) const;
            int random(int, int);
            void checkMap(std::vector<std::string> &);
            std::vector<std::string> generate(int = 2);
            std::vector<std::string> map_generator(void);
            void perso_position(std::vector<std::string> &, int = 2);

        private:
            size_t width;
            size_t heigh;
    };
}

#endif