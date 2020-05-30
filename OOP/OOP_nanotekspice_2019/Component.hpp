/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "Pin.hpp"

class Component : public nts::IComponent {
    public:
        Component();
        virtual ~Component() = default;
        virtual nts::Tristate compute(std::size_t pin = 1);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        virtual void dump() const;
        virtual std::vector<Pin> getPins() {};
        virtual size_t getMax() {};
        virtual std::string getName() {
            return _name;
        };
        virtual void setPins(std::vector<Pin> pin) {};

    protected :
        std::string _name;
};
#endif /* !Component_HPP_ */
