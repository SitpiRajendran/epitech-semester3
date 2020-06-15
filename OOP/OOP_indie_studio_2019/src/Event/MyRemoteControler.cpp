/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** MyRemoteControler
*/

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "Character.hpp"
#include "WindowHandler.hpp"
#include "MyRemoteControler.hpp"
#include "MenuEventReceiver.hpp"

indie::MyRemoteControler::MyRemoteControler() {
    this->looper = 0;
    this->fpsSignal = 0;
    this->userInput = 0;
    this->last_input = 0;
    this->eventP = EventParticular::Nothing;
}
indie::MyRemoteControler::~MyRemoteControler() {}

//Get Remote Event Type
bool indie::MyRemoteControler::OnEvent(const SEvent &event) {
    this->eventP = EventParticular::Nothing;
    if (event.EventType == EET_MOUSE_INPUT_EVENT) {
        switch (event.MouseInput.Event) {
            case EMIE_LMOUSE_PRESSED_DOWN: MouseState.LeftButtonDown = true; break;
            case EMIE_LMOUSE_LEFT_UP: MouseState.LeftButtonDown = false; break;
            case EMIE_MOUSE_MOVED:
                MouseState.Position.X = event.MouseInput.X;
                MouseState.Position.Y = event.MouseInput.Y;
                break;
            default: break;
        }
    } if (event.EventType == EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0)
        JoystickState = event.JoystickEvent;
    if (event.JoystickEvent.ButtonStates != 0 && event.JoystickEvent.ButtonStates != this->last_input) {
        if (event.JoystickEvent.ButtonStates != 0)
            switch (event.JoystickEvent.ButtonStates) {
                case Button::HOME:     this->last_input = Button::HOME;     break;//cout << "Home Button" << endl; break;
                case Button::SELECT:   this->last_input = Button::SELECT;   break;//cout << "Select Button" << endl; break;
                case Button::START:    this->last_input = Button::START;    break;//cout << "Start Button" << endl; break;
                case Button::CROIX:    this->last_input = Button::CROIX;    break;//cout << "Croix Button" << endl; break;
                case Button::SQUARE:   this->last_input = Button::SQUARE;   break;//cout << "Square Button" << endl; break;
                case Button::TRIANGLE: this->last_input = Button::TRIANGLE; break;//cout << "Triangle Button" << endl; break;
                case Button::CIRCLE:   this->last_input = Button::CIRCLE;   break;//cout << "Circle Button" << endl; break;
                case Button::L1:       this->last_input = Button::L1;       break;//cout << "L1 Button" << endl; break;
                case Button::R1:       this->last_input = Button::R1;       break;//cout << "R1 Button" << endl; break;
                case Button::LJOY:     this->last_input = Button::LJOY;     break;//cout << "LJOY Button" << endl; break;
                case Button::RJOY:     this->last_input = Button::RJOY;     break;//cout << "RJOY Button" << endl; break;
                default: cout << "Unknown Button: " << event.JoystickEvent.ButtonStates << endl;
            }
        this->last_input = event.JoystickEvent.ButtonStates;
        if (event.JoystickEvent.ButtonStates > 100)
            return false;
    }
    return false;
}

//Get Remote Infos, like name, button number, etc
void indie::MyRemoteControler::RemoteInfos(IrrlichtDevice *device) {
    if (device->activateJoysticks(this->joystickInfo)) {
        cout << "Joystick support is enabled and " << this->joystickInfo.size() << (this->joystickInfo.size() > 1 ? " joysticks" : " joystick") << " are present." << endl;

        for (size_t joystick = 0; joystick < this->joystickInfo.size(); joystick ++) {
            cout << "Joystick " << joystick << ":" << endl;
            cout << "\tName: '" << this->joystickInfo[joystick].Name.c_str() << "'" << endl;
            cout << "\tAxes: " << this->joystickInfo[joystick].Axes << endl;
            cout << "\tButtons: " << this->joystickInfo[joystick].Buttons << endl;
            cout << "\tHat is: ";

            switch (this->joystickInfo[joystick].PovHat) {
                case SJoystickInfo::POV_HAT_PRESENT: cout << "present" << endl; break;
                case SJoystickInfo::POV_HAT_ABSENT: cout << "absent" << endl; break;
                default: cout << "unknown" << endl; break;
            }
        }
    } else
        cout << "Joystick support is not enabled." << endl;
}

