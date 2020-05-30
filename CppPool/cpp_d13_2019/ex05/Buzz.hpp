/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"
#include "Picture.hpp"

class Buzz : public Toy {
    public:
        Buzz(std::string name, std::string ascii = "buzz.txt");
        ~Buzz();
        void speak(std::string str);
        bool speak_es(std::string str);
    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
