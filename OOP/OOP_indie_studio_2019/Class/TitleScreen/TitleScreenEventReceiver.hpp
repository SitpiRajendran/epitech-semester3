/*
** EPITECH PROJECT, 2020
** IndieStudioTech
** File description:
** TitleScreenEventReceiver
*/

#ifndef TITLESCREENEVENTRECEIVER_HPP_
#define TITLESCREENEVENTRECEIVER_HPP_

#include "Irrlicht.hpp"

namespace indie
{
    class TitleScreenEventReceiver : public IEventReceiver
    {
        public:
            TitleScreenEventReceiver(bool &launched);
            virtual bool OnEvent(const SEvent &event);

        private:
            bool *_launched;
    };
}

#endif /* !TITLESCREENEVENTRECEIVER_HPP_ */