//Handle and find Joystick Direction
void indie::MyRemoteControler::JoystickMouvement(WindowHandler &windowhdl, vector3df &nodePosition, float frameDeltaTime) {
    vector3df mousePosition;
    plane3df plane(nodePosition, vector3df(0, 0, -1));
    line3df ray = windowhdl.getSceneManager()->getSceneCollisionManager()->getRayFromScreenCoordinates(this->GetMouseState().Position, windowhdl.getCamera());

    if (plane.getIntersectionWithLine(ray.start, ray.getVector(), mousePosition)) {
        vector3df toMousePosition(mousePosition - nodePosition);
        float availableMovement = 5 * frameDeltaTime; //5 == Mouvement Speed

        if (toMousePosition.getLength() <= availableMovement)
            nodePosition = mousePosition;
        else
            nodePosition += toMousePosition.normalize() * availableMovement;
    }
}

//Avoid 1.000.000.000 signals from remote
void indie::MyRemoteControler::avoidMultipleSignal(void) {
    this->looper ++;
    if (this->looper > this->fpsSignal) {
        this->looper = 0;
        this->last_input = 0;
    } if (this->last_input > 100 || this->last_input < 0)
        this->last_input = 0;
}

//Update player Position with Remote Input
void indie::MyRemoteControler::updatePlayer(WindowHandler &windowhdl, MyPerso &Perso, Mapper &AsciiMap) {
    bool moving = false;
    size_t x = (int)Perso.getNode()->getPosition().X;
    size_t y = (int)Perso.getNode()->getPosition().Z;
    const SEvent::SJoystickEvent joystickData = this->GetJoystickState();
    float Horizontal = (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_X] / 32767.f;
    float Vertical =   (f32)joystickData.Axis[SEvent::SJoystickEvent::AXIS_Y] / -32767.f;

    if (Horizontal == 1) {
        Perso.getCharacter()->animRight();
        moving = true;
    } else if (Horizontal == -1) {
        Perso.getCharacter()->animLeft();
        moving = true;
    } else if (Vertical == 1) {
        Perso.getCharacter()->animUp();
        moving = true;
    } else if (Vertical == -1) {
        Perso.getCharacter()->animDown();
        moving = true;
    } if (!moving)
        Perso.getCharacter()->reInitAnim();
    x = (int)Perso.getNode()->getPosition().X;
    y = (int)Perso.getNode()->getPosition().Z;
    AsciiMap.setCharPos(AsciiMap.getPlayers()[0], x, y);
    switch (this->last_input) {
        case Button::CROIX:
            Perso.getCharacter()->bombPos();
            AsciiMap.setCharPos(AsciiMap.getBombs(), x, y);
            this->eventP = EventParticular::BombPosP1;
            break;
        default: break;
    }
    if (Perso.getCharacter() != nullptr)
        Perso.getCharacter()->reInitBombPos();
    this->last_input = 0;
}

//Return true if one Remote is plug (or more)
bool indie::MyRemoteControler::CheckPlug(IrrlichtDevice *device) {
    if (joystickInfo.size() > 0)
        return true;
    return false;
}

void indie::MyRemoteControler::setFpsSignal(size_t fps) {this->fpsSignal = fps;}
indie::EventParticular indie::MyRemoteControler::getParticularEvent() {return (this->eventP);}
const SEvent::SJoystickEvent indie::MyRemoteControler::GetJoystickState(void) const {return JoystickState;}
const indie::MyRemoteControler::SMouseState indie::MyRemoteControler::GetMouseState(void) const {return MouseState;}
