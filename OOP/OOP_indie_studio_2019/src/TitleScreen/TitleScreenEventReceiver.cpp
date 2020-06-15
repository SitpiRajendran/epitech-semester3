/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** TitleScreenEventReceiver
*/

#include "TitleScreenEventReceiver.hpp"

indie::TitleScreenEventReceiver::TitleScreenEventReceiver(bool &launched)
{
    _launched = &launched;
}

bool indie::TitleScreenEventReceiver::OnEvent(const SEvent &event)
{
    if (event.EventType == EET_MOUSE_INPUT_EVENT) {
        if (event.MouseInput.Event == EMIE_LMOUSE_PRESSED_DOWN ||
            event.MouseInput.Event == EMIE_RMOUSE_PRESSED_DOWN) {
            *_launched = false;
            return (true);
        }
    }
    return (false);
}