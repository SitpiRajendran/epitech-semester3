/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Bot
*/

#ifndef BOT_HPP_
#define BOT_HPP_

//#include "MyPerso.hpp"
#include <tuple>
#include <iostream>
#include "Maper.hpp"
#include "MyPerso.hpp"
#include "PathFinder.hpp"

enum BOT_ACTION {
    DEFENSE,
    ATTACK
};

enum BOT_DIR {
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP,
    DIR_DOWN,
    DIR_LOST
};

namespace indie {
    class Bot {
        public:
            Bot();
            ~Bot();

            int where_do_i_go(std::vector<std::string> map);

            void Movement(int &, int &, MyPerso &);
            void activate(std::vector<std::string> &);
            bool randomMove(std::vector<std::string> &);
            void new_dest_attack(std::vector<std::string> &);
            void new_dest_defense(std::vector<std::string> &);
            void getAllPosition(MyPerso &player, int &, int &);
            std::vector<std::string> map_modifier(std::vector<std::string> &);
            std::vector<std::string> map_bomb(std::vector<std::string>, int, int);
            void updatePlayer(MyPerso &, std::vector<std::string>, Mapper &, EventParticular &);
            void breakable_function(MyPerso &player, Mapper &Asciimap, EventParticular &evt, int &, int &);

            char lastdir;
        private:
            char _num;
            int _posX;
            int _posY;
            int _destX;
            int _destY;
            bool _lost;
            int _action;
            int _dir;

    };
}
#endif
