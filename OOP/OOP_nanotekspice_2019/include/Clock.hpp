/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

class Clock : public nts::IComponent {
    public:
        Clock(std::string name);
        ~Clock();
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::vector<Pin> getPins() override {return _pins;};
        size_t getMax() override {return _maxPin;};
        void setPins(std::vector<Pin> pin) override {_pins = pin;};
    private:
        std::string _name;
        size_t _maxPin;
        std::vector<Pin> _pins;
};

#endif /* !INPUT_HPP_ */
