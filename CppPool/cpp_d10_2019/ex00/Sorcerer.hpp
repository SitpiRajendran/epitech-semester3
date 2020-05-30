/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Sorcerer
*/

#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
	protected:
        std::string _name;
        std::string _title;
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer();
        std::string getName() const {return _name;};
        std::string getTitle() const {return _title;};
        void polymorph(const Victim &victim) const;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcer);

#endif /* !SORCERER_HPP_ */