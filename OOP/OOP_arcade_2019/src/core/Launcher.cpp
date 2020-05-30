/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** Launcher
*/

#include "Launcher.hpp"
#include <string>

void print(std::vector<std::string> const &input)
{
    std::cout << "///";

	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
    std::cout << "///" << std::endl;
}

namespace arcade {
    Launcher::Launcher(const std::string &lib) {
        Lib get;

        this->grpLib_path = get.getGraphLib();
        this->gameLib_path = get.getGamelib();
	    print(gameLib_path);
        if (displayLoader.loadLibrary(lib.c_str()) == 84)
            throw (Exception("can't load"));

        currGrp = displayLoader.getInstance("entryPoint");
         if (currGrp == nullptr)
            throw (Exception("No EntryPoint function in library"));
        currentGame = nullptr;
        gameSelected = 0;
    }

    Launcher::~Launcher() {
        if (!currentGame)
            delete currentGame;
        if (!currGrp)
            delete currGrp;
    }

    void Launcher::launch() {
        CoreGame_t *data = NULL;
        Input in = NOTHING;
        printf("dans_launch\n");
        data = currentGame->getData();
        while (data->end != true) {
            currGrp->Clear();
            currGrp->dispScore(data->score);
            currGrp->dispMap(data->map, data->map_style);
            currGrp->dispObject(data->allElements);
            currGrp->Refresh();
            if (currGrp->getTimeDiff() == false)
                continue;
            in = static_cast<Input>(currGrp->getEvent());
            if (in == QUIT)
                break;
            if (in == RESTART) {
                currentGame->restartGame();
                in = NOTHING;
            }
            if (in == MENU)
                break;
            if (in == NEXT_LIB || in == PREV_LIB)
                changeGrp(in);
            if (in == NEXT_GAME || in == PREV_GAME)
                changeGame(in);
            currentGame->SendInput(in);
            data = currentGame->getData();
        }
        if (in == MENU)
            menu();
    }

    void Launcher::quit() {
        if (!currentGame)
            delete currentGame;
        if (!currGrp)
            delete currGrp;
    }

    void Launcher::restart() {
        if (!currentGame)
            delete currentGame;
        gameLoader.loadLibrary(gameLib_path.at(gameSelected).c_str());
        currentGame = gameLoader.getInstance("entryPoint");
        if (!currentGame)
            throw (Exception("Library not found"));
    }

    int Launcher::changeGame(Input move) {
        if (move == NEXT_GAME) {
            gameSelected++;
            if (gameSelected >= gameLib_path.size())
                gameSelected = 0;
            gameLoader.loadLibrary(gameLib_path.at(gameSelected).c_str());
        } else {
            gameSelected--;
            if (gameSelected < 0)
                gameSelected = gameLib_path.size();
            gameLoader.loadLibrary(gameLib_path.at(gameSelected).c_str());
        }
        currentGame = gameLoader.getInstance("entryPoint");
        if (!currentGame)
            throw (Exception("Library not found"));
        return gameSelected;
    }

    int Launcher::changeGrp(int move) {
        if (move == NEXT_LIB) {
            grpSelected++;
            if (grpSelected >= grpLib_path.size())
                grpSelected = 0;
            displayLoader.loadLibrary(grpLib_path.at(grpSelected).c_str());
        } else {
            grpSelected--;
            if (grpSelected < 0)
                grpSelected = grpLib_path.size();
            displayLoader.loadLibrary(grpLib_path.at(grpSelected).c_str());
        }
        currGrp = displayLoader.getInstance("entryPoint");
        return gameSelected;
    }

    void Launcher::menu() {
        currGrp->setName(name);
        std::string str = "./game/";
        int ret = -1;

        while (ret != 11) {
            ret = currGrp->menu(gameLib_path);
            if (ret == QUIT)
                return;
            if (ret == NEXT_LIB || ret == PREV_LIB)
                changeGrp(ret);
        }
        name = currGrp->getName();
        if (gameLoader.loadLibrary((str + gameLib_path.at(1)).c_str()) == 84)
            throw (Exception("can't load game"));
        currentGame = gameLoader.getInstance("entryPoint");
         if (currentGame == nullptr)
            throw (Exception("No EntryPoint function in library"));
        launch();
    }
} // namespace Arcade