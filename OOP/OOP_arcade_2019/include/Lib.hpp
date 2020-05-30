/*
** EPITECH PROJECT, 2020
** clone_arcade
** File description:
** Lib
*/

#ifndef LIB_HPP_
#define LIB_HPP_

#include<dirent.h>
#include "CoreGame.hpp"

class Lib {
    public:
        Lib();
        ~Lib();
        std::vector<std::string> getGamelib();
        std::vector<std::string> getGraphLib();
    protected:
    private:
};

#endif /* !LIB_HPP_ */
