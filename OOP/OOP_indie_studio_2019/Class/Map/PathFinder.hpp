#ifndef __PATHFINDER__
#define __PATHFINDER__

#include <vector>
#include <string>

class PathFinder {
    public:
        PathFinder(int destX = 1, int destY = 1);
        ~PathFinder();

        bool isRight(std::vector<std::string>);
        void setMap(std::vector<std::string> &);
        void printMap(std::vector<std::string>);
        bool pathFinding(std::vector<std::string>);
        int printSpecialMap(std::vector<std::string>);
        bool DoIFind(std::vector<std::string>, int = 0, int = 0);
        bool pathFindingCoord(std::vector<std::string>, int, int);
        bool RandomMouvement(int &, int &, std::vector<std::string>);
        bool BetterDirection(int &, int &, std::vector<std::string>);
        bool GoBackMouvement(int &, int &, std::vector<std::string> &);
        void findPosByChar(std::vector<std::string>, char, int &, int &);
        std::vector<std::string> myway(std::vector<std::string>, char, char);

    private:
        int destY;
        int destX;
};

#endif