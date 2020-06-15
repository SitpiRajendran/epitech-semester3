#ifndef __COMPONENTSCLASS__
#define __COMPONENTSCLASS__

#include <irrlicht.h>
#include "Irrlicht.hpp"
#include "WindowHandler.hpp"

#include <string>
#include <vector>

namespace indie {
    class Components {
        public:
            Components(vector<vector3df> tabVector, float speed, std::string path = "");
            ~Components();

            void setPos(vector3df pos);
            void setSpeed(float speed);
            void setPath(std::string path);
            void setScale(vector3df Scale);
            void setRotate(vector3df pos);

            void createSelector(WindowHandler &windowhdl, ITriangleSelector **selector);
            void setAllData(vector<vector3df> tabVector, float speed, std::string path = "");

        private:
            float speed;
            vector3df pos;
            vector3df Scale;
            std::string path;
            vector3df rotate;
    };
}

#endif