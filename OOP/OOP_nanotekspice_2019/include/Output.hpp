/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "IComponent.hpp"
#include"Pin.hpp"

class Output : public nts::IComponent {
    public:
        Output(std::string name);
        ~Output();
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

#endif /* !OUTPUT_HPP_ */
