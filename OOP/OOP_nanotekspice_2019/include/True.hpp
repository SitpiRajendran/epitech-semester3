/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

class True : public nts::IComponent {
    public:
        True(std::string name);
        ~True();
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::vector<Pin> getPins() override {return _pins;};
        size_t getMax() override {return _maxPin;};
        std::string getName() {return _name;};
        void setPins(std::vector<Pin> pin) override;
    private:
        std::string _name;
        size_t _maxPin;
        std::vector<Pin> _pins;
};

#endif /* !TRUE_HPP_ */
