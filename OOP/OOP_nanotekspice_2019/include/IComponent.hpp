/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iterator>
#include <iostream>
#include <vector>
#include <memory>
class Pin;

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            IComponent() {};
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::vector<Pin> getPins() = 0;
            virtual size_t getMax() = 0;
            virtual std::string getName() = 0;
            virtual void setPins(std::vector<Pin> pin) = 0;
        protected:
        private:
    };
};
std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
nts::Tristate and_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate nand_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate or_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate xor_gate(nts::Tristate a, nts::Tristate b);
nts::Tristate nor_gate(nts::Tristate a, nts::Tristate b);

enum Type {
    I,
    O,
    U
};

class Pin {
    public:
        Pin(std::size_t pin, Type type, nts::Tristate stat = nts::UNDEFINED);
        Pin(const Pin&);
        ~Pin();
        Pin& operator=(const Pin&);
        void setStatus(nts::Tristate stat) {_status = stat;};
        nts::Tristate getStatus() {return _status;};
        Type getType() {return _type;};
        std::unique_ptr<Pin> getLink();
        void setLink(Pin pin);
    private:
        std::size_t _name;
        Type _type;
        std::unique_ptr<Pin> _link;
        nts::Tristate _status;
};
#endif /* !ICOMPONENT_HPP_ */
