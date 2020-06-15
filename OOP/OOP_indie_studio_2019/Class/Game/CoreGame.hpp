/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** CoreGame
*/

#ifndef __COREGAME__
#define __COREGAME__

#include <vector>
#include "Menu.hpp"
#include "Maper.hpp"
#include "CoreGame.hpp"
#include "MapHandler.hpp"
#include "TitleScreen.hpp"
#include "MapGenerator.hpp"
#include "MyRemoteControler.hpp"

namespace indie {
    class CoreGame {
        public:
            CoreGame(const char *persoPath, const int nbPlayer, const int nbBot);
            ~CoreGame();

            void initPerso();
            int Core(void);
            void addCollision();
            int LaunchTitleScreenAndMenu();
            int LaunchMenu();
            int LaunchChooseMultiMenu();
            int LaunchGameAndReplayMenu();
            void addBomb(std::string poserName);
            void handleParticularEvent(EventParticular event);
            void initializeGameParticle();
            void initializeGameParticleFlame();
            void initializeGameParticleSnow();
            void initializeGameParticleRain();
            void checkPowerUp(std::shared_ptr<indie::MapHandler> MapHandler);
            void resetPerso(std::shared_ptr<indie::MapHandler> MapHandler);
            int CheckEnd();
            std::string getWinner();

        private:
            int nbBot;
            int nbPlayer;
            bool is_solo;
            bool is_load;
            Mapper *AsciiMap;
            BombList bombList;
            irrManager_t manager;
            WindowHandler *windowhdl;
            MyRemoteControler *Remote;
            MyEventReceiver *receiver;
            std::vector<std::shared_ptr<MyPerso>> bot;
            std::vector<std::shared_ptr<MyPerso>> PlayerPerso;
            std::string winner_name;
    };
}

#endif