/*
** EPITECH PROJECT, 2020
** bootstrap_NanoTekSpice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

class Component {
    public:
        Component();
        Component(int value);
        ~Component();


    protected:
        Component& _link;
        int _state;
    private:
};

#endif /* !COMPONENT_HPP_ */
