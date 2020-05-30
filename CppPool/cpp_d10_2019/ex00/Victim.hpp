/*
** EPITECH PROJECT, 2020
** CppPool
** File description:
** Victim
*/

#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>
#include <iostream>

class Victim {
	protected:
        std::string _name;
	public:
		Victim(std::string name);
		~Victim();
        std::string getName() const {return _name;};
        virtual void getPolymorphed() const;
	private:
};

std::ostream &operator<<(std::ostream &out, const Victim &vict);


#endif /* !VICTIM_HPP_ */
