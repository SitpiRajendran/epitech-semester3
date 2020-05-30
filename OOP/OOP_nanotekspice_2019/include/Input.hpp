/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

class Input : public nts::IComponent {
    public:
        Input(std::string name);
        ~Input();
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::vector<Pin> getPins() override {return _pins;};
        size_t getMax() override {return _maxPin;};
        std::string getName() {return _name;};
        void setPins(std::vector<Pin> pin) override {_pins = pin;};
    private:
        std::string _name;
        size_t _maxPin;
        std::vector<Pin> _pins;
};

#endif /* !INPUT_HPP_ */
