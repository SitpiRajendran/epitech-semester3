/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "IComponent.hpp"
#include "Pin.hpp"

class False : public nts::IComponent {
    public:
        False(std::string name);
        ~False();
        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void dump() const override;
        std::vector<Pin> getPins() override {return _pins;};
        size_t getMax() override {return _maxPin;};
        void setPins(std::vector<Pin> pin) override;
    private:
        std::string _name;
        size_t _maxPin;
        std::vector<Pin> _pins;
};

#endif /* !FALSE_HPP_ */
