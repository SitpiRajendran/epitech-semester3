#ifndef __SYSTEM_CLASS__
#define __SYSTEM_CLASS__

#include <vector>
#include <iostream>
#include "Exception.hpp"

class System {
    public:
        System();
        ~System();

        void saveMap(std::vector<std::string>);
        std::vector<std::string> loadMap();
        std::vector<std::string> loadStat(std::string name);
    private:
};

#endif