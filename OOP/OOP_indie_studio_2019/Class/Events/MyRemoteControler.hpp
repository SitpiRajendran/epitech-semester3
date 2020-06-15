/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MyRemoteControler
*/

#ifndef __REMOTECONTROLER__
#define __REMOTECONTROLER__

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

#include <ostream>
#include <iostream>
#include <irrlicht.h>

#include "Maper.hpp"
#include "MyPerso.hpp"
#include "Irrlicht.hpp"
#include "Character.hpp"
#include "WindowHandler.hpp"

namespace indie {
    class WindowHandler;
    class MyPerso;
    class Mapper;

    class MyRemoteControler: public IEventReceiver {
        public:
            MyRemoteControler();
            ~MyRemoteControler();

            enum Button {
                SELECT = 64,
                START = 128,
                HOME = 256,

                CROIX = 1,
                CIRCLE = 2,
                SQUARE = 4,
                TRIANGLE = 8,

                L1 = 16,
                R1 = 32,
                L1_R1 = 48,

                LJOY = 512,
                RJOY = 1024
            };

            struct SMouseState {
                bool LeftButtonDown;
                position2di Position;
                SMouseState() : LeftButtonDown(false) {}
            } MouseState;
            core::array<SJoystickInfo> joystickInfo;

            void setFpsSignal(size_t);
            void avoidMultipleSignal(void);
            bool CheckPlug(IrrlichtDevice *);
            EventParticular getParticularEvent(void);
            void RemoteInfos(IrrlichtDevice *);
            virtual bool OnEvent(const SEvent &);
            const SMouseState GetMouseState(void) const;
            const SEvent::SJoystickEvent GetJoystickState(void) const;
            void updatePlayer(WindowHandler &, MyPerso &, Mapper &);
            void JoystickMouvement(WindowHandler &, vector3df &, float);

        private:
            size_t looper;
            size_t fpsSignal;
            size_t userInput;
            unsigned int last_input;
            EventParticular eventP;
            SEvent::SKeyInput RemoteInput;
            SEvent::SJoystickEvent JoystickState;
    };
}

#endif