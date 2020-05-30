/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Launcher
*/

#ifndef LAUNCHER_HPP_
#define LAUNCHER_HPP_

#include "DDloader.hpp"
#include "Lib.hpp"
#include "ICoreGame.hpp"
#include "IDisplay.hpp"
#include "Exception.hpp"

namespace arcade
{
class Launcher {
    public:
        Launcher(const std::string &lib);
        ~Launcher();

        void launch();
        void quit();
        void restart();
        int changeGame(int move);
        int changeGrp(int move);
        void menu();

    protected:

    private:
        std::vector<std::string> gameLib_path;
        std::vector<std::string> grpLib_path;

        int gameSelected;
        int grpSelected;
        
        std::string name;
        arcade::ICoreGame *currentGame;
        arcade::IDisplay *currGrp;
};
} // namespace arcade
#endif /* !LAUNCHER_HPP_ */
