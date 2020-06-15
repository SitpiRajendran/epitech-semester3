#include <vector>
#include <iostream>
#include "PathFinder.hpp"

PathFinder::PathFinder(int destX, int destY) {
    this->destX = destX;
    this->destY = destY;
}
PathFinder::~PathFinder() {}

//Print the map
void PathFinder::printMap(std::vector<std::string> map) {
    for (size_t i = 0; i < map.size(); i ++)
        std::cout << map[i] << std::endl;
}

//Set the map without destructable block in the map to get a clean map for the algo
void PathFinder::setMap(std::vector<std::string> &map) {
    for (size_t i = 1; i < map.size(); i ++)
        for (size_t j = 1; j < map[i].length(); j ++)
            if (map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'o' || map[i][j] == 'X' || map[i][j] == 'D')
                map[i][j] = ' ';
}

//Check if the position given is near the asked point (Here an other player)
bool PathFinder::DoIFind(std::vector<std::string> map, int x, int y) {
    if (x == this->destX && y == this->destY)
        return true;
    else if (x < map.size() - 2 && map[x + 1][y] == '2')
        return true;
    else if (x > 2 && map[x - 1][y] == '2')
        return true;
    else if (y < map[x].length() - 2 && map[x][y + 1] == '2')
        return true;
    else if (y > 2 && map[x][y - 1] == '2')
        return true;
    return false;
}

//Modify x & y reference to the char position given as argument
void PathFinder::findPosByChar(std::vector<std::string> map, char c, int &x, int &y) {
    for (; x < map.size() && map[x].find(c) == std::string::npos; x ++);
    if (x == map.size()) {
        x = 1;
        y = 1;
        return;
    }
    for (; y < map[x].length() && map[x][y] != c; y ++);
}

//Choose the direction to go to a define point (here an other player)
bool PathFinder::BetterDirection(int &x, int &y, std::vector<std::string> map) {
    if (x < this->destX && map[x + 1][y] == ' ') {
        x += 1;
        return true;
    } else if (x > this->destX && map[x - 1][y] == ' ') {
        x -= 1;
        return true;
    } else if (y < this->destY && map[x][y + 1] == ' ') {
        y += 1;
        return true;
    } else if (y > this->destY && map[x][y - 1] == ' ') {
        y -= 1;
        return true;
    }
    return false;
}

//Random Mouvement
bool PathFinder::RandomMouvement(int &x, int &y, std::vector<std::string> map) {
    if (map[x + 1][y] == ' ') {
        x += 1;
        return true;
    } else if (map[x - 1][y] == ' ') {
        x -= 1;
        return true;
    } else if (map[x][y + 1] == ' ') {
        y += 1;
        return true;
    } else if (map[x][y - 1] == ' ') {
        y -= 1;
        return true;
    }
    return false;
}

//Handle if the algo need to go back
bool PathFinder::GoBackMouvement(int &x, int &y, std::vector<std::string> &map) {
    if (map[x + 1][y] == 'o') {
        map[x][y] = 'X';
        x += 1;
        return true;
    } else if (map[x - 1][y] == 'o') {
        map[x][y] = 'X';
        x -= 1;
        return true;
    } else if (map[x][y + 1] == 'o') {
        map[x][y] = 'X';
        y += 1;
        return true;
    } else if (map[x][y - 1] == 'o') {
        map[x][y] = 'X';
        y -= 1;
        return true;
    }
    return false;
}

//Last Check if the path is right
bool PathFinder::isRight(std::vector<std::string> map) {
    int x = 1;
    int y = 1;
    bool one = false;
    bool two = false;

    map = this->myway(map, '1', '2');
    this->findPosByChar(map, '1', x, y);
    if (map[x + 1][y] == 'o')
        one = true;
    else if (map[x - 1][y] == 'o')
        one = true;
    else if (map[x][y - 1] == 'o')
        one = true;
    else if (map[x][y + 1] == 'o')
        one = true;
    x = 1;
    y = 1;
    this->findPosByChar(map, '2', x, y);
    if (map[x + 1][y] == 'o')
        two = true;
    else if (map[x - 1][y] == 'o')
        two = true;
    else if (map[x][y - 1] == 'o')
        two = true;
    else if (map[x][y + 1] == 'o')
        two = true;
    return (one && two ? true : false);
}

//Algorithm of PathFinding which just saying if it's possible or not
bool PathFinder::pathFinding(std::vector<std::string> map) {
    int x = 0;
    int y = 0;
    bool end = false;

    this->destX = 0;
    this->destY = 0;
    this->setMap(map);
    this->findPosByChar(map, '2', x, y);
    this->findPosByChar(map, '1', this->destX, this->destY);
    while (!end) {
        if (DoIFind(map, x, y))
            return this->isRight(map);
        else if (BetterDirection(x, y, map));
        else if (RandomMouvement(x, y, map));
        else if (GoBackMouvement(x, y, map));
        else
            return this->isRight(map);
        map[x][y] = 'o';
    }
    return this->isRight(map);
}

//Algorithm of PathFinding which just saying if it's possible or not
bool PathFinder::pathFindingCoord(std::vector<std::string> map, int xx, int yy) {
    int x = 0;
    int y = 0;
    bool end = false;

    this->destX = xx;
    this->destY = yy;
    this->findPosByChar(map, '2', x, y);
    this->setMap(map);
    while (!end) {
        if (DoIFind(map, x, y))
            return true;
        else if (BetterDirection(x, y, map));
        else if (RandomMouvement(x, y, map));
        else if (GoBackMouvement(x, y, map));
        else
            return false;
        map[x][y] = 'o';
    }
    return false;
}

//Print map with colors for differents char
int PathFinder::printSpecialMap(std::vector<std::string> map) {
    for (size_t i = 0; i < map.size(); i ++) {
        for (size_t j = 0; j < map[0].length(); j ++) {
            if (map[i][j] == '#')
                std::cout << "\e[93m" << map[i][j] << "\e[0m";
            else if (map[i][j] == '1' || map[i][j] == '2')
                std::cout << "\e[95m" << map[i][j] << "\e[0m";
            else if (map[i][j] == 'o')
                std::cout << "\e[96m" << map[i][j] << "\e[0m";
            else
                std::cout << map[i][j];
        }
        std::cout << "" << std::endl;
    }
    std::cout << "" << std::endl;
    return 0;
}

//Pathfinding which return the map with the path set on
std::vector<std::string> PathFinder::myway(std::vector<std::string> map, char one, char two) {
    int x = 0;
    int y = 0;
    bool end = false;

    this->destX = 0;
    this->destY = 0;
    this->setMap(map);
    this->findPosByChar(map, one, x, y);
    this->findPosByChar(map, two, this->destX, this->destY);
    while (!end) {
        if (DoIFind(map, x, y))
            end = true;
        else if (BetterDirection(x, y, map));
        else if (RandomMouvement(x, y, map));
        else if (GoBackMouvement(x, y, map));
        else
            return map;
        if (map[x][y] != one && map[x][y] != two)
            map[x][y] = 'o';
    }
    return map;
}