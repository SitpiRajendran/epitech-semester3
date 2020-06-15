/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** main
*/

#include <vector>
#include <ostream>
#include <iostream>
#include <time.h>

#include "Menu.hpp"
#include "Irrlicht.hpp"
#include "CoreGame.hpp"
#include "ErrorHandling.hpp"
#include "MenuEventReceiver.hpp"

int main(int ac, char **av, char **env)
{
    shared_ptr<indie::CoreGame> coreGame;

    srand(time(NULL));
    if (!indie::ErrorHandling().env_handling(env))
        return (ERROR);
    try {
        try {
            coreGame = make_shared<indie::CoreGame>("./resources/Character/model/Bomberman.MD3", 2, 0);
            coreGame->LaunchTitleScreenAndMenu();
        }
        catch (std::bad_alloc &e) {
            throw(Exception("can't create shared_ptr for CoreGame"));
        }
    }
    catch (Exception &e) {
        std::cerr << e.what() << std::endl;
        return (ERROR);
    }
    return (SUCCESS);
}