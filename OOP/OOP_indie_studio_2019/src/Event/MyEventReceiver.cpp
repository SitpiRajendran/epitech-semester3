/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** eventReceiver
*/

#include <irrlicht.h>
#include "PathFinder.hpp"
#include "MyEventReceiver.hpp"

using namespace irr;
indie::MyEventReceiver::MyEventReceiver(std::shared_ptr<Character> Nmodele , std::shared_ptr<Character> _player2)
{
    is_fighting = 0;
    myKeySecond = "";
    myKeyPressed = "";
    player1 = Nmodele;
    player2 = _player2;
    player1_isMoving = false;
    player2_isMoving = false;
    eventP = EventParticular::Nothing;
}

indie::MyEventReceiver::~MyEventReceiver()
{
}

bool indie::MyEventReceiver::eventPlayer2(const SEvent &event, bool status)
{
    bool value = false;

    if (player2 != nullptr && player2->getDead() == 1 && event.EventType == irr::EET_KEY_INPUT_EVENT &&
        (event.KeyInput.Key == irr::KEY_KEY_O || event.KeyInput.Key == irr::KEY_KEY_L
        || event.KeyInput.Key == irr::KEY_KEY_K || event.KeyInput.Key == irr::KEY_KEY_M
        || event.KeyInput.Key == irr::KEY_KEY_J)) {
        value = true;
        switch (event.KeyInput.Key) {
            case irr::KEY_KEY_O: myKeySecond = "O"; break;
            case irr::KEY_KEY_L: myKeySecond = "L"; break;
            case irr::KEY_KEY_K: myKeySecond = "K"; break;
            case irr::KEY_KEY_M: myKeySecond = "M"; break;
            case irr::KEY_KEY_J: myKeySecond = "J"; break;
            default: break;
        }
        player2_isMoving = event.KeyInput.PressedDown;
        if (myKeySecond == "J" && player2_isMoving)
            eventP = EventParticular::BombPosP2;
    }
    if (!player2_isMoving && value)
        myKeySecond = "";
    if (!player1_isMoving && status)
        myKeyPressed = "";
    return (value);
}

bool indie::MyEventReceiver::OnEvent(const SEvent &event)
{
    bool value = false;

    eventP = EventParticular::Nothing;
    if (player1 != nullptr && player1->getDead() == 1 && event.EventType == irr::EET_KEY_INPUT_EVENT &&
        (event.KeyInput.Key == irr::KEY_KEY_Z || event.KeyInput.Key == irr::KEY_KEY_Q
        || event.KeyInput.Key == irr::KEY_KEY_S || event.KeyInput.Key == irr::KEY_KEY_D
        || event.KeyInput.Key == irr::KEY_KEY_G || event.KeyInput.Key == irr::KEY_KEY_T)) {
        value = true;
        switch (event.KeyInput.Key) {
            case irr::KEY_KEY_Z: myKeyPressed = "Z"; break;
            case irr::KEY_KEY_S: myKeyPressed = "S"; break;
            case irr::KEY_KEY_Q: myKeyPressed = "Q"; break;
            case irr::KEY_KEY_D: myKeyPressed = "D"; break;
            case irr::KEY_KEY_G: myKeyPressed = "G"; break;
            case irr::KEY_KEY_T: myKeyPressed = "T"; break;
            default: value = false; break;
        }
        player1_isMoving = event.KeyInput.PressedDown;
        if (myKeyPressed == "G" && player1_isMoving)
            eventP = EventParticular::BombPosP1;
    }
    if (eventPlayer2(event, value))
        return (true);
    return value;
}

void indie::MyEventReceiver::moveEvent_Player2(Mapper &AsciiMap)
{
    int x = 0;
    int y = 0;

    if (player1->getDead() == 1) {
        x = (int)player1->getNode()->getPosition().X / 3;
        y = (int)player1->getNode()->getPosition().Z / 3;
    }
    if (player2 != nullptr && player2->getDead() == 1 && player2_isMoving) {
        player2->updatePosRot();
        if (myKeySecond == "O") {
            player2->animUp();
        } if (myKeySecond == "L") {
            player2->animDown();
        } if (myKeySecond == "K") {
            player2->animLeft();
        } if (myKeySecond == "M") {
            player2->animRight();
        } if (myKeySecond == "J") {
            player2->bombPos();
            AsciiMap.setCharPos(AsciiMap.getBombs(), x, y);
        }
        x = (int)player2->getNode()->getPosition().X / 3;
        y = (int)player2->getNode()->getPosition().Z / 3;

        AsciiMap.setCharPos(AsciiMap.getPlayers()[1], x, y);
    }
    if (!player2_isMoving && player2 != 0 && player2->getDead() == 1)
        player2->reInitAnim();
    if (player2 != nullptr && player2->getDead() == 1)
        player2->reInitBombPos();
}

void indie::MyEventReceiver::moveEvent_Player1(Mapper &AsciiMap)
{
    int x = 0;
    int y = 0;

    if (player1->getDead() == 1) {
        x = (int)player1->getNode()->getPosition().X / 3;
        y = (int)player1->getNode()->getPosition().Z / 3;
    }
    if (player1 != nullptr && player1->getDead() == 1 && player1_isMoving) {
        player1->updatePosRot();
        if (myKeyPressed == "Z") {
            player1->animUp();
        } if (myKeyPressed == "S") {
            player1->animDown();
        } if (myKeyPressed == "Q") {
            player1->animLeft();
        } if (myKeyPressed == "D") {
            player1->animRight();
        } if (myKeyPressed == "G") {
            player1->bombPos();
            AsciiMap.setCharPos(AsciiMap.getBombs(), x, y);
        } if (myKeyPressed == "T")
            PathFinder().printMap(PathFinder().myway(AsciiMap.getMap(), AsciiMap.getPlayers()[0], AsciiMap.getPlayers()[1]));
        x = (int)player1->getNode()->getPosition().X / 3;
        y = (int)player1->getNode()->getPosition().Z / 3;

        AsciiMap.setCharPos(AsciiMap.getPlayers()[0], x, y);
    } if (!player1_isMoving && player1 != 0  && player1->getDead() == 1)
        player1->reInitAnim();
    if (player1 != nullptr && player1->getDead() == 1)
        player1->reInitBombPos();
}

void indie::MyEventReceiver::majPosMesh(Mapper &AsciiMap)
{
    moveEvent_Player1(AsciiMap);
    moveEvent_Player2(AsciiMap);
}

indie::EventParticular indie::MyEventReceiver::getParticularEvent()
{
    return (this->eventP);
}