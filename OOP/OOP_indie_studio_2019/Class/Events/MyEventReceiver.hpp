/*
** EPITECH PROJECT, 2020
** indie_test
** File description:
** eventReceiver
*/

#ifndef EVENTRECEIVER_HPP_
#define EVENTRECEIVER_HPP_

#include <memory>
#include "memory.h"
#include <iostream>
#include "Maper.hpp"
#include "Character.hpp"
#include "MyRemoteControler.hpp"

namespace indie {
    class Mapper;


    class MyEventReceiver: public irr::IEventReceiver {
        public:
            MyEventReceiver(std::shared_ptr<Character> , std::shared_ptr<Character> );
            ~MyEventReceiver();

            void majPosMesh(Mapper &AsciiMap);
            EventParticular getParticularEvent();
            void moveEvent_Player1(Mapper &AsciiMap);
            void moveEvent_Player2(Mapper &AsciiMap);
            virtual bool OnEvent(const irr::SEvent &);
            bool eventPlayer2(const irr::SEvent &, bool status);

        private :
            int is_fighting;
            bool player1_isMoving;
            bool player2_isMoving;
            irr::core::matrix4 Mat;
            EventParticular eventP;
            std::string myKeySecond;
            std::string myKeyPressed;
            std::shared_ptr<Character> player1;
            std::shared_ptr<Character> player2;
    };
}

#endif
