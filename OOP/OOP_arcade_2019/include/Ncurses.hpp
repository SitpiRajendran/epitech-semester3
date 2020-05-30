/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include "IDisplay.hpp"
#include <ncurses.h>

namespace lib
{
    class Ncurses : public arcade::IDisplay {
        public:
            Ncurses();
            ~Ncurses();
            void Refresh() override;
            void Clear() override;
            void dispMap(std::vector<std::string> &map, arcade::Element &map_element) override;
            void dispObject(std::vector<arcade::Element> &allElement) override;
            int menu(std::vector<std::string> &gameLib_path) override;
            int getEvent() override;
            std::string getName() override;
            void setName(const std::string &name) override;
            int getTimeDiff() override;
            void dispName(std::string name) override;
            void dispScore(int score) override;

        protected:
        private:
            int _length;
            int _height;
            std::string _name;
            int currentWindow = 0;
    };
} // namespace lib

#endif /* !NCURSES_HPP_ */
