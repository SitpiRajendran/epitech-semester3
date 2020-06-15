#ifndef __POWERUP__
#define __POWERUP__

#include "manager.h"

namespace indie {
    class Stat {
        public:
            Stat();
            Stat(const int _maxBomb, const float _range, const vector3df _speed);
            Stat &operator=(const Stat &to_cmp);
            ~Stat();

            void setMaxBomb(const int _maxBomb);
            void setRange(const float _range);
            void putBomb();
            void remBomb();
            void fireUp();
            void incSpeed();
            int getMaxBomb() const;
            float getRange() const;
            vector3df getSpeed() const;

        private:
            int maxBomb;
            float range;
            vector3df speed;
    };
}

#endif