/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

class C4001 : public nts::IComponent {
    public:
        C4001(std::string name);
        ~C4001();
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const;
        std::vector<Pin> getPins() override {return _pins;};
        size_t getMax() override {return _maxPin;};
        std::string getName() override {return _name;};
        void setPins(std::vector<Pin> pin) override {_pins = pin;};

    private:
        std::string _name;
        size_t _maxPin;
        std::vector<Pin> _pins;
};

#endif /* !C4001_HPP_ */
