/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MapGenerator
*/

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#elif __linux__
#include <unistd.h>
#endif
#include "MapGenerator.hpp"

indie::MapGenerator::MapGenerator(size_t width, size_t heigh) {
    this->heigh = heigh < 20 ? 20 : heigh;
    this->width = width < 20 ? 20 : width;
}

indie::MapGenerator::~MapGenerator() {}

int indie::MapGenerator::random(int min, int max) {
    int i = 0;

    if (min > max)
        return -1;
    i = min + (rand() % (max - min));
    return i;
}

std::string indie::MapGenerator::line(bool wall) {
    std::string newline = "#";

    for (size_t i = 0; i < this->width; i ++) {
        if (wall && i % 2 == 0)
            newline += "#";
        else {
            switch (random(0, 10)) {
                case 0: newline += "C"; break;
                case 1: newline += "C"; break;
                case 2: newline += "C"; break;
                case 3: newline += "C"; break;
                case 4: newline += "C"; break;
                case 5: newline += "C"; break;
                case 6: newline += "#"; break;
                case 7: newline += " "; break;
                case 8: newline += " "; break;
                case 9: newline += " "; break;
            }
        }
    }
    newline += "#";
    return newline;
}

std::string indie::MapGenerator::wallline() {
    std::string newline = "#";

    for (size_t i = 0; i < this->width; i ++)
        newline += "#";
    return (newline += "#");
}

std::vector<std::string> indie::MapGenerator::map_generator(void) {
    std::vector<std::string> av;

    srand(time(0));
    av.push_back(wallline());
    for (size_t i = 0; i < this->heigh; i ++)
        av.push_back(line(i % 2 == 0 ? true : false));
    av.push_back(wallline());
    return av;
}

void indie::MapGenerator::perso_position(std::vector<std::string> &av, int nbr) {
    int max_heigh = av.size() - 2;
    int max_width = av[av.size() - 2].length() - 2;

    nbr = (nbr < 2 || nbr > 4) ? 2 : nbr;
    av[1][1] = '1';
    av[1][2] = ' ';
    av[2][1] = ' ';
    switch (nbr) {
        case 2:
            av[max_heigh][max_width] = '2';
            av[max_heigh - 1][max_width] = ' ';
            av[max_heigh][max_width - 1] = ' ';
            break;
        case 3:
            av[1][max_width] = '2';
            av[2][max_width] = ' ';
            av[1][max_width - 1] = ' ';
            av[max_heigh][1] = '3';
            av[max_heigh][2] = ' ';
            av[max_heigh - 1][1] = ' ';
            break;
        case 4:
            av[1][max_width] = '2';
            av[2][max_width] = ' ';
            av[1][max_width - 1] = ' ';
            av[max_heigh][1] = '3';
            av[max_heigh][2] = ' ';
            av[max_heigh - 1][1] = ' ';
            av[max_heigh][max_width] = '4';
            av[max_heigh - 1][max_width] = ' ';
            av[max_heigh][max_width - 1] = ' ';
            break;
        default: av[max_heigh][max_width] = '2';
    }
}

void indie::MapGenerator::checkMap(std::vector<std::string> &map) {
    for (size_t i = 1; i < map.size() - 1; i ++) {
        for (size_t j = 1; j < map[i].length(); j ++) {
            size_t k = 0;
            std::vector<bool> check;

            check.push_back(map[i - 1][j] == '#' ? true : false);
            check.push_back(map[i + 1][j] == '#' ? true : false);
            check.push_back(map[i][j + 1] == '#' ? true : false);
            check.push_back(map[i][j + 1] == '#' ? true : false);
            check.push_back(map[i - 1][j + 1] == '#' ? true : false);
            check.push_back(map[i + 1][j + 1] == '#' ? true : false);
            check.push_back(map[i - 1][j - 1] == '#' ? true : false);
            check.push_back(map[i + 1][j - 1] == '#' ? true : false);

            for (; k < check.size() && check[k]; k ++);
            if (k == check.size())
                map[i][j] = 'X';
            check.clear();
        }
    }
}

std::vector<std::string> indie::MapGenerator::generate(int nbr) {
    bool good = false;
    std::vector<std::string> map;

    for (size_t i = 1; !good; i ++) {
        std::cout << "Map Generation | Attempting " << i << std::endl;
        map = map_generator();
        perso_position(map, 2);
        this->checkMap(map);
        if (!PathFinder().pathFinding(map)) {
            #ifdef _WIN32
            Sleep(1);
            #elif __linux__
            sleep(1);
            #endif
        } else good = true;
    }
    PathFinder().printMap(map);
    return map;
}

size_t indie::MapGenerator::getHeigh() const {return this->heigh;}
size_t indie::MapGenerator::getWidth() const {return this->width;}