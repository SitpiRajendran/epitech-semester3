/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Maper
*/

#ifndef __MAPPER__
#define __MAPPER__

#include <vector>
#include <iostream>
#include "MyPerso.hpp"

namespace indie {
    class MyPerso;

    class Mapper {
        public:
            Mapper(char = '#', char = 'C', std::vector<char> = {'1', '2'}, char = 'Q', char = 'B');
            ~Mapper();

            void setWall(char);
            void setBombs(char);
            void setBonus(char);
            void setBrokable(char);
            char getWall(void) const;
            char getBonus(void) const;
            char getBombs(void) const;
            char getBrokable(void) const;
            void setMap(std::vector<std::string>);
            std::vector<char> getPlayers(void) const;
            std::vector<std::string> getMap(void) const;
            void check_map(std::vector<MyPerso *>);
            void setCharPos(char, size_t, size_t, bool = false);
            void setChars(char = '#', char = 'C', std::vector<char> = {'1', '2'}, char = 'Q', char = 'B');

        private:
            char _wall;
            char _bonus;
            char _bombs;
            char _brokable;
            std::vector<char> _players;
            std::vector<std::string> _Map;
    };
}

#endif
